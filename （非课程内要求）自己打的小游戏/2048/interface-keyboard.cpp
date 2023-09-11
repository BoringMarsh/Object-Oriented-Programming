#include"90-b3.h"

/***************************************************************************
  函数名称：set_button_type
  功    能：给按键设置种类
  输入参数：无
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void keyboard::set_button_type()
{
	button_up.set_type(KB_UP);        /*上箭头键设置种类*/
	button_down.set_type(KB_DOWN);    /*下箭头键设置种类*/
	button_left.set_type(KB_LEFT);    /*左箭头键设置种类*/
	button_right.set_type(KB_RIGHT);  /*右箭头键设置种类*/
	button_q.set_type(KB_Q);          /*功能键Q设置种类*/
	button_r.set_type(KB_R);          /*功能键R设置种类*/
	button_s.set_type(KB_S);          /*功能键S设置种类*/
	button_d.set_type(KB_D);          /*功能键H设置种类*/
	button_o.set_type(KB_O);          /*功能键O设置种类*/
}

/***************************************************************************
  函数名称：set_button_coord
  功    能：给按键坐标赋值
  输入参数：无
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void keyboard::set_button_coord()
{
	button_up.set_coord(UP_COORD_X, UP_COORD_Y);           /*上箭头键坐标赋值*/
	button_down.set_coord(DOWN_COORD_X, DOWN_COORD_Y);     /*下箭头键坐标赋值*/
	button_left.set_coord(LEFT_COORD_X, LEFT_COORD_Y);     /*左箭头键坐标赋值*/
	button_right.set_coord(RIGHT_COORD_X, RIGHT_COORD_Y);  /*右箭头键坐标赋值*/
	button_q.set_coord(Q_COORD_X, Q_COORD_Y);  /*功能键Q坐标赋值*/
	button_r.set_coord(R_COORD_X, R_COORD_Y);  /*功能键R坐标赋值*/
	button_s.set_coord(S_COORD_X, S_COORD_Y);  /*功能键S坐标赋值*/
	button_d.set_coord(D_COORD_X, D_COORD_Y);  /*功能键H坐标赋值*/
	button_o.set_coord(O_COORD_X, O_COORD_Y);  /*功能键O坐标赋值*/
}

/***************************************************************************
  函数名称：print
  功    能：打印小键盘
  输入参数：无
  返 回 值：无
  说    明：本函数同时打印了连接线，改善观感
***************************************************************************/
void keyboard::print()
{
	/*1、打印连接线*/
	cct_showstr(4 * __GAME.order + 4, 4 * __GAME.order + 3, "  ", COLOR_WHITE, COLOR_BLACK);
	cct_showstr(4 * __GAME.order + 2, 4 * __GAME.order + 4, "  ", COLOR_WHITE, COLOR_BLACK);
	cct_showstr(4 * __GAME.order + 4, 4 * __GAME.order + 5, "  ", COLOR_WHITE, COLOR_BLACK);

	/*2、打印控制面板*/
	cct_showstr(KB_COORD_X, KB_COORD_Y, "┏━━━━━━━━━━┓", COLOR_WHITE, COLOR_BLACK);
	cct_showstr(KB_COORD_X - 2, KB_COORD_Y + 1, "┏┛                    ┗┓", COLOR_WHITE, COLOR_BLACK);
	for (int i = 0; i < 5; i++) {
		cct_showstr(KB_COORD_X - 2, KB_COORD_Y + 2 + i, "┃                        ┃", COLOR_WHITE, COLOR_BLACK);
	}
	cct_showstr(KB_COORD_X - 2, KB_COORD_Y + 7, "┗┓                    ┏┛", COLOR_WHITE, COLOR_BLACK);
	cct_showstr(KB_COORD_X, KB_COORD_Y + 8, "┗━━━━━━━━━━┛", COLOR_WHITE, COLOR_BLACK);

	/*3、打印方向键*/
	button_up.act(DEFAULT);     /*打印上箭头*/
	button_down.act(DEFAULT);   /*打印下箭头*/
	button_left.act(DEFAULT);   /*打印左箭头*/
	button_right.act(DEFAULT);  /*打印右箭头*/

	/*4、打印版本号铭牌*/
	cct_showstr(KBVER_COORD_X, KBVER_COORD_Y, __GAME.version, COLOR_BLACK, COLOR_WHITE);

	/*5、打印功能键*/
	button_q.act(DEFAULT);  /*打印功能键Q*/
	button_r.act(DEFAULT);  /*打印功能键R*/
	button_s.act(DEFAULT);  /*打印功能键S*/
	button_d.act(DEFAULT);  /*打印功能键D*/
	button_o.act(DEFAULT);  /*打印功能键O*/
}

/***************************************************************************
  函数名称：mouse_if_button
  功    能：判断鼠标位置是否在某一按键上
  输入参数：const int X：鼠标位置横坐标（只读）
		    const int Y：鼠标位置纵坐标（只读）
  返 回 值：int：鼠标在哪一按键上
  说    明：无
***************************************************************************/
int keyboard::mouse_if_button(const int X, const int Y)
{
	int ret = 0;  /*返回值*/
	bool p[KB_BUTTON_NUM];
	for (int i = 0; i < KB_BUTTON_NUM; i++)
		p[i] = false;

	if (X >= UP_COORD_X && X <= UP_COORD_X + 5 && Y >= UP_COORD_Y && Y <= UP_COORD_Y + 2)              /*判断是否在上箭头键上*/
		p[0] = true;
	if (X >= DOWN_COORD_X && X <= DOWN_COORD_X + 5 && Y >= DOWN_COORD_Y && Y <= DOWN_COORD_Y + 2)      /*判断是否在下箭头键上*/
		p[1] = true;
	if (X >= LEFT_COORD_X && X <= LEFT_COORD_X + 5 && Y >= LEFT_COORD_Y && Y <= LEFT_COORD_Y + 2)      /*判断是否在左箭头键上*/
		p[2] = true;
	if (X >= RIGHT_COORD_X && X <= RIGHT_COORD_X + 5 && Y >= RIGHT_COORD_Y && Y <= RIGHT_COORD_Y + 2)  /*判断是否在右箭头键上*/
		p[3] = true;
	if (X == Q_COORD_X && Y == Q_COORD_Y)   /*判断是否在功能键Q上*/
		p[4] = true;
	if (X == R_COORD_X && Y == R_COORD_Y)   /*判断是否在功能键R上*/
		p[5] = true;
	if (X == S_COORD_X && Y == S_COORD_Y)   /*判断是否在功能键S上*/
		p[6] = true;
	if (X == D_COORD_X && Y == D_COORD_Y)   /*判断是否在功能键D上*/
		p[7] = true;
	if (X == O_COORD_X && Y == O_COORD_Y)   /*判断是否在功能键O上*/
		p[8] = true;

	for (int i = 0; i < KB_BUTTON_NUM; i++) {  /*检查各个位置的情况，遇到真则取对应返回值后结束检查*/
		if (p[i]) {
			ret = i + 1;
			break;
		}
	}

	return ret;
}

/***************************************************************************
  函数名称：keyboard_if_button
  功    能：判断键盘按下的按键是否为小键盘上的某一按键
  输入参数：const int keycode1：键码1（只读）
		    const int keycode2：键码2（只读）
  返 回 值：int：键盘按下了哪一按键
  说    明：无
***************************************************************************/
int keyboard::keyboard_if_button(const int keycode1, const int keycode2)
{
	int ret = 0;

	if (keycode1 == 224) {
		switch (keycode2) {
		case KB_ARROW_UP:     /*判断是否按下了上箭头键*/
			ret = 1;
			break;
		case KB_ARROW_DOWN:   /*判断是否按下了下箭头键*/
			ret = 2;
			break;
		case KB_ARROW_LEFT:   /*判断是否按下了左箭头键*/
			ret = 3;
			break;
		case KB_ARROW_RIGHT:  /*判断是否按下了右箭头键*/
			ret = 4;
			break;
		}
	}
	else if (keycode1 == 'Q' || keycode1 == 'q')  /*判断是否按下了功能键Q*/
		ret = 5;
	else if (keycode1 == 'R' || keycode1 == 'r')  /*判断是否按下了功能键R*/
		ret = 6;
	else if (keycode1 == 'S' || keycode1 == 's')  /*判断是否按下了功能键S*/
		ret = 7;
	else if (keycode1 == 'D' || keycode1 == 'd')  /*判断是否按下了功能键D*/
		ret = 8;
	else if (keycode1 == 'O' || keycode1 == 'o')  /*判断是否按下了功能键O*/
		ret = 9;

	return ret;
}

/***************************************************************************
  函数名称：selective_default
  功    能：选择性地为某一按键取消高亮
  输入参数：const int selection：按键选择（只读）
  返 回 值：无
  说    明：当选择为DEFAULT_ALL时，通过递归调用取消所有按键的高亮
***************************************************************************/
void keyboard::selective_default(const int selection)
{
	switch (selection) {
	case 1:
		button_up.act(DEFAULT);      /*上箭头键取消高亮*/
		break;
	case 2:
		button_down.act(DEFAULT);    /*下箭头键取消高亮*/
		break;
	case 3:
		button_left.act(DEFAULT);    /*左箭头键取消高亮*/
		break;
	case 4:
		button_right.act(DEFAULT);   /*右箭头键取消高亮*/
		break;
	case 5:
		button_q.act(DEFAULT);       /*功能键Q取消高亮*/
		break;
	case 6:
		button_r.act(DEFAULT);       /*功能键R取消高亮*/
		break;
	case 7:
		button_s.act(DEFAULT);       /*功能键S取消高亮*/
		break;
	case 8:
		button_d.act(DEFAULT);       /*功能键D取消高亮*/
		break;
	case 9:
		button_o.act(DEFAULT);       /*功能键O取消高亮*/
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < KB_BUTTON_NUM; i++)  /*所有按键取消高亮*/
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
void keyboard::selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		button_up.act(ACTIVATE);     /*上箭头键设置高亮*/
		break;
	case 2:
		button_down.act(ACTIVATE);   /*下箭头键设置高亮*/
		break;
	case 3:
		button_left.act(ACTIVATE);   /*左箭头键设置高亮*/
		break;
	case 4:
		button_right.act(ACTIVATE);  /*右箭头键设置高亮*/
		break;
	case 5:
		button_q.act(ACTIVATE);      /*功能键Q设置高亮*/
		break;
	case 6:
		button_r.act(ACTIVATE);      /*功能键R设置高亮*/
		break;
	case 7:
		button_s.act(ACTIVATE);      /*功能键S设置高亮*/
		break;
	case 8:
		button_d.act(ACTIVATE);      /*功能键D设置高亮*/
		break;
	case 9:
		button_o.act(ACTIVATE);      /*功能键O设置高亮*/
		break;
	}
}

/***************************************************************************
  函数名称：control
  功    能：用键鼠在小键盘上进行操作
  输入参数：无
  返 回 值：int：进行的操作
  说    明：无
***************************************************************************/
int keyboard::control()
{
	int X = 0, Y = 0;  /*横纵坐标，初始均为零*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0, RESULT = 0;  /*函数的返回值、对话框操作函数的返回值*/

	cct_enable_mouse();  /*启用鼠标*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*读鼠标/键盘*/
		selective_default(DEFAULT_ALL);  /*取消小键盘所有按键的高亮*/

		int RET1 = mouse_if_button(X, Y);                   /*判断此时鼠标的位置是否在某个按键中*/
		int RET2 = keyboard_if_button(keycode1, keycode2);  /*判断此时键盘按下的按钮是否为某个按键*/
		selective_activate(RET1);  /*若鼠标在某个按键中，将对应的按键设置高亮*/

		/*1、若返回的是鼠标事件并且按下左键，同时鼠标在某一按键上*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK && RET1 != 0) {
			selective_default(RET1);

			switch (RET1) {
			case 1:
				act_up();     /*向上合成操作*/
				break;
			case 2:
				act_down();   /*向下合成操作*/
				break;
			case 3:
				act_left();   /*向左合成操作*/
				break;
			case 4:
				act_right();  /*向右合成操作*/
				break;
			case 5:
				__GAME.game_mailbox.print(BUTTON_TWO, "您确定要退出游戏？", "  所有未保存的进度会消失");  /*功能键Q，弹出对话框询问是否退出*/
				RESULT = __GAME.game_mailbox.control();  /*用返回值读取对话框操作*/
				if (RESULT == GMMB_RET_YES)       /*若按“是”，则函数返回QUIT，表示退出状态*/
					result = QUIT;
				else if (RESULT == GMMB_RET_NO)   /*若按“否”，则函数返回CONTINUE，表示继续状态*/
					result = CONTINUE;
				break;
			case 6:
				__GAME.game_mailbox.print(BUTTON_TWO, "您确定要重新开始？", "  所有未保存的进度会消失");  /*功能键R，弹出对话框询问是否重新开始*/
				RESULT = __GAME.game_mailbox.control();  /*用返回值读取对话框操作*/
				if (RESULT == GMMB_RET_YES)       /*若按“是”，则函数返回RESET，表示重开状态*/
					result = RESET;
				else if (RESULT == GMMB_RET_NO)   /*若按“否”，则函数返回CONTINUE，表示继续状态*/
					result = CONTINUE;
				break;
			case 7:
				__GAME.game_mailbox.print(BUTTON_FIVE, "保存到哪个位置？");    /*功能键S，弹出对话框询问是否存档*/
				RESULT = __GAME.game_mailbox.control();                        /*用返回值读取对话框操作*/
				if (RESULT >= GMMB_RET_ONE && RESULT <= GMMB_RET_FOUR)  /*若按某一数字键，则函数返回对应值，表示游戏保存到对应位置*/
					result = SAVE_1 + RESULT - GMMB_RET_ONE;
				else if (RESULT == GMMB_RET_CANCEL)                     /*若按“取消”，则函数返回CONTINUE，表示继续状态*/
					result = CONTINUE;
				break;
			case 8:
				__GAME.game_mailbox.print(BUTTON_FIVE, "删除哪个位置的存档？");  /*功能键D，弹出对话框询问是否删除存档*/
				RESULT = __GAME.game_mailbox.control();                          /*用返回值读取对话框操作*/
				if (RESULT >= GMMB_RET_ONE && RESULT <= GMMB_RET_FOUR)    /*若按某一数字键，则函数返回对应值，表示删除对应位置上的存档*/
					result = DELETE_1 + RESULT - GMMB_RET_ONE;
				else if (RESULT == GMMB_RET_CANCEL)                       /*若按“取消”，则函数返回CONTINUE，表示继续状态*/
					result = CONTINUE;
				break;
			case 9:
				__GAME.game_mailbox.print(BUTTON_SWITCH, "色块闪烁：  提示：");  /*功能键O，弹出对话框进行设置*/
				while (1) {
					RESULT = __GAME.game_mailbox.control();
					if (RESULT == GMMB_RET_SURE)  /*按“确定”键则退出*/
						break;
					else                          /*按其他键则进行相应设置*/
						__GAME.game_mailbox.options(RESULT);
				}
				result = CONTINUE;  /*函数返回CONTINUE，表示继续状态*/
				break;
			}

			Sleep(100);
			selective_activate(RET1);  /*延时后对应按键设置高亮，营造按键效果*/
			loop = 0;
		}

		/*2、若返回的是键盘事件，并且按下某一按键*/
		else if (ret == CCT_KEYBOARD_EVENT && RET2 != 0) {
			selective_activate(RET2);

			switch (RET2) {
			case 1:
				act_up();     /*向上合成操作*/
				break;
			case 2:
				act_down();   /*向下合成操作*/
				break;
			case 3:
				act_left();   /*向左合成操作*/
				break;
			case 4:
				act_right();  /*向右合成操作*/
				break;
			case 5:
				__GAME.game_mailbox.print(BUTTON_TWO, "您确定要退出游戏？", "  所有未保存的进度会消失");  /*功能键Q，弹出对话框询问是否退出*/
				RESULT = __GAME.game_mailbox.control();  /*用返回值读取对话框操作*/
				if (RESULT == GMMB_RET_YES)       /*若按“是”，则函数返回QUIT，表示退出状态*/
					result = QUIT;
				else if (RESULT == GMMB_RET_NO)   /*若按“否”，则函数返回CONTINUE，表示继续状态*/
					result = CONTINUE;
				break;
			case 6:
				__GAME.game_mailbox.print(BUTTON_TWO, "您确定要重新开始？", "  所有未保存的进度会消失");  /*功能键R，弹出对话框询问是否重新开始*/
				RESULT = __GAME.game_mailbox.control();  /*用返回值读取对话框操作*/
				if (RESULT == GMMB_RET_YES)       /*若按“是”，则函数返回RESET，表示重开状态*/
					result = RESET;
				else if (RESULT == GMMB_RET_NO)   /*若按“否”，则函数返回CONTINUE，表示继续状态*/
					result = CONTINUE;
				break;
			case 7:
				__GAME.game_mailbox.print(BUTTON_FIVE, "保存到哪个位置？");    /*功能键S，弹出对话框询问是否存档*/
				RESULT = __GAME.game_mailbox.control();                        /*用返回值读取对话框操作*/
				if (RESULT >= GMMB_RET_ONE && RESULT <= GMMB_RET_FOUR)  /*若按某一数字键，则函数返回对应值，表示游戏保存到对应位置*/
					result = SAVE_1 + RESULT - GMMB_RET_ONE;
				else if (RESULT == GMMB_RET_CANCEL)                     /*若按“取消”，则函数返回CONTINUE，表示继续状态*/
					result = CONTINUE;
				break;
			case 8:
				__GAME.game_mailbox.print(BUTTON_FIVE, "删除哪个位置的存档？");  /*功能键D，弹出对话框询问是否删除存档*/
				RESULT = __GAME.game_mailbox.control();                          /*用返回值读取对话框操作*/
				if (RESULT >= GMMB_RET_ONE && RESULT <= GMMB_RET_FOUR)    /*若按某一数字键，则函数返回对应值，表示删除对应位置上的存档*/
					result = DELETE_1 + RESULT - GMMB_RET_ONE;
				else if (RESULT == GMMB_RET_CANCEL)                       /*若按“取消”，则函数返回CONTINUE，表示继续状态*/
					result = CONTINUE;
				break;
			case 9:
				__GAME.game_mailbox.print(BUTTON_SWITCH, "色块闪烁：  提示：");  /*功能键O，弹出对话框进行设置*/
				while (1) {
					RESULT = __GAME.game_mailbox.control();
					if (RESULT == GMMB_RET_SURE)  /*按“确定”键则退出*/
						break;
					else                          /*按其他键则进行相应设置*/
						__GAME.game_mailbox.options(RESULT);
				}
				result = CONTINUE;  /*函数返回CONTINUE，表示继续状态*/
				break;
			}

			Sleep(100);
			selective_default(RET2);  /*延时后对应按键设置高亮，营造按键效果*/
			loop = 0;
		}
	}

	cct_disable_mouse();	//禁用鼠标
	return result;
}