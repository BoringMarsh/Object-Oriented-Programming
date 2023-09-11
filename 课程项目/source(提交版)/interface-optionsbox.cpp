#include<Windows.h>
#include"player.h"
#include"interface-optionsbox.h"
#include"interface-cover.h"

/***************************************************************************
  函数名称：read_fontsize
  功    能：读取字体大小并转换成字符串
  输入参数：char* String：存放结果的字符数组
  返 回 值：char*：字符串形式的读取结果
  说    明：1、存放结果的字符数组仅有三个元素
			2、手动添加了尾零
***************************************************************************/
char* optionsbox::read_fontsize(char* String)
{
	if (fontsize >= 10) {  /*若字体大小大于10，则分别读取两位数*/
		String[0] = (fontsize - fontsize % 10) / 10 + '0';
		String[1] = fontsize % 10 + '0';
	}

	else {  /*若字体大小小于10，则读取个位数后添加一个空格*/
		String[0] = fontsize % 10 + '0';
		String[1] = ' ';
	}

	String[2] = '\0';  /*添加尾零*/
	return String;
}

/***************************************************************************
  函数名称：print
  功    能：打印标题画面对话框
  输入参数：const char* prompt1：提示语1（只读，默认为空指针）
			const char* prompt2：提示语2（只读，默认为空指针）
  返 回 值：无
  说    明：无
***************************************************************************/
void optionsbox::print(const char* prompt1, const char* prompt2)
{
	/*1、打印设置对话框外形*/
	cct_showstr(OPBX_COORD_X, OPBX_COORD_Y, "┏━━━━━━━━━━┓", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	cct_showstr(OPBX_COORD_X - 2, OPBX_COORD_Y + 1, "┏┛                    ┗┓", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	for (int i = 0; i < OPBX_WIDTH - 4; i++) {
		cct_showstr(OPBX_COORD_X - 2, OPBX_COORD_Y + 2 + i, "┃                        ┃", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	}
	cct_showstr(OPBX_COORD_X - 2, OPBX_COORD_Y + OPBX_WIDTH - 2, "┗┓                    ┏┛", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	cct_showstr(OPBX_COORD_X, OPBX_COORD_Y + OPBX_WIDTH - 1, "┗━━━━━━━━━━┛", OPBX_BG_COLOR, OPBX_FG_COLOR_D);

	/*2、打印设置对话框提示语*/
	cct_showstr(OPPROM_COORD_X1, OPPROM_COORD_Y1, prompt1, OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	cct_showstr(OPPROM_COORD_X2, OPPROM_COORD_Y2, prompt2, OPBX_BG_COLOR, OPBX_FG_COLOR_D);

	/*3、打印设置对话框按键*/
	button_setblink.act(DEFAULT);  /*打印闪烁设置框*/
	button_setshow.act(DEFAULT);   /*打印清除效果设置框*/
	button_setsound.act(DEFAULT);  /*打印声音设置框*/
	button_setfont.act(DEFAULT);   /*打印字体大小设置框*/
	button_sure.act(DEFAULT);      /*打印“确定”键*/
	button_cancel.act(DEFAULT);    /*打印“取消”键*/

	/*4、根据设置情况打印设置状态*/
	if (if_blink)  /*是否闪烁*/
		cct_showstr(SETBLINK_COORD_X + 2, SETBLINK_COORD_Y + 1, "√", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	else
		cct_showstr(SETBLINK_COORD_X + 2, SETBLINK_COORD_Y + 1, "×", OPBX_BG_COLOR, OPBX_FG_COLOR_D);

	if (if_show)  /*是否有清除效果*/
		cct_showstr(SETSHOW_COORD_X + 2, SETSHOW_COORD_Y + 1, "√", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	else
		cct_showstr(SETSHOW_COORD_X + 2, SETSHOW_COORD_Y + 1, "×", OPBX_BG_COLOR, OPBX_FG_COLOR_D);

	if (if_sound)  /*是否有声音*/
		cct_showstr(SETSOUND_COORD_X + 2, SETSOUND_COORD_Y + 1, "√", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	else
		cct_showstr(SETSOUND_COORD_X + 2, SETSOUND_COORD_Y + 1, "×", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
}

/***************************************************************************
  函数名称：mouse_if_button
  功    能：判断鼠标位置是否在某一按键上
  输入参数：const int X：鼠标位置横坐标（只读）
			const int Y：鼠标位置纵坐标（只读）
  返 回 值：int：鼠标在哪一按键上
  说    明：无
***************************************************************************/
int optionsbox::mouse_if_button(const int X, const int Y)
{
	int ret = 0;  /*返回值*/
	bool p[OPBX_BUTTON_NUM];
	for (int i = 0; i < OPBX_BUTTON_NUM; i++)
		p[i] = false;

	if (X >= SETBLINK_COORD_X && X <= SETBLINK_COORD_X + 5 && Y >= SETBLINK_COORD_Y && Y <= SETBLINK_COORD_Y + 2)  /*判断是否在闪烁设置框上*/
		p[0] = true;
	if (X >= SETSHOW_COORD_X && X <= SETSHOW_COORD_X + 5 && Y >= SETSHOW_COORD_Y && Y <= SETSHOW_COORD_Y + 2)      /*判断是否在清除效果设置框上*/
		p[1] = true;
	if (X >= SETSOUND_COORD_X && X <= SETSOUND_COORD_X + 5 && Y >= SETSOUND_COORD_Y && Y <= SETSOUND_COORD_Y + 2)  /*判断是否在声音设置框上*/
		p[2] = true;
	if (X >= SETFONT_COORD_X && X <= SETFONT_COORD_X + 5 && Y >= SETFONT_COORD_Y && Y <= SETFONT_COORD_Y + 2)      /*判断是否在字体大小设置框上*/
		p[3] = true;
	if (X >= OPSURE_COORD_X && X <= OPSURE_COORD_X + 5 && Y >= OPSURE_COORD_Y && Y <= OPSURE_COORD_Y + 1)          /*判断是否在“确定”键上*/
		p[4] = true;
	if (X >= OPCANCEL_COORD_X && X <= OPCANCEL_COORD_X + 5 && Y >= OPCANCEL_COORD_Y && Y <= OPCANCEL_COORD_Y + 1)  /*判断是否在“取消”键上*/
		p[5] = true;

	/*检查各个位置的情况，遇到真则取对应返回值后结束检查*/
	for (int i = 0; i < OPBX_BUTTON_NUM; i++) {
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
void optionsbox::selective_default(const int selection)
{
	switch (selection) {
	case 1:
		button_setblink.act(DEFAULT);  /*闪烁设置框取消高亮*/
		break;
	case 2:
		button_setshow.act(DEFAULT);   /*清除效果设置框取消高亮*/
		break;
	case 3:
		button_setsound.act(DEFAULT);  /*声音设置框取消高亮*/
		break;
	case 4:
		button_setfont.act(DEFAULT);   /*字体大小设置框取消高亮*/
		break;
	case 5:
		button_sure.act(DEFAULT);      /*“确定”键取消高亮*/
		break;
	case 6:
		button_cancel.act(DEFAULT);    /*“取消”键取消高亮*/
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < OPBX_BUTTON_NUM; i++)  /*所有按键取消高亮*/
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
void optionsbox::selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		button_setblink.act(ACTIVATE);  /*闪烁设置框取消高亮*/
		break;
	case 2:
		button_setshow.act(ACTIVATE);   /*清除效果设置框取消高亮*/
		break;
	case 3:
		button_setsound.act(ACTIVATE);  /*声音设置框设置高亮*/
		break;
	case 4:
		button_setfont.act(ACTIVATE);   /*字体大小设置框设置高亮*/
		break;
	case 5:
		button_sure.act(ACTIVATE);      /*“确定”键设置高亮*/
		break;
	case 6:
		button_cancel.act(ACTIVATE);    /*“取消”键设置高亮*/
		break;
	}
}

/***************************************************************************
  函数名称：move_cursor
  功    能：根据操作变量情况及位数，移动光标至相应位置
  输入参数：const bool pblock：是否正在操作变量（只读）
			const int ppos：正在操作的位数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void optionsbox::move_cursor(const bool pblock, const int ppos)
{
	if (pblock) {  /*若正在操作变量，则根据正在操作的位数移动光标至相应位置*/
		switch (ppos) {
		case 1:
			cct_gotoxy(SETFONT_COORD_X + 2, SETFONT_COORD_Y + 1);  /*操作字体大小第一位*/
			break;
		case 2:
			cct_gotoxy(SETFONT_COORD_X + 3, SETFONT_COORD_Y + 1);  /*操作字体大小第二位*/
			break;
		}
	}
}

/***************************************************************************
  函数名称：keyboard_input
  功    能：根据操作变量情况、位数、键盘输入值，改变对应变量的值
  输入参数：const bool pblock：操作变量情况（只读）
			const int ppos：正在操作的位数（只读）
			const int keycode：键盘的输入值（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void optionsbox::keyboard_input(const bool pblock, const int ppos, const int keycode)
{
	if (pblock && keycode >= '0' && keycode <= '9') {  /*若正在操作变量，且键盘输入1-9，增加对应变量的值*/
		switch (ppos) {
		case 1:
			fontsize = fontsize + keycode - '0';  /*操作字体大小的第一位，输入值加到个位上*/
			break;
		case 2:
			if (fontsize < 10)
				fontsize = fontsize * 10 + keycode - '0';  /*操作字体大小的第二位，若字体大小仅有一位，输入值加到十位上*/
			else
				fontsize = fontsize - fontsize % 10 + keycode - '0';  /*操作字体大小的第二位，若字体大小有两位，输入值改变到个位上*/
			break;
		}
	}

	else if (pblock && keycode == '\b') {  /*若正在操作变量，且键盘输入退格，减少对应变量的值*/
		switch (ppos) {
		case 1:
			fontsize = 0;  /*操作字体大小的第一位，直接使行数取零*/
			break;
		case 2:
			fontsize = (fontsize - fontsize % 10) / 10;  /*操作字体大小的第二位，使字体大小取操作前的十位数*/
			break;
		}
	}
}

/***************************************************************************
  函数名称：info_check
  功    能：检查键盘输入量是否合理
  输入参数：无
  返 回 值：bool：输入量是否合理
  说    明：本函数若遇到不合理的情况，会在输入框中显示对应的提示语
***************************************************************************/
bool optionsbox::info_check()
{
	bool ret = false;  /*返回值，先置为假*/

	if (fontsize == 0) {  /*字体大小为零的情况*/
		cct_showstr(OPPROM_COORD_X3, OPPROM_COORD_Y3, "字体大小不能为零！", OPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(OPPROM_COORD_X3, OPPROM_COORD_Y3, "                  ", OPBX_BG_COLOR, COLOR_RED);
	}

	else if (fontsize % 2 == 1) {  /*字体大小为奇数的情况*/
		cct_showstr(OPPROM_COORD_X3, OPPROM_COORD_Y3, "字体大小不能为奇数！", OPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(OPPROM_COORD_X3, OPPROM_COORD_Y3, "                    ", OPBX_BG_COLOR, COLOR_BLUE);
	}

	else  /*输入量均合理，返回值置为真*/
		ret = true;

	return ret;
}

/***************************************************************************
  函数名称：control
  功    能：用键鼠在设置对话框内进行操作
  输入参数：bool* IF_SOUND：是否有声音
            int* FONTSIZE：字体大小
  返 回 值：int：进行的操作
  说    明：无
***************************************************************************/
int optionsbox::control(bool* IF_SOUND, int* FONTSIZE)
{
	int X = 0, Y = 0;  /*横纵坐标，初始均为零*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*函数的返回值*/

	bool pblock = false;  /*操作变量情况，先置为假*/
	int ppos = 0;         /*指向位数的指针，先置为零*/
	char font[3];         /*存放字体大小读取结果的字符数组*/

	/*根据字体大小取ppos的初值*/
	if (fontsize >= 10)
		ppos = 2;
	else
		ppos = 1;

	cct_showstr(SETFONT_COORD_X + 2, SETFONT_COORD_Y + 1, read_fontsize(font), OPBX_BG_COLOR, OPBX_FG_COLOR_D);  /*在字体大小设置框中显示读取结果*/
	cct_enable_mouse();  /*启用鼠标*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*读鼠标/键盘*/
		selective_default(DEFAULT_ALL);  /*取消对话框所有按键的高亮*/

		int RET1 = mouse_if_button(X, Y);  /*判断此时鼠标的位置是否在某个按键中*/
		selective_activate(RET1);          /*若鼠标在某个按键中，将对应的按键设置高亮*/

		if (pblock)  /*若正在操作变量，移动光标至对应位置*/
			move_cursor(pblock, ppos);

		/*1、若返回的是鼠标事件并且按下左键*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {
			selective_default(RET1);  /*取消高亮、延时再设置高亮，营造按键效果*/
			Sleep(100);
			selective_activate(RET1);

			switch (RET1) {
			case 1:
				pblock = false;  /*未进行操作变量，情况置为假*/
				cct_setcursor(CURSOR_INVISIBLE);  /*隐藏光标*/

				switch (if_blink) {
				case true:
					if_blink = false;  /*若操作前有闪烁，则置为假，并将设置框中字符换为×*/
					cct_showstr(SETBLINK_COORD_X + 2, SETBLINK_COORD_Y + 1, "×", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				case false:
					if_blink = true;  /*若操作前无闪烁，则置为假，并将设置框中字符换为×*/
					cct_showstr(SETBLINK_COORD_X + 2, SETBLINK_COORD_Y + 1, "√", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				}
				break;
			case 2:
				pblock = false;  /*未进行操作变量，情况置为假*/
				cct_setcursor(CURSOR_INVISIBLE);  /*隐藏光标*/

				switch (if_show) {
				case true:
					if_show = false;  /*若操作前有清除效果，则置为假，并将设置框中字符换为×*/
					cct_showstr(SETSHOW_COORD_X + 2, SETSHOW_COORD_Y + 1, "×", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				case false:
					if_show = true;  /*若操作前无清除效果，则置为假，并将设置框中字符换为×*/
					cct_showstr(SETSHOW_COORD_X + 2, SETSHOW_COORD_Y + 1, "√", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				}
				break;
			case 3:
				pblock = false;  /*未进行操作变量，情况置为假*/
				cct_setcursor(CURSOR_INVISIBLE);  /*隐藏光标*/

				switch (if_sound) {
				case true:
					if_sound = false;  /*若操作前有声音，则置为假，并将设置框中字符换为×*/
					cct_showstr(SETSOUND_COORD_X + 2, SETSOUND_COORD_Y + 1, "×", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				case false:
					if_sound = true;  /*若操作前没有声音，则置为真，并将设置框中字符换为√*/
					cct_showstr(SETSOUND_COORD_X + 2, SETSOUND_COORD_Y + 1, "√", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				}
				break;
			case 4:
				pblock = true;  /*进行操作变量，情况置为真*/
				cct_setcursor(CURSOR_VISIBLE_NORMAL);  /*显示光标*/
				break;
			case 5:
				cct_setcursor(CURSOR_INVISIBLE);  /*即将退出设置对话框，隐藏光标*/

				switch (info_check()) {  /*检查所有输入量是否合理，若合理则取返回值后结束输入，若不合理则重新输入*/
				case true:
					result = OPBX_RET_SURE, loop = 0;
					break;
				case false:
					continue;
					break;
				}
				break;
			case 6:
				cct_setcursor(CURSOR_INVISIBLE);  /*即将退出设置对话框，隐藏光标*/
				result = OPBX_RET_CANCEL, loop = 0;  /*取返回值后结束输入*/
				break;
			}
		}

		/*2、若返回的是键盘事件*/
		else if (ret == CCT_KEYBOARD_EVENT) {
			int x, y;

			switch (keycode1) {
			case '\n':
			case '\r':
				cct_setcursor(CURSOR_INVISIBLE);  /*即将退出设置对话框，隐藏光标*/

				switch (info_check()) {  /*检查所有输入量是否合理，若合理则取返回值后结束输入，若不合理则重新输入*/
				case true:
					result = OPBX_RET_SURE, loop = 0;
					break;
				case false:
					continue;
					break;
				}
				break;
			case 'C':
			case 'c':
				cct_setcursor(CURSOR_INVISIBLE);  /*即将退出设置对话框，隐藏光标*/
				result = OPBX_RET_CANCEL, loop = 0;  /*取返回值后结束输入*/
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
				keyboard_input(pblock, ppos, keycode1);  /*改变对应变量的值*/

				if (pblock) {  /*若正在操作变量，进行以下操作*/
					if (ppos == 1)  /*若正在操作第一位，则操作位数自增*/
						ppos++;

					cct_getxy(x, y);  /*在当前光标位置显示键盘输入的字符*/
					cct_showch(x, y, keycode1, OPBX_BG_COLOR, OPBX_FG_COLOR_D);
				}

				move_cursor(pblock, ppos);  /*完成操作后，移动光标至对应位置*/
				break;
			case '\b':
				keyboard_input(pblock, ppos, keycode1);  /*改变对应变量的值*/

				if (pblock) {  /*若正在操作变量，进行以下操作*/
					cct_getxy(x, y);  /*取当前光标位置*/

					if (ppos == 2 && fontsize == 0)  /*若正在操作第二位且操作后行数为零，说明操作前第二位数为空，则操作位数自减，光标横坐标自减*/
						ppos--, x--;

					cct_showch(x, y, ' ', OPBX_BG_COLOR, OPBX_FG_COLOR_D);  /*在对应位置上输出空格，覆盖原数字，营造退格效果*/
				}

				move_cursor(pblock, ppos);  /*完成操作后，移动光标至对应位置*/
				break;
			}
		}
	}

	cct_disable_mouse();	//禁用鼠标

	switch (result) {
	case OPBX_RET_SURE:  /*若按“确定”键，则将设置好的值返回给实参，达到设置效果*/
		*IF_SOUND = if_sound;
		*FONTSIZE = fontsize;
		player::if_blink = if_blink;
		player::if_show = if_show;
		break;
	case OPBX_RET_CANCEL:  /*若按“取消”键，则实参赋值给内部值，达到取消效果*/
		if_sound = *IF_SOUND;
		fontsize = *FONTSIZE;
		if_blink = player::if_blink;
		if_show = player::if_show;
		break;
	}

	return result;
}

/***************************************************************************
  函数名称：erase
  功    能：重画标题画面，达到擦除对话框的效果
  输入参数：cover& TitleScreen：标题画面对象
  返 回 值：无
  说    明：本函数重画了对话框对应的那几行以及所有数字和其他被盖住的部分
***************************************************************************/
void optionsbox::erase(cover& TitleScreen)
{
	int i;

	/*1、补上背景*/
	for (i = 0; i < OPBX_WIDTH; i++)
		cct_showstr(0, OPBX_COORD_Y + i, "┃                                                                            ┃", COLOR_WHITE, COLOR_BLACK);  /*按行重画背景*/

	/*2、补上标题画面上的其他部分*/
	TitleScreen.O_print(1);  /*第一个字母O*/
	TitleScreen.O_print(2);  /*第二个字母O*/
	TitleScreen.B_print();   /*字母B*/
	TitleScreen.A_print();   /*字母A*/
	TitleScreen.L_print(2);  /*第二个字母L*/
	TitleScreen.L_print(3);  /*第三个字母L*/
	TitleScreen.ball_print(5, 10, COLOR_YELLOW);  /*橙色珠子*/
	TitleScreen.ball_print(22, 13, COLOR_GREEN);  /*绿色珠子*/
	TitleScreen.ball_print(60, 5, COLOR_BLUE);    /*蓝色珠子*/
	TitleScreen.ball_print(72, 21, COLOR_PINK);   /*紫色珠子*/
	TitleScreen.button_new.act(DEFAULT);      /*“新游戏”键*/
	TitleScreen.button_load.act(DEFAULT);     /*“载入游戏”键*/
	TitleScreen.button_options.act(DEFAULT);  /*“设置”键*/
}