#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__ 

#include <stddef.h>

template <typename T>
class SmartPtr
{
	public:
		SmartPtr();
		explicit SmartPtr(T *ptr);
		~SmartPtr();

		void resetPtr(T *ptr);
		const T *getPtr() const;

		T &operator * ();
		const T &operator * () const;

		T *operator -> ();
		const T *operator -> () const;

		operator bool() const
		{
			return ptr_;
		}

	private:
		T *ptr_;
		SmartPtr(const SmartPtr &);
		void operator = (const SmartPtr &);
	
};


template <typename T>
inline SmartPtr<T>::SmartPtr():
	ptr_(NULL)
{}

template <typename T>
inline SmartPtr<T>::SmartPtr(T *ptr):
	ptr_(ptr)
{}

template <typename T>
inline SmartPtr<T>::~SmartPtr()
{
	delete ptr_;
}

template <typename T>
inline void SmartPtr<T>::resetPtr(T *ptr)
{
	if(ptr != ptr_)
	{
		delete ptr_;
		ptr_ = ptr;
	}
}

template <typename T>
inline const T *SmartPtr<T>::getPtr() const
{
	return ptr_;
}

template <typename T>
inline T &SmartPtr<T>::operator * ()
{
	return *ptr_;
}

template <typename T>
inline const T &SmartPtr<T>::operator * () const
{
	return *ptr_;
}

template <typename T>
inline T *SmartPtr<T>::operator -> ()
{
	return ptr_;
}

template <typename T>
inline const T *SmartPtr<T>::operator -> () const
{
	return ptr_;
}





#endif  /*__SMARTPTR_H__*/
