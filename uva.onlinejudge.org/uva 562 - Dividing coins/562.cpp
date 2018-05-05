/**
 * uva 562 - Dividing coins
 * frank 2018-05-04
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib> // abs
#include <stdint.h>

using namespace std;

/**
 * 可以看成一个大小为sum/2的背包，装尽可能多的硬币(装进去的硬币是需要分成的两堆中较小的一堆，
 * 未被装进去的是较大的一堆)，
 * 于是就变成了一个不折不扣的0/1背包问题。
 */

namespace std {
template<> struct hash<std::pair<int, int>>
{
	size_t operator()(const std::pair<int, int>& p) const
	{
		return std::hash<int>{}(p.first) ^ std::hash<int>{}(p.second);
	}
};
}

// 递归解决方案，会超时
class Knap
{
public:
	Knap() : total_sum_ { 0 } {}
	void Input()
	{
		int count;
		cin>>count;
		values_.resize(count + 1);
		values_[0] = 0;
		for(int i = 1; i <= count; ++i)
		{
			cin>>values_[i];
			total_sum_ += values_[i];
		}
	}

	void Solve()
	{
		int result = DP(values_.size(), total_sum_/2);
		cout<<abs(total_sum_ - 2 * result)<<"\n";
	}
private:
	int DP(int i, int w)
	{
		if(i == 0)
		{
			return 0;
		}

		auto it = result_map_.find(std::pair<int, int> {i, w});
		if(it != result_map_.end())
		{
			return it->second;
		}

		int result = 0;
		if(values_[i] > w)
		{
			result = DP(i - 1, w);
		}
		else
		{
			result = std::max(DP(i - 1, w), DP(i - 1, w - values_[i]) + values_[i]);
		}

		result_map_.insert(std::make_pair(std::make_pair(i, w), result));
		return result;
	}
private:
	int total_sum_;
	vector<int> values_;
	unordered_map<std::pair<int, int>, int> result_map_;
};

// 自底向上的解决方案
class BottomToUp
{
public:
	void Input()
	{
		cin>>coin_count_;
		values_.resize(coin_count_ + 1);
		values_[0] = 0;
		for(int i = 1; i <= coin_count_; ++i)
		{
			cin>>values_[i];
			total_sum_ += values_[i];
		}

		knap_weight_ = total_sum_ / 2;
		table_.resize(coin_count_ + 1);
		for(int i = 0; i <= coin_count_; ++i)
		{
			table_[i].resize(knap_weight_ + 1);
		}

		//cout<<"total_sum_ = "<<total_sum_<<", knap_weight_ = "<<knap_weight_<<", coin_count_ = "<<coin_count_<<"\n";
	}

	void Solve()
	{
		for(int i = 0; i <= knap_weight_; ++i)
		{
			table_[0][i] = 0;
		}
		for(int i = 0; i <= coin_count_; ++i)
		{
			table_[i][0] = 0;
		}

		for(int i = 1; i <= coin_count_; ++i)
		{
			for(int w = 1; w <= knap_weight_; ++w)
			{
				if(w < values_[i])
				{
					table_[i][w] = table_[i-1][w];
				}
				else
				{
					table_[i][w] = std::max(table_[i - 1][w], table_[i - 1][w - values_[i]] + values_[i]);
				}
			}
		}

		//PrintMap();

		int result = table_[coin_count_][knap_weight_];
		cout<<abs(total_sum_ - 2 * result)<<"\n";
	}
private:
	void PrintMap()
	{
		for(int j = 0; j < table_[0].size(); ++j)
		{
			printf("%3d ", j);
		}
		printf("\n");

		for(int i = 0; i < table_.size(); ++i)
		{
			for(int j = 0; j < table_[i].size(); ++j)
			{
				printf("%3d ", table_[i][j]);
			}
			printf("\n");
		}
	}
private:
	int coin_count_ = 0;
	int knap_weight_ = 0; // 背包容量 = total_sum / 2
	int total_sum_ = 0;
	vector<int> values_;
	vector<vector<int>> table_;
};

int main()
{
	int cases;
	cin>>cases;
	while(cases--)
	{
		//Knap knap;
		BottomToUp knap;
		knap.Input();
		knap.Solve();
	}
	return 0;
}
