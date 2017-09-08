#pragma once
#ifndef VY_VECTOR_H_
#define VY_VECTOR_H_

#include"vy_Define.h"
#include<memory>
#include<cstring>

namespace vstl
{
	template<typename Type>
	class Vector
	{
	public:
		explicit Vector(size_tp size);
		Vector(size_tp size, Type data);
		Vector(Vector& rhand);
		~Vector();

		//Operator
		const Type& operator[] (unsigned int index) const;
		Type& operator[] (unsigned int index);


		//Get
		size_tp size() const;
		size_tp memory() const;


		//Element access
		Type& at(unsigned int index);
		Type& front();
		Type& back();
		Type* data();


		//Modifiers
		void push_back(Type& data);
		void pop_back();
		void insert(unsigned int index);
		void erase(unsigned int index);
		void swap(Vector<Type>& rhand);
		void clear();
	protected:
	private:
		//Functions
		void Malloc(size_tp size);
		void Reset(size_tp NewSize, size_tp NewMemory);
		void CopyData(Type* pOld, Type* pNew);
		//Variables
		size_tp m_Size;
		size_tp m_Memory;
		Type*  m_pData;
	};


	/*******************************************************/
	/*                     implement                       */
	/*******************************************************/

	//public functions
	//Constructors
	template<typename Type>
	inline Vector<Type>::Vector(size_tp size)
	{
		m_Size = size;
		Malloc(m_Size);
	}
	template<typename Type>
	inline Vector<Type>::Vector(size_tp size, Type data):m_Size(size)
	{
		Malloc(size);
		for (unsigned int i = 0; i < m_Size; ++i)
		{
			memcpy_s(&m_pData[i], sizeof(Type), &data, sizeof(Type));
			
		}
	}
	template<typename Type>
	inline Vector<Type>::Vector(Vector & rhand):m_Size(rhand.m_Size), m_Memory(rhand.m_Memory)
	{

		Malloc(m_Size);
		for (unsigned int i = 0; i < m_Size; ++i)
		{
			memcpy_s(&m_pData[i], sizeof(Type), &(rhand.m_pData[i]), sizeof(Type));

		}
	}

	//Destructor
	template<typename Type>
	inline Vector<Type>::~Vector()
	{
		free(m_pData);
	}

	//Operators
	template<typename Type>
	inline const Type & Vector<Type>::operator[](unsigned int index) const
	{
		return m_pData[index];
	}
	template<typename Type>
	inline Type & Vector<Type>::operator[](unsigned int index)
	{
		return m_pData[index];
	}

	//Get
	template<typename Type>
	inline size_tp Vector<Type>::size() const
	{
		return m_Size;
	}
	template<typename Type>
	inline size_tp Vector<Type>::memory() const
	{
		return m_Memory;
	}

	//Element access
	template<typename Type>
	inline Type & Vector<Type>::at(unsigned int index)
	{
		//throw out_of_range exception
		if(index < 0 || index > m_Size)
			return Type();

		return m_pData[index];
	}
	template<typename Type>
	inline Type & Vector<Type>::front()
	{
		if(m_Size > 0)
			return m_pData[0];
		else
			//throw exception
			return Type();
	}
	template<typename Type>
	inline Type & Vector<Type>::back()
	{
		if(m_Size > 0)
			return m_pData[m_Size-1];
		else
		//throw exception
			return Type();
	}
	template<typename Type>
	inline Type * Vector<Type>::data()
	{
		return m_pData;
	}

	//Modifider
	template<typename Type>
	inline void Vector<Type>::swap(Vector<Type>& rhand)
	{
		//swap m_Size
		size_tp stemp = rhand.m_Size;
		rhand.m_Size = m_Size;
		m_Size = stemp;

		//swap m_Memory
		size_tp mtemp = rhand.m_Memory;
		rhand.m_Memory = m_Memory;
		m_Memory = mtemp;

		//swap m_pData
		Type* ptemp = rhand.m_pData;
		rhand.m_pData = m_pData;
		m_pData = temp;

		temp = nullptr;
	}

	//Protected functions
	
	//Private functions
	//malloc new storage space
	template<typename Type>
	inline void Vector<Type>::Malloc(size_tp size)
	{
		m_Memory = sizeof(Type)*m_Size*2;
		m_pData = (Type*)malloc(m_Memory);
	}
	//Reset the m_Size and m_Memory
	template<typename Type>
	inline void Vector<Type>::Reset(size_tp NewSize, size_tp NewMemory)
	{
		m_Size = NewSize;
		m_Memory = NewMemory;
	}
	template<typename Type>
	inline void Vector<Type>::CopyData(Type* pOld, Type* pNew)
	{

	}
}
#endif
