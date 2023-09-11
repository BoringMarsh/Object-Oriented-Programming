#pragma once
#include"interface-button.h"

//读标题画面键鼠操作的返回值
#define COVER_EASY     0x1001  //简单
#define COVER_MEDIUM   0x1002  //中等
#define COVER_HARD     0x1003  //困难
#define COVER_DIY      0x1004  //自定义
#define COVER_OPTIONS  0x1005  //设置
#define COVER_QUIT     0x1006  //退出游戏

//标题画面内各部分的坐标
#define M_COORD_X   15            //字母M左上角横坐标
#define M_COORD_Y   2             //字母M左上角纵坐标
#define I_COORD_X   M_COORD_X+17  //字母I左上角横坐标
#define I_COORD_Y   2             //字母I左上角纵坐标
#define N_COORD_X   M_COORD_X+30  //字母N左上角横坐标
#define N_COORD_Y   2             //字母N左上角纵坐标
#define E_COORD_X1  M_COORD_X+45  //第一个字母E左上角横坐标
#define E_COORD_Y1  2             //第一个字母E左上角纵坐标
#define S_COORD_X   5             //字母S左上角横坐标
#define S_COORD_Y   9             //字母S左上角纵坐标
#define W_COORD_X   S_COORD_X+10  //字母W左上角横坐标
#define W_COORD_Y   11            //字母W左上角纵坐标
#define E_COORD_X2  S_COORD_X+24  //第二个字母E左上角横坐标
#define E_COORD_Y2  9             //第二个字母E左上角纵坐标
#define E_COORD_X3  S_COORD_X+34  //第三个字母E左上角横坐标
#define E_COORD_Y3  11            //第三个字母E左上角纵坐标
#define P_COORD_X   S_COORD_X+44  //字母P左上角横坐标
#define P_COORD_Y   9             //字母P左上角纵坐标
#define E_COORD_X4  S_COORD_X+54  //第四个字母E左上角横坐标
#define E_COORD_Y4  11            //第四个字母E左上角纵坐标
#define R_COORD_X   S_COORD_X+64  //字母R左上角横坐标
#define R_COORD_Y   9             //字母R左上角纵坐标
#define EASY_COORD_X     15  //“简单”键左上角横坐标
#define EASY_COORD_Y     18  //“简单”键左上角纵坐标
#define MEDIUM_COORD_X   34  //“中等”键左上角横坐标
#define MEDIUM_COORD_Y   18  //“中等”键左上角纵坐标
#define HARD_COORD_X     53  //“困难”键左上角横坐标
#define HARD_COORD_Y     18  //“困难”键左上角纵坐标
#define DIY_COORD_X      15  //“自定义”键左上角横坐标
#define DIY_COORD_Y      23  //“自定义”键左上角纵坐标
#define OPTIONS_COORD_X  34  //“设置”键左上角横坐标
#define OPTIONS_COORD_Y  23  //“设置”键左上角纵坐标
#define QUIT_COORD_X     53  //“退出”键左上角横坐标
#define QUIT_COORD_Y     23  //“退出”键左上角纵坐标

//标题画面各字母颜色
#define S_COLOR  COLOR_RED     //字母S的颜色
#define W_COLOR  COLOR_YELLOW  //字母W的颜色
#define E_COLOR2 COLOR_BLUE    //第二个字母E的颜色
#define E_COLOR3 COLOR_GREEN   //第三个字母E的颜色
#define P_COLOR  COLOR_CYAN    //字母P的颜色
#define E_COLOR4 COLOR_PINK    //第四个字母E的颜色
#define R_COLOR  COLOR_HBLACK  //字母R的颜色

//标题画面按键数
#define COVER_BUTTON_NUM  6

//打印所有字母
#define PRINT_ALL_LETTERS M_print();I_print();N_print();E_print(1);S_print();W_print();E_print(2);E_print(3);P_print();E_print(4);R_print();

//存放标题画面地雷坐标的结构体
struct coord {
	int x;
	int y;
};

/*标题画面类的声明*/
class cover {
private:
	button button_easy;     //“简单”键
	button button_medium;   //“中等”键
	button button_hard;     //“困难”键
	button button_diy;      //“自定义”键
	button button_options;  //“设置”键
	button button_quit;     //“退出”键
	coord bomb_coord[20];   //各个地雷的坐标
	const int COVER_WIDTH;  //标题画面宽度
public:
	void M_print();  //打印一个字母M
	void I_print();  //打印一个字母I
	void N_print();  //打印一个字母N
	void E_print(const int E_num);  //打印一个字母E
	void S_print();  //打印一个字母S
	void W_print();  //打印一个字母W
	void P_print();  //打印一个字母P
	void R_print();  //打印一个字母R
	void bomb_print();  //打印地雷
	void bomb_reprint();  //根据第一次打印时存储的坐标信息，重新打印地雷
	void button_reprint();  //重新打印标题画面中的一些按键
	void print();  //打印标题画面
	int if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	void selective_default(const int selection);   //选择性地为某一按键取消高亮
	void selective_activate(const int selection);  //选择性地为某一按键设置高亮
	int control();  //用键鼠在标题画面上进行操作

	//构造函数
	cover() : button_easy(EASY_COORD_X, EASY_COORD_Y, CV_EASY),
		button_medium(MEDIUM_COORD_X, MEDIUM_COORD_Y, CV_MEDIUM),
		button_hard(HARD_COORD_X, HARD_COORD_Y, CV_HARD),
		button_diy(DIY_COORD_X, DIY_COORD_Y, CV_DIY),
		button_options(OPTIONS_COORD_X, OPTIONS_COORD_Y, CV_OPTIONS),
		button_quit(QUIT_COORD_X, QUIT_COORD_Y, CV_QUIT),
		COVER_WIDTH(30) 
	{
		for (int i = 0; i < 20; i++)
			bomb_coord[i].x = 0, bomb_coord[i].y = 0;
	}
};