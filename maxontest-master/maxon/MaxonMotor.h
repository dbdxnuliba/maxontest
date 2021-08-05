#ifndef MAXONMOTOR_H
#define MAXONMOTOR_H
#include "Definitions.h"
#include <functional>

typedef struct{
   bool enable = false;
   int mode;
   int speed;
   int position;
   int acceleration;
   int deceleration;
   int resolution;
   double gear_ratio;
   float lead;
} motorParameter;


class MaxonMotor
{
public:
    void init(const char* DeviceName, const char* ProtocolStackName, const char* InterfaceName, const char* PortName, WORD nodeId);
    void init();
    void setGearRatio(double gear_ratio);
    void setLead(float lead);
    double transformQcToPosition(float qc);
    double transformPositionToQc(float position);
    double transformRPMToLineSp(double rpm);
    double transformLineSpToRPM(double lineSp);
    void SetDirection(bool isDirection);
    double sameDirection(double input);
    short sameDirection(short input);
    void setNodeId(int nodeid);
    bool openDevice();
    bool closeDevice();
    void initMachPara(int resolution, double gear_ratio, float lead);
    bool enable();
    bool disable();
    bool enableIs();
    bool m_isDirection;

    bool setProfilePositionMode();
    bool setProfilePosPara(double vel, double pos);
    void setProfileVelocityModeTargetVelocity(double profileVelocity);
    bool ProfilePositionStartMove();
    bool ProfilePositionHalt();

    bool setProfileVelocityMode();
    bool ProfileVelocityStartMove();
    bool ProfileVelocityStartMove(double profileVelocity);
    bool ProfileVelocityHalt();

    bool setVelocityMode();
    bool setVelocityModeVelocity(double velocityMust);
    bool setQuickStopState();


    double getCurrentPosition();
    double getCurrentVelocity();

    bool setCurrentMode();
    bool setCurrentMust(short currentMust);

    bool startMove();
    bool halt();

public:
    motorParameter parameter;

    int     m_oRadio;
    double  m_lActualPosition;
    long    m_lStartPosition;
    long    m_ProfilePosModeAbsPosition;
    long    m_ProfilePosModeVelocity;
    double  m_lActualVelocity;
    double  m_ProfileVelModeVelocity;
    __int8  m_bMode;
    BOOL    m_oImmediately;
    BOOL    m_oInitialisation;
    BOOL    m_oUpdateActive;
    DWORD   m_ulErrorCode;
    DWORD   m_ulProfileAcceleration;
    DWORD   m_ulProfileDeceleration;
    DWORD   m_ulProfileVelocity;
    HANDLE  m_KeyHandle;
    WORD    m_usNodeId;
    char* DeviceName;
    char* ProtocolStackName;
    char* InterfaceName;
    char* PortName;

public:
    MaxonMotor(const char* DeviceName, const char* ProtocolStackName, const char* InterfaceName, const char* PortName, WORD nodeId);
    MaxonMotor(int nodeid);
};

#endif // MAXONMOTOR_H
