/*
 * 11988.cpp
 *
 *	uva 11988 - Broken Keyboard (a.k.a. Beiju Text)
 *
 *  Created on: Mar 14, 2015
 *      Author: frank
 */

/*
 * 一个字符一个字符地读取然后碰到\n就输出，结果WA；
 * 读取一行再处理就能正确。难道是因为输入是windows的格式，含有\r的原因？
 * 不管了。
 */

#include <iostream>
#include <list>
#include <stdio.h>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	string line;
	while(std::getline(cin, line))
	{
		std::list<char> result;
		std::list<char>::iterator it = result.begin();
		for(char c: line)
		{
			if(c == '[')
			{
				it = result.begin();
			}
			else if(c == ']')
			{
				it = result.end();
			}
			else
			{
				it = result.insert(it, c);
				++it;
			}
		}

		for(char c: result)
		{
			putchar(c);
		}
		putchar('\n');
	}

	return 0;
}

