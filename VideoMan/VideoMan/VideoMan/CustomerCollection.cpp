
#include <iostream>
#include "CustomerCollection.h"
using namespace std;


CustomerCollection::CustomerCollection(void)
{
	m_root = 0;
}

void CustomerCollection::insert(const Customer a_customer)
{
	if (m_root == 0)
	{
		m_root = new CTreeNode(a_customer);
	}
	else 
		insert(a_customer, m_root);
}

void CustomerCollection::insert(Customer a_customer, CTreeNode* p)
{	
	if (a_customer.getName() < p->getItem().getName())
	{
		if (p->getLChild() == 0)
			p->setLChild(new CTreeNode(a_customer));
		else
			insert(a_customer, p->getLChild());
	}
	else 
	{
		if (p->getRChild() == 0)
			p->setRChild(new CTreeNode(a_customer));
		else 
			insert(a_customer, p->getRChild());
	}

}

bool CustomerCollection::search(const Customer a_customer) const
{
	return search(a_customer, m_root);
}

bool CustomerCollection::search(const Customer a_customer, CTreeNode* a_root) const
{
	if (a_root != 0)
	{
		if (a_customer.getName() == a_root->getItem().getName())
		{
			return true;
		}
		else 
			if (a_customer.getName() < a_root->getItem().getName())
			{
				return search(a_customer, a_root->getLChild());
			}
			else 
				return search(a_customer, a_root->getRChild());
	}
	else 
		return false;

}

void CustomerCollection::__cleanUp(const CTreeNode* p)
{
	if(p != 0)
	{
		__cleanUp(p->getLChild());
		__cleanUp(p->getRChild());
		delete p;
	}
}

void CustomerCollection::PreOrderTraverse() const
{
	cout << "PreOrder: " << endl;;
	PreOrderTraverse(m_root);
	cout<< endl;
}

void CustomerCollection::PreOrderTraverse(CTreeNode* root) const
{
	if(root != 0)
	{
		cout << root->getItem();
		PreOrderTraverse(root->getLChild());
		PreOrderTraverse(root->getRChild());
	}
}

void CustomerCollection::InOrderTraverse() const
{
	cout<< "InOrder: " << endl;
	InOrderTraverse(m_root);
	cout << endl;
}

void CustomerCollection::InOrderTraverse(CTreeNode* root) const
{
	if(root != 0)
	{
		InOrderTraverse(root->getLChild());
		cout << root->getItem();
		InOrderTraverse(root->getRChild());
	}
}

void CustomerCollection::PostOrderTraverse() const
{
	cout << "PostOrder: " << endl;
	PostOrderTraverse(m_root);
	cout << endl;
}

void CustomerCollection::PostOrderTraverse(CTreeNode* root) const
{
	if(root != 0)
	{
		PostOrderTraverse(root->getLChild());
		PostOrderTraverse(root->getRChild());
		cout << root->getItem(); 
	}
}

CustomerCollection::~CustomerCollection(void)
{
	__cleanUp(m_root);
}

void CustomerCollection::deleteItem(const Customer a_customer)
{
	CTreeNode* ptr = m_root; // search reference
	CTreeNode* parent = 0; // parent of ptr
	while((ptr != 0)&&(a_customer.getName() != ptr->getItem().getName()))
	{
		parent = ptr;
		if(a_customer.getName() < ptr->getItem().getName()) // move to the left child of ptr
			ptr = ptr->getLChild();
		else
			ptr = ptr->getRChild();
	}

	if(ptr != 0) // if the search was successful
	{
		// case 3: item has two children
		if((ptr->getLChild() != 0)&&(ptr->getRChild() != 0))
		{
			// find the right-most node in left subtree of ptr
			if(ptr->getLChild()->getRChild() == 0) // a special case: the right subtree of ptr.LChild is empty
			{
				CTreeNode* temp = ptr->getLChild();
				ptr->setItem((ptr->getLChild())->getItem());
				ptr->setLChild(ptr->getLChild()->getLChild());
				delete temp;
			}
			else 
			{
				CTreeNode* p = ptr->getLChild()->getRChild();
				CTreeNode* pp = ptr->getLChild(); // parent of p
				while(p->getRChild() != 0)
				{
					pp = p;
					p = p->getRChild();
				}
				// copy the item at p to ptr
				Customer temp = p->getItem();
				ptr->setItem (temp);
				CTreeNode* temp_pointer = p->getLChild();
				pp->setRChild (temp_pointer);
				delete p;
			}
		}
		else // cases 1 & 2: item has no or only one child
		{
			CTreeNode* c;
			if(ptr->getLChild() != 0)
				c = ptr->getLChild();
			else
				c = ptr->getRChild();

			// remove node ptr
			if(ptr == m_root) //need to change root
				m_root = c;
			else
			{
				if(ptr == parent->getLChild())
					parent->setLChild (c);
				else
					parent->setRChild (c);
			}

			//SHOULD WE CALL A CLEANUP METHOD IN CUSTOMER?
			//
			//
			//
			//
			delete ptr;
		}

	}
}