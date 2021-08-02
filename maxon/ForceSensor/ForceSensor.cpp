#include "ForceSensor.h"
#include <QtDebug>

ForceSensor::ForceSensor(const char* com, int baude, char parity, int dataBit, int stopBit)
{
    connectFlg = false;
    memcpy(this->com, com, 5);
    this->baude = baude;
    this->parity = parity;
    this->dataBit = dataBit;
    this->stopBit = stopBit;
    connectFlg = connectForceSensor();
}

ForceSensor::~ForceSensor(){

}

bool ForceSensor::connectForceSensor()
{
    mb = modbus_new_rtu(this->com, this->baude, this->parity, this->dataBit, this->stopBit);   //相同的端口只能同时打开一个
//    mb = modbus_new_rtu("COM4", 9600, 'N', 8, 1);   //相同的端口只能同时打开一个
    modbus_set_slave(mb, 1);  //设置modbus从机地址
//    modbus_connect(mb);
    if (modbus_connect(mb) == -1) {
        fprintf(stderr, "Connection failed: %s\n", modbus_strerror(errno));
        modbus_free(mb);
        return false;
    }
    struct timeval t;
    t.tv_sec=0;
    t.tv_usec=1000000;   //设置modbus超时时间为1000毫秒
    modbus_set_response_timeout(mb, (uint32_t)t.tv_sec, (uint32_t)t.tv_usec);
    return true;
}

///
/// \brief modbusSensor::getCalValue
/// \return
///获得AD内码值
bool ForceSensor::getSlaveValue(uint16_t* codevalue)
{
    if(!connectFlg) return false;
    int regs = modbus_read_registers(mb, 0x1E, 02, codevalue);
    if(regs <= 0)
    {
        return false;
    }
    return true;
}

int ForceSensor::getCalForce()
{
    int force = 0;
    uint16_t codevalue[2];
    if (getSlaveValue(codevalue)){
       force = MODBUS_GET_INT32_FROM_INT16(codevalue, 0);
    }

    return force*10;
}

bool ForceSensor::disconnectForceSensor()
{
    modbus_close(mb);
    modbus_free(mb);
    return true;
}
