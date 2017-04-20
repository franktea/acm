/*
 * 10550.cpp
 *
 *  Created on: Apr 20, 2017
 *      Author: frank
 */
#include <iostream>
#include <stdint.h>
using namespace std;

class Clock
{
public:
	Clock(int32_t init, int32_t a, int32_t b, int32_t c): init(init), a(a), b(b), c(c) {}

	void Solve()
	{
		int32_t result = 3*360;
		int32_t ar = init - a;
		if(ar < 0) ar = 40 + ar;
		int32_t br = b - a;
		if(br < 0) br = 40 + br;
		int32_t cr = b - c;
		if(cr < 0) cr = cr + 40;
		result += (ar + br + cr)*9;
		cout<<result<<"\n";
	}
private:
	int32_t init;
	int32_t a;
	int32_t b;
	int32_t c;
};

int main()
{
	int32_t i, a, b, c;
	while(cin>>i>>a>>b>>c)
	{
		if(!i && !a && !b && !c)
			break;

		Clock cl(i, a, b, c);
		cl.Solve();
	}
	return 0;
}



