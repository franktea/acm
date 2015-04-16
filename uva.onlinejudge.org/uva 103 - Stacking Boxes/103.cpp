/*
 * 103.cpp
 *
 *	uva 103 - Stacking Boxes
 *
 *  Created on: Feb 17, 2015
 *      Author: frank
 */

#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <vector>
#include <string>
#include <string.h>

using namespace std;

/**
 * 对k个n维的矩形，按照矩形从小到大，找出最长的递增子序列。
 */

const int32_t MAX_DIMENSION = 11;
const int32_t MAX_BOX_COUNT = 31;

struct Box
{
	int32_t dimension_; // 维度
	int32_t index_; // 是输入的第几个盒子， 要记住，输出的时候需要
	int32_t value_[MAX_DIMENSION];
	void Init(const int32_t dimension, const int32_t index)
	{
		dimension_ = dimension;
		index_ = index;
		bzero(value_, sizeof(value_));
		for(int32_t i = 1; i <= dimension_; ++i)
		{
			cin>>value_[i];
		}

		std::sort(value_ + 1, value_ + dimension_ + 1);
	}

	// box的比较，必须每一维都要严格小于，不能相等，与box排序函数不同
	bool operator < (const Box& rhs) const
	{
		for(int32_t i = 1; i <= dimension_; ++i)
		{
			if(value_[i] >= rhs.value_[i]) return false;
		}

		return true;
	}

	void Print()
	{
		cout<<index_<<"==>"<<value_[1];
		for(int32_t i = 2; i <= dimension_; ++i)
		{
			cout<<" "<<value_[i];
		}
		cout<<"\n";
	}
};

struct BoxSortCmp // 函数对象，相当于是inline，从结果看比直接传递函数指针快一点点
{
	// 排序，依次按照第一维、第二维。。。的从小到大的顺序
	bool operator()(const Box& lhs, const Box& rhs) const
	{
		// 排序函数很久没写对，先用string来代替，用string来搞，至少排序肯定是对的
	//	basic_string<int32_t> string1(lhs.value_+1, lhs.dimension_);
	//	basic_string<int32_t> string2(rhs.value_+1, rhs.dimension_);
	//	return string1 < string2;
		// 按照字典顺序排序，和比较的函数不同
		int32_t i = 1;
		while( (i <= lhs.dimension_) && (lhs.value_[i] == rhs.value_[i]) ) ++i;
		if(i > lhs.dimension_) return false;
		return lhs.value_[i] < rhs.value_[i];
	}
};

void Find(Box* boxes, const int32_t k)
{
	// 记录以第i个元素结尾的最长递增序列, 显然length[1] = 1
	// length[i+1] = 1 + max(length[x]), 1<=x<=i, 并且box[x] < box[i+1]
	// 如果之前所有的box都大于box[i+1]，则length[i+1] = 1
	int32_t length[MAX_BOX_COUNT];
	int32_t indexes[MAX_BOX_COUNT]; // 记录在第i个最长序列中，满足要求的前一个数组下标
	bzero(length, sizeof(length));
	bzero(indexes, sizeof(indexes));
	length[1] = 1;
	indexes[1] = 1;
	int32_t longest = length[1];
	int32_t longest_index = 1;
	for(int32_t i = 2; i <= k; ++i)
	{
		int32_t max_length = 0;
		int32_t max_index = 0;
		for(int32_t j = 1; j < i; ++j)
		{
			if(boxes[j] < boxes[i] && max_length < length[j])
			{
				max_length = length[j];
				max_index = j;
			}
		}

		length[i] = 1 + max_length;
		indexes[i] = max_length == 0 ? i : max_index;
		if(length[i] > longest)
		{
			longest = length[i];
			longest_index = i;
		}
	}

	cout<<longest<<"\n";
	// 逆序输出，用递归，递归更间接，但是提交发现不如之前的方法高效
	struct OutPut
	{
		static void Path(Box* boxes, int32_t* indexes, const int32_t longest_index)
		{
			if(longest_index == indexes[longest_index])
			{
				cout<<boxes[longest_index].index_;
			}
			else
			{
				OutPut::Path(boxes, indexes, indexes[longest_index]);
				cout<<" "<<boxes[longest_index].index_;
			}
		}
	};
	OutPut::Path(boxes, indexes, longest_index);
	cout<<"\n";
/*
	vector<int32_t> tmp;
	tmp.reserve(longest);
	// 输出数组下标，要倒过来，先用一个vector来实现倒序输出，也可以用递归，但是不知道递归是否更高效
	// cout<<boxes[longest_index].index_<<"***";
	tmp.push_back(boxes[longest_index].index_);
	while(longest_index > 0 && longest_index != indexes[longest_index])
	{
		longest_index = indexes[longest_index];
		//cout<<" "<<boxes[longest_index].index_;
		tmp.push_back(boxes[longest_index].index_);
	}

	std::reverse(tmp.begin(), tmp.end()); // size_t的类型从后往前输出时容易死循环，干脆逆序一下
	if(!tmp.empty())
	{
		cout<<tmp[0];
		for(size_t i = 1; i < tmp.size(); ++i)
		{
			cout<<" "<<tmp[i];
		}
		cout<<"\n";
	}
*/
}

int main()
{
	Box boxes[MAX_BOX_COUNT];
	BoxSortCmp boxsortcmp;
	int32_t k, n; // k个n维的盒子
	while(cin>>k>>n)
	{
		bzero(boxes, sizeof(boxes));
		for(int i = 1; i <= k; ++i)
		{
			boxes[i].Init(n, i);
		}
//		for(int i = 1; i <= k; ++i)
//		{
//			boxes[i].Print();
//		}
//		cout<<"===========after sort========="<<endl;

		std::sort(boxes + 1, boxes + k + 1, boxsortcmp);
//		for(int i = 1; i <= k; ++i)
//		{
//			boxes[i].Print();
//		}

		Find(boxes, k);
	}
	return 0;
}


