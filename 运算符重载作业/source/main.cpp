#include<iostream>
#include"fraction.h"
using namespace std;

int main()
{
	cout << "����ʹ�������з�ʽ�������ݽ��в��ԣ���Ա����StoF���ٵ������в��ԣ���Ա����display�������������" << endl << endl;

	if (1) {
		cout << "���Գ�Ա����Inverse:" << endl;
		fraction a;
		char c[30];

		cout << "������: ";
		cin >> c;
		a.StoF(c);
		a.Inverse();
		cout << "���Ϊ: ";
		a.display();

		cout << "������: ";
		cin >> c;
		a.StoF(c);
		a.Inverse();
		cout << "���Ϊ: ";
		a.display();
	}

	if (1) {
		cout << "\n���Գ�Ա����Reciprocal:" << endl;
		fraction a;
		char c[30];

		cout << "������: ";
		cin >> c;
		a.StoF(c);
		a.Reciprocal();
		cout << "���Ϊ: ";
		a.display();

		cout << "������: ";
		cin >> c;
		a.StoF(c);
		a.Reciprocal();
		cout << "���Ϊ: ";
		a.display();
	}

	if (1) {
		cout << "\n���Գ�Ա����Reduction:" << endl;
		fraction a;
		char c[30];

		cout << "������: ";
		cin >> c;
		a.StoF(c);
		cout << "���Ϊ: ";
		a.display();

		cout << "������: ";
		cin >> c;
		a.StoF(c);
		cout << "���Ϊ: ";
		a.display();
	}

	if (1) {
		cout << "\n���Գ�Ա����DtoF:" << endl;
		fraction a;
		double num;

		cout << "������: ";
		cin >> num;
		a.DtoF(num);
		cout << "���Ϊ: ";
		a.display();

		cout << "������: ";
		cin >> num;
		a.DtoF(num);
		cout << "���Ϊ: ";
		a.display();
	}

	if (1) {
		cout << "\n���Գ�Ա����operator+:" << endl;
		fraction a, b, ret;
		char c[30];

		cout << "������a: ";
		cin >> c;
		a.StoF(c);

		cout << "������b: ";
		cin >> c;
		b.StoF(c);

		ret = a + b;
		cout << "���Ϊ:  ";
		ret.display();
	}

	if (1) {
		cout << "\n���Գ�Ա����operator-:" << endl;
		fraction a, b, ret;
		char c[30];

		cout << "������a: ";
		cin >> c;
		a.StoF(c);

		cout << "������b: ";
		cin >> c;
		b.StoF(c);

		ret = a - b;
		cout << "���Ϊ:  ";
		ret.display();
	}

	if (1) {
		cout << "\n���Գ�Ա����operator*:" << endl;
		fraction a, b, ret;
		char c[30];

		cout << "������a: ";
		cin >> c;
		a.StoF(c);

		cout << "������b: ";
		cin >> c;
		b.StoF(c);

		ret = a * b;
		cout << "���Ϊ:  ";
		ret.display();
	}

	if (1) {
		cout << "\n���Գ�Ա����operator/:" << endl;
		fraction a, b, ret;
		char c[30];

		cout << "������a: ";
		cin >> c;
		a.StoF(c);

		cout << "������b: ";
		cin >> c;
		b.StoF(c);

		ret = a / b;
		cout << "���Ϊ:  ";
		ret.display();
	}

	if (1) {
		cout << "\n���Գ�Ա����operator%:" << endl;
		fraction a, b;
		char c[30];

		cout << "������a: ";
		cin >> c;
		a.StoF(c);

		cout << "������b: ";
		cin >> c;
		b.StoF(c);

		a % b;
		cout << "aͨ�ֺ�: ";
		a.display();
		cout << "bͨ�ֺ�: ";
		b.display();
	}

	if (1) {
		cout << "\n���Գ�Ա����operator>:" << endl;
		fraction a, b;
		char c[30];

		cout << "������a: ";
		cin >> c;
		a.StoF(c);

		cout << "������b: ";
		cin >> c;
		b.StoF(c);

		cout << "���Ϊ:  ";
		if (a > b)
			cout << "a��b��" << endl;
		else
			cout << "b��a��" << endl;
	}

	if (1) {
		cout << "\n���Գ�Ա����operator<:" << endl;
		fraction a, b;
		char c[30];

		cout << "������a: ";
		cin >> c;
		a.StoF(c);

		cout << "������b: ";
		cin >> c;
		b.StoF(c);

		cout << "���Ϊ:  ";
		if (a < b)
			cout << "a��bС" << endl;
		else
			cout << "b��aС" << endl;
	}

	if (1) {
		cout << "\n���Գ�Ա����operator>=:" << endl;
		fraction a, b;
		char c[30];

		cout << "������a: ";
		cin >> c;
		a.StoF(c);

		cout << "������b: ";
		cin >> c;
		b.StoF(c);

		cout << "���Ϊ:  ";
		if (a >= b)
			cout << "a���ڵ���b" << endl;
		else
			cout << "b���ڵ���a" << endl;
	}

	if (1) {
		cout << "\n���Գ�Ա����operator<=:" << endl;
		fraction a, b;
		char c[30];

		cout << "������a: ";
		cin >> c;
		a.StoF(c);

		cout << "������b: ";
		cin >> c;
		b.StoF(c);

		cout << "���Ϊ:  ";
		if (a <= b)
			cout << "aС�ڵ���b" << endl;
		else
			cout << "bС�ڵ���a" << endl;
	}

	if (1) {
		cout << "\n���Գ�Ա����operator==:" << endl;
		fraction a, b;
		char c[30];

		cout << "������a: ";
		cin >> c;
		a.StoF(c);

		cout << "������b: ";
		cin >> c;
		b.StoF(c);

		cout << "���Ϊ:  ";
		if (a == b)
			cout << "a����b" << endl;
		else
			cout << "a������b" << endl;
	}

	if (1) {
		cout << "\n���Գ�Ա����operator!=:" << endl;
		fraction a, b;
		char c[30];

		cout << "������a: ";
		cin >> c;
		a.StoF(c);

		cout << "������b: ";
		cin >> c;
		b.StoF(c);

		cout << "���Ϊ:  ";
		if (a != b)
			cout << "a������b" << endl;
		else
			cout << "a����b" << endl;
	}

	if (1) {
		cout << "\n���Գ�Ա����display:" << endl;
		fraction a;
		char c[30];

		cout << "������: ";
		cin >> c;
		a.StoF(c);
		cout << "���Ϊ: ";
		a.display();

		cout << "������: ";
		cin >> c;
		a.StoF(c);
		cout << "���Ϊ: ";
		a.display();

		cout << "������: ";
		cin >> c;
		a.StoF(c);
		cout << "���Ϊ: ";
		a.display();
	}

	return 0;
}