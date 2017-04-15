/*
 * 10344.cpp
 *  uva 10344 - 23 out of 5
 *  Created on: Apr 15, 2017
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdint.h>
using namespace std;

class Expression
{
public:
	Expression(int32_t a, int32_t b, int32_t c, int32_t d, int32_t e)
	{
		v = {a, b, c, d, e};
		sort(v.begin(), v.end());

		operators = {'+', '-', '*'};
		last_operators.resize(4);
	}

	bool Check()
	{
		int32_t result = v[0];
		for(int32_t i = 0; i < 4; ++i)
		{
			switch(last_operators[i])
			{
			case '+':
				result += v[i+1];
				break;
			case '-':
				result -= v[i+1];
				break;
			case '*':
				result *= v[i+1];
				break;
			}
		}
		return result == 23;
	}

	void Solve()
	{
		do {
			for(int32_t i = 0; i < 3; ++i)
				for(int32_t j = 0; j < 3; ++j)
					for(int32_t k = 0; k < 3; ++k)
						for(int32_t l = 0; l < 3; ++l)
						{
							last_operators[0] = operators[i];
							last_operators[1] = operators[j];
							last_operators[2] = operators[k];
							last_operators[3] = operators[l];
							if(Check())
							{
								cout<<"Possible\n";
								return;
							}
						}
		} while(next_permutation(v.begin(), v.end()));
		cout<<"Impossible\n";
	}
private:
	vector<int32_t> v;
	vector<char> operators;
	vector<char> last_operators;
};

int main()
{
	int32_t a, b, c, d, e;
	while(cin>>a>>b>>c>>d>>e)
	{
		if(!a && !b && !c && !d && !e)
			break;

		Expression exp(a, b, c, d, e);
		exp.Solve();
	}
	return 0;
}



