#pragma once

#if defined(WIN32)
#include <Windows.h>
#include <cstdint>
#include <vector>
#else
#include <dlfcn.h>
#endif
#include <device/LaserRangeFinder.h>
#include <device/Uart.h>

class Hokuyo_SCIP_V2_0 : public LaserRangeFinder
{
public:
	Hokuyo_SCIP_V2_0(void);
	virtual ~Hokuyo_SCIP_V2_0(void);

public:
	virtual int32_t Initialize(OPRoS::Property parameter);		
	virtual int32_t Finalize(void);
	virtual int32_t Enable(void); 
	virtual int32_t Disable(void);
	virtual int32_t SetProperty(OPRoS::Property parameter);	
	virtual int32_t GetProperty(OPRoS::Property &parameter);	

	virtual int32_t GetSensorValue(std::vector<OPRoS::Float64Array> &laserScannerData);

private:
	OPRoS::Property parameter;
	Uart *uart;

#if defined(WIN32)
	HMODULE hOprosAPI;
#else
	void *hOprosAPI;
#endif

	int maximumStep;
	int startStep;
	int endStep;
	int deltaStep;
	int scanStepSize;
	std::vector<int> scannedData;

	int InitializeUART(OPRoS::Property parameter);
	int FinalizeUART(void);

	int Hokuyo_SCIPV2_0_SendPack(unsigned char *data, int size);
	int Hokuyo_SCIPV2_0_RecvPack(unsigned char *data, int size);
	int Hokuyo_SCIPV2_0_CheckSum(unsigned char *data, int size);
	int Hokuyo_SCIPV2_0_ParsingData(unsigned char *data, int size);
	int Hokuyo_SCIPV2_0_ParsingTimeStamp(unsigned char *data);
	int Hokuyo_SCIPV2_0_ChangeVer2_0(void);
	int Hokuyo_SCIPV2_0_Reset(void);
	int Hokuyo_SCIPV2_0_SetBaudRate(int baudRate);
	int Hokuyo_SCIPV2_0_Enable(unsigned char *status);
	int Hokuyo_SCIPV2_0_Disable(void);
	int Hokuyo_SCIPV2_0_MeasureAndGetData(void);
	int Hokuyo_SCIPV2_0_GetLastData(void);
};
