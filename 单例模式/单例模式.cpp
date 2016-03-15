// ����ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//http://www.jellythink.com/archives/82

#include "stdafx.h"
/*
** FileName     : SingletonPatternDemo2
** Author       : Jelly Young
** Date         : 2013/11/20
** Description  : More information, please go to http://www.jellythink.com
*/

#include <iostream>
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard, std::adopt_lock
using namespace std;
std::mutex mtx;           // mutex for critical section
class Singleton
{
public:
	static Singleton *GetInstance()
	{
		if (m_Instance == NULL )
		{
			mtx.lock(); // C++û��ֱ�ӵ�Lock��������ʹ���������Lock������Boost���˴���Ϊ��˵��
			if (m_Instance == NULL )
			{
				m_Instance = new Singleton ();
			}
			mtx.unlock(); // C++û��ֱ�ӵ�Lock��������ʹ���������Lock������Boost���˴���Ϊ��˵��
		}
		return m_Instance;
	}

	static void DestoryInstance()
	{
		if (m_Instance != NULL )
		{
			delete m_Instance;
			m_Instance = NULL ;
		}
	}

	int GetTest()
	{
		return m_Test;
	}

private:
	Singleton(){ m_Test = 0; }
	static Singleton *m_Instance;
	int m_Test;
};

Singleton *Singleton ::m_Instance = NULL;

int main(int argc , char *argv [])
{
	Singleton *singletonObj = Singleton ::GetInstance();
	cout<<singletonObj->GetTest()<<endl;
	Singleton ::DestoryInstance();

	return 0;
}