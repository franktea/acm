/*
 * 224.cpp
 *
 *  Created on: Sep 11, 2018
 *      Author: frank
 */
#include <string>
#include <stack>
#include <iostream>
#include <cctype> // isdigit
#include <cassert>

using namespace std;

enum ItemType {IT_NUMBER, IT_OPERATOR, IT_BARCKET};

struct Item
{
	int v;
	ItemType type;

	Item operator()(const Item& lhs, const Item& rhs)
	{
		assert(type == IT_OPERATOR);
		assert(lhs.type == IT_NUMBER);
		assert(rhs.type == IT_NUMBER);
		if(v == '+')
			return Item { lhs.v + rhs.v, IT_NUMBER};
		else
			return Item { lhs.v - rhs.v, IT_NUMBER};
	}
};

class Solution {
public:
    int calculate(string s) {
    	s = RemoveSpace(s);
    	if(s.empty()) return 0;

    	stack<Item> slots;
    	int i = 0;
    	while(i < s.length())
    	{
    		const char c = s[i];
    		if(c == '(')
    		{
    			slots.push(Item{c, IT_BARCKET});
    			++i;
    		}
    		else if(c == ')')
    		{
    			Item item = slots.top();
    			slots.pop();
    			while(slots.top().type != IT_BARCKET)
    			{
    				Item op = slots.top();
    				slots.pop();
    				Item lhs = slots.top();
    				slots.pop();
    				item = op(lhs, item);
    			}
    			slots.pop();
    			while(!slots.empty() && slots.top().type == IT_OPERATOR)
    			{
    				Item op = slots.top();
    				slots.pop();
    				Item lhs = slots.top();
    				slots.pop();
    				item = op(lhs, item);
    			}
    			slots.push(item);

    			++i;
    		}
    		else if(c == '+' || c == '-')
    		{
    			slots.push(Item{c, IT_OPERATOR});
    			++i;
    		}
    		else
    		{
    			int index = i;
    			while(index < s.length() && std::isdigit(s[index]))
    				++index;

    			int number = std::stoi(s.substr(i, index - i));
    			Item item {number, IT_NUMBER};
    			while(!slots.empty() && slots.top().type == IT_OPERATOR)
    			{
    				Item op = slots.top();
    				slots.pop();
    				Item lhs = slots.top();
    				slots.pop();
    				item = op(lhs, item);
    			}
    			slots.push(item);

    			i = index;
    		}
    	}

    	int value = slots.top().v;
//    	while(!slots.empty())
//    	{
//    		cout<<slots.top().v<<", "<<slots.top().type<<"\n";
//    		slots.pop();
//    	}

    	return value;
    }
private:
    string RemoveSpace(const string& s)
    {
    	string result;
    	result.reserve(s.size());
    	for(char c: s)
    	{
    		if(c != ' ')
    			result.push_back(c);
    	}
    	return result;
    }
};

int main()
{
	Solution* ps = new Solution;
	string str = "((3 + 2) - 5) + (((6 - (7 + 8) - 9) - 10) + 11)";
	int ret = ps->calculate(str);
	cout<<"ret="<<ret<<"\n";
	return 0;
}



