// Visitor模式.cpp : 定义控制台应用程序的入口点。
//http://www.cnblogs.com/loveis715/p/4423464.html
//完成C++不能做到的事 - Visitor模式，实现Double Dispatch


#include "stdafx.h"
#include <iostream>
using namespace std;

// 普通汽车，折扣为0.03
class Vehicle
{
public:
	virtual double GetBaseDiscountRate() { return 0.03; }
	virtual double GetManagerDiscountRate() { return 0.03; }
};

// 由于是奔驰特销商，因此可以得到更大的折扣
class Benz : public Vehicle
{
public:
	virtual double GetBaseDiscountRate() { return 0.06; }
	virtual double GetManagerDiscountRate() { return 0.066; }
};

// 普通的销售人员，只能按照公司规定的折扣进行销售
class Sales
{
public:
	virtual double GetDiscountRate(Vehicle& vehicle)
	{
		return vehicle.GetBaseDiscountRate();
	}
};

// 销售经理，可以针对某些车型提供额外的优惠
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
	// 需要销售的两辆车
	Vehicle& vehicle = Vehicle();
	Benz& benz = Benz();

	// 向普通销售询问这两辆车的折扣
	Sales* pSales = new Sales();
	double rate = pSales->GetDiscountRate(vehicle);
	cout << "Sales: The rate for common vehicle is: " << rate << endl;
	rate = pSales->GetDiscountRate(benz);
	cout << "Sales: The rate for benz is: " << rate << endl;

	// 向销售经理询问这两辆车的折扣
	SalesManager* pSalesManager = new SalesManager();
	rate = pSalesManager->GetDiscountRate(vehicle);
	cout << "Sales Manager: The rate for common vehicle is: " << rate << endl;
	rate = pSalesManager->GetDiscountRate(benz);
	cout << "Sales Manager: The rate for benz is: " << rate << endl;

	return 0;
}