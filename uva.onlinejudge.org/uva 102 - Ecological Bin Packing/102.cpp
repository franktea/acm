/*
 * 102.cpp
 *
 *  102 - Ecological Bin Packing
 *
 *  Created on: Dec 13, 2015
 *      Author: frank
 */

#include <iostream>
#include <algorithm>
#include <map>
#include <stdint.h>

using namespace std;

struct Bin
{
	int32_t bc; // brown bottle count
	int32_t gc; // green bottle count
	int32_t cc; // clear bottle count

	int32_t MovementsCount(char label) const
	{
		if(label == 'G')
		{
			return bc + cc;
		}
		else if(label == 'B')
		{
			return gc + cc;
		}
		else // label == 'C'
		{
			return gc + bc;
		}
	}
};

class BinPacker
{
public:
	BinPacker(int32_t bc1, int32_t gc1, int32_t cc1,
			int32_t bc2, int32_t gc2, int32_t cc2,
			int32_t bc3, int32_t gc3, int32_t cc3)
	{
		bins_[0] = Bin{bc1, gc1, cc1};
		bins_[1] = Bin{bc2, gc2, cc2};
		bins_[2] = Bin{bc3, gc3, cc3};
	}

	void GetMinMovements()
	{
		std::map<int32_t, string> all_counts;
		string all_colors = "BCG";
		do
		{
			//cout<<all_colors<<endl;
			int32_t count = GetMovementsCount(all_colors);
			//插入，如果数值的key存在就会失败，
			//但是由于next_permutation本身就是字典顺序的，所以失败也不用管
			all_counts.insert(std::make_pair(count, all_colors));

		}while(std::next_permutation(all_colors.begin(), all_colors.end()));
		cout<<all_counts.begin()->second<<" "<<all_counts.begin()->first<<endl;
	}
private:
	/**
	 * 计算按照某个字符串排列时的移动次数
	 * @param color_string 字符串， 行如 GBC BCG GCB
	 * @return
	 */
	int32_t GetMovementsCount(const string& color_string)
	{
		return bins_[0].MovementsCount(color_string[0]) +
				bins_[1].MovementsCount(color_string[1]) +
				bins_[2].MovementsCount(color_string[2]);
	}
private:
	Bin bins_[3];
};

int main()
{
	std::ios::sync_with_stdio(false);
	int32_t bc1, gc1, cc1, bc2, gc2, cc2, bc3, gc3, cc3;
	while(cin>>bc1>>gc1>>cc1>>bc2>>gc2>>cc2>>bc3>>gc3>>cc3)
	{
		BinPacker bp(bc1, gc1, cc1, bc2, gc2, cc2, bc3, gc3, cc3);
		bp.GetMinMovements();
	}

	return 0;
}


