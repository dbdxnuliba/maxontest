#include <QScreen>
#include "mainwindow.h"
#include <QDebug>
#include <QGuiApplication>
#include <QCloseEvent>

#define REFRESH_INTERVAL 0.05

//! ---------------------------------------------------------------------------------------------------------------------------------------------------
//!
//! \brief MainWindow::MainWindow
//!
MainWindow::MainWindow(){

    QScreen *screen = QGuiApplication::primaryScreen ();
    QRect mm=screen->availableGeometry() ;
    int screen_width = mm.width();
    int screen_height = mm.height();

    int window_width = screen_width*2/3;
    int window_height  =screen_height*2/3;
    int width_scale = window_width / 50;
    int height_scale = window_height / 50;
//    this->setFixedSize(QSize(window_width, window_height));
//    this->setGeometry(0, 0, window_width, window_height);
    this->setStyleSheet("background: gray");

    //! motor1
    this->maxon_motor1_label = new QLabel(this);
    this->maxon_motor1_label->setGeometry(0.5*width_scale, 0.5*height_scale, 3*width_scale, 2*height_scale);
    this->maxon_motor1_label->setText("motor1");
    this->maxon_motor1_position_label = new QLabel(this);
    this->maxon_motor1_position_label->setGeometry(5*width_scale, 0.5*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_position_label->setText("pos(mm)");
    this->maxon_motor1_position_label->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_velocity_label = new QLabel(this);
    this->maxon_motor1_velocity_label->setText("vel(mm/s)");
    this->maxon_motor1_velocity_label->setGeometry(11*width_scale, 0.5*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_velocity_label->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_enable_button = new QPushButton(this);
    this->maxon_motor1_enable_button->setGeometry(0.5*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_enable_button->setStyleSheet("background: green");
    this->maxon_motor1_enable_button->setText("disable");
    this->maxon_motor1_current_position = new QLabel(this);
    this->maxon_motor1_current_position->setGeometry(5*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_current_position->setText("0");
    this->maxon_motor1_current_position->setStyleSheet("background: green");
    this->maxon_motor1_current_position->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_current_velocity = new QLabel(this);
    this->maxon_motor1_current_velocity->setText("0");
    this->maxon_motor1_current_velocity->setGeometry(11*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_current_velocity->setStyleSheet("background: green");
    this->maxon_motor1_current_velocity->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_profileVelocitymode_button = new QPushButton(this);
    this->maxon_motor1_profileVelocitymode_button->setGeometry(0.5*width_scale, 9*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_button->setText("规划速度模式");
    this->maxon_motor1_profileVelocitymode_setVelocity_label = new QLabel(this);
    this->maxon_motor1_profileVelocitymode_setVelocity_label->setGeometry(0.5*width_scale, 12*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_setVelocity_label->setText("设置速度");
    this->maxon_motor1_profileVelocitymode_setVelocity_text = new QLineEdit(this);
    this->maxon_motor1_profileVelocitymode_setVelocity_text->setGeometry(5*width_scale, 12*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_setVelocity_text->setText(QString("0"));
    this->maxon_motor1_profileVelocitymode_setVelocity_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_profileVelocitymode_setVelocity_text->setStyleSheet("background: green");
    this->maxon_motor1_profileVelocitymode_unit_label = new QLabel(this);
    this->maxon_motor1_profileVelocitymode_unit_label->setGeometry(10*width_scale, 12*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_unit_label->setText("mm/s");
    this->maxon_motor1_profileVelocitymode_startmove_button = new QPushButton(this);
    this->maxon_motor1_profileVelocitymode_startmove_button->setGeometry(0.5*width_scale, 15*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_startmove_button->setText(QString("velocity移动"));
    this->maxon_motor1_profileVelocitymode_startmove_button->setStyleSheet("background: green");
    this->maxon_motor1_profileVelocitymode_stop_button = new QPushButton(this);
    this->maxon_motor1_profileVelocitymode_stop_button->setGeometry(8*width_scale, 15*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_profileVelocitymode_stop_button->setText(QString("velocity停止"));
    this->maxon_motor1_profileVelocitymode_stop_button->setStyleSheet("background: green");
    this->maxon_motor1_positionmode_button = new QPushButton(this);
    this->maxon_motor1_positionmode_button->setGeometry(0.5*width_scale, 22*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_positionmode_button->setText("规划位置模式");
    this->maxon_motor1_absposition_radiaoButton = new QRadioButton(this);
    this->maxon_motor1_absposition_radiaoButton->setGeometry(0.5*width_scale, 25*height_scale, 1*width_scale, 2*height_scale);
    this->maxon_motor1_absposition_label = new QLabel(this);
    this->maxon_motor1_absposition_label->setGeometry(2*width_scale, 25*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_absposition_label->setText("绝对位置");
    this->maxon_motor1_absposition_text = new QLineEdit(this);
    this->maxon_motor1_absposition_text->setGeometry(6.5*width_scale, 25*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_absposition_text->setText(QString("0"));
    this->maxon_motor1_absposition_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_absposition_text->setStyleSheet("background: green");
    this->maxon_motor1_asbposition_unit_label = new QLabel(this);
    this->maxon_motor1_asbposition_unit_label->setGeometry(11.5*width_scale, 25*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_asbposition_unit_label->setText("mm");
    this->maxon_motor1_absposition_radiaoButton = new QRadioButton(this);
    this->maxon_motor1_absposition_radiaoButton->setGeometry(0.5*width_scale, 28*height_scale, 1*width_scale, 2*height_scale);
    this->maxon_motor1_relposition_label = new QLabel(this);
    this->maxon_motor1_relposition_label->setGeometry(2*width_scale, 28*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_relposition_label->setText("相对位置");
    this->maxon_motor1_relposition_text = new QLineEdit(this);
    this->maxon_motor1_relposition_text->setGeometry(6.5*width_scale, 28*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_relposition_text->setText(QString("0"));
    this->maxon_motor1_relposition_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_relposition_text->setStyleSheet("background: green");
    this->maxon_motor1_relposition_unit_label = new QLabel(this);
    this->maxon_motor1_relposition_unit_label->setGeometry(11.5*width_scale, 28*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_relposition_unit_label->setText("mm");
    this->maxon_motor1_positionmode_velocity_label = new QLabel(this);
    this->maxon_motor1_positionmode_velocity_label->setGeometry(0.5*width_scale, 31*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_positionmode_velocity_label->setText("速度");
    this->maxon_motor1_positionmode_velocity_text = new QLineEdit(this);
    this->maxon_motor1_positionmode_velocity_text->setGeometry(3.5*width_scale, 31*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_positionmode_velocity_text->setText(QString("0"));
    this->maxon_motor1_positionmode_velocity_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_positionmode_velocity_text->setStyleSheet("background: green");
    this->maxon_motor1_asbposition_velocity_unit_label = new QLabel(this);
    this->maxon_motor1_asbposition_velocity_unit_label->setGeometry(8.5*width_scale, 31*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_asbposition_velocity_unit_label->setText("mm/s");
    this->maxon_motor1_asbpositionmode_startmove_button = new QPushButton(this);
    this->maxon_motor1_asbpositionmode_startmove_button->setGeometry(0.5*width_scale, 34.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_asbpositionmode_startmove_button->setText("asbpos移动");
    this->maxon_motor1_asbpositionmode_startmove_button->setStyleSheet("background: green");
    this->maxon_motor1_positionmode_halt_button = new QPushButton(this);
    this->maxon_motor1_positionmode_halt_button->setGeometry(8*width_scale, 34.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_positionmode_halt_button->setText("position停止");
    this->maxon_motor1_positionmode_halt_button->setStyleSheet("background: green");
    this->maxon_motor1_relpositionmode_startmove_button = new QPushButton(this);
    this->maxon_motor1_relpositionmode_startmove_button->setGeometry(0.5*width_scale, 37.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_relpositionmode_startmove_button->setText("relpos移动");
    this->maxon_motor1_relpositionmode_startmove_button->setStyleSheet("background: green");

    this->maxon_motor1_velocitymode_button = new QPushButton(this);
    this->maxon_motor1_velocitymode_button->setGeometry(0.5*width_scale, 45*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_button->setText("速度模式");
    this->maxon_motor1_velocitymode_setVelocity_label = new QLabel(this);
    this->maxon_motor1_velocitymode_setVelocity_label->setGeometry(0.5*width_scale, 48*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_setVelocity_label->setText("设置速度");
    this->maxon_motor1_velocitymode_setVelocity_text = new QLineEdit(this);
    this->maxon_motor1_velocitymode_setVelocity_text->setGeometry(5*width_scale, 48*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_setVelocity_text->setText(QString("0"));
    this->maxon_motor1_velocitymode_setVelocity_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_velocitymode_setVelocity_text->setStyleSheet("background: green");
    this->maxon_motor1_velocitymode_unit_label = new QLabel(this);
    this->maxon_motor1_velocitymode_unit_label->setGeometry(10*width_scale, 48*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_unit_label->setText("mm/s");
    this->maxon_motor1_velocitymode_startmove_button = new QPushButton(this);
    this->maxon_motor1_velocitymode_startmove_button->setGeometry(0.5*width_scale, 51*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_startmove_button->setText(QString("velocity移动"));
    this->maxon_motor1_velocitymode_startmove_button->setStyleSheet("background: green");
    this->maxon_motor1_velocitymode_stop_button = new QPushButton(this);
    this->maxon_motor1_velocitymode_stop_button->setGeometry(8*width_scale, 51*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_velocitymode_stop_button->setText(QString("velocity停止"));
    this->maxon_motor1_velocitymode_stop_button->setStyleSheet("background: green");

    this->maxon_motor1_currentmode_button = new QPushButton(this);
    this->maxon_motor1_currentmode_button->setGeometry(0.5*width_scale, 55*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_currentmode_button->setText("力矩模式");
    this->maxon_motor1_currentmode_setVelocity_label = new QLabel(this);
    this->maxon_motor1_currentmode_setVelocity_label->setGeometry(0.5*width_scale, 58*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_currentmode_setVelocity_label->setText("设置电流参数");
    this->maxon_motor1_currentmode_setVelocity_text = new QLineEdit(this);
    this->maxon_motor1_currentmode_setVelocity_text->setGeometry(5*width_scale, 58*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor1_currentmode_setVelocity_text->setText(QString("0"));
    this->maxon_motor1_currentmode_setVelocity_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor1_currentmode_setVelocity_text->setStyleSheet("background: green");
    this->maxon_motor1_currentmode_unit_label = new QLabel(this);
    this->maxon_motor1_currentmode_unit_label->setGeometry(10*width_scale, 58*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor1_currentmode_unit_label->setText("mA");
    this->maxon_motor1_currentmode_startmove_button = new QPushButton(this);
    this->maxon_motor1_currentmode_startmove_button->setGeometry(0.5*width_scale, 61*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor1_currentmode_startmove_button->setText(QString("设置电流"));
    this->maxon_motor1_currentmode_startmove_button->setStyleSheet("background: green");

    //! motor2
    this->maxon_motor2_label = new QLabel(this);
    this->maxon_motor2_label->setGeometry(20*width_scale, 0.5*height_scale, 3*width_scale, 2*height_scale);
    this->maxon_motor2_label->setText("motor2");
    this->maxon_motor2_position_label = new QLabel(this);
    this->maxon_motor2_position_label->setGeometry(24.5*width_scale, 0.5*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_position_label->setText("pos(mm)");
    this->maxon_motor2_position_label->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_velocity_label = new QLabel(this);
    this->maxon_motor2_velocity_label->setText("vel(mm/s)");
    this->maxon_motor2_velocity_label->setGeometry(30.5*width_scale, 0.5*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_velocity_label->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_enable_button = new QPushButton(this);
    this->maxon_motor2_enable_button->setGeometry(20*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_enable_button->setStyleSheet("background: green");
    this->maxon_motor2_enable_button->setText("disable");
    this->maxon_motor2_current_position = new QLabel(this);
    this->maxon_motor2_current_position->setGeometry(24.5*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_current_position->setText("0");
    this->maxon_motor2_current_position->setStyleSheet("background: green");
    this->maxon_motor2_current_position->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_current_velocity = new QLabel(this);
    this->maxon_motor2_current_velocity->setText("0");
    this->maxon_motor2_current_velocity->setGeometry(30.5*width_scale, 4*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_current_velocity->setStyleSheet("background: green");
    this->maxon_motor2_current_velocity->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_velocitymode_button = new QPushButton(this);
    this->maxon_motor2_velocitymode_button->setGeometry(20*width_scale, 9*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_button->setText("规划速度模式");
    this->maxon_motor2_velocitymode_setVelocity_label = new QLabel(this);
    this->maxon_motor2_velocitymode_setVelocity_label->setGeometry(20*width_scale, 12*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_setVelocity_label->setText("设置速度");
    this->maxon_motor2_velocitymode_setVelocity_text = new QLineEdit(this);
    this->maxon_motor2_velocitymode_setVelocity_text->setGeometry(24.5*width_scale, 12*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_setVelocity_text->setText(QString("0"));
    this->maxon_motor2_velocitymode_setVelocity_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_velocitymode_setVelocity_text->setStyleSheet("background: green");
    this->maxon_motor2_velocitymode_unit_label = new QLabel(this);
    this->maxon_motor2_velocitymode_unit_label->setGeometry(29.5*width_scale, 12*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_unit_label->setText("mm/s");
    this->maxon_motor2_velocitymode_startmove_button = new QPushButton(this);
    this->maxon_motor2_velocitymode_startmove_button->setGeometry(20*width_scale, 15*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_startmove_button->setText(QString("velocity移动"));
    this->maxon_motor2_velocitymode_startmove_button->setStyleSheet("background: green");
    this->maxon_motor2_velocitymode_stop_button = new QPushButton(this);
    this->maxon_motor2_velocitymode_stop_button->setGeometry(27.5*width_scale, 15*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_velocitymode_stop_button->setText(QString("velocity停止"));
    this->maxon_motor2_velocitymode_stop_button->setStyleSheet("background: green");
    this->maxon_motor2_positionmode_button = new QPushButton(this);
    this->maxon_motor2_positionmode_button->setGeometry(20*width_scale, 22*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_positionmode_button->setText("规划位置模式");
    this->maxon_motor2_absposition_radiaoButton = new QRadioButton(this);
    this->maxon_motor2_absposition_radiaoButton->setGeometry(20*width_scale, 25*height_scale, 1*width_scale, 2*height_scale);
    this->maxon_motor2_absposition_label = new QLabel(this);
    this->maxon_motor2_absposition_label->setGeometry(21.5*width_scale, 25*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_absposition_label->setText("绝对位置");
    this->maxon_motor2_absposition_text = new QLineEdit(this);
    this->maxon_motor2_absposition_text->setGeometry(26*width_scale, 25*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_absposition_text->setText(QString("0"));
    this->maxon_motor2_absposition_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_absposition_text->setStyleSheet("background: green");
    this->maxon_motor2_asbposition_unit_label = new QLabel(this);
    this->maxon_motor2_asbposition_unit_label->setGeometry(31*width_scale, 25*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor2_asbposition_unit_label->setText("mm");
    this->maxon_motor2_absposition_radiaoButton = new QRadioButton(this);
    this->maxon_motor2_absposition_radiaoButton->setGeometry(20*width_scale, 28*height_scale, 1*width_scale, 2*height_scale);
    this->maxon_motor2_relposition_label = new QLabel(this);
    this->maxon_motor2_relposition_label->setGeometry(21.5*width_scale, 28*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_relposition_label->setText("相对位置");
    this->maxon_motor2_relposition_text = new QLineEdit(this);
    this->maxon_motor2_relposition_text->setGeometry(26*width_scale, 28*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_relposition_text->setText(QString("0"));
    this->maxon_motor2_relposition_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_relposition_text->setStyleSheet("background: green");
    this->maxon_motor2_relposition_unit_label = new QLabel(this);
    this->maxon_motor2_relposition_unit_label->setGeometry(31*width_scale, 28*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor2_relposition_unit_label->setText("mm");
    this->maxon_motor2_positionmode_velocity_label = new QLabel(this);
    this->maxon_motor2_positionmode_velocity_label->setGeometry(20*width_scale, 31*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor2_positionmode_velocity_label->setText("速度");
    this->maxon_motor2_positionmode_velocity_text = new QLineEdit(this);
    this->maxon_motor2_positionmode_velocity_text->setGeometry(23*width_scale, 31*height_scale, 4*width_scale, 2*height_scale);
    this->maxon_motor2_positionmode_velocity_text->setText(QString("0"));
    this->maxon_motor2_positionmode_velocity_text->setAlignment(Qt::AlignCenter);
    this->maxon_motor2_positionmode_velocity_text->setStyleSheet("background: green");
    this->maxon_motor2_asbposition_velocity_unit_label = new QLabel(this);
    this->maxon_motor2_asbposition_velocity_unit_label->setGeometry(28*width_scale, 31*height_scale, 2*width_scale, 2*height_scale);
    this->maxon_motor2_asbposition_velocity_unit_label->setText("mm/s");
    this->maxon_motor2_asbpositionmode_startmove_button = new QPushButton(this);
    this->maxon_motor2_asbpositionmode_startmove_button->setGeometry(20*width_scale, 34.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_asbpositionmode_startmove_button->setText("asbpos移动");
    this->maxon_motor2_asbpositionmode_startmove_button->setStyleSheet("background: green");
    this->maxon_motor2_positionmode_halt_button = new QPushButton(this);
    this->maxon_motor2_positionmode_halt_button->setGeometry(27.5*width_scale, 34.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_positionmode_halt_button->setText("position停止");
    this->maxon_motor2_positionmode_halt_button->setStyleSheet("background: green");
    this->maxon_motor2_relpositionmode_startmove_button = new QPushButton(this);
    this->maxon_motor2_relpositionmode_startmove_button->setGeometry(20*width_scale, 37.5*height_scale, 7*width_scale, 2*height_scale);
    this->maxon_motor2_relpositionmode_startmove_button->setText("relpos移动");
    this->maxon_motor2_relpositionmode_startmove_button->setStyleSheet("background: green");

    this->hitParticle_button = new QPushButton(this);
    this->hitParticle_button->setGeometry(20*width_scale, 41*height_scale, 7*width_scale, 2*height_scale);
    this->hitParticle_button->setText("hit Particle");
    this->hitParticle_button->setStyleSheet("background: green");

    //! enable
    this->maxon_motor_enable_button = new QPushButton(this);
    this->maxon_motor_enable_button->setGeometry(40*width_scale, 0.5*height_scale, 8*width_scale, 4*height_scale);
    this->maxon_motor_enable_button->setText(QString("打开伺服"));
    this->maxon_motor_enable_button->setStyleSheet("background: green");

    this->omage_test_button = new QPushButton(this);
    this->omage_test_button->setGeometry(40*width_scale, 5*height_scale, 8*width_scale, 4*height_scale);
    this->omage_test_button->setText(QString("omega"));
    this->omage_test_button->setStyleSheet("background: green");

    this->gravityButton = new QPushButton(this);
    this->gravityButton->setGeometry(40*width_scale, 10*height_scale, 8*width_scale, 4*height_scale);
    this->gravityButton->setText(QString("gravity"));
    this->gravityButton->setStyleSheet("background: green");

    this->startFollowControlButton = new QPushButton(this);
    this->startFollowControlButton->setGeometry(40*width_scale, 15*height_scale, 8*width_scale, 4*height_scale);
    this->startFollowControlButton->setText(QString("Start Follow"));
    this->startFollowControlButton->setStyleSheet("background: green");


    //force show
    this->forceSensorLabel = new QLabel(this);
    this->forceSensorLabel->setGeometry(50*width_scale, 0.5*height_scale, 2*width_scale, 2*height_scale);
    this->forceSensorLabel->setText("Force");
    this->forceSensorLabel->setAlignment(Qt::AlignCenter);
    this->forceSensorShowLabel = new QLabel(this);
    this->forceSensorShowLabel->setGeometry(52.5*width_scale, 0.5*height_scale, 4*width_scale, 2*height_scale);
    this->forceSensorShowLabel->setText("0");
    this->forceSensorShowLabel->setAlignment(Qt::AlignCenter);
    this->forceSensorShowLabel->setStyleSheet("background: green");
    this->forceSensorLabel = new QLabel(this);
    this->forceSensorLabel->setGeometry(57*width_scale, 0.5*height_scale, 2*width_scale, 2*height_scale);
    this->forceSensorLabel->setText("mN");
    this->forceSensorLabel->setAlignment(Qt::AlignCenter);

    this->init();
}

void MainWindow::init(){
    maxonMotor1 = new MaxonMotor(1);
    this->maxonMotor1->SetDirection(false);
    maxonMotor1->initMachPara(1000*4, 33, 2);
    maxonMotor2 = new MaxonMotor(2);
    maxonMotor2->SetDirection(true);
    maxonMotor2->initMachPara(512*4, 19.2*1.33, 37.68);

    m_omegaFunc = new OmegaFunction();
    omega_win = new omega(m_omegaFunc);

    forceSensor = new ForceSensor("COM7", 9600, 'N', 8, 1);
    this->enableF = false;
    this->m_isFollow = false;
    this->m_done = true;
    this->forceSBT = 0;

    this->interFaceInit();
    this->connect(maxon_motor1_enable_button, SIGNAL(clicked()), this, SLOT(motor1_enable()));
    this->connect(maxon_motor2_enable_button, SIGNAL(clicked()), this, SLOT(motor2_enable()));
    this->connect(maxon_motor1_profileVelocitymode_button, SIGNAL(clicked()), this, SLOT(set_motor1_profileVelmode()));
    this->connect(maxon_motor2_velocitymode_button, SIGNAL(clicked()), this, SLOT(set_motor2_ProfileVelMode()));
    this->connect(maxon_motor1_velocitymode_button, SIGNAL(clicked()), this, SLOT(set_motor1_velocityMode()));
    this->connect(maxon_motor1_currentmode_startmove_button, SIGNAL(clicked()), this, SLOT(motor1_currentmode_move()));
    this->connect(maxon_motor1_currentmode_button, SIGNAL(clicked()), this, SLOT(set_motor1_currentMode()));
    this->connect(maxon_motor1_velocitymode_startmove_button, SIGNAL(clicked()), this, SLOT(motor1_velocitymode_move()));
    this->connect(maxon_motor1_velocitymode_stop_button, SIGNAL(clicked()), this, SLOT(motor1_velocitymode_halt()));
    this->connect(maxon_motor1_profileVelocitymode_startmove_button, SIGNAL(clicked()), this, SLOT(motor1_profileVelocitymode_move()));
    this->connect(maxon_motor2_velocitymode_startmove_button, SIGNAL(clicked()), this, SLOT(motor2_velocitymode_move()));
    this->connect(maxon_motor1_profileVelocitymode_stop_button, SIGNAL(clicked()), this, SLOT(motor1_profileVelocitymode_halt()));
    this->connect(maxon_motor2_velocitymode_stop_button, SIGNAL(clicked()), this, SLOT(motor2_velocitymode_halt()));
    this->connect(maxon_motor1_positionmode_button, SIGNAL(clicked()), this, SLOT(set_motor1_profilePosmode()));
    this->connect(maxon_motor2_positionmode_button, SIGNAL(clicked()), this, SLOT(set_motor2_profilePosmode()));
    this->connect(maxon_motor1_asbpositionmode_startmove_button, SIGNAL(clicked()), this, SLOT(motor1_profilePosAbsmove()));
    this->connect(maxon_motor2_asbpositionmode_startmove_button, SIGNAL(clicked()), this, SLOT(motor2_profilePosAbsmove()));
    this->connect(maxon_motor1_relpositionmode_startmove_button, SIGNAL(clicked()), this, SLOT(motor1_profilePosRelmove()));
    this->connect(maxon_motor2_relpositionmode_startmove_button, SIGNAL(clicked()), this, SLOT(motor2_profilePosRelmove()));
    this->connect(maxon_motor1_positionmode_halt_button, SIGNAL(clicked()), this, SLOT(motor1_profilePoshalt()));
    this->connect(maxon_motor2_positionmode_halt_button, SIGNAL(clicked()), this, SLOT(motor2_profilePoshalt()));
    this->connect(maxon_motor1_velocitymode_startmove_button, SIGNAL(clicked()), this, SLOT(motor1_velocitymode_move()));
    this->connect(hitParticle_button, SIGNAL(clicked()), this, SLOT(hit_particle()));
    this->connect(omage_test_button, SIGNAL(clicked()), this, SLOT(omega_show()));
    this->connect(gravityButton, SIGNAL(clicked()), this, SLOT(startGravity()));
    this->connect(startFollowControlButton, SIGNAL(clicked()), this, SLOT(startFollowControl()));

    this->connect(this->paraShowTimer, SIGNAL(timeout()), this, SLOT(showPara()));
}

MainWindow::~MainWindow(){
    this->maxonMotor1->closeDevice();
    this->maxonMotor2->closeDevice();
}
void MainWindow::interFaceInit(){
    this->maxon_motor_enable_button->setDisabled(true);
    //to do ...
    this->maxon_motor1_asbpositionmode_startmove_button->setDisabled(true);
    this->maxon_motor1_relpositionmode_startmove_button->setDisabled(true);
    this->maxon_motor1_positionmode_halt_button->setDisabled(true);
    this->maxon_motor2_asbpositionmode_startmove_button->setDisabled(true);
    this->maxon_motor2_relpositionmode_startmove_button->setDisabled(true);
    this->maxon_motor2_positionmode_halt_button->setDisabled(true);
    this->hitParticle_button->setDisabled(true);
    this->startFollowControlButton->setDisabled(true);
    this->maxon_motor1_velocitymode_startmove_button->setDisabled(true);
    this->maxon_motor1_velocitymode_stop_button->setDisabled(true);
    this->paraShowTimer = new QTimer();
    this->paraShowTimer->start(200);
}

void MainWindow::showPara(){
    double currentPos = maxonMotor1->getCurrentPosition();
    double currentVel = maxonMotor1->getCurrentVelocity();
    maxon_motor1_current_position->setText(QString::number(currentPos));
    maxon_motor1_current_velocity->setText(QString::number(currentVel));

    double currentPos2 = maxonMotor2->getCurrentPosition();
    double currentVel2 = maxonMotor2->getCurrentVelocity();
    maxon_motor2_current_position->setText(QString::number(currentPos2));
    maxon_motor2_current_velocity->setText(QString::number(currentVel2));

//    int force = forceSensor->getCalForce();
    forceSensorShowLabel->setText(QString::number(this->forceSBT));
}

void MainWindow::omega_show(){
    omega_win->show();
}

bool MainWindow::enable(){
    qDebug()<<"enable";
    if(this->enableF){
        if(this->maxonMotor2->enable()&&this->maxonMotor2->enable()){
            this->enableF = true;
            this->maxon_motor_enable_button->setText("关闭使能");
            return true;
        }
        else{
            qDebug()<<"can't enable!";
            return false;
        }
    }
    else{
        if(this->maxonMotor2->disable()&&this->maxonMotor2->disable()){
            this->enableF = false;
            this->maxon_motor_enable_button->setText("打开使能");
            return true;
        }
        else{
            qDebug()<<"failed disable!";
            return false;
        }
    }
}

bool MainWindow::motor1_enable(){
    if(this->maxonMotor1->enableIs()){
        if(this->maxonMotor1->disable()){
            this->maxon_motor1_enable_button->setText("disable");
            return true;
        }else{
            qDebug()<<"failed disable!";
            return false;
        }

    }else{
      if(this->maxonMotor1->enable()){
          this->maxon_motor1_enable_button->setText("enable");
          return true;
      }else{
          qDebug()<<"can't enable!";
          return false;
      }
    }
}

bool MainWindow::set_motor1_profileVelmode(){
    if(0 != this->maxonMotor1->parameter.mode){
        if(this->maxonMotor1->setProfileVelocityMode()){
            this->maxon_motor1_profileVelocitymode_startmove_button->setDisabled(false);
            this->maxon_motor1_profileVelocitymode_stop_button->setDisabled(false);
            this->maxon_motor1_asbpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor1_relpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor1_positionmode_halt_button->setDisabled(true);
            this->maxon_motor1_velocitymode_startmove_button->setDisabled(true);
            this->maxon_motor1_velocitymode_stop_button->setDisabled(true);
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

bool MainWindow::motor1_profileVelocitymode_move(){
    float profileVelmodeVelocity = this->maxon_motor1_profileVelocitymode_setVelocity_text->text().toFloat();
    this->maxonMotor1->setProfileVelocityModeTargetVelocity(profileVelmodeVelocity);
    return this->maxonMotor1->ProfileVelocityStartMove();
}

bool MainWindow::motor1_profileVelocitymode_halt(){
    return this->maxonMotor1->ProfileVelocityHalt();
}

bool MainWindow::set_motor1_profilePosmode(){
    if(0 != this->maxonMotor1->parameter.mode){
        if(this->maxonMotor1->setProfilePositionMode()){
            this->maxon_motor1_profileVelocitymode_startmove_button->setDisabled(true);
            this->maxon_motor1_profileVelocitymode_stop_button->setDisabled(true);
            this->maxon_motor1_asbpositionmode_startmove_button->setDisabled(false);
            this->maxon_motor1_relpositionmode_startmove_button->setDisabled(false);
            this->maxon_motor1_positionmode_halt_button->setDisabled(false);
            this->maxon_motor1_velocitymode_startmove_button->setDisabled(true);
            this->maxon_motor1_velocitymode_stop_button->setDisabled(true);
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

void MainWindow::motor1_profilePosAbsmove(){
    float position = maxon_motor1_absposition_text->text().toFloat();
    float velocity = maxon_motor1_positionmode_velocity_text->text().toFloat();
    this->maxonMotor1->setProfilePosPara(velocity, position);
    this->maxonMotor1->ProfilePositionStartMove();
}

void MainWindow::motor1_profilePosRelmove(){

}

void MainWindow::motor1_profilePoshalt(){
    maxonMotor1->ProfilePositionHalt();
}

bool MainWindow::set_motor1_velocityMode(){
    if(2 != this->maxonMotor1->parameter.mode){
        if(this->maxonMotor1->setVelocityMode()){
            this->maxon_motor1_profileVelocitymode_startmove_button->setDisabled(true);
            this->maxon_motor1_profileVelocitymode_stop_button->setDisabled(true);
            this->maxon_motor1_asbpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor1_relpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor1_positionmode_halt_button->setDisabled(true);
            this->maxon_motor1_velocitymode_startmove_button->setDisabled(false);
            this->maxon_motor1_velocitymode_stop_button->setDisabled(false);
//            this->maxon_motor1_currentmode_button->setDisabled(true);
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

bool MainWindow::set_motor1_currentMode(){
    if(3 != this->maxonMotor1->parameter.mode){
        if(this->maxonMotor1->setCurrentMode()){
            this->maxon_motor1_profileVelocitymode_startmove_button->setDisabled(true);
            this->maxon_motor1_profileVelocitymode_stop_button->setDisabled(true);
            this->maxon_motor1_asbpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor1_relpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor1_positionmode_halt_button->setDisabled(true);
            this->maxon_motor1_velocitymode_startmove_button->setDisabled(false);
            this->maxon_motor1_velocitymode_stop_button->setDisabled(false);
//            this->maxon_motor1_currentmode_button->setDisabled(true);
            qDebug()<<"set_motor1_currentMode";
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

bool MainWindow::motor1_currentmode_move(){
    short profileVelmodeVelocity = this->maxon_motor1_currentmode_setVelocity_text->text().toShort();
    qDebug()<<"motor1_currentmode_move "<<profileVelmodeVelocity;
    return this->maxonMotor1->setCurrentMust(profileVelmodeVelocity);
}

bool MainWindow::motor1_velocitymode_move(){
    qDebug()<<"velocityMode";
    float profileVelmodeVelocity = this->maxon_motor1_velocitymode_setVelocity_text->text().toFloat();
    return this->maxonMotor1->setVelocityModeVelocity(profileVelmodeVelocity);
}

bool MainWindow::motor1_velocitymode_halt(){
    return this->maxonMotor1->setQuickStopState();
}

bool MainWindow::motor2_enable(){
    if(this->maxonMotor2->enableIs()){
        if(this->maxonMotor2->disable()){
            this->maxon_motor2_enable_button->setText("disable");
            return true;
        }else{
            qDebug()<<"failed disable!";
            return false;
        }
    }else{
      if(this->maxonMotor2->enable()){
          this->maxon_motor2_enable_button->setText("enable");
          return true;
      }else{
            qDebug()<<"can't enable!";
            return false;
      }
    }
}

bool MainWindow::set_motor2_ProfileVelMode(){
    if(0 != this->maxonMotor2->m_bMode){
        if(this->maxonMotor2->setProfileVelocityMode()){
            this->maxon_motor2_velocitymode_startmove_button->setDisabled(false);
            this->maxon_motor2_velocitymode_stop_button->setDisabled(false);
            this->maxon_motor2_asbpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor2_relpositionmode_startmove_button->setDisabled(true);
            this->maxon_motor2_positionmode_halt_button->setDisabled(true);
            this->hitParticle_button->setDisabled(true);
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

bool MainWindow::motor2_velocitymode_move(){
    float profileVelmodeVelocity = this->maxon_motor2_velocitymode_setVelocity_text->text().toFloat();
    this->maxonMotor2->setProfileVelocityModeTargetVelocity(profileVelmodeVelocity);
    return this->maxonMotor2->ProfileVelocityStartMove();
}

bool MainWindow::motor2_velocitymode_halt(){
    return this->maxonMotor2->ProfileVelocityHalt();
}

bool MainWindow::set_motor2_profilePosmode(){
    if(0 != this->maxonMotor2->m_bMode){
        if(this->maxonMotor2->setProfilePositionMode()){
            this->maxon_motor2_velocitymode_startmove_button->setDisabled(true);
            this->maxon_motor2_velocitymode_stop_button->setDisabled(true);
            this->maxon_motor2_asbpositionmode_startmove_button->setDisabled(false);
            this->maxon_motor2_relpositionmode_startmove_button->setDisabled(false);
            this->maxon_motor2_positionmode_halt_button->setDisabled(false);
            this->hitParticle_button->setDisabled(false);
            return true;
        }
        else{
            return false;
        }
    }
    return true;
}

void MainWindow::motor2_profilePosAbsmove(){
    float position = maxon_motor2_absposition_text->text().toFloat();
    float velocity = maxon_motor2_positionmode_velocity_text->text().toFloat();
    this->maxonMotor2->setProfilePosPara(velocity, position);
    this->maxonMotor2->ProfilePositionStartMove();
}

void MainWindow::motor2_profilePosRelmove(){

}

void MainWindow::motor2_profilePoshalt(){
    this->maxonMotor2->ProfilePositionHalt();
}

void MainWindow::hit_particle(){
    std::thread t = std::thread([=]{
        float position = maxon_motor2_absposition_text->text().toFloat();
        float velocity = maxon_motor2_positionmode_velocity_text->text().toFloat();
        this->maxonMotor2->setProfilePosPara(velocity, position);
        this->maxonMotor2->ProfilePositionStartMove();
    });
    t.detach();
}

bool MainWindow::halt(){
    return this->maxonMotor2->halt();
}

void MainWindow::go_to_pos1(){
//    coordinatesMovementMoudle->CoordinateMovementModuleMoveTo(758.364, 367.447, 49.646);
    this->maxonMotor2->startMove();
    qDebug()<<"go_pos1";
}

void MainWindow::closeEvent(QCloseEvent * e)
{
    delete omega_win;
    maxonMotor1->closeDevice();
    maxonMotor2->closeDevice();
//    delete maxonMotor1;
//    delete maxonMotor2;
    e->accept();
}


void MainWindow::startGravity(){
    if(m_isFollow) return;
    if(m_done){
        m_done = false;
        std::thread tForce(std::bind(&MainWindow::setForce, this));
        tForce.detach();
    }else{
        m_done = true;
        gravityButton->setText("gravity");
    }

    std::thread velFollow(std::bind(&MainWindow::VelFollow, this));
    velFollow.detach();
}

void MainWindow::VelFollow(){
    //To do
    double Vsd = 0;
    double Vs = 0;
    double Current = 0;
    double kp;
    double t0=0;
    double t;
    double tp = (t-t0)/500;
    for (double i = t0+tp; i < t; i+=tp){
        Vsd += Vs * tp;
    }
    while(true){

    }
    return Vsd*kp;
}

void MainWindow::setForce(){
    gravityButton->setText("running..");

//    int    done  = 0;
    double t1,t0 = dhdGetTime ();

    double p[3];
    double v[3];
    double s[3];
    double g[3];
    double f[3];

    bool   oldButton  = false;
    int    pointCount = 0;
    double point[2][3];

    const double K = 2000.0;
    const double C = 20.0;

    double additionalForce[3] = {0, 0, 0};
    double pushForce[3] = {2};

    // message
    int major, minor, release, revision;
    dhdGetSDKVersion (&major, &minor, &release, &revision);
    printf ("\n");
    printf ("Force Dimension - Segment Constraint Example %d.%d.%d.%d\n", major, minor, release, revision);
    printf ("Copyright (C) 2001-2020 Force Dimension\n");
    printf ("All Rights Reserved.\n\n");

    // open the first available device
    if (dhdOpen () < 0) {
      printf ("error: cannot open device (%s)\n", dhdErrorGetLastStr());
      dhdSleep (2.0);
      return;
    }

    // identify device
    printf ("%s device detected\n\n", dhdGetSystemName());

    // display instructions
    printf ("press BUTTON or 'p' to define segment points\n");
    printf ("      'c' to clear current segment constraint\n");
    printf ("      'q' to quit\n\n");

    // enable force and button emulation, disable velocity threshold
    dhdEnableExpertMode ();
    dhdSetVelocityThreshold (0);
    dhdEnableForce (DHD_ON);
    dhdEmulateButton (DHD_ON);

    // loop while the user does not press 'q'
    while (!m_done) {

        // get position and velocity
        dhdGetPosition       (&(p[0]), &(p[1]), &(p[2]));
        dhdGetLinearVelocity (&(v[0]), &(v[1]), &(v[2]));

        // if a segment has been defined
        if (pointCount >= 2) {

            // compute projection of the device position onto segment
            project_point_on_segment (p, point[0], point[1], s);

            // compute guidance force, modeled as a spring+damper system that pulls
            // the device towards its projection on the constraint segment
            for (int i=0; i<3; i++) g[i] = K * (s[i] - p[i]) - C * v[i];

            // project guidance force onto the vector defined by the device position and its projection;
            // this removes all unwanted force components (e.g. viscosity along the "free" direction)
            project_force_on_direction (g, p, s, f);
        }

        // otherwise, apply a null force
        else f[0] = f[1] = f[2] = 0.0;

        //除了限定直线方向的力之外，还需要增加直线方向的力 additionalForce
        f[0] = f[0] + additionalForce[0];
        f[1] = f[1] + additionalForce[1];
        f[2] = f[2] + additionalForce[2];

        // apply force
        if (dhdSetForceAndTorqueAndGripperForce (f[0], f[1], f[2], 0.0, 0.0, 0.0, 0.0) < DHD_NO_ERROR) {
            printf ("error: cannot set force (%s)\n", dhdErrorGetLastStr());
            m_done = true;
        }

        // user interface
        t1 = dhdGetTime ();
        if ((t1-t0) > REFRESH_INTERVAL) {

            bool button   = false;
            bool setPoint = false;

            // check for user input (button and keyboard)
            if (dhdGetButton (0) == DHD_ON) button   = true;
            if (oldButton && !button)       setPoint = true;
            oldButton = button;
            if (dhdKbHit()) {
                switch (dhdKbGet()) {
                case 'q': m_done     = true;     break;
                case 'p': setPoint   = true;  break;
                case 'c': pointCount = 0;     break;
                }
            }

            // define point if requested
            if (pointCount < 2 && setPoint) {
                point[pointCount][0] = p[0];
                point[pointCount][1] = p[1];
                point[pointCount][2] = p[2];
                pointCount++;
            }

            // display instructions
            if (pointCount == 0) printf ("Please define first segment point  \r");
            if (pointCount == 1) printf ("Please define second segment point \r");
            if (pointCount >= 2){
                //printf ("Press 'c' clear                    \r");
                //刚开始定义两个点的线段，之后以这条线段为单轴进行运动
                //在选定的线段上，按照此方向增加0.5N的力
                project_force_on_direction(pushForce, point[0], point[1], additionalForce);
//                qDebug()<<"additionalForce "<<additionalForce[0]<<additionalForce[1]<<additionalForce[2];
            }

            // update timestamp
            t0 = t1;
        }
    }

    // close the connection
    dhdClose ();

    // happily exit
    printf ("done.                              \n");
    return;

/*
//    startFollowControlButton->setDisabled(false);
    m_done = false;
    double px, py, pz;
    double fx, fy, fz;
    double t1,t0  = dhdGetTime ();
    // open the first available device
    if (!m_omegaFunc->drdOpenOmega()) {
      dhdSleep (2.0);
      return;
    }
    if(!m_omegaFunc->omegaDrdIsSupport()) return;
    if(!m_omegaFunc->omegaDrdAutoInit()) return;
    else if(!m_omegaFunc->omegaDrdStart()) return;
    double nullPos[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    m_omegaFunc->omegaDrdMoveTo(nullPos);
    m_omegaFunc->omegaDrdStop(true);
    // haptic loop
    while (!m_done) {
      // apply zero force
      if (m_omegaFunc->omegaDrdSetForceAndTorqueAndGripperForce(this->forceSBT, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0) < DHD_NO_ERROR) {
        printf ("error: cannot set force (%s)\n", dhdErrorGetLastStr());
        m_done = true;
      }
      // display refresh rate and position at 10Hz
      t1 = dhdGetTime ();
      if ((t1-t0) > 0.01) {
        // update timestamp
        t0 = t1;
        this->forceSBT = forceSensor->getCalForce()/2000.0;
        if(m_isFollow){
            omegaFollow();
        }
      }
    }
    // close the connection
    m_omegaFunc->drdCloseOmega();

    gravityButton->setText("gravity");
    startFollowControlButton->setDisabled(true);
    // happily exit
    return;
    */
}

void MainWindow::startFollowControl(){

    //To do....
//    while (true) {
        //this->forceSBT = this->forceSensor->getCalForce();
//        pushForce[0] = this->forceSBT/2000.0;
//        pushForce[1] = this->forceSBT/2000.0;
//        pushForce[2] = this->forceSBT/2000.0;

//    }
}

//2021.08.04 quanzeng 远端pid位置跟随
/*
void MainWindow::omegaFollow1(){
    //to do....
    // e = (Xm - Xm0) - K(Xs - Xs0)
    double Kp = 1, Kd = 0.5, K = 10;
    double KdKInverse = 1/(Kd*K);
    double KInverse = 1/K;
    double XsSpeed = 0;
    double XmPos, YmPos, ZmPos;
    // retrieve position
    recordeOmegaPos(&XmPos, &YmPos, &ZmPos);
    double XmSpeed, YmSpeed, ZmSpeed;
    recordeOmegaVel(&XmSpeed, &YmSpeed, &ZmSpeed);
    double XsPos = maxonMotor1->getCurrentPosition();
    XsSpeed = KInverse*XmSpeed + KdKInverse*(Kp*(XmPos - XmPosInit) - K*(XsPos - XsPosInit));
//    qDebug()<<"XsSpeed: "<<XsSpeed;
    maxonMotor1->setVelocityModeVelocity(XsSpeed);
}

void MainWindow::startFollowControl(){
    if(!m_isFollow){
        bool rnt = maxonMotor1->enable();
        rnt = maxonMotor1->setVelocityMode();
        //quanzeng 2021.07.15 记录当前omega的当前位置
        recordeOmegaPos(&XmPosInit, &YmPosInit, &ZmPosInit);
        XsPosInit = maxonMotor1->getCurrentPosition();
        startFollowControlButton->setText("running..");
        m_isFollow = true;
//        qDebug()<<"XmPosInit:"<<XmPosInit<<" "<<"YmPosInit:"<<YmPosInit<<" "<<"ZmPosInit:"<<ZmPosInit<<"XsPosInit:"<<XsPosInit;
    }else{
        maxonMotor1->setQuickStopState();
        maxonMotor1->disable();

        startFollowControlButton->setText("Start Follow");
        m_isFollow = false;
    }
}
*/


