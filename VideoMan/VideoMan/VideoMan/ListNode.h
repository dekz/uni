#pragma once
#include "Movie.h"
using namespace std;

class ListNode
{
public:
	ListNode(void);
	ListNode(const Movie& data);
	~ListNode(void);
	Movie getData() const;
	ListNode* getNext();
	void setNext(ListNode* nextNode);
	void setPrevious(ListNode* previousNode);
	void setData(const Movie& data);
	void insertAfter(ListNode* node);

private:
	Movie m_data;
	ListNode* m_next;
	ListNode* m_previous;
};
