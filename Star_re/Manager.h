#pragma once

class Node
{
private:
public:
	Node* m_next;
	Node* m_prev;
	Star* m_star;
	Node();
	~Node();
};

class LinkedList
{
private:
	Node* m_head;
	Node* m_tail;
public:
	LinkedList();
	~LinkedList();
	void PushBack(int x);
	void Print();
	void Delete(Node* _node);
	Node* GetHead() { return m_head; }
};

class Manager
{
private:
	LinkedList* m_list;
	int countingStar = 0;
public:
	Manager();
	~Manager();
	void MakeStar();
	void MoveStar();
	void CheckStar();
	bool CheckCollision(Flight* _flight);
};