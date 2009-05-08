#pragma once

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
	void insert(const Customer a_customer);
	void insert(Customer item, CTreeNode* root);
	void deleteItem(const Customer a_customer);
	bool search(const Customer a_customer) const;
	void PreOrderTraverse() const;
	void InOrderTraverse() const;
	void PostOrderTraverse() const;
	void PreOrderTraverse(CTreeNode* root) const;
	void InOrderTraverse(CTreeNode* root) const;
	void PostOrderTraverse(CTreeNode* root) const;
	void Clear();
	bool search(const Customer a_customer, CTreeNode* a_root) const; 

private:
	CTreeNode* m_root;
	void __cleanUp(const CTreeNode* p);
};
