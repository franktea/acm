/*
 * 140.cpp
 *
 *  Created on: Sep 17, 2018
 *      Author: frank
 */
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

// 用的跟139一样的方法，依然是递归，打败99.9%。
// 本题中是要得到所有的结果，用一个map把所有的index全部保存下来，最后根据index来构建结果。

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
    	visited_.clear();
    	visited_.resize(s.length()+1, -1);
    	indexes_.clear();
    	bool ret = DFS(0, s, wordDict);
    	if(!ret)
    		return {};
//    	cout<<"result:"<<ret<<"\n";
//    	for(int i: visited_)
//    		cout<<i<<", ";
//    	cout<<"\n";
//    	cout<<"---------------------\n";
//    	for(auto it = indexes_.begin(); it != indexes_.end(); ++it)
//    	{
//    		cout<<it->first<<": [";
//    		for(int i: it->second)
//    			cout<<i<<", ";
//    		cout<<"]\n";
//    	}
    	string tmp = "";
    	BuildResult(tmp, 0, wordDict);
    	return result_;
    }
private:
    // index is index in string s
    bool DFS(int index, const string& s, const vector<string>& dict)
    {
    	//cout<<"index="<<index<<"\n";
    	if(index >= s.length())
    		return true;

    	bool result = false;
    	for(int i = 0; i < dict.size(); ++i)
		{
    		if(int(s.length())-index >= dict[i].length() &&
    				0 == memcmp(&s[0]+index, &dict[i][0], dict[i].length()))
    		{
    			const int next_index = index + dict[i].length();
    			if(visited_[next_index] == -1)
    			{
    				bool ret = DFS(index + dict[i].length(), s, dict);
    				if(ret)
    				{
    					visited_[next_index] = 1;
    					result = true;
    					indexes_[index].push_back(i);
    				}
    				else
    				{
    					visited_[next_index] = visited_[next_index] == -1 ? 0 : visited_[next_index];
    				}
    			}
    			else if(visited_[next_index] == 0)
    			{
    				continue;
    			}
    			else // 1
    			{
    				result = true;
    				indexes_[index].push_back(i); // 所有满足条件的都要记下来
    			}
    		}
		}

    	return result;
    }

    void BuildResult(string str, int index, const vector<string>& dict)
    {//indexes_中的结果其实是一个树状结构，用深度优先来遍历节点，到叶子节点的时候输出结果即可
    	if(indexes_.find(index) == indexes_.end())
    	{
    		result_.push_back(str);
    		return;
    	}

    	for(int i: indexes_[index])
    	{
    		string tmp = str.empty() ? dict[i] : str + string(" ") + dict[i];
    		BuildResult(tmp, index+dict[i].length(), dict);
    	}
    }
private:
    vector<string> result_;
    std::map<int, vector<int>> indexes_; // key->values保存的是在string的key位置，有values中所表示的字符串可以匹配上，values中用int表示在dict数组中的下标
    vector<int> visited_;
};

int main()
{
	vector<string> words = {"apple", "pen", "applepen", "pine", "pineapple"};
	vector<string> ret;
	Solution* ps = new Solution;
	ret = ps->wordBreak("pineapplepenapple", words);
	for(auto&& str: ret)
		cout<<str<<"\n";
	return 0;
}

