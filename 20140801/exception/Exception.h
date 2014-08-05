#ifndef EXCEPTION_H_
#define EXCEPTION_H_ 

#include <string>
#include <exception>

class Exception : public std::exception
{
	public:
		Exception(const char *);
		Exception(const std::string &);
		virtual ~Exception() throw();
		virtual const char *what() const throw();
		const char *stackTrace() const throw();
	private:
		void fillStackTrace();
		std::string message_;
		std::string stack_;
};



#endif  /*EXCEPTION_H_*/
