#ifndef __SMART_PTR_H__
#define __SMART_PTR_H__ 

#include <iostream>
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
	TypeName(const TypeName&); \
	void operator=(const TypeName&)

class Animal
{
	public:
		Animal()
		{
			std::cout << "construct......" << std::endl;
		}

		~Animal()
		{
			std::cout << "detruct......" << std::endl;	
		}
		void run()
		{
			std::cout << "runing......" << std::endl;
		}
		
};

class SmartPtr
{
	public:
		SmartPtr(Animal *ptr);
		~SmartPtr();
		Animal &operator * ();
		const Animal &operator * () const;

		Animal *operator -> ();
		const Animal *operator -> () const;
	private:
		DISALLOW_COPY_AND_ASSIGN(SmartPtr);
		Animal *ptr_;
};


#endif  /*__SMART_PTR_H__*/
