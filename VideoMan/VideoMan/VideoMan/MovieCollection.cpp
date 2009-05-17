#include "MovieCollection.h"

MovieCollection::MovieCollection()
{
	firstNode = 0;
	lastNode = 0;

}

void MovieCollection::insert(Movie* data)
{
	ListNode* p = new ListNode(data);

	if (firstNode == 0) //if we haven't got elements than this is our first
	{
		firstNode = p;
		lastNode = p;
	}
	else 
	{
		ListNode* _currNode;
		for (_currNode = firstNode; _currNode != 0; _currNode = _currNode->getNext())
		{
			if (_currNode->getData()->getTitle() < data->getTitle()) 
			{
				if (_currNode->getNext() == 0) 
				{
					p->insertAfter(_currNode);
					_currNode->setNext(p);
					lastNode = p;
					p->setPrevious(_currNode);
					//lastNode = lastNode->getNext();
				//	_currNode->setNext(p);
				} else if (_currNode->getNext()->getData()->getTitle() > data->getTitle())
				{
					p->insertAfter(_currNode);
					_currNode->setNext(p);
					p->setPrevious(_currNode);
				}

			}
		}
	}
	m_listCount++;
}

void MovieCollection::traverse()
{
	ListNode* _currNode = firstNode;
	for (_currNode = firstNode; _currNode != 0; _currNode = _currNode->getNext())
	{
		cout << _currNode->getData()->getTitle() << endl;
	}
}

void MovieCollection::traverse(string a_char)
{
	ListNode* _currNode = firstNode;
	for (_currNode = firstNode; _currNode != 0; _currNode = _currNode->getNext())
	{
		
		/*string tempstring(a_char.begin()
		if (a_char = _currNode->getData()->getTitle().
		{
			cout << _currNode->getData()->getTitle() << endl;
		{*/
	}
}


bool MovieCollection::search(Movie* data)
{
	ListNode* _currNode = firstNode;
	for (_currNode = firstNode; _currNode != 0; _currNode = _currNode->getNext())
	{
		if (_currNode->getData()->getTitle() == data->getTitle())
		{
			return 1;
		}
	}

	return 0;
}

bool MovieCollection::search(string data)
{
	ListNode* _currNode = firstNode;
	for (_currNode = firstNode; _currNode != 0; _currNode = _currNode->getNext())
	{
		if (_currNode->getData()->getTitle() == data)
		{
			return 1;
		}
	}

	return 0;
}

Movie* MovieCollection::getMovie(string a_name)
{
	ListNode* _currNode = firstNode;
	for (_currNode = firstNode; _currNode != 0; _currNode = _currNode->getNext())
	{
		if (_currNode->getData()->getTitle() == a_name)
		{
			return _currNode->getData();
		}
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

bool MovieCollection::remove(Movie* data)
{
	ListNode* _currNode;
	ListNode* _deleteNode;
	bool _success = false;
	for (_currNode = firstNode; _currNode != 0; _currNode = _currNode->getNext())
	{
		if (_currNode->getData()->getTitle() == data->getTitle())
		{
			if (_currNode == firstNode)
			{
				firstNode = _currNode->getNext();
			} 
			else if (_currNode == lastNode)
			{
				lastNode = _currNode->getPrevious();
			}
			else
			{
				//since we have a doubly linked list, properly detatch our node
				_currNode->getNext()->setPrevious(_currNode->getPrevious());
				_currNode->getPrevious()->setNext(_currNode->getNext());
			}

			//create a temp variable as to not cause error with our for loop
			_deleteNode = _currNode;
			_currNode = _currNode->getPrevious();

			delete _deleteNode;
			_success = 1;
		}
	}

	if (_success)
	{
		m_listCount--;
		return 1;
	}
	else
		return 0;

}

MovieCollection::~MovieCollection(void)
{
	clear();
}


