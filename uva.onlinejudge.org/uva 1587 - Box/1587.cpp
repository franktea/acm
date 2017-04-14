/*
 * 1587.cpp
 *
 *  Created on: Apr 14, 2017
 *      Author: frank
 */
#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <stdint.h>

using namespace std;

class Edege
{
	friend class Box;
	friend ostream& operator<<(ostream& os, const Edege& e);
public:
	Edege(int32_t a, int32_t b): a(a), b(b)
	{
		if(this->a > this->b)
		{
			std::swap(this->a, this->b);
		}
	}

	bool operator==(const Edege& other) const
	{
		return this->a == other.a && this->b == other.b;
	}

	bool operator<(const Edege& other) const
	{
		if(a != other.a)
		{
			return a < other.a;
		}
		else
		{
			return b < other.b;
		}
	}
private:
	int32_t a;
	int32_t b;
};

ostream& operator<<(ostream& os, const Edege& e)
{
	os<<"("<<e.a<<","<<e.b<<")";
	return os;
}

class Box
{
public:
	Box()
	{
		edeges_.reserve(6);
	}

	void AddEdege(Edege e)
	{
		edeges_.push_back(e);
	}

	bool Check()
	{
		std::sort(edeges_.begin(), edeges_.end());

//		for(auto& e: edeges_)
//		{
//			cout<<e;
//		}
//		cout<<"\n";

		return edeges_.size() == 6 &&
				edeges_[0] == edeges_[1] &&
				edeges_[2] == edeges_[3] &&
				edeges_[4] == edeges_[5] &&
				(   (edeges_[0].a == edeges_[4].a && edeges_[0].b == edeges_[2].a && edeges_[2].b == edeges_[4].b) ||
					(edeges_[0].a == edeges_[2].a && edeges_[0].b == edeges_[4].a && edeges_[2].b == edeges_[4].b));
	}
private:
	vector<Edege> edeges_;
};

int main()
{
	int32_t a1, b1, a2, b2, a3, b3, a4, b4, a5, b5, a6, b6;
	while(cin>>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4>>a5>>b5>>a6>>b6)
	{
		Box box;
		box.AddEdege(Edege(a1, b1));
		box.AddEdege(Edege(a2, b2));
		box.AddEdege(Edege(a3, b3));
		box.AddEdege(Edege(a4, b4));
		box.AddEdege(Edege(a5, b5));
		box.AddEdege(Edege(a6, b6));
		cout<<(box.Check()?"POSSIBLE\n":"IMPOSSIBLE\n");
	}
	return 0;
}



