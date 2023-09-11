#pragma once
#include"interface-button.h"

//对话框按键形式
#define BUTTON_TWO     0x007  //双键式（是否）
#define BUTTON_ONE     0x008  //单键式（确定）

//读游戏内对话框键鼠操作的返回值
#define GMMB_RET_YES        0x3101  //按“是”键
#define GMMB_RET_NO         0x3102  //按“否”键
#define GMMB_RET_SURE       0x3103  //按“确定”键

//游戏内对话框各部分的坐标（用阶数表示）
#define GMMB_COORD_X      (row % 2 ? 6 * (row / 2) - 8 : 6 * (row / 2) - 11)  //游戏内对话框左上角横坐标
#define GMMB_COORD_Y      (line % 2 ? 3 * (line / 2) + 10 : 3 * (line / 2) + 7)  //游戏内对话框左上角纵坐标
#define GMPROM_COORD_X    GMMB_COORD_X+2   //游戏内对话框中，提示语左上角横坐标
#define GMPROM_COORD_Y    GMMB_COORD_Y+1   //游戏内对话框中，提示语左上角纵坐标
#define GMYES_COORD_X     GMMB_COORD_X+6   //游戏内对话框中，按键“是”左上角横坐标
#define GMYES_COORD_Y     GMMB_COORD_Y+4   //游戏内对话框中，按键“是”左上角纵坐标
#define GMNO_COORD_X      GMMB_COORD_X+18  //游戏内对话框中，按键“否”左上角横坐标
#define GMNO_COORD_Y      GMMB_COORD_Y+4   //游戏内对话框中，按键“否”左上角纵坐标
#define GMSURE_COORD_X    GMMB_COORD_X+11  //游戏内对话框中，按键“确定”左上角横坐标
#define GMSURE_COORD_Y    GMMB_COORD_Y+4   //游戏内对话框中，按键“确定”左上角纵坐标

//游戏内对话框按键数
#define GMMB_BUTTON_NUM 3

/*游戏内对话框类的声明*/
class game_mailbox {
private:
	button button_yes   { 0,0,GMMB_YES };     //“是”键
	button button_no    { 0,0,GMMB_NO };      //“否”键
	button button_sure  { 0,0,GMMB_SURE };    //“确定”键
	int IF_GMMB;        //游戏内对话框状态（为零则不出现，不为零则数值对应按键形式）
	const int GMMB_BG_COLOR;  //游戏内对话框背景色
	const int GMMB_FG_COLOR;  //游戏内对话框前景色
	const int GMMB_WIDTH;     //游戏内对话框宽度
public:
	void set_button_coord(const int line, const int row);  //给按键坐标赋值
	void print(const int button_mode, const int line, const int row, const char* prompt1 = NULL, const char* prompt2 = NULL, const char* prompt3 = NULL);  //打印游戏内对话框
	int mouse_if_button(const int X, const int Y, const int line, const int row);  //判断鼠标位置是否在某一按键上
	int keyboard_if_button(const int keycode);      //判断键盘按下的按键是否为对话框内的某一按键
	void selective_default(const int selection);    //选择性地为某一按键取消高亮
	void selective_activate(const int selection);   //选择性地为某一按键设置高亮
	int control(const int line, const int row);  //用键鼠在游戏内对话框内进行操作
	void erase(const struct matrix MATRIX[], const int line, const int row);   //重画游戏面板，达到擦除对话框的效果（参数一定要加struct，否则报错!!!）
	void options(const int options);  //完成标题画面对话框中的各种设置

	//构造函数
	game_mailbox() :button_yes(0, 0, GMMB_YES),
		button_no(0, 0, GMMB_NO),
		button_sure(0, 0, GMMB_SURE),
		IF_GMMB(0), GMMB_BG_COLOR(COLOR_HBLUE), GMMB_FG_COLOR(COLOR_BLACK), GMMB_WIDTH(7) {}
};