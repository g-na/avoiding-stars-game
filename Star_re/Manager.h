#pragma once

class LinkedList
{
private:
	Star* m_head;
	Star* m_tail;
public:
	LinkedList();
	~LinkedList();
	void PushBack(int _x);
	void Print();
	void Delete(Star* _star);
	Star* GetHead() { return m_head; }
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
	void PrintStar();
	void CheckStar();
	bool CheckCollision(Flight* _flight);
	void GameOver(int _score);
};