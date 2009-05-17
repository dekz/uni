#include "ListNode.h"

ListNode::ListNode()
{
	m_data = NULL;
	m_next = 0;
	m_previous = 0;
}

ListNode::ListNode(Movie* data)
{
	m_data = data;
	m_next = 0;
	m_previous = 0;
}

Movie* ListNode::getData() const
{
	return m_data;
}

ListNode* ListNode::getNext()
{
	return m_next;
}

ListNode* ListNode::getPrevious()
{
	return m_previous;
}


void ListNode::setData(Movie* data)
{
	m_data = data;
}

void ListNode::setNext(ListNode* nextNode)
{
	this->m_next = nextNode;
}

void ListNode::setPrevious(ListNode* previousNode)
{
	m_previous = previousNode;
}


/*
This method will take a node as a parameter 
It will insert the current node after that node
Will fail if it has connections, only moves one node
*/
void ListNode::insertAfter(ListNode* node)
{
	//if im the node at the end
	//or i don't have any links
	if (m_next == 0)
	{
		m_next = node->getNext();
		node->setNext(this);
		m_previous = node;
	}
	else 
	{
		cout << "shuffling linked list" << endl;
		m_next = node->getNext();
		m_next->setPrevious(this);
		m_previous = node;
		node->setNext(this);
	}
}

ListNode::~ListNode(void)
{

}
