#include<Windows.h>
#include"colorball.h"
#include"interface-cover.h"

/***************************************************************************
  函数名称：C_print
  功    能：打印一个字母C
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::C_print()
{
	cct_showstr(C_COORD_X, C_COORD_Y, "     ", C_COLOR);
	for (int i = 0; i < 3; i++)
		cct_showch(C_COORD_X, C_COORD_Y + 1 + i, ' ', C_COLOR);
	cct_showstr(C_COORD_X, C_COORD_Y + 4, "     ", C_COLOR);
}

/***************************************************************************
  函数名称：O_print
  功    能：打印一个字母O
  输入参数：const int O_num：字母的编号（只读）
  返 回 值：无
  说    明：需要输出不止一个字母O，故根据编号在不同位置输出字母O
***************************************************************************/
void cover::O_print(const int O_num)
{
	int x = 0, y = 0;
	int bg_color = COLOR_BLACK;

	switch (O_num) {  /*根据要打印的字母E设置坐标和颜色*/
	case 1:
		x = O_COORD_X1, y = O_COORD_Y1;
		bg_color = O_COLOR1;
		break;
	case 2:
		x = O_COORD_X2, y = O_COORD_Y2;
		bg_color = O_COLOR2;
		break;
	}

	/*根据设置的坐标和颜色打印字母*/
	cct_showstr(x, y, "     ", bg_color);
	for (int i = 0; i < 3; i++) {
		cct_showch(x, y + 1 + i, ' ', bg_color);
		cct_showch(x + 4, y + 1 + i, ' ', bg_color);
	}
	cct_showstr(x, y + 4, "     ", bg_color);
}

/***************************************************************************
  函数名称：L_print
  功    能：打印一个字母L
  输入参数：const int L_num：字母的编号（只读）
  返 回 值：无
  说    明：需要输出不止一个字母L，故根据编号在不同位置输出字母L
***************************************************************************/
void cover::L_print(const int L_num)
{
	int x = 0, y = 0;
	int bg_color = COLOR_BLACK;

	switch (L_num) {  /*根据要打印的字母E设置坐标和颜色*/
	case 1:
		x = L_COORD_X1, y = L_COORD_Y1;
		bg_color = L_COLOR;
		break;
	case 2:
		x = L_COORD_X2, y = L_COORD_Y2;
		bg_color = BALL_COLOR;
		break;
	case 3:
		x = L_COORD_X3, y = L_COORD_Y3;
		bg_color = BALL_COLOR;
		break;
	}

	/*根据设置的坐标和颜色打印字母*/
	for (int i = 0; i < 4; i++)
		cct_showch(x, y + i, ' ', bg_color);
	cct_showstr(x, y + 4, "     ", bg_color);
}

/***************************************************************************
  函数名称：R_print
  功    能：打印一个字母R
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::R_print()
{
	cct_showstr(R_COORD_X, R_COORD_Y, "     ", R_COLOR);
	cct_showch(R_COORD_X, R_COORD_Y + 1, ' ', R_COLOR);
	cct_showch(R_COORD_X + 4, R_COORD_Y + 1, ' ', R_COLOR);
	cct_showstr(R_COORD_X, R_COORD_Y + 2, "     ", R_COLOR);
	cct_showch(R_COORD_X, R_COORD_Y + 3, ' ', R_COLOR);
	cct_showch(R_COORD_X + 3, R_COORD_Y + 3, ' ', R_COLOR);
	cct_showch(R_COORD_X, R_COORD_Y + 4, ' ', R_COLOR);
	cct_showch(R_COORD_X + 4, R_COORD_Y + 4, ' ', R_COLOR);
}

/***************************************************************************
  函数名称：B_print
  功    能：打印一个字母B
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::B_print()
{
	cct_showstr(B_COORD_X, B_COORD_Y, "    ", BALL_COLOR);
	cct_showch(B_COORD_X, B_COORD_Y + 1, ' ', BALL_COLOR);
	cct_showch(B_COORD_X + 3, B_COORD_Y + 1, ' ', BALL_COLOR);
	cct_showstr(B_COORD_X, B_COORD_Y + 2, "      ", BALL_COLOR);
	cct_showch(B_COORD_X, B_COORD_Y + 3, ' ', BALL_COLOR);
	cct_showch(B_COORD_X + 5, B_COORD_Y + 3, ' ', BALL_COLOR);
	cct_showstr(B_COORD_X, B_COORD_Y + 4, "      ", BALL_COLOR);
}

/***************************************************************************
  函数名称：A_print
  功    能：打印一个字母A
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::A_print()
{
	cct_showch(A_COORD_X + 4, A_COORD_Y, ' ', BALL_COLOR);
	for (int i = 0; i < 4; i++) {
		cct_showch(A_COORD_X + 3 - i, A_COORD_Y + 1 + i, ' ', BALL_COLOR);
		cct_showch(A_COORD_X + 5 + i, A_COORD_Y + 1 + i, ' ', BALL_COLOR);
	}
	cct_showstr(A_COORD_X + 2, A_COORD_Y + 3, "     ", BALL_COLOR);
}

/***************************************************************************
  函数名称：ball_print
  功    能：打印一个珠子
  输入参数：const int X：珠子左上角横坐标（只读）
            const int Y：珠子左上角纵坐标（只读）
			const int bg_color：珠子颜色（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::ball_print(const int X, const int Y, const int bg_color)
{
	for (int i = 0; i < 3; i++)
		cct_showstr(X, Y + i, "      ", bg_color);
	cct_showch(X + 2, Y + 1, ' ', COLOR_WHITE);
}

/***************************************************************************
  函数名称：print
  功    能：打印标题画面
  输入参数：无
  返 回 值：无
  说    明：本函数同时根据标题画面宽度设置了窗口大小，减少黑色部分
***************************************************************************/
void cover::print()
{
	cct_setconsoleborder(80, COVER_WIDTH + 2);  /*设置窗口大小，除去黑边*/

	/*1、打印标题画面背景*/
	cct_showstr(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓", COLOR_WHITE, COLOR_BLACK);
	for (int i = 0; i < COVER_WIDTH - 2; i++) {
		cct_showstr(0, i + 1, "┃                                                                            ┃", COLOR_WHITE, COLOR_BLACK);
		Sleep(10);
	}
	cct_showstr(0, COVER_WIDTH - 1, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛", COLOR_WHITE, COLOR_BLACK);

	/*2、打印彩色球和所有字母*/
	PRINT_ALL_BALLS;
	PRINT_ALL_LETTERS;

	/*3、打印按键*/
	Sleep(100);
	button_new.act(DEFAULT);
	button_load.act(DEFAULT);
	button_options.act(DEFAULT);
	button_help.act(DEFAULT);
	button_about.act(DEFAULT);
	button_exit.act(DEFAULT);
}

/***************************************************************************
  函数名称：if_button
  功    能：判断鼠标位置是否在某一按键上
  输入参数：const int X：鼠标位置横坐标（只读）
			const int Y：鼠标位置纵坐标（只读）
  返 回 值：int：鼠标在哪一按键上
  说    明：无
***************************************************************************/
int cover::if_button(const int X, const int Y)
{
	int ret = 0;    /*返回值*/
	bool p[COVER_BUTTON_NUM];
	for (int i = 0; i < COVER_BUTTON_NUM; i++)
		p[i] = false;

	if (X >= NEW_COORD_X && X <= NEW_COORD_X + 11 && Y >= NEW_COORD_Y && Y <= NEW_COORD_Y + 2)          /*判断是否在“新游戏”键上*/
		p[0] = true;
	if (X >= LOAD_COORD_X && X <= LOAD_COORD_X + 11 && Y >= LOAD_COORD_Y && Y <= LOAD_COORD_Y + 2)      /*判断是否在“载入游戏”键上*/
		p[1] = true;
	if (X >= CVOP_COORD_X && X <= CVOP_COORD_X + 11 && Y >= CVOP_COORD_Y && Y <= CVOP_COORD_Y + 2)      /*判断是否在“设置”键上*/
		p[2] = true;
	if (X >= HELP_COORD_X && X <= HELP_COORD_X + 11 && Y >= HELP_COORD_Y && Y <= HELP_COORD_Y + 2)      /*判断是否在“帮助”键上*/
		p[3] = true;
	if (X >= ABOUT_COORD_X && X <= ABOUT_COORD_X + 11 && Y >= ABOUT_COORD_Y && Y <= ABOUT_COORD_Y + 2)  /*判断是否在“关于”键上*/
		p[4] = true;
	if (X >= EXIT_COORD_X && X <= EXIT_COORD_X + 11 && Y >= EXIT_COORD_Y && Y <= EXIT_COORD_Y + 2)      /*判断是否在“退出”键上*/
		p[5] = true;

	for (int i = 0; i < COVER_BUTTON_NUM; i++) {  /*检查各个位置的情况，遇到真则取对应返回值后结束检查*/
		if (p[i]) {
			ret = i + 1;
			break;
		}
	}

	return ret;
}

/***************************************************************************
  函数名称：selective_default
  功    能：选择性地为某一按键取消高亮
  输入参数：const int selection：按键选择（只读）
  返 回 值：无
  说    明：当选择为DEFAULT_ALL时，通过递归调用取消所有按键的高亮
***************************************************************************/
void cover::selective_default(const int selection)
{
	switch (selection) {  /*根据选择进行对应操作*/
	case 1:
		button_new.act(DEFAULT);      /*“新游戏”键取消高亮*/
		break;
	case 2:
		button_load.act(DEFAULT);     /*“载入游戏”键取消高亮*/
		break;
	case 3:
		button_options.act(DEFAULT);  /*“设置”键取消高亮*/
		break;
	case 4:
		button_help.act(DEFAULT);     /*“帮助”键取消高亮*/
		break;
	case 5:
		button_about.act(DEFAULT);    /*“关于”键取消高亮*/
		break;
	case 6:
		button_exit.act(DEFAULT);     /*“退出”键取消高亮*/
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < COVER_BUTTON_NUM; i++)  /*所有按键取消高亮*/
			selective_default(i + 1);
		break;
	}
}

/***************************************************************************
  函数名称：selective_activate
  功    能：选择性地为某一按键设置高亮
  输入参数：const int selection：按键选择（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::selective_activate(const int selection)
{
	switch (selection) {  /*根据选择进行对应操作*/
	case 1:
		button_new.act(ACTIVATE);      /*“新游戏”键设置高亮*/
		break;
	case 2:
		button_load.act(ACTIVATE);     /*“载入游戏”键设置高亮*/
		break;
	case 3:
		button_options.act(ACTIVATE);  /*“设置”键设置高亮*/
		break;
	case 4:
		button_help.act(ACTIVATE);     /*“帮助”键设置高亮*/
		break;
	case 5:
		button_about.act(ACTIVATE);    /*“关于”键设置高亮*/
		break;
	case 6:
		button_exit.act(ACTIVATE);     /*“退出”键设置高亮*/
		break;
	}
}

/***************************************************************************
  函数名称：control
  功    能：用键鼠在标题画面上进行操作
  输入参数：bool* if_sound：是否有声音
  返 回 值：int：进行的操作
  说    明：无
***************************************************************************/
int cover::control(bool* if_sound)
{
	int X = 0, Y = 0;  /*横纵坐标，初始均为零*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*函数的返回值*/

	cct_enable_mouse();  /*启用鼠标*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*读鼠标/键盘*/
		int RET = if_button(X, Y);  /*判断此时鼠标的位置是否在某个按键中*/

		if(!RET)
			selective_default(DEFAULT_ALL);  /*取消标题画面所有按键的高亮*/

		if (!last_button) {
			last_button = RET;
			selective_activate(RET);    /*若在某个按键中，将对应的按键设置高亮*/

			if (RET && *if_sound)  /*根据需要播放声音*/
				Beep(SOUND_FA, 100);
		}

		else {
			if (RET != last_button) {
				last_button = RET;
				selective_activate(RET);    /*若在某个按键中，将对应的按键设置高亮*/

				if (RET && *if_sound)  /*根据需要播放声音*/
					Beep(SOUND_FA, 100);
			}
		}

		/*1、若返回的是鼠标事件并且按下左键*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {
			switch (RET) {
			case 1:
				result = COVER_RET_NEW, loop = 0;      /*取返回值、结束循环*/
				break;
			case 2:
				result = COVER_RET_LOAD, loop = 0;     /*取返回值、结束循环*/
				break;
			case 3:
				result = COVER_RET_OPTIONS, loop = 0;  /*取返回值、结束循环*/
				break;
			case 4:
				result = COVER_RET_HELP, loop = 0;     /*取返回值、结束循环*/
				break;
			case 5:
				result = COVER_RET_ABOUT, loop = 0;    /*取返回值、结束循环*/
				break;
			case 6:
				result = COVER_RET_EXIT, loop = 0;     /*取返回值、结束循环*/
				break;
			}
		}
	}

	last_button = 0;  /*清除按键上一次位置信息*/
	cct_disable_mouse();	//禁用鼠标
	return result;
}