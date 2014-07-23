#ifndef __ANIMAL_H__
#define __ANIMAL_H__ 

#include <iostream>

class Animal
{
	public:
		virtual ~Animal() {}
		virtual void display() const = 0;

		virtual Animal *copy() const = 0;
};

class Cat: public Animal
{
	public:
		void display() const
		{
			std::cout << "Cat" << std::endl;
		}

		Cat *copy() const
		{
			return new Cat(*this);
		}

};

class Dog: public Animal
{
	public:
		void display() const
		{
			std::cout << "Dog" << std::endl;
		}

		Dog *copy() const
		{
			return new Dog(*this);
		}

};

class Beer: public Animal
{
	public:
		void display() const
		{
			std::cout << "Beer" << std::endl;
		}

		Beer *copy() const
		{
			return new Beer(*this);
		}

};

#endif  /*__ANIMAL_H__*/
