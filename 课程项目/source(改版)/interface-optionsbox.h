#pragma once
#include"interface-button.h"

//读设置对话框键鼠操作的返回值
#define OPBX_RET_SURE    0x4001  //确定
#define OPBX_RET_CANCEL  0x4002  //取消

//设置对话框的颜色
#define OPBX_BG_COLOR    COLOR_HBLACK  //背景色
#define OPBX_FG_COLOR_A  COLOR_HWHITE  //高亮前景色
#define OPBX_FG_COLOR_D  COLOR_BLACK   //正常前景色

//设置对话框各部分的坐标
#define OPBX_COORD_X  28  //设置对话框左上角横坐标
#define OPBX_COORD_Y  7   //设置对话框左上角纵坐标
#define OPPROM_COORD_X1  OPBX_COORD_X+2    //设置对话框中，提示语1左上角横坐标
#define OPPROM_COORD_Y1  OPBX_COORD_Y+2    //设置对话框中，提示语1左上角纵坐标
#define OPPROM_COORD_X2  OPBX_COORD_X+2    //设置对话框中，提示语2左上角横坐标
#define OPPROM_COORD_Y2  OPBX_COORD_Y+7    //设置对话框中，提示语2左上角纵坐标
#define OPPROM_COORD_X3  OPBX_COORD_X+2    //设置对话框中，提示语3左上角横坐标
#define OPPROM_COORD_Y3  OPBX_COORD_Y+11   //设置对话框中，提示语3左上角纵坐标
#define SETBLINK_COORD_X  OPBX_COORD_X+4   //设置对话框中，闪烁设置框左上角横坐标
#define SETBLINK_COORD_Y  OPBX_COORD_Y+3   //设置对话框中，闪烁设置框左上角纵坐标
#define SETSHOW_COORD_X   OPBX_COORD_X+14  //设置对话框中，清除效果设置框左上角横坐标
#define SETSHOW_COORD_Y   OPBX_COORD_Y+3   //设置对话框中，清除效果设置框左上角纵坐标
#define SETSOUND_COORD_X  OPBX_COORD_X+4   //设置对话框中，声音设置框左上角横坐标
#define SETSOUND_COORD_Y  OPBX_COORD_Y+8   //设置对话框中，声音设置框左上角纵坐标
#define SETFONT_COORD_X   OPBX_COORD_X+14  //设置对话框中，字体大小设置框左上角横坐标
#define SETFONT_COORD_Y   OPBX_COORD_Y+8   //设置对话框中，字体大小设置框左上角纵坐标
#define OPSURE_COORD_X    OPBX_COORD_X+4   //设置对话框中，“确定”键左上角横坐标
#define OPSURE_COORD_Y    OPBX_COORD_Y+12  //设置对话框中，“确定”键左上角纵坐标
#define OPCANCEL_COORD_X  OPBX_COORD_X+14  //设置对话框中，“取消”键左上角横坐标
#define OPCANCEL_COORD_Y  OPBX_COORD_Y+12  //设置对话框中，“取消”键左上角纵坐标

//设置对话框按键数
#define OPBX_BUTTON_NUM  6

//需作为参数类型的提前声明
class cover;

/*设置对话框类的声明*/
class optionsbox {
private:
	button button_setblink{ SETBLINK_COORD_X,SETBLINK_COORD_Y,OPBX_SETBLINK };  //闪烁设置框
	button button_setshow { SETSHOW_COORD_X,SETSHOW_COORD_Y,OPBX_SETSHOW };     //清除效果设置框
	button button_setsound{ SETSOUND_COORD_X,SETSOUND_COORD_Y,OPBX_SETSOUND };  //声音设置框
	button button_setfont { SETFONT_COORD_X,SETFONT_COORD_Y,OPBX_SETFONT };     //字体大小设置框
	button button_sure    { OPSURE_COORD_X,OPSURE_COORD_Y,OPBX_SURE };          //“确定”键
	button button_cancel  { OPCANCEL_COORD_X,OPCANCEL_COORD_Y,OPBX_CANCEL };    //“取消”键
	const int OPBX_WIDTH;  //设置对话框宽度

	/*以下成员在操作输入框时改变值，结束后再赋给实参*/
	bool if_blink;  //是否闪烁
	bool if_show;   //是否有清除效果
	bool if_sound;  //是否有声音
	int fontsize;   //字体大小
public:
	char* read_fontsize(char* String);  //读取字体大小并转换成字符串
	void print(const char* prompt1, const char* prompt2);  //打印设置对话框
	int mouse_if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	void selective_default(const int selection);    //选择性地为某一按键取消高亮
	void selective_activate(const int selection);   //选择性地为某一按键设置高亮
	void move_cursor(const bool pblock, const int ppos);  //根据操作变量情况及位数，移动光标至相应位置
	void keyboard_input(const bool pblock, const int ppos, const int keycode);    //根据操作变量情况、位数、键盘输入值，改变对应变量的值
	bool info_check();  //检查键盘输入量是否合理
	int control(bool* IF_SOUND, int* FONTSIZE);  //用键鼠在设置对话框内进行操作
	void erase(cover& TitleScreen);  //重画标题画面，达到擦除对话框的效果

	optionsbox() :if_blink(true), if_show(true), if_sound(true), fontsize(28), OPBX_WIDTH(15) {}  //构造函数
};