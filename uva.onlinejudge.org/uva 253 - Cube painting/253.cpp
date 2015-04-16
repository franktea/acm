/*
 * 253.cpp
 *
 *	uva 253 - Cube painting
 *
 *  Created on: Feb 20, 2015
 *      Author: frank
 */

#include <iostream>
#include <string.h>
#include <stdint.h>

using namespace std;

/* 一个立方体转来转去共有24种组合，24种组合的编号一定是有规律的，
 * 应该是只要其中一个就可以推出其它剩下的。
 * 不过还没去管，先全部列出来再说。
 */

template<typename T, std::size_t N>
std::size_t array_size(T(&)[N])
{
	return N;
}

// 为了和后面的数据类型统一，这里也用char，
// 因为取值范围很小，用char足够
const char all[][6] = {
		{1, 2, 3, 4, 5, 6}, {1, 5, 4, 3, 2, 6},
		{2, 6, 3, 4, 1, 5}, {5, 6, 4, 3, 1, 2},
		{6, 5, 3, 4, 2, 1}, {6, 2, 4, 3, 5, 1},
		{5, 1, 3, 4, 6, 2}, {2, 1, 4, 3, 6, 5},

		{1, 4, 2, 5, 3, 6}, {1, 3, 5, 2, 4, 6},
		{4, 6, 2, 5, 1, 3}, {3, 6, 5, 2, 1, 4},
		{6, 3, 2, 5, 4, 1}, {6, 4, 5, 2, 3, 1},
		{3, 1, 2, 5, 6, 4}, {4, 1, 5, 2, 6, 3},

		{4, 5, 6, 1, 2, 3}, {4, 2, 1, 6, 5, 3},
		{5, 3, 6, 1, 4, 2}, {2, 3, 1, 6, 4, 5},
		{3, 2, 6, 1, 5, 4}, {3, 5, 1, 6, 2, 4},
		{2, 4, 6, 1, 3, 5}, {5, 4, 1, 6, 3, 2}};

template<class T, std::size_t N>
bool Compare(const T(&a)[N], const T(&b)[N])
{
	for(size_t i = 0; i < N; ++i)
	{
		if(a[i] != b[i]) return false;
	}

	return true;
}

// 按照pos中的位置，把b中的内容变化到c中去
template<class T, std::size_t N>
void Rotate(const T(&pos)[N], const T(&b)[N], T(&c)[N])
{
	for(size_t i = 0; i < N; ++i)
	{
		c[i] = b[pos[i]-1];
	}
}

template<class T, std::size_t N>
void Check(const T(&a)[N], const T(&b)[N])
{
	T c[N]; // 转动b的结果保存在这里
	bool is_same = false;
	for(size_t i = 0; i < array_size(all); ++i)
	{// 数组a的内容无须改变，按照24种可能的情况转动数组b，只要有一种符合，就算一样
		Rotate(all[i], b, c);
		if(Compare(a, c))
		{
			is_same = true;
			break;
		}
	}

	if(is_same) cout<<"TRUE\n";
	else cout<<"FALSE\n";
}

int main()
{
	char a[6]; char b[6];
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>
			b[0]>>b[1]>>b[2]>>b[3]>>b[4]>>b[5])
	{
		Check(a, b);
	}
	return 0;
}



