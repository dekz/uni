#pragma once

#ifndef _ListNode
#define _ListNode

#include "Movie.h"
using namespace std;

class ListNode
{
public:
	ListNode();
	ListNode(Movie* data);
	~ListNode();
	Movie* getData() const;
	ListNode* getNext();
	ListNode* getPrevious();
	void setNext(ListNode* nextNode);
	void setPrevious(ListNode* previousNode);
	void setData(Movie* data);
	void insertAfter(ListNode* node);

private:
	Movie* m_data;
	ListNode* m_previous;
	ListNode* m_next;
};
#endif