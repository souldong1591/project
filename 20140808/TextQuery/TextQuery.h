#ifndef TEXT_QUERY_H_
#define TEXT_QUERY_H_ 

#include "NonCopyable.h"
#include <vector>
#include <map>
#include <fstream>
#include <set>
#include <string>

class TextQuery : NonCopyable
{
	public:
		typedef std::vector<std::string>::size_type line_no;

		void read_file(std::ifstream &is)
		{ store_file(is); build_map(); }

		std::set<line_no> run_query(const std::string&) const;
		std::string text_line(line_no) const;
	private:
		void store_file(std::ifstream&);
		void build_map();
		std::vector<std::string> lines_of_text;
		std::map< std::string, std::set<line_no> > word_map;
};



#endif  /*TEXT_QUERY_H_*/
