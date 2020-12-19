#include "Maze.h"
#include "MCell.h"
#include <algorithm>
#include <iostream>
using namespace std;

Maze::Maze() {

}
Maze::Maze(int n, int m)
{
	MCell* j = new MCell[n * m]();
	m_field = j;
	horizontal_size = n;
}

Maze::~Maze()
{
	delete(m_field);
}

const MCell& Maze::cell(int i, int j) const
{
	return m_field[i * horizontal_size + j];
}

bool Maze::hasConnection(int i1, int j1, int i2, int j2)
{
	const MCell* cell1 = &cell(i1, j1);
	const MCell* cell2 = &cell(i2, j2);
	int coord1 = i1 * horizontal_size + j1;
	int coord2 = i2 * horizontal_size + j2;
	if (min(coord1, coord2) == coord1) {
		if (i2 - i1 == 1)
			return cell1->m_right;
		if (j2 - j1 == 1)
			return cell1->m_down;
	}
	else {
		if (i1 - i2 == 1)
			return cell2->m_right;
		if (j1 - j2 == 1)
			return cell2->m_down;
	}
}

bool Maze::makeConnection(int i1, int j1, int i2, int j2)
{
	int coord1 = i1 * horizontal_size + j1;
	int coord2 = i2 * horizontal_size + j2;
	MCell* m = new MCell();
	if (i2 - i1 == 1) {
		m->m_right = true;
		m_field[coord1] = *m;
		return true;
	}
	if (j2 - j1 == 1) {
		m->m_down = true;
		m_field[coord1] = *m;
		return true;
	}
	if (i1 - i2 == 1) {
		m->m_right = true;
		m_field[coord2] = *m;
		return true;
	}
	if (j1 - j2 == 1) {
		m->m_down = true;
		m_field[coord2] = *m;
		return true;
	}
	return false;
}

bool Maze::removeConnection(int i1, int j1, int i2, int j2)
{
	if (hasConnection(i1, j1, i2, j2)) {
		int coord1 = i1 * horizontal_size + j1;
		int coord2 = i2 * horizontal_size + j2;
		MCell* m = new MCell();
		if (i2 - i1 == 1) {
			m->m_right = false;
			m_field[coord1] = *m;
		}
		if (j2 - j1 == 1) {
			m->m_down = false;
			m_field[coord1] = *m;
		}
		if (i1 - i2 == 1) {
			m->m_right = false;
			m_field[coord2] = *m;
		}
		if (j1 - j2 == 1) {
			m->m_down = false;
			m_field[coord2] = *m;
		}
		return true;
	}
	return false;
}

void Maze::printMaze()
{
	char ver = 179;
	char verch = 180;
	char down = 191;
	char right = 192;
	char up = 193;
	char dch = 194;
	char rightch = 195;
	char hor = 196;
	char plus = 197;
	char zero = 248;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
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
}
