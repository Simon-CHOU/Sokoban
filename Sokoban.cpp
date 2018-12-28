// CodeM.cpp: 定义控制台应用程序的入口点。
//
//Sokoban
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;
struct Point
{
	int x = 0;
	int y = 0;
	Point(int x, int y) : x(x), y(y){}; //初始化列表
};
//边界为0，边界外为-1
//内部空位为1
//内部目标点为2 *
//箱子位置为3  O
//主角位置为4
const int ROW = 9;  //行数
const int COL = 11; //列数
int Board[ROW][COL] = {
	{-1, -1, -1, 0, 0, 0, -1, -1, -1, -1, -1},
	{-1, -1, -1, 0, 2, 0, -1, -1, -1, -1, -1},
	{-1, -1, -1, 0, 1, 0, -1, -1, -1, -1, -1},
	{0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0},
	{0, 2, 1, 1, 3, 4, 1, 3, 1, 2, 0},
	{0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
	{-1, -1, -1, -1, 0, 1, 0, -1, -1, -1, -1},
	{-1, -1, -1, -1, 0, 2, 0, -1, -1, -1, -1},
	{-1, -1, -1, -1, 0, 0, 0, -1, -1, -1, -1}};
//位置记录；
Point dst1(1, 2);
//地图数字转换为字符
char Trans(int x)
{
	switch (x)
	{
	case -1:
		return ' ';
		break;
	case 0:
		return '#';
		break;
	case 1:
		return ' ';
		break;
	case 2:
		return '*';
		break;
	case 3:
		return 'O';
		break;
	case 4:
		return 'S';
		break;
	default:
		cout << "Map has unusual keys." << endl;
		break;
	}
}
//刷新一次棋盘
void Refresh()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
			cout << Trans(Board[i][j]);
		cout << endl;
	}
}
int main()
{

	Refresh();
	return 0;
}