#pragma once
#ifndef VY_VECTOR_H_
#define VY_VECTOR_H_

#include"vy_Define.h"
#include<memory>

namespace vstl
{
	template<typename Type>
	class Vector
	{
	public:
		explicit Vector(size_tp size);
		Vector(size_tp size, Type data);
		~Vector();

		//Operator
		const Type& operator[] (unsigned int index) const;
		Type& operator[] (unsigned int index);


		//Get
		size_tp size() const;
	protected:
	private:
		//Functions
		void Malloc(size_tp size);
		//Variables
		size_tp m_Size;
		size_tp m_Memory;
		Type*  m_pData;
	};
	template<typename Type>
	inline Vector<Type>::Vector(size_tp size)
	{
		m_Size = size;
		Malloc(m_Size);
	}
	template<typename Type>
	inline Vector<Type>::Vector(size_tp size, Type data)
	{
		m_Size = size;
		Malloc(size);
		for (int i = 0; i < m_Size; ++i)
		{
			memcpy_s(&m_pData[i], sizeof(TYPE), &data, sizeof(TYPE));
			
		}
	}
	template<typename Type>
	inline Vector<Type>::~Vector()
	{
		free(m_pData);
	}
	template<typename Type>
	inline const Type & Vector<Type>::operator[](unsigned int index) const
	{
		return m_pData[index];
	}
	template<typename Type>
	inline Type & Vector<Type>::operator[](unsigned int index)
	{
		return m_pData[i];
	}
	template<typename Type>
	inline size_tp Vector<Type>::size() const
	{
		return m_Size;
	}
	template<typename Type>
	inline void Vector<Type>::Malloc(size_tp size)
	{
		m_Memory = sizeof(Type)*m_Size*2;
		m_pData = (Type*)malloc(m_Memory);
	}
}

#endif