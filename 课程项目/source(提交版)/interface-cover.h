#pragma once
#include"interface-button.h"

//读标题画面键鼠操作的返回值
#define COVER_RET_NEW      0x2001  //新游戏
#define COVER_RET_LOAD     0x2002  //载入游戏
#define COVER_RET_OPTIONS  0x2003  //设置
#define COVER_RET_HELP     0x2004  //帮助
#define COVER_RET_ABOUT    0x2005  //关于
#define COVER_RET_EXIT     0x2006  //退出游戏

//标题画面内各部分的坐标
#define C_COORD_X   8   //字母C左上角横坐标
#define C_COORD_Y   2   //字母C左上角纵坐标
#define O_COORD_X1  17  //第一个字母O左上角横坐标
#define O_COORD_Y1  4   //第一个字母O左上角纵坐标
#define L_COORD_X1  26  //第一个字母L左上角横坐标
#define L_COORD_Y1  2   //第一个字母L左上角纵坐标
#define O_COORD_X2  35  //第二个字母O左上角横坐标
#define O_COORD_Y2  4   //第二个字母O左上角纵坐标
#define R_COORD_X   44  //字母R左上角横坐标
#define R_COORD_Y   2   //字母R左上角纵坐标
#define B_COORD_X   36  //字母B左上角横坐标
#define B_COORD_Y   11  //字母B左上角纵坐标
#define A_COORD_X   46  //字母A左上角横坐标
#define A_COORD_Y   11  //字母A左上角纵坐标
#define L_COORD_X2  59  //第二个字母L左上角横坐标
#define L_COORD_Y2  11  //第二个字母L左上角纵坐标
#define L_COORD_X3  68  //第三个字母L左上角横坐标
#define L_COORD_Y3  11  //第三个字母L左上角纵坐标
#define NEW_COORD_X    15  //“新游戏”键左上角横坐标
#define NEW_COORD_Y    18  //“新游戏”键左上角纵坐标
#define LOAD_COORD_X   34  //“载入游戏”键左上角横坐标
#define LOAD_COORD_Y   18  //“载入游戏”键左上角纵坐标
#define CVOP_COORD_X   53  //“设置”键左上角横坐标
#define CVOP_COORD_Y   18  //“设置”键左上角纵坐标
#define HELP_COORD_X   15  //“帮助”键左上角横坐标
#define HELP_COORD_Y   23  //“帮助”键左上角纵坐标
#define ABOUT_COORD_X  34  //“关于”键左上角横坐标
#define ABOUT_COORD_Y  23  //“关于”键左上角纵坐标
#define EXIT_COORD_X   53  //“退出”键左上角横坐标
#define EXIT_COORD_Y   23  //“退出”键左上角纵坐标

//标题画面各字母颜色
#define C_COLOR    COLOR_RED     //字母C的颜色
#define O_COLOR1   COLOR_YELLOW  //第一个字母O的颜色
#define L_COLOR    COLOR_BLUE    //第一个字母L的颜色
#define O_COLOR2   COLOR_GREEN   //第二个字母O的颜色
#define R_COLOR    COLOR_PINK    //字母R的颜色
#define BALL_COLOR COLOR_CYAN    //单词BALL的颜色

//标题画面按键数
#define COVER_BUTTON_NUM  6

//打印所有字母
#define PRINT_ALL_LETTERS C_print();O_print(1);L_print(1);O_print(2);R_print();B_print();A_print();L_print(2);L_print(3)

//打印所有珠子
#define PRINT_ALL_BALLS ball_print(2, 24, COLOR_RED);ball_print(5, 10, COLOR_YELLOW);ball_print(22, 13, COLOR_GREEN);ball_print(60, 5, COLOR_BLUE);ball_print(72, 1, COLOR_HYELLOW);ball_print(72, 21, COLOR_PINK)

//需作为友元类的提前声明
class cover_messagebox;
class optionsbox;

/*标题画面类的声明*/
class cover {
private:
	button button_new    { NEW_COORD_X,NEW_COORD_Y,CV_NEW };        //“新游戏”键
	button button_load   { LOAD_COORD_X,LOAD_COORD_Y,CV_LOAD };     //“载入游戏”键
	button button_options{ CVOP_COORD_X,CVOP_COORD_Y,CV_OPTIONS };  //“设置”键
	button button_help   { HELP_COORD_X,HELP_COORD_Y,CV_HELP };     //“帮助”键
	button button_about  { ABOUT_COORD_X,ABOUT_COORD_Y,CV_ABOUT };  //“关于”键
	button button_exit   { EXIT_COORD_X,EXIT_COORD_Y,CV_EXIT };     //“退出”键
	const int COVER_WIDTH;  //标题画面宽度
	int last_button;  //上一次鼠标所在的按键
public:
	void C_print();  //打印一个字母C
	void O_print(const int O_num);  //打印一个字母O
	void L_print(const int L_num);  //打印一个字母L
	void R_print();  //打印一个字母R
	void B_print();  //打印一个字母B
	void A_print();  //打印一个字母A
	void ball_print(const int X, const int Y, const int bg_color);  //打印一个珠子
	void print();  //打印标题画面
	int if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	void selective_default(const int selection);   //选择性地为某一按键取消高亮
	void selective_activate(const int selection);  //选择性地为某一按键设置高亮
	int control(bool* if_sound);  //用键鼠在标题画面上进行操作

	cover() :COVER_WIDTH(30), last_button(0) {}  //构造函数

	//友元类的声明
	friend class cover_messagebox;
	friend class optionsbox;
};