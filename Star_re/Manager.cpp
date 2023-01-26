#include "GameObject.h"
#include "Manager.h"
#include <stdio.h>
#include <random>

Node::Node()
{
	m_next = nullptr;
	m_prev = nullptr;
	m_star = new Star();
}
Node::~Node()
{
	delete m_star;
}

LinkedList::LinkedList()
{
	m_head = nullptr;
	m_tail = nullptr;
}
LinkedList::~LinkedList()
{
	Node* node = m_head;
	Node* nextNode = nullptr;
	while (node)
	{
		nextNode = node->m_next;
		delete node;
		node = nextNode;
	}
}
void LinkedList::PushBack(int _x)
{
	Node* node = new Node();
	node->m_star->m_x = _x;
	node->m_star->m_y = 0;

	if (m_head == nullptr)	{ m_head = node; }
	else
	{
		m_tail->m_next = node;
		node->m_prev = m_tail;
	}		
	m_tail = node;
}
void LinkedList::Print()
{
	Node* node = m_head;
	while (node)
	{	
		node->m_star->Print();
		node = node->m_next;
	}
}
void LinkedList::Delete(Node* _node)
{
	if (_node == nullptr) { return; }

	Node* prevNode = _node->m_prev;
	Node* nextNode = _node->m_next;
	if (_node == m_head || _node == m_tail)
	{
		if(_node == m_head){ m_head = nextNode; }
		else { m_tail = prevNode; }
	}
	else
	{	
		prevNode->m_next = nextNode;
		nextNode->m_prev = prevNode;
	}
	m_head->m_prev = nullptr;
	m_tail->m_next = nullptr;
	delete _node;
}

Manager::Manager()
{
	m_list = new LinkedList();
}
Manager::~Manager()
{
	delete m_list;
}
void Manager::MakeStar()
{
	if (countingStar < 30)
	{	
		int x = (rand() % 48) + 1;
		m_list->PushBack(x);
		countingStar++;
	}
}
void Manager::MoveStar()
{
	Node* node = m_list->GetHead();
	while (node)
	{
		node->m_star->Move();
		node = node->m_next;
	}
	m_list->Print();
}
void Manager::CheckStar()
{
	Node* node = m_list->GetHead();
	Node* nextNode = nullptr;
	while (node)
	{
		nextNode = node->m_next;
		if (node->m_star->m_y == 25)
		{	
			m_list->Delete(node);
			countingStar--;
		}
		node = nextNode;
	}
}
bool Manager::CheckCollision(Flight* _flight)
{
	Node* node = m_list->GetHead();
	while (node)
	{
		if (_flight->m_x == node->m_star->m_x)
		{
			if (_flight->m_y == node->m_star->m_y)
			{
				m_list->Delete(node);
				return true;
			}
		}
		node = node->m_next;
	}
	return false;
}

