// ����¼ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//http://www.jellythink.com/archives/342

#include "stdafx.h"
#include <iostream>
using namespace std;

class RoleStateMemento
{
public:
	RoleStateMemento(unsigned iBlood, unsigned iAttack, unsigned iDefense) : m_iBlood(iBlood), m_iAttack(iAttack), m_iDefense(iDefense){}

private:
	friend class GameRole;

	unsigned GetBloodValue() { return m_iBlood; }
	unsigned GetAttackValue() { return m_iAttack; }
	unsigned GetDefenseValue() { return m_iDefense; }

	unsigned m_iBlood;   // ������
	unsigned m_iAttack;  // ������
	unsigned m_iDefense; // ������
};

class GameRole
{
public:
	GameRole() : m_iBlood(100), m_iAttack(100), m_iDefense(100){}

	// �浵
	RoleStateMemento *SaveState() { return new RoleStateMemento(m_iBlood, m_iAttack, m_iDefense); }

	// �ָ��浵
	void RecoveryState(RoleStateMemento *pRoleState)
	{
		m_iBlood = pRoleState->GetBloodValue();
		m_iAttack = pRoleState->GetAttackValue();
		m_iDefense = pRoleState->GetDefenseValue();
		cout<<"Recovery..."<<endl;
	}

	void ShowState()
	{
		cout<<"Blood:"<<m_iBlood<<endl;
		cout<<"Attack:"<<m_iAttack<<endl;
		cout<<"Defense:"<<m_iDefense<<endl;
	}

	void Fight()
	{
		m_iBlood -= 100;
		m_iAttack -= 10;
		m_iDefense -= 20;

		if (m_iBlood == 0)
		{
			cout<<"Game Over"<<endl;
		}
	}

private:
	unsigned m_iBlood;   // ������
	unsigned m_iAttack;  // ������
	unsigned m_iDefense; // ������
};

class RoleStateCaretaker
{
public:
	void SetRoleStateMemento(RoleStateMemento *pRoleStateMemento) { m_pRoleStateMemento = pRoleStateMemento; }
	RoleStateMemento *GetRoleStateMemento() { return m_pRoleStateMemento; }

private:
	RoleStateMemento *m_pRoleStateMemento;
};

int main()
{
	GameRole *pLiXY = new GameRole(); // ��������ң�����ɫ
	pLiXY->ShowState(); // ��ʾ��ʼ��״̬

	// �浵
	RoleStateCaretaker *pRoleStateCaretaker = new RoleStateCaretaker();
	pRoleStateCaretaker->SetRoleStateMemento(pLiXY->SaveState());

	// ��ʼ���BOSS
	pLiXY->Fight();
	pLiXY->ShowState();

	// ���������¿�ʼ
	pLiXY->RecoveryState(pRoleStateCaretaker->GetRoleStateMemento());
	pLiXY->ShowState();

	return 0;
}
