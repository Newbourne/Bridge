#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include "serialbase.h"

class MotorDriver : public SerialBase
{
public:
    MotorDriver(const string port);
    ~MotorDriver();
};

#endif MOTORDRIVER_H
