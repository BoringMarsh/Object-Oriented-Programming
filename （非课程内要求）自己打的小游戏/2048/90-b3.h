#pragma once

//全部所需开头声明及头文件
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include"cmd_console_tools.h"
#include"gameboard.h"
#include"interface-button.h"
#include"interface-keyboard.h"
#include"interface-mailbox.h"
#include"interface-cover.h"
using namespace std;

//游戏面板阶数边界
#define ORDER_MIN 3  //阶数最小值
#define ORDER_MAX 7  //阶数最大值

//色块型按钮打印模式
#define BLOCK_ARROW_MODE_UP    0x001  //包含上箭头
#define BLOCK_ARROW_MODE_DOWN  0x002  //包含下箭头
#define BLOCK_ARROW_MODE_LEFT  0x003  //包含左箭头
#define BLOCK_ARROW_MODE_RIGHT 0x004  //包含右箭头

//小键盘按键种类
#define KB_UP      0x101  //上箭头键
#define KB_DOWN    0x102  //下箭头键
#define KB_LEFT    0x103  //左箭头键
#define KB_RIGHT   0x104  //右箭头键
#define KB_Q       0x105  //功能键Q
#define KB_R       0x106  //功能键R
#define KB_S       0x107  //功能键S
#define KB_D       0x108  //功能键D
#define KB_O       0x109  //功能键O

//游戏内对话框按键种类
#define GMMB_YES     0x201  //“是”键
#define GMMB_NO      0x202  //“否”键
#define GMMB_SURE    0x203  //“确定”键
#define GMMB_ONE     0x204  //“1”键
#define GMMB_TWO     0x205  //“2”键
#define GMMB_THREE   0x206  //“3”键
#define GMMB_FOUR    0x207  //“4”键
#define GMMB_CANCEL  0x208  //“取消”键
#define GMMB_SW11    0x209  //开关1按键1
#define GMMB_SW12    0x20a  //开关1按键2
#define GMMB_SW21    0x20b  //开关2按键1
#define GMMB_SW22    0x20c  //开关2按键2

//标题画面对话框按键种类
#define CVMB_YES     0x301  //“是”键
#define CVMB_NO      0x302  //“否”键
#define CVMB_SURE    0x303  //“确定”键
#define CVMB_ONE     0x304  //“1”键
#define CVMB_TWO     0x305  //“2”键
#define CVMB_THREE   0x306  //“3”键
#define CVMB_FOUR    0x307  //“4”键
#define CVMB_CANCEL  0x308  //“取消”键
#define CVMB_SW11    0x309  //开关1按键1
#define CVMB_SW12    0x30a  //开关1按键2
#define CVMB_SW21    0x30b  //开关2按键1
#define CVMB_SW22    0x30c  //开关2按键2

//封面按键种类
#define CV_NEW      0x401  //“新游戏”键
#define CV_LOAD     0x402  //“载入游戏”键
#define CV_AUTO     0x403  //“自动游戏”键
#define CV_OPTIONS  0x404  //“设置”键
#define CV_ABOUT    0x405  //“关于”键
#define CV_QUIT     0x406  //“退出游戏”键

//按键效果种类
#define ACTIVATE     0x10001  //某一按键设置高亮
#define DEFAULT      0x10002  //某一按键取消高亮
#define DEFAULT_ALL  0x10003  //所有按键取消高亮

/***************************************************************************

  90-b3-base.cpp

***************************************************************************/
void move_left();
void add_left();
void act_left();
void move_right();
void add_right();
void act_right();
void move_up();
void add_up();
void act_up();
void move_down();
void add_down();
void act_down();
int matrix_getmax();
int matrix_getmin();
void summon_two();

struct matrix {  //检查游戏是否结束时用的结构体
	int num;
	int mark;
};
void matrix_single_scan(matrix m[], const int coord);
int matrix_mark_count(matrix m[]);
void matrix_mark_set(matrix m[]);
bool if_end();
bool if_full();

/***************************************************************************

  90-b3-tools.cpp

***************************************************************************/
void pause();
void console_print_base();
void print_cover_button(const char* prompt, const int bg_color, const int fg_color);
void print_keyboard_button(const int print_mode, const int bg_color, const int fg_color);
void print_switch_button(const int bg_color, const int fg_color);
int color_number(int initial_num);
int power(const int base_number, const int exponent);

/***************************************************************************

  90-b3-main.cpp

***************************************************************************/
void order_input();
void cover_in_progress();
void game_in_progress();

/*存档管理类的声明*/
class files {
private:
	ofstream writer;  //写对象
	ifstream reader;  //读对象
	char filename[10] = "save .txt";  //文件名
public:
	void file_save(const int save_slot);  //将游戏保存到文件中
	bool if_file_deleted(const int save_slot);  //判断当前位置上的文件是否被清空
	void file_load(const int save_slot);  //读取游戏存档文件
	void file_delete(const int save_slot);  //清空游戏存档文件
};

//寻找到的最优解行动
#define AI_SLN_UP      0x4001  //向上合成
#define AI_SLN_DOWN    0x4002  //向下合成
#define AI_SLN_LEFT    0x4003  //向左合成
#define AI_SLN_RIGHT   0x4004  //向右合成
#define AI_SLN_NOMOVE  0x4005  //该元素不合成
#define AI_SLN_END     0x4006  //结束游戏
#define AI_SLN_LIMIT   0x4099  //极限状态（只剩一格）

/*自动游戏类的声明*/
class ai_player {
private:
	int matrix[ORDER_MAX * ORDER_MAX];  //求解最优解用的数组
public:
	void matrix_copy();  //将游戏内部数组复制到私有成员数组中
	int two_order(int initial_num);  //返回一个数是2的几次方
	void matrix_trans();       //将私有成员数组转换，以便寻找最优解
	int find_best_solution();  //检查整个数组，找出最优解
	bool check_up(const int line, const int row, const int num);     //检查某个位置的元素能否通过向上合成消除
	bool check_down(const int line, const int row, const int num);   //检查某个位置的元素能否通过向下合成消除
	bool check_left(const int line, const int row, const int num);   //检查某个位置的元素能否通过向左合成消除
	bool check_right(const int line, const int row, const int num);  //检查某个位置的元素能否通过向右合成消除
	int check_and_answer(const int line, const int row, const int num);  //检查并给出对于某个位置的元素的最优解
	bool if_limit();   //检查内部数组是否为极限状态
	void auto_game();  //进行自动游戏
};

//存放所有外部全局变量或对象的结构体
struct game {
	int order = 0;  //面板阶数
	int matrix[ORDER_MAX * ORDER_MAX];  //内部数组
	int score = 0;       //得分
	int stepnumber = 0;  //步数
	const char* version = "v3.0";  //游戏版本号
	bool if_blink = true;  //是否开启色块闪烁
	bool if_tips = true;   //是否开启提示
	ai_player ai_player;   //自动游戏对象
	gameboard gameboard;   //游戏面板对象
	keyboard keyboard;     //小键盘对象
	cover_mailbox cover_mailbox;  //标题画面对话框
	game_mailbox game_mailbox;    //游戏内对话框
	cover cover;  //标题画面对象
	files files;  //存档管理对象
};

/*在各个源文件中都可使用的声明*/
extern struct game __GAME;