#include<iostream>
#include"fraction.h"
using namespace std;

int main()
{
	cout << "由于使用命令行方式输入数据进行测试，成员函数StoF不再单独进行测试，成员函数display仅进行特殊测试" << endl << endl;

	if (1) {
		cout << "测试成员函数Inverse:" << endl;
		fraction a;
		char c[30];

		cout << "请输入: ";
		cin >> c;
		a.StoF(c);
		a.Inverse();
		cout << "结果为: ";
		a.display();

		cout << "请输入: ";
		cin >> c;
		a.StoF(c);
		a.Inverse();
		cout << "结果为: ";
		a.display();
	}

	if (1) {
		cout << "\n测试成员函数Reciprocal:" << endl;
		fraction a;
		char c[30];

		cout << "请输入: ";
		cin >> c;
		a.StoF(c);
		a.Reciprocal();
		cout << "结果为: ";
		a.display();

		cout << "请输入: ";
		cin >> c;
		a.StoF(c);
		a.Reciprocal();
		cout << "结果为: ";
		a.display();
	}

	if (1) {
		cout << "\n测试成员函数Reduction:" << endl;
		fraction a;
		char c[30];

		cout << "请输入: ";
		cin >> c;
		a.StoF(c);
		cout << "结果为: ";
		a.display();

		cout << "请输入: ";
		cin >> c;
		a.StoF(c);
		cout << "结果为: ";
		a.display();
	}

	if (1) {
		cout << "\n测试成员函数DtoF:" << endl;
		fraction a;
		double num;

		cout << "请输入: ";
		cin >> num;
		a.DtoF(num);
		cout << "结果为: ";
		a.display();

		cout << "请输入: ";
		cin >> num;
		a.DtoF(num);
		cout << "结果为: ";
		a.display();
	}

	if (1) {
		cout << "\n测试成员函数operator+:" << endl;
		fraction a, b, ret;
		char c[30];

		cout << "请输入a: ";
		cin >> c;
		a.StoF(c);

		cout << "请输入b: ";
		cin >> c;
		b.StoF(c);

		ret = a + b;
		cout << "结果为:  ";
		ret.display();
	}

	if (1) {
		cout << "\n测试成员函数operator-:" << endl;
		fraction a, b, ret;
		char c[30];

		cout << "请输入a: ";
		cin >> c;
		a.StoF(c);

		cout << "请输入b: ";
		cin >> c;
		b.StoF(c);

		ret = a - b;
		cout << "结果为:  ";
		ret.display();
	}

	if (1) {
		cout << "\n测试成员函数operator*:" << endl;
		fraction a, b, ret;
		char c[30];

		cout << "请输入a: ";
		cin >> c;
		a.StoF(c);

		cout << "请输入b: ";
		cin >> c;
		b.StoF(c);

		ret = a * b;
		cout << "结果为:  ";
		ret.display();
	}

	if (1) {
		cout << "\n测试成员函数operator/:" << endl;
		fraction a, b, ret;
		char c[30];

		cout << "请输入a: ";
		cin >> c;
		a.StoF(c);

		cout << "请输入b: ";
		cin >> c;
		b.StoF(c);

		ret = a / b;
		cout << "结果为:  ";
		ret.display();
	}

	if (1) {
		cout << "\n测试成员函数operator%:" << endl;
		fraction a, b;
		char c[30];

		cout << "请输入a: ";
		cin >> c;
		a.StoF(c);

		cout << "请输入b: ";
		cin >> c;
		b.StoF(c);

		a % b;
		cout << "a通分后: ";
		a.display();
		cout << "b通分后: ";
		b.display();
	}

	if (1) {
		cout << "\n测试成员函数operator>:" << endl;
		fraction a, b;
		char c[30];

		cout << "请输入a: ";
		cin >> c;
		a.StoF(c);

		cout << "请输入b: ";
		cin >> c;
		b.StoF(c);

		cout << "结果为:  ";
		if (a > b)
			cout << "a比b大" << endl;
		else
			cout << "b比a大" << endl;
	}

	if (1) {
		cout << "\n测试成员函数operator<:" << endl;
		fraction a, b;
		char c[30];

		cout << "请输入a: ";
		cin >> c;
		a.StoF(c);

		cout << "请输入b: ";
		cin >> c;
		b.StoF(c);

		cout << "结果为:  ";
		if (a < b)
			cout << "a比b小" << endl;
		else
			cout << "b比a小" << endl;
	}

	if (1) {
		cout << "\n测试成员函数operator>=:" << endl;
		fraction a, b;
		char c[30];

		cout << "请输入a: ";
		cin >> c;
		a.StoF(c);

		cout << "请输入b: ";
		cin >> c;
		b.StoF(c);

		cout << "结果为:  ";
		if (a >= b)
			cout << "a大于等于b" << endl;
		else
			cout << "b大于等于a" << endl;
	}

	if (1) {
		cout << "\n测试成员函数operator<=:" << endl;
		fraction a, b;
		char c[30];

		cout << "请输入a: ";
		cin >> c;
		a.StoF(c);

		cout << "请输入b: ";
		cin >> c;
		b.StoF(c);

		cout << "结果为:  ";
		if (a <= b)
			cout << "a小于等于b" << endl;
		else
			cout << "b小于等于a" << endl;
	}

	if (1) {
		cout << "\n测试成员函数operator==:" << endl;
		fraction a, b;
		char c[30];

		cout << "请输入a: ";
		cin >> c;
		a.StoF(c);

		cout << "请输入b: ";
		cin >> c;
		b.StoF(c);

		cout << "结果为:  ";
		if (a == b)
			cout << "a等于b" << endl;
		else
			cout << "a不等于b" << endl;
	}

	if (1) {
		cout << "\n测试成员函数operator!=:" << endl;
		fraction a, b;
		char c[30];

		cout << "请输入a: ";
		cin >> c;
		a.StoF(c);

		cout << "请输入b: ";
		cin >> c;
		b.StoF(c);

		cout << "结果为:  ";
		if (a != b)
			cout << "a不等于b" << endl;
		else
			cout << "a等于b" << endl;
	}

	if (1) {
		cout << "\n测试成员函数display:" << endl;
		fraction a;
		char c[30];

		cout << "请输入: ";
		cin >> c;
		a.StoF(c);
		cout << "结果为: ";
		a.display();

		cout << "请输入: ";
		cin >> c;
		a.StoF(c);
		cout << "结果为: ";
		a.display();

		cout << "请输入: ";
		cin >> c;
		a.StoF(c);
		cout << "结果为: ";
		a.display();
	}

	return 0;
}