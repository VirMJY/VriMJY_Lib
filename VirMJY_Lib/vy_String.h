#pragma once
#ifndef VY_STRING_H_
#define VY_STRING_H_

namespace vstl
{
	/*************************************************/
	/*				Others functions 				 */
	/*************************************************/
	size_tp Strlen(const char* _Str);


	/*************************************************/
	/*						String					 */
	/*************************************************/
	template<typename Type = char>
	class String
	{
	public:
        //Constructor
        String();
        String(const char* c_str);
		String(String& string);
		explic

        //Destructor
        ~String();

        //Operator
        bool operator==(const String& rhand)const;
        bool operator>(const String& rhand)const;
        bool operator<(const String& rhand)const;
        String& operator=(const String& rhand);
    protected:
	private:
		//Functions
		void Malloc(size_tp size, Type** pData);
		//Variables
		size_tp m_Size;
		Type* m_CStr;
	};


	/*****************************************************/
	/*				String	Implement					 */
	/*****************************************************/

	//Constructors
	template<typename Type>
    String::String()
    {

    }
	template<typename Type>
    String::String(const char* c_str)
    {
        
    }
	template<typename Type>
    String::String(String& rhand)
    {
		m_Size = strlen()
    }

	//Destructor
	template<typename Type>
    String<Type>::~String()
    {

    }

	//Operators
	template<typename Type>
    bool String<Type>::operator==(const String& rhand)
    {

    }
	template<typename Type>
    String& String<Type>::operator=(const String& rhand)
    {

    }
	template<typename Type>
    bool String<Type>::operator>(const String& rhand)
    {

    }
	template<typename Type>
    bool String<Type>::operator<(const String& rhand)
    {

	}
	
}
#endif
