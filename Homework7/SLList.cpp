#include "SLList.h"
#include <iostream>
#include <ctime>
using namespace std;

SLList::SLList() {

}
SLList::SLList(int data)
{
	setData(data);
	m_nextElem = nullptr;
}

void SLList::setData(int data)
{
	m_data = data;
}

SLList* SLList::next()
{
	return m_nextElem;
}

bool SLList::hasNext()
{
	return m_nextElem != nullptr;
}

SLList* SLList::beginList(int data)
{
	SLList *p = new SLList(data);
	return p;
}

SLList* SLList::addElement(int data)
{
	SLList *temp = new SLList();
	SLList* reg = this;
	while (reg->m_nextElem != nullptr) 
	{
		reg = reg->next();
	}
	temp->m_data = data;
	temp->m_nextElem = nullptr;
	reg->m_nextElem = temp;
	return(temp);
}

void SLList::removeNext()
{
	if (m_nextElem->hasNext()) {
		m_nextElem->removeNext();
	}
	delete(m_nextElem);
}

void printSLList(SLList* list) {
	do {
		cout << list->m_data << " "; // вывод значения элемента p
		list = list->m_nextElem; // переход к следующему узлу
	} while (list->m_nextElem != nullptr);
}
