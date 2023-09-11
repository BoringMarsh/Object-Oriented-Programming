#pragma once
#include"interface-button.h"

//读设置对话框键鼠操作的返回值
#define OPBX_RET_SURE    1  //确定
#define OPBX_RET_CANCEL  2  //取消

//设置对话框的颜色
#define OPBX_BG_COLOR    COLOR_HBLACK
#define OPBX_FG_COLOR_A  COLOR_HWHITE
#define OPBX_FG_COLOR_D  COLOR_BLACK

//设置对话框各部分的坐标
#define OPBX_COORD_X  29  //设置对话框左上角横坐标
#define OPBX_COORD_Y  10  //设置对话框左上角纵坐标
#define OPPROM_COORD_X1  OPBX_COORD_X+2    //设置对话框中，提示语1左上角横坐标
#define OPPROM_COORD_Y1  OPBX_COORD_Y+2    //设置对话框中，提示语1左上角纵坐标
#define OPPROM_COORD_X2  OPBX_COORD_X+2    //设置对话框中，提示语2左上角横坐标
#define OPPROM_COORD_Y2  OPBX_COORD_Y+6    //设置对话框中，提示语2左上角纵坐标
#define SETSOUND_COORD_X  OPBX_COORD_X+4   //设置对话框中，声音设置框左上角横坐标
#define SETSOUND_COORD_Y  OPBX_COORD_Y+3   //设置对话框中，声音设置框左上角纵坐标
#define SETFONT_COORD_X   OPBX_COORD_X+14  //设置对话框中，字体大小设置框左上角横坐标
#define SETFONT_COORD_Y   OPBX_COORD_Y+3   //设置对话框中，字体大小设置框左上角纵坐标
#define OPSURE_COORD_X    OPBX_COORD_X+4   //设置对话框中，“确定”键左上角横坐标
#define OPSURE_COORD_Y    OPBX_COORD_Y+7   //设置对话框中，“确定”键左上角纵坐标
#define OPCANCEL_COORD_X  OPBX_COORD_X+14  //设置对话框中，“取消”键左上角横坐标
#define OPCANCEL_COORD_Y  OPBX_COORD_Y+7   //设置对话框中，“取消”键左上角纵坐标

//设置对话框按键数
#define OPBX_BUTTON_NUM  4

class optionsbox {
private:
	button button_setsound;  //声音设置框
	button button_setfont;   //字体大小设置框
	button button_sure;      //“确定”键
	button button_cancel;    //“取消”键
	bool if_sound;   //是否有声音（操作输入框时改变此值，结束后再赋给实参）
	int fontsize;    //字体大小（操作输入框时改变此值，结束后再赋给实参）
	const int OPBX_WIDTH;  //设置对话框的宽度
public:
	int get_width();  //取设置对话框宽度
	bool get_if_sound();  //取是否有声音
	int get_fontsize();   //取字体大小
	char* read_fontsize(char* String);  //读取字体大小并转换成字符串
	void print(const char* prompt);  //打印设置对话框
	int mouse_if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	void selective_default(const int selection);    //选择性地为某一按键取消高亮
	void selective_activate(const int selection);   //选择性地为某一按键设置高亮
	void move_cursor(const bool pblock, const int ppos);  //根据操作变量情况及位数，移动光标至相应位置
	void keyboard_input(const bool pblock, const int ppos, const int keycode);    //根据操作变量情况、位数、键盘输入值，改变对应变量的值
	int info_check();  //检查键盘输入量是否合理
	int control(bool* IF_SOUND, int* FONTSIZE);  //用键鼠在设置对话框内进行操作

	//构造函数
	optionsbox() :button_setsound(SETSOUND_COORD_X, SETSOUND_COORD_Y, OPBX_SETSOUND),
		button_setfont(SETFONT_COORD_X, SETFONT_COORD_Y, OPBX_SETFONT),
		button_sure(OPSURE_COORD_X, OPSURE_COORD_Y, OPBX_SURE),
		button_cancel(OPCANCEL_COORD_X, OPCANCEL_COORD_Y, OPBX_CANCEL),
		if_sound(true), fontsize(28), OPBX_WIDTH(10) {}
};