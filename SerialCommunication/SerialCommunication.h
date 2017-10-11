#pragma once

#include "device/Uart.h"
#include "device/OprosLock.h"
#include "SerialImpl.h"

class SerialCommunication : public Uart
{
public:
	SerialCommunication(void);
	virtual ~SerialCommunication(void);

private:
	SerialImpl *handle;
	OPRoS::Property parameter;
	OprosLock lock;

public:
	int32_t Initialize(OPRoS::Property parameter);
	int32_t Finalize(void);
	int32_t Enable(void);
	int32_t Disable(void);
	int32_t SetProperty(OPRoS::Property parameter);
	int32_t GetProperty(OPRoS::Property &parameter);

	int Lock(void);
	int Unlock(void);

	int Write(unsigned char *data, int size);
	int Read(unsigned char *data, int size);
};
