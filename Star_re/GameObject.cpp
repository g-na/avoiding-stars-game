#include "GameObject.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

Foundation::Foundation()
{
	m_x = 0;
	m_y = 0;
}
Foundation::~Foundation()
{
}
void Foundation::GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

Flight::Flight()
{
	m_x = 25;
	m_y = 10;
}
Flight::~Flight()
{}
void Flight::Move(int _input)
{
	switch (_input)
	{
	case 'a':
		if (m_x != 0) { m_x--; }
		if (m_x < 0) { m_x = 0; }
		break;
	case 'd':
		if (m_x != 50) { m_x++; }
		if (m_x > 50) { m_x = 50; }
		break;
	}
}
void Flight::Print()
{
	GotoXY(m_x, m_y);
	printf("¡â");
}

Star::Star()
{
	m_x = 0;
	m_y = 0;
}
Star::~Star()
{}
void Star::Move()
{
	m_y++;
}
void Star::Print()
{
	GotoXY(m_x, m_y);
	printf("¡Ú");
}