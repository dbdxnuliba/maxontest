#include "omega.h"
#include <qdebug.h>
#include "ui_omega.h"
#include <QCloseEvent>
#include <thread>

omega::omega(OmegaFunction* omegaFunc, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::omega)
{
    ui->setupUi(this);
    this->m_omegaFunc = omegaFunc;
    this->init();
}

omega::~omega()
{
    delete ui;
}

void omega::init(){
    ui->openButton->setDisabled(false);
    ui->closeButton->setDisabled(true);
    initFx = 0;
    initFy = 0;
    initFz = 0;
    initTx = 0;
    initTy = 0;
    initTz = 0;
    forcex = 0;
    forcey = 0;
    forcez = 0;
    tx = 0;
    ty = 0;
    tz = 0;
    m_startThread = false;
    m_setForceDone = true;
    m_isOpen = false;
}


void omega::closeOmega(){
    // close the connection
    m_omegaFunc->closeOmega();
}

void omega::closeEvent(QCloseEvent *event){
    this->closeOmega();
    event->accept();
}

void omega::on_openButton_clicked()
{
    // open the first available device
    if (m_omegaFunc->openOmega() < 0) {
        qDebug()<< "error: cannot open device"<<dhdErrorGetLastStr();
        dhdSleep (2.0);
        return;
    }
    m_isOpen = true;
    // retrieve force
    if (m_omegaFunc->getForceAndTorque(&initFx, &initFy, &initFz, &initTx, &initTy, &initTz) < DHD_NO_ERROR) {
        this->closeOmega();
        qDebug()<<"error: cannot read force "<<dhdErrorGetLastStr();
        return;
    }
    ui->openButton->setDisabled(true);
    ui->closeButton->setDisabled(false);

    std::thread t(std::bind(&omega::showParameter, this));
    t.detach();
}

void omega::on_closeButton_clicked()
{
    if(!m_setForceDone){
        return;
    }
    m_isOpen = false;
    m_startThread = false;
    ui->openButton->setDisabled(false);
    ui->closeButton->setDisabled(true);
}

void omega::showParameter(){
    m_startThread = true;
    while(m_startThread){
        double px, py, pz, theta1, theta2, theta3, fx, fy, fz, tx, ty, tz;
        if (m_omegaFunc->getPositionAndOrientationDeg(&px, &py, &pz, &theta1, &theta2, &theta3) < DHD_NO_ERROR) {
            qDebug()<<"error: cannot read position "<<dhdErrorGetLastStr();
            m_startThread = false;
        }
        // retrieve force
        if (m_omegaFunc->getForceAndTorque(&fx, &fy, &fz, &tx, &ty, &tz) < DHD_NO_ERROR) {
            qDebug()<<"error: cannot read force "<<dhdErrorGetLastStr();
            m_startThread = false;
        }
        int rt = dhdGetButton(0);
        if(rt == -1){
            m_startThread = false;
        }else if(rt == DHD_ON){
            ui->statusButton->setChecked(true);
        }else if(rt == DHD_OFF){
            ui->statusButton->setChecked(false);
        }
        ui->posX->setText(QString::number(px*1000));
        ui->posY->setText(QString::number(py*1000));
        ui->posZ->setText(QString::number(pz*1000));
        ui->theta1->setText(QString::number(theta1));
        ui->theta2->setText(QString::number(theta2));
        ui->theta3->setText(QString::number(theta3));
        ui->forceX->setText(QString::number(fx));
        ui->forceY->setText(QString::number(fy));
        ui->forceZ->setText(QString::number(fz));
        ui->torque1->setText(QString::number(tx));
        ui->torque2->setText(QString::number(ty));
        ui->torque3->setText(QString::number(tz));
        std::chrono::milliseconds dura(100);
        std::this_thread::sleep_for(dura);
    }
    this->closeOmega();
}

void omega::setForce(){
    while(!m_setForceDone){
        // apply zero force
        if (!m_omegaFunc->setForceAndTorqueAndGripperForce(forcex, forcey, forcez, 0.0, 0.0, 0.0, 0.0)) {
            qDebug()<<"error: cannot set force "<<dhdErrorGetLastStr();
            m_setForceDone = true;
        }
        std::chrono::milliseconds dura(50);
        std::this_thread::sleep_for(dura);
    }
}


int omega::getStatus(){
    int status[DHD_MAX_STATUS];
    dhdGetStatus(status);
    return 0;
}

void omega::on_setForceButton_clicked()
{
    if(!m_isOpen) return;

    if(m_setForceDone){
        // enable force
        dhdEnableForce (DHD_ON);
        m_setForceDone = false;
        ui->setForceButton->setText("quit");
        std::thread tForce(std::bind(&omega::setForce, this));
        tForce.detach();
    }else{
        m_setForceDone = true;
        ui->setForceButton->setText("SetForce");
        std::chrono::milliseconds dura(200);
        std::this_thread::sleep_for(dura);
        // enable force
        dhdEnableForce (DHD_OFF);
    }
}


void omega::on_forceXSetEdit_editingFinished()
{
    double rt = ui->forceXSetEdit->text().toDouble();
    if(rt > 5){
        return;
    }
    forcex = rt;
}

void omega::on_forceYSetEdit_editingFinished()
{
    double rt = ui->forceYSetEdit->text().toDouble();
    if(rt > 5){
        return;
    }
    forcey = rt;
}

void omega::on_forceZSetEdit_editingFinished()
{
    double rt = ui->forceZSetEdit->text().toDouble();
    if(rt > 5){
        return;
    }
    forcez = rt;
}

