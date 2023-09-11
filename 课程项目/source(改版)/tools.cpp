#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<string>
#include"cmd_console_tools.h"
#include"colorball.h"
using namespace std;

/***************************************************************************
  函数名称：pause
  功    能：设置一个程序的间断点
  输入参数：无
  返 回 值：无
  说    明：输入回车才继续，其他字符无回显
***************************************************************************/
void pause()
{
	char c;
	while (1) {
		c = _getch();
		if (c == '\r')
			break;
	}
}

/***************************************************************************
  函数名称：num_trans_color
  功    能：输入一个0-5的数，返回表示颜色的量
  输入参数：const int num：输入的数（只读）
  返 回 值：int：返回的颜色
  说    明：该函数是为了随机产生颜色时，0-5之间的随机数可以与颜色进行对应
***************************************************************************/
int num_trans_color(const int num)
{
	int ret = 0;  /*返回值*/

	switch (num) {
	case 0:
		ret = COLOR_RED;
		break;
	case 1:
		ret = COLOR_YELLOW;
		break;
	case 2:
		ret = COLOR_HYELLOW;
		break;
	case 3:
		ret = COLOR_GREEN;
		break;
	case 4:
		ret = COLOR_BLUE;
		break;
	case 5:
		ret = COLOR_PINK;
		break;
	}

	return ret;
}

/***************************************************************************
  函数名称：color_trans_string
  功    能：输入表示颜色的量，返回表示该颜色的字符串
  输入参数：const int color：输入的颜色（只读）
            char* c：存放返回结果的字符数组
  返 回 值：char*：输入颜色对应的字符串
  说    明：该函数是为了预告颜色时，整型的颜色可以与字符串进行对应
***************************************************************************/
char* color_trans_string(const int color, char* c)
{
	switch (color) {
	case COLOR_RED:
		strcpy(c, "红");
		break;
	case COLOR_YELLOW:
		strcpy(c, "橙");
		break;
	case COLOR_HYELLOW:
		strcpy(c, "黄");
		break;
	case COLOR_GREEN:
		strcpy(c, "绿");
		break;
	case COLOR_BLUE:
		strcpy(c, "蓝");
		break;
	case COLOR_PINK:
		strcpy(c, "紫");
		break;
	}

	return c;
}

/***************************************************************************
  函数名称：chessboard_single_line
  功    能：输出游戏面板的某一行
  输入参数：int Y：光标调用函数前的纵坐标
			const char* ch1：该行第一个制表符（只读）
			const char* ch2：该行中间的制表符（只读）
			const char* ch3：该行中间的特殊制表符（只读）
			const char* ch4：该行最后一个制表符（只读）
  返 回 值：无
  说    明：每输出一个制表符，X进行自增2的操作
***************************************************************************/
void chessboard_single_line(int Y, const char* ch1, const char* ch2, const char* ch3, const char* ch4)
{
	int i;      /*计数变量*/
	int X = 0;  /*横坐标，初始为2*/

	/*1、输出第一个制表符*/
	cct_showstr(X, Y, ch1, COLOR_WHITE, COLOR_BLACK);
	X = X + 2;

	/*2、输出中间的多个制表符*/
	for (i = 0; i < 36; i++) {

		/*2.1、输出中间的一般制表符*/
		cct_showstr(X, Y, ch2, COLOR_WHITE, COLOR_BLACK);
		X = X + 2;

		/*2.2、在指定位置打印特殊制表符*/
		if (X % 10 == 0 && X != 90) {
			cct_showstr(X, Y, ch3, COLOR_WHITE, COLOR_BLACK);
			X = X + 2;
		}
	}

	/*3、输出最后一个制表符并重置颜色*/
	cct_showstr(X, Y, ch4, COLOR_WHITE, COLOR_BLACK);
	cct_setcolor();
}

/***************************************************************************
  函数名称：chessboard_multiple_lines
  功    能：输出游戏面板的各行
  输入参数：const int Y：行数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void chessboard_multiple_lines(const int Y)
{
	/*首行的输出*/
	if (Y == 0)
		chessboard_single_line(Y, "┏", "━", "┳", "┓");

	/*最后一行的输出*/
	else if (Y == 45)
		chessboard_single_line(Y, "┗", "━", "┻", "┛");

	/*特殊行的输出*/
	else if (Y % 5 == 0)
		chessboard_single_line(Y, "┣", "━", "╋", "┫");

	/*一般行的输出*/
	else
		chessboard_single_line(Y, "┃", "  ", "┃", "┃");
}

/***************************************************************************
  函数名称：print_chessboard
  功    能：输出游戏面板
  输入参数：无
  返 回 值：无
  说    明：本函数除了打印白色背景外，还打印了游戏相关信息显示框，以及游戏内各个按键
***************************************************************************/
void print_chessboard()
{
	/*逐行打印棋盘*/
	for (int Y = 0; Y <= 45; Y++) {
		chessboard_multiple_lines(Y);  /*输出不同形式的每一行*/

		cct_gotoxy(0, Y + 1);
	}

	/*逐行打印棋盘右侧区域*/
	for (int Y = 0; Y <= 45; Y++) {
		const int X = 92;
		switch (Y) {
		case 0:
			cct_showstr(X, Y, "┏━━━━━━━━┓", COLOR_HWHITE, COLOR_BLACK);
			break;
		case 45:
			cct_showstr(X, Y, "┗━━━━━━━━┛", COLOR_HWHITE, COLOR_BLACK);
			break;
		default:
			cct_showstr(X, Y, "┃                ┃", COLOR_HWHITE, COLOR_BLACK);
			break;
		}
	}

	cct_gotoxy(0, 0);

	/*打印游戏相关信息显示框，以及游戏内各个按键*/
	print_info_block(SCORE_COORD_X, SCORE_COORD_Y, "得分：", COLOR_CYAN, COLOR_HWHITE);         /*打印得分显示框*/
	print_info_block(COLOR_COORD_X, COLOR_COORD_Y, "下一颜色：", COLOR_BLACK, COLOR_HWHITE);    /*打印下一颜色显示框*/
	print_info_block(STATE_COORD_X, STATE_COORD_Y, "状态：", COLOR_HRED, COLOR_HWHITE);         /*打印状态显示框*/
	print_game_button(OPTIONS_COORD_X, OPTIONS_COORD_Y, " 设置 ", COLOR_HBLACK, COLOR_HWHITE);  /*打印“设置”键*/
	print_game_button(SAVE_COORD_X, SAVE_COORD_Y, " 保存 ", COLOR_HBLUE, COLOR_HWHITE);         /*打印“保存”键*/
	print_game_button(DELETE_COORD_X, DELETE_COORD_Y, " 删除 ", COLOR_HGREEN, COLOR_HWHITE);    /*打印“删除”键*/
	print_game_button(QUIT_COORD_X, QUIT_COORD_Y, " 退出 ", COLOR_BLACK, COLOR_HWHITE);         /*打印“退出”键*/
}

/***************************************************************************
  函数名称：print_info_block
  功    能：打印一个游戏相关信息的显示框
  输入参数：cosnt int X：显示框左上角横坐标（只读）
            cosnt int Y：显示框左上角纵坐标（只读）
			const char* title：显示框标题（只读）
			const int bg_color：显示框背景色（只读）
			const int fg_color：显示框前景色（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void print_info_block(const int X, const int Y, const char* title, const int bg_color, const int fg_color)
{
	cct_showstr(X, Y, "┏━━━━━┓", bg_color, fg_color);
	cct_showstr(X, Y + 1, "┃          ┃", bg_color, fg_color);
	cct_showstr(X, Y + 2, "┃          ┃", bg_color, fg_color);
	cct_showstr(X, Y + 3, "┗━━━━━┛", bg_color, fg_color);
	cct_showstr(X + 2, Y + 1, title, bg_color, fg_color);
}

/***************************************************************************
  函数名称：print_game_button
  功    能：打印一个游戏内的按键
  输入参数：cosnt int X：按键左上角横坐标（只读）
			cosnt int Y：按键左上角纵坐标（只读）
			const char* title：按键内容（只读）
			const int bg_color：按键背景色（只读）
			const int fg_color：按键前景色（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void print_game_button(const int X, const int Y, const char* prompt, const int bg_color, const int fg_color)
{
	cct_showstr(X, Y, "┏━━━┓", bg_color, fg_color);
	cct_showstr(X, Y + 1, "┃", bg_color, fg_color);
	cct_showstr(X + 2, Y + 1, prompt, bg_color, fg_color);
	cct_showstr(X + 8, Y + 1, "┃", bg_color, fg_color);
	cct_showstr(X, Y + 2, "┗━━━┛", bg_color, fg_color);
}

/***************************************************************************
  函数名称：print_cover_button
  功    能：在光标当前位置打印一个标题画面按键
  输入参数：const char* prompt：按键内容（只读）
			const int bg_color：按键背景色（只读）
			const int fg_color：按键前景色（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void print_cover_button(const char* prompt, const int bg_color, const int fg_color)
{
	int X, Y;
	cct_getxy(X, Y);
	cct_showstr(X, Y, "┏━━━━┓", bg_color, fg_color);
	cct_showstr(X, Y + 1, "┃", bg_color, fg_color);
	cct_showstr(X + 2, Y + 1, prompt, bg_color, fg_color);
	cct_showstr(X + 10, Y + 1, "┃", bg_color, fg_color);
	cct_showstr(X, Y + 2, "┗━━━━┛", bg_color, fg_color);
}

/***************************************************************************
  函数名称：print_empty_block
  功    能：在光标当前位置打印一个中心为空的色块
  输入参数：const int bg_color：按键背景色（只读）
			const int fg_color：按键前景色（只读）
  返 回 值：无
  说    明：中心为空指不在中心位置进行打印
***************************************************************************/
void print_empty_block(const int bg_color, const int fg_color)
{
	int X, Y;         /*横纵坐标*/
	cct_getxy(X, Y);  /*取光标当前坐标*/

	/*1、打印上边界*/
	cct_showstr(X, Y, "┏━┓", bg_color, fg_color);

	/*2、打印左边界*/
	cct_showstr(X, Y + 1, "┃", bg_color, fg_color);

	/*4、打印右边界*/
	cct_showstr(X + 4, Y + 1, "┃", bg_color, fg_color);

	/*5、打印下边界*/
	cct_showstr(X, Y + 2, "┗━┛", bg_color, fg_color);

	cct_setcolor();  /*重置颜色*/
}

/***************************************************************************
  函数名称：print_switch_button
  功    能：打印一个开关上的按键
  输入参数：const int bg_color：按键背景色（只读）
			const int fg_color：按键前景色（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void print_switch_button(const int bg_color, const int fg_color)
{
	int X, Y;         /*横纵坐标*/
	cct_getxy(X, Y);  /*取光标当前坐标*/

	cct_showch(X, Y, ' ', bg_color, fg_color);
	cct_showch(X, Y + 1, ' ', bg_color, fg_color);
}

/***************************************************************************
  函数名称：power
  功    能：求一个数的n次方
  输入参数：const int base_number：底数（只读）
			const int exponent：指数（只读）
  返 回 值：int：该数的n次方
  说    明：无
***************************************************************************/
int power(const int base_number, const int exponent)
{
	int ret = 1;

	if (exponent) {
		for (int i = 0; i < exponent; i++)
			ret = ret * base_number;
	}

	return ret;
}

/***************************************************************************
  函数名称：highscore_compare
  功    能：规定排序方法
  输入参数：const void* p1：指针1（只读）
			const void* p2：指针2（只读）
  返 回 值：int：比较后的返回值（与排序方法有关，从大到小为负，从小到大为正）
  说    明：1、本函数为qsort函数所用
			2、本函数支持int型的排序，方法为从大到小排序
			3、本函数不能为任何类的成员（否则用qsort时会报错）
***************************************************************************/
int highscore_compare(const void* p1, const void* p2)
{
	int* a = (int*)p1;  /*转换p1的类型为指向int型的指针，另定义指针变量a接收地址*/
	int* b = (int*)p2;  /*转换p2的类型为指向int型的指针，另定义指针变量b接收地址*/
	return *b - *a;  /*返回两指针指向的变量做差，本处*b - *a表示从大到小排序*/
}