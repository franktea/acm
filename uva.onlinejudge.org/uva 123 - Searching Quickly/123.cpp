/*
 * 123.cpp
 *
 *	uva 123 - Searching Quickly
 *
 *  Created on: Feb 17, 2015
 *      Author: frank
 */

#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stddef.h>

using namespace std;

/**
 * 定义一组非关键字，每碰到一个含有关键字的句子，就把整句输出一遍，其中关键字转为大写，其它全部转为小写，
 * 如果一个句子有多个关键字，就要输出多遍。
 *
 * 输出的时候注意，句子的空格要和原来的空格个数一样(如果末尾含有空格应该也一样保留)；
 * 对于含有同一个关键字的句子，输出的顺序需要与输入的顺序相同。
 * 采用multimap，最后输出的顺序就刚好和输入的顺序一样的。
 */

void Tokenize(const string& str, vector<string>& tokens)
{
    size_t index = 0;
    while(index < str.length())
    {
    	if(str[index] == ' ' || str[index] == '\t')
    	{
    		string spaces;
    		while(index < str.length() && (str[index] == ' ' || str[index] == '\t'))
    		{
    			spaces.push_back(str[index]);
    			++ index;
    		}
    		tokens.push_back(spaces);
    	}

    	if(index < str.length())
    	{
    		string word;
			while(index < str.length() && (str[index] != ' ') && str[index] != '\t')
			{
				word.push_back(tolower(str[index]));
				++ index;
			}
			tokens.push_back(word);
    	}
    }
}

std::string MakeSentence(const vector<string>& words, const size_t index, const string& key_word)
{
	string result;
	for(size_t i = 0; i < words.size(); ++i)
	{
		if(i == index) result.append(key_word);
		else result.append(words[i]);
	}
	return result;
}

void ProcessSentence(string& line, set<string>& ignore,
		std::multimap<std::string, std::string>& sentences)
{
	std::vector<string> words;
	Tokenize(line, words);
	for(size_t i = 0; i < words.size(); ++i)
	{
		if((words[i][0] != ' ' && words[i][0] != '\t') && ignore.find(words[i]) == ignore.end())
		{
			string key_word = words[i];
			std::transform(key_word.begin(), key_word.end(),key_word.begin(), ::toupper);


			string result;
			for(size_t index = 0; index < words.size(); ++index)
			{
				if(index == i) result.append(key_word);
				else result.append(words[index]);
			}

			sentences.insert(std::make_pair(key_word, result));
		}
	}
}

int main()
{
	std::set<std::string> ignore;
	std::multimap<std::string, std::string> sentences;
	string line;
	bool is_sentence = false;
	while(std::getline(cin, line))
	{
		if(line == "::")
		{
			is_sentence = true;
			continue;
		}

		if(! is_sentence)
		{
			ignore.insert(line);
		}
		else
		{
			ProcessSentence(line, ignore, sentences);
		}
	}

	for(auto it = sentences.begin(); it != sentences.end(); ++it)
	{
		cout<<it->second<<"\n";
	}

	return 0;
}


