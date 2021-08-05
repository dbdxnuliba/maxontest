#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QThread>
#include <QTimer>
#include <thread>
#include <QLineEdit>
#include <QRadioButton>
#include "MaxonMotor.h"
#include "omega.h"
#include "omega/OmegaFunction.h"
#include "ForceSensor/ForceSensor.h"
#include "functioncustom.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    void init();
    void interFaceInit();

protected:
    void closeEvent(QCloseEvent *event);
    void setForce();
    void VelFollow();
    void omegaFollow();

public slots:
    bool enable();
    bool motor1_enable();
    bool motor2_enable();
    bool set_motor1_profileVelmode();
    bool set_motor2_ProfileVelMode();
    bool motor1_profileVelocitymode_move();
    bool motor2_velocitymode_move();
    bool motor1_profileVelocitymode_halt();
    bool motor2_velocitymode_halt();
    bool set_motor1_profilePosmode();
    bool set_motor2_profilePosmode();
    void motor1_profilePosAbsmove();
    void motor2_profilePosAbsmove();
    void motor1_profilePosRelmove();
    void motor2_profilePosRelmove();
    void motor1_profilePoshalt();
    bool set_motor1_velocityMode();
    bool motor1_velocitymode_move();
    bool motor1_velocitymode_halt();
    void motor2_profilePoshalt();
    bool set_motor1_currentMode();
    bool motor1_currentmode_move();
    bool halt();
    void go_to_pos1();
    void hit_particle();
    void startGravity();
    void startFollowControl();

    void showPara();
    void omega_show();
private:
    QLabel* maxon_motor1_label;
    QLabel* maxon_motor1_position_label;
    QLabel* maxon_motor1_velocity_label;
    QPushButton* maxon_motor1_enable_button;
    QLabel* maxon_motor1_current_position;
    QLabel* maxon_motor1_current_velocity;
    QPushButton* maxon_motor1_profileVelocitymode_button;
    QLabel* maxon_motor1_profileVelocitymode_setVelocity_label;
    QPushButton* maxon_motor_enable_button;
    QPushButton* omage_test_button;
    QPushButton* gravityButton;
    QPushButton* startFollowControlButton;
    QLabel* forceSensorLabel;
    QLabel* forceSensorShowLabel;
    QPushButton* maxon_motor1_profileVelocitymode_startmove_button;
    QPushButton* maxon_motor1_profileVelocitymode_stop_button;
    QPushButton* maxon_motor1_positionmode_button;
    QRadioButton* maxon_motor1_absposition_radiaoButton;
    QLabel* maxon_motor1_absposition_label;
    QLineEdit* maxon_motor1_absposition_text;
    QLabel* maxon_motor1_asbposition_unit_label;
    QLabel* maxon_motor1_positionmode_velocity_label;
    QLineEdit* maxon_motor1_positionmode_velocity_text;
    QLabel* maxon_motor1_asbposition_velocity_unit_label;
    QLabel* maxon_motor1_relposition_label;
    QLineEdit* maxon_motor1_relposition_text;
    QLabel* maxon_motor1_relposition_unit_label;
    QPushButton* maxon_motor1_asbpositionmode_startmove_button;
    QPushButton* maxon_motor1_relpositionmode_startmove_button;
    QPushButton* maxon_motor1_velocitymode_button;
    QLabel* maxon_motor1_velocitymode_setVelocity_label;
    QLineEdit* maxon_motor1_velocitymode_setVelocity_text;
    QLabel* maxon_motor1_velocitymode_unit_label;
    QPushButton* maxon_motor1_velocitymode_startmove_button;
    QPushButton* maxon_motor1_velocitymode_stop_button;
    QPushButton* maxon_motor1_positionmode_halt_button;
    QLineEdit* maxon_motor1_profileVelocitymode_setVelocity_text;
    QLabel* maxon_motor1_profileVelocitymode_unit_label;
    QPushButton* maxon_motor1_currentmode_button;
    QLabel* maxon_motor1_currentmode_setVelocity_label;
    QLineEdit* maxon_motor1_currentmode_setVelocity_text;
    QLabel* maxon_motor1_currentmode_unit_label;
    QPushButton* maxon_motor1_currentmode_startmove_button;


    QLabel* maxon_motor2_label;
    QLabel* maxon_motor2_position_label;
    QLabel* maxon_motor2_velocity_label;
    QPushButton* maxon_motor2_enable_button;
    QLabel* maxon_motor2_current_position;
    QLabel* maxon_motor2_current_velocity;
    QPushButton* maxon_motor2_velocitymode_button;
    QLabel* maxon_motor2_velocitymode_setVelocity_label;
    QPushButton* maxon_motor2_velocitymode_startmove_button;
    QPushButton* maxon_motor2_velocitymode_stop_button;
    QPushButton* maxon_motor2_positionmode_button;
    QRadioButton* maxon_motor2_absposition_radiaoButton;
    QLabel* maxon_motor2_absposition_label;
    QLineEdit* maxon_motor2_absposition_text;
    QLabel* maxon_motor2_asbposition_unit_label;
    QLabel* maxon_motor2_positionmode_velocity_label;
    QLineEdit* maxon_motor2_positionmode_velocity_text;
    QLabel* maxon_motor2_asbposition_velocity_unit_label;
    QLabel* maxon_motor2_relposition_label;
    QLineEdit* maxon_motor2_relposition_text;
    QLabel* maxon_motor2_relposition_unit_label;
    QPushButton* maxon_motor2_asbpositionmode_startmove_button;
    QPushButton* maxon_motor2_relpositionmode_startmove_button;
    QPushButton* maxon_motor2_positionmode_halt_button;
    QLineEdit* maxon_motor2_velocitymode_setVelocity_text;
    QLabel* maxon_motor2_velocitymode_unit_label;
    QPushButton* hitParticle_button;

    MaxonMotor* maxonMotor1;
    MaxonMotor* maxonMotor2;
    bool enableF;
    bool m_isFollow;
    bool m_done;
    double XmPosInit, YmPosInit, ZmPosInit;
    double XsPosInit;
    QTimer* paraShowTimer;
    omega* omega_win;
    OmegaFunction* m_omegaFunc;
    ForceSensor* forceSensor;

    double forceSBT;
public:
    explicit MainWindow();
    ~MainWindow();
};

#endif // MAINWINDOW_H
