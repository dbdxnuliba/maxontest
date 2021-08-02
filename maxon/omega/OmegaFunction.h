#ifndef OMEGAFUNCTION_H
#define OMEGAFUNCTION_H
#include"dhdc.h"
#include"drdc.h"

class OmegaFunction
{
public:
    bool openOmega();
    bool closeOmega();
    bool getForceAndTorque(double *fx, double *fy, double *fz, double *tx, double *ty, double *tz, char ID = -1);
    bool getForce(double *fx, double *fy, double *fz);
    bool getPositionAndOrientationDeg(double *px, double *py, double *pz, double *oa, double *ob, double *og, char ID = -1);
    bool getPosition(double *px, double *py, double *pz);
    bool getLinearVelocity(double* px, double* py, double* pz);
    int getButton();
    int enableForceMode();
    int disableForceMode();
    bool setForceAndTorqueAndGripperForce(double fx, double fy, double fz, double tx, double ty, double tz, double fg, char ID = -1);
    bool setForce(double fx, double fy, double fz, char ID = -1);

    bool drdOpenOmega();
    bool drdCloseOmega();
    bool omegaDrdIsSupport();
    bool omegaDrdAutoInit();
    bool omegaDrdStart();
    bool omegaDrdStop(bool IsKeepForce);
    bool omegaDrdMoveTo(double *pos);
    bool omegaDrdMoveToPos(double posx, double posy, double posz);
    bool omegaDrdSetForceAndTorqueAndGripperForce(double fx, double fy, double fz, double tx, double ty, double tz, double fg, char ID=-1);
    bool omegaDrdGetPos(double* xPos, double* yPos, double* zPos, double* theta1, double* theta2, double* theta3, double* gPos);
    bool omegaDrdGetVel(double* xVel, double* yVel, double* zVel, double* theta1Vel, double* theta2Vel, double* theta3Vel, double* gVel);
private:
    void init();

private:
    bool m_isOpen;
public:
    OmegaFunction();

};

#endif // OMEGAFUNCTION_H
