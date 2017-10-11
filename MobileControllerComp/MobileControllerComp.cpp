/*************************************************************

 file: MobileControllerComp.cpp
 author: E.C. Shin
 begin: January 30 2010
 copyright: (c) 2010 KITECH, OPRoS
 email: unchol@kitech.re.kr

***************************************************************

OPRoS source code is provided under a dual license mode:
 LGPL and OPRoS individually.

LGPL: You can redistribute it and/or modify it under the terms
 of the Less GNU General Public License as published by the Free
 Software Foundation, either version 3 of the License.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 Less GNU General Public License for more details.

 You should have received a copy of the Less GNU General Public
 License along with this program. If not, see
 <http://www.gnu.org/licenses/>.

OPRoS individual license: An individual license is a license for
 modifying the source code of OPRoS and distiributing it in a
 closed format for commercial purposes.

 If you are interested in this option, please see
 <http://www.opros.or.kr>.

This license policy may be changed without prior notice.

***************************************************************/
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "MobileControllerComp.h"

//
// constructor declaration
//
MobileControllerComp::MobileControllerComp()
	:velocity(OPROS_FIFO,1)
{

	portSetup();
}

//
// constructor declaration (with name)
//
MobileControllerComp::MobileControllerComp(const std::string &name):Component(name)
	,velocity(OPROS_FIFO,1)
{
	
	portSetup();
}

//
// destructor declaration
//

MobileControllerComp::~MobileControllerComp() {
}
bool MobileControllerComp::IsBaseRunning()
{
	//user code here
	bool isWheelRunning = false;

	if(MobileControl == NULL) {
		PrintMessage("ERROR : WheelControllerComp::IsWheelRunning() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(MobileControl->IsBaseRunning(isWheelRunning) < 0) {
		lastError = OPROS_CALL_API_ERROR;
	}

	lastError = OPROS_SUCCESS;

	return isWheelRunning;
}

ReturnType MobileControllerComp::StopBase()
{
	//user code here
	if(MobileControl == NULL)
	{
		 PrintMessage("ERROR : MobileControllerComp::StopBase() -> The handle of API is not created.\n");
         lastError = OPROS_PRECONDITION_NOT_MET;
	}

	ReturnType msg = (ReturnType)MobileControl->Disable();

	if(msg == API_ERROR)
	{
		 lastError = OPROS_CALL_API_ERROR;
	}

	lastError = OPROS_SUCCESS;

	return lastError = OPROS_SUCCESS;
}

ReturnType MobileControllerComp::RotateBase(float64_t angle,float64_t velocity)
{
	//user code here

	OPRoS::MobileVelocityData tVel;

	if(MobileControl == NULL)
	{
        PrintMessage("ERROR : MobileControllerComp::SetVelocity() -> The handle of API is not created.\n");
        lastError = OPROS_PRECONDITION_NOT_MET;
    }
	std::cout << "qqq = " << tVel.x << "www = " << tVel.theta << std::endl;
	tVel.x = velocity;
	tVel.theta = angle;

	ReturnType msg = (ReturnType)MobileControl->SetVelocity(tVel);

	if(msg == API_ERROR)
	{
		 return lastError = OPROS_CALL_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

ReturnType MobileControllerComp::MoveBase(float64_t distance,float64_t velocity)
{
	//user code here

	if(MobileControl == NULL) {
		PrintMessage("ERROR : WheelControllerComp::MoveWheel() -> The handle of API is not created.\n");
		lastError = OPROS_PRECONDITION_NOT_MET;
	}

	if(MobileControl->MoveBase(distance, velocity) < 0) {
		return lastError = OPROS_CALL_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

OPRoS::MobilePositionData MobileControllerComp::GetPosition()
{
	//user code here
	OPRoS::MobilePositionData position;

	if(MobileControl == NULL)
	{
		std::cout<<"test0013"<<std::endl;
        PrintMessage("ERROR : MobileControllerComp::GetPosition() -> The handle of API is not created.\n");
        lastError = OPROS_PRECONDITION_NOT_MET;

    	std::cout<<"test0012"<<std::endl;
    }
	std::cout<<"test001"<<std::endl;
	ReturnType msg = (ReturnType)MobileControl->GetPosition(position);
	std::cout<<"test002"<<std::endl;


	std::cout << "MobileController get Position : " << Position.x << Position.y << Position.theta << std::endl;


	if(msg == API_ERROR)
	{
		std::cout<<"test0101"<<std::endl;
		 lastError = OPROS_CALL_API_ERROR;
	}
	std::cout<<"test0031"<<std::endl;

	lastError = OPROS_SUCCESS;

	std::cout<<"test0201"<<std::endl;
	return position;
}

ReturnType MobileControllerComp::SetPosition(OPRoS::MobilePositionData position)
{
	//user code here

	if(MobileControl == NULL)
	{
        PrintMessage("ERROR : MobileControllerComp::SetPosition() -> The handle of API is not created.\n");
        lastError = OPROS_PRECONDITION_NOT_MET;
    }

	std::cout<<"test00131"<<std::endl;
	ReturnType msg = (ReturnType)MobileControl->SetPosition(position);

	std::cout<<"test201"<<std::endl;
	std::cout << "MobileController set Position : " << Position.x << Position.y << Position.theta << std::endl;

	if(msg == API_ERROR)
	{
		std::cout<<"test0081"<<std::endl;
		return lastError =OPROS_CALL_API_ERROR;
	}

	std::cout<<"test0019"<<std::endl;
	return lastError = OPROS_SUCCESS;

}

ReturnType MobileControllerComp::SetVelocity(OPRoS::MobileVelocityData velocity)
{
	//user code here
	if(MobileControl == NULL)
	{
        PrintMessage("ERROR : MobileControllerComp::SetVelocity() -> The handle of API is not created.\n");
        lastError = OPROS_PRECONDITION_NOT_MET;
    }

	ReturnType msg = (ReturnType)MobileControl->SetVelocity(velocity);

	if(msg == API_ERROR)
	{
		return lastError =OPROS_CALL_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;

}

std::vector<OPRoS::Int32> MobileControllerComp::GetOdometry()
{
	//user code here
	std::vector<OPRoS::Int32> odometry;

	if(MobileControl == NULL)
	{
        PrintMessage("ERROR : MobileControllerComp::GetOdometry() -> The handle of API is not created.\n");
        lastError = OPROS_PRECONDITION_NOT_MET;
    }

	ReturnType msg = (ReturnType)MobileControl->GetOdometry(odometry);


	if(msg == API_ERROR)
	{
		 lastError = OPROS_CALL_API_ERROR;
	}

	lastError = OPROS_SUCCESS;

	return odometry;
}

ReturnType MobileControllerComp::Disable()
{
	//user code here
	if(MobileControl == NULL)
	{
        PrintMessage("ERROR : MobileControllerComp::Disable() -> The handle of API is not created.\n");
        lastError = OPROS_PRECONDITION_NOT_MET;
    }

	ReturnType msg = (ReturnType)MobileControl->Disable();


	if(msg == API_ERROR)
	{
		 return lastError = OPROS_DISABLE_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

ReturnType MobileControllerComp::Enable()
{
	//user code here
	if(MobileControl == NULL)
	{
        PrintMessage("ERROR : MobileControllerComp::Enable() -> The handle of API is not created.\n");
        lastError = OPROS_PRECONDITION_NOT_MET;
    }

	ReturnType msg = (ReturnType)MobileControl->Enable();


	if(msg == API_ERROR)
	{
		 return lastError = OPROS_ENABLE_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}

ReturnType MobileControllerComp::GetError()
{
	//user code here
	return lastError;
}

OPRoS::Property MobileControllerComp::GetProperty()
{
	//user code here
	if(MobileControl == NULL)
	{
		PrintMessage("ERROR : MobileControllerComp::GetProperty() -> The handle of API is not created.\n");
        lastError = OPROS_PRECONDITION_NOT_MET;
	}

	ReturnType msg = (ReturnType)MobileControl->GetProperty(m_Property);


	if(msg == API_ERROR)
	{
		 lastError = OPROS_CALL_API_ERROR;
	}

	lastError = OPROS_SUCCESS;

	return m_Property;
}

ReturnType MobileControllerComp::SetProperty(OPRoS::Property parameter)
{
	//user code here

	if(MobileControl == NULL)
	{
		PrintMessage("ERROR : MobileControllerComp::SetProperty() -> The handle of API is not created.\n");
        lastError = OPROS_PRECONDITION_NOT_MET;
	}

	ReturnType msg = (ReturnType)MobileControl->SetProperty(parameter);

	if(msg == API_ERROR)
	{
		 return lastError = OPROS_CALL_API_ERROR;
	}

	return lastError = OPROS_SUCCESS;
}


void MobileControllerComp::portSetup() {
//data port setup
	addPort("velocity", &velocity);

	ProvidedServicePort *pa1;
	pa1=new MobileControllerServiceProvided(this);
	addPort("MobileControllerService",pa1);




	// export variable setup


}

// Call back Declaration
ReturnType MobileControllerComp::onInitialize()
{
	// user code here
	OPRoS::Property parameter;
	std::map<std::string, std::string> temp = getPropertyMap();
	parameter.SetProperty(temp);

	if(parameter.FindName("ApiName") == false) {
		PrintMessage("Can't find the APIName in property\n");
		return lastError = OPROS_FIND_PROPERTY_ERROR;
	}


	//	DLL 로드
	std::string dllname = parameter.GetValue("ApiName");


	hOprosAPI = LoadLibrary((LPCSTR)dllname.c_str());
	if(hOprosAPI == NULL) {
		PrintMessage("ERROR : Can't find the %s\n", parameter.GetValue("ApiName").c_str());
		return lastError = OPROS_FIND_DLL_ERROR;
	}

	//	API 로드
	GET_OPROS_DEVICE getOprosAPI;
	getOprosAPI = (GET_OPROS_DEVICE)GetProcAddress(hOprosAPI, "GetAPI");
	if(getOprosAPI == NULL) {
		PrintMessage("ERROR :  Can't get a handle of GetAPI Funtion\n");
		FreeLibrary(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}

	MobileControl = dynamic_cast<MobileController *>(getOprosAPI());
	if(MobileControl == NULL) {
		PrintMessage("ERROR : Can't get a handle of ServoActuator API\n");
		FreeLibrary(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_LOAD_DLL_ERROR;
	}
	if(MobileControl->Initialize(parameter) != API_SUCCESS)
	{
		delete MobileControl;
		MobileControl = NULL;
		FreeLibrary(hOprosAPI);
		hOprosAPI = NULL;
		return lastError = OPROS_INITIALIZE_API_ERROR;
	}

		return lastError = OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onStart()
{
	// user code here
	MobileControl->Enable();

	return OPROS_SUCCESS;
}
	
ReturnType MobileControllerComp::onStop()
{
	// user code here
	if(MobileControl->Disable() != OPROS_SUCCESS)
		return  OPROS_INTERNAL_FAULT;

	return OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onExecute()
{
	// user code here
	
	OPRoS::MobileVelocityData tVel;
	opros_any *pData = velocity.pop();
	if (pData != NULL)
	{
		tVel = velocity.getContent(*pData);
		std::cout << "pData : " <<tVel.x << "\n" << std::endl;
		SetVelocity(tVel);
		
	}
	 else std::cout << "NO Data Received!!!" << std::endl;

	delete pData;
	return OPROS_SUCCESS;
}
	
ReturnType MobileControllerComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobileControllerComp::onPeriodChanged()
{
	// user code here
	return OPROS_SUCCESS;
}







#ifndef MAKE_STATIC_COMPONENT
#ifdef WIN32

extern "C"
{
__declspec(dllexport) Component *getComponent();
__declspec(dllexport) void releaseComponent(Component *pcom);
}

Component *getComponent()
{
	return new MobileControllerComp();
}

void releaseComponent(Component *com)
{
	delete com;
}

#else
extern "C"
{
	Component *getComponent();
	void releaseComponent(Component *com);
}
Component *getComponent()
{
	return new MobileControllerComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

