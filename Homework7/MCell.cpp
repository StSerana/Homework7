#include "MCell.h"

MCell::MCell() {
	m_down = false;
	m_right = false;
}
bool MCell::right() { return m_right; }
bool MCell::down() { return m_down; }
