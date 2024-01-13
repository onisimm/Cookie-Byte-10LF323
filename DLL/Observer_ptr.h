#pragma once
#include<iostream>

#ifndef OBSERVER_PTR_H
#define OBSERVER_PTR_H

// !OBSERVER_PTR.H

namespace twixt
{

	template<typename T>
	class Observer_ptr
	{
	private:
		T* pointer;
	public:
		Observer_ptr();
		Observer_ptr(const Observer_ptr& pointer);
		Observer_ptr(T* pointer);
		Observer_ptr(std::unique_ptr<T> uniquePointer);
		~Observer_ptr();

		Observer_ptr& operator=(const Observer_ptr& Pointer);
		bool operator==(const Observer_ptr& Pointer) const;

		const T* GetPointer() const;
		T* GetPointer();

		template<typename S>
		S* To();
	};

	template<typename T>
	inline Observer_ptr<T>::Observer_ptr()
	{
		pointer = nullptr;
	}

	template<typename T>
	inline Observer_ptr<T>::Observer_ptr(const Observer_ptr& Pointer)
	{
		pointer = Pointer.pointer;
	}

	template<typename T>
	inline Observer_ptr<T>::~Observer_ptr()
	{}

	template<typename T>
	inline Observer_ptr<T>& Observer_ptr<T>::operator=(const Observer_ptr& Pointer)
	{
		pointer = Pointer.pointer;
		return *this;
	}

	template<typename T>
	inline bool Observer_ptr<T>::operator==(const Observer_ptr& Pointer) const
	{
		return this->pointer == Pointer.pointer;
	}

	template<typename T>
	inline const T* Observer_ptr<T>::GetPointer() const
	{
		return pointer;
	}

	template<typename T>
	inline T* Observer_ptr<T>::GetPointer()
	{
		return pointer;
	}

	template<typename T>
	inline Observer_ptr<T>::Observer_ptr(T* pointer)
	{
		this->pointer = pointer;
	}

	template<typename T>
	inline Observer_ptr<T>::Observer_ptr(std::unique_ptr<T> uniquePointer)
	{
		this->pointer = uniquePointer.get();
	}

	template<typename T>
	template<typename S>
	inline S* Observer_ptr<T>::To()
	{

		return dynamic_cast<S*>(pointer);
	}
}
#endif