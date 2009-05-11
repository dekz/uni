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
		p->insertAfter(lastNode);
		lastNode = lastNode->getNext();
	}
	m_listCount++;
}

bool MovieCollection::search(Movie* data)
{
	ListNode* _currNode = firstNode;
	while ((_currNode != lastNode) || (_currNode != 0))
	{
		if (_currNode->getData()->getTitle() == data->getTitle())
		{
			return 1;
		}
		_currNode = _currNode->getNext();
		if ((_currNode == lastNode) || (_currNode == 0))
		{
			break;
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
		cout << "looking in node: " << _currNode << endl;
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
				_currNode->getNext()->setPrevious(_currNode->getPrevious());
				cout << "My previous is: " << _currNode->getPrevious()->getData()->getTitle() << endl;
				_currNode->getPrevious()->setNext(_currNode->getNext());
			}
			cout << "deleting node: " << _currNode << endl;
			
			_deleteNode = _currNode;
			_currNode = _currNode->getPrevious();
			delete _deleteNode;
			_success = 1;
		}
	}

		//check empty
		//check the head
	
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


