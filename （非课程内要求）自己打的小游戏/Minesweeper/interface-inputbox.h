#pragma once
#include"interface-button.h"

//读输入框键鼠操作的返回值
#define IPBX_RET_SURE    1  //确定
#define IPBX_RET_CANCEL  2  //取消

//输入框的颜色
#define IPBX_BG_COLOR    COLOR_YELLOW  //背景色
#define IPBX_FG_COLOR_A  COLOR_HWHITE  //高亮前景色
#define IPBX_FG_COLOR_D  COLOR_BLACK   //正常前景色

//输入框各部分的坐标
#define IPBX_COORD_X  24  //输入框左上角横坐标
#define IPBX_COORD_Y  10  //输入框左上角纵坐标
#define IPPROM_COORD_X1    IPBX_COORD_X+2  //输入框中，提示语1左上角横坐标
#define IPPROM_COORD_Y1    IPBX_COORD_Y+2  //输入框中，提示语1左上角纵坐标
#define IPPROM_COORD_X2    IPBX_COORD_X+2  //输入框中，提示语2左上角横坐标
#define IPPROM_COORD_Y2    IPBX_COORD_Y+6  //输入框中，提示语2左上角纵坐标
#define IPLINE_COORD_X    IPBX_COORD_X+4   //输入框中，行数输入框左上角横坐标
#define IPLINE_COORD_Y    IPBX_COORD_Y+3   //输入框中，行数输入框左上角纵坐标
#define IPROW_COORD_X     IPBX_COORD_X+14  //输入框中，列数输入框左上角横坐标
#define IPROW_COORD_Y     IPBX_COORD_Y+3   //输入框中，列数输入框左上角纵坐标
#define IPBOMB_COORD_X    IPBX_COORD_X+24  //输入框中，地雷数输入框左上角横坐标
#define IPBOMB_COORD_Y    IPBX_COORD_Y+3   //输入框中，地雷数输入框左上角纵坐标
#define IPSURE_COORD_X    IPBX_COORD_X+10  //输入框中，“确定”键左上角横坐标
#define IPSURE_COORD_Y    IPBX_COORD_Y+7   //输入框中，“确定”键左上角纵坐标
#define IPCANCEL_COORD_X  IPBX_COORD_X+20  //输入框中，“取消”键左上角横坐标
#define IPCANCEL_COORD_Y  IPBX_COORD_Y+7   //输入框中，“取消”键左上角纵坐标

//输入框按键数
#define IPBX_BUTTON_NUM  5

//输入框类的声明
class inputbox {
private:
	button button_ipline;  //行数输入框
	button button_iprow;   //列数输入框
	button button_ipbomb;  //地雷数输入框
	button button_sure;    //“确定”键
	button button_cancel;  //“取消”键
	int line;        //行数（操作输入框时改变此值，结束后再赋给实参）
	int row;         //列数（操作输入框时改变此值，结束后再赋给实参）
	int bomb_num;    //地雷数（操作输入框时改变此值，结束后再赋给实参）
	const int IPBX_WIDTH;  //输入框宽度
public:
	int get_width();  //取输入框宽度
	void print(const char* prompt);  //打印输入框
	int mouse_if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	void selective_default(const int selection);    //选择性地为某一按键取消高亮
	void selective_activate(const int selection);   //选择性地为某一按键设置高亮
	void move_cursor(const int pblock, const int ppos);  //根据正在操作的变量及位数，移动光标至相应位置
	void keyboard_input(const int pblock, const int ppos, const int keycode);  //根据正在操作的变量、位数、键盘输入值，改变对应变量的值
	int info_check();  //检查键盘输入量是否合理
	int control(int* LINE, int* ROW, int* BOMB_NUM);  //用键鼠在输入框内进行操作

	//构造函数
	inputbox() :button_ipline(IPLINE_COORD_X, IPLINE_COORD_Y, IPBX_IPLINE),
		button_iprow(IPROW_COORD_X, IPROW_COORD_Y, IPBX_IPROW),
		button_ipbomb(IPBOMB_COORD_X, IPBOMB_COORD_Y, IPBX_IPBOMB),
		button_sure(IPSURE_COORD_X, IPSURE_COORD_Y, IPBX_SURE),
		button_cancel(IPCANCEL_COORD_X, IPCANCEL_COORD_Y, IPBX_CANCEL),
		line(0), row(0), bomb_num(0), IPBX_WIDTH(10) {}
};