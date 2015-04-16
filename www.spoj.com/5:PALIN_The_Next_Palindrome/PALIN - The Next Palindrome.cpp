#include <iostream>
#include <string>
#include <algorithm>
#include <stdint.h>
#include <assert.h>

using namespace std;

bool IsPalindrome(const string& s)
{
	for(size_t i = 0; i <= s.size()/2; ++i)
	{
		if(s[i] != s[s.size() - 1 - i])
			return false;
	}
	return true;
}

void Inc(string& s, size_t pos)
{
	if(pos >= s.size()) return;

	while(1)
	{
		int32_t val = s[pos] - '0';
		++ val;
		s[pos] = (val % 10) + '0';
		if(val < 10) 
			return;
		
		// val >= 10
		if(pos > 0) 
			--pos;
		else
			break;
	}
	s.insert(0, "1");
}

void TestInc()
{
	string str = "123456";
	Inc(str, str.length() - 1);
	assert(str == "123457");
	str = "123499";
	Inc(str, str.length() - 1);
	assert(str == "123500");
	str = "999321";
	Inc(str, 2);
	assert(str == "1000321");
	str = "999999";
	Inc(str, str.length() - 1);
	assert(str == "1000000");
}

// 从中位开始，是否有连续的左边的每一位都大于等于右边的对称位置的每一位，并且至少有一位大于右边的
// 这种情况直接翻转即可
bool LeftGreater(const string& line)
{
	for(int32_t i = line.length()/2 - 1; i >= 0; --i)
	{
		if(line[i] > line[line.length()-1-i])
			return true;
		if(line[i] < line[line.length()-1-i])
			return false;
	}
	return false;
}

void FindNext(string& line)
{
	if(! LeftGreater(line))
	{
		size_t pos = (line.length() % 2) ? line.length() / 2 : line.length()/2 - 1;
		Inc(line, pos);
	}

	for(size_t i = 0; i <= line.length()/2 - 1; ++i)
	{
		line[line.length()-1-i] = line[i];
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
//	TestInc();
//	cout<<"test done\n";
	int32_t lines;
	cin>>lines;
	string line;
	while(lines --)
	{
		cin>>line;
		if(IsPalindrome(line))
			Inc(line, line.length() - 1);
		if(! IsPalindrome(line))
			FindNext(line);
		cout<<line<<"\n";
	}

	return 0;
}
