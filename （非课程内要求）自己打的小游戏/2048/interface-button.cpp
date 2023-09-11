#include"90-b3.h"

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
	case KB_UP:
		if (act_mode == ACTIVATE)
			set_color(COLOR_RED, COLOR_WHITE);  /*小键盘上箭头键设置高亮颜色*/
		else
			set_color(COLOR_RED, COLOR_BLACK);  /*小键盘上箭头键取消高亮颜色*/
		print_keyboard_button(BLOCK_ARROW_MODE_UP, bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case KB_DOWN:
		if (act_mode == ACTIVATE)
			set_color(COLOR_YELLOW, COLOR_WHITE);  /*小键盘下箭头键设置高亮颜色*/
		else
			set_color(COLOR_YELLOW, COLOR_BLACK);  /*小键盘下箭头键取消高亮颜色*/
		print_keyboard_button(BLOCK_ARROW_MODE_DOWN, bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case KB_LEFT:
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLUE, COLOR_WHITE);  /*小键盘左箭头键设置高亮颜色*/
		else
			set_color(COLOR_BLUE, COLOR_BLACK);  /*小键盘左箭头键取消高亮颜色*/
		print_keyboard_button(BLOCK_ARROW_MODE_LEFT, bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case KB_RIGHT:
		if (act_mode == ACTIVATE)
			set_color(COLOR_GREEN, COLOR_WHITE);  /*小键盘右箭头键设置高亮颜色*/
		else
			set_color(COLOR_GREEN, COLOR_BLACK);  /*小键盘右箭头键取消高亮颜色*/
		print_keyboard_button(BLOCK_ARROW_MODE_RIGHT, bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case KB_Q:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HRED, COLOR_WHITE);  /*小键盘功能键Q设置高亮颜色*/
		else
			set_color(COLOR_HRED, COLOR_BLACK);  /*小键盘功能键Q取消高亮颜色*/
		cct_showch(x, y, 'Q', bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case KB_R:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HYELLOW, COLOR_WHITE);  /*小键盘功能键R设置高亮颜色*/
		else
			set_color(COLOR_HYELLOW, COLOR_BLACK);  /*小键盘功能键R取消高亮颜色*/
		cct_showch(x, y, 'R', bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case KB_S:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HBLUE, COLOR_WHITE);  /*小键盘功能键S设置高亮颜色*/
		else
			set_color(COLOR_HBLUE, COLOR_BLACK);  /*小键盘功能键S取消高亮颜色*/
		cct_showch(x, y, 'S', bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case KB_D:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HGREEN, COLOR_WHITE);  /*小键盘功能键D设置高亮颜色*/
		else
			set_color(COLOR_HGREEN, COLOR_BLACK);  /*小键盘功能键D取消高亮颜色*/
		cct_showch(x, y, 'D', bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case KB_O:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HBLACK, COLOR_WHITE);  /*小键盘功能键O设置高亮颜色*/
		else
			set_color(COLOR_HBLACK, COLOR_BLACK);  /*小键盘功能键O取消高亮颜色*/
		cct_showch(x, y, 'O', bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case GMMB_YES:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*游戏内对话框“是”键设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*游戏内对话框“是”键取消高亮颜色*/
		cct_showstr(x, y, "是", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_NO:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*游戏内对话框“否”键设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*游戏内对话框“否”键取消高亮颜色*/
		cct_showstr(x, y, "否", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_SURE:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*游戏内对话框“确定”键设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*游戏内对话框“确定”键取消高亮颜色*/
		cct_showstr(x, y, "确定", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━━", bg_color, fg_color);
		break;
	case GMMB_ONE:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*游戏内对话框“1”键设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*游戏内对话框“1”键取消高亮颜色*/
		cct_showstr(x, y, "1 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_TWO:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*游戏内对话框“2”键设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*游戏内对话框“2”键取消高亮颜色*/
		cct_showstr(x, y, "2 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_THREE:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*游戏内对话框“3”键设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*游戏内对话框“3”键取消高亮颜色*/
		cct_showstr(x, y, "3 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_FOUR:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*游戏内对话框“4”键设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*游戏内对话框“4”键取消高亮颜色*/
		cct_showstr(x, y, "4 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_CANCEL:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*游戏内对话框“取消”键设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*游戏内对话框“取消”键取消高亮颜色*/
		cct_showstr(x, y, "取消", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━━", bg_color, fg_color);
		break;
	case GMMB_SW11:
	case GMMB_SW12:
	case GMMB_SW21:
	case GMMB_SW22:
		if (act_mode == ACTIVATE)
			set_color(GMMBSW_BG_COLOR_A, GMMBSW_FG_COLOR);  /*游戏内对话框开关按键设置高亮*/
		else
			set_color(GMMBSW_BG_COLOR_D, GMMBSW_FG_COLOR);  /*游戏内对话框开关按键取消高亮*/
		print_switch_button(bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CVMB_YES:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*标题画面对话框“是”键设置高亮*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*标题画面对话框“是”键取消高亮*/
		cct_showstr(x, y, "是", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_NO:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*标题画面对话框“否”键设置高亮*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*标题画面对话框“否”键取消高亮*/
		cct_showstr(x, y, "否", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_SURE:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*标题画面对话框“确定”键设置高亮*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*标题画面对话框“确定”键取消高亮*/
		cct_showstr(x, y, "确定", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━━", bg_color, fg_color);
		break;
	case CVMB_ONE:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*标题画面对话框“1”键设置高亮*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*标题画面对话框“1”键取消高亮*/
		cct_showstr(x, y, "1 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_TWO:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*标题画面对话框“2”键设置高亮*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*标题画面对话框“2”键取消高亮*/
		cct_showstr(x, y, "2 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_THREE:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*标题画面对话框“3”键设置高亮*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*标题画面对话框“3”键取消高亮*/
		cct_showstr(x, y, "3 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_FOUR:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*标题画面对话框“4”键设置高亮*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*标题画面对话框“4”键取消高亮*/
		cct_showstr(x, y, "4 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_CANCEL:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*标题画面对话框“取消”键设置高亮*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*标题画面对话框“取消”键取消高亮*/
		cct_showstr(x, y, "取消", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━━", bg_color, fg_color);
		break;
	case CVMB_SW11:
	case CVMB_SW12:
	case CVMB_SW21:
	case CVMB_SW22:
		if (act_mode == ACTIVATE)
			set_color(CVMBSW_BG_COLOR_A, CVMBSW_FG_COLOR);  /*标题画面对话框开关按键设置高亮*/
		else
			set_color(CVMBSW_BG_COLOR_D, CVMBSW_FG_COLOR);  /*标题画面对话框开关按键取消高亮*/
		print_switch_button(bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_NEW:
		if (act_mode == ACTIVATE)
			set_color(COLOR_RED, COLOR_BLACK);  /*标题画面“新游戏”键设置高亮*/
		else
			set_color(COLOR_HRED, COLOR_BLACK);  /*标题画面“新游戏”键取消高亮*/
		print_cover_button(" 新游戏 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_LOAD:
		if (act_mode == ACTIVATE)
			set_color(COLOR_YELLOW, COLOR_BLACK);  /*标题画面“载入游戏”键设置高亮*/
		else
			set_color(COLOR_HYELLOW, COLOR_BLACK);  /*标题画面“载入游戏”键取消高亮*/
		print_cover_button("载入游戏", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_AUTO:
		if (act_mode == ACTIVATE)
			set_color(COLOR_CYAN, COLOR_BLACK);  /*标题画面“自动游戏”键设置高亮*/
		else
			set_color(COLOR_HCYAN, COLOR_BLACK);  /*标题画面“自动游戏”键取消高亮*/
		print_cover_button("自动游戏", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_OPTIONS:
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLUE, COLOR_BLACK);  /*标题画面“设置”键设置高亮*/
		else
			set_color(COLOR_HBLUE, COLOR_BLACK);  /*标题画面“设置”键取消高亮*/
		print_cover_button("  设置  ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_ABOUT:
		if (act_mode == ACTIVATE)
			set_color(COLOR_GREEN, COLOR_BLACK);  /*标题画面“关于”键设置高亮*/
		else
			set_color(COLOR_HGREEN, COLOR_BLACK);  /*标题画面“关于”键取消高亮*/
		print_cover_button("  关于  ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_QUIT:
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLACK, COLOR_HWHITE);  /*标题画面“退出游戏”键设置高亮*/
		else
			set_color(COLOR_HBLACK, COLOR_HWHITE);  /*标题画面“退出游戏”键取消高亮*/
		print_cover_button("退出游戏", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	}
}