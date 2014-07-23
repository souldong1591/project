#ifndef __HANDLE_H__
#define __HANDLE_H__ 

class Animal;

class Handle
{
	public:
		Handle();
		Handle(const Animal &);
		Handle(const Handle &);
		Handle &operator = (const Handle &);
		~Handle();
		
		Animal *operator -> ();
		const Animal *operator -> () const;
	private:
		Animal *ptr_;
};

#endif  /*__HANDLE_H__*/
