/*118.cpp
frank May 7, 2018
*/
#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

struct Position
{
	int x;
	int y;
	char d; // direction
};

class Grid
{
	static const int MAX_GRID_SIZE = 50 + 1;
public:
	Grid(int w, int h):width_(w), height_(h) {}
	void Process(int x, int y, char d)
	{
		Position p {x, y, d};
		string line;
		cin>>line;
		// cout<<line<<"\n";
		for(char c : line)
		{
			Position newp = Run(p, c);

			// cout<<"("<<p.x<<", "<<p.y<<", "<<p.d<<") + "<<c<<" ==> ("<<newp.x<<", "<<newp.y<<", "<<newp.d<<")\n";

			if(newp.x < 0 || newp.x > width_ || newp.y < 0 || newp.y > height_)
			{
				if(! grid_[p.x][p.y])
				{
					grid_[p.x][p.y] = true;
					cout<<p.x<<" "<<p.y<<" "<<p.d<<" LOST\n";
					return;
				}
				else // ignore
				{
					continue;
				}
			}

			p = newp;
		}
		cout<<p.x<<" "<<p.y<<" "<<p.d<<"\n";
	}
private:
	Position Run(const Position& p, char direction)
	{
		Position result = p;

		static std::map<char, std::map<char, std::function<void(Position& p)>>> char_map = {
				{'E', { {'L', [](Position& p){ p.d = 'N'; } },
					    {'R', [](Position& p){ p.d = 'S'; } },
					    {'F', [](Position& p){ ++p.x; } } } },
				{'S', { {'L', [](Position& p){ p.d = 'E'; } },
					    {'R', [](Position& p){ p.d = 'W'; } },
					    {'F', [](Position& p){ --p.y; } } } },
				{'W', { {'L', [](Position& p){ p.d = 'S'; } },
						{'R', [](Position& p){ p.d = 'N'; } },
						{'F', [](Position& p){ --p.x; } } } },
				{'N', { {'L', [](Position& p){ p.d = 'W'; } },
						{'R', [](Position& p){ p.d = 'E'; } },
						{'F', [](Position& p){ ++p.y; } } } },
				};

		char_map[p.d][direction](result);

		return result;
	}

private:
	const int width_;
	const int height_;
	bool grid_[MAX_GRID_SIZE][MAX_GRID_SIZE] = {}; // 曾经跑出范围的位置(只用记录位置不用记录方向)，要记下来，后面在相同位置碰如果执行F超出范围时需要
};

int main()
{
	int w, h;
	cin>>w>>h;
	Grid g(w, h);
	int x, y;
	char d;
	while(cin>>x>>y>>d)
	{
		// cout<<x<<y<<d<<"\n";
		g.Process(x, y, d);
	}
	return 0;
}

