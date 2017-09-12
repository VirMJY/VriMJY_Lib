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
		Type& operator[](unsigned int index);
		Type& at(unsigned int index);
		//Modifiers
		basic_string& append(const Type* c_str);
		basic_string& append(const basic_string& _str);
		basic_string& append(const Type c);
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

	//Element access
	template<typename Type, typename _allocator>
	Type& basic_string<Type, _allocator>::operator[](unsigned int index)
	{
		return  m_pData[index];
	}
	template<typename Type, typename _allocator>
	Type& basic_string<Type, _allocator>::at(unsigned int index)
	{
		if(index < 0 || index >= size)
		{
			//Throw out_of_range exception
			return Type();
		}
		return m_pData[index];
	}
	//Modifiers
	template<typename Type, typename _allocator>
	basic_string& basic_string<Type, _allocator>::append(const Type* c_str)
	{
		size_tp size = Strlen(c_str);
		if(size + m_Size > m_Capacity)
		{
			Type* temp = nullptr;
			Malloc(m_Capacity<<1, &temp);
			CopyData(m_pData, temp, m_Size);
			m_Capacity = m_Capacity<<1;
			free(m_pData);
			m_pData = temp;
			append(c_str);
		}
		else
		{
			CopyData(m_pData + m_Size, c_str, size);
			m_Size += size;
		}

		return *this;
	}
	template<typename Type, typename _allocator>
	basic_string& basic_string<Type, _allocator>::append(const basic_string<Type, _allocator>& _str)
	{

	}
	template<typename Type, typename _allocator>
	basic_string& basic_string<Type, _allocator>::append(const Type c)
	{
		if(m_Size + 1 < m_Capacity)
		{
			m_pData[m_Size] = c;
		}
		else
		{
			Type* temp = nullptr;
			Malloc(m_Capacity<<1, &temp);
			CopyData(m_pData, temp, m_Size);
			m_Capacity = m_Capacity<<1;
			free(m_pData);
			m_pData = temp;
			m_pData[m_Size] = c;
		}
		++m_Size;

		return *this;
	}

	//Operators
	template<typename Type, typename _allocator>
    bool basic_string<Type, _allocator>::operator==(const basic_string<Type, _allocator>& rhand)
    {
		if(rhand.m_Size != m_Size)	return false;
		int size = 0;
		while(rhand[size] == (*this)[size] && size <= m_Size)
		{
			++size;
		}
		return size == m_Size;
    }
	template<typename Type, typename _allocator>
    basic_string& basic_string<Type, _allocator>::operator=(const basic_string<Type, _allocator>& rhand)
    {
		if(&rhand == this)	return *this;

		Type* temp = nullptr;
		Malloc(m_Capacity, &temp);
		CopyData(rhand.m_pData, temp, m_Size);
		m_Size = rhand.m_Size;
		m_Capacity = rhand.m_Capacity;
		free(m_pData);
		m_pData = temp;
    }
	//Protected functions

	//Private functions
	template<typename Type, typename _allocator>
	void basic_string<Type, _allocator>::Malloc(size_tp size, Type** pData)
	{
		*pData = (Type*)malloc(sizeof(Type)*size);
	}
	template<typename Type, typename _allocator>
	void basic_string<Type, _allocator>::CopyData(Type* pOld, Type* pNew, size_tp size)
	{
		for(int i = 0; i < size; ++i)
		{
		memcpy_s(&pOld[i], sizeof(Type), &pNew[i], sizeof(Type));
		}
	}

	//Typedef
	typedef basic_string<char> String;

	//Non-member functions
	String operator+ (String& lhand, String& rhand)
	{
		String temp = lhand;
		temp.append(rhand);

		return temp;
	}

	
}
#endif
