#include <iostream>
#include "SLList.h"
#include <ctime>
using namespace std;

void printSLList(SLList* node);
void removeDuplicates(SLList* start);
SLList* getElem(SLList* list, int n);

int main()
{
	srand(time(0));
	SLList* sllist = SLList::beginList(rand() % 5 - 0);

	for (int i = 1; i < 10; i++) {
		sllist->addElement(rand() % 5 - 0);
	}
	printSLList(sllist);
    cout << endl << getElem(sllist, 6)->m_data << endl;
    removeDuplicates(sllist);
    printSLList(sllist);
	return 0;
}

void printSLList(SLList* node)
{
	while (node != nullptr)
	{
		cout << node->m_data<< " ";
		node = node->m_nextElem;
	}
}
void removeDuplicates(SLList* start)
{
    SLList* ptr1, * ptr2, * dup;
    ptr1 = start;

    /* Pick elements one by one */
    while (ptr1 != nullptr && ptr1->hasNext())
    {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->hasNext())
        {
            /* If duplicate then delete it */
            if (ptr1->m_data == ptr2->m_nextElem->m_data)
            {
                /* sequence of steps is important here */
                dup = ptr2->m_nextElem;
                ptr2->m_nextElem = ptr2->m_nextElem->m_nextElem;
                delete(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->m_nextElem;
        }
        ptr1 = ptr1->m_nextElem;
    }
}

SLList* getElem(SLList* list, int n) {
    SLList* temp = list;
    for (int i = 0; i < 10 - n; i++) {
        temp = temp->m_nextElem;
    }
    return temp;
}