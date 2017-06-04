/*
 * 232.cpp
 *
 *  Created on: Jun 4, 2017
 *      Author: frank
 */
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Cell
{
	friend class Matrix;
public:
	Cell(){}
	Cell(char c):value_(c){}
private:
	char value_ = 0;
	bool across_start_ = false;
	bool down_start_ = false;
	size_t start_index_ = 0;
};

class Matrix
{
public:
	Matrix(size_t rows, size_t cols):rows_(rows), cols_(cols)
	{
		matrix_.resize(rows*cols);
	}

	void AddRow(size_t row, const string& line)
	{
		//cout<<"adding row: "<<row<<", "<<line<<endl;
		for(size_t col = 0; col < line.size(); ++col)
		{
			Cell& cell = Get(row, col);
			cell.value_ = line[col];
		}
	}

	void CheckStart()
	{
		size_t current_start_index = 0;
		for(size_t r = 0; r < rows_; ++r)
		{
			for(size_t c = 0; c < cols_; ++c)
			{
				Cell& cell = Get(r, c);
				if(cell.value_ == '*')
					continue;
				cell.across_start_ = (c == 0) || (c != 0 && Get(r, c-1).value_ == '*');
				cell.down_start_ = (r == 0) || (r != 0 && Get(r-1, c).value_ == '*');
				if(cell.across_start_ || cell.down_start_)
				{
					cell.start_index_ = ++current_start_index;
				}
			}
		}
	}

	void OutPut()
	{
		cout<<"Across\n";
		for(size_t r = 0; r < rows_; ++r)
		{
			for(size_t c = 0; c < cols_; ++c)
			{
				Cell& cell = Get(r, c);
				if(cell.across_start_)
				{
					cout<<std::setw(3)<<std::setfill(' ')<<cell.start_index_<<".";
					for(size_t cc = c; cc < cols_; ++cc)
					{
						Cell& ccell = Get(r, cc);
						if(ccell.value_ == '*')
							break;
						cout<<ccell.value_;
					}
					cout<<"\n";
				}
			}
		}
		cout<<"Down\n";
		for(size_t r = 0; r < rows_; ++r)
		{
			for(size_t c = 0; c < cols_; ++c)
			{
				Cell& cell = Get(r, c);
				if(cell.down_start_)
				{
					cout<<std::setw(3)<<std::setfill(' ')<<cell.start_index_<<".";
					for(size_t rr = r; rr < rows_; ++rr)
					{
						Cell& ccell = Get(rr, c);
						if(ccell.value_ == '*')
							break;
						cout<<ccell.value_;
					}
					cout<<"\n";
				}
			}
		}
	}

	void Print()
	{
		cout<<rows_<<", "<<cols_<<";\n";
		for(size_t r = 0; r < rows_; ++r)
		{
			for(size_t c = 0; c < cols_; ++c)
			{
				cout<<Get(r, c).start_index_<<",";
			}
			cout<<"\n";
		}
	}
private:
	Cell& Get(size_t row, size_t col)
	{
		return matrix_[row*cols_ + col];
	}
private:
	vector<Cell> matrix_;
	const size_t rows_;
	const size_t cols_;
};

int main()
{
	size_t rows, cols;
	int case_index = 0;
	cin>>rows;
	while(0 != rows)
	{
		++ case_index;
		if(case_index > 1) cout<<"\n";
		cout<<"puzzle #"<<case_index<<":\n";
		cin>>cols;
		Matrix matrix(rows, cols);
		string line;
		for(size_t row = 0; row < rows; ++row)
		{
			cin>>line;
			matrix.AddRow(row, line);
		}
		matrix.CheckStart();
		matrix.OutPut();
		//matrix.Print();

		cin>>rows;
	}
	return 0;
}



