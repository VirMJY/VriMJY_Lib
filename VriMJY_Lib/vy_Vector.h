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
		Vector(Vector& rhand);
		~Vector();

		//Operator
		const Type& operator[] (unsigned int index) const;
		Type& operator[] (unsigned int index);


		//Get
		size_tp size() const;
		size_tp memory() const;
	protected:
	private:
		//Functions
		void Malloc(size_tp size);
		//Variables
		size_tp m_Size;
		size_tp m_Memory;
		Type*  m_pData;
	};


	/*******************************************************/
	/*                     implement                       */
	/*******************************************************/
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
		return m_pData[index];
	}
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
	template<typename Type>
	inline void Vector<Type>::Malloc(size_tp size)
	{
		m_Memory = sizeof(Type)*m_Size*2;
		m_pData = (Type*)malloc(m_Memory);
	}
}

#endif