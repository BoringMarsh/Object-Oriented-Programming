#pragma once
#include"90-b3.h"

//读小键盘键鼠操作的返回值
#define QUIT      0x2001  //退出
#define RESET     0x2002  //重新开始
#define CONTINUE  0x2003  //继续
#define SAVE_1    0x2004  //保存游戏到位置1
#define SAVE_2    0x2005  //保存游戏到位置2
#define SAVE_3    0x2006  //保存游戏到位置3
#define SAVE_4    0x2007  //保存游戏到位置4
#define DELETE_1  0x2008  //删除位置1上的存档
#define DELETE_2  0x2009  //删除位置1上的存档
#define DELETE_3  0x200a  //删除位置1上的存档
#define DELETE_4  0x200b  //删除位置1上的存档

//小键盘各部分的坐标（用阶数表示）
#define KB_COORD_X     4*__GAME.order-7  //小键盘左上角横坐标
#define KB_COORD_Y     4*__GAME.order+6  //小键盘左上角纵坐标
#define Q_COORD_X      KB_COORD_X+3   //功能键Q横坐标
#define Q_COORD_Y      KB_COORD_Y+1   //功能键Q纵坐标
#define R_COORD_X      KB_COORD_X+6   //功能键R横坐标
#define R_COORD_Y      KB_COORD_Y+1   //功能键R纵坐标
#define S_COORD_X      KB_COORD_X+3   //功能键S横坐标
#define S_COORD_Y      KB_COORD_Y+7   //功能键S纵坐标
#define D_COORD_X      KB_COORD_X+6   //功能键D横坐标
#define D_COORD_Y      KB_COORD_Y+7   //功能键D纵坐标
#define O_COORD_X      KB_COORD_X+17  //功能键O横坐标
#define O_COORD_Y      KB_COORD_Y+7   //功能键O纵坐标
#define KBVER_COORD_X  KB_COORD_X+17  //小键盘版本号左上角横坐标
#define KBVER_COORD_Y  KB_COORD_Y+1   //小键盘版本号右上角横坐标
#define UP_COORD_X     KB_COORD_X+9   //上箭头键左上角横坐标
#define UP_COORD_Y     KB_COORD_Y+1   //上箭头键左上角纵坐标
#define DOWN_COORD_X   KB_COORD_X+9   //下箭头键左上角横坐标
#define DOWN_COORD_Y   KB_COORD_Y+5   //下箭头键左上角纵坐标
#define LEFT_COORD_X   KB_COORD_X+2   //左箭头键左上角横坐标
#define LEFT_COORD_Y   KB_COORD_Y+3   //左箭头键左上角纵坐标
#define RIGHT_COORD_X  KB_COORD_X+16  //右箭头键左上角横坐标
#define RIGHT_COORD_Y  KB_COORD_Y+3   //右箭头键左上角纵坐标

//小键盘按键数
#define KB_BUTTON_NUM 9

/*键盘类的声明*/
class keyboard {
private:
	button button_up;     //上箭头键
	button button_down;   //下箭头键
	button button_left;   //左箭头键
	button button_right;  //右箭头键
	button button_q;      //功能键Q
	button button_r;      //功能键R
	button button_s;      //功能键S
	button button_d;      //功能键D
	button button_o;      //功能键O
public:
	void set_button_type();   //给按键设置种类
	void set_button_coord();  //给按键坐标赋值
	void print();  //打印小键盘
	int mouse_if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	int keyboard_if_button(const int keycode1, const int keycode2);  //判断键盘按下的按键是否为小键盘上的某一按键
	void selective_default(const int selection);   //选择性地为某一按键取消高亮
	void selective_activate(const int selection);  //选择性地为某一按键设置高亮
	int control();  //用键鼠在小键盘上进行操作
};