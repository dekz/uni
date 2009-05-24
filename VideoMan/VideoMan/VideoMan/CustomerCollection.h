#pragma once


#ifndef _CustomerCollection
#define _CustomerCollection

#include <iostream>
#include <string>
#include "CTreeNode.h"
using namespace std;

class CustomerCollection
{
public:
	CustomerCollection(void);
	~CustomerCollection(void);
	bool IsEmpty() const;
	void insert(Customer* a_customer);
	void insert(Customer* a_customer, CTreeNode* root);
	void deleteItem(Customer* a_customer);
	bool search(Customer* a_customer) const;
	void PreOrderTraverse() const;
	void InOrderTraverse() const;
	void rentingMovie(Movie* a_movie);
	void rentingMovie(CTreeNode* a_node, Movie* a_movie);
	Customer* getCustomer(string a_name);
	Customer* getCustomer(string a_name, CTreeNode* a_node);
	void PostOrderTraverse() const;
	void PreOrderTraverse(CTreeNode* root) const;
	void InOrderTraverse(CTreeNode* root) const;
	void PostOrderTraverse(CTreeNode* root) const;
	void Clear();
	bool search(Customer* a_customer, CTreeNode* a_root) const; 
	bool search(string a_name);
	bool search(string a_name, CTreeNode* a_root);

private:
	CTreeNode* m_root;
	void __cleanUp(const CTreeNode* p);
};
#endif
