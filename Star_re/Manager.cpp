#include "GameObject.h"
#include "Manager.h"
#include <stdio.h>
#include <random>

LinkedList::LinkedList()
{
	m_head = nullptr;
	m_tail = nullptr;
}
LinkedList::~LinkedList()
{
	Star* star = m_head;
	Star* nextStar = nullptr;
	while (star)
	{
		nextStar = star->m_next;
		delete star;
		star = nextStar;
	}
}
void LinkedList::PushBack(int _x)
{
	Star* star = new Star();
	star->m_x = _x;
	star->m_y = 0;

	if (m_head == nullptr)	{ m_head = star; }
	else
	{
		m_tail->m_next = star;
		star->m_prev = m_tail;
	}		
	m_tail = star;
}
void LinkedList::Print()
{
	Star* star = m_head;
	while (star)
	{	
		star->Print();
		star = star->m_next;
	}
}
void LinkedList::Delete(Star* _star)
{
	if (_star == nullptr) { return; }

	Star* prevStar = _star->m_prev;
	Star* nextStar = _star->m_next;
	
	if(_star == m_head){ m_head = nextStar; }
	else if(_star == m_tail) { m_tail = prevStar; }
	else
	{	
		prevStar->m_next = nextStar;
		nextStar->m_prev = prevStar;
	}
	m_head->m_prev = nullptr;
	m_tail->m_next = nullptr;
	delete _star;
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
	Star* star = m_list->GetHead();
	while (star)
	{
		star->Move();
		star = star->m_next;
	}
	
}
void Manager::PrintStar()
{
	m_list->Print();
}
void Manager::CheckStar()
{
	Star* star = m_list->GetHead();
	Star* nextStar = nullptr;
	while (star)
	{
		nextStar = star->m_next;
		if (star->m_y == 25)
		{	
			m_list->Delete(star);
			countingStar--;
		}
		star = nextStar;
	}
}
bool Manager::CheckCollision(Flight* _flight)
{
	Star* star = m_list->GetHead();
	while (star)
	{
		if (_flight->m_x == star->m_x)
		{
			if (_flight->m_y == star->m_y)
			{
				m_list->Delete(star);
				return true;
			}
		}
		star = star->m_next;
	}
	return false;
}
void Manager::GameOver(int _score)
{
	printf("\n=========================\n\n");
	printf("your score is %d.", _score);
	printf("\n\n=========================\n");
}
