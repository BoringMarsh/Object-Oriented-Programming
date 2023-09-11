#pragma once
#include"90-b3.h"

//对话框按键形式
#define BUTTON_ONE     0x006  //单键式（确定）
#define BUTTON_TWO     0x007  //双键式（是否）
#define BUTTON_FIVE    0x008  //五键式（1-4、取消）
#define BUTTON_SWITCH  0x009  //开关式（开启关闭）

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
#define GMMB_RET_TIPS_OFF   0x310b  //关闭提示
#define GMMB_RET_TIPS_ON    0x310c  //开启提示

//游戏内对话框各部分的坐标（用阶数表示）
#define GMMB_COORD_X      4*__GAME.order-6  //游戏内对话框左上角横坐标
#define GMMB_COORD_Y      2*__GAME.order-1  //游戏内对话框左上角纵坐标
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

/*游戏内对话框类的声明*/
class game_mailbox {
private:
	button button_yes;     //“是”键
	button button_no;      //“否”键
	button button_sure;    //“确定”键
	button button_one;     //“1”键
	button button_two;     //“2”键
	button button_three;   //“3”键
	button button_four;    //“4”键
	button button_cancel;  //“取消”键
	button switch_one[2];  //开关1的两个按钮
	button switch_two[2];  //开关2的两个按钮
	int IF_GMMB = 0;       //游戏内对话框状态（为零则不出现，不为零则数值对应按键形式）
	const int GMMB_BG_COLOR = COLOR_HBLUE;  //游戏内对话框背景色
	const int GMMB_FG_COLOR = COLOR_BLACK;  //游戏内对话框前景色
	const int GMMB_WIDTH = 8;               //游戏内对话框宽度
public:
	void set_button_type();   //给按键设置种类
	void set_button_coord();  //给按键坐标赋值
	void print(const int button_mode, const char* prompt1 = NULL, const char* prompt2 = NULL, const char* prompt3 = NULL);  //打印游戏内对话框
	int mouse_if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	int keyboard_if_button(const int keycode);      //判断键盘按下的按键是否为对话框内的某一按键
	void selective_default(const int selection);    //选择性地为某一按键取消高亮
	void selective_activate(const int selection);   //选择性地为某一按键设置高亮
	int control();  //用键鼠在游戏内对话框内进行操作
	void erase();   //重画游戏面板，达到擦除对话框的效果
	void options(const int options);  //完成标题画面对话框中的各种设置
};

//读标题画面对话框键鼠操作的返回值
#define CVMB_RET_YES        0x3201  //按“是”键
#define CVMB_RET_NO         0x3202  //按“否”键
#define CVMB_RET_SURE       0x3203  //按“确定”键
#define CVMB_RET_ONE        0x3204  //按“1”键
#define CVMB_RET_TWO        0x3205  //按“2”键
#define CVMB_RET_THREE      0x3206  //按“3”键
#define CVMB_RET_FOUR       0x3207  //按“4”键
#define CVMB_RET_CANCEL     0x3208  //按“取消”键
#define CVMB_RET_BLINK_OFF  0x3209  //关闭色块闪烁
#define CVMB_RET_BLINK_ON   0x320a  //开启色块闪烁
#define CVMB_RET_TIPS_OFF   0x320b  //关闭提示
#define CVMB_RET_TIPS_ON    0x320c  //开启提示

//标题画面对话框各部分的坐标（用阶数表示）
#define CVMB_COORD_X      9  //标题画面对话框左上角横坐标
#define CVMB_COORD_Y      7  //标题画面对话框左上角纵坐标
#define CVPROM_COORD_X    CVMB_COORD_X+2   //标题画面对话框中，提示语左上角横坐标
#define CVPROM_COORD_Y    CVMB_COORD_Y+1   //标题画面对话框中，提示语左上角纵坐标
#define CVYES_COORD_X     CVMB_COORD_X+6   //标题画面对话框中，按键“是”左上角横坐标
#define CVYES_COORD_Y     CVMB_COORD_Y+5   //标题画面对话框中，按键“是”左上角纵坐标
#define CVNO_COORD_X      CVMB_COORD_X+18  //标题画面对话框中，按键“否”左上角横坐标
#define CVNO_COORD_Y      CVMB_COORD_Y+5   //标题画面对话框中，按键“否”左上角纵坐标
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
#define CVSW11_COORD_X    CVMB_COORD_X+2   //标题画面对话框中，开关1按键1左上角横坐标
#define CVSW11_COORD_Y    CVMB_COORD_Y+2   //标题画面对话框中，开关1按键1左上角纵坐标
#define CVSW12_COORD_X    CVMB_COORD_X+8   //标题画面对话框中，开关1按键2左上角横坐标
#define CVSW12_COORD_Y    CVMB_COORD_Y+2   //标题画面对话框中，开关1按键2左上角纵坐标
#define CVSW1P_COORD_X    CVMB_COORD_X+10  //标题画面对话框中，开关1状态标志左上角横坐标
#define CVSW1P_COORD_Y    CVMB_COORD_Y+3   //标题画面对话框中，开关1状态标志左上角纵坐标
#define CVSW21_COORD_X    CVMB_COORD_X+14  //标题画面对话框中，开关2按键1左上角横坐标
#define CVSW21_COORD_Y    CVMB_COORD_Y+2   //标题画面对话框中，开关2按键1左上角纵坐标
#define CVSW22_COORD_X    CVMB_COORD_X+20  //标题画面对话框中，开关2按键2左上角横坐标
#define CVSW22_COORD_Y    CVMB_COORD_Y+2   //标题画面对话框中，开关2按键2左上角纵坐标
#define CVSW2P_COORD_X    CVMB_COORD_X+22  //标题画面对话框中，开关2状态标志左上角横坐标
#define CVSW2P_COORD_Y    CVMB_COORD_Y+3   //标题画面对话框中，开关2状态标志左上角纵坐标

//标题画面对话框按键数
#define CVMB_BUTTON_NUM 12

/*标题画面对话框类的声明*/
class cover_mailbox {
private:
	button button_yes;     //“是”键
	button button_no;      //“否”键
	button button_sure;    //“确定”键
	button button_one;     //“1”键
	button button_two;     //“2”键
	button button_three;   //“3”键
	button button_four;    //“4”键
	button button_cancel;  //“取消”键
	button switch_one[2];  //开关1的两个按钮
	button switch_two[2];  //开关2的两个按钮
	int IF_CVMB = 0;       //标题画面对话框状态（为零则不出现，不为零则数值对应按键形式）
	const int CVMB_BG_COLOR = COLOR_CYAN;  //标题画面对话框背景色
	const int CVMB_FG_COLOR = COLOR_BLACK;  //标题画面对话框前景色
	const int CVMB_WIDTH = 8;               //标题画面对话框宽度
public:
	void set_button_type();   //给按键设置种类
	void set_button_coord();  //给按键坐标赋值
	void print(const int button_mode, const char* prompt1 = NULL, const char* prompt2 = NULL, const char* prompt3 = NULL);  //打印标题画面对话框
	int mouse_if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	int keyboard_if_button(const int keycode);      //判断键盘按下的按键是否为对话框内的某一按键
	void selective_default(const int selection);    //选择性地为某一按键取消高亮
	void selective_activate(const int selection);   //选择性地为某一按键设置高亮
	int control();  //用键鼠在标题画面对话框内进行操作
	void erase();   //重画标题画面，达到擦除对话框的效果
	void options(const int options);  //完成标题画面对话框中的各种设置
};