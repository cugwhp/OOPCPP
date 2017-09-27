#pragma once

#include "stdlib.h"

template<typename T>
struct Node
{
	T	item;
	Node* next;
};

template<typename T>
class CTList
{
public:
	CTList(void)
	{
		m_ptHead = m_ptTail = new Node<T>;
		memset(m_ptHead, 0, sizeof(Node<T>));
	}

	CTList(const CTList& list)
	{
		m_ptHead = m_ptTail = new Node<T>;
		memset(m_ptHead, 0, sizeof(Node<T>));

		Node<T>*	ptNode = list.m_ptHead;
		while(ptNode)
		{
			Insert(ptNode->item);
		}
	}

	void Insert(const T& item)
	{
		Insert(m_ptTail, item);
	}

	void Insert(Node<T>* ptNode, const T& item)
	{
		Node<T>*	ptNew = new Node<T>;
		ptNew->item = item;

		ptNew->next = ptNode->next;
		ptNode->next = ptNew;

		if (ptNode == m_ptTail)
			m_ptTail = ptNew;
	}

	int GetSize()
	{
		Node<T>*	ptNode = m_ptHead;
		int			nSize = 0;
		
		while(ptNode)
		{
			if (ptNode->next)
				nSize++;

			ptNode = ptNode->next;
		}

		return nSize;
	}
	
	~CTList(void)
	{
		Node<T>*	pt = m_ptHead;
		while(pt)
		{
			delete[] pt;

			pt = pt->next;
		}
	}

	operator=(const CTList<T>& list);

	bool empty()
	{
		return m_ptHead==m_ptTail;
	}

private:
	void clear()
	{
		Node<T>*	pt = m_ptHead;
		Node<T>*	next = NULL;
		while(pt)
		{
			next = pt->next;
			delete pt;
			pt = next;
		}
	}

private:
	Node<T>*	m_ptHead;
	Node<T>*	m_ptTail;
};
