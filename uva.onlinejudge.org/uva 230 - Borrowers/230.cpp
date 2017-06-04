/*
 * 230.cpp
 *
 *  Created on: Jun 4, 2017
 *      Author: frank
 */
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <list>
#include <limits>

using namespace std;

class Book
{
	friend class BookList;
public:
	Book(const string& line):borrowed_(false)
	{
		Parse(line);
	}

	void Print() const
	{
		cout<<"book:("<<name_<<", "<<authur_<<")"<<endl;
	}
private:
	void Parse(const string& line)
	{
		size_t name_start_pos = line.find('"');
		size_t name_end_pos = line.find('"', name_start_pos+1);
		name_ = string(line, name_start_pos, name_end_pos - name_start_pos + 1);
		size_t by_pos = line.find("by ", name_end_pos + 1);
		size_t orthur_start_pos = by_pos + 3;
		authur_ = string(line, orthur_start_pos);
	}
private:
	bool borrowed_;
	string name_;
	string authur_;
};

class BookList
{
public:
	void AddBook(const string& line)
	{
		vb_.emplace_back(line);
		//vb_[vb_.size()-1].Print();
	}

	void FinishAdding() // sort
	{
		std::sort(vb_.begin(), vb_.end(), [](const Book& lhs, const Book& rhs)
				{
					if(lhs.authur_ != rhs.authur_)
						return lhs.authur_ < rhs.authur_;
					return lhs.name_ < rhs.name_;
				});

//		cout<<"sorted:"<<endl;
//		for(const auto& book: vb_)
//		{
//			book.Print();
//		}
	}

	void BorrowBook(const string& name)
	{
//		cout<<"borrowing: "<<name<<endl;
		FindBookToBorrow(name);
	}

	void ReturnBook(const string& name)
	{
//		cout<<"returning: "<<name<<endl;
		auto it = borrowed_books_.find(name);
		if(it == borrowed_books_.end())
			abort();
		size_t index = it->second;

		returned_books_.push_back(std::make_pair(index, name));
		borrowed_books_.erase(it);
	}

	void Shelve()
	{
		std::sort(returned_books_.begin(), returned_books_.end(),
				[](const std::pair<size_t, string>& lhs, const std::pair<size_t, string>& rhs)
				{
					return lhs.first < rhs.first;
				});

		auto find_prior = [this](const size_t index)->string
		{
			string&& result = "first";
			for(size_t i = 0; i < index; ++i)
			{
				if(!vb_[i].borrowed_)
				{
					result = string("after ") + vb_[i].name_;
				}
			}

			return result;
		};

		for(auto& p: returned_books_)
		{
			cout<<"Put "<<p.second<<" "<<find_prior(p.first)<<"\n";
			vb_[p.first].borrowed_ = false;
		}

		cout<<"END\n";
		returned_books_.clear();
	}
private:
	// find the book index
	void FindBookToBorrow(const string& book_name)
	{
		for(size_t index = 0; index < vb_.size(); ++index)
		{
			if(vb_[index].name_ == book_name)
			{
				vb_[index].borrowed_ = true;
				borrowed_books_.insert(std::make_pair(book_name, index));
				return;
			}
		}
	}
private:
	vector<Book> vb_;
	std::map<string, size_t> borrowed_books_;
	std::vector<std::pair<size_t, string>> returned_books_;
};

int main()
{
	BookList bl;

	string line;
	// read books
	std::getline(cin, line);
	while(line != "END")
	{
		bl.AddBook(line);
		std::getline(cin, line);
	}
	bl.FinishAdding();

	// read borrow or return actions
	std::getline(cin, line);
	while(line != "END")
	{
		if(line.find("BORROW") == 0)
		{
			bl.BorrowBook(string(line, line.find('"')));
		}
		else if(line.find("RETURN") == 0)
		{
			bl.ReturnBook(string(line, line.find('"')));
		}
		else // shelf
		{
			bl.Shelve();
		}
		std::getline(cin, line);
	}

	return 0;
}


