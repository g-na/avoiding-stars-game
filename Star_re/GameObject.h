#pragma once

class Foundation
{
private:	
public:
	int m_x;
	int m_y;
	Foundation();
	~Foundation();
	void GotoXY(int x, int y);
};

class Flight :public Foundation
{
private:
public:
	Flight();
	~Flight();
	void Move(int input);
	void Print();
};

class Star :public Foundation
{
private:
public:
	Star* m_next;
	Star* m_prev;
	Star();
	~Star();
	void Move();
	void Print();
};