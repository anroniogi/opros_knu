
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

//#include <termios.h>  //for Linux
//#include <unistd.h>  //for Linux

#include <Windows.h>

#include <iostream>

#include "KeyInputComp.h"
/*
 //for Linux
class BufferToggle
{
    private:
        struct termios t;

    public:

        //
        // Disables buffered input
        //

        void off(void)
        {
            tcgetattr(STDIN_FILENO, &t); //get the current terminal I/O structure
            t.c_lflag &= ~ICANON; //Manipulate the flag bits to do what you want it to do
            tcsetattr(STDIN_FILENO, TCSANOW, &t); //Apply the new settings
        }


        //
        // Enables buffered input
        //

        void on(void)
        {
            tcgetattr(STDIN_FILENO, &t); //get the current terminal I/O structure
            t.c_lflag |= ICANON; //Manipulate the flag bits to do what you want it to do
            tcsetattr(STDIN_FILENO, TCSANOW, &t); //Apply the new settings
        }
};
*/
//
// constructor declaration
//
KeyInputComp::KeyInputComp()
{

	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// constructor declaration (with name)
//
KeyInputComp::KeyInputComp(const std::string &name):Component(name)
{
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// destructor declaration
//

KeyInputComp::~KeyInputComp() {
}

OPRoS::Int16 KeyInputComp::GetKeyInput()
{
	//user code here
	//std::cout<<"KeyInputComp: GetKeyInput: test 01"<<std::endl;

	// push key value for elapse time measuring
	//key=49;  // '1'

	//if(key==68)
		//key=82;
	//else
	    //key=68;  // 'D'

	OPRoS::Int16 ret;
	ret.status=OPROS_SUCCESS;
	ret.data = key;

/*
	  int kbd = open(kbd_dev, O_RDONLY);
	  if(kbd != -1)
	  {
	    input_event ie;
	    while(read(kbd, &ie, sizeof(ie)))
	    {
	      std::cout << "Key Code: " << ie.code << "    Value: " << ie.value << "\n";
	    }
	    close(kbd);
	  }
*/
	//std::cout << "Key Code: " << key  << ret.data << "\n";
	return ret;

}

ReturnType KeyInputComp::Disable()
{
	//user code here
	return lastError;
}

ReturnType KeyInputComp::Enable()
{
	//user code here
	return lastError;

}

ReturnType KeyInputComp::GetError()
{
	//user code here
	return lastError;

}

OPRoS::Property KeyInputComp::GetProperty()
{
	//user code here
	OPRoS::Property retParameter = parameter;
	if (retParameter.GetProperty().size() == 0)
	{
		lastError = OPROS_FIND_PROPERTY_ERROR;
		retParameter.status = lastError;
	}

	LifecycleState lifeStat = getStatus() ;
	if (lifeStat == OPROS_CS_CREATED || lifeStat == OPROS_CS_DESTROYED)
	{
		lastError = OPROS_PRECONDITION_NOT_MET;
		retParameter.status = lastError;
	}
	return retParameter;

}

ReturnType KeyInputComp::SetProperty(OPRoS::Property parameter)
{
	//user code here
	return lastError;

}


void KeyInputComp::portSetup() {
	ProvidedServicePort *pa5;
	pa5=new KeyInputServiceProvided(this);
	addPort("KeyInputService",pa5);

//data port setup
	addPort("OutputKeyInputData", &OutputKeyInputData);



	// export variable setup


}

// Call back Declaration
ReturnType KeyInputComp::onInitialize()
{
	// user code here
	std::cout<<"KeyInputComp: onInitialize: test 01"<<std::endl;
	key=-1;

	return OPROS_SUCCESS;
}

ReturnType KeyInputComp::onStart()
{
	// user code here
	std::cout<<"KeyInputComp: onStart: test 01"<<std::endl;

	return OPROS_SUCCESS;
}
	
ReturnType KeyInputComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KeyInputComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KeyInputComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KeyInputComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KeyInputComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KeyInputComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KeyInputComp::onExecute()
{

	// user code here
	GetKeyInput();

    //BufferToggle bt;  //for Linux
    //bt.off();  //for Linux

    	std::string input = "";
	 char myChar  = {0};

	   std::getline(std::cin, input);

	   if (input.length() == 1) {
	    myChar = input[0];

#ifdef WIN32
	 	if(GetAsyncKeyState('0'))	{
	 		//ret.data = 48;
	 		key=48;
	 	}
	 	else if(GetAsyncKeyState('1'))	{
	 		//ret.data = 49;
	 		key=49;
	 	}
	 	else if(GetAsyncKeyState('2'))	{
	 		//ret.data = 50;
	 		key=50;
	 	}
	 	else if(GetAsyncKeyState('3'))	{
	 		//ret.data = 51;
	 		key=51;
	 	}
	 	else if(GetAsyncKeyState('4'))	{
	 		//ret.data = 52;
	 		key=52;
	 	}
	 	else if(GetAsyncKeyState('5'))	{
	 		//ret.data = 53;
	 		key=53;
	 	}
	 	else if(GetAsyncKeyState('6'))	{
	 		//ret.data = 54;
	 		key=54;
	 	}
	 	else if(GetAsyncKeyState('7'))	{
	 		//ret.data = 55;
	 		key=55;
	 	}
	 	else if(GetAsyncKeyState('8'))	{
	 		//ret.data = 56;
	 		key=56;
	 	}
	 	else if(GetAsyncKeyState('9'))	{
	 		//ret.data = 57;
	 		key=57;
	 	}
	 	else if(GetAsyncKeyState('A'))	{
	 		//ret.data = 64;
	 		key=65;
	 	}
	 	else if(GetAsyncKeyState('B'))	{
	 		//ret.data = 65;
	 		key=66;
	 	}
	 	else if(GetAsyncKeyState('C'))	{
	 		//ret.data = 66;
	 		key=67;
	 	}
	 	else if(GetAsyncKeyState('D'))	{
	 		//ret.data = 67;
	 		key=68;
	 	}
	 	else if(GetAsyncKeyState('E'))	{
	 		//ret.data = 68;
	 		key=69;
	 	}
	 	else if(GetAsyncKeyState('F'))	{
	 		//ret.data = 69;
	 		key=70;
	 	}
	 	else if(GetAsyncKeyState('G'))	{
	 		//ret.data = 70;
	 		key=71;
	 	}
	 	else if(GetAsyncKeyState('H'))	{
	 		//ret.data = 71;
	 		key=72;
	 	}
	 	else if(GetAsyncKeyState('I'))	{
	 		//ret = 72;
	 		key=73;
	 	}
	 	else if(GetAsyncKeyState('J'))	{
	 		//ret.data = 73;
	 		key=74;
	 	}
	 	else if(GetAsyncKeyState('K'))	{
	 		//ret.data = 74;
	 		key=75;
	 	}
	 	else if(GetAsyncKeyState('L'))	{
	 		//ret.data = 75;
	 		key=76;
	 	}
	 	else if(GetAsyncKeyState('M'))	{
	 		//ret.data = 76;
	 		key=77;
	 	}
	 	else if(GetAsyncKeyState('N'))	{
	 		//ret.data = 77;
	 		key=78;
	 	}
	 	else if(GetAsyncKeyState('O'))	{
	 		//ret.data = 78;
	 		key=79;
	 	}
	 	else if(GetAsyncKeyState('P'))	{
	 		//ret.data = 79;
	 		key=80;
	 	}
	 	else if(GetAsyncKeyState('Q'))	{
	 		//ret.data = 80;
	 		key=81;
	 	}
	 	else if(GetAsyncKeyState('R'))	{
	 		//ret.data = 81;
	 		key=82;
	 	}
	 	else if(GetAsyncKeyState('S'))	{
	 		//ret.data = 82;
	 		key=83;
	 	}
	 	else if(GetAsyncKeyState('T'))	{
	 		//ret.data = 83;
	 		key=84;
	 	}
	 	else if(GetAsyncKeyState('U'))	{
	 		//ret.data = 84;
	 		key=85;
	 	}
	 	else if(GetAsyncKeyState('V'))	{
	 		//ret.data = 85;
	 		key=86;
	 	}
	 	else if(GetAsyncKeyState('W'))	{
	 		//ret.data = 86;
	 		key=87;
	 	}
	 	else if(GetAsyncKeyState('X'))	{
	 		//ret.data = 87;
	 		key=88;
	 	}
	 	else if(GetAsyncKeyState('Y'))	{
	 		//ret.data = 88;
	 		key=89;
	 	}
	 	else if(GetAsyncKeyState('Z'))	{
	 		//ret.data = 89;
	 		key=90;
	 	}
	 	else if(GetAsyncKeyState(VK_NUMPAD0))	{
	 		//ret = 96;
	 		key=96;
	 	}
	 	else if(GetAsyncKeyState(VK_NUMPAD1))	{
	 		//ret.data = 97;
	 		key=97;
	 	}
	 	else if(GetAsyncKeyState(VK_NUMPAD2))	{
	 		//ret.data = 98;
	 		key=98;
	 	}
	 	else if(GetAsyncKeyState(VK_NUMPAD3))	{
	 		//ret.data = 99;
	 		key=99;
	 	}
	 	else if(GetAsyncKeyState(VK_NUMPAD4))	{
	 		//ret.data = 100;
	 		key=100;
	 	}
	 	else if(GetAsyncKeyState(VK_NUMPAD5))	{
	 		//ret.data = 101;
	 		key=101;
	 	}
	 	else if(GetAsyncKeyState(VK_NUMPAD6))	{
	 		//ret.data = 102;
	 		key=102;
	 	}
	 	else if(GetAsyncKeyState(VK_NUMPAD7))	{
	 		//ret.data = 103;
	 		key=103;
	 	}
	 	else if(GetAsyncKeyState(VK_NUMPAD8))	{
	 		//ret.data = 104;
	 		key=104;
	 	}
	 	else if(GetAsyncKeyState(VK_NUMPAD9))	{
	 		//ret.data = 105;
	 		key=105;
	 	}
	 	else if(GetAsyncKeyState(VK_MULTIPLY))	{
	 		//ret.data = 106;
	 		key=106;
	 	}
	 	else if(GetAsyncKeyState(VK_ADD))	{
	 		//ret.data = 107;
	 		key=107;
	 	}
	 	else if(GetAsyncKeyState(VK_SEPARATOR))	{
	 		//ret.data = 108;
	 		key=108;
	 	}
	 	else if(GetAsyncKeyState(VK_SUBTRACT))	{
	 		//ret.data = 109;
	 		key=109;
	 	}
	 	else if(GetAsyncKeyState(VK_DECIMAL))	{
	 		//ret.data = 110;
	 		key=110;
	 	}
	 	else if(GetAsyncKeyState(VK_DIVIDE))	{
	 		//ret.data = 111;
	 		key=111;
	 	}
	   }
	 	else
	 		//ret.data=0;
	 		key=0;

#else

	     if(myChar == '0') 	key = 48;
	     else if (myChar == '1') key = 49;
	     else if (myChar == '2') key = 50;
	     else if (myChar == '3') key = 51;
	     else if (myChar == '4') key = 52;
	     else if (myChar == '5') key = 53;
	     else if (myChar == '6') key = 54;
	     else if (myChar == '7') key = 55;
	     else if (myChar == '8') key = 56;
	     else if (myChar == '9') key = 57;
	     else if (myChar == 'A') key = 65;
	     else if (myChar == 'B') key = 66;
	     else if (myChar == 'C') key = 67;
	     else if (myChar == 'D') key = 68;
	     else if (myChar == 'E') key = 69;
	     else if (myChar == 'F') key = 70;
	     else if (myChar == 'G') key = 71;
	     else if (myChar == 'H') key = 72;
	     else if (myChar == 'I') key = 73;
	     else if (myChar == 'J') key = 74;
	     else if (myChar == 'K') key = 75;
	     else if (myChar == 'L') key = 76;
	     else if (myChar == 'M') key = 77;
	     else if (myChar == 'N') key = 78;
	     else if (myChar == 'O') key = 79;
	     else if (myChar == 'P') key = 80;
	     else if (myChar == 'Q') key = 81;
	     else if (myChar == 'R') key = 82;
	     else if (myChar == 'S') key = 83;
	     else if (myChar == 'T') key = 84;
	     else if (myChar == 'U') key = 85;
	     else if (myChar == 'V') key = 86;
	     else if (myChar == 'W') key = 87;
	     else if (myChar == 'X') key = 88;
	     else if (myChar == 'Y') key = 89;
	     else if (myChar == 'Z') key = 90;
/*
	 	 else if (myChar == VK_NUMPAD0) key = 96;
	 	 else if (myChar == VK_NUMPAD1) key = 97;
	 	 else if (myChar == VK_NUMPAD2) key = 98;
	 	 else if (myChar == VK_NUMPAD3) key = 99;
	 	 else if (myChar == VK_NUMPAD4) key = 100;
	 	 else if (myChar == VK_NUMPAD5) key = 101;
	 	 else if (myChar == VK_NUMPAD6) key = 102;
	 	 else if (myChar == VK_NUMPAD7) key = 103;
	 	 else if (myChar == VK_NUMPAD8) key = 104;
	 	 else if (myChar == VK_NUMPAD9) key = 105;
	 	 else if (myChar == VK_MULTIPLY) key = 106;
	 	 else if (myChar == VK_ADD) key = 107;
	 	 else if (myChar == VK_SEPARATOR) key = 108;
	 	 else if (myChar == VK_SUBTRACT) key = 109;
	 	 else if (myChar == VK_DECIMAL) key = 110;
	 	 else if (myChar == VK_DIVIDE) key = 111;
*/
         else key = 0;
//std::cout << "length=1: key=" <<key<< std::endl;

#endif

	   //}
	  // else {
	    //  std::cout << "length>1: more than one character before a enter key" << std::endl;
	   //}

	 //}

	  // std::cout<<"key"<<key<<std::endl;
	return OPROS_SUCCESS;
}
	
ReturnType KeyInputComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType KeyInputComp::onPeriodChanged()
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
	return new KeyInputComp();
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
	return new KeyInputComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

