/*
 * 272.c
 *
 * uva 272 - TEX Quotes
 *
 *  Created on: Feb 24, 2015
 *      Author: frank
 */

#include <stdio.h>

/**
 * 最简单的题用c＋＋的结果排名第1.8w，整了个c的一提交发现只快了3ms，
 * 后来发现用c的三元运算符会比之前的if..else快了30％，然后恍然大悟。
 */

int main()
{
	int c;
	int even = 1;
	while((c = getchar()) != EOF)
	{
		if(c == '"')
		{
			even = !even;
			printf("%s", even ? "''" : "``");
		}
		else putchar(c);
	}
	return 0;
}


