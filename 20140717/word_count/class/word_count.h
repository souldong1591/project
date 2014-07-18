#ifndef __WORD_COUNT_H__
#define __WORD_COUNT_H__ 

#include <set>
#include <map>
#include <string>

class WordCount
{
	public:
		WordCount(const std::string &file_name);	
		virtual ~WordCount();
		void add(const std::string &word);
		void print() const;
	private:
		void readExclude();
		std::map<std::string, int> words_;
		std::set<std::string> exclude_;
		std::string file_name_;
};


#endif  /*__WORD_COUNT_H__*/
