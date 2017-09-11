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
	template<typename Type = char, typename _allocator = Allocator>
	class String
	{
	public:
        //Constructor
        String();
        String(const char* c_str);
		String(String& string);
		String(unsigned int Count, Type& a_Data);

        //Destructor
        ~String();


		//Capacity

		//Element access

		//Modifiers

		//String operations
		
        //Operator
        bool operator==(const String& rhand)const;
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
	//Public functions
	//Constructors
	template<typename Type = char, typename _allocator = Allocator>
    String::String()
    {

    }
	template<typename Type = char, typename _allocator = Allocator>
    String::String(const char* c_str)
    {
        
    }
	template<typename Type = char, typename _allocator = Allocator>
    String::String(String& rhand)
    {
		m_Size = Strlen()
    }

	//Destructor
	template<typename Type = char, typename _allocator = Allocator>
    String<Type>::~String()
    {

    }

	//Operators
	template<typename Type = char, typename _allocator = Allocator>
    bool String<Type>::operator==(const String& rhand)
    {

    }
	template<typename Type = char, typename _allocator = Allocator>
    String& String<Type>::operator=(const String& rhand)
    {

    }
	//Protected functions

	//Private functions



	//Non-member functions
	template<typename Type = char>
	String<Type>& operator+ (String<Type>& lhand, String<Type>& rhand)
	{

	}
}
#endif
