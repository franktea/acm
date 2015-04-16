/*
 * 705.cpp
 *
 *	uva 705 - Slash Maze
 *
 *  Created on: Mar 14, 2015
 *      Author: frank
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <stdint.h>

using namespace std;

/**
 * 每个格子被分成四个小块，每个小块最多只有2个通路：
 * 1：同一个大格子中间相邻的小格子；
 * 2：相邻大格子的某个小格子。
 * 相当于是遍历二叉树一样。
 */

class Graph
{
public:
	Graph(int32_t row_count, int32_t col_count) :
		ROW_COUNT(row_count), COL_COUNT(col_count)
	{
		nodes_.resize(ROW_COUNT*COL_COUNT);
	}

	struct Node
	{
		char value; // 为'/'或者‘\'
		uint8_t visited[4]; // 每个节点分解成四个节点，从左上角顺时针方向编号为0、1、2、3
	};

	struct Piece
	{
		int32_t row;
		int32_t col;
		int32_t piece;
	};

	Node& GetNode(int32_t row, int32_t col)
	{
		return nodes_[COL_COUNT*row + col];
	}

	void FindCircle()
	{
		int32_t count = 0;
		int32_t max_length = 0;
		for(int32_t row = 0; row < ROW_COUNT; ++row)
		{
			for(int32_t col = 0; col < COL_COUNT; ++col)
			{
				for(int32_t i = 0; i < 4; ++i)
				{
					if(! GetNode(row, col).visited[i])
					{
						int32_t total = 0;
						int32_t inner = 0;
						DFS(row, col, i, total, inner);
						if(total == inner)
						{
							++count;
							max_length = std::max(max_length, total);
						}
					}
				}
			}
		}

		if(0 == count)
		{
			cout<<"There are no cycles.\n\n";
		}
		else
		{
			cout<<count<<" Cycles; the longest has length "<<max_length/2<<".\n\n";
		}
	}

	void Print()
	{
		for(int32_t r = 0; r < ROW_COUNT; ++r)
		{
			for(int32_t c = 0; c < COL_COUNT; ++c)
			{
				cout<<GetNode(r, c).value;
			}
			cout<<"\n";
		}

		for(int32_t r = 0; r < ROW_COUNT; ++r)
		{
			for(int32_t c = 0; c < COL_COUNT; ++c)
			{
				cout<<"(";
				for(int32_t i = 0; i < 4; ++i)
				{
					cout<<int32_t(GetNode(r,c).visited[i]);
					if(i < 3)
						cout<<",";
				}
				cout<<")";
			}
			cout<<"\n";
		}
	}
private:
	bool NearPiece(const Piece piece, Piece& next_piece)
	{
		next_piece = piece;
		Node& node = GetNode(piece.row, piece.col);
		if(node.value == '/')
		{
			static const int32_t NEXT_NEAR_PIECE[4] = {3, 2, 1, 0};
			next_piece.piece = NEXT_NEAR_PIECE[piece.piece];
		}
		else // node.value == '\'
		{
			static const int32_t NEXT_NEAR_PIECE[4] = {1, 0, 3, 2};
			next_piece.piece = NEXT_NEAR_PIECE[piece.piece];
		}

		return node.visited[next_piece.piece] == 0;
	}

	bool NeighbourPiece(const Piece piece, Piece& next_piece)
	{
		static const std::vector<Piece> neighbour = { {-1, 0, 2},
				{0, 1, 3},
				{1, 0, 0},
				{0, -1, 1} };
		const int32_t next_row = neighbour[piece.piece].row + piece.row;
		const int32_t next_col = neighbour[piece.piece].col + piece.col;
		const int32_t next_piece_index = neighbour[piece.piece].piece;
		if(next_row < 0 || next_row >= ROW_COUNT || next_col < 0 || next_col >= COL_COUNT)
		{
			return false;
		}

		next_piece = {next_row, next_col, next_piece_index};
		return GetNode(next_row, next_col).visited[next_piece_index] == 0;
	}

	/**
	 * dfs，参数total，返回本次遍历的节点数目（指的是每个大节点的四个小节点）；
	 * 参数inner，返回那些非边界节点的数目。如果total＝＝count，
	 * 就表示这次遍历的是一个封闭的区域。
	 *
	 * 参数piece_index为[0,3],表示为第几个小节点
	 */
	void DFS(const int32_t row, const int32_t col, const int32_t piece_index,
			int32_t& total, int32_t& inner)
	{
		GetNode(row, col).visited[piece_index] = 1;
		const Piece this_piece {row, col, piece_index};
		++total;
		if(piece_index == 0 && row > 0) ++inner;
		if(piece_index == 1 && col < COL_COUNT - 1) ++inner;
		if(piece_index == 2 && row < ROW_COUNT - 1) ++inner;
		if(piece_index == 3 && col > 0) ++inner;
		//cout<<"row="<<row<<", col="<<col<<", piece_index="<<piece_index<<", total="<<total<<", inner="<<inner<<"\n";

		Piece next_piece;
		if(NearPiece(this_piece, next_piece))
		{
			DFS(next_piece.row, next_piece.col, next_piece.piece, total, inner);
		}

		if(NeighbourPiece(this_piece, next_piece))
		{
			DFS(next_piece.row, next_piece.col, next_piece.piece, total, inner);
		}
	}
private:
	const int32_t ROW_COUNT;
	const int32_t COL_COUNT;
	vector<Node> nodes_;
};

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int32_t row, col;
	int32_t case_count = 0;
	while(cin>>col>>row)
	{
		if(row == 0 && col ==0) break;
		cout<<"Maze #"<<++case_count<<":\n";

		Graph graph(row, col);
		for(int r = 0; r < row; ++r)
		{
			for(int c = 0; c < col; ++c)
			{
				cin>>graph.GetNode(r, c).value;
			}
		}
		//graph.Print();
		graph.FindCircle();
	}

	return 0;
}


