/*
 * 32_Longest_Valid_Parentheses.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: frank
 */

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
	struct Range
	{
		int start;
		int ending;
		bool operator<(const Range& another) const
		{
			return start < another.start;
		}

		int Length()
		{
			return ending - start + 1;
		}

		// make sure *this < another
		bool OverLap(const Range& another) const
		{
			return (this->ending + 1 == another.start) ||
					(this->ending > another.ending);
		}

		void Merge(const Range& another)
		{
			this->ending = std::max(this->ending, another.ending);
		}
	};

	struct Pos
	{
		int index;
		char c;
	};
public:
    int longestValidParentheses(string s)
    {
    	list<Pos> q; // work as a queue
    	vector<Range> ranges;
    	for(int i = 0; i < s.length(); ++i)
    	{
    		if(s[i] == ')')
    		{
    			if(q.back().c != '(')
    			{
    				q.clear();
    			}
    			else
    			{
    				ranges.push_back({q.back().index, i});
    				q.pop_back();
    			}
    		}
    		else // s[i] == '('
    		{
    			q.push_back({i, s[i]});
    		}
    	}

    	if(ranges.empty())
    		return 0;

    	sort(ranges.begin(), ranges.end());

    	size_t current_index = 0;
    	int max_length = ranges[0].Length();
    	for(size_t i = 1; i < ranges.size(); ++i)
    	{
    		if(current_index == i)
    			continue;

    		if(ranges[current_index].OverLap(ranges[i]))
    		{
    			ranges[current_index].Merge(ranges[i]);
    		}
    		else
    		{
    			max_length = std::max(max_length, ranges[current_index].Length());
    			current_index = i;
    		}
    	}
    	max_length = std::max(max_length, ranges[current_index].Length());

//    	for(auto r: ranges)
//    	{
//    		cout<<r.start<<", "<<r.ending<<"\n";
//    	}

    	return max_length;
    }
};

int main()
{
	Solution s;
	cout<<s.longestValidParentheses("((())()")<<"\n";
	cout<<s.longestValidParentheses("(()()((()()())")<<"\n";
	return 0;
}
