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
		void insert(unsigned int index, Type& data);
		void erase(unsigned int index);
		void swap(Vector<Type>& rhand);
		void clear();
	protected:
	private:
		//Functions
		void Malloc(size_tp size, Type** pData);
		void Realloc();
		void Reset(size_tp NewSize, size_tp NewMemory);
		void CopyData(Type* pOld, Type* pNew, size_tp size);
		//Variables
		size_tp m_Size;
		size_tp m_Memory;
		size_tp m_Capacity;
		Type*  m_pData;
	};


	/*******************************************************/
	/*                     Implement                       */
	/*******************************************************/

	//public functions
	//Constructors
	template<typename Type>
	inline Vector<Type>::Vector(size_tp size)
	{
		m_Size = size;
		m_Capacity = m_Size*2;
		m_Memory = sizeof(Type)*m_Size*2;  
		Malloc(m_Size, **m_pData);
	}
	template<typename Type>
	inline Vector<Type>::Vector(size_tp size, Type data):m_Size(size)
	{
		Malloc(size, *m_pData);
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
	template<typename Type>
	inline void Vector<Type>::clear()
	{
		m_Size = 0;
		m_Memory = 0;
		free(m_pData);
		m_pData = nullptr;
	}
	template<typename Type>
	inline void Vector<Type>::insert(unsigned int index, Type& data)
	{
		if(m_Size + 1 > m_Capacity)
		{
			Realloc();
		}

		for(int i = m_Size; i > index; --i)
		{
			memcpy_s(&m_pData[i-1], sizeof(Type), &m_pData[i], sizeof(Type));
		}
		m_pData[index] = data;
		m_Size += 1;
	}
	template<typename Type>
	inline void Vector<Type>::erase(unsigned int index)
	{
		if(m_Size <= 0 || index > m_Sisze - 1 )
		{
			//throw out_of_range exception
			return;
		}
		for(int i = index; i < m_Size-1; ++i)
		{
			memcpy_s(&m_pData[i], sizeof(Type), &m_pData[i+1], sizeof(Type));
		}
		m_Size -= 1;
	}
	template<typename Type>
	inline void push_back(Type& data)
	{
		if(m_Size + 1 > m_Capacity)
		{
			Realloc();
		}
		m_pData[m_Size] = data;
		m_Size += 1;
	}
	template<typename Type>
	inline void pop_back()
	{
		m_Size -= 1;
	}
	//Protected functions
	
	//Private functions
	//malloc new storage space
	template<typename Type>
	inline void Vector<Type>::Malloc(size_tp size, Type** pData)
	{
		*pData = (Type*)malloc(m_Memory);
	}
	template<typename Type>
	inline void Vector<Type>::Realloc()
	{
		Type* pTemp = nullptr;
		Malloc(m_Capacity*2, **pTemp, m_Size);
		CopyData(m_pData, pTemp);
		free(m_pData);
		m_pData = pTemp;
		p_Temp = nullptr;
		m_Size = m_Capacity;
		m_Capacity *= 2;
		m_Memory = sizeof(Type)*m_Capacity;
	}
	//Reset the m_Size and m_Memory
	template<typename Type>
	inline void Vector<Type>::Reset(size_tp NewSize, size_tp NewMemory)
	{
		m_Size = NewSize;
		m_Memory = NewMemory;
	}
	template<typename Type>
	inline void Vector<Type>::CopyData(Type* pOld, Type* pNew, size_tp size)
	{
		for (unsigned int i = 0; i < size; ++i)
		{
			memcpy_s(&pNew[i], sizeof(Type), &pOld[i], sizeof(Type));
		}
	}
}
#endif
