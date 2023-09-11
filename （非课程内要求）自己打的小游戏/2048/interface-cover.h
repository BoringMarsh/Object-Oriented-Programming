#pragma once
#include"90-b3.h"

//读标题画面键鼠操作的返回值
#define COVER_NEW     0x1001  //新游戏
#define COVER_LOAD    0x1002  //载入游戏
#define COVER_AUTO    0x1003  //自动游戏
#define COVER_OPTIONS 0x1004  //设置
#define COVER_ABOUT   0x1005  //关于
#define COVER_QUIT    0x1006  //退出游戏

//标题画面内各部分的坐标
#define TWO_COORD_X      6   //数字2左上角横坐标
#define TWO_COORD_Y      2   //数字2左上角纵坐标
#define ZERO_COORD_X     15  //数字0左上角横坐标
#define ZERO_COORD_Y     4   //数字0左上角纵坐标
#define FOUR_COORD_X     24  //数字4左上角横坐标
#define FOUR_COORD_Y     2   //数字4左上角纵坐标
#define EIGHT_COORD_X    33  //数字8左上角横坐标
#define EIGHT_COORD_Y    4   //数字8左上角纵坐标
#define CVVER_COORD_X    38  //封面版本号左上角横坐标
#define CVVER_COORD_Y    22  //封面版本号左上角纵坐标
#define NEW_COORD_X      8   //“新游戏”键左上角横坐标
#define NEW_COORD_Y      12  //“新游戏”键左上角纵坐标
#define LOAD_COORD_X     24  //“载入游戏”键左上角横坐标
#define LOAD_COORD_Y     12  //“载入游戏”键左上角纵坐标
#define AUTO_COORD_X     8   //“自动游戏”键左上角横坐标
#define AUTO_COORD_Y     16  //“自动游戏”键左上角纵坐标
#define OPTIONS_COORD_X  24  //“设置”键左上角纵坐标
#define OPTIONS_COORD_Y  16  //“设置”键左上角纵坐标
#define ABOUT_COORD_X    8   //“关于”键左上角横坐标
#define ABOUT_COORD_Y    20  //“关于”键左上角纵坐标
#define QUIT_COORD_X     24  //“退出游戏”键左上角横坐标
#define QUIT_COORD_Y     20  //“退出游戏”键左上角纵坐标

//标题画面按键数
#define COVER_BUTTON_NUM 6

/*标题画面类的声明*/
class cover {
private:
	button button_new;      //“新游戏”键
	button button_load;     //“载入游戏”键
	button button_auto;     //“自动游戏”键
	button button_options;  //“设置”键
	button button_about;    //“关于”键
	button button_quit;     //“退出游戏”键
	const int COVER_WIDTH = 24;      //标题画面宽度
public:
	void set_button_type();   //给按键设置种类
	void set_button_coord();  //给按键坐标赋值
	void print();  //打印标题画面
	int if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	void selective_default(const int selection);   //选择性地为某一按键取消高亮
	void selective_activate(const int selection);  //选择性地为某一按键设置高亮
	int control();  //用键鼠在标题画面上进行操作
};