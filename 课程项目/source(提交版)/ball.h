#pragma once
#include"cmd_console_tools.h"

//需作为友元类的提前声明
class player;
class game_messagebox;
class file_tools;

/*球类的声明*/
class ball {
private:
	int x, y, color;  //行、列、颜色
	bool mark;        //标志（用于后续进行消除）
	bool spmark;      //特殊标志（用于实现光标效果）
	static bool if_ball[81];  //各个位置是否有珠子的标志（静态成员，在各个对象间共享）
public:
	void print();  //打印珠子
	void set(const int COORD_X, const int COORD_Y, const int COLOR);  //设置珠子的位置和颜色

	ball() :x(-1), y(-1), color(COLOR_WHITE), mark(false), spmark(false) {}  //构造函数

	//友元类的声明
	friend class player;
	friend class game_messagebox;
	friend class file_tools;
};