
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "ControllComp.h"
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>

#pragma comment(lib, "winmm.lib")
/*
int main(int argc, char * argv[])
{
	PlaySound("C:\\res\\example.wav", NULL, SND_FILENAME |  SND_ASYNC | SND_LOOP);
	getchar();
	return 0;
}*/
//
// constructor declaration
//
ControllComp::ControllComp()
{
	ptrLaserScannerService = NULL;

	ptrKeyInputService = NULL;


	
	portSetup();
}

//
// constructor declaration (with name)
//
ControllComp::ControllComp(const std::string &name):Component(name)
{
	ptrLaserScannerService = NULL;

	ptrKeyInputService = NULL;


	
	portSetup();
}

//
// destructor declaration
//

ControllComp::~ControllComp() {
}

void ControllComp::portSetup() {
	ptrLaserScannerService=new LaserScannerServiceRequired();
	addPort("LaserScannerService",ptrLaserScannerService);

	// export variable setup
	EXPORT_VARIABLE("counter", m_counter);

	ptrKeyInputService=new KeyInputServiceRequired();
	addPort("KeyInputService",ptrKeyInputService);




	// export variable setup


}

// Call back Declaration
ReturnType ControllComp::onInitialize()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ControllComp::onStart()
{

	// user code here
	m_counter =60;
	return OPROS_SUCCESS;
}
	
ReturnType ControllComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ControllComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ControllComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ControllComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ControllComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ControllComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ControllComp::onExecute()
{
	// user code here

	OPRoS::Int16 value= ptrKeyInputService->GetKeyInput();
		m_counter--;

		std::cout<<"IF accept Paper Push 'O'or 'o'"<<"["<<m_counter<<"]"<<std::endl;
		std::cout<<"test value="<<value.data<<std::endl;
				//", '0' = "<< (int)'O'<<std::endl;

		if(m_counter ==0){
			m_counter =61;
			// 사용자에게 가서 띄어줄 화면
		}
			if(value.data == 79 )
			{
				std::cout<<"Check accept"<<std::endl;
				// O or o 입력시 accept 출력
				PlaySound("C:\\OPRoS_2015\\worskpace_170904\\example.wav", NULL, SND_FILENAME |  SND_ASYNC | SND_LOOP);
				getchar();
			}
			else
				std::cout<<"STAND BY!!! "<<std::endl;

		/*
	std::vector<OPRoS::Float64Array> vval;
	OPRoS::Float64Array fval;
	vval=ptrLaserScannerService->GetSensorValue();

	//std::cout<<"Lazertest"<<std::endl;
	fval=vval[0].data;
	//std::cout <<"fval="<<fval.data.size()<<std::endl;
	std::vector<int>::size_type sz = fval.data.size();
	for(unsigned i=0;i<sz;i++)
	//	std::cout << ' ' << fval.data[i];
	//std::cout<<'\n';
*/
	return OPROS_SUCCESS;
}
	
ReturnType ControllComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType ControllComp::onPeriodChanged()
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
	return new ControllComp();
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
	return new ControllComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

