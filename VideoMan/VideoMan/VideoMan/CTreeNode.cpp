#include "CTreeNode.h"

CTreeNode::CTreeNode(Customer* item)
{
	lchild = 0;
	rchild = 0;
	m_item = item;
}

void CTreeNode::setItem(Customer* data)
{
	m_item = data;
}

Customer* CTreeNode::getItem() const
{
	return m_item;
}

CTreeNode* CTreeNode::getLChild() const
{
	return lchild;
}

CTreeNode* CTreeNode::getRChild() const
{
	return  rchild;
}

void CTreeNode::setRChild(CTreeNode* p)
{
	rchild = p;
}

void CTreeNode::setLChild(CTreeNode* p)
{
	lchild = p;
}


CTreeNode::~CTreeNode(void)
{
}
