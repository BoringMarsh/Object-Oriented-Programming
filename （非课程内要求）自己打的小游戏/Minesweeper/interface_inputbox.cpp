#include<windows.h>
#include"90-b4.h"
#include"interface-inputbox.h"

/***************************************************************************
  函数名称：get_width
  功    能：取输入框宽度
  输入参数：无
  返 回 值：int：输入框的宽度
  说    明：该函数可返回私有成员值
***************************************************************************/
int inputbox::get_width()
{
	return IPBX_WIDTH;
}

/***************************************************************************
  函数名称：print
  功    能：打印输入框
  输入参数：const int button_mode：按键形式（只读）
			const char* prompt：提示语（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void inputbox::print(const char* prompt)
{
	/*1、打印输入框外形*/
	cct_showstr(IPBX_COORD_X, IPBX_COORD_Y, "┏━━━━━━━━━━━━━━━┓", IPBX_BG_COLOR, IPBX_FG_COLOR_D);
	cct_showstr(IPBX_COORD_X - 2, IPBX_COORD_Y + 1, "┏┛                              ┗┓", IPBX_BG_COLOR, IPBX_FG_COLOR_D);
	for (int i = 0; i < IPBX_WIDTH - 4; i++) {
		cct_showstr(IPBX_COORD_X - 2, IPBX_COORD_Y + 2 + i, "┃                                  ┃", IPBX_BG_COLOR, IPBX_FG_COLOR_D);
	}
	cct_showstr(IPBX_COORD_X - 2, IPBX_COORD_Y + IPBX_WIDTH - 2, "┗┓                              ┏┛", IPBX_BG_COLOR, IPBX_FG_COLOR_D);
	cct_showstr(IPBX_COORD_X, IPBX_COORD_Y + IPBX_WIDTH - 1, "┗━━━━━━━━━━━━━━━┛", IPBX_BG_COLOR, IPBX_FG_COLOR_D);

	/*2、打印输入框提示语*/
	cct_showstr(IPPROM_COORD_X1, IPPROM_COORD_Y1, prompt, IPBX_BG_COLOR, IPBX_FG_COLOR_D);

	/*3、打印输入框按键*/
	button_ipline.act(DEFAULT);
	button_iprow.act(DEFAULT);
	button_ipbomb.act(DEFAULT);
	button_sure.act(DEFAULT);
	button_cancel.act(DEFAULT);
}

/***************************************************************************
  函数名称：mouse_if_button
  功    能：判断鼠标位置是否在某一按键上
  输入参数：const int X：鼠标位置横坐标（只读）
			const int Y：鼠标位置纵坐标（只读）
  返 回 值：int：鼠标在哪一按键上
  说    明：无
***************************************************************************/
int inputbox::mouse_if_button(const int X, const int Y)
{
	int ret = 0;  /*返回值*/
	bool p[IPBX_BUTTON_NUM];
	for (int i = 0; i < IPBX_BUTTON_NUM; i++)
		p[i] = false;

	if (X >= IPLINE_COORD_X && X <= IPLINE_COORD_X + 5 && Y >= IPLINE_COORD_Y && Y <= IPLINE_COORD_Y + 2)          /*判断是否在行数输入框上*/
		p[0] = true;
	if (X >= IPROW_COORD_X && X <= IPROW_COORD_X + 5 && Y >= IPROW_COORD_Y && Y <= IPROW_COORD_Y + 2)              /*判断是否在列数输入框上*/
		p[1] = true;
	if (X >= IPBOMB_COORD_X && X <= IPBOMB_COORD_X + 5 && Y >= IPBOMB_COORD_Y && Y <= IPBOMB_COORD_Y + 2)          /*判断是否在地雷数输入框上*/
		p[2] = true;
	if (X >= IPSURE_COORD_X && X <= IPSURE_COORD_X + 3 && Y >= IPSURE_COORD_Y && Y <= IPSURE_COORD_Y + 1)          /*判断是否在“确定”键上*/
		p[3] = true;
	if (X >= IPCANCEL_COORD_X && X <= IPCANCEL_COORD_X + 3 && Y >= IPCANCEL_COORD_Y && Y <= IPCANCEL_COORD_Y + 1)  /*判断是否在“取消”键上*/
		p[4] = true;

	/*检查各个位置的情况，遇到真则取对应返回值后结束检查*/
	for (int i = 0; i < IPBX_BUTTON_NUM; i++) {
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
void inputbox::selective_default(const int selection)
{
	switch (selection) {
	case 1:
		button_ipline.act(DEFAULT);  /*行数输入框取消高亮*/
		break;
	case 2:
		button_iprow.act(DEFAULT);   /*列数输入框取消高亮*/
		break;
	case 3:
		button_ipbomb.act(DEFAULT);  /*地雷数输入框取消高亮*/
		break;
	case 4:
		button_sure.act(DEFAULT);    /*“确定”键取消高亮*/
		break;
	case 5:
		button_cancel.act(DEFAULT);  /*“取消”键取消高亮*/
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < IPBX_BUTTON_NUM; i++)  /*所有按键取消高亮*/
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
void inputbox::selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		button_ipline.act(ACTIVATE);  /*行数输入框设置高亮*/
		break;
	case 2:
		button_iprow.act(ACTIVATE);   /*列数输入框设置高亮*/
		break;
	case 3:
		button_ipbomb.act(ACTIVATE);  /*地雷数输入框设置高亮*/
		break;
	case 4:
		button_sure.act(ACTIVATE);    /*“确定”键设置高亮*/
		break;
	case 5:
		button_cancel.act(ACTIVATE);  /*“取消”键设置高亮*/
		break;
	}
}

/***************************************************************************
  函数名称：move_cursor
  功    能：根据正在操作的变量及位数，移动光标至相应位置
  输入参数：const int pblock：正在操作的变量（只读）
            const int ppos：正在操作的位数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void inputbox::move_cursor(const int pblock, const int ppos)
{
	int x = 0, y = 0;  /*横纵坐标*/

	switch (pblock) {  /*根据正在操作的变量，取对应输入框左上角的坐标*/
	case 0:
		x = IPLINE_COORD_X, y = IPLINE_COORD_Y;
		break;
	case 1:
		x = IPROW_COORD_X, y = IPROW_COORD_Y;
		break;
	case 2:
		x = IPBOMB_COORD_X, y = IPBOMB_COORD_Y;
		break;
	}

	switch (ppos) {  /*根据正在操作的位数，移动光标至对应位置*/
	case 1:
		cct_gotoxy(x + 2, y + 1);
		break;
	case 2:
		cct_gotoxy(x + 3, y + 1);
		break;
	}
}

/***************************************************************************
  函数名称：keyboard_input
  功    能：根据正在操作的变量、位数、键盘输入值，改变对应变量的值
  输入参数：const int pblock：正在操作的变量（只读）
			const int ppos：正在操作的位数（只读）
			const int keycode：键盘的输入值（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void inputbox::keyboard_input(const int pblock, const int ppos, const int keycode)
{
	if (keycode >= '0' && keycode <= '9') {  /*键盘输入1-9，增加对应变量的值*/
		switch (pblock) {
		case 0:
			switch (ppos) {
			case 1:
				line = line + keycode - '0';  /*操作行数的第一位，输入值加到个位上*/
				break;
			case 2:
				if (line < 10)
					line = line * 10 + keycode - '0';  /*操作行数的第二位，若行数仅有一位，输入值加到十位上*/
				else
					line = line - line % 10 + keycode - '0';  /*操作行数的第二位，若行数有两位，输入值改变到个位上*/
				break;
			}
			break;
		case 1:
			switch (ppos) {
			case 1:
				row = row + keycode - '0';  /*操作列数的第一位，输入值加到个位上*/
				break;
			case 2:
				if (row < 10)
					row = row * 10 + keycode - '0';  /*操作列数的第二位，若列数仅有一位，输入值加到十位上*/
				else
					row = row - row % 10 + keycode - '0';  /*操作列数的第二位，若列数有两位，输入值改变到个位上*/
				break;
			}
			break;
		case 2:
			switch (ppos) {
			case 1:
				bomb_num = bomb_num + keycode - '0';  /*操作地雷数的第一位，输入值加到个位上*/
				break;
			case 2:
				if (bomb_num < 10)
					bomb_num = bomb_num * 10 + keycode - '0';  /*操作地雷数的第二位，若地雷数仅有一位，输入值加到十位上*/
				else
					bomb_num = bomb_num - bomb_num % 10 + keycode - '0';  /*操作地雷数的第二位，若地雷数有两位，输入值改变到个位上*/
				break;
			}
			break;
		}
	}
	
	else if (keycode == '\b') {  /*键盘输入退格，减少对应变量的值*/
		switch (pblock) {
		case 0:
			switch (ppos) {
			case 1:
				line = 0;  /*操作行数的第一位，直接使行数取零*/
				break;
			case 2:
				line = (line - line % 10) / 10;  /*操作行数的第二位，使行数取操作前的十位数*/
				break;
			}
			break;
		case 1:
			switch (ppos) {
			case 1:
				row = 0;  /*操作列数的第一位，直接使列数取零*/
				break;
			case 2:
				row = (row - row % 10) / 10;  /*操作列数的第二位，使列数取操作前的十位数*/
				break;
			}
			break;
		case 2:
			switch (ppos) {
			case 1:
				bomb_num = 0;  /*操作地雷数的第一位，直接使列数取零*/
				break;
			case 2:
				bomb_num = (bomb_num - bomb_num % 10) / 10;  /*操作地雷数的第二位，使列数取操作前的十位数*/
				break;
			}
			break;
		}
	}
}

/***************************************************************************
  函数名称：info_check
  功    能：检查键盘输入量是否合理
  输入参数：无
  返 回 值：int：所有输入量是否合理
  说    明：本函数若遇到不合理的情况，会在输入框中显示对应的提示语
***************************************************************************/
int inputbox::info_check()
{
	int ret = 0;  /*返回值，先置为0*/

	if (line == 0) {  /*行数为零的情况*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "行数不能为零！", IPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "              ", IPBX_BG_COLOR, COLOR_RED);
	}

	else if (line > LINE_MAX) {  /*行数过大的情况*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "行数过大！", IPBX_BG_COLOR, COLOR_GREEN);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "          ", IPBX_BG_COLOR, COLOR_GREEN);
	}

	else if (row == 0) {  /*列数为零的情况*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "列数不能为零！", IPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "              ", IPBX_BG_COLOR, COLOR_RED);
	}

	else if (row > ROW_MAX) {  /*列数过大的情况*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "列数过大！", IPBX_BG_COLOR, COLOR_GREEN);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "          ", IPBX_BG_COLOR, COLOR_GREEN);
	}

	else if (bomb_num == 0) {  /*地雷数为零的情况*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "地雷数不能为零！", IPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "                ", IPBX_BG_COLOR, COLOR_RED);
	}

	else if (bomb_num > int(line * row * 0.8)) {  /*地雷数过多的情况*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "地雷数过多！", IPBX_BG_COLOR, COLOR_BLUE);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "            ", IPBX_BG_COLOR, COLOR_BLUE);
	}

	else  /*所有输入量均合理，返回值置为1*/
		ret = 1;

	return ret;
}

/***************************************************************************
  函数名称：control
  功    能：用键鼠在输入框内进行操作
  输入参数：无
  返 回 值：int：进行的操作
  说    明：无
***************************************************************************/
int inputbox::control(int* LINE, int* ROW, int* BOMB_NUM)
{
	int X = 0, Y = 0;  /*横纵坐标，初始均为零*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*函数的返回值*/

	int pblock = 0, ppos[3] = { 1,1,1 };  /*指向正在操作变量、位数的指针*/

	cct_enable_mouse();  /*启用鼠标*/
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  /*显示光标*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*读鼠标/键盘*/
		selective_default(DEFAULT_ALL);  /*取消对话框所有按键的高亮*/

		int RET1 = mouse_if_button(X, Y);  /*判断此时鼠标的位置是否在某个按键中*/
		selective_activate(RET1);          /*若鼠标在某个按键中，将对应的按键设置高亮*/

		move_cursor(pblock, ppos[pblock]);  /*移动光标至对应位置*/

		/*1、若返回的是鼠标事件并且按下左键*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {
			selective_default(RET1);  /*取消高亮、延时再设置高亮，营造按键效果*/
			Sleep(100);
			selective_activate(RET1);

			switch (RET1) {
			case 1:
			case 2:
			case 3:
				pblock = RET1 - 1;  /*改变正在操作的变量*/
				break;
			case 4:
				switch (info_check()) {  /*检查所有输入量是否合理，若不合理则重新输入，若合理则取返回值后结束输入*/
				case 0:
					continue;
					break;
				case 1:
					result = IPBX_RET_SURE, loop = 0;
					break;
				}
				break;
			case 5:
				result = IPBX_RET_CANCEL, loop = 0;  /*取返回值后结束输入*/
				break;
			}
		}

		/*2、若返回的是键盘事件*/
		else if (ret == CCT_KEYBOARD_EVENT) {
			int x, y;

			switch (keycode1) {
			case '\n':
			case '\r':
				switch (info_check()) {  /*检查所有输入量是否合理，若不合理则重新输入，若合理则取返回值后结束输入*/
				case 0:
					continue;
					break;
				case 1:
					result = IPBX_RET_SURE, loop = 0;
					break;
				}
				break;
			case 'C':
			case 'c':
				result = IPBX_RET_CANCEL, loop = 0;  /*取返回值后结束输入*/
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				keyboard_input(pblock, ppos[pblock], keycode1);  /*改变对应变量的值*/
				if (ppos[pblock] == 1)  /*若正在操作第一位，则操作位数自增*/
					ppos[pblock]++;

				cct_getxy(x, y);  /*在当前光标位置显示键盘输入的字符*/
				cct_showch(x, y, keycode1, IPBX_BG_COLOR, COLOR_BLACK);
				move_cursor(pblock, ppos[pblock]);  /*完成操作后，移动光标至对应位置*/
				break;
			case '\b':
				keyboard_input(pblock, ppos[pblock], keycode1);  /*改变对应变量的值*/
				cct_getxy(x, y);  /*取当前光标位置*/

				if (ppos[pblock] == 2) {  /*若正在操作第二位，分类讨论*/
					switch (pblock) {
					case 0:
						if (line == 0)  /*若操作后行数为零，说明操作前第二位数为空，则操作位数自减，光标横坐标自减*/
							ppos[pblock]--, x--;
						break;
					case 1:
						if (row == 0)  /*若操作后列数为零，说明操作前第二位数为空，则操作位数自减，光标横坐标自减*/
							ppos[pblock]--, x--;
						break;
					case 2:
						if (bomb_num == 0)  /*若操作后地雷数为零，说明操作前第二位数为空，则操作位数自减，光标横坐标自减*/
							ppos[pblock]--, x--;
						break;
					}
				}

				cct_showch(x, y, ' ', IPBX_BG_COLOR, COLOR_BLACK);  /*在对应位置上输出空格，覆盖原数字，营造退格效果*/
				move_cursor(pblock, ppos[pblock]);  /*完成操作后，移动光标至对应位置*/
				break;
			}
		}
	}

	cct_disable_mouse();	//禁用鼠标
	cct_setcursor(CURSOR_INVISIBLE);  /*隐藏光标*/
	*LINE = line, * ROW = row, * BOMB_NUM = bomb_num;  /*将输入好的值赋给实参*/
	line = 0, row = 0, bomb_num = 0;  /*内部值重新置零，以便下一次打开输入框时都为空*/

	return result;
}