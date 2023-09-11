#include"interface-button.h"

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
  函数名称：set_color
  功    能：给按键设置颜色
  输入参数：const int BG_COLOR：背景色（只读）
			const int FG_COLOR：前景色（只读）
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void button::set_color(const int BG_COLOR, const int FG_COLOR)
{
	bg_color = BG_COLOR;
	fg_color = FG_COLOR;
}

/***************************************************************************
  函数名称：set_coord
  功    能：给按键设置左上角坐标
  输入参数：const int X：左上角横坐标（只读）
		    const int Y：左上角纵坐标（只读）
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void button::set_coord(const int X, const int Y)
{
	x = X;
	y = Y;
}

/***************************************************************************
  函数名称：set_type
  功    能：给按键设置种类
  输入参数：const int TYPE：按键种类（只读）
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void button::set_type(const int TYPE)
{
	type = TYPE;
}

/***************************************************************************
  函数名称：act
  功    能：根据按键的种类表现按键效果
  输入参数：const int act_mode：效果模式（只读）
  返 回 值：无
  说    明：该函数可以为某一按键取消高亮，也可以达到打印该按键的效果
***************************************************************************/
void button::act(const int act_mode)
{
	cct_gotoxy(x, y);  /*移动光标至指定位置*/

	switch (type) {  /*根据按键种类不同设置对应颜色并打印*/
	case GMMB_YES:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);
		cct_showstr(x, y, "是", bg_color, fg_color);
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_NO:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);
		cct_showstr(x, y, "否", bg_color, fg_color);
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_SURE:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);
		cct_showstr(x, y, "确定", bg_color, fg_color);
		cct_showstr(x, y + 1, "━━", bg_color, fg_color);
		break;
	case CV_EASY:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HRED, COLOR_HWHITE);
		else
			set_color(COLOR_RED, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button("  简单  ", bg_color, fg_color);
		break;
	case CV_MEDIUM:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HBLUE, COLOR_HWHITE);
		else
			set_color(COLOR_BLUE, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button("  中等  ", bg_color, fg_color);
		break;
	case CV_HARD:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HGREEN, COLOR_HWHITE);
		else
			set_color(COLOR_GREEN, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button("  困难  ", bg_color, fg_color);
		break;
	case CV_DIY:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HCYAN, COLOR_HWHITE);
		else
			set_color(COLOR_CYAN, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button(" 自定义 ", bg_color, fg_color);
		break;
	case CV_OPTIONS:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HPINK, COLOR_HWHITE);
		else
			set_color(COLOR_PINK, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button("  设置  ", bg_color, fg_color);
		break;
	case CV_QUIT:
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLACK, COLOR_HWHITE);
		else
			set_color(COLOR_HBLACK, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button("  退出  ", bg_color, fg_color);
		break;
	case IPBX_IPLINE:
	case IPBX_IPROW:
	case IPBX_IPBOMB:
		if (act_mode == ACTIVATE)
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_A);
		else
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_D);
		cct_gotoxy(x, y);
		print_empty_block(bg_color, fg_color);
		break;
	case IPBX_SURE:
		if (act_mode == ACTIVATE)
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_A);
		else
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_D);
		cct_showstr(x, y, "确定", bg_color, fg_color);
		cct_showstr(x, y + 1, "━━", bg_color, fg_color);
		break;
	case IPBX_CANCEL:
		if (act_mode == ACTIVATE)
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_A);
		else
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_D);
		cct_showstr(x, y, "取消", bg_color, fg_color);
		cct_showstr(x, y + 1, "━━", bg_color, fg_color);
		break;
	case OPBX_SETSOUND:
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);
		cct_gotoxy(x, y);
		print_empty_block(bg_color, fg_color);
		break;
	case OPBX_SETFONT:
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);
		cct_gotoxy(x, y);
		print_empty_block(bg_color, fg_color);
		break;
	case OPBX_SURE:
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);
		cct_showstr(x, y, " 确定 ", bg_color, fg_color);
		cct_showstr(x, y + 1, "━━━", bg_color, fg_color);
		break;
	case OPBX_CANCEL:
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);
		cct_showstr(x, y, " 取消 ", bg_color, fg_color);
		cct_showstr(x, y + 1, "━━━", bg_color, fg_color);
		break;
	}
}