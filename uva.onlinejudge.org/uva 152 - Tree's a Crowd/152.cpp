#include <iostream>
#include <vector>
#include <stdint.h>
#include <cmath>
#include <iomanip>

using namespace std;

int32_t Distance(int32_t x1, int32_t y1, int32_t z1,
		int32_t x2, int32_t y2, int32_t z2)
{
	double d = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
	return int32_t(floor(d));
}

struct Point
{
	int32_t x, y, z;
};

int32_t Distance(const Point& p1, const Point& p2)
{
	return Distance(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	std::vector<Point> points;
	points.reserve(5001);
	int32_t x, y, z;
	while(cin>>x>>y>>z)
	{
		if(x == 0 && y == 0 && z == 0)
			break;

		//cout<<x<<"|"<<y<<"|"<<z<<"\n";

		points.emplace_back(Point{x, y, z});
	}

	int32_t distance[10] = {0};
	for(size_t i = 0; i < points.size(); ++i)
	{
		int32_t min_d = 11;
		for(size_t j = 0; j < points.size(); ++j)
		{
			if(i == j)
				continue;

			int32_t d = Distance(points[i], points[j]);
			if(d < min_d)
			{
				min_d = d;
			}
		}

		if(min_d < 10)
		{
			++ distance[min_d];
		}
	}

	for(auto c: distance)
	{
		std::cout << std::right << std::setw(4) << c;
	}
	cout<<"\n";
	return 0;
}
