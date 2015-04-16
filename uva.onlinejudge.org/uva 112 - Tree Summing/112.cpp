/*
 * 112_1.cpp
 *
 *  title: Tree Summing
 *
 *  Created on: Feb 3, 2015
 *      Author: frank
 */
#include <stdint.h>
#include <stddef.h> // for NULL
#include <iostream>
#include <string>
#include <stdio.h> // for getchar
#include <ctype.h> // for isspace

using namespace std;

class Text
{
public:
	Text(): index_(0) { content_.reserve(8192); }
	inline const char Get()
	{
		return index_ >= content_.size() ? '\0' : content_[index_++];
	}

	inline const char Peek()
	{
		return index_ >= content_.size() ? '\0' : content_[index_];
	}

	void InitFromStdin()
	{
		int c = getchar();
		while(c != EOF)
		{
			content_.push_back(char(c));
			c = getchar();
		}
	}

	inline bool Finished()
	{
		return index_ >= content_.size();
	}

	bool NextInt(int32_t& value)
	{
		bool result = false;

		while( (index_ < content_.size()) &&
				(content_[index_] != '-') &&
				! isdigit(content_[index_]) )
		{
			++index_;
		}

		bool is_negtive = false;
		if( (index_ < content_.size()) && (content_[index_] == '-') )
		{
			++index_;
			is_negtive = true;
		}

		while( (index_ < content_.size()) &&
				(! isdigit(content_[index_])) )
		{
			++index_;
		}

		value = 0;
		while( (index_ < content_.size()) && isdigit(content_[index_]))
		{
			result = true;
			const char c = Get();
			value = value*10 + (c - '0');
		}

		if(is_negtive)
		{
			value = 0 - value;
		}

		return result;
	}

	bool ConsumeLeftBracket()
	{
		while( (index_ < content_.size()) && content_[index_] != '(')
		{
			++ index_;
		}

		if( (index_ < content_.size()) && content_[index_] == '(')
		{
			++ index_;
			return true;
		}

		return false;
	}

	bool ConsumeRightBracket()
	{
		while( (index_ < content_.size()) && content_[index_] != ')')
		{
			++ index_;
		}

		if( (index_ < content_.size()) && content_[index_] == ')')
		{
			++ index_;
			return true;
		}

		return false;
	}

	inline void GoToNextNoneSpace()
	{
		while( (index_ < content_.size()) && isspace(content_[index_]))
		{
			++index_;
		}
	}

//	string ParsedText()
//	{
//		return string(&content_[0], &content_[index_]);
//	}

	void JumpUntilNextEnd(int32_t level)
	{
		while(index_ < content_.size())
		{
			if(content_[index_] == '(')
				++ level;
			else if(content_[index_] == ')')
				-- level;

			if(0 == level)
			{
				break;
			}

			++ index_;
		}
	}

//	string& All() { return content_; }
//
//	void SetString(string str) { content_ = str; }
private:
	size_t index_;
	string content_;
};

class TreeNode
{
public:
	TreeNode(int32_t level, Text& text): empty_(true), value_(0), level_(level),
		text_(text), left_(NULL), right_(NULL){}

	void Parse(const int32_t expected_sum, const int32_t current_sum,
			bool& found)
	{
		if(found)
		{
			return;
		}

		text_.ConsumeLeftBracket();
		text_.GoToNextNoneSpace();
		const char c = text_.Peek();
		if(c == '\0')
		{
			return;
		}
		else if(c == ')') // just empty
		{
			text_.ConsumeRightBracket();
		}
		else // has positive or negtive value
		{
			empty_ = false;
			text_.NextInt(value_);
			left_ = new TreeNode(level_ + 1, text_);
			left_->Parse(expected_sum, current_sum + value_, found);
			if(found) return;
			right_ = new TreeNode(level_ + 1, text_);
			right_->Parse(expected_sum, current_sum + value_, found);
			if(found) return;
			text_.ConsumeRightBracket();
			if(left_->empty_ && right_->empty_ &&
					expected_sum == current_sum + value_)
			{
				found = true;
				text_.JumpUntilNextEnd(level_ - 1);
			}
		}

	}
private:
	bool empty_;
	int32_t value_;
	int32_t level_;
	Text& text_;
	TreeNode* left_;
	TreeNode* right_;
};

int main()
{
	Text text;
	text.InitFromStdin();
	while(! text.Finished())
	{
		int32_t sum = 0;
		if(! text.NextInt(sum)) break;
		TreeNode* root = new TreeNode(1, text);
		bool found = false;
		root->Parse(sum, 0, found);
		const char* str = found ? "yes\n" : "no\n";
		cout<<str;
	}

	return 0;
}


