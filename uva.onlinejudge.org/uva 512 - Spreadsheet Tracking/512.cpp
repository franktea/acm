/*
 * 512.cpp
 *
 *  Created on: Jun 23, 2018
 *      Author: frank
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Matrix
{
public:
	Matrix(int r, int c, int index): rows_(r), cols_(c), case_index_(index)
	{
		data_.resize(rows_ + 1);
		for(int i = 0; i < rows_ + 1; ++i)
		{
			data_[i].resize(cols_ + 1);
		}

		for(int i = 0; i <= rows_; ++i)
		{
			for(int j = 0; j <= cols_; ++j)
			{
				data_[i][j] = {i, j};
			}
		}
	}

	void Print()
	{
		for(int i = 0; i < static_cast<int>(data_.size()); ++i)
		{
			for(int j = 0; j < static_cast<int>(data_[0].size()); ++j)
			{
				auto p = data_[i][j];
				cout<<"("<<p.first<<","<<p.second<<") ";
			}
			cout<<"\n";
		}
	}

	void DeleteRow(int r)
	{
		data_.erase(data_.begin() + r);
	}

	void DeleteCol(int c)
	{
		for(int i = 0; i < static_cast<int>(data_.size()); ++i)
		{
			data_[i].erase(data_[i].begin() + c);
		}
	}

	void InsertRow(int r)
	{
		const int cols = data_[0].size();
		data_.insert(data_.begin() + r, vector<std::pair<int, int>>(cols, {0, 0}));
	}

	void InsertCol(int c)
	{
		for(int i = 0; i < static_cast<int>(data_.size()); ++i)
		{
			data_[i].insert(data_[i].begin() + c, {0, 0});
		}
	}

	void Exchange(int r1, int c1, int r2, int c2)
	{
		auto& cell1 = data_[r1][c1];
		auto& cell2 = data_[r2][c2];
		std::swap(cell1, cell2);
	}

	void EndEdit() // finished editing, prepare for query
	{
		const std::pair<int, int> zero_pair = {0, 0};
		for(int i = 0; i < static_cast<int>(data_.size()); ++i)
		{
			for(int j = 0; j < static_cast<int>(data_[0].size()); ++j)
			{
				if(data_[i][j] != zero_pair)
				{
					positions_.insert(std::make_pair(data_[i][j], std::make_pair(i, j)));
					//cout<<"::::::::"<<data_[i][j].first<<","<<data_[i][j].second<<"|"<<i<<","<<j<<"\n";
				}
			}
		}
		if(case_index_ > 1)
		{
			cout<<"\n";
		}
		std::cout<<"Spreadsheet #"<<case_index_<<"\n";
	}

	void Query(int r, int c)
	{
		cout<<"Cell data in ("<<r<<","<<c<<") ";
		auto it = positions_.find(std::make_pair(r, c));
		if(it == positions_.end())
		{
			cout<<"GONE\n";
		}
		else
		{
			cout<<"moved to ("<<it->second.first<<","<<it->second.second<<")\n";
		}
	}
private:
	const int case_index_; // Spreadsheet #1,2...
	const int rows_; // init rows and cols, maybe changed
	const int cols_;
	vector<vector<std::pair<int, int>>> data_;
	map<std::pair<int, int>, std::pair<int, int>> positions_;
};

void split(const std::string& str, const std::string& delimiters,
    std::vector<std::string>& tokens)
{
	tokens.clear();
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
	int index = 0;
	std::string line;
	while(std::getline(cin, line))
	{
		if(line == "")
		{
			continue;
		}

		std::vector<string> vec;
		split(line, " ", vec);
		int rows = stoi(vec[0]);
		int cols = stoi(vec[1]);

		if(rows == 0 && cols == 0)
		{
			break;
		}

		Matrix m(rows, cols, ++index);
		//m.Print();
		std::getline(cin, line);
		int cmds = stoi(line);
		for(int i = 0; i < cmds; ++i)
		{
			std::getline(cin, line);
			split(line, " ", vec);
			if(vec[0] == "DR")
			{
				vector<int> vec2;
				for(int x = 2; x < int(vec.size()); ++x)
				{
					vec2.push_back(stoi(vec[x]));
				}
				sort(vec2.begin(), vec2.end(), std::greater<int>());
				for(auto x: vec2)
				{
					m.DeleteRow(x);
				}
			}
			else if(vec[0] == "DC")
			{
				vector<int> vec2;
				for(int x = 2; x < int(vec.size()); ++x)
				{
					vec2.push_back(stoi(vec[x]));
				}
				sort(vec2.begin(), vec2.end(), std::greater<int>());
				for(auto x: vec2)
				{
					m.DeleteCol(x);
				}
			}
			else if(vec[0] == "IR")
			{
				vector<int> vec2;
				for(int x = 2; x < int(vec.size()); ++x)
				{
					vec2.push_back(stoi(vec[x]));
				}
				sort(vec2.begin(), vec2.end(), std::greater<int>());
				for(auto x: vec2)
				{
					m.InsertRow(x);
				}
			}
			else if(vec[0] == "IC")
			{
				vector<int> vec2;
				for(int x = 2; x < int(vec.size()); ++x)
				{
					vec2.push_back(stoi(vec[x]));
				}
				sort(vec2.begin(), vec2.end(), std::greater<int>());
				for(auto x: vec2)
				{
					m.InsertCol(x);
				}
			}
			else if(vec[0] == "EX")
			{
				m.Exchange(stoi(vec[1]), stoi(vec[2]), stoi(vec[3]), stoi(vec[4]));
			}

			//cout<<"---------\n";
			//m.Print();
		}
		m.EndEdit();
		std::getline(cin, line);
		int querys = stoi(line);
		for(int i = 0; i < querys; ++i)
		{
			std::getline(cin, line);
			split(line, " ", vec);
			m.Query(stoi(vec[0]), stoi(vec[1]));
		}
	}
}

