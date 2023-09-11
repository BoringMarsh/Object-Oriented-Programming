#include"90-b3.h"

/***************************************************************************
  函数名称：set_button_type
  功    能：给按键设置种类
  输入参数：无
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void cover::set_button_type()
{
	button_new.set_type(CV_NEW);          /*“新游戏”键设置种类*/
	button_load.set_type(CV_LOAD);        /*“载入游戏”键设置种类*/
	button_auto.set_type(CV_AUTO);        /*“自动游戏”键设置种类*/
	button_options.set_type(CV_OPTIONS);  /*“设置”键设置种类*/
	button_about.set_type(CV_ABOUT);      /*“关于”键设置种类*/
	button_quit.set_type(CV_QUIT);        /*“退出游戏”键设置种类*/
}

/***************************************************************************
  函数名称：set_button_coord
  功    能：给按键坐标赋值
  输入参数：无
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void cover::set_button_coord()
{
	button_new.set_coord(NEW_COORD_X, NEW_COORD_Y);              /*“新游戏”键坐标赋值*/
	button_load.set_coord(LOAD_COORD_X, LOAD_COORD_Y);           /*“载入游戏”键坐标赋值*/
	button_auto.set_coord(AUTO_COORD_X, AUTO_COORD_Y);           /*“自动游戏”键坐标赋值*/
	button_options.set_coord(OPTIONS_COORD_X, OPTIONS_COORD_Y);  /*“设置”键坐标赋值*/
	button_about.set_coord(ABOUT_COORD_X, ABOUT_COORD_Y);        /*“关于”键坐标赋值*/
	button_quit.set_coord(QUIT_COORD_X, QUIT_COORD_Y);           /*“退出游戏”键坐标赋值*/
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
	cct_setconsoleborder(44, COVER_WIDTH + 2);  /*设置窗口大小，除去黑边*/
	int i;

	/*1、打印标题画面背景*/
	cct_showstr(0, 0, "┏━━━━━━━━━━━━━━━━━━━━┓", COLOR_WHITE, COLOR_BLACK);
	for (i = 0; i < COVER_WIDTH - 2; i++) {
		cct_showstr(0, i + 1, "┃                                        ┃", COLOR_WHITE, COLOR_BLACK);
		Sleep(10);
	}
	cct_showstr(0, COVER_WIDTH - 1, "┗━━━━━━━━━━━━━━━━━━━━┛", COLOR_WHITE, COLOR_BLACK);

	/*2、打印数字“2”*/
	Sleep(100);
	cct_showstr(TWO_COORD_X, TWO_COORD_Y, "     ", COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X + 4, TWO_COORD_Y + 1, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X + 4, TWO_COORD_Y + 2, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showstr(TWO_COORD_X, TWO_COORD_Y + 3, "     ", COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X, TWO_COORD_Y + 4, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X, TWO_COORD_Y + 5, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showstr(TWO_COORD_X, TWO_COORD_Y + 6, "     ", COLOR_HRED, COLOR_BLACK);

	/*3、打印数字“0”*/
	Sleep(100);
	cct_showstr(ZERO_COORD_X, ZERO_COORD_Y, "     ", COLOR_HYELLOW, COLOR_BLACK);
	for (i = 0; i < 5; i++) {
		cct_showch(ZERO_COORD_X, ZERO_COORD_Y + 1 + i, ' ', COLOR_HYELLOW, COLOR_BLACK);
		cct_showch(ZERO_COORD_X + 4, ZERO_COORD_Y + 1 + i, ' ', COLOR_HYELLOW, COLOR_BLACK);
	}
	cct_showstr(ZERO_COORD_X, ZERO_COORD_Y + 6, "     ", COLOR_HYELLOW, COLOR_BLACK);

	/*4、打印数字“4”*/
	Sleep(100);
	for (i = 0; i < 3; i++) {
		cct_showch(FOUR_COORD_X, FOUR_COORD_Y + i, ' ', COLOR_HBLUE, COLOR_BLACK);
		cct_showch(FOUR_COORD_X + 4, FOUR_COORD_Y + i, ' ', COLOR_HBLUE, COLOR_BLACK);
	}
	cct_showstr(FOUR_COORD_X, FOUR_COORD_Y + 3, "     ", COLOR_HBLUE, COLOR_BLACK);
	for (i = 0; i < 3; i++) {
		cct_showch(FOUR_COORD_X + 4, FOUR_COORD_Y + 4 + i, ' ', COLOR_HBLUE, COLOR_BLACK);
	}

	/*5、打印数字“8”*/
	Sleep(100);
	cct_showstr(EIGHT_COORD_X, EIGHT_COORD_Y, "     ", COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X, EIGHT_COORD_Y + 1, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X + 4, EIGHT_COORD_Y + 1, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X, EIGHT_COORD_Y + 2, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X + 4, EIGHT_COORD_Y + 2, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showstr(EIGHT_COORD_X, EIGHT_COORD_Y + 3, "     ", COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X, EIGHT_COORD_Y + 4, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X + 4, EIGHT_COORD_Y + 4, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X, EIGHT_COORD_Y + 5, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X + 4, EIGHT_COORD_Y + 5, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showstr(EIGHT_COORD_X, EIGHT_COORD_Y + 6, "     ", COLOR_HGREEN, COLOR_BLACK);

	/*6、打印按键*/
	Sleep(100);
	button_new.act(DEFAULT);
	button_load.act(DEFAULT);
	button_auto.act(DEFAULT);
	button_options.act(DEFAULT);
	button_about.act(DEFAULT);
	button_quit.act(DEFAULT);

	/*7、打印版本号*/
	cct_showstr(CVVER_COORD_X, CVVER_COORD_Y, __GAME.version, COLOR_WHITE, COLOR_BLACK);
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

	if (X >= NEW_COORD_X && X <= NEW_COORD_X + 11 && Y >= NEW_COORD_Y && Y <= NEW_COORD_Y + 2)                  /*判断是否在“新游戏”键上*/
		p[0] = true;
	if (X >= LOAD_COORD_X && X <= LOAD_COORD_X + 11 && Y >= LOAD_COORD_Y && Y <= LOAD_COORD_Y + 2)              /*判断是否在“载入游戏”键上*/
		p[1] = true;
	if (X >= AUTO_COORD_X && X <= AUTO_COORD_X + 11 && Y >= AUTO_COORD_Y && Y <= AUTO_COORD_Y + 2)              /*判断是否在“自动游戏”键上*/
		p[2] = true;
	if (X >= OPTIONS_COORD_X && X <= OPTIONS_COORD_X + 11 && Y >= OPTIONS_COORD_Y && Y <= OPTIONS_COORD_Y + 2)  /*判断是否在“设置”键上*/
		p[3] = true;
	if (X >= ABOUT_COORD_X && X <= ABOUT_COORD_X + 11 && Y >= ABOUT_COORD_Y && Y <= ABOUT_COORD_Y + 2)          /*判断是否在“关于”键上*/
		p[4] = true;
	if (X >= QUIT_COORD_X && X <= QUIT_COORD_X + 11 && Y >= QUIT_COORD_Y && Y <= QUIT_COORD_Y + 2)              /*判断是否在“退出游戏”键上*/
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
		button_auto.act(DEFAULT);     /*“自动游戏”键取消高亮*/
		break;
	case 4:
		button_options.act(DEFAULT);  /*“设置”键取消高亮*/
		break;
	case 5:
		button_about.act(DEFAULT);    /*“关于”键取消高亮*/
		break;
	case 6:
		button_quit.act(DEFAULT);     /*“退出游戏”键取消高亮*/
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
		button_auto.act(ACTIVATE);     /*“自动游戏”键设置高亮*/
		break;
	case 4:
		button_options.act(ACTIVATE);  /*“设置”键设置高亮*/
		break;
	case 5:
		button_about.act(ACTIVATE);    /*“关于”键设置高亮*/
		break;
	case 6:
		button_quit.act(ACTIVATE);     /*“退出游戏”键设置高亮*/
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
				result = COVER_NEW, loop = 0;       /*取返回值、结束循环*/
				break;
			case 2:
				result = COVER_LOAD, loop = 0;      /*取返回值、结束循环*/
				break;
			case 3:
				result = COVER_AUTO, loop = 0;      /*取返回值、结束循环*/
				break;
			case 4:
				result = COVER_OPTIONS, loop = 0;   /*取返回值、结束循环*/
				break;
			case 5:
				result = COVER_ABOUT, loop = 0;     /*取返回值、结束循环*/
				break;
			case 6:
				result = COVER_QUIT, loop = 0;      /*取返回值、结束循环*/
				break;
			}
		}
	}

	cct_disable_mouse();	//禁用鼠标
	return result;
}