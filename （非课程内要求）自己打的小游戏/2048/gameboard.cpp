#include"90-b3.h"

/***************************************************************************
  函数名称：print_background
  功    能：打印最底层背景
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void gameboard::print_background()
{
	int Y = 0;  /*行数*/

	/*打印第一行*/
	cct_showstr(0, Y, "┏", GMBD_BG_COLOR, GMBD_FG_COLOR);
	cct_showstr(2, Y, "━", GMBD_BG_COLOR, GMBD_FG_COLOR, 4 * __GAME.order + 11);
	cct_showstr(__GAME.order * 8 + 24, Y, "┓", GMBD_BG_COLOR, GMBD_FG_COLOR);

	/*打印中间行*/
	for (Y = 1; Y < __GAME.order * 4 + 16; Y++) {
		cct_showstr(0, Y, "┃", GMBD_BG_COLOR, GMBD_FG_COLOR);
		cct_showstr(2, Y, "  ", GMBD_BG_COLOR, GMBD_FG_COLOR, 4 * __GAME.order + 11);
		cct_showstr(__GAME.order * 8 + 24, Y, "┃", GMBD_BG_COLOR, GMBD_FG_COLOR);
	}

	/*打印最后一行*/
	cct_showstr(0, __GAME.order * 4 + 16, "┗", GMBD_BG_COLOR, GMBD_FG_COLOR);
	cct_showstr(2, __GAME.order * 4 + 16, "━", GMBD_BG_COLOR, GMBD_FG_COLOR, 4 * __GAME.order + 11);
	cct_showstr(__GAME.order * 8 + 24, __GAME.order * 4 + 16, "┛", GMBD_BG_COLOR, GMBD_FG_COLOR);
}

/***************************************************************************
  函数名称：read_score
  功    能：读取得分并转换成字符串
  输入参数：char* max：存放结果的字符数组
  返 回 值：char*：字符串形式的读取结果
  说    明：1、本函数在读取各个位数完成后，将多余的零转换为空格
			2、手动添加了尾零
***************************************************************************/
char* gameboard::read_score(char* score)
{
	int i;
	int s = __GAME.score;  /*取当前得分*/

	for (i = 0; i < 10; i++) {  /*读各个位数*/
		score[9 - i] = s % 10;
		s = (s - s % 10) / 10;
	}

	i = 0;
	bool if_score_char = false;

	while (i < 10) {
		if (score[i])
			if_score_char = true;  /*遇到第一位不为零的数，设置为真*/
		if (if_score_char)
			score[i] = score[i] + '0';  /*当设置为真后，每一位数转换为对应数字的字符*/
		else
			score[i] = ' ';  /*未设置为真时，每一位数转换为空格*/
		i++;
	}

	score[10] = '\0';  /*添加尾零*/
	return score;
}

/***************************************************************************
  函数名称：read_max
  功    能：读取各个元素中的最大值并转换成字符串
  输入参数：char* max：存放结果的字符数组
  返 回 值：char*：字符串形式的读取结果
  说    明：1、本函数在读取各个位数完成后，将多余的零转换为空格
			2、手动添加了尾零
***************************************************************************/
char* gameboard::read_max(char* max)
{
	int i;
	int m = matrix_getmax();  /*取最大元素*/

	for (i = 0; i < 10; i++) {  /*读各个位数*/
		max[9 - i] = m % 10;
		m = (m - m % 10) / 10;
	}

	i = 0;
	bool if_max_char = false;

	while (i < 10) {
		if (max[i])
			if_max_char = true;  /*遇到第一位不为零的数，设置为真*/
		if (if_max_char)
			max[i] = max[i] + '0';  /*当设置为真后，每一位数转换为对应数字的字符*/
		else
			max[i] = ' ';  /*未设置为真时，每一位数转换为空格*/
		i++;
	}

	max[10] = '\0';  /*添加尾零*/
	return max;
}

/***************************************************************************
  函数名称：read_solution
  功    能：读取寻找出的最优解并转换为字符串
  输入参数：无
  返 回 值：const char*：最优解（字符串形式）
  说    明：1、本函数在读取各个位数完成后，将多余的零转换为空格
			2、手动添加了尾零
***************************************************************************/
const char* gameboard::read_solution()
{
	int ret = __GAME.ai_player.find_best_solution();
	const char* RET = NULL;

	switch (ret) {
	case AI_SLN_UP:
		RET = "  向上合成";
		break;
	case AI_SLN_DOWN:
		RET = "  向下合成";
		break;
	case AI_SLN_LEFT:
		RET = "  向左合成";
		break;
	case AI_SLN_RIGHT:
		RET = "  向右合成";
		break;
	}

	return RET;
}

/***************************************************************************
  函数名称：read_stepnumber
  功    能：读取步数并转换为字符串
  输入参数：无
  返 回 值：char*：字符串形式的读取结果
  说    明：1、本函数在读取各个位数完成后，将多余的零转换为空格
			2、手动添加了尾零
***************************************************************************/
char* gameboard::read_stepnumber(char* stepnumber)
{
	int i;
	int s = __GAME.stepnumber;  /*取步数*/

	for (i = 0; i < 10; i++) {  /*读各个位数*/
		stepnumber[9 - i] = s % 10;
		s = (s - s % 10) / 10;
	}

	i = 0;
	bool if_max_char = false;

	while (i < 10) {
		if (stepnumber[i])
			if_max_char = true;  /*遇到第一位不为零的数，设置为真*/
		if (if_max_char)
			stepnumber[i] = stepnumber[i] + '0';  /*当设置为真后，每一位数转换为对应数字的字符*/
		else
			stepnumber[i] = ' ';  /*未设置为真时，每一位数转换为空格*/
		i++;
	}

	stepnumber[10] = '\0';  /*添加尾零*/
	return stepnumber;
}

/***************************************************************************
  函数名称：print_info
  功    能：显示游戏相关信息
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void gameboard::print_info()
{
	const int X = __GAME.order * 8 + 8;
	const int Y = 2;

	cct_showstr(SCORE_COORD_X, SCORE_COORD_Y, "┏━━━━━┓", SCORE_BG_COLOR, SCORE_FG_COLOR);
	cct_showstr(SCORE_COORD_X, SCORE_COORD_Y + 1, "┃          ┃", SCORE_BG_COLOR, SCORE_FG_COLOR);
	cct_showstr(SCORE_COORD_X, SCORE_COORD_Y + 2, "┃          ┃", SCORE_BG_COLOR, SCORE_FG_COLOR);
	cct_showstr(SCORE_COORD_X, SCORE_COORD_Y + 3, "┗━━━━━┛", SCORE_BG_COLOR, SCORE_FG_COLOR);
	cct_showstr(SCORE_COORD_X + 2, SCORE_COORD_Y + 1, "得分：", SCORE_BG_COLOR, SCORE_FG_COLOR);
	cct_showstr(SCORE_COORD_X + 2, SCORE_COORD_Y + 2, "         0", SCORE_BG_COLOR, SCORE_FG_COLOR);

	cct_showstr(MAX_COORD_X, MAX_COORD_Y, "┏━━━━━┓", MAX_BG_COLOR, MAX_FG_COLOR);
	cct_showstr(MAX_COORD_X, MAX_COORD_Y + 1, "┃          ┃", MAX_BG_COLOR, MAX_FG_COLOR);
	cct_showstr(MAX_COORD_X, MAX_COORD_Y + 2, "┃          ┃", MAX_BG_COLOR, MAX_FG_COLOR);
	cct_showstr(MAX_COORD_X, MAX_COORD_Y + 3, "┗━━━━━┛", MAX_BG_COLOR, MAX_FG_COLOR);
	cct_showstr(MAX_COORD_X + 2, MAX_COORD_Y + 1, "最大值：", MAX_BG_COLOR, MAX_FG_COLOR);
	cct_showstr(MAX_COORD_X + 2, MAX_COORD_Y + 2, "         0", MAX_BG_COLOR, MAX_FG_COLOR);

	cct_showstr(TIPS_COORD_X, TIPS_COORD_Y, "┏━━━━━┓", TIPS_BG_COLOR, TIPS_FG_COLOR);
	cct_showstr(TIPS_COORD_X, TIPS_COORD_Y + 1, "┃          ┃", TIPS_BG_COLOR, TIPS_FG_COLOR);
	cct_showstr(TIPS_COORD_X, TIPS_COORD_Y + 2, "┃          ┃", TIPS_BG_COLOR, TIPS_FG_COLOR);
	cct_showstr(TIPS_COORD_X, TIPS_COORD_Y + 3, "┗━━━━━┛", TIPS_BG_COLOR, TIPS_FG_COLOR);
	cct_showstr(TIPS_COORD_X + 2, TIPS_COORD_Y + 1, "提示：", TIPS_BG_COLOR, TIPS_FG_COLOR);

	if (__GAME.if_tips)
		cct_showstr(TIPS_COORD_X + 2, TIPS_COORD_Y + 2, "请进行移动", COLOR_HWHITE, COLOR_BLACK);
	else
		cct_showstr(TIPS_COORD_X + 6, TIPS_COORD_Y + 2, "已关闭", COLOR_HWHITE, COLOR_BLACK);

	cct_showstr(STEPNUM_COORD_X, STEPNUM_COORD_Y, "┏━━━━━┓", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
	cct_showstr(STEPNUM_COORD_X, STEPNUM_COORD_Y + 1, "┃          ┃", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
	cct_showstr(STEPNUM_COORD_X, STEPNUM_COORD_Y + 2, "┃          ┃", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
	cct_showstr(STEPNUM_COORD_X, STEPNUM_COORD_Y + 3, "┗━━━━━┛", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
	cct_showstr(STEPNUM_COORD_X + 2, STEPNUM_COORD_Y + 1, "当前步数：", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
	cct_showstr(STEPNUM_COORD_X + 2, STEPNUM_COORD_Y + 2, "         0", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
}

/***************************************************************************
  函数名称：update_info
  功    能：更新游戏相关信息
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void gameboard::update_info()
{
	const int X = __GAME.order * 8 + 8;
	const int Y = 2;
	char score[11];
	char max[11];
	char stepnumber[11];

	cct_showstr(X + 2, Y + 2, read_score(score), SCORE_BG_COLOR, SCORE_FG_COLOR);
	cct_showstr(X + 2, Y + 7, read_max(max), MAX_BG_COLOR, MAX_FG_COLOR);
	if (__GAME.if_tips)
		cct_showstr(X + 2, Y + 12, read_solution(), TIPS_BG_COLOR, TIPS_FG_COLOR);
	else
		cct_showstr(X + 2, Y + 12, "    已关闭", TIPS_BG_COLOR, TIPS_FG_COLOR);
	cct_showstr(X + 2, Y + 17, read_stepnumber(stepnumber), STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
}

/***************************************************************************
  函数名称：block_single_print
  功    能：打印一个包含着数字的有颜色的方块
  输入参数：const int num：方块中间的数字（只读）
            const int bg_color：方块背景色（只读）
			const int fg_color：方块前景色（只读）
  返 回 值：无
  说    明：1、本函数以光标当前位置为方块的左上角
			2、中间数字可以显示到四位数了
***************************************************************************/
void gameboard::block_single_print(const int num, const int bg_color, const int fg_color)
{
	int X, Y;         /*横纵坐标*/
	cct_getxy(X, Y);  /*取光标当前坐标*/

	/*1、打印上边界*/
	cct_showstr(X, Y, "┏━┓", bg_color, fg_color);

	/*2、打印左边界*/
	if (num >= 100) {  /*若包含三位及以上数字，左边界为|以及千位或百位数*/
		cct_showch(X, Y + 1, '|', bg_color, fg_color);

		if (num < 1000)  /*三位数打印百位*/
			cct_showch(X + 1, Y + 1, char((num - num % 100) / 100 + '0'), bg_color, fg_color);
		else             /*四位数打印千位*/
			cct_showch(X + 1, Y + 1, char((num - num % 1000) / 1000 + '0'), bg_color, fg_color);
	}

	else  /*若只包含箭头或包含的数字是两位数及以下，则只打印制表符*/
		cct_showstr(X, Y + 1, "┃", bg_color, fg_color);

	/*3、打印中间*/
	const int num1 = num % 10;                          /*取个位*/
	const int num2 = ((num - num % 10) / 10) % 10;      /*取十位*/
	const int num3 = ((num - num % 100) / 100) % 10;    /*取百位*/
	const int num4 = ((num - num % 1000) / 1000) % 10;  /*取千位*/

	int NUM1, NUM2;

	if (num < 10)                       /*若num为一位数，输出该数及一个空格*/
		NUM1 = num1, NUM2 = 0;
	else if (num >= 10 && num < 100)    /*若num为两位数，输出该数两个不同位上的数*/
		NUM1 = num2, NUM2 = num1;
	else if (num >= 100 && num < 1000)  /*若num为三位数，输出该数十位和个位上的数*/
		NUM1 = num2, NUM2 = num1;
	else                                /*若num为四位数，输出该数百位和十位上的数*/
		NUM1 = num3, NUM2 = num2;

	cct_showch(X + 2, Y + 1, char(NUM1 + '0'), bg_color, fg_color);  /*输出第一个数字*/
	const char c = NUM2 ? char(NUM2 + '0') : ' ';                    /*输出第二个数字，当包含个位数时输出空格*/
	cct_showch(X + 3, Y + 1, c, bg_color, fg_color);

	/*4、打印右边界*/
	if (num >= 1000) {  /*若包含四位数，右边界为|以及个位数*/
		cct_showch(X + 4, Y + 1, char(num % 10 + '0'), bg_color, fg_color);
		cct_showch(X + 5, Y + 1, '|', bg_color, fg_color);
	}
	else  /*其余情况只打印制表符*/
		cct_showstr(X + 4, Y + 1, "┃", bg_color, fg_color);

	/*5、打印下边界*/
	cct_showstr(X, Y + 2, "┗━┛", bg_color, fg_color);
	
	cct_setcolor();  /*重置颜色*/
}

/***************************************************************************
  函数名称：block_multiple_print
  功    能：根据当前内部数组值打印色块
  输入参数：无
  返 回 值：无
  说    明：元素为零时清除对应色块
***************************************************************************/
void gameboard::block_multiple_print()
{
	int i;  /*计数变量*/

	for (i = 0; i < __GAME.order * __GAME.order; i++) {
		const int J = i % __GAME.order;        /*将一维坐标转换为列标*/
		const int I = (i - J) / __GAME.order;  /*将一维坐标转换为行标*/

		if (__GAME.matrix[i]) {  /*该元素不为零才重画对应色块，保证游戏效果*/
			cct_gotoxy(8 * J + CSBD_COORD_X + 2, 4 * I + CSBD_COORD_Y + 1);
			block_single_print(__GAME.matrix[i], color_number(__GAME.matrix[i]), COLOR_BLACK);
		}

		else {  /*该元素为零时清除对应色块，保证游戏效果*/
			cct_gotoxy(8 * J + CSBD_COORD_X + 2, 4 * I + CSBD_COORD_Y + 1);
			block_clear();
		}
	}
}

/***************************************************************************
  函数名称：block_clear
  功    能：将当前坐标下对应的色块清除
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void gameboard::block_clear()
{
	int X, Y;
	cct_getxy(X, Y);
	cct_showstr(X, Y, "      ", CSBD_BG_COLOR);      /*用白色擦除第一行*/
	cct_showstr(X, Y + 1, "      ", CSBD_BG_COLOR);  /*用白色擦除第二行*/
	cct_showstr(X, Y + 2, "      ", CSBD_BG_COLOR);  /*用白色擦除第三行*/
	cct_setcolor();  /*重置颜色*/
}

/***************************************************************************
  函数名称：chessboard_single_line
  功    能：输出游戏面板的某一行
  输入参数：int Y：光标调用函数前的纵坐标
			const char* ch1：该行第一个制表符（只读）
			const char* ch2：该行中间的制表符（只读）
			const char* ch3：该行中间的特殊制表符（只读）
			const char* ch4：该行最后一个制表符（只读）
			const bool if_delay:是否延时（只读）
  返 回 值：无
  说    明：1、每行都是从X=2处开始打印
			2、每输出一个制表符，X进行自增2的操作
***************************************************************************/
void gameboard::chessboard_single_line(int Y, const char* ch1, const char* ch2, const char* ch3, const char* ch4, const bool if_delay)
{
	int i;      /*计数变量*/
	int X = CSBD_COORD_X;  /*横坐标，初始为2*/

	/*1、输出第一个制表符*/
	cct_showstr(X, Y, ch1, CSBD_BG_COLOR, CSBD_FG_COLOR);
	X = X + 2;

	/*2、输出中间的多个制表符*/
	for (i = 0; i < 3 * __GAME.order; i++) {

		/*2.1、输出中间的一般制表符*/
		cct_showstr(X, Y, ch2, CSBD_BG_COLOR, CSBD_FG_COLOR);
		X = X + 2;

		/*2.2、在指定位置打印特殊制表符*/
		if (X % 8 == CSBD_COORD_X && X != CSBD_COORD_X + __GAME.order * 8) {
			cct_showstr(X, Y, ch3, CSBD_BG_COLOR, CSBD_FG_COLOR);
			X = X + 2;
		}

		/*2.3、每执行三次停止1，控制打印速度*/
		if (i % 3 == 1 && if_delay)
			Sleep(1);
	}

	/*3、输出最后一个制表符并重置颜色*/
	cct_showstr(X, Y, ch4, CSBD_BG_COLOR, CSBD_FG_COLOR);
	cct_setcolor();
}

/***************************************************************************
  函数名称：chessboard_multiple_lines
  功    能：输出游戏面板的各行
  输入参数：const int Y：行数（只读）
            const bool if_delay:是否延时（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void gameboard::chessboard_multiple_lines(const int Y, const bool if_delay)
{
	/*首行的输出*/
	if (Y == CSBD_COORD_Y)
		chessboard_single_line(Y, "┏", "━", "┳", "┓", if_delay);

	/*最后一行的输出*/
	else if (Y == 4 * __GAME.order + CSBD_COORD_Y)
		chessboard_single_line(Y, "┗", "━", "┻", "┛", if_delay);

	/*特殊行的输出*/
	else if (Y % 4 == CSBD_COORD_Y)
		chessboard_single_line(Y, "┣", "━", "╋", "┫", if_delay);

	/*一般行的输出*/
	else
		chessboard_single_line(Y, "┃", "  ", "┃", "┃", if_delay);
}

/***************************************************************************
  函数名称：print_chessboard
  功    能：打印游戏面板
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void gameboard::print_chessboard()
{
	int Y;          /*纵坐标*/

	/*从第二行开始，逐行打印内容*/
	for (Y = CSBD_COORD_Y; Y <= 4 * __GAME.order + CSBD_COORD_Y; Y++) {
		chessboard_multiple_lines(Y, true);  /*输出不同形式的每一行*/

		cct_gotoxy(CSBD_COORD_X, Y + 1);
	}
}

/***************************************************************************
  函数名称：block_activate
  功    能：将当前坐标下对应的色块设置高亮
  输入参数：const int coord：元素的一维坐标（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void gameboard::block_activate(const int coord)
{
	const int J = coord % __GAME.order;        /*将一维坐标转换为列标*/
	const int I = (coord - J) / __GAME.order;  /*将一维坐标转换为行标*/
	cct_gotoxy(J * 8 + CSBD_COORD_X + 2, I * 4 + CSBD_COORD_Y + 1);   /*移动光标至指定位置，便于接下来重画色块*/
	block_single_print(__GAME.matrix[coord], color_number(__GAME.matrix[coord]), COLOR_WHITE);  /*重画色块，底色不变，前景色为白色*/
	cct_setcolor();  /*重置颜色*/
}

/***************************************************************************
  函数名称：block_default
  功    能：将当前坐标下对应的色块高亮取消
  输入参数：const int coord：元素的一维坐标（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void gameboard::block_default(const int coord)
{
	const int J = coord % __GAME.order;        /*将一维坐标转换为列标*/
	const int I = (coord - J) / __GAME.order;  /*将一维坐标转换为行标*/
	cct_gotoxy(J * 8 + CSBD_COORD_X + 2, I * 4 + CSBD_COORD_Y + 1);   /*移动光标至指定位置，便于接下来重画色块*/
	block_single_print(__GAME.matrix[coord], color_number(__GAME.matrix[coord]), COLOR_BLACK);  /*重画色块，底色不变，前景色为黑色*/
	cct_setcolor();  /*重置颜色*/
}

/***************************************************************************
  函数名称：blink_block
  功    能：使当前坐标下的元素对应色块闪烁
  输入参数：const int coord：元素的一维坐标（只读）
  返 回 值：无
  说    明：本函数设置为闪烁10次
***************************************************************************/
void gameboard::blink_block(const int coord)
{
	const int J = coord % __GAME.order;        /*将一维坐标转换为列标*/
	const int I = (coord - J) / __GAME.order;  /*将一维坐标转换为行标*/
	const int rpt = 10;       /*重复次数：10次*/
	int i;  /*计数变量*/

	for (i = 0; i < rpt; i++) {
		block_activate(coord);  /*设置高亮*/
		Sleep(10);  /*延时10，控制速度*/

		block_default(coord);   /*高亮取消*/
		Sleep(10);  /*延时10，控制速度*/
	}
}