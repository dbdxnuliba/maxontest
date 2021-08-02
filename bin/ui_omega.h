/********************************************************************************
** Form generated from reading UI file 'omega.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OMEGA_H
#define UI_OMEGA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_omega
{
public:
    QPushButton *openButton;
    QPushButton *closeButton;
    QGroupBox *groupBox;
    QRadioButton *statusButton;
    QLineEdit *forceZSetEdit;
    QPushButton *setForceButton;
    QLabel *label_2;
    QLineEdit *forceYSetEdit;
    QLabel *label_3;
    QLineEdit *forceXSetEdit;
    QLabel *label_4;
    QGroupBox *groupBox_2;
    QLabel *theta3;
    QLabel *posX;
    QLabel *theta2Label;
    QLabel *theta3Label;
    QLabel *theta1Label;
    QLabel *posY;
    QLabel *posZLabel;
    QLabel *posZ;
    QLabel *theta2;
    QLabel *posXLabel;
    QLabel *posYLabel;
    QLabel *posX_2;
    QLabel *theta1;
    QGroupBox *groupBox_3;
    QLabel *torque3;
    QLabel *posX_4;
    QLabel *forceZ;
    QLabel *torque2;
    QLabel *forceX_2;
    QLabel *torque1_2;
    QLabel *torque1;
    QLabel *forceX;
    QLabel *torque2_2;
    QLabel *forceY_2;
    QLabel *forceZ_2;
    QLabel *forceY;
    QLabel *torque3_2;

    void setupUi(QWidget *omega)
    {
        if (omega->objectName().isEmpty())
            omega->setObjectName(QString::fromUtf8("omega"));
        omega->resize(948, 764);
        openButton = new QPushButton(omega);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(20, 80, 90, 70));
        closeButton = new QPushButton(omega);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(20, 190, 90, 70));
        groupBox = new QGroupBox(omega);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(220, 340, 651, 331));
        statusButton = new QRadioButton(groupBox);
        statusButton->setObjectName(QString::fromUtf8("statusButton"));
        statusButton->setGeometry(QRect(140, 260, 21, 19));
        forceZSetEdit = new QLineEdit(groupBox);
        forceZSetEdit->setObjectName(QString::fromUtf8("forceZSetEdit"));
        forceZSetEdit->setGeometry(QRect(220, 190, 113, 21));
        setForceButton = new QPushButton(groupBox);
        setForceButton->setObjectName(QString::fromUtf8("setForceButton"));
        setForceButton->setGeometry(QRect(20, 30, 90, 70));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 20, 68, 15));
        forceYSetEdit = new QLineEdit(groupBox);
        forceYSetEdit->setObjectName(QString::fromUtf8("forceYSetEdit"));
        forceYSetEdit->setGeometry(QRect(220, 110, 113, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(140, 110, 68, 15));
        forceXSetEdit = new QLineEdit(groupBox);
        forceXSetEdit->setObjectName(QString::fromUtf8("forceXSetEdit"));
        forceXSetEdit->setGeometry(QRect(220, 20, 113, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 190, 68, 15));
        groupBox_2 = new QGroupBox(omega);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(240, 20, 571, 91));
        theta3 = new QLabel(groupBox_2);
        theta3->setObjectName(QString::fromUtf8("theta3"));
        theta3->setGeometry(QRect(490, 60, 68, 15));
        theta3->setAlignment(Qt::AlignCenter);
        posX = new QLabel(groupBox_2);
        posX->setObjectName(QString::fromUtf8("posX"));
        posX->setGeometry(QRect(90, 60, 68, 15));
        posX->setAlignment(Qt::AlignCenter);
        theta2Label = new QLabel(groupBox_2);
        theta2Label->setObjectName(QString::fromUtf8("theta2Label"));
        theta2Label->setGeometry(QRect(410, 20, 68, 15));
        theta2Label->setAlignment(Qt::AlignCenter);
        theta3Label = new QLabel(groupBox_2);
        theta3Label->setObjectName(QString::fromUtf8("theta3Label"));
        theta3Label->setGeometry(QRect(490, 20, 68, 15));
        theta3Label->setAlignment(Qt::AlignCenter);
        theta1Label = new QLabel(groupBox_2);
        theta1Label->setObjectName(QString::fromUtf8("theta1Label"));
        theta1Label->setGeometry(QRect(330, 20, 68, 15));
        theta1Label->setAlignment(Qt::AlignCenter);
        posY = new QLabel(groupBox_2);
        posY->setObjectName(QString::fromUtf8("posY"));
        posY->setGeometry(QRect(170, 60, 68, 15));
        posY->setAlignment(Qt::AlignCenter);
        posZLabel = new QLabel(groupBox_2);
        posZLabel->setObjectName(QString::fromUtf8("posZLabel"));
        posZLabel->setGeometry(QRect(250, 20, 68, 15));
        posZLabel->setAlignment(Qt::AlignCenter);
        posZ = new QLabel(groupBox_2);
        posZ->setObjectName(QString::fromUtf8("posZ"));
        posZ->setGeometry(QRect(250, 60, 68, 15));
        posZ->setAlignment(Qt::AlignCenter);
        theta2 = new QLabel(groupBox_2);
        theta2->setObjectName(QString::fromUtf8("theta2"));
        theta2->setGeometry(QRect(410, 60, 68, 15));
        theta2->setAlignment(Qt::AlignCenter);
        posXLabel = new QLabel(groupBox_2);
        posXLabel->setObjectName(QString::fromUtf8("posXLabel"));
        posXLabel->setGeometry(QRect(90, 20, 68, 15));
        posXLabel->setAlignment(Qt::AlignCenter);
        posYLabel = new QLabel(groupBox_2);
        posYLabel->setObjectName(QString::fromUtf8("posYLabel"));
        posYLabel->setGeometry(QRect(170, 20, 68, 15));
        posYLabel->setAlignment(Qt::AlignCenter);
        posX_2 = new QLabel(groupBox_2);
        posX_2->setObjectName(QString::fromUtf8("posX_2"));
        posX_2->setGeometry(QRect(0, 60, 68, 15));
        posX_2->setAlignment(Qt::AlignCenter);
        theta1 = new QLabel(groupBox_2);
        theta1->setObjectName(QString::fromUtf8("theta1"));
        theta1->setGeometry(QRect(330, 60, 68, 15));
        theta1->setAlignment(Qt::AlignCenter);
        groupBox_3 = new QGroupBox(omega);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(240, 170, 591, 91));
        torque3 = new QLabel(groupBox_3);
        torque3->setObjectName(QString::fromUtf8("torque3"));
        torque3->setGeometry(QRect(520, 60, 68, 15));
        torque3->setAlignment(Qt::AlignCenter);
        posX_4 = new QLabel(groupBox_3);
        posX_4->setObjectName(QString::fromUtf8("posX_4"));
        posX_4->setGeometry(QRect(10, 60, 95, 15));
        forceZ = new QLabel(groupBox_3);
        forceZ->setObjectName(QString::fromUtf8("forceZ"));
        forceZ->setGeometry(QRect(280, 60, 68, 15));
        forceZ->setAlignment(Qt::AlignCenter);
        torque2 = new QLabel(groupBox_3);
        torque2->setObjectName(QString::fromUtf8("torque2"));
        torque2->setGeometry(QRect(440, 60, 68, 15));
        torque2->setAlignment(Qt::AlignCenter);
        forceX_2 = new QLabel(groupBox_3);
        forceX_2->setObjectName(QString::fromUtf8("forceX_2"));
        forceX_2->setGeometry(QRect(120, 20, 68, 15));
        forceX_2->setAlignment(Qt::AlignCenter);
        torque1_2 = new QLabel(groupBox_3);
        torque1_2->setObjectName(QString::fromUtf8("torque1_2"));
        torque1_2->setGeometry(QRect(360, 20, 68, 15));
        torque1_2->setAlignment(Qt::AlignCenter);
        torque1 = new QLabel(groupBox_3);
        torque1->setObjectName(QString::fromUtf8("torque1"));
        torque1->setGeometry(QRect(360, 60, 68, 15));
        torque1->setAlignment(Qt::AlignCenter);
        forceX = new QLabel(groupBox_3);
        forceX->setObjectName(QString::fromUtf8("forceX"));
        forceX->setGeometry(QRect(120, 60, 68, 15));
        forceX->setAlignment(Qt::AlignCenter);
        torque2_2 = new QLabel(groupBox_3);
        torque2_2->setObjectName(QString::fromUtf8("torque2_2"));
        torque2_2->setGeometry(QRect(440, 20, 68, 15));
        torque2_2->setAlignment(Qt::AlignCenter);
        forceY_2 = new QLabel(groupBox_3);
        forceY_2->setObjectName(QString::fromUtf8("forceY_2"));
        forceY_2->setGeometry(QRect(200, 20, 68, 15));
        forceY_2->setAlignment(Qt::AlignCenter);
        forceZ_2 = new QLabel(groupBox_3);
        forceZ_2->setObjectName(QString::fromUtf8("forceZ_2"));
        forceZ_2->setGeometry(QRect(280, 20, 68, 15));
        forceZ_2->setAlignment(Qt::AlignCenter);
        forceY = new QLabel(groupBox_3);
        forceY->setObjectName(QString::fromUtf8("forceY"));
        forceY->setGeometry(QRect(200, 60, 68, 15));
        forceY->setAlignment(Qt::AlignCenter);
        torque3_2 = new QLabel(groupBox_3);
        torque3_2->setObjectName(QString::fromUtf8("torque3_2"));
        torque3_2->setGeometry(QRect(520, 20, 68, 15));
        torque3_2->setAlignment(Qt::AlignCenter);

        retranslateUi(omega);

        QMetaObject::connectSlotsByName(omega);
    } // setupUi

    void retranslateUi(QWidget *omega)
    {
        omega->setWindowTitle(QCoreApplication::translate("omega", "Omega", nullptr));
        openButton->setText(QCoreApplication::translate("omega", "\345\274\200\345\220\257", nullptr));
        closeButton->setText(QCoreApplication::translate("omega", "\345\205\263\351\227\255", nullptr));
        groupBox->setTitle(QCoreApplication::translate("omega", "SET", nullptr));
        statusButton->setText(QString());
        forceZSetEdit->setText(QCoreApplication::translate("omega", "0", nullptr));
        setForceButton->setText(QCoreApplication::translate("omega", "SetForce", nullptr));
        label_2->setText(QCoreApplication::translate("omega", "forceX", nullptr));
        forceYSetEdit->setText(QCoreApplication::translate("omega", "0", nullptr));
        label_3->setText(QCoreApplication::translate("omega", "forceY", nullptr));
        forceXSetEdit->setText(QCoreApplication::translate("omega", "0", nullptr));
        label_4->setText(QCoreApplication::translate("omega", "forceZ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("omega", "GroupBox", nullptr));
        theta3->setText(QCoreApplication::translate("omega", "0", nullptr));
        posX->setText(QCoreApplication::translate("omega", "0", nullptr));
        theta2Label->setText(QCoreApplication::translate("omega", "theta2", nullptr));
        theta3Label->setText(QCoreApplication::translate("omega", "theta3", nullptr));
        theta1Label->setText(QCoreApplication::translate("omega", "theta1", nullptr));
        posY->setText(QCoreApplication::translate("omega", "0", nullptr));
        posZLabel->setText(QCoreApplication::translate("omega", "Z", nullptr));
        posZ->setText(QCoreApplication::translate("omega", "0", nullptr));
        theta2->setText(QCoreApplication::translate("omega", "0", nullptr));
        posXLabel->setText(QCoreApplication::translate("omega", "X", nullptr));
        posYLabel->setText(QCoreApplication::translate("omega", "Y", nullptr));
        posX_2->setText(QCoreApplication::translate("omega", "pos", nullptr));
        theta1->setText(QCoreApplication::translate("omega", "0", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("omega", "GroupBox", nullptr));
        torque3->setText(QCoreApplication::translate("omega", "0", nullptr));
        posX_4->setText(QCoreApplication::translate("omega", "force/torque", nullptr));
        forceZ->setText(QCoreApplication::translate("omega", "0", nullptr));
        torque2->setText(QCoreApplication::translate("omega", "0", nullptr));
        forceX_2->setText(QCoreApplication::translate("omega", "X", nullptr));
        torque1_2->setText(QCoreApplication::translate("omega", "torque1", nullptr));
        torque1->setText(QCoreApplication::translate("omega", "0", nullptr));
        forceX->setText(QCoreApplication::translate("omega", "0", nullptr));
        torque2_2->setText(QCoreApplication::translate("omega", "torque2", nullptr));
        forceY_2->setText(QCoreApplication::translate("omega", "Y", nullptr));
        forceZ_2->setText(QCoreApplication::translate("omega", "Z", nullptr));
        forceY->setText(QCoreApplication::translate("omega", "0", nullptr));
        torque3_2->setText(QCoreApplication::translate("omega", "torque3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class omega: public Ui_omega {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OMEGA_H
