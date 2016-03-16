// ���ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
/*
** FileName     : FacadePatternDemo
** Author       : Jelly Young
** Date         : 2014/1/2
** Description  : More information, please go to http://www.jellythink.com
*/

#include <iostream>
using namespace std;

// �﷨������ϵͳ
class CSyntaxParser
{
public:
	void SyntaxParser()
	{
		cout<<"Syntax Parser"<<endl;
	}
};

// �����м������ϵͳ
class CGenMidCode
{
public:
	void GenMidCode()
	{
		cout<<"Generate middle code"<<endl;
	}
};

// ���ɻ�������ϵͳ
class CGenAssemblyCode
{
public:
	void GenAssemblyCode()
	{
		cout<<"Generate assembly code"<<endl;
	}
};

// �������ɿ�ִ��Ӧ�ó�������ϵͳ
class CLinkSystem
{
public:
	void LinkSystem()
	{
		cout<<"Link System"<<endl;
	}
};

class Facade
{
public:
	void Compile()
	{
		CSyntaxParser syntaxParser;
		CGenMidCode genMidCode;
		CGenAssemblyCode genAssemblyCode;
		CLinkSystem linkSystem;
		syntaxParser.SyntaxParser();
		genMidCode.GenMidCode();
		genAssemblyCode.GenAssemblyCode();
		linkSystem.LinkSystem();
	}
};

// �ͻ���
int main()
{
	Facade facade;
	facade.Compile();
}
