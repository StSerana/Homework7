#pragma once
class SLList
{
	private:
		SLList();
		SLList(int data);
	public:
		SLList* m_nextElem;
		int m_data = 0;
		void setData(int data);
		SLList* next();
		bool hasNext();
		static SLList* beginList(int data);
		SLList* addElement(int data);
		void removeNext();
};
