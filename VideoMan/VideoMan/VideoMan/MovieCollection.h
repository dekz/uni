#pragma once

#include <iostream>
#include <string>
#include "ListNode.h"
using namespace std;


class MovieCollection
{
public:
	MovieCollection();
	~MovieCollection(void);
	int Capacity();
	int Count();
	bool isEmpty();
	bool isFull();
	bool isMember();
	void insert(const Movie data); //insert somewhere and increase listCount
	int remove(); //remove something and decrease listCount
	void clear(); //delete all objects 
	bool search(Movie data);

private:
	int m_listCount;
	ListNode* firstNode;
	ListNode* lastNode;

};
