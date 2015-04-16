/*
 * 282.cpp
 *
 *  Created on: Feb 22, 2015
 *      Author: frank
 */

#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>

using namespace std;

/**
 尝试了一下c++11中强大又复杂的regex，将＊匹配的部分提取出来，
 居然一次AC了， 后来发现结果排在十几名， 真是难以想象。
 难道c++的regex真的是难以想象的高效？ regex的语法参考这里：
 http://en.cppreference.com/w/cpp/regex/regex_search
 */

void Solve(std::vector<string>& lines, const std::string& from,
		const std::string& to)
{
	string from_pattern;
	for(char c: from)
	{
		if(c == '*')
			from_pattern.append("(.*)");
		else if(c == '.')
			from_pattern.append("\\.");
		else
			from_pattern.push_back(c);
	}

	std::regex wildcard(from_pattern);
	std::smatch sub;
	for(const auto &line: lines)
	{
		std::regex_match(line, sub, wildcard);
		if(sub.size() > 0)
		{
			string part = sub[1].str(); // 星号匹配的子串
			string result;
			for(char c: to) // 将结果中的＊替换成子串然后输出
			{
				if(c == '*') result.append(part);
				else result.push_back(c);
			}
			cout<<"mv "<<line<<" "<<result<<"\n";
		}
	}
}

void Tokenize(const string& str,
                      vector<string>& tokens,
                      const string& delimiters = " ")
{
    // Skip delimiters at beginning.
    string::size_type last_pos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, last_pos);

    while (string::npos != pos || string::npos != last_pos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(last_pos, pos - last_pos));
        // Skip delimiters.  Note the "not_of"
        last_pos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, last_pos);
    }
}

int main()
{
	std::vector<string> lines;
	string line;
	while(std::getline(cin, line))
	{
		if(line == "end") break;

		lines.clear();
		lines.push_back(line);
		while(getline(cin, line))
		{
			if(line == "end") break;
			lines.push_back(line);
		}

		while(getline(cin, line))
		{
			if(line == "end") break;

			cout<<line<<"\n"; // rename命令，要输出一遍
			std::vector<string> tokens;
			Tokenize(line, tokens);
			Solve(lines, tokens[1], tokens[2]);
		}

		cout<<"\n";
	}
}


