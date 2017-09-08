#include"vy_String.h"

namespace vstl
{
    /*****************************************************/
	/*						Implement					 */
	/*****************************************************/

	//Constructors
    String::String()
    {

    }

    String::String(const char* c_str)
    {
        m_CStr = c_str;
    }

    String::String(String& rhand)
    {

    }

    //Destructor
    String::~String()
    {

    }

    //Operators
    bool String::operator==(const String& rhand)
    {

    }

    String& String::operator=(const String& rhand)
    {

    }

    bool String::operator>(const String& rhand)
    {

    }

    bool String::operator<(const String& rhand)
    {

    }
}