#include"colorball.h"
#include"interface-button.h"

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
  函数名称：act
  功    能：根据按键的种类表现按键效果
  输入参数：const int act_mode：效果模式（只读）
  返 回 值：无
  说    明：1、该函数可以为某一按键取消高亮，也可以达到打印该按键的效果
            2、该函数存储了所有按键的各类表现效果
***************************************************************************/
void button::act(const int act_mode)
{
	cct_gotoxy(x, y);  /*移动光标至指定位置*/

	switch (type) {  /*根据按键种类不同设置对应颜色并打印*/
	case GAME_OPTIONS:  /*游戏内：“设置”键*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLACK, COLOR_HWHITE);  /*设置高亮颜色*/
		else
			set_color(COLOR_HBLACK, COLOR_HWHITE);  /*取消高亮颜色*/
		print_game_button(x, y, " 设置 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case GAME_SAVE:  /*游戏内：“保存”键*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLUE, COLOR_HWHITE);  /*设置高亮颜色*/
		else
			set_color(COLOR_HBLUE, COLOR_HWHITE);  /*取消高亮颜色*/
		print_game_button(x, y, " 保存 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case GAME_DELETE:  /*游戏内：“删除”键*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_GREEN, COLOR_HWHITE);  /*设置高亮颜色*/
		else
			set_color(COLOR_HGREEN, COLOR_HWHITE);  /*取消高亮颜色*/
		print_game_button(x, y, " 删除 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case GAME_QUIT:  /*游戏内：“退出”键*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HBLACK, COLOR_HWHITE);  /*设置高亮颜色*/
		else
			set_color(COLOR_BLACK, COLOR_HWHITE);  /*取消高亮颜色*/
		print_game_button(x, y, " 退出 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case GMMB_YES:  /*游戏内对话框：“是”键*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "是", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_NO:  /*游戏内对话框：“否”键*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "否", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_SURE:  /*游戏内对话框：“确定”键*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "确定", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━━", bg_color, fg_color);
		break;
	case GMMB_ONE:  /*游戏内对话框：“1”键*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "1", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_TWO:  /*游戏内对话框：“2”键*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "2", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_THREE:  /*游戏内对话框：“3”键*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "3", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_FOUR:  /*游戏内对话框：“4”键*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "4", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case GMMB_CANCEL:  /*游戏内对话框：“取消”键*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "取消", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━━", bg_color, fg_color);
		break;
	case GMMB_SW11:  /*游戏内对话框：开关1按键1*/
	case GMMB_SW12:  /*游戏内对话框：开关1按键2*/
	case GMMB_SW21:  /*游戏内对话框：开关2按键1*/
	case GMMB_SW22:  /*游戏内对话框：开关2按键2*/
		if (act_mode == ACTIVATE)
			set_color(GMMBSW_BG_COLOR_A, GMMBSW_FG_COLOR);  /*设置高亮颜色*/
		else
			set_color(GMMBSW_BG_COLOR_D, GMMBSW_FG_COLOR);  /*取消高亮颜色*/
		print_switch_button(bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_NEW:  /*标题画面：“新游戏”键*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HRED, COLOR_HWHITE);  /*设置高亮颜色*/
		else
			set_color(COLOR_RED, COLOR_HWHITE);  /*取消高亮颜色*/
		print_cover_button(" 新游戏 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_LOAD:  /*标题画面：“载入游戏”键*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HBLUE, COLOR_HWHITE);  /*设置高亮颜色*/
		else
			set_color(COLOR_BLUE, COLOR_HWHITE);  /*取消高亮颜色*/
		print_cover_button("载入游戏", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_OPTIONS:  /*标题画面：“设置”键*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HGREEN, COLOR_HWHITE);  /*设置高亮颜色*/
		else
			set_color(COLOR_GREEN, COLOR_HWHITE);  /*取消高亮颜色*/
		print_cover_button("  设置  ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_HELP:  /*标题画面：“帮助”键*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HCYAN, COLOR_HWHITE);  /*设置高亮颜色*/
		else
			set_color(COLOR_CYAN, COLOR_HWHITE);  /*取消高亮颜色*/
		print_cover_button("  帮助  ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_HS:  /*标题画面：“高分榜”键*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HPINK, COLOR_HWHITE);  /*设置高亮颜色*/
		else
			set_color(COLOR_PINK, COLOR_HWHITE);  /*取消高亮颜色*/
		print_cover_button(" 高分榜 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CV_EXIT:  /*标题画面：“退出”键*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLACK, COLOR_HWHITE);  /*设置高亮颜色*/
		else
			set_color(COLOR_HBLACK, COLOR_HWHITE);  /*取消高亮颜色*/
		print_cover_button("  退出  ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case CVMB_YES:  /*标题画面对话框：“是”键*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "是", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_NO:  /*标题画面对话框：“否”键*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "否", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_SURE:  /*标题画面对话框：“确定”键*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "确定", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━━", bg_color, fg_color);
		break;
	case CVMB_ONE:  /*标题画面对话框：“1”键*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "1", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_TWO:  /*标题画面对话框：“2”键*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "2", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_THREE:  /*标题画面对话框：“3”键*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "3", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_FOUR:  /*标题画面对话框：“4”键*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "4", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━", bg_color, fg_color);
		break;
	case CVMB_CANCEL:  /*标题画面对话框：“取消”键*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, "取消", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━━", bg_color, fg_color);
		break;
	case OPBX_SETBLINK:  /*设置对话框：闪烁设置框*/
	case OPBX_SETSHOW:   /*设置对话框：清除效果设置框*/
	case OPBX_SETSOUND:  /*设置对话框：声音设置框*/
	case OPBX_SETFONT:   /*设置对话框：字体大小设置框*/
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);  /*取消高亮颜色*/
		print_empty_block(bg_color, fg_color);  /*设置好颜色后打印该按键*/
		break;
	case OPBX_SURE:  /*设置对话框：“确定”键*/
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, " 确定 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━━━", bg_color, fg_color);
		break;
	case OPBX_CANCEL:  /*设置对话框：“取消”键*/
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);  /*设置高亮颜色*/
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);  /*取消高亮颜色*/
		cct_showstr(x, y, " 取消 ", bg_color, fg_color);  /*设置好颜色后打印该按键*/
		cct_showstr(x, y + 1, "━━━", bg_color, fg_color);
		break;
	}
}