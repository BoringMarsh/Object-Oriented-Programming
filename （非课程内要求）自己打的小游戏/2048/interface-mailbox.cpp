#include"90-b3.h"

/***************************************************************************
  函数名称：set_button_type
  功    能：给按键设置种类
  输入参数：无
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void game_mailbox::set_button_type()
{
	button_yes.set_type(GMMB_YES);        /*“是”键设置种类*/
	button_no.set_type(GMMB_NO);          /*“否”键设置种类*/
	button_sure.set_type(GMMB_SURE);      /*“确定”键设置种类*/
	button_one.set_type(GMMB_ONE);        /*“1”键设置种类*/
	button_two.set_type(GMMB_TWO);        /*“2”键设置种类*/
	button_three.set_type(GMMB_THREE);    /*“3”键设置种类*/
	button_four.set_type(GMMB_FOUR);      /*“4”键设置种类*/
	button_cancel.set_type(GMMB_CANCEL);  /*“取消”键设置种类*/
	switch_one[0].set_type(GMMB_SW11);    /*开关1按键1设置种类*/
	switch_one[1].set_type(GMMB_SW12);    /*开关1按键2设置种类*/
	switch_two[0].set_type(GMMB_SW21);    /*开关2按键1设置种类*/
	switch_two[1].set_type(GMMB_SW22);    /*开关2按键2设置种类*/
}

/***************************************************************************
  函数名称：set_button_coord
  功    能：给按键坐标赋值
  输入参数：无
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void game_mailbox::set_button_coord()
{
	button_yes.set_coord(GMYES_COORD_X, GMYES_COORD_Y);           /*“是”键坐标赋值*/
	button_no.set_coord(GMNO_COORD_X, GMNO_COORD_Y);              /*“否”键坐标赋值*/
	button_sure.set_coord(GMSURE_COORD_X, GMSURE_COORD_Y);        /*“确定”键坐标赋值*/
	button_one.set_coord(GMONE_COORD_X, GMONE_COORD_Y);           /*“1”键坐标赋值*/
	button_two.set_coord(GMTWO_COORD_X, GMTWO_COORD_Y);           /*“2”键坐标赋值*/
	button_three.set_coord(GMTHREE_COORD_X, GMTHREE_COORD_Y);     /*“3”键坐标赋值*/
	button_four.set_coord(GMFOUR_COORD_X, GMFOUR_COORD_Y);        /*“4”键坐标赋值*/
	button_cancel.set_coord(GMCANCEL_COORD_X, GMCANCEL_COORD_Y);  /*“取消”键坐标赋值*/
	switch_one[0].set_coord(GMSW11_COORD_X, GMSW11_COORD_Y);      /*开关1按键1坐标赋值*/
	switch_one[1].set_coord(GMSW12_COORD_X, GMSW12_COORD_Y);      /*开关1按键2坐标赋值*/
	switch_two[0].set_coord(GMSW21_COORD_X, GMSW21_COORD_Y);      /*开关2按键1坐标赋值*/
	switch_two[1].set_coord(GMSW22_COORD_X, GMSW22_COORD_Y);      /*开关2按键2坐标赋值*/
}

/***************************************************************************
  函数名称：print
  功    能：打印游戏内对话框
  输入参数：const int button_mode：按键形式（只读）
			const char* prompt1：提示语1（只读，默认为空指针）
			const char* prompt2：提示语2（只读，默认为空指针）
			const char* prompt3：提示语3（只读，默认为空指针）
  返 回 值：无
  说    明：无
***************************************************************************/
void game_mailbox::print(const int button_mode, const char* prompt1, const char* prompt2, const char* prompt3)
{
	IF_GMMB = button_mode;       /*根据对话框按键种类调整标记变量，标志对话框已出现*/

	/*1、打印对话框外形*/
	cct_showstr(GMMB_COORD_X, GMMB_COORD_Y, "┏━━━━━━━━━━━┓", GMMB_BG_COLOR, GMMB_FG_COLOR);
	cct_showstr(GMMB_COORD_X - 2, GMMB_COORD_Y + 1, "┏┛                      ┗┓", GMMB_BG_COLOR, GMMB_FG_COLOR);
	for (int i = 0; i < GMMB_WIDTH - 4; i++) {
		cct_showstr(GMMB_COORD_X - 2, GMMB_COORD_Y + 2 + i, "┃                          ┃", GMMB_BG_COLOR, GMMB_FG_COLOR);
	}
	cct_showstr(GMMB_COORD_X - 2, GMMB_COORD_Y + GMMB_WIDTH - 2, "┗┓                      ┏┛", GMMB_BG_COLOR, GMMB_FG_COLOR);
	cct_showstr(GMMB_COORD_X, GMMB_COORD_Y + GMMB_WIDTH - 1, "┗━━━━━━━━━━━┛", GMMB_BG_COLOR, GMMB_FG_COLOR);

	/*2、打印对话框提示语*/
	cct_showstr(GMPROM_COORD_X, GMPROM_COORD_Y, prompt1, GMMB_BG_COLOR, COLOR_BLACK);
	cct_showstr(GMPROM_COORD_X - 2, GMPROM_COORD_Y + 1, prompt2, GMMB_BG_COLOR, COLOR_BLACK);
	cct_showstr(GMPROM_COORD_X - 2, GMPROM_COORD_Y + 2, prompt3, GMMB_BG_COLOR, COLOR_BLACK);

	/*3、根据按键形式打印对话框按键*/
	if (button_mode == BUTTON_TWO) {  /*双键式*/
		button_yes.act(DEFAULT);  /*打印“是”键*/
		button_no.act(DEFAULT);   /*打印“否”键*/
	}

	else if (button_mode == BUTTON_ONE)  /*单键式*/
		button_sure.act(DEFAULT);  /*打印“确定”键*/

	else if (button_mode == BUTTON_FIVE) {  /*五键式*/
		button_one.act(DEFAULT);     /*打印“1”键*/
		button_two.act(DEFAULT);     /*打印“2”键*/
		button_three.act(DEFAULT);   /*打印“3”键*/
		button_four.act(DEFAULT);    /*打印“4”键*/
		button_cancel.act(DEFAULT);  /*打印“取消”键*/
	}

	else if (button_mode == BUTTON_SWITCH) {  /*开关式*/
		cct_showstr(GMSW11_COORD_X, GMSW11_COORD_Y + 1, "       ", COLOR_HCYAN);  /*打印开关1的滑动条*/
		cct_showstr(GMSW21_COORD_X, GMSW21_COORD_Y + 1, "       ", COLOR_HCYAN);  /*打印开关2的滑动条*/
		button_sure.act(DEFAULT);  /*打印“确定”键*/

		if (__GAME.if_blink) {  /*打印开关1按键1以及当前状态*/
			cct_showstr(GMSW1P_COORD_X, GMSW1P_COORD_Y, "开", GMMB_BG_COLOR, GMMB_FG_COLOR);
			switch_one[0].act(DEFAULT);
		}
		else {  /*打印开关1按键2以及当前状态*/
			cct_showstr(GMSW1P_COORD_X, GMSW1P_COORD_Y, "关", GMMB_BG_COLOR, GMMB_FG_COLOR);
			switch_one[1].act(DEFAULT);
		}
		if (__GAME.if_tips) {  /*打印开关2按键1以及当前状态*/
			cct_showstr(GMSW2P_COORD_X, GMSW2P_COORD_Y, "开", GMMB_BG_COLOR, GMMB_FG_COLOR);
			switch_two[0].act(DEFAULT);
		}
		else {  /*打印开关2按键2以及当前状态*/
			cct_showstr(GMSW2P_COORD_X, GMSW2P_COORD_Y, "关", GMMB_BG_COLOR, GMMB_FG_COLOR);
			switch_two[1].act(DEFAULT);
		}
	}
}

/***************************************************************************
  函数名称：mouse_if_button
  功    能：判断鼠标位置是否在某一按键上
  输入参数：const int X：鼠标位置横坐标（只读）
			const int Y：鼠标位置纵坐标（只读）
  返 回 值：int：鼠标在哪一按键上
  说    明：无
***************************************************************************/
int game_mailbox::mouse_if_button(const int X, const int Y)
{
	int ret = 0;  /*返回值*/
	bool p[GMMB_BUTTON_NUM];
	for (int i = 0; i < GMMB_BUTTON_NUM; i++)
		p[i] = false;

	if ((X == GMYES_COORD_X || X == GMYES_COORD_X + 1) && (Y == GMYES_COORD_Y || Y == GMYES_COORD_Y + 1))            /*判断是否在“是”键上*/
		p[0] = true;
	if ((X == GMNO_COORD_X || X == GMNO_COORD_X + 1) && (Y == GMNO_COORD_Y || Y == GMNO_COORD_Y + 1))                /*判断是否在“否”键上*/
		p[1] = true;
	if (X >= GMSURE_COORD_X && X <= GMSURE_COORD_X + 3 && (Y == GMSURE_COORD_Y || Y == GMSURE_COORD_Y + 1))          /*判断是否在“确定”键上*/
		p[2] = true;
	if ((X == GMONE_COORD_X || X == GMONE_COORD_X + 1) && (Y == GMONE_COORD_Y || Y == GMONE_COORD_Y + 1))            /*判断是否在“1”键上*/
		p[3] = true;
	if ((X == GMTWO_COORD_X || X == GMTWO_COORD_X + 1) && (Y == GMTWO_COORD_Y || Y == GMTWO_COORD_Y + 1))            /*判断是否在“2”键上*/
		p[4] = true;
	if ((X == GMTHREE_COORD_X || X == GMTHREE_COORD_X + 1) && (Y == GMTHREE_COORD_Y || Y == GMTHREE_COORD_Y + 1))    /*判断是否在“3”键上*/
		p[5] = true;
	if ((X == GMFOUR_COORD_X || X == GMFOUR_COORD_X + 1) && (Y == GMFOUR_COORD_Y || Y == GMFOUR_COORD_Y + 1))        /*判断是否在“4”键上*/
		p[6] = true;
	if (X >= GMCANCEL_COORD_X && X <= GMCANCEL_COORD_X + 3 && (Y == GMCANCEL_COORD_Y || Y == GMCANCEL_COORD_Y + 1))  /*判断是否在“取消”键上*/
		p[7] = true;
	if (X == GMSW11_COORD_X && (Y == GMSW11_COORD_Y || Y == GMSW11_COORD_Y + 1))  /*判断是否在开关1按键1上*/
		p[8] = true;
	if (X == GMSW12_COORD_X && (Y == GMSW12_COORD_Y || Y == GMSW12_COORD_Y + 1))  /*判断是否在开关1按键2上*/
		p[9] = true;
	if (X == GMSW21_COORD_X && (Y == GMSW21_COORD_Y || Y == GMSW21_COORD_Y + 1))  /*判断是否在开关2按键1上*/
		p[10] = true;
	if (X == GMSW22_COORD_X && (Y == GMSW22_COORD_Y || Y == GMSW22_COORD_Y + 1))  /*判断是否在开关2按键2上*/
		p[11] = true;

	/*检查各个位置的情况，遇到真并且与按键形式对应，则取对应返回值后结束检查*/
	switch (IF_GMMB) {
	case BUTTON_TWO:
		for (int i = 0; i < 2; i++) {  /*双键式按键的检查*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_ONE:
		for (int i = 2; i < 3; i++) {  /*单键式按键的检查*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_FIVE:
		for (int i = 3; i < 8; i++) {  /*五键式按键的检查*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_SWITCH:                /*开关式按键的检查*/
		if (p[2])
			ret = 3;
		if (__GAME.if_blink && p[8])
			ret = 9;
		else if (!__GAME.if_blink && p[9])
			ret = 10;
		if (__GAME.if_tips && p[10])
			ret = 11;
		else if (!__GAME.if_tips && p[11])
			ret = 12;
		break;
	}

	return ret;
}

/***************************************************************************
  函数名称：keyboard_if_button
  功    能：判断键盘按下的按键是否为对话框内的某一按键
  输入参数：const int keycode：键码（只读）
  返 回 值：int：键盘按下了哪一按键
  说    明：无
***************************************************************************/
int game_mailbox::keyboard_if_button(const int keycode)
{
	int ret = 0;

	if (keycode == 'Y' || keycode == 'y')         /*判断是否按下了“是”键*/
		ret = 1;
	else if (keycode == 'N' || keycode == 'n')    /*判断是否按下了“否”键*/
		ret = 2;
	else if (keycode == '\n' || keycode == '\r')  /*判断是否按下了“确定”键*/
		ret = 3;
	else if (keycode >= '1' && keycode <= '4')    /*判断是否按下了某个数字键*/
		ret = keycode - '0' + 3;
	else if (keycode == 'C' || keycode == 'c')    /*判断是否按下了“取消”键*/
		ret = 8;

	return ret;
}

/***************************************************************************
  函数名称：selective_default
  功    能：选择性地为某一按键取消高亮
  输入参数：const int selection：按键选择（只读）
  返 回 值：无
  说    明：1、当选择为DEFAULT_ALL时，通过递归调用取消所有按键的高亮
			2、只有当按键选择与按键模式对应时才进行操作
***************************************************************************/
void game_mailbox::selective_default(const int selection)
{
	switch (selection) {
	case 1:
		if (IF_GMMB == BUTTON_TWO)   /*“是”键取消高亮*/
			button_yes.act(DEFAULT);
		break;
	case 2:
		if (IF_GMMB == BUTTON_TWO)   /*“否”键取消高亮*/
			button_no.act(DEFAULT);
		break;
	case 3:
		if (IF_GMMB == BUTTON_ONE || IF_GMMB == BUTTON_SWITCH)   /*“确定”键取消高亮*/
			button_sure.act(DEFAULT);
		break;
	case 4:
		if (IF_GMMB == BUTTON_FIVE)  /*“1”键取消高亮*/
			button_one.act(DEFAULT);
		break;
	case 5:
		if (IF_GMMB == BUTTON_FIVE)  /*“2”键取消高亮*/
			button_two.act(DEFAULT);
		break;
	case 6:
		if (IF_GMMB == BUTTON_FIVE)  /*“3”键取消高亮*/
			button_three.act(DEFAULT);
		break;
	case 7:
		if (IF_GMMB == BUTTON_FIVE)  /*“4”键取消高亮*/
			button_four.act(DEFAULT);
		break;
	case 8:
		if (IF_GMMB == BUTTON_FIVE)  /*“取消”键取消高亮*/
			button_cancel.act(DEFAULT);
		break;
	case 9:
		if (IF_GMMB == BUTTON_SWITCH && __GAME.if_blink)   /*开关1按键1取消高亮*/
			switch_one[0].act(DEFAULT);
		break;
	case 10:
		if (IF_GMMB == BUTTON_SWITCH && !__GAME.if_blink)  /*开关1按键2取消高亮*/
			switch_one[1].act(DEFAULT);
		break;
	case 11:
		if (IF_GMMB == BUTTON_SWITCH && __GAME.if_tips)    /*开关2按键1取消高亮*/
			switch_two[0].act(DEFAULT);
		break;
	case 12:
		if (IF_GMMB == BUTTON_SWITCH && !__GAME.if_tips)   /*开关2按键2取消高亮*/
			switch_two[1].act(DEFAULT);
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < GMMB_BUTTON_NUM; i++)  /*所有按键取消高亮*/
			selective_default(i + 1);
		break;
	}
}

/***************************************************************************
  函数名称：selective_activate
  功    能：选择性地为某一按键设置高亮
  输入参数：const int selection：按键选择（只读）
  返 回 值：无
  说    明：只有当按键选择与按键模式对应时才进行操作
***************************************************************************/
void game_mailbox::selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		if (IF_GMMB == BUTTON_TWO)   /*“是”键设置高亮*/
			button_yes.act(ACTIVATE);
		break;
	case 2:
		if (IF_GMMB == BUTTON_TWO)   /*“否”键设置高亮*/
			button_no.act(ACTIVATE);
		break;
	case 3:
		if (IF_GMMB == BUTTON_ONE || IF_GMMB == BUTTON_SWITCH)   /*“确定”键设置高亮*/
			button_sure.act(ACTIVATE);
		break;
	case 4:
		if (IF_GMMB == BUTTON_FIVE)  /*“1”键设置高亮*/
			button_one.act(ACTIVATE);
		break;
	case 5:
		if (IF_GMMB == BUTTON_FIVE)  /*“2”键设置高亮*/
			button_two.act(ACTIVATE);
		break;
	case 6:
		if (IF_GMMB == BUTTON_FIVE)  /*“3”键设置高亮*/
			button_three.act(ACTIVATE);
		break;
	case 7:
		if (IF_GMMB == BUTTON_FIVE)  /*“4”键设置高亮*/
			button_four.act(ACTIVATE);
		break;
	case 8:
		if (IF_GMMB == BUTTON_FIVE)  /*“取消”键设置高亮*/
			button_cancel.act(ACTIVATE);
		break;
	case 9:
		if (IF_GMMB == BUTTON_SWITCH && __GAME.if_blink)   /*开关1按键1设置高亮*/
			switch_one[0].act(ACTIVATE);
		break;
	case 10:
		if (IF_GMMB == BUTTON_SWITCH && !__GAME.if_blink)  /*开关1按键2设置高亮*/
			switch_one[1].act(ACTIVATE);
		break;
	case 11:
		if (IF_GMMB == BUTTON_SWITCH && __GAME.if_tips)    /*开关2按键1设置高亮*/
			switch_two[0].act(ACTIVATE);
		break;
	case 12:
		if (IF_GMMB == BUTTON_SWITCH && !__GAME.if_tips)   /*开关2按键2设置高亮*/
			switch_two[1].act(ACTIVATE);
		break;
	}
}

/***************************************************************************
  函数名称：control
  功    能：用键鼠在游戏内对话框内进行操作
  输入参数：无
  返 回 值：int：进行的操作
  说    明：无
***************************************************************************/
int game_mailbox::control()
{
	int X = 0, Y = 0;  /*横纵坐标，初始均为零*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*函数的返回值*/

	cct_enable_mouse();  /*启用鼠标*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*读鼠标/键盘*/
		selective_default(DEFAULT_ALL);  /*取消对话框所有按键的高亮*/

		int RET1 = mouse_if_button(X, Y);         /*判断此时鼠标的位置是否在某个按键中*/
		int RET2 = keyboard_if_button(keycode1);  /*判断此时键盘按下的按钮是否为某个按键*/
		selective_activate(RET1);  /*若鼠标在某个按键中，将对应的按键设置高亮*/

		/*1、若返回的是鼠标事件并且按下左键*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {

			switch (IF_GMMB) {  /*根据对应的对话框状态进行操作，避免按键之间互相干扰*/
			case BUTTON_TWO:
				if (RET1 >= 1 && RET1 <= 2) {
					selective_default(RET1);       /*取消高亮、延时再设置高亮，营造按键效果*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_GMMB = 0;         /*对话框状态置零*/
				}

				result = RET1 + GMMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			case BUTTON_ONE:
				if (RET1 == 3) {
					selective_default(RET1);       /*取消高亮、延时再设置高亮，营造按键效果*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_GMMB = 0;         /*对话框状态置零*/
				}

				result = RET1 + GMMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			case BUTTON_FIVE:
				if (RET1 >= 4 && RET1 <= 8) {
					selective_default(RET1);       /*取消高亮、延时再设置高亮，营造按键效果*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_GMMB = 0;         /*对话框状态置零*/
				}

				result = RET1 + GMMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			case BUTTON_SWITCH:
				if (RET1 == 3 || (RET1 >= 9 && RET1 <= 12)) {
					selective_default(RET1);       /*取消高亮、延时再设置高亮，营造按键效果*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0;
				}

				if (RET1 == 3)                     /*若按“确定”键，对话框状态置零*/
					IF_GMMB = 0;
				result = RET1 + GMMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			}
		}

		/*2、若返回的是键盘事件*/
		else if (ret == CCT_KEYBOARD_EVENT) {
			switch (IF_GMMB) {    /*根据对应的对话框状态进行操作，避免按键之间互相干扰*/
			case BUTTON_TWO:
				if (RET2 >= 1 && RET2 <= 2) {
					selective_activate(RET2);      /*设置高亮、延时再取消高亮，营造按键效果*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_GMMB = 0;         /*对话框状态置零*/
				}

				result = RET2 + GMMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			case BUTTON_ONE:
				if (RET2 == 3) {
					selective_activate(RET2);      /*设置高亮、延时再取消高亮，营造按键效果*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_GMMB = 0;         /*对话框状态置零*/
				}

				result = RET2 + GMMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			case BUTTON_FIVE:
				if (RET2 >= 4 && RET2 <= 8) {
					selective_activate(RET2);      /*设置高亮、延时再取消高亮，营造按键效果*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_GMMB = 0;         /*对话框状态置零*/
				}

				result = RET2 + GMMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			}
		}
	}

	cct_disable_mouse();	//禁用鼠标
	return result;
}

/***************************************************************************
  函数名称：erase
  功    能：重画游戏面板，达到擦除对话框的效果
  输入参数：无
  返 回 值：无
  说    明：本函数重画了对话框对应的那几行以及所有色块
***************************************************************************/
void game_mailbox::erase()
{
	cct_gotoxy(0, GMMB_COORD_Y);  /*移动光标*/
	cct_setcolor();            /*重设颜色*/

	for (int Y = GMMB_COORD_Y; Y <= GMMB_COORD_Y + GMMB_WIDTH - 1; Y++)/*按行重画面板底盘*/
		__GAME.gameboard.chessboard_multiple_lines(Y, false);  /*输出不同形式的每一行*/

	__GAME.gameboard.block_multiple_print();  /*重画所有色块*/
}

/***************************************************************************
  函数名称：options
  功    能：完成游戏内对话框中的各种设置
  输入参数：const int options：设置（只读）
  返 回 值：无
  说    明：本函数根据对应设置，先改变布尔值、消除原按键、输出当前状态，然后再重画原按键
***************************************************************************/
void game_mailbox::options(const int options)
{
	switch (options) {
	case GMMB_RET_BLINK_OFF:  /*关闭色块闪烁*/
		__GAME.if_blink = false;
		cct_showch(GMSW11_COORD_X, GMSW11_COORD_Y, ' ', GMMB_BG_COLOR);
		cct_showch(GMSW11_COORD_X, GMSW11_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(GMSW1P_COORD_X, GMSW1P_COORD_Y, "关", GMMB_BG_COLOR, GMMB_FG_COLOR);
		switch_one[1].act(DEFAULT);
		break;
	case GMMB_RET_BLINK_ON:   /*开启色块闪烁*/
		__GAME.if_blink = true;
		cct_showch(GMSW12_COORD_X, GMSW12_COORD_Y, ' ', GMMB_BG_COLOR);
		cct_showch(GMSW12_COORD_X, GMSW12_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(GMSW1P_COORD_X, GMSW1P_COORD_Y, "开", GMMB_BG_COLOR, GMMB_FG_COLOR);
		switch_one[0].act(DEFAULT);
		break;
	case GMMB_RET_TIPS_OFF:   /*关闭提示*/
		__GAME.if_tips = false;
		cct_showch(GMSW21_COORD_X, GMSW21_COORD_Y, ' ', GMMB_BG_COLOR);
		cct_showch(GMSW21_COORD_X, GMSW21_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(GMSW2P_COORD_X, GMSW2P_COORD_Y, "关", GMMB_BG_COLOR, GMMB_FG_COLOR);
		switch_two[1].act(DEFAULT);
		break;
	case GMMB_RET_TIPS_ON:    /*开启提示*/
		__GAME.if_tips = true;
		cct_showch(GMSW22_COORD_X, GMSW22_COORD_Y, ' ', GMMB_BG_COLOR);
		cct_showch(GMSW22_COORD_X, GMSW22_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(GMSW2P_COORD_X, GMSW2P_COORD_Y, "开", GMMB_BG_COLOR, GMMB_FG_COLOR);
		switch_two[0].act(DEFAULT);
		break;
	}
}

/***************************************************************************
  函数名称：set_button_type
  功    能：给按键设置种类
  输入参数：无
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void cover_mailbox::set_button_type()
{
	button_yes.set_type(CVMB_YES);        /*“是”键设置种类*/
	button_no.set_type(CVMB_NO);          /*“否”键设置种类*/
	button_sure.set_type(CVMB_SURE);      /*“确定”键设置种类*/
	button_one.set_type(CVMB_ONE);        /*“1”键设置种类*/
	button_two.set_type(CVMB_TWO);        /*“2”键设置种类*/
	button_three.set_type(CVMB_THREE);    /*“3”键设置种类*/
	button_four.set_type(CVMB_FOUR);      /*“4”键设置种类*/
	button_cancel.set_type(CVMB_CANCEL);  /*“取消”键设置种类*/
	switch_one[0].set_type(CVMB_SW11);    /*开关1按键1设置种类*/
	switch_one[1].set_type(CVMB_SW12);    /*开关1按键2设置种类*/
	switch_two[0].set_type(CVMB_SW21);    /*开关2按键1设置种类*/
	switch_two[1].set_type(CVMB_SW22);    /*开关2按键2设置种类*/
}

/***************************************************************************
  函数名称：set_button_coord
  功    能：给按键坐标赋值
  输入参数：无
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void cover_mailbox::set_button_coord()
{
	button_yes.set_coord(CVYES_COORD_X, CVYES_COORD_Y);           /*“是”键坐标赋值*/
	button_no.set_coord(CVNO_COORD_X, CVNO_COORD_Y);              /*“否”键坐标赋值*/
	button_sure.set_coord(CVSURE_COORD_X, CVSURE_COORD_Y);        /*“确定”键坐标赋值*/
	button_one.set_coord(CVONE_COORD_X, CVONE_COORD_Y);           /*“1”键坐标赋值*/
	button_two.set_coord(CVTWO_COORD_X, CVTWO_COORD_Y);           /*“2”键坐标赋值*/
	button_three.set_coord(CVTHREE_COORD_X, CVTHREE_COORD_Y);     /*“3”键坐标赋值*/
	button_four.set_coord(CVFOUR_COORD_X, CVFOUR_COORD_Y);        /*“4”键坐标赋值*/
	button_cancel.set_coord(CVCANCEL_COORD_X, CVCANCEL_COORD_Y);  /*“取消”键坐标赋值*/
	switch_one[0].set_coord(CVSW11_COORD_X, CVSW11_COORD_Y);      /*开关1按键1坐标赋值*/
	switch_one[1].set_coord(CVSW12_COORD_X, CVSW12_COORD_Y);      /*开关1按键2坐标赋值*/
	switch_two[0].set_coord(CVSW21_COORD_X, CVSW21_COORD_Y);      /*开关2按键1坐标赋值*/
	switch_two[1].set_coord(CVSW22_COORD_X, CVSW22_COORD_Y);      /*开关2按键2坐标赋值*/
}

/***************************************************************************
  函数名称：print
  功    能：打印标题画面对话框
  输入参数：const int button_mode：按键形式（只读）
			const char* prompt1：提示语1（只读，默认为空指针）
			const char* prompt2：提示语2（只读，默认为空指针）
			const char* prompt3：提示语3（只读，默认为空指针）
  返 回 值：无
  说    明：无
***************************************************************************/
void cover_mailbox::print(const int button_mode, const char* prompt1, const char* prompt2, const char* prompt3)
{
	IF_CVMB = button_mode;       /*根据对话框按键种类调整标记变量，标志对话框已出现*/

/*1、打印对话框外形*/
	cct_showstr(CVMB_COORD_X, CVMB_COORD_Y, "┏━━━━━━━━━━━┓", CVMB_BG_COLOR, CVMB_FG_COLOR);
	cct_showstr(CVMB_COORD_X - 2, CVMB_COORD_Y + 1, "┏┛                      ┗┓", CVMB_BG_COLOR, CVMB_FG_COLOR);
	for (int i = 0; i < CVMB_WIDTH - 4; i++) {
		cct_showstr(CVMB_COORD_X - 2, CVMB_COORD_Y + 2 + i, "┃                          ┃", CVMB_BG_COLOR, CVMB_FG_COLOR);
	}
	cct_showstr(CVMB_COORD_X - 2, CVMB_COORD_Y + CVMB_WIDTH - 2, "┗┓                      ┏┛", CVMB_BG_COLOR, CVMB_FG_COLOR);
	cct_showstr(CVMB_COORD_X, CVMB_COORD_Y + CVMB_WIDTH - 1, "┗━━━━━━━━━━━┛", CVMB_BG_COLOR, CVMB_FG_COLOR);

	/*2、打印对话框内容*/
	cct_showstr(CVPROM_COORD_X, CVPROM_COORD_Y, prompt1, CVMB_BG_COLOR, CVMB_FG_COLOR);
	cct_showstr(CVPROM_COORD_X - 2, CVPROM_COORD_Y + 1, prompt2, CVMB_BG_COLOR, CVMB_FG_COLOR);
	cct_showstr(CVPROM_COORD_X - 2, CVPROM_COORD_Y + 2, prompt3, CVMB_BG_COLOR, CVMB_FG_COLOR);

	/*3、根据按键形式打印对话框按钮*/
	if (button_mode == BUTTON_TWO) {  /*双键式*/
		button_yes.act(DEFAULT);  /*打印“是”键*/
		button_no.act(DEFAULT);   /*打印“否”键*/
	}

	else if (button_mode == BUTTON_ONE)  /*单键式*/
		button_sure.act(DEFAULT);  /*打印“确定”键*/

	else if (button_mode == BUTTON_FIVE) {  /*五键式*/
		button_one.act(DEFAULT);     /*打印“1”键*/
		button_two.act(DEFAULT);     /*打印“2”键*/
		button_three.act(DEFAULT);   /*打印“3”键*/
		button_four.act(DEFAULT);    /*打印“4”键*/
		button_cancel.act(DEFAULT);  /*打印“取消”键*/
	}

	else if (button_mode == BUTTON_SWITCH) {  /*开关式*/
		cct_showstr(CVSW11_COORD_X, CVSW11_COORD_Y + 1, "       ", COLOR_HCYAN);  /*打印开关1的滑动条*/
		cct_showstr(CVSW21_COORD_X, CVSW21_COORD_Y + 1, "       ", COLOR_HCYAN);  /*打印开关2的滑动条*/
		button_sure.act(DEFAULT);  /*打印“确定”键*/

		if (__GAME.if_blink) {  /*打印开关1按键1以及当前状态*/
			cct_showstr(CVSW1P_COORD_X, CVSW1P_COORD_Y, "开", CVMB_BG_COLOR, CVMB_FG_COLOR);
			switch_one[0].act(DEFAULT);
		}
		else {  /*打印开关1按键2以及当前状态*/
			cct_showstr(CVSW1P_COORD_X, CVSW1P_COORD_Y, "关", CVMB_BG_COLOR, CVMB_FG_COLOR);
			switch_one[1].act(DEFAULT);
		}
		if (__GAME.if_tips) {  /*打印开关2按键1以及当前状态*/
			cct_showstr(CVSW2P_COORD_X, CVSW2P_COORD_Y, "开", CVMB_BG_COLOR, CVMB_FG_COLOR);
			switch_two[0].act(DEFAULT);
		}
		else {  /*打印开关2按键2以及当前状态*/
			cct_showstr(CVSW2P_COORD_X, CVSW2P_COORD_Y, "关", CVMB_BG_COLOR, CVMB_FG_COLOR);
			switch_two[1].act(DEFAULT);
		}
	}
}

/***************************************************************************
  函数名称：mouse_if_button
  功    能：判断鼠标位置是否在某一按键上
  输入参数：const int X：鼠标位置横坐标（只读）
			const int Y：鼠标位置纵坐标（只读）
  返 回 值：int：鼠标在哪一按键上
  说    明：无
***************************************************************************/
int cover_mailbox::mouse_if_button(const int X, const int Y)
{
	int ret = 0;  /*返回值*/
	bool p[CVMB_BUTTON_NUM];
	for (int i = 0; i < CVMB_BUTTON_NUM; i++)
		p[i] = false;

	if ((X == CVYES_COORD_X || X == CVYES_COORD_X + 1) && (Y == CVYES_COORD_Y || Y == CVYES_COORD_Y + 1))            /*判断是否在“是”键上*/
		p[0] = true;
	if ((X == CVNO_COORD_X || X == CVNO_COORD_X + 1) && (Y == CVNO_COORD_Y || Y == CVNO_COORD_Y + 1))                /*判断是否在“否”键上*/
		p[1] = true;
	if (X >= CVSURE_COORD_X && X <= CVSURE_COORD_X + 3 && (Y == CVSURE_COORD_Y || Y == CVSURE_COORD_Y + 1))          /*判断是否在“确定”键上*/
		p[2] = true;
	if ((X == CVONE_COORD_X || X == CVONE_COORD_X + 1) && (Y == CVONE_COORD_Y || Y == CVONE_COORD_Y + 1))            /*判断是否在“1”键上*/
		p[3] = true;
	if ((X == CVTWO_COORD_X || X == CVTWO_COORD_X + 1) && (Y == CVTWO_COORD_Y || Y == CVTWO_COORD_Y + 1))            /*判断是否在“2”键上*/
		p[4] = true;
	if ((X == CVTHREE_COORD_X || X == CVTHREE_COORD_X + 1) && (Y == CVTHREE_COORD_Y || Y == CVTHREE_COORD_Y + 1))    /*判断是否在“3”键上*/
		p[5] = true;
	if ((X == CVFOUR_COORD_X || X == CVFOUR_COORD_X + 1) && (Y == CVFOUR_COORD_Y || Y == CVFOUR_COORD_Y + 1))        /*判断是否在“4”键上*/
		p[6] = true;
	if (X >= CVCANCEL_COORD_X && X <= CVCANCEL_COORD_X + 3 && (Y == CVCANCEL_COORD_Y || Y == CVCANCEL_COORD_Y + 1))  /*判断是否在“取消”键上*/
		p[7] = true;
	if (X == CVSW11_COORD_X && (Y == CVSW11_COORD_Y || Y == CVSW11_COORD_Y + 1))  /*判断是否在开关1按键1上*/
		p[8] = true;
	if (X == CVSW12_COORD_X && (Y == CVSW12_COORD_Y || Y == CVSW12_COORD_Y + 1))  /*判断是否在开关1按键2上*/
		p[9] = true;
	if (X == CVSW21_COORD_X && (Y == CVSW21_COORD_Y || Y == CVSW21_COORD_Y + 1))  /*判断是否在开关2按键1上*/
		p[10] = true;
	if (X == CVSW22_COORD_X && (Y == CVSW22_COORD_Y || Y == CVSW22_COORD_Y + 1))  /*判断是否在开关2按键2上*/
		p[11] = true;

	/*检查各个位置的情况，遇到真并且与按键形式对应，则取对应返回值后结束检查*/
	switch (IF_CVMB) {
	case BUTTON_TWO:
		for (int i = 0; i < 2; i++) {  /*双键式按键的检查*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_ONE:
		for (int i = 2; i < 3; i++) {  /*单键式按键的检查*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_FIVE:
		for (int i = 3; i < 8; i++) {  /*五键式按键的检查*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_SWITCH:                /*开关式按键的检查*/
		if (p[2])
			ret = 3;
		if (__GAME.if_blink && p[8])
			ret = 9;
		else if (!__GAME.if_blink && p[9])
			ret = 10;
		if (__GAME.if_tips && p[10])
			ret = 11;
		else if (!__GAME.if_tips && p[11])
			ret = 12;
		break;
	}

	return ret;
}

/***************************************************************************
  函数名称：keyboard_if_button
  功    能：判断键盘按下的按键是否为对话框内的某一按键
  输入参数：const int keycode：键码（只读）
  返 回 值：int：键盘按下了哪一按键
  说    明：无
***************************************************************************/
int cover_mailbox::keyboard_if_button(const int keycode)
{
	int ret = 0;

	if (keycode == 'Y' || keycode == 'y')         /*判断是否按下了“是”键*/
		ret = 1;
	else if (keycode == 'N' || keycode == 'n')    /*判断是否按下了“否”键*/
		ret = 2;
	else if (keycode == '\n' || keycode == '\r')  /*判断是否按下了“确定”键*/
		ret = 3;
	else if (keycode >= '1' && keycode <= '4')    /*判断是否按下了某个数字键*/
		ret = keycode - '0' + 3;
	else if (keycode == 'C' || keycode == 'c')    /*判断是否按下了“取消”键*/
		ret = 8;

	return ret;
}

/***************************************************************************
  函数名称：selective_default
  功    能：选择性地为某一按键取消高亮
  输入参数：const int selection：按键选择（只读）
  返 回 值：无
  说    明：1、当选择为DEFAULT_ALL时，通过递归调用取消所有按键的高亮
			2、只有当按键选择与按键模式对应时才进行操作
***************************************************************************/
void cover_mailbox::selective_default(const int selection)
{
	switch (selection) {
	case 1:
		if (IF_CVMB == BUTTON_TWO)     /*“是”键取消高亮*/
			button_yes.act(DEFAULT);
		break;
	case 2:
		if (IF_CVMB == BUTTON_TWO)     /*“否”键取消高亮*/
			button_no.act(DEFAULT);
		break;
	case 3:
		if (IF_CVMB == BUTTON_ONE || IF_CVMB == BUTTON_SWITCH)     /*“确定”键取消高亮*/
			button_sure.act(DEFAULT);
		break;
	case 4:
		if (IF_CVMB == BUTTON_FIVE)    /*“1”键取消高亮*/
			button_one.act(DEFAULT);
		break;
	case 5:
		if (IF_CVMB == BUTTON_FIVE)    /*“2”键取消高亮*/
			button_two.act(DEFAULT);
		break;
	case 6:
		if (IF_CVMB == BUTTON_FIVE)    /*“3”键取消高亮*/
			button_three.act(DEFAULT);
		break;
	case 7:
		if (IF_CVMB == BUTTON_FIVE)    /*“4”键取消高亮*/
			button_four.act(DEFAULT);
		break;
	case 8:
		if (IF_CVMB == BUTTON_FIVE)    /*“取消”键取消高亮*/
			button_cancel.act(DEFAULT);
		break;
	case 9:
		if (IF_CVMB == BUTTON_SWITCH && __GAME.if_blink)   /*开关1按键1取消高亮*/
			switch_one[0].act(DEFAULT);
		break;
	case 10:
		if (IF_CVMB == BUTTON_SWITCH && !__GAME.if_blink)  /*开关1按键2取消高亮*/
			switch_one[1].act(DEFAULT);
		break;
	case 11:
		if (IF_CVMB == BUTTON_SWITCH && __GAME.if_tips)    /*开关2按键1取消高亮*/
			switch_two[0].act(DEFAULT);
		break;
	case 12:
		if (IF_CVMB == BUTTON_SWITCH && !__GAME.if_tips)   /*开关2按键2取消高亮*/
			switch_two[1].act(DEFAULT);
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < CVMB_BUTTON_NUM; i++)   /*所有按键取消高亮*/
			selective_default(i + 1);
		break;
	}
}

/***************************************************************************
  函数名称：selective_activate
  功    能：选择性地为某一按键设置高亮
  输入参数：const int selection：按键选择（只读）
  返 回 值：无
  说    明：只有当按键选择与按键模式对应时才进行操作
***************************************************************************/
void cover_mailbox::selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		if (IF_CVMB == BUTTON_TWO)   /*“是”键设置高亮*/
			button_yes.act(ACTIVATE);
		break;
	case 2:
		if (IF_CVMB == BUTTON_TWO)   /*“否”键设置高亮*/
			button_no.act(ACTIVATE);
		break;
	case 3:
		if (IF_CVMB == BUTTON_ONE || IF_CVMB == BUTTON_SWITCH)   /*“确定”键设置高亮*/
			button_sure.act(ACTIVATE);
		break;
	case 4:
		if (IF_CVMB == BUTTON_FIVE)  /*“1”键设置高亮*/
			button_one.act(ACTIVATE);
		break;
	case 5:
		if (IF_CVMB == BUTTON_FIVE)  /*“2”键设置高亮*/
			button_two.act(ACTIVATE);
		break;
	case 6:
		if (IF_CVMB == BUTTON_FIVE)  /*“3”键设置高亮*/
			button_three.act(ACTIVATE);
		break;
	case 7:
		if (IF_CVMB == BUTTON_FIVE)  /*“4”键设置高亮*/
			button_four.act(ACTIVATE);
		break;
	case 8:
		if (IF_CVMB == BUTTON_FIVE)  /*“取消”键设置高亮*/
			button_cancel.act(ACTIVATE);
		break;
	case 9:
		if (IF_CVMB == BUTTON_SWITCH && __GAME.if_blink)   /*开关1按键1设置高亮*/
			switch_one[0].act(ACTIVATE);
		break;
	case 10:
		if (IF_CVMB == BUTTON_SWITCH && !__GAME.if_blink)  /*开关1按键2设置高亮*/
			switch_one[1].act(ACTIVATE);
		break;
	case 11:
		if (IF_CVMB == BUTTON_SWITCH && __GAME.if_tips)    /*开关2按键1设置高亮*/
			switch_two[0].act(ACTIVATE);
		break;
	case 12:
		if (IF_CVMB == BUTTON_SWITCH && !__GAME.if_tips)   /*开关2按键2设置高亮*/
			switch_two[1].act(ACTIVATE);
		break;
	}
}

/***************************************************************************
  函数名称：control
  功    能：用键鼠在标题画面对话框内进行操作
  输入参数：无
  返 回 值：int：进行的操作
  说    明：无
***************************************************************************/
int cover_mailbox::control()
{
	int X = 0, Y = 0;  /*横纵坐标，初始均为零*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*函数的返回值*/

	cct_enable_mouse();  /*启用鼠标*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*读鼠标/键盘*/
		selective_default(DEFAULT_ALL);  /*取消对话框所有按键的高亮*/

		int RET1 = mouse_if_button(X, Y);         /*判断此时鼠标的位置是否在某个按键中*/
		int RET2 = keyboard_if_button(keycode1);  /*判断此时键盘按下的按钮是否为某个按键*/
		selective_activate(RET1);  /*若鼠标在某个按键中，将对应的按键设置高亮*/

		/*1、若返回的是鼠标事件并且按下左键*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {

			switch (IF_CVMB) {  /*根据对应的对话框状态进行操作，避免按键之间互相干扰*/
			case BUTTON_TWO:
				if (RET1 >= 1 && RET1 <= 2) {
					selective_default(RET1);       /*取消高亮、延时再设置高亮，营造按键效果*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_CVMB = 0;         /*对话框状态置零*/
				}

				result = RET1 + CVMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			case BUTTON_ONE:
				if (RET1 == 3) {
					selective_default(RET1);       /*取消高亮、延时再设置高亮，营造按键效果*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_CVMB = 0;         /*对话框状态置零*/
				}

				result = RET1 + CVMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			case BUTTON_FIVE:
				if (RET1 >= 4 && RET1 <= 8) {
					selective_default(RET1);       /*取消高亮、延时再设置高亮，营造按键效果*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_CVMB = 0;         /*对话框状态置零*/
				}

				result = RET1 + CVMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			case BUTTON_SWITCH:
				if (RET1 == 3 || (RET1 >= 9 && RET1 <= 12)) {
					selective_default(RET1);       /*取消高亮、延时再设置高亮，营造按键效果*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0;
				}

				if (RET1 == 3)                     /*若按“确定”键，对话框状态置零*/
					IF_CVMB = 0;
				result = RET1 + CVMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			}
		}

		/*2、若返回的是键盘事件*/
		else if (ret == CCT_KEYBOARD_EVENT) {
			switch (IF_CVMB) {
			case BUTTON_TWO:
				if (RET2 >= 1 && RET2 <= 2) {
					selective_activate(RET2);       /*取消高亮、延时再设置高亮，营造按键效果*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_CVMB = 0;         /*对话框状态置零*/
				}

				result = RET2 + CVMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			case BUTTON_ONE:
				if (RET2 == 3) {
					selective_activate(RET2);       /*取消高亮、延时再设置高亮，营造按键效果*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_CVMB = 0;         /*对话框状态置零*/
				}

				result = RET2 + CVMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			case BUTTON_FIVE:
				if (RET2 >= 4 && RET2 <= 8) {
					selective_activate(RET2);       /*取消高亮、延时再设置高亮，营造按键效果*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_CVMB = 0;         /*对话框状态置零*/
				}

				result = RET2 + CVMB_RET_YES - 1;  /*根据操作取返回值*/
				break;
			}
		}
	}

	cct_disable_mouse();	//禁用鼠标
	return result;
}

/***************************************************************************
  函数名称：erase
  功    能：重画标题画面，达到擦除对话框的效果
  输入参数：无
  返 回 值：无
  说    明：本函数重画了对话框对应的那几行以及所有数字和部分被盖住的按键
***************************************************************************/
void cover_mailbox::erase()
{
	int i;

	/*1、补上背景*/
	for (i = 0; i < CVMB_WIDTH; i++)
		cct_showstr(0, CVMB_COORD_Y + i, "┃                                        ┃", COLOR_WHITE, COLOR_BLACK);

	/*2、重画数字“2”*/
	cct_showstr(TWO_COORD_X, TWO_COORD_Y, "     ", COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X + 4, TWO_COORD_Y + 1, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X + 4, TWO_COORD_Y + 2, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showstr(TWO_COORD_X, TWO_COORD_Y + 3, "     ", COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X, TWO_COORD_Y + 4, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X, TWO_COORD_Y + 5, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showstr(TWO_COORD_X, TWO_COORD_Y + 6, "     ", COLOR_HRED, COLOR_BLACK);

	/*3、重画数字“0”*/
	cct_showstr(ZERO_COORD_X, ZERO_COORD_Y, "     ", COLOR_HYELLOW, COLOR_BLACK);
	for (i = 0; i < 5; i++) {
		cct_showch(ZERO_COORD_X, ZERO_COORD_Y + 1 + i, ' ', COLOR_HYELLOW, COLOR_BLACK);
		cct_showch(ZERO_COORD_X + 4, ZERO_COORD_Y + 1 + i, ' ', COLOR_HYELLOW, COLOR_BLACK);
	}
	cct_showstr(ZERO_COORD_X, ZERO_COORD_Y + 6, "     ", COLOR_HYELLOW, COLOR_BLACK);

	/*4、重画数字“4”*/
	for (i = 0; i < 3; i++) {
		cct_showch(FOUR_COORD_X, FOUR_COORD_Y + i, ' ', COLOR_HBLUE, COLOR_BLACK);
		cct_showch(FOUR_COORD_X + 4, FOUR_COORD_Y + i, ' ', COLOR_HBLUE, COLOR_BLACK);
	}
	cct_showstr(FOUR_COORD_X, FOUR_COORD_Y + 3, "     ", COLOR_HBLUE, COLOR_BLACK);
	for (i = 0; i < 3; i++) {
		cct_showch(FOUR_COORD_X + 4, FOUR_COORD_Y + 4 + i, ' ', COLOR_HBLUE, COLOR_BLACK);
	}

	/*5、重画数字“8”*/
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

	/*6、重画按键*/
	cct_gotoxy(NEW_COORD_X, NEW_COORD_Y);
	print_cover_button(" 新游戏 ", COLOR_BLUE, COLOR_HWHITE);
	cct_gotoxy(LOAD_COORD_X, LOAD_COORD_Y);
	print_cover_button("载入游戏", COLOR_PINK, COLOR_HWHITE);
}

/***************************************************************************
  函数名称：options
  功    能：完成标题画面对话框中的各种设置
  输入参数：const int options：设置（只读）
  返 回 值：无
  说    明：本函数根据对应设置，先改变布尔值、消除原按键、输出当前状态，然后再重画原按键
***************************************************************************/
void cover_mailbox::options(const int options)
{
	switch (options) {
	case CVMB_RET_BLINK_OFF:  /*关闭色块闪烁*/
		__GAME.if_blink = false;
		cct_showch(CVSW11_COORD_X, CVSW11_COORD_Y, ' ', CVMB_BG_COLOR);
		cct_showch(CVSW11_COORD_X, CVSW11_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(CVSW1P_COORD_X, CVSW1P_COORD_Y, "关", CVMB_BG_COLOR, CVMB_FG_COLOR);
		switch_one[1].act(DEFAULT);
		break;
	case CVMB_RET_BLINK_ON:   /*开启色块闪烁*/
		__GAME.if_blink = true;
		cct_showch(CVSW12_COORD_X, CVSW12_COORD_Y, ' ', CVMB_BG_COLOR);
		cct_showch(CVSW12_COORD_X, CVSW12_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(CVSW1P_COORD_X, CVSW1P_COORD_Y, "开", CVMB_BG_COLOR, CVMB_FG_COLOR);
		switch_one[0].act(DEFAULT);
		break;
	case CVMB_RET_TIPS_OFF:   /*关闭提示*/
		__GAME.if_tips = false;
		cct_showch(CVSW21_COORD_X, CVSW21_COORD_Y, ' ', CVMB_BG_COLOR);
		cct_showch(CVSW21_COORD_X, CVSW21_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(CVSW2P_COORD_X, CVSW2P_COORD_Y, "关", CVMB_BG_COLOR, CVMB_FG_COLOR);
		switch_two[1].act(DEFAULT);
		break;
	case CVMB_RET_TIPS_ON:    /*开启提示*/
		__GAME.if_tips = true;
		cct_showch(CVSW22_COORD_X, CVSW22_COORD_Y, ' ', CVMB_BG_COLOR);
		cct_showch(CVSW22_COORD_X, CVSW22_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(CVSW2P_COORD_X, CVSW2P_COORD_Y, "开", CVMB_BG_COLOR, CVMB_FG_COLOR);
		switch_two[0].act(DEFAULT);
		break;
	}
}