#pragma once
#include"cmd_console_tools.h"

//按键效果种类
#define ACTIVATE     0x10001  //某一按键设置高亮
#define DEFAULT      0x10002  //某一按键取消高亮
#define DEFAULT_ALL  0x10003  //所有按键取消高亮

//游戏内对话框按键颜色
#define GMMB_KEYS_BG_COLOR COLOR_HBLUE
#define GMMB_KEYS_FG_COLOR_A COLOR_HWHITE
#define GMMB_KEYS_FG_COLOR_D COLOR_BLACK

//输入框的颜色
#define IPBX_BG_COLOR    COLOR_YELLOW  //背景色
#define IPBX_FG_COLOR_A  COLOR_HWHITE  //高亮前景色
#define IPBX_FG_COLOR_D  COLOR_BLACK   //正常前景色

//设置对话框的颜色
#define OPBX_BG_COLOR    COLOR_HBLACK
#define OPBX_FG_COLOR_A  COLOR_HWHITE
#define OPBX_FG_COLOR_D  COLOR_BLACK

//游戏内对话框按键种类
#define GMMB_YES  1001  //“是”键
#define GMMB_NO   1002  //“否”键
#define GMMB_SURE 1003  //“确定”键

//标题画面按键种类
#define CV_EASY     2001  //“简单”键
#define CV_MEDIUM   2002  //“中等”键
#define CV_HARD     2003  //“困难”键
#define CV_DIY      2004  //“自定义”键
#define CV_OPTIONS  2005  //“设置”键
#define CV_QUIT     2006  //“退出”键

//输入框按键种类
#define IPBX_IPLINE  3001  //行数输入框
#define IPBX_IPROW   3002  //列数输入框
#define IPBX_IPBOMB  3003  //地雷数输入框
#define IPBX_SURE    3004  //“确定”键
#define IPBX_CANCEL  3005  //“取消”键

//设置对话框按键种类
#define OPBX_SETSOUND  4001  //声音设置框
#define OPBX_SETFONT   4002  //字体大小设置框
#define OPBX_SURE      4003  //“确定”键
#define OPBX_CANCEL    4004  //“取消”键

/*按键类的声明*/
class button {
private:
	int x;         //按键左上角横坐标
	int y;         //按键左上角纵坐标
	int bg_color;  //按键背景色
	int fg_color;  //按键前景色
	int type;      //按键种类
public:
	void set_color(const int BG_COLOR, const int FG_COLOR);  //给按键设置颜色
	void set_coord(const int X, const int Y);  //给按键设置左上角坐标
	void set_type(const int TYPE);  //给按键设置种类
	void act(const int act_mode);   //根据按键的种类表现按键效果

	button(const int X, const int Y, const int TYPE) :x(X), y(Y), type(TYPE) {  //构造函数
		bg_color = COLOR_BLACK;
		fg_color = COLOR_BLACK;
	}
};