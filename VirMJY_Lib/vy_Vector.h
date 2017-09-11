#pragma once
#ifndef VY_VECTOR_H_
#define VY_VECTOR_H_

#include"vy_Define.h"
#include<memory>
#include<cstring>
#include"vy_allocator.h"
namespace vstl
{
	template<typename Type, typename _allocator = Allocator>
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
		size_tp m_Capacity;
		Type*  m_pData;
	};


	/*******************************************************/
	/*                     Implement                       */
	/*******************************************************/

	//public functions
	//Constructors
	template<typename Type, typename _allocator>
	inline Vector<Type, _allocator>::Vector(size_tp size): m_Size(size), m_Capacity(size<<1)
	{
		Malloc(m_Capacity, **m_pData);
	}
	template<typename Type, typename _allocator>
	inline Vector<Type, _allocator>::Vector(size_tp size, Type data):m_Size(size), m_Capacity(size<<1)
	{
		Malloc(m_Capacity, *m_pData);
		for (unsigned int i = 0; i < m_Size; ++i)
		{
			memcpy_s(&m_pData[i], sizeof(Type), &data, sizeof(Type));
			
		}
	}
	template<typename Type, typename _allocator>
	inline Vector<Type, _allocator>::Vector(Vector<Type, _allocator> & rhand):m_Size(rhand.m_Size), m_Capacity(rhand.m_Capacity)
	{

		Malloc(m_Capacity, &m_pData);
		for (unsigned int i = 0; i < m_Size; ++i)
		{
			memcpy_s(&(m_pData[i]), sizeof(Type), &(rhand.m_pData[i]), sizeof(Type));

		}
	}

	//Destructor
	template<typename Type, typename _allocator>
	inline Vector<Type, _allocator>::~Vector()
	{
		free(m_pData);
	}

	//Operators
	template<typename Type, typename _allocator>
	inline const Type & Vector<Type, _allocator>::operator[](unsigned int index) const
	{
		return m_pData[index];
	}
	template<typename Type, typename _allocator>
	inline Type & Vector<Type, _allocator>::operator[](unsigned int index)
	{
		return m_pData[index];
	}

	//Get
	template<typename Type, typename _allocator>
	inline size_tp Vector<Type, _allocator>::size() const
	{
		return m_Size;
	}

	//Element access
	template<typename Type, typename _allocator>
	inline Type & Vector<Type, _allocator>::at(unsigned int index)
	{
		//throw out_of_range exception
		if(index < 0 || index > m_Size)
			return Type();

		return m_pData[index];
	}
	template<typename Type, typename _allocator>
	inline Type & Vector<Type, _allocator>::front()
	{
		if(m_Size > 0)
			return m_pData[0];
		else
			//throw exception
			return Type();
	}
	template<typename Type, typename _allocator>
	inline Type & Vector<Type, _allocator>::back()
	{
		if(m_Size > 0)
			return m_pData[m_Size-1];
		else
		//throw exception
			return Type();
	}
	template<typename Type, typename _allocator>
	inline Type * Vector<Type, _allocator>::data()
	{
		return m_pData;
	}

	//Modifider
	template<typename Type, typename _allocator>
	inline void Vector<Type, _allocator>::swap(Vector<Type>& rhand)
	{
		//swap m_Size
		size_tp stemp = rhand.m_Size;
		rhand.m_Size = m_Size;
		m_Size = stemp;

		//swap m_pData
		Type* ptemp = rhand.m_pData;
		rhand.m_pData = m_pData;
		m_pData = temp;

		temp = nullptr;
	}
	template<typename Type, typename _allocator>
	inline void Vector<Type, _allocator>::clear()
	{
		m_Size = 0;
		free(m_pData);
		m_pData = nullptr;
	}
	template<typename Type, typename _allocator>
	inline void Vector<Type, _allocator>::insert(unsigned int index, Type& data)
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
	template<typename Type, typename _allocator>
	inline void Vector<Type, _allocator>::erase(unsigned int index)
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
	template<typename Type, typename _allocator>
	inline void Vector<Type, _allocator>::push_back(Type& data)
	{
		if(m_Size + 1 > m_Capacity)
		{
			Realloc();
		}
		m_pData[m_Size] = data;
		m_Size += 1;
	}
	template<typename Type, typename _allocator>
	inline void Vector<Type, _allocator>::pop_back()
	{
		m_Size -= 1;
	}
	//Protected functions
	
	//Private functions
	//malloc new storage space
	template<typename Type, typename _allocator>
	inline void Vector<Type, _allocator>::Malloc(size_tp size, Type** pData)
	{
		*pData = (Type*)malloc(size*sizeof(Type));
	}
	template<typename Type, typename _allocator>
	inline void Vector<Type, _allocator>::Realloc()
	{
		Type* pTemp = nullptr;
		Malloc(m_Capacity*2, **pTemp);
		CopyData(m_pData, pTemp);
		free(m_pData);
		m_pData = pTemp;
		p_Temp = nullptr;
		m_Size = m_Capacity;
		m_Capacity *= 2;
	}
	//Reset the m_Size
	template<typename Type, typename _allocator>
	inline void Vector<Type, _allocator>::Reset(size_tp NewSize, size_tp NewMemory)
	{
		m_Size = NewSize;
	}
	template<typename Type, typename _allocator>
	inline void Vector<Type, _allocator>::CopyData(Type* pOld, Type* pNew, size_tp size)
	{
		for (unsigned int i = 0; i < size; ++i)
		{
			memcpy_s(&pNew[i], sizeof(Type), &pOld[i], sizeof(Type));
		}
	}
}
#endif
