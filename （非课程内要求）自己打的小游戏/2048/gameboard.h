#pragma once
#include"90-b3.h"

#define GMBD_BG_COLOR     COLOR_CYAN     //游戏最底层背景色
#define GMBD_FG_COLOR     COLOR_HWHITE   //游戏最底层前景色
#define CSBD_BG_COLOR     COLOR_WHITE    //游戏面板背景色
#define CSBD_FG_COLOR     COLOR_BLACK    //游戏面板前景色
#define SCORE_BG_COLOR    COLOR_GREEN    //分数显示栏背景色
#define SCORE_FG_COLOR    COLOR_BLACK    //分数显示栏前景色
#define MAX_BG_COLOR      COLOR_YELLOW   //最大值显示栏背景色
#define MAX_FG_COLOR      COLOR_BLACK    //最大值显示栏前景色
#define TIPS_BG_COLOR     COLOR_HWHITE   //提示显示栏背景色
#define TIPS_FG_COLOR     COLOR_BLACK    //提示显示栏前景色
#define STEPNUM_BG_COLOR  COLOR_HYELLOW  //步数显示栏背景色
#define STEPNUM_FG_COLOR  COLOR_BLACK    //步数显示栏前景色
#define CSBD_COORD_X     4                 //游戏面板横坐标
#define CSBD_COORD_Y     2                 //游戏面板纵坐标
#define SCORE_COORD_X    __GAME.order*8+8  //分数显示栏横坐标
#define SCORE_COORD_Y    2                 //分数显示栏纵坐标
#define MAX_COORD_X      __GAME.order*8+8  //最大值显示栏横坐标
#define MAX_COORD_Y      7                 //最大值显示栏纵坐标
#define TIPS_COORD_X     __GAME.order*8+8  //提示显示栏横坐标
#define TIPS_COORD_Y     12                //提示显示栏纵坐标
#define STEPNUM_COORD_X  __GAME.order*8+8  //步数显示栏横坐标
#define STEPNUM_COORD_Y  17                //步数显示栏纵坐标

class gameboard {
private:
public:
	void print_background();  //打印最底层背景
	char* read_score(char* score);  //读取得分并转换成字符串
	char* read_max(char* max);  //读取各个元素中的最大值并转换成字符串
	const char* read_solution();  //读取寻找出的最优解并转换为字符串
	char* read_stepnumber(char* stepnumber);  //读取步数并转换为字符串
	void print_info();   //显示游戏相关信息
	void update_info();  //更新游戏相关信息
	void block_single_print(const int num, const int bg_color, const int fg_color);  //打印一个包含着数字的有颜色的方块
	void block_multiple_print();  //根据当前内部数组值打印色块
	void block_clear();  //将当前坐标下对应的色块清除
	void chessboard_single_line(int Y, const char* ch1, const char* ch2, const char* ch3, const char* ch4, const bool if_delay);  //输出游戏面板的某一行
	void chessboard_multiple_lines(const int Y, const bool if_delay);  //输出游戏面板的各行
	void print_chessboard();  //打印游戏面板
	void block_activate(const int coord);  //将当前坐标下对应的色块设置高亮
	void block_default(const int coord);   //将当前坐标下对应的色块高亮取消
	void blink_block(const int coord);     //使当前坐标下的元素对应色块闪烁
};