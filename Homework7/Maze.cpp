#include "Maze.h"
#include "MCell.h"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <map>
using namespace std;

std::map<int, char> Maze::symbols = { 
	{0, 176}, {1, '0'}, {4, '0'}, {5, 179},
	{2, '0'}, {8, '0'}, {10, 196}, {3, 192},
	{6, 218}, {12, 191}, {9, 217}, {7, 195},
	{14, 194}, {13, 180}, {11, 193}, {15, 197} };

Maze::Maze(int n, int m)
{
	srand(time(0));
	MCell* j = new MCell[n * m]();
	m_field = j;
	m_columns = n;
	m_rows = m;
	start[0] = rand() % n;
	start[1] = start[0] != 0 ? 0 : rand() % m;
}

Maze::~Maze()
{
	delete[] m_field;
}

int Maze::rows() const
{
	return m_rows;
}

int Maze::columns() const
{
	return m_columns;
}

int Maze::startX() const
{
	return start[0];
}

int Maze::startY() const
{
	return start[1];
}

const MCell& Maze::cell(int i, int j) const
{
	return m_field[i * m_rows + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	if (i1 < 0 || i1 > m_columns - 1 || i2 < 0 || i2 > m_columns - 1 ||
		j1 < 0 || j1 > m_rows - 1 || j2 < 0 || j2 >  m_rows - 1)
		return false;
	if (i1 == i2)
		return m_field[i1 * m_columns + std::min(j1, j2)].right();
	if (j1 == j2)
		return m_field[std::min(i1, i2) * m_rows + j1].down();
	return false;
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{

	if (i1 < 0 || i1 > m_columns - 1 || i2 < 0 || i2 > m_columns - 1 ||
		j1 < 0 || j1 > m_rows - 1 || j2 < 0 || j2 >  m_rows - 1)
		return false;
	if (i1 == i2)
	{
		m_field[i1 * 5 + std::min(j1, j2)].m_right = true;
		return true;
	}
		
	if (j1 == j2)
	{
		m_field[std::min(i1, i2) * 5 + j1].m_down = true;
		return true;
	}
		
	return false;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{

	if (i1 < 0 || i1 > m_columns - 1 || i2 < 0 || i2 > m_columns - 1 ||
		j1 < 0 || j1 > m_rows - 1 || j2 < 0 || j2 >  m_rows - 1)
		return false;
	if (i1 == i2)
		return !(m_field[i1 * 5 + std::min(j1, j2)].right());
	if (j1 == j2)
		return !(m_field[std::min(i1, i2) * 5 + j1].down());
	return false;
}

void Maze::printMaze()
{
	/* //Homework 8
	char down = 191;
	char right = 192;
	char zero = 248;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i * j == 16) {
				cout << right;
				continue;
			}
			if (hasConnection(i, j, i + 1, j)) {
				cout << down;
			}
			else if (hasConnection(i, j, i, j + 1)) {
				cout << right;
			}
			else {
				cout << zero;
			}
		}
		cout << endl;
	} 
	*/
	 //Homework 9
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			if (i == start[0] && j == start[1])
			{
				cout << 0;
				continue;
			}
			std::cout << symbols[(hasConnection(i, j, i - 1, j) ? 1 : 0) +
			(hasConnection(i, j, i, j - 1) ? 8 : 0) +
			(cell(i, j).m_right ? 2 : 0) +
			(cell(i, j).m_down ? 4 : 0)];
		}
		std::cout << std::endl;
	}
	
}
