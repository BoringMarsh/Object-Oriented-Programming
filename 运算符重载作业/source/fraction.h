#pragma once

class fraction {
private:
	long long n, d;  //˽�г�Ա�����ӡ���ĸ
public:
	/*��һ�ࣺ��Ŀ�����ຯ��*/
	void Inverse();  //ȡ������
	void Reciprocal();  //����
	void Reduction();  //Լ��
	void DtoF(double num);  //������double��ת�ɷ���
	void StoF(const char* String);  //�������ַ����ͷ����ı�ʾת����ֵ�ͷ���

	/*�ڶ��ࣺ˫Ŀ�����ຯ��*/
	/*1����������*/
	fraction operator+(const fraction& f);  //��
	fraction operator-(const fraction& f);  //��
	fraction operator*(const fraction& f);  //��
	fraction operator/(const fraction& f);  //��
	void operator%(fraction& f);            //ͨ��
	/*2����ϵ����*/
	bool operator>(const fraction& f);   //����
	bool operator<(const fraction& f);   //С��
	bool operator>=(const fraction& f);  //���ڵ���
	bool operator<=(const fraction& f);  //С�ڵ���
	bool operator==(const fraction& f);  //����
	bool operator!=(const fraction& f);  //������

	/*�����ࣺ��ʾ����display*/
	void display();

	fraction(long long N = 0, long long D = 0) :n(N), d(D)  //���캯��
	{
		Reduction();
	}

	~fraction() {}  //��������
};