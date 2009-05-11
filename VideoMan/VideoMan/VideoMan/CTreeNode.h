#pragma once
#ifndef _CTreeNode
#define _CTreeNode

#include <string>
#include "Customer.h"

using namespace std;

class CTreeNode
{
public:
	CTreeNode(Customer* item);
	void setItem(Customer* data);
	Customer* getItem() const;
	CTreeNode* getLChild() const;
	CTreeNode* getRChild() const;
	void setRChild(CTreeNode* p);
	void setLChild(CTreeNode* p);
	~CTreeNode(void);
private:
	Customer* m_item;
	CTreeNode* lchild;
	CTreeNode* rchild;
};
#endif