#pragma once
class MCell
{
	private:
		bool m_down = false;
		bool m_right = false;
		MCell();
		friend class Maze;
	public:
		bool right();
		bool down();
};

