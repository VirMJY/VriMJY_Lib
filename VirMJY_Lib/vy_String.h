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
	/*				   basic_string					 */
	/*************************************************/
	template<typename Type = char, typename _allocator = Allocator>
	class basic_string
	{
	public:
        //Constructor
        basic_string();
        basic_string(const char* c_str);
		basic_string(basic_string& basic_string);
		basic_string(unsigned int Count, Type& a_Data);

        //Destructor
        ~basic_string();


		//Capacity
		size_tp size() const;
		size_tp length() const;
		size_tp max_size() const;
		size_tp capacity() const;
		void clear();
		bool empty() const;
		//Element access

		//Modifiers

		//String operations
		const char* c_str()const;
        //Operator
        bool operator==(const basic_string& rhand)const;
        basic_string& operator=(const basic_string& rhand);
    protected:
	private:
		//Functions
		void Malloc(size_tp size, Type** pData);
		void Realloc(size_tp size, Type** pData);
		void CopyData(const Type* pOld, Type* pNew, size_tp size);
		//Variables
		size_tp m_Size;
		size_tp m_Capacity;
		size_tp m_MaxSize;
		Type* m_pData;
		Type* m_CStr;
	};


	/*****************************************************/
	/*				basic_string	Implement			 */
	/*****************************************************/
	//Public functions
	//Constructors
	template<typename Type, typename _allocator>
    basic_string<Type, _allocator>::basic_string():m_Size(0), m_Capacity(0), m_MaxSize(0)
    {

    }
	template<typename Type, typename _allocator>
    basic_string<Type, _allocator>::basic_string(const char* c_str)
    {
		m_Size = Strlen(c_str);
		m_Capacity = m_Size<<1;
		Malloc(m_Capacity, &m_pData);
		CopyData(c_str, m_pData, m_Size);
    }
	template<typename Type, typename _allocator>
    basic_string<Type, _allocator>::basic_string(basic_string<Type, _allocator>& rhand):m_Size(rhand.m_Size), m_Capacity(rhand.m_Capacity)
    {
		Malloc(m_Capacity, &m_pData);
		CopyData(rhand.m_pData, m_pData, m_Size);
    }

	//Destructor
	template<typename Type, typename _allocator>
    basic_string<Type, _allocator>::~basic_string()
    {
		free(m_pData);
    }

	//Operators
	template<typename Type, typename _allocator>
    bool basic_string<Type, _allocator>::operator==(const basic_string<Type, _allocator>& rhand)
    {

    }
	template<typename Type, typename _allocator>
    basic_string& basic_string<Type, _allocator>::operator=(const basic_string<Type, _allocator>& rhand)
    {

    }
	//Protected functions

	//Private functions
	template<typename Type, typename _allocator>
	void basic_string<Type, _allocator>::Malloc(size_tp size, Type** pData)
	{
		*pData = (Type*)malloc(sizeof(Type)*size);
	}

	//Non-member functions
	template<typename Type = char>
	basic_string<Type, _allocator>& operator+ (basic_string<Type, _allocator>& lhand, basic_string<Type, _allocator>& rhand)
	{

	}

	//Typedef
	typedef basic_string<char> String;
}
#endif
