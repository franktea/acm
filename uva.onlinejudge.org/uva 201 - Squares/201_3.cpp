/*
 * 201_3.cpp
 *
 * uva 201 Squares
 *  Created on: Feb 24, 2015
 *      Author: frank
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

/**
 * 既不用iostream，也不用c＋＋的类（因为暂时还没搞清楚编译器的O2到底会内联哪些东西），
 * 再来测试O(n**3)的方法，发现对于本题的测试数据，确实比O(n**4)的算法速度相差无几。
 */

const int32_t MAX_DOT_COUNT = 10; // 2 <= n <= 9

int main()
{
	int32_t H[MAX_DOT_COUNT][MAX_DOT_COUNT][MAX_DOT_COUNT];
	int32_t V[MAX_DOT_COUNT][MAX_DOT_COUNT][MAX_DOT_COUNT];
	int32_t dot_count;
	int32_t prob_count = 0;
	while(~scanf("%d", &dot_count))
	{
		getchar();
		bzero(H, sizeof(H));
		bzero(V, sizeof(V));
		++ prob_count;
		if(prob_count > 1) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n", prob_count);
		int32_t lines;
		scanf("%d", &lines); getchar();
		while(lines--)
		{
			char type; int32_t x, y;
			scanf("%c %d %d", &type, &x, &y); getchar();
			if(type == 'H') H[x][y][y+1] = 1;
			else V[x][y][y+1] = 1;
		}

		bool has_squres = false; // 是否至少有一个正方形，没有要输出一句话
		for(int32_t s = 1; s <= dot_count - 1; ++s) // 需要查找的正方形的边长
		{
			int32_t s_count = 0; // 边长为s的正方形累计个数
			for(int32_t i = 1; i <= dot_count - s; ++i) // 第i行
			{
				for(int32_t j = 1; j <= dot_count - s; ++j) // 第j列
				{
					// 要查看点(i, j)与(i+s, j+s)外层的四边是否连通
					// 只要看点(i, j)与(i+s-1, j+s-1)、并且(i+s-1, j+s-1)与(i+s, j+s)是否连通即可
					if(i+s > dot_count || j+s > dot_count)
						continue;

					if(s > 1)
					{
						H[i][j][j+s] = H[i][j][j+s-1] && H[i][j+s-1][j+s];
						V[j][i][i+s] = V[j][i][i+s-1] && V[j][i+s-1][i+s];
						H[i+s][j][j+s] = H[i+s][j][j+s-1] && H[i+s][j+s-1][j+s];
						V[j+s][i][i+s] = V[j+s][i][i+s-1] && V[j+s][i+s-1][i+s];
					}
					s_count += (H[i][j][j+s] && H[i+s][j][j+s] &&
						V[j][i][i+s] && V[j+s][i][i+s]);
				}
			}
			if(s_count > 0)
			{
				has_squres = true;
				printf("%d square (s) of size %d\n", s_count, s);
			}
		}

		if(! has_squres)
			printf("No completed squares can be found.\n");
	}

	return 0;
}




