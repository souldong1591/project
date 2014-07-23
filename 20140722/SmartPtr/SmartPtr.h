#ifndef __SMART_H__
#define __SMART_H__ 

#include <iostream>
class Animal
{
	public:
		Animal()
		{
			std::cout << "Animal..." << std::endl;
		}
		~Animal()
		{
			std::cout << "~Animal...."  << std::endl;
		}
};

class SmartPtr
{
	public:
		SmartPtr();
		explicit SmartPtr(Animal *ptr);
		~SmartPtr();

		void resetPtr(Animal *ptr);
		const Animal *getPtr() const;

		Animal &operator * ();
		const Animal &operator * () const;

		Animal *operator -> ();
		const Animal *operator -> () const;
	private:
		SmartPtr(const SmartPtr &);
		void operator = (const SmartPtr &);
		Animal *ptr_;
};



#endif  /*__SMART_H__*/
