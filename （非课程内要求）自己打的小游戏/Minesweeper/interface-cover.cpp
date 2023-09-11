#include<windows.h>
#include"interface-cover.h"

/***************************************************************************
  函数名称：M_print
  功    能：打印一个字母M
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::M_print()
{
	for (int i = 0; i < 5; i++) {
		cct_showch(M_COORD_X, M_COORD_Y + i, ' ', COLOR_BLACK);
		cct_showch(M_COORD_X + i, M_COORD_Y + i, ' ', COLOR_BLACK);
		cct_showch(M_COORD_X + 10 - i - 2, M_COORD_Y + i, ' ', COLOR_BLACK);
		cct_showch(M_COORD_X + 8, M_COORD_Y + i, ' ', COLOR_BLACK);
	}
}

/***************************************************************************
  函数名称：I_print
  功    能：打印一个字母I
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::I_print()
{
	cct_showstr(I_COORD_X, I_COORD_Y, "     ", COLOR_BLACK);
	for (int i = 0; i < 3; i++)
		cct_showch(I_COORD_X + 2, I_COORD_Y + i + 1, ' ', COLOR_BLACK);
	cct_showstr(I_COORD_X, I_COORD_Y + 4, "     ", COLOR_BLACK);
}

/***************************************************************************
  函数名称：N_print
  功    能：打印一个字母N
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::N_print()
{
	for (int i = 0; i < 5; i++) {
		cct_showch(N_COORD_X, N_COORD_Y + i, ' ', COLOR_BLACK);
		cct_showch(N_COORD_X + i + 1, N_COORD_Y + i, ' ', COLOR_BLACK);
		cct_showch(N_COORD_X + 6, N_COORD_Y + i, ' ', COLOR_BLACK);
	}
}

/***************************************************************************
  函数名称：E_print
  功    能：打印一个字母E
  输入参数：const int E_num：字母的编号（只读）
  返 回 值：无
  说    明：需要输出不止一个字母E，故根据编号在不同位置输出字母E
***************************************************************************/
void cover::E_print(const int E_num)
{
	int x = 0, y = 0;
	int bg_color = COLOR_BLACK;

	switch (E_num) {  /*根据要打印的字母E设置坐标和颜色*/
	case 1:
		x = E_COORD_X1, y = E_COORD_Y1;
		break;
	case 2:
		x = E_COORD_X2, y = E_COORD_Y2;
		bg_color = E_COLOR2;
		break;
	case 3:
		x = E_COORD_X3, y = E_COORD_Y3;
		bg_color = E_COLOR3;
		break;
	case 4:
		x = E_COORD_X4, y = E_COORD_Y4;
		bg_color = E_COLOR4;
		break;
	}

	/*根据设置的坐标和颜色打印字母*/
	cct_showstr(x, y, "     ", bg_color);
	cct_showch(x, y + 1, ' ', bg_color);
	cct_showstr(x, y + 2, "     ", bg_color);
	cct_showch(x, y + 3, ' ', bg_color);
	cct_showstr(x, y + 4, "     ", bg_color);
}

/***************************************************************************
  函数名称：S_print
  功    能：打印一个字母S
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::S_print()
{
	cct_showstr(S_COORD_X, S_COORD_Y, "     ", S_COLOR);
	cct_showch(S_COORD_X, S_COORD_Y + 1, ' ', S_COLOR);
	cct_showstr(S_COORD_X, S_COORD_Y + 2, "     ", S_COLOR);
	cct_showch(S_COORD_X + 4, S_COORD_Y + 3, ' ', S_COLOR);
	cct_showstr(S_COORD_X, S_COORD_Y + 4, "     ", S_COLOR);
}

/***************************************************************************
  函数名称：W_print
  功    能：打印一个字母W
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::W_print()
{
	int i, j;

	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			cct_showch(W_COORD_X + 4 * j, W_COORD_Y + i, ' ', W_COLOR);

	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++)
			cct_showch(W_COORD_X + 2 * j + 1, W_COORD_Y + 2 + i, ' ', W_COLOR);

	for (i = 0; i < 2; i++)
		cct_showch(W_COORD_X + 4 * i + 2, W_COORD_Y + 4, ' ', W_COLOR);
}

/***************************************************************************
  函数名称：P_print
  功    能：打印一个字母P
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void cover::P_print()
{
	cct_showstr(P_COORD_X, P_COORD_Y, "     ", P_COLOR);
	cct_showch(P_COORD_X, P_COORD_Y + 1, ' ', P_COLOR);
	cct_showch(P_COORD_X + 4, P_COORD_Y + 1, ' ', P_COLOR);
	cct_showstr(P_COORD_X, P_COORD_Y + 2, "     ", P_COLOR);
	cct_showch(P_COORD_X, P_COORD_Y + 3, ' ', P_COLOR);
	cct_showch(P_COORD_X, P_COORD_Y + 4, ' ', P_COLOR);
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
  函数名称：bomb_print
  功    能：打印地雷
  输入参数：无
  返 回 值：无
  说    明：1、本函数在标题画面上打印地雷，增强画面效果
            2、打印的同时将每个地雷的位置信息存放在对应的结构体中
***************************************************************************/
void cover::bomb_print()
{
	for (int i = 0; i < 20; i++) {
		int x = rand() % 76 + 2;  /*随机取横坐标*/
		int y = rand() % 16 + 1;  /*随机取横坐标*/

		bomb_coord[i].x = x;  /*记录当前横坐标*/
		bomb_coord[i].y = y;  /*记录当前纵坐标*/

		cct_showch(x, y, '*', COLOR_WHITE, COLOR_BLACK);  /*打印地雷*/
	}
}

/***************************************************************************
  函数名称：bomb_reprint
  功    能：根据第一次打印时存储的坐标信息，重新打印地雷
  输入参数：无
  返 回 值：无
  说    明：本函数在标题画面上打印地雷，增强画面效果
***************************************************************************/
void cover::bomb_reprint()
{
	for (int i = 0; i < 20; i++)
		cct_showch(bomb_coord[i].x, bomb_coord[i].y, '*', COLOR_WHITE, COLOR_BLACK);
}

/***************************************************************************
  函数名称：button_reprint
  功    能：重新打印标题画面中的一些按键
  输入参数：无
  返 回 值：无
  说    明：仅重画了上三个按键
***************************************************************************/
void cover::button_reprint()
{
	button_easy.act(DEFAULT);    /*重画“简单”键*/
	button_medium.act(DEFAULT);  /*重画“中等”键*/
	button_hard.act(DEFAULT);    /*重画“困难”键*/
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
	int i;

	/*1、打印标题画面背景*/
	cct_showstr(0, 0, "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓", COLOR_WHITE, COLOR_BLACK);
	for (i = 0; i < COVER_WIDTH - 2; i++) {
		cct_showstr(0, i + 1, "┃                                                                            ┃", COLOR_WHITE, COLOR_BLACK);
		Sleep(10);
	}
	cct_showstr(0, COVER_WIDTH - 1, "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛", COLOR_WHITE, COLOR_BLACK);

	/*2、打印地雷和所有字母*/
	bomb_print();
	PRINT_ALL_LETTERS
	
	/*3、打印按键*/
	Sleep(100);
	button_easy.act(DEFAULT);
	button_medium.act(DEFAULT);
	button_hard.act(DEFAULT);
	button_diy.act(DEFAULT);
	button_options.act(DEFAULT);
	button_quit.act(DEFAULT);
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

	if (X >= EASY_COORD_X && X <= EASY_COORD_X + 11 && Y >= EASY_COORD_Y && Y <= EASY_COORD_Y + 2)              /*判断是否在“简单”键上*/
		p[0] = true;
	if (X >= MEDIUM_COORD_X && X <= MEDIUM_COORD_X + 11 && Y >= MEDIUM_COORD_Y && Y <= MEDIUM_COORD_Y + 2)      /*判断是否在“中等”键上*/
		p[1] = true;
	if (X >= HARD_COORD_X && X <= HARD_COORD_X + 11 && Y >= HARD_COORD_Y && Y <= HARD_COORD_Y + 2)              /*判断是否在“困难”键上*/
		p[2] = true;
	if (X >= DIY_COORD_X && X <= DIY_COORD_X + 11 && Y >= DIY_COORD_Y && Y <= DIY_COORD_Y + 2)                  /*判断是否在“自定义”键上*/
		p[3] = true;
	if (X >= OPTIONS_COORD_X && X <= OPTIONS_COORD_X + 11 && Y >= OPTIONS_COORD_Y && Y <= OPTIONS_COORD_Y + 2)  /*判断是否在“设置”键上*/
		p[4] = true;
	if (X >= QUIT_COORD_X && X <= QUIT_COORD_X + 11 && Y >= QUIT_COORD_Y && Y <= QUIT_COORD_Y + 2)              /*判断是否在“退出”键上*/
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
		button_easy.act(DEFAULT);     /*“简单”键取消高亮*/
		break;
	case 2:
		button_medium.act(DEFAULT);   /*“中等”键取消高亮*/
		break;
	case 3:
		button_hard.act(DEFAULT);     /*“困难”键取消高亮*/
		break;
	case 4:
		button_diy.act(DEFAULT);      /*“自定义”键取消高亮*/
		break;
	case 5:
		button_options.act(DEFAULT);  /*“设置”键取消高亮*/
		break;
	case 6:
		button_quit.act(DEFAULT);     /*“退出”键取消高亮*/
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
		button_easy.act(ACTIVATE);     /*“简单”键设置高亮*/
		break;
	case 2:
		button_medium.act(ACTIVATE);   /*“中等”键设置高亮*/
		break;
	case 3:
		button_hard.act(ACTIVATE);     /*“困难”键设置高亮*/
		break;
	case 4:
		button_diy.act(ACTIVATE);      /*“自定义”键设置高亮*/
		break;
	case 5:
		button_options.act(ACTIVATE);  /*“设置”键设置高亮*/
		break;
	case 6:
		button_quit.act(ACTIVATE);     /*“退出”键设置高亮*/
		break;
	}
}

/***************************************************************************
  函数名称：control
  功    能：用键鼠在标题画面上进行操作
  输入参数：无
  返 回 值：int：进行的操作
  说    明：无
***************************************************************************/
int cover::control()
{
	int X = 0, Y = 0;  /*横纵坐标，初始均为零*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*函数的返回值*/

	cct_enable_mouse();  /*启用鼠标*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*读鼠标/键盘*/
		selective_default(DEFAULT_ALL);  /*取消标题画面所有按键的高亮*/

		int RET = if_button(X, Y);  /*判断此时鼠标的位置是否在某个按键中*/
		selective_activate(RET);    /*若在某个按键中，将对应的按键设置高亮*/

		/*1、若返回的是鼠标事件并且按下左键*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {
			switch (RET) {
			case 1:
				result = COVER_EASY, loop = 0;     /*取返回值、结束循环*/
				break;
			case 2:
				result = COVER_MEDIUM, loop = 0;   /*取返回值、结束循环*/
				break;
			case 3:
				result = COVER_HARD, loop = 0;     /*取返回值、结束循环*/
				break;
			case 4:
				result = COVER_DIY, loop = 0;      /*取返回值、结束循环*/
				break;
			case 5:
				result = COVER_OPTIONS, loop = 0;  /*取返回值、结束循环*/
				break;
			case 6:
				result = COVER_QUIT, loop = 0;     /*取返回值、结束循环*/
				break;
			}
		}
	}

	cct_disable_mouse();	//禁用鼠标
	return result;
}