#ifndef WORD_INDEX_H_
#define WORD_INDEX_H_ 

#include <map>
#include <unordered_map>


class WordIndex
{
	public:
		WordIndex(char *path);
		void creatIndex();
		std::unordered_map<char, std::map<std::string, int> > getIndex() const;
		
	private:
		char *path_;
		std::unordered_map<char, std::map<std::string, int> > wordIndex_;
		
};




#endif  /*WORD_INDEX_H_*/
