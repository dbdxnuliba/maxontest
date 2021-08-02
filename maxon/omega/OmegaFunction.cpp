#include "OmegaFunction.h"
#include <qdebug.h>

OmegaFunction::OmegaFunction()
{
    this->init();
}

void OmegaFunction::init(){
    m_isOpen = false;

}

bool OmegaFunction::openOmega(){
    if (dhdOpen () < 0) {
        dhdSleep (2.0);
        m_isOpen = false;
        return false;
    }
    m_isOpen = true;
    return true;
}

bool OmegaFunction::closeOmega(){
    if(dhdClose() < 0){
        m_isOpen = true;
        return false;
    }
    m_isOpen = false;
    return true;
}

bool OmegaFunction::getForceAndTorque(double *fx, double *fy, double *fz, double *tx, double *ty, double *tz, char ID){
    if (dhdGetForceAndTorque (fx, fy, fz, tx, ty, tz) < DHD_NO_ERROR) {
        return false;
    }
    return true;
}

bool OmegaFunction::getForce(double *fx, double *fy, double *fz){
    if (dhdGetForce (fx, fy, fz) < DHD_NO_ERROR) {
        return false;
    }
    return true;
}

bool OmegaFunction::getPositionAndOrientationDeg(double *px, double *py, double *pz, double *oa, double *ob, double *og, char ID){
    if (dhdGetPositionAndOrientationDeg(px, py, pz, oa, ob, og) < DHD_NO_ERROR) {
        return false;
    }
    return true;
}

bool OmegaFunction::getPosition(double *px, double *py, double *pz){
    if (dhdGetPosition(px, py, pz) < DHD_NO_ERROR) {
        return false;
    }
    return true;
}

bool OmegaFunction::getLinearVelocity(double* px, double* py, double* pz){
    if (dhdGetLinearVelocity(px, py, pz) < DHD_NO_ERROR) {
        return false;
    }
    return true;
}

int OmegaFunction::getButton(){
    return dhdGetButton(0);
}

int OmegaFunction::enableForceMode(){
    return dhdEnableForce(DHD_ON);
}

int OmegaFunction::disableForceMode(){
    return dhdEnableForce(DHD_OFF);
}

bool OmegaFunction::setForceAndTorqueAndGripperForce(double fx, double fy, double fz, double tx, double ty, double tz, double fg, char ID){
    if (dhdSetForceAndTorqueAndGripperForce (fx, fy, fz, tx, ty, tz, fg) < DHD_NO_ERROR) {
//        qDebug()<<"failed!";
        return false;
    }
    return true;
}

bool OmegaFunction::setForce(double fx, double fy, double fz, char ID){
    if (dhdSetForce(fx, fy, fz) < DHD_NO_ERROR) {
        return false;
    }
    return true;
}

bool OmegaFunction::drdOpenOmega(){
    if(drdOpen()<0) return false;
    return true;
}

bool OmegaFunction::drdCloseOmega(){
    if(drdClose()<0) return false;
    return true;
}

bool OmegaFunction::omegaDrdIsSupport(){
    if (!drdIsSupported ()) {
        dhdSleep (2.0);
        drdClose ();
        return false;
      }
    return true;
}

bool OmegaFunction::omegaDrdAutoInit(){
    if (!drdIsInitialized () && drdAutoInit () < 0) {
        dhdSleep (2.0);
        drdClose();
        return false;
      }
    return true;
}

bool OmegaFunction::omegaDrdStart(){
    if (drdStart () < 0) {
        dhdSleep (2.0);
        return false;
      }
    return true;
}

bool OmegaFunction::omegaDrdStop(bool IsKeepForce){
    if (drdStop(IsKeepForce) < 0) {
        dhdSleep (2.0);
        return false;
      }
    return true;
}

bool OmegaFunction::omegaDrdMoveTo(double *pos){
    if (drdMoveTo(pos) < 0) {
        dhdSleep (2.0);
        return false;
      }
    return true;
}

bool OmegaFunction::omegaDrdMoveToPos(double posx, double posy, double posz){
    if (drdMoveToPos(posx, posy, posz) < 0) {
        dhdSleep (2.0);
        return false;
      }
    return true;
}

bool OmegaFunction::omegaDrdSetForceAndTorqueAndGripperForce(double fx, double fy, double fz, double tx, double ty, double tz, double fg, char ID){
    if (drdSetForceAndTorqueAndGripperForce(fx, fy, fz, tx, ty, tz, fg) < 0) {
        dhdSleep (2.0);
        return false;
      }
    return true;
}

bool OmegaFunction::omegaDrdGetPos(double* xPos, double* yPos, double* zPos, double* theta1, double* theta2, double* theta3, double* gPos){
    double matrix[3][3]={0.0, 0.0, 0.0,
                         0.0, 0.0, 0.0,
                         0.0, 0.0, 0.0
    };
    if (drdGetPositionAndOrientation(xPos, yPos, zPos, theta1, theta2, theta3, gPos, matrix) < 0) {
        dhdSleep (2.0);
        return false;
      }
    return true;
}

bool OmegaFunction::omegaDrdGetVel(double* xVel, double* yVel, double* zVel, double* theta1Vel, double* theta2Vel, double* theta3Vel, double* gVel){
    if (drdGetVelocity(xVel, yVel, zVel, theta1Vel, theta2Vel, theta3Vel, gVel) < 0) {
        dhdSleep (2.0);
        return false;
      }
    return true;
}
