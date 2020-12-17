#pragma once
class MCell
{
	private:
		bool m_down;
		bool m_right;
		MCell();
		
	public:
		bool right();
		bool down();

		friend class Maze;
};