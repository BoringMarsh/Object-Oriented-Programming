#pragma once
#include"cmd_console_tools.h"

//按键效果种类
#define ACTIVATE     0x10001  //某一按键设置高亮
#define DEFAULT      0x10002  //某一按键取消高亮
#define DEFAULT_ALL  0x10003  //所有按键取消高亮

//游戏内对话框按键颜色
#define GMMB_KEYS_BG_COLOR    COLOR_HBLUE   //背景色
#define GMMB_KEYS_FG_COLOR_A  COLOR_HWHITE  //高亮前景色
#define GMMB_KEYS_FG_COLOR_D  COLOR_BLACK   //正常前景色

//游戏内对话框开关按键颜色
#define GMMBSW_BG_COLOR_A  COLOR_HWHITE  //高亮背景色
#define GMMBSW_BG_COLOR_D  COLOR_HBLACK  //正常背景色
#define GMMBSW_FG_COLOR    COLOR_BLACK   //前景色

//标题画面对话框按键颜色
#define CVMB_KEYS_BG_COLOR    COLOR_CYAN    //背景色
#define CVMB_KEYS_FG_COLOR_A  COLOR_HWHITE  //高亮前景色
#define CVMB_KEYS_FG_COLOR_D  COLOR_BLACK   //正常前景色

//设置对话框的颜色
#define OPBX_BG_COLOR    COLOR_HBLACK  //背景色
#define OPBX_FG_COLOR_A  COLOR_HWHITE  //高亮前景色
#define OPBX_FG_COLOR_D  COLOR_BLACK   //正常前景色

//游戏内按键种类
#define GAME_OPTIONS  1001  //“设置”键
#define GAME_SAVE     1002  //“保存”键
#define GAME_DELETE   1003  //“删除”键
#define GAME_QUIT     1004  //“退出”键

//游戏内对话框按键种类
#define GMMB_YES     2001  //“是”键
#define GMMB_NO      2002  //“否”键
#define GMMB_SURE    2003  //“确定”键
#define GMMB_ONE     2004  //“1”键
#define GMMB_TWO     2005  //“2”键
#define GMMB_THREE   2006  //“3”键
#define GMMB_FOUR    2007  //“4”键
#define GMMB_CANCEL  2008  //“取消”键
#define GMMB_SW11    2009  //开关1按键1
#define GMMB_SW12    2010  //开关1按键2
#define GMMB_SW21    2011  //开关2按键1
#define GMMB_SW22    2012  //开关2按键2

//标题画面按键种类
#define CV_NEW      3001  //“新游戏”键
#define CV_LOAD     3002  //“载入游戏”键
#define CV_OPTIONS  3003  //“设置”键
#define CV_HELP     3004  //“帮助”键
#define CV_HS       3005  //“高分榜”键
#define CV_EXIT     3006  //“退出”键

//标题画面对话框按键种类
#define CVMB_YES     4001  //“是”键
#define CVMB_NO      4002  //“否”键
#define CVMB_SURE    4003  //“确定”键
#define CVMB_ONE     4004  //“1”键
#define CVMB_TWO     4005  //“2”键
#define CVMB_THREE   4006  //“3”键
#define CVMB_FOUR    4007  //“4”键
#define CVMB_CANCEL  4008  //“取消”键

//设置对话框按键种类
#define OPBX_SETBLINK  5001  //闪烁设置框
#define OPBX_SETSHOW   5002  //清除效果设置框
#define OPBX_SETSOUND  5003  //声音设置框
#define OPBX_SETFONT   5004  //字体大小设置框
#define OPBX_SURE      5005  //“确定”键
#define OPBX_CANCEL    5006  //“取消”键

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
	void act(const int act_mode);   //根据按键的种类表现按键效果

	button(const int X, const int Y, const int TYPE) :x(X), y(Y), type(TYPE) {  //构造函数
		bg_color = COLOR_BLACK;
		fg_color = COLOR_BLACK;
	}
};