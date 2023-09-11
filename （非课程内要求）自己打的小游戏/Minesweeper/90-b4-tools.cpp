#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include"cmd_console_tools.h"
#include"90-b4.h"
#include"interface-inputbox.h"
#include"interface-cover.h"
#include"interface-optionsbox.h"
using namespace std;

/***************************************************************************
  函数名称：tick
  功    能：停止一定时间并进行计时
  输入参数：const int sleep_length：停止时间长度（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void tick(const int sleep_length)
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	Sleep(sleep_length);

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;  //输出计数器频率
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;  //输出计数器计数
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;  //根据计数器频率及计数，计算出时间长度并输出
}

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
  函数名称：set_info
  功    能：各类游戏参数
  输入参数：const int difficulty：游戏难度（只读）
            const int info_type：参数类型（只读）
  返 回 值：int：对应的参数
  说    明：无
***************************************************************************/
int set_info(const int difficulty, const int info_type)
{
	int ret = 0;  /*返回值*/

	switch (difficulty) {
	/*简单*/
	case EASY:
		switch (info_type) {
		case INFO_LINE:
			ret = EASY_LINE;  /*简单难度下的行数*/
			break;
		case INFO_ROW:
			ret = EASY_ROW;  /*简单难度下的列数*/
			break;
		case INFO_BOMB_NUM:
			ret = EASY_BOMB_NUM;  /*简单难度下的地雷数*/
			break;
		}
		break;
	/*中等*/
	case MEDIUM:
		switch (info_type) {
		case INFO_LINE:
			ret = MEDIUM_LINE;  /*中等难度下的行数*/
			break;
		case INFO_ROW:
			ret = MEDIUM_ROW;  /*中等难度下的列数*/
			break;
		case INFO_BOMB_NUM:
			ret = MEDIUM_BOMB_NUM;  /*中等难度下的地雷数*/
			break;
		}
		break;
	/*困难*/
	case HARD:
		switch (info_type) {
		case INFO_LINE:
			ret = HARD_LINE;  /*困难难度下的行数*/
			break;
		case INFO_ROW:
			ret = HARD_ROW;  /*困难难度下的列数*/
			break;
		case INFO_BOMB_NUM:
			ret = HARD_BOMB_NUM;  /*困难难度下的地雷数*/
			break;
		}
		break;
	}

	return ret;
}

/***************************************************************************
  函数名称：num_trans_color
  功    能：根据数值取对应的颜色
  输入参数：const int num：待处理数值（只读）
  返 回 值：int：对应数值的颜色
  说    明：无
***************************************************************************/
int num_trans_color(const int num)
{
	int ret = 0;  /*返回值，先设为0*/

	switch (num) {
	case '*' - '0':
		ret = COLOR_BLACK;  /*地雷，对应黑色*/
		break;
	case 0:
		ret = COLOR_HWHITE;  /*0，对应亮白色*/
		break;
	case 1:
		ret = COLOR_BLUE;    /*1，对应蓝色*/
		break;
	case 2:
		ret = COLOR_GREEN;   /*2，对应绿色*/
		break;
	case 3:
		ret = COLOR_HRED;    /*3，对应亮红色*/
		break;
	case 4:
		ret = COLOR_PINK;    /*4，对应粉色*/
		break;
	case 5:
		ret = COLOR_RED;     /*5，对应红色*/
		break;
	case 6:
		ret = COLOR_HCYAN;   /*6，对应亮青色*/
		break;
	case 7:
		ret = COLOR_BLACK;   /*7，对应黑色*/
		break;
	case 8:
		ret = COLOR_HBLACK;  /*8，对应亮黑色*/
		break;
	}

	return ret;
}

/***************************************************************************
  函数名称：if_end
  功    能：判断游戏是否结束
  输入参数：const matrix MATRIX[]：整个游戏的内部结构体数组（只读）
            const int line：游戏行数（只读）
			const int row：游戏列数（只读）
  返 回 值：bool：游戏是否结束
  说    明：无
***************************************************************************/
bool if_end(const matrix MATRIX[], const int line, const int row)
{
	bool ret = true;  /*返回值，先设为真*/

	for (int i = 0; i < line * row; i++) {  /*逐个检查所有元素，若未翻开的元素中有不是雷的元素，则游戏未结束*/
		if (!MATRIX[i].if_turned && MATRIX[i].num != '*') {
			ret = false;  /*返回值设为假并结束检查*/
			break;
		}
	}

	return ret;
}

/***************************************************************************
  函数名称：inputbox_erase
  功    能：重画标题画面，达到擦除对话框的效果
  输入参数：无
  返 回 值：无
  说    明：本函数重画了输入框对应的那几行以及所有数字和部分被盖住的按键
***************************************************************************/
void inputbox_erase()
{
	cct_gotoxy(0, IPBX_COORD_Y);
	const char* String = "┃                                                                            ┃";

	/*1、补上背景*/
	for (int i = 0; i < INPUTBOX.get_width(); i++)
		cct_showstr(0, IPBX_COORD_Y + i, String, COLOR_WHITE, COLOR_BLACK);

	/*2、重画地雷及上三个按键*/
	COVER.bomb_reprint();
	COVER.button_reprint();

	/*3、重画所有字母*/
	COVER.M_print();
	COVER.I_print();
	COVER.N_print();
	COVER.E_print(1);
	COVER.S_print();
	COVER.W_print();
	COVER.E_print(2);
	COVER.E_print(3);
	COVER.P_print();
	COVER.E_print(4);
	COVER.R_print();
}

/***************************************************************************
  函数名称：optionsbox_erase
  功    能：重画设置对话框，达到擦除对话框的效果
  输入参数：无
  返 回 值：无
  说    明：本函数重画了设置对话框对应的那几行以及所有数字和部分被盖住的按键
***************************************************************************/
void optionsbox_erase()
{
	cct_gotoxy(0, OPBX_COORD_Y);
	const char* String = "┃                                                                            ┃";

	/*1、补上背景*/
	for (int i = 0; i < OPTIONSBOX.get_width(); i++)
		cct_showstr(0, OPBX_COORD_Y + i, String, COLOR_WHITE, COLOR_BLACK);

	/*2、重画地雷及上三个按键*/
	COVER.bomb_reprint();
	COVER.button_reprint();

	/*3、重画所有字母*/
	COVER.M_print();
	COVER.I_print();
	COVER.N_print();
	COVER.E_print(1);
	COVER.S_print();
	COVER.W_print();
	COVER.E_print(2);
	COVER.E_print(3);
	COVER.P_print();
	COVER.E_print(4);
	COVER.R_print();
}