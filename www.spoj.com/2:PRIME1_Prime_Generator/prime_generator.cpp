#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(unsigned long n) 
{
    if (n <= 3)
        return n > 1;
    else if (n % 2 == 0 || n % 3 == 0)
        return false;
    else 
    {
        for (unsigned short i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int case_count;
	cin>>case_count;
	for(int i = 0; i < case_count; ++i)
	{
		if(i > 0) cout<<"\n";
		int a, b;
		cin>>a>>b;
		for(int x = a; x <= b; ++x)
		{
			if(IsPrime(x))
				cout<<x<<"\n";
		}
	}
	return 0;
}
