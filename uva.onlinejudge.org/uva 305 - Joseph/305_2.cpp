/*
 * 305_2.cpp
 *
 *	uva 305 - Joseph
 *
 *  Created on: Feb 18, 2015
 *      Author: frank
 */

#include <iostream>
#include <list>
#include <bitset>
#include <stdint.h>
#include <string.h>
//#include <assert.h>

using namespace std;

// 向前一步(不管下一个位置是否已经被删除)
#define MOVE 		++index; if(index>=2*k) index = 0;
// 走到下一个有人的位置，如果当前位置就有人，就不动
#define NEXT		while(!(guys & (1 << index))) { MOVE }

bool Test(const int32_t m, const int32_t k)
{
	int32_t guys = -1; // 2＊k最多不超过32，可以用一个32位整数的每个位来表示。先将所有位置1
	int32_t index = 0;
	int32_t deleted = 0;
	int32_t next_steps = m % (2*k);
	if(next_steps == 0) next_steps = 2*k - deleted;
	while(1)
	{
		// 向前移动next_steps个位置，即移动到下一个被删除的位置，
		// 当前位置为第1步，还需要移动 next_steps-1 步
		NEXT
		while(--next_steps > 0)
		{
			if(guys & (1 << index)) { MOVE }
			NEXT
		}

		//assert(guys & (1 << index));
		if(index < k) return false;
		++ deleted;
		guys &= ~(1<<index);
		next_steps = m % (2*k - deleted);
		if(next_steps == 0) next_steps = 2*k - deleted;

		if(deleted >= k)
		{
			//cout<<bitset<32>(guys)<<endl;
			return true;
		}
	}
}

int main()
{
	int32_t k;
	int32_t cache[14] = {0};
	while(cin>>k)
	{
		if(0 == k) break;

		if(0 != cache[k])
		{
			cout<<cache[k]<<"\n";
			continue;
		}

		int32_t m = 0;
		do{ ++ m; }while(! Test(m, k));
		cache[k] = m;
		cout<<m<<"\n";
	}

	return 0;
}



