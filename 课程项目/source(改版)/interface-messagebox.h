#pragma once
#include<iostream>
#include"interface-button.h"

//对话框按键形式
#define BUTTON_ONE     0x20001  //单键式（确定）
#define BUTTON_TWO     0x20002  //双键式（是否）
#define BUTTON_FIVE    0x20003  //五键式（1-4、取消）
#define BUTTON_SWITCH  0x20004  //开关式（开启关闭）

//读游戏内对话框键鼠操作的返回值
#define GMMB_RET_YES        0x3101  //按“是”键
#define GMMB_RET_NO         0x3102  //按“否”键
#define GMMB_RET_SURE       0x3103  //按“确定”键
#define GMMB_RET_ONE        0x3104  //按“1”键
#define GMMB_RET_TWO        0x3105  //按“2”键
#define GMMB_RET_THREE      0x3106  //按“3”键
#define GMMB_RET_FOUR       0x3107  //按“4”键
#define GMMB_RET_CANCEL     0x3108  //按“取消”键
#define GMMB_RET_BLINK_OFF  0x3109  //关闭色块闪烁
#define GMMB_RET_BLINK_ON   0x310a  //开启色块闪烁
#define GMMB_RET_SHOW_OFF   0x310b  //关闭清除效果
#define GMMB_RET_SHOW_ON    0x310c  //开启清除效果

//游戏内对话框各部分的坐标（用阶数表示）
#define GMMB_COORD_X      33  //游戏内对话框左上角横坐标
#define GMMB_COORD_Y      19  //游戏内对话框左上角纵坐标
#define GMPROM_COORD_X    GMMB_COORD_X+2   //游戏内对话框中，提示语左上角横坐标
#define GMPROM_COORD_Y    GMMB_COORD_Y+1   //游戏内对话框中，提示语左上角纵坐标
#define GMYES_COORD_X     GMMB_COORD_X+6   //游戏内对话框中，按键“是”左上角横坐标
#define GMYES_COORD_Y     GMMB_COORD_Y+4   //游戏内对话框中，按键“是”左上角纵坐标
#define GMNO_COORD_X      GMMB_COORD_X+18  //游戏内对话框中，按键“否”左上角横坐标
#define GMNO_COORD_Y      GMMB_COORD_Y+4   //游戏内对话框中，按键“否”左上角纵坐标
#define GMSURE_COORD_X    GMMB_COORD_X+11  //游戏内对话框中，按键“确定”左上角横坐标
#define GMSURE_COORD_Y    GMMB_COORD_Y+5   //游戏内对话框中，按键“确定”左上角纵坐标
#define GMONE_COORD_X     GMMB_COORD_X+4   //游戏内对话框中，按键“1”左上角横坐标
#define GMONE_COORD_Y     GMMB_COORD_Y+3   //游戏内对话框中，按键“1”左上角纵坐标
#define GMTWO_COORD_X     GMMB_COORD_X+10  //游戏内对话框中，按键“2”左上角横坐标
#define GMTWO_COORD_Y     GMMB_COORD_Y+3   //游戏内对话框中，按键“2”左上角纵坐标
#define GMTHREE_COORD_X   GMMB_COORD_X+4   //游戏内对话框中，按键“3”左上角横坐标
#define GMTHREE_COORD_Y   GMMB_COORD_Y+5   //游戏内对话框中，按键“3”左上角纵坐标
#define GMFOUR_COORD_X    GMMB_COORD_X+10  //游戏内对话框中，按键“4”左上角横坐标
#define GMFOUR_COORD_Y    GMMB_COORD_Y+5   //游戏内对话框中，按键“4”左上角纵坐标
#define GMCANCEL_COORD_X  GMMB_COORD_X+18  //游戏内对话框中，按键“取消”左上角横坐标
#define GMCANCEL_COORD_Y  GMMB_COORD_Y+5   //游戏内对话框中，按键“取消”左上角纵坐标
#define GMSW11_COORD_X    GMMB_COORD_X+2   //游戏内对话框中，开关1按键1左上角横坐标
#define GMSW11_COORD_Y    GMMB_COORD_Y+2   //游戏内对话框中，开关1按键1左上角纵坐标
#define GMSW12_COORD_X    GMMB_COORD_X+8   //游戏内对话框中，开关1按键2左上角横坐标
#define GMSW12_COORD_Y    GMMB_COORD_Y+2   //游戏内对话框中，开关1按键2左上角纵坐标
#define GMSW1P_COORD_X    GMMB_COORD_X+10  //游戏内对话框中，开关1状态标志左上角横坐标
#define GMSW1P_COORD_Y    GMMB_COORD_Y+3   //游戏内对话框中，开关1状态标志左上角纵坐标
#define GMSW21_COORD_X    GMMB_COORD_X+14  //游戏内对话框中，开关2按键1左上角横坐标
#define GMSW21_COORD_Y    GMMB_COORD_Y+2   //游戏内对话框中，开关2按键1左上角纵坐标
#define GMSW22_COORD_X    GMMB_COORD_X+20  //游戏内对话框中，开关2按键2左上角横坐标
#define GMSW22_COORD_Y    GMMB_COORD_Y+2   //游戏内对话框中，开关2按键2左上角纵坐标
#define GMSW2P_COORD_X    GMMB_COORD_X+22  //游戏内对话框中，开关2状态标志左上角横坐标
#define GMSW2P_COORD_Y    GMMB_COORD_Y+3   //游戏内对话框中，开关2状态标志左上角纵坐标

//游戏内对话框按键数
#define GMMB_BUTTON_NUM 12

//需作为参数类型的提前声明
class player;
class ball;

/*游戏内对话框类的声明*/
class game_messagebox {
private:
	button button_yes   { GMYES_COORD_X,GMYES_COORD_Y,GMMB_YES };           //“是”键
	button button_no    { GMNO_COORD_X,GMNO_COORD_Y,GMMB_NO };              //“否”键
	button button_sure  { GMSURE_COORD_X,GMSURE_COORD_Y,GMMB_SURE };        //“确认”键
	button button_one   { GMONE_COORD_X,GMONE_COORD_Y,GMMB_ONE };           //“1”键
	button button_two   { GMTWO_COORD_X,GMTWO_COORD_Y,GMMB_TWO };           //“2”键
	button button_three { GMTHREE_COORD_X,GMTHREE_COORD_Y,GMMB_THREE };     //“3”键
	button button_four  { GMFOUR_COORD_X,GMFOUR_COORD_Y,GMMB_FOUR };        //“4”键
	button button_cancel{ GMCANCEL_COORD_X,GMCANCEL_COORD_Y,GMMB_CANCEL };  //“取消”键
	button switch_one[2]{ {GMSW11_COORD_X,GMSW11_COORD_Y,GMMB_SW11},{GMSW12_COORD_X,GMSW12_COORD_Y,GMMB_SW12} };  //开关1的两个按钮
	button switch_two[2]{ {GMSW21_COORD_X,GMSW21_COORD_Y,GMMB_SW21},{GMSW22_COORD_X,GMSW22_COORD_Y,GMMB_SW22} };  //开关2的两个按钮
	int IF_GMMB;  //游戏内对话框状态（为零则不出现，不为零则数值对应按键形式）
	const int GMMB_BG_COLOR;  //游戏内对话框背景色
	const int GMMB_FG_COLOR;  //游戏内对话框前景色
	const int GMMB_WIDTH;     //游戏内对话框宽度
public:
	void print(const int button_mode, const char* prompt1 = NULL, const char* prompt2 = NULL, const char* prompt3 = NULL);  //打印游戏内对话框
	int mouse_if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	int keyboard_if_button(const int keycode);      //判断键盘按下的按键是否为对话框内的某一按键
	void selective_default(const int selection);    //选择性地为某一按键取消高亮
	void selective_activate(const int selection);   //选择性地为某一按键设置高亮
	int control(bool* if_sound);  //用键鼠在游戏内对话框内进行操作
	void erase(player& client, ball b[]);   //重画游戏面板，达到擦除对话框的效果
	void options(const int options);  //完成标题画面对话框中的各种设置

	game_messagebox() :IF_GMMB(0), GMMB_BG_COLOR(COLOR_HBLUE), GMMB_FG_COLOR(COLOR_BLACK), GMMB_WIDTH(8) {}  //构造函数
};

//读标题画面对话框键鼠操作的返回值
#define CVMB_RET_YES     0x3201  //按“是”键
#define CVMB_RET_NO      0x3202  //按“否”键
#define CVMB_RET_SURE    0x3203  //按“确定”键
#define CVMB_RET_ONE     0x3204  //按“1”键
#define CVMB_RET_TWO     0x3205  //按“2”键
#define CVMB_RET_THREE   0x3206  //按“3”键
#define CVMB_RET_FOUR    0x3207  //按“4”键
#define CVMB_RET_CANCEL  0x3208  //按“取消”键

//标题画面对话框各部分的坐标（用阶数表示）
#define CVMB_COORD_X      27  //标题画面对话框左上角横坐标
#define CVMB_COORD_Y      11  //标题画面对话框左上角纵坐标
#define CVPROM_COORD_X    CVMB_COORD_X+2   //标题画面对话框中，提示语左上角横坐标
#define CVPROM_COORD_Y    CVMB_COORD_Y+1   //标题画面对话框中，提示语左上角纵坐标
#define CVYES_COORD_X     CVMB_COORD_X+6   //标题画面对话框中，按键“是”左上角横坐标
#define CVYES_COORD_Y     CVMB_COORD_Y+4   //标题画面对话框中，按键“是”左上角纵坐标
#define CVNO_COORD_X      CVMB_COORD_X+18  //标题画面对话框中，按键“否”左上角横坐标
#define CVNO_COORD_Y      CVMB_COORD_Y+4   //标题画面对话框中，按键“否”左上角纵坐标
#define CVSURE_COORD_X    CVMB_COORD_X+11  //标题画面对话框中，按键“确定”左上角横坐标
#define CVSURE_COORD_Y    CVMB_COORD_Y+5   //标题画面对话框中，按键“确定”左上角纵坐标
#define CVONE_COORD_X     CVMB_COORD_X+4   //标题画面对话框中，按键“1”左上角横坐标
#define CVONE_COORD_Y     CVMB_COORD_Y+3   //标题画面对话框中，按键“1”左上角纵坐标
#define CVTWO_COORD_X     CVMB_COORD_X+10  //标题画面对话框中，按键“2”左上角横坐标
#define CVTWO_COORD_Y     CVMB_COORD_Y+3   //标题画面对话框中，按键“2”左上角纵坐标
#define CVTHREE_COORD_X   CVMB_COORD_X+4   //标题画面对话框中，按键“3”左上角横坐标
#define CVTHREE_COORD_Y   CVMB_COORD_Y+5   //标题画面对话框中，按键“3”左上角纵坐标
#define CVFOUR_COORD_X    CVMB_COORD_X+10  //标题画面对话框中，按键“4”左上角横坐标
#define CVFOUR_COORD_Y    CVMB_COORD_Y+5   //标题画面对话框中，按键“4”左上角纵坐标
#define CVCANCEL_COORD_X  CVMB_COORD_X+18  //标题画面对话框中，按键“取消”左上角横坐标
#define CVCANCEL_COORD_Y  CVMB_COORD_Y+5   //标题画面对话框中，按键“取消”左上角纵坐标

//标题画面对话框按键数
#define CVMB_BUTTON_NUM 8

//需作为参数类型的提前声明
class cover;

/*标题画面对话框类的声明*/
class cover_messagebox {
private:
	button button_yes   { CVYES_COORD_X,CVYES_COORD_Y,CVMB_YES };           //“是”键
	button button_no    { CVNO_COORD_X,CVNO_COORD_Y,CVMB_NO };              //“否”键
	button button_sure  { CVSURE_COORD_X,CVSURE_COORD_Y,CVMB_SURE };        //“确认”键
	button button_one   { CVONE_COORD_X,CVONE_COORD_Y,CVMB_ONE };           //“1”键
	button button_two   { CVTWO_COORD_X,CVTWO_COORD_Y,CVMB_TWO };           //“2”键
	button button_three { CVTHREE_COORD_X,CVTHREE_COORD_Y,CVMB_THREE };     //“3”键
	button button_four  { CVFOUR_COORD_X,CVFOUR_COORD_Y,CVMB_FOUR };        //“4”键
	button button_cancel{ CVCANCEL_COORD_X,CVCANCEL_COORD_Y,CVMB_CANCEL };  //“取消”键
	int IF_CVMB = 0;  //标题画面对话框状态（为零则不出现，不为零则数值对应按键形式）
	const int CVMB_BG_COLOR = COLOR_CYAN;   //标题画面对话框背景色
	const int CVMB_FG_COLOR = COLOR_BLACK;  //标题画面对话框前景色
	const int CVMB_WIDTH = 8;               //标题画面对话框宽度
public:
	void print(const int button_mode, const char* prompt1 = NULL, const char* prompt2 = NULL, const char* prompt3 = NULL, const char* prompt4 = NULL);  //打印标题画面对话框
	int mouse_if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	int keyboard_if_button(const int keycode);      //判断键盘按下的按键是否为对话框内的某一按键
	void selective_default(const int selection);    //选择性地为某一按键取消高亮
	void selective_activate(const int selection);   //选择性地为某一按键设置高亮
	int control(bool* if_sound);  //用键鼠在标题画面对话框内进行操作
	void erase(cover& TitleScreen);  //重画标题画面，达到擦除对话框的效果

	cover_messagebox() :IF_CVMB(0), CVMB_BG_COLOR(COLOR_CYAN), CVMB_FG_COLOR(COLOR_BLACK), CVMB_WIDTH(8) {}  //构造函数
};