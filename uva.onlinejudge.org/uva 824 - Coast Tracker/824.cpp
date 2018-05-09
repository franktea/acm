/*
824.cpp
frank May 9, 2018
*/
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

class Direction
{
public:
	explicit Direction(int v): value_(v) {}

	Direction& operator++()
	{
		++ value_;
		if(value_ >= 8)
		{
			value_ = 0;
		}
		return *this;
	}

	operator int() const
	{
		return value_;
	}

	bool operator ==(const Direction& another) const
	{
		return value_ == another.value_;
	}

	std::pair<int, int> NextItem(const std::pair<int, int>& p)
	{
		static const std::pair<int, int> delta[] = { {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1} };
		return {delta[value_].first + p.first, delta[value_].second + p.second};
	}

	Direction ScanDirection() const
	{
		static const int new_direction[] = {7, 7, 1, 1, 3, 3, 5, 5};
		return Direction(new_direction[value_]);
	}
private:
	int value_;
};

class Grids
{
public:
	Grids(int x, int y, int d): center_({x, y}), direction_(d) {}
	void AddPoint(int x, int y, int v)
	{
		surrounding_[{x, y}] = v;
	}

	void Solve()
	{
		Direction d = direction_.ScanDirection();
		for(int i = 0; i < 8; ++i, ++d)
		{
			std::pair<int, int> p = d.NextItem(center_);
			if(surrounding_[p])
			{
				cout<<int(d)<<"\n";
				return;
			}
		}
	}
private:
	const std::pair<int, int> center_;
	const Direction direction_;
	std::map<std::pair<int, int>, int> surrounding_;
};

void split(const std::string& str, const std::string& delimiters,
    std::vector<std::string>& tokens)
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}

int main()
{
	string line;
	while(std::getline(cin, line))
	{
		if(line.empty() || line == "-1")
			break;

		vector<string> v1;
		split(line, " ", v1);
		assert(v1.size() == 3);
		Grids g(stoi(v1[0]), stoi(v1[1]), stoi(v1[2]));
		for(int i = 0; i < 8; ++i)
		{
			string line2;
			std::getline(cin, line2);
			vector<string> v2;
			split(line2, " ", v2);
			assert(v2.size() == 3);
			g.AddPoint(stoi(v2[0]), stoi(v2[1]), stoi(v2[2]));
		}
		g.Solve();
	}

	return 0;
}
