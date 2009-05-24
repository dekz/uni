#pragma once


#ifndef _MovieCollection
#define _MovieCollection

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
	void insert(Movie* data); 
	bool remove(Movie* data); 
	void clear(); //delete all objects 
	bool search(Movie* data);
	void traverse();
	void traverse(string a_char);
	bool search(string data);
	Movie* getMovie(string a_name);

private:
	int m_listCount;
	ListNode* firstNode;
	ListNode* lastNode;

};
#endif
