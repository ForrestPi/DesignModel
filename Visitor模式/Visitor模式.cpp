// Visitorģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//http://www.cnblogs.com/loveis715/p/4423464.html
//���C++������������ - Visitorģʽ��ʵ��Double Dispatch


#include "stdafx.h"
#include <iostream>
using namespace std;

// ��ͨ�������ۿ�Ϊ0.03
class Vehicle
{
public:
	virtual double GetBaseDiscountRate() { return 0.03; }
	virtual double GetManagerDiscountRate() { return 0.03; }
};

// �����Ǳ��������̣���˿��Եõ�������ۿ�
class Benz : public Vehicle
{
public:
	virtual double GetBaseDiscountRate() { return 0.06; }
	virtual double GetManagerDiscountRate() { return 0.066; }
};

// ��ͨ��������Ա��ֻ�ܰ��չ�˾�涨���ۿ۽�������
class Sales
{
public:
	virtual double GetDiscountRate(Vehicle& vehicle)
	{
		return vehicle.GetBaseDiscountRate();
	}
};

// ���۾����������ĳЩ�����ṩ������Ż�
class SalesManager : public Sales
{
public:
	virtual double GetDiscountRate(Vehicle& vehicle)
	{
		return vehicle.GetManagerDiscountRate();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	// ��Ҫ���۵�������
	Vehicle& vehicle = Vehicle();
	Benz& benz = Benz();

	// ����ͨ����ѯ�������������ۿ�
	Sales* pSales = new Sales();
	double rate = pSales->GetDiscountRate(vehicle);
	cout << "Sales: The rate for common vehicle is: " << rate << endl;
	rate = pSales->GetDiscountRate(benz);
	cout << "Sales: The rate for benz is: " << rate << endl;

	// �����۾���ѯ�������������ۿ�
	SalesManager* pSalesManager = new SalesManager();
	rate = pSalesManager->GetDiscountRate(vehicle);
	cout << "Sales Manager: The rate for common vehicle is: " << rate << endl;
	rate = pSalesManager->GetDiscountRate(benz);
	cout << "Sales Manager: The rate for benz is: " << rate << endl;

	return 0;
}