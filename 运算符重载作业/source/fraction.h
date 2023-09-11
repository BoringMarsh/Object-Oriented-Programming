#pragma once

class fraction {
private:
	long long n, d;  //私有成员：分子、分母
public:
	/*第一类：单目运算类函数*/
	void Inverse();  //取负运算
	void Reciprocal();  //求倒数
	void Reduction();  //约分
	void DtoF(double num);  //输入是double型转成分数
	void StoF(const char* String);  //输入是字符串型分数的表示转成数值型分数

	/*第二类：双目运算类函数*/
	/*1、算术运算*/
	fraction operator+(const fraction& f);  //加
	fraction operator-(const fraction& f);  //减
	fraction operator*(const fraction& f);  //乘
	fraction operator/(const fraction& f);  //除
	void operator%(fraction& f);            //通分
	/*2、关系运算*/
	bool operator>(const fraction& f);   //大于
	bool operator<(const fraction& f);   //小于
	bool operator>=(const fraction& f);  //大于等于
	bool operator<=(const fraction& f);  //小于等于
	bool operator==(const fraction& f);  //等于
	bool operator!=(const fraction& f);  //不等于

	/*第三类：显示函数display*/
	void display();

	fraction(long long N = 0, long long D = 0) :n(N), d(D)  //构造函数
	{
		Reduction();
	}

	~fraction() {}  //析构函数
};