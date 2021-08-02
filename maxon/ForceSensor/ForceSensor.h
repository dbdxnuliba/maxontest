#ifndef FORCESENSOR_H
#define FORCESENSOR_H

#include "modbus-rtu.h"
#include "modbus-tcp.h"
#include "modbus-version.h"
#include "modbus.h"

class ForceSensor
{
private:
    char com[5];
    int baude;
    char parity;
    int dataBit;
    int stopBit;
    modbus_t *mb;

    bool connectFlg;
public:
    bool connectForceSensor();

    bool getSlaveValue(uint16_t* codevalue);
    int getCalForce();

    bool disconnectForceSensor();

public:
    ForceSensor(const char* com, int baude, char parity, int dataBit, int stopBit);
    ~ForceSensor();
};

#endif // FORCESENSOR_H
