#include "MovieCollection.h"

MovieCollection::MovieCollection()
{
	firstNode = 0;
	lastNode = 0;
	
}

void MovieCollection::insert(const Movie data)
{
	ListNode* p = new ListNode(data);

	if (firstNode == 0) //if we haven't got elements than this is our first
	{
		firstNode = p;
		lastNode = p;
	}
	else 
	{
		p->insertAfter(lastNode);
		lastNode = lastNode->getNext();
	}
	m_listCount++;
}

bool MovieCollection::search(Movie data)
{
	ListNode* current = firstNode;

	while ((current != lastNode) || (current != NULL))
	{

		if (current->getData().getTitle() == data.getTitle())
		{
			return 1;
		}
		current = current->getNext();
	}
	return 0;
}

void MovieCollection::clear()
{
	while (firstNode != 0)
    {
          ListNode *t = firstNode;
		  firstNode = firstNode->getNext();
          delete t;
    }

}

int MovieCollection::remove()
{
	return 1;
}

MovieCollection::~MovieCollection(void)
{
	clear();
}
