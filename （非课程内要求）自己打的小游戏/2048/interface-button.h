#pragma once
#include"90-b3.h"

//游戏内对话框按键颜色
#define GMMB_KEYS_BG_COLOR COLOR_HBLUE
#define GMMB_KEYS_FG_COLOR_A COLOR_HWHITE
#define GMMB_KEYS_FG_COLOR_D COLOR_BLACK

//游戏内对话框开关按键颜色
#define GMMBSW_BG_COLOR_A COLOR_HWHITE
#define GMMBSW_BG_COLOR_D COLOR_HBLACK
#define GMMBSW_FG_COLOR COLOR_BLACK

//标题画面对话框按键颜色
#define CVMB_KEYS_BG_COLOR COLOR_CYAN
#define CVMB_KEYS_FG_COLOR_A COLOR_HWHITE
#define CVMB_KEYS_FG_COLOR_D COLOR_BLACK

//标题画面对话框开关按键颜色
#define CVMBSW_BG_COLOR_A COLOR_HWHITE
#define CVMBSW_BG_COLOR_D COLOR_HBLACK
#define CVMBSW_FG_COLOR COLOR_BLACK

/*按键类的声明*/
class button {
private:
	int x = -1;                  //按键左上角横坐标
	int y = -1;                  //按键左上角纵坐标
	int bg_color = COLOR_BLACK;  //按键背景色
	int fg_color = COLOR_BLACK;  //按键前景色
	int type = 0;                //按键种类
public:
	void set_color(const int BG_COLOR, const int FG_COLOR);  //给按键设置颜色
	void set_coord(const int X, const int Y);  //给按键设置左上角坐标
	void set_type(const int TYPE);  //给按键设置种类
	void act(const int act_mode);   //根据按键的种类表现按键效果
};