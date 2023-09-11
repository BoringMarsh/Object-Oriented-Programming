#include<windows.h>
#include"90-b4.h"
#include"interface-mailbox.h"

/***************************************************************************
  函数名称：set_button_coord
  功    能：给按键坐标赋值
  输入参数：无
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void game_mailbox::set_button_coord(const int line, const int row)
{
	button_yes.set_coord(GMYES_COORD_X, GMYES_COORD_Y);           /*“是”键坐标赋值*/
	button_no.set_coord(GMNO_COORD_X, GMNO_COORD_Y);              /*“否”键坐标赋值*/
	button_sure.set_coord(GMSURE_COORD_X, GMSURE_COORD_Y);        /*“确定”键坐标赋值*/
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
void game_mailbox::print(const int button_mode, const int line, const int row, const char* prompt1, const char* prompt2, const char* prompt3)
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

	/*3、根据按键形式打印对话框按钮*/
	if (button_mode == BUTTON_TWO) {  /*双键式*/
		button_yes.act(DEFAULT);  /*打印“是”键*/
		button_no.act(DEFAULT);   /*打印“否”键*/
	}

	else if (button_mode == BUTTON_ONE)  /*单键式*/
		button_sure.act(DEFAULT);  /*打印“确定”键*/
}

/***************************************************************************
  函数名称：mouse_if_button
  功    能：判断鼠标位置是否在某一按键上
  输入参数：const int X：鼠标位置横坐标（只读）
			const int Y：鼠标位置纵坐标（只读）
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
  返 回 值：int：鼠标在哪一按键上
  说    明：无
***************************************************************************/
int game_mailbox::mouse_if_button(const int X, const int Y, const int line, const int row)
{
	int ret = 0;  /*返回值*/
	bool p[GMMB_BUTTON_NUM];
	for (int i = 0; i < GMMB_BUTTON_NUM; i++)
		p[i] = false;

	if ((X == GMYES_COORD_X || X == GMYES_COORD_X + 1) && (Y == GMYES_COORD_Y || Y == GMYES_COORD_Y + 1))    /*判断是否在“是”键上*/
		p[0] = true;
	if ((X == GMNO_COORD_X || X == GMNO_COORD_X + 1) && (Y == GMNO_COORD_Y || Y == GMNO_COORD_Y + 1))        /*判断是否在“否”键上*/
		p[1] = true;
	if (X >= GMSURE_COORD_X && X <= GMSURE_COORD_X + 3 && (Y == GMSURE_COORD_Y || Y == GMSURE_COORD_Y + 1))  /*判断是否在“确定”键上*/
		p[2] = true;

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
		if (IF_GMMB == BUTTON_ONE)   /*“确定”键取消高亮*/
			button_sure.act(DEFAULT);
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
		if (IF_GMMB == BUTTON_ONE)   /*“确定”键设置高亮*/
			button_sure.act(ACTIVATE);
		break;
	}
}

/***************************************************************************
  函数名称：control
  功    能：用键鼠在游戏内对话框内进行操作
  输入参数：const int line：游戏行数（只读）
			const int row：游戏列数（只读）
  返 回 值：int：进行的操作
  说    明：无
***************************************************************************/
int game_mailbox::control(const int line, const int row)
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

		int RET1 = mouse_if_button(X, Y, line, row);  /*判断此时鼠标的位置是否在某个按键中*/
		int RET2 = keyboard_if_button(keycode1);      /*判断此时键盘按下的按钮是否为某个按键*/
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
			}
		}
	}

	cct_disable_mouse();	//禁用鼠标
	return result;
}

/***************************************************************************
  函数名称：erase
  功    能：重画游戏面板，达到擦除对话框的效果
  输入参数：const matrix MATRIX[]：整个游戏的内部结构体数组（只读）
            const int line：游戏行数（只读）
			const int row：游戏列数（只读）
  返 回 值：无
  说    明：本函数重画了对话框对应的那几行以及所有色块
***************************************************************************/
void game_mailbox::erase(const matrix MATRIX[], const int line, const int row)
{
	const int line_min = line % 2 ? line / 2 - 1 : line / 2 - 2;  /*根据行数取最小行数（即对话框占的最上面一行的行数）*/

	for (int i = line_min * row; i < (line_min + 3) * row; i++) {
		const int J = i % row;        /*将一维坐标转换为列标*/
		const int I = (i - J) / row;  /*将一维坐标转换为行标*/
		cct_gotoxy(6 * J + 2, 3 * I + 12);  /*移动光标至对应色块的左上角*/

		if (MATRIX[i].if_flag)  /*若该元素已被插旗，则打印插旗色块*/
			block_print('F' - '0', COLOR_HBLACK, COLOR_HWHITE);

		else {  /*该元素未被插旗的情况*/
			switch (MATRIX[i].if_turned) {
			case true:
				if (MATRIX[i].num)
					block_print(MATRIX[i].num - '0', COLOR_HWHITE, num_trans_color(MATRIX[i].num - '0'));  /*若被翻开且数值不为零，则打印对应色块*/
				else
					block_print(0, COLOR_HWHITE, COLOR_HWHITE);  /*若被翻开且数值为零，则打印空白色块*/
				break;
			case false:
				block_print(NUM_SPACE, COLOR_WHITE, COLOR_BLACK);  /*若未被翻开，则打印初始色块*/
				break;
			}
		}
	}
}