#pragma once
#include<windows.h>

/*表示游戏内对话框的外部全局对象*/
extern class game_mailbox GAME_MAILBOX;

/*表示标题画面的外部全局对象*/
extern class cover COVER;

/*表示输入框的外部全局对象*/
extern class inputbox INPUTBOX;

/*表示设置对话框的外部全局对象*/
extern class optionsbox OPTIONSBOX;

//游戏行列数边界
#define LINE_MAX 30  //行数最大值
#define ROW_MAX 30   //列数最大值

//游戏难度
#define EASY    1  //简单
#define MEDIUM  2  //中等
#define HARD    3  //困难
#define DIY     4  //自定义

//游戏信息种类
#define INFO_LINE      11  //行数信息
#define INFO_ROW       12  //列数信息
#define INFO_BOMB_NUM  13  //地雷数信息

//游戏各信息预设值
#define EASY_LINE        8   //简单难度行数
#define EASY_ROW         8   //简单难度列数
#define EASY_BOMB_NUM    10  //简单难度地雷数
#define MEDIUM_LINE      16  //中等难度行数
#define MEDIUM_ROW       16  //中等难度列数
#define MEDIUM_BOMB_NUM  40  //中等难度地雷数
#define HARD_LINE        30  //困难难度行数
#define HARD_ROW         16  //困难难度列数
#define HARD_BOMB_NUM    99  //困难难度地雷数
#define DIY_LINE         30  //自定义行数（最大值）
#define DIY_ROW          30  //自定义列数（最大值）
#define DIY_BOMB_NUM     (line * row) * 0.8  //自定义地雷数（最大值）

//空格键对应的num值（用于打印中间为空的色块）
#define NUM_SPACE  ' '-'0'

//游戏面板各部分坐标
#define NEW_COORD_X   (row % 2 ? 6 * (row / 2) + 2 : 6 * (row / 2) - 1)  //新游戏键左上角横坐标
#define NEW_COORD_Y   5  //新游戏键左上角纵坐标
#define MINE_COORD_X  8  //剩余地雷数左上角横坐标
#define MINE_COORD_Y  4  //剩余地雷数左上角纵坐标
#define TIME_COORD_X  (6 * row - 18)  //用时左上角横坐标
#define TIME_COORD_Y  4  //用时左上角纵坐标

//游戏面板各部分颜色
#define NEW_BG_COLOR_D  COLOR_WHITE   //新游戏键正常背景色
#define NEW_FG_COLOR_D  COLOR_YELLOW  //新游戏键正常前景色
#define NEW_BG_COLOR_A  COLOR_HBLACK  //新游戏键高亮背景色
#define NEW_FG_COLOR_A  COLOR_YELLOW  //新游戏键高亮前景色
#define MINE_BG_COLOR   COLOR_BLACK   //剩余地雷数背景色
#define MINE_FG_COLOR   COLOR_RED     //剩余地雷数前景色
#define TIME_BG_COLOR   COLOR_BLACK   //用时背景色
#define TIME_FG_COLOR   COLOR_RED     //用时前景色

//每一局游戏的结果
#define FAILURE  1  //失败
#define VICTORY  2  //胜利
#define NEW      3  //新游戏
#define QUIT     4  //退出

//关于旗子的操作
#define PLACE_FLAG   11  //插旗
#define REMOVE_FLAG  12  //移除旗子

/*游戏中每一个元素对应的结构体*/
struct matrix {
	int num;
	bool mark;
	bool coord_mark;
	bool if_turned;
	bool if_flag;
};

/***************************************************************************

  90-b4-base.cpp

***************************************************************************/
void matrix_single_scan(matrix MATRIX[], const int line, const int row, const int coord);
void zero_check1(matrix MATRIX[], const int line, const int row, const int coord);
void zero_check2(matrix MATRIX[], const int line, const int row, const int coord);
int flag_check(const matrix MATRIX[], const int line, const int row, const int coord);
void matrix_copy(matrix dst[], const matrix src[], const int line, const int row);
bool matrix_compare(const matrix m1[], const matrix m2[], const int line, const int row);
void matrix_initialize(matrix MATRIX[], const int line, const int row, const int bomb_num, const int first_x, const int first_y);

/***************************************************************************

  90-b4-console.cpp

***************************************************************************/
void block_print(const int num, const int bg_color, const int fg_color);
void block_blink(const int row, const int coord, const int bg_color1, const int bg_color2, const int fg_color);
void gameboard_print(const int line, const int row);
char* read_bomb_num(char* bomb_num, const int BOMB_NUM);
char* read_time(char* time, const LONGLONG TIME);
void print_info(const int row, const int bomb_num);
void update_bomb_num(const int row, const int bomb_num);
void update_time(const int row, const LARGE_INTEGER tick, const LARGE_INTEGER begin, const LARGE_INTEGER end);
int if_block(matrix MATRIX[], const int X, const int Y, const int line, const int row);
bool if_new_button(const int X, const int Y, const int row);
void new_button_default(const int row);
void new_button_activate(const int row);
void selective_default(matrix MATRIX[], const int line, const int row, const int coord);
void selective_activate(matrix MATRIX[], const int line, const int row, const int coord, const int X, const int Y);
int turn(matrix MATRIX[], const int line, const int row, const int coord);
int wheel_click_turn(matrix MATRIX[], const int line, const int row, const int coord);
void failure(const matrix MATRIX[], const int line, const int row, const int coord);
void victory(const matrix MATRIX[], const int line, const int row);
void flag(matrix MATRIX[], const int line, const int row, const int coord, int* bomb_num, const int flag_mode);
int control(matrix MATRIX[], const int line, const int row, const int BOMB_NUM, bool* if_initialized);

/***************************************************************************

  90-b4-tools.cpp

***************************************************************************/
void pause();
int set_info(const int difficulty, const int info_type);
int num_trans_color(const int num);
bool if_end(const matrix MATRIX[], const int line, const int row);
void inputbox_erase();
void optionsbox_erase();

/***************************************************************************

  ai_player.cpp

***************************************************************************/
int unturned_check(const matrix MATRIX[], const int line, const int row, const int coord);
int ai_control(matrix MATRIX[], const int line, const int row, int* bomb_num, bool* if_initialized);