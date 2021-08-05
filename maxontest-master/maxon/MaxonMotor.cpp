#include "MaxonMotor.h"
#include <QDebug>
#include <QMessageBox>

MaxonMotor::MaxonMotor(const char* DeviceName, const char* ProtocolStackName, const char* InterfaceName, const char* PortName, WORD nodeId)
{
    m_oImmediately = TRUE;
    this->init(DeviceName, ProtocolStackName, InterfaceName, PortName, nodeId);
    this->openDevice();
    this->setProfileVelocityMode();
}

MaxonMotor::MaxonMotor(int nodeid){
    this->m_usNodeId = nodeid;
    m_oImmediately = TRUE;
    this->init();
    this->openDevice();
    this->setProfileVelocityMode();
}

void MaxonMotor::init(const char* DeviceName, const char* ProtocolStackName, const char* InterfaceName, const char* PortName, WORD nodeId){
    this->DeviceName = new char[20];
    this->ProtocolStackName = new char[20];
    this->InterfaceName = new char[20];
    this->PortName = new char[20];
    memcpy(this->DeviceName, DeviceName, 6);
    memcpy(this->ProtocolStackName, ProtocolStackName, 16);
    memcpy(this->InterfaceName, InterfaceName, 4);
    memcpy(this->PortName, PortName, 6);
    m_KeyHandle = 0;
    this->m_usNodeId = nodeId;
    this->m_ProfilePosModeAbsPosition = 0;
    this->m_ProfilePosModeVelocity = 0;
    this->m_isDirection = true;

    this->parameter.mode = 999;
    this->parameter.speed = 0;
    this->parameter.enable = false;
    this->parameter.acceleration = 0;
    this->parameter.deceleration = 0;
    this->parameter.resolution = 1024;
    this->parameter.gear_ratio = 1;
    this->parameter.lead = 1;
    this->m_ProfileVelModeVelocity = 0;
}

void MaxonMotor::init(){
    m_KeyHandle = 0;
    this->m_ProfilePosModeAbsPosition = 0;
    this->m_ProfilePosModeVelocity = 0;
    this->m_isDirection = true;

    this->parameter.mode = 999;
    this->parameter.speed = 0;
    this->parameter.enable = false;
    this->parameter.acceleration = 0;
    this->parameter.deceleration = 0;
    this->parameter.resolution = 1024;
    this->parameter.gear_ratio = 1;
    this->parameter.lead = 1;
    this->m_ProfileVelModeVelocity = 0;
}
void MaxonMotor::setGearRatio(double gear_ratio){
    this->parameter.gear_ratio = gear_ratio;
}

void MaxonMotor::setLead(float lead){
    this->parameter.lead = lead;
}

void MaxonMotor::SetDirection(bool isDirection){
    this->m_isDirection = isDirection;
}

double MaxonMotor::sameDirection(double input){
    if(this->m_isDirection) return input;
    else return -1*input;
}

short MaxonMotor::sameDirection(short input){
    if(this->m_isDirection) return input;
    else return -1*input;
}

void MaxonMotor::setNodeId(int nodeid){
    this->m_usNodeId = nodeid;
}

double MaxonMotor::transformQcToPosition(float qc){
    double position = qc * this->parameter.lead / (this->parameter.resolution * this->parameter.gear_ratio);
    position = ((int)(position * pow(10, 3))) / pow(10, 3);
    return position;
}

double MaxonMotor::transformPositionToQc(float position){
    double qc = position * this->parameter.gear_ratio * this->parameter.resolution / this->parameter.lead;
    return qc;
}

double MaxonMotor::transformRPMToLineSp(double rpm){
    double lineSp = transformQcToPosition(this->parameter.resolution * rpm / 60);
    return lineSp;
}

double MaxonMotor::transformLineSpToRPM(double lineSp){
    double rmp = transformPositionToQc(lineSp) * 60/ this->parameter.resolution;
    return rmp;
}

bool MaxonMotor::openDevice(){
//    HANDLE hNewKeyHandle;
    //Close Previous Device
    if(m_KeyHandle)
    {
        if(m_KeyHandle) VCS_CloseDevice(m_KeyHandle, &m_ulErrorCode);
        m_KeyHandle = 0;
    }
    m_KeyHandle = VCS_OpenDeviceDlg(&m_ulErrorCode);
    if(!m_KeyHandle){
//        qDebug()<<"Can't open device!";
//        QMessageBox::information(NULL, "Warning", "Can't OPEN DEVICE!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    return true;
}

bool MaxonMotor::closeDevice(){
    if(VCS_CloseDevice(m_KeyHandle, &m_ulErrorCode)){
        m_KeyHandle = 0;
        return true;
    }
    return false;
}

void MaxonMotor::initMachPara(int resolution, double gear_ratio, float lead){
    this->parameter.resolution = resolution;
    this->parameter.gear_ratio = gear_ratio;
    this->parameter.lead = lead;
}

bool MaxonMotor::enable(){
    BOOL oFault = FALSE;
    if(!VCS_GetFaultState(m_KeyHandle, m_usNodeId, &oFault, &m_ulErrorCode))
    {
        closeDevice();
        return false;
    }
    if(oFault)
    {
        if(!VCS_ClearFault(m_KeyHandle, m_usNodeId, &m_ulErrorCode))
        {
            return false;
        }
    }
    if(!VCS_SetEnableState(m_KeyHandle, m_usNodeId, &m_ulErrorCode))
    {
        qDebug()<<"enable failed!";
        return false;
    }
    this->parameter.enable = true;
    return true;
}

bool MaxonMotor::disable(){
    if(!VCS_SetDisableState(m_KeyHandle, m_usNodeId, &m_ulErrorCode))
    {
        return false;
    }
    this->parameter.enable = false;
    return true;
}

bool MaxonMotor::enableIs(){
    return this->parameter.enable;
}

bool MaxonMotor::setProfilePositionMode(){
    if(m_KeyHandle)
    {
        //Clear Error History
        if(VCS_ClearFault(m_KeyHandle, m_usNodeId, &m_ulErrorCode))
        {
            //Read Operation Mode
            if(VCS_GetOperationMode(m_KeyHandle, m_usNodeId, &m_bMode, &m_ulErrorCode))
            {
                //Read Position Profile Objects
                if(VCS_GetPositionProfile(m_KeyHandle, m_usNodeId, &m_ulProfileVelocity, &m_ulProfileAcceleration, &m_ulProfileDeceleration, &m_ulErrorCode))
                {
                    //Write Profile Position Mode
                    if(VCS_SetOperationMode(m_KeyHandle, m_usNodeId, OMD_PROFILE_POSITION_MODE, &m_ulErrorCode))
                    {
                        this->parameter.mode = 1;
                        return TRUE;
                    }
                }
            }
        }
        closeDevice();
        QMessageBox::information(NULL, "Warning!", "error " + QString::number(m_ulErrorCode), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    else
    {
        QMessageBox::information(NULL, "Warning!", "Don't open device!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
}

bool MaxonMotor::setProfilePosPara(double vel, double pos){
    m_ProfilePosModeVelocity = sameDirection(transformLineSpToRPM(vel));
    m_ProfilePosModeAbsPosition = sameDirection(transformPositionToQc(pos));
    //Write Profile Position Objects
    if(VCS_SetPositionProfile(m_KeyHandle, m_usNodeId, m_ProfilePosModeVelocity, 1000, 1000, &m_ulErrorCode))
    {
        //Read Actual Position
        if(VCS_GetPositionIs(m_KeyHandle, m_usNodeId, &m_lStartPosition, &m_ulErrorCode))
        {
            return TRUE;
        }
    }
    return false;
}

bool MaxonMotor::ProfilePositionStartMove(){
    if(VCS_GetPositionIs(m_KeyHandle, m_usNodeId, &m_lStartPosition, &m_ulErrorCode))
    {
        if(!VCS_MoveToPosition(m_KeyHandle, m_usNodeId, m_ProfilePosModeAbsPosition, m_oRadio, m_oImmediately, &m_ulErrorCode))
        {
            return false;
        }
    }
    return true;
}

bool MaxonMotor::ProfilePositionHalt(){
    if(!VCS_HaltPositionMovement(m_KeyHandle, m_usNodeId, &m_ulErrorCode))
    {
        qDebug()<<m_ulErrorCode;
        return false;
    }
    return true;
}

bool MaxonMotor::setProfileVelocityMode(){
    long velocity = 0;
    if(m_KeyHandle)
    {
        //Clear Error History
        if(VCS_ClearFault(m_KeyHandle, m_usNodeId, &m_ulErrorCode))
        {
            //Read Operation Mode
            if(VCS_GetOperationMode(m_KeyHandle, m_usNodeId, &m_bMode, &m_ulErrorCode))
            {
                //Read velocity Profile Objects
                //VCS_GetVelocityProfile(HANDLE KeyHandle, WORD NodeId, DWORD* pProfileAcceleration, DWORD* pProfileDeceleration, DWORD* pErrorCode);
                if(VCS_GetVelocityProfile(m_KeyHandle, m_usNodeId, &m_ulProfileAcceleration, &m_ulProfileDeceleration, &m_ulErrorCode))
                {
                    //Write Profile velocity Mode
                    if(VCS_SetOperationMode(m_KeyHandle, m_usNodeId, OMD_PROFILE_VELOCITY_MODE, &m_ulErrorCode))
                    {
                        //Write Profile velocity Objects
                        //VCS_SetVelocityProfile(HANDLE KeyHandle, WORD NodeId, DWORD ProfileAcceleration, DWORD ProfileDeceleration, DWORD* pErrorCode)
                        if(VCS_SetVelocityProfile(m_KeyHandle, m_usNodeId, 1000, 1000, &m_ulErrorCode))
                        {
                            //Read Actual velocity
                            if(VCS_GetVelocityIs(m_KeyHandle, m_usNodeId, &velocity, &m_ulErrorCode))
                            {
                                this->m_lActualVelocity = sameDirection(transformRPMToLineSp(velocity));
                                this->parameter.mode = 0;
                                return true;
                            }
                        }
                    }
                }
            }
        }
        closeDevice();
        QMessageBox::information(NULL, "Warning", "Can't clear fault!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    else
    {
        qDebug()<<"Don't open device!";
        return false;
    }
}

void MaxonMotor::setProfileVelocityModeTargetVelocity(double profileVelocity){
    this->m_ProfileVelModeVelocity = profileVelocity;
}

bool MaxonMotor::ProfileVelocityStartMove(){
    double profilemodevel = sameDirection(transformLineSpToRPM(m_ProfileVelModeVelocity));
    long velocity = 0;
//    qDebug()<<"profilemodevel: "<<profilemodevel;
    if(VCS_GetVelocityIs(m_KeyHandle, m_usNodeId, &velocity, &m_ulErrorCode))
    {
        //VCS_MoveWithVelocity(HANDLE KeyHandle, WORD NodeId, long TargetVelocity, DWORD* pErrorCode)
        if(!VCS_MoveWithVelocity(m_KeyHandle, m_usNodeId, profilemodevel, &m_ulErrorCode))
        {
            return false;
        }
    }
    return true;
}

bool MaxonMotor::ProfileVelocityStartMove(double profileVelocity){
    this->setProfileVelocityModeTargetVelocity(profileVelocity);
    if(!this->ProfileVelocityStartMove()) return false;
    return true;
}

bool MaxonMotor::ProfileVelocityHalt(){
    if(!VCS_HaltVelocityMovement(m_KeyHandle, m_usNodeId, &m_ulErrorCode))
    {
        qDebug()<<m_ulErrorCode;
        return false;
    }
    return true;
}

bool MaxonMotor::setVelocityMode(){
    long velocity = 0;
    if(m_KeyHandle)
    {
        //Clear Error History
        if(VCS_ClearFault(m_KeyHandle, m_usNodeId, &m_ulErrorCode))
        {
            //Read Operation Mode
            if(VCS_GetOperationMode(m_KeyHandle, m_usNodeId, &m_bMode, &m_ulErrorCode))
            {
                //Write Profile velocity Mode
                if(VCS_SetOperationMode(m_KeyHandle, m_usNodeId, OMD_VELOCITY_MODE, &m_ulErrorCode))
                {
                    //Read Actual velocity
                    if(VCS_GetVelocityIs(m_KeyHandle, m_usNodeId, &velocity, &m_ulErrorCode))
                    {
                        this->m_lActualVelocity = sameDirection(transformRPMToLineSp(velocity));
                        this->parameter.mode = 2;
                        return true;
                    }
                }
            }
        }
        closeDevice();
        QMessageBox::information(NULL, "Warning", "Can't clear fault!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    else
    {
        qDebug()<<"Don't open device!";
        return false;
    }
}

bool MaxonMotor::setVelocityModeVelocity(double velocityMust){
    BOOL state = true;
    if(!VCS_GetQuickStopState(m_KeyHandle, m_usNodeId, &state, &m_ulErrorCode)){
        return false;
    }
    if(state){
        if(!VCS_SetState(m_KeyHandle, m_usNodeId, ST_ENABLED, &m_ulErrorCode)) return false;
    }
    long velocityMustLong = sameDirection(transformLineSpToRPM(velocityMust));
    if(!VCS_SetVelocityMust(m_KeyHandle, m_usNodeId, velocityMustLong, &m_ulErrorCode))
    {
        return false;
    }
}

bool MaxonMotor::setQuickStopState(){
    if(!VCS_SetQuickStopState(m_KeyHandle, m_usNodeId, &m_ulErrorCode)){
        return false;
    }
    if(!VCS_SetState(m_KeyHandle, m_usNodeId, ST_ENABLED, &m_ulErrorCode)) return false;
    return true;
}


double MaxonMotor::getCurrentPosition(){
    long currentPos = 0;
    if(VCS_GetPositionIs(m_KeyHandle, m_usNodeId, &currentPos, &m_ulErrorCode)){
        m_lActualPosition = sameDirection(transformQcToPosition(currentPos));
        return m_lActualPosition;
    }
    return 0;
}

double MaxonMotor::getCurrentVelocity(){
    long currentVel = 0;
    if(VCS_GetVelocityIs(m_KeyHandle, m_usNodeId, &currentVel, &m_ulErrorCode)){
        m_lActualVelocity = sameDirection(transformRPMToLineSp(currentVel));
        return m_lActualVelocity;
    }
    return 0;
}

bool MaxonMotor::setCurrentMode(){
    long velocity = 0;
    if(m_KeyHandle)
    {
        //Clear Error History
        if(VCS_ClearFault(m_KeyHandle, m_usNodeId, &m_ulErrorCode))
        {
            //Read Operation Mode
            if(VCS_GetOperationMode(m_KeyHandle, m_usNodeId, &m_bMode, &m_ulErrorCode))
            {
                //Write Profile velocity Mode
                if(VCS_SetOperationMode(m_KeyHandle, m_usNodeId, OMD_CURRENT_MODE, &m_ulErrorCode))
                {
                    //Read Actual velocity
                    if(VCS_GetVelocityIs(m_KeyHandle, m_usNodeId, &velocity, &m_ulErrorCode))
                    {
                        VCS_GetOperationMode(m_KeyHandle, m_usNodeId, &m_bMode, &m_ulErrorCode);
                        qDebug()<<"operationMode "<<m_bMode;
                        this->m_lActualVelocity = sameDirection(transformRPMToLineSp(velocity));
                        this->parameter.mode = 3;
                        return true;
                    }
                }
            }
        }
        closeDevice();
        QMessageBox::information(NULL, "Warning", "Can't clear fault!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }
    else
    {
        qDebug()<<"Don't open device!";
        return false;
    }
}

bool MaxonMotor::setCurrentMust(short currentMust){
    BOOL state = true;
    if(!VCS_GetQuickStopState(m_KeyHandle, m_usNodeId, &state, &m_ulErrorCode)){
        return false;
    }
    if(state){
        if(!VCS_SetState(m_KeyHandle, m_usNodeId, ST_ENABLED, &m_ulErrorCode)) return false;
    }
    currentMust = sameDirection(currentMust);
    if(!VCS_SetCurrentMust(m_KeyHandle, m_usNodeId, currentMust, &m_ulErrorCode))
    {
        return false;
    }
}

bool MaxonMotor::startMove(){
    return true;
}

bool MaxonMotor::halt(){
    return true;
}




