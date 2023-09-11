#include<cmath>
#include"cmd_console_tools.h"
#include"90-b4.h"
#include"interface-mailbox.h"

/***************************************************************************
  函数名称：block_single_print
  功    能：打印一个包含着字符的有颜色的方块
  输入参数：const int num：方块中间的数字（只读）
			const int bg_color：方块背景色（只读）
			const int fg_color：方块前景色（只读）
  返 回 值：无
  说    明：1、本函数以光标当前位置为方块的左上角
			2、本游戏中中间只可能有一个字符，故仅处理一个字符的输出
			3、当数值为'*'-'0'时输出中间字符为'*'的色块
			4、可以输出中间字符为'√'的色块
***************************************************************************/
void block_print(const int num, const int bg_color, const int fg_color)
{
	int X, Y;         /*横纵坐标*/
	cct_getxy(X, Y);  /*取光标当前坐标*/

	/*1、打印上边界*/
	cct_showstr(X, Y, "┏━┓", bg_color, fg_color);

	/*2、打印左边界*/
	cct_showstr(X, Y + 1, "┃", bg_color, fg_color);

	/*3、打印中间*/
	if (num == '*' - '0') {
		cct_showch(X + 2, Y + 1, '*', bg_color, fg_color);
		cct_showch(X + 3, Y + 1, ' ', bg_color, fg_color);
	}

	else if (num == '√')
		cct_showstr(X + 2, Y + 1, "√", bg_color, fg_color);

	else {
		cct_showch(X + 2, Y + 1, char(num + '0'), bg_color, fg_color);  /*输出第一个数字*/
		cct_showch(X + 3, Y + 1, ' ', bg_color, fg_color);  /*输出第一个数字后的空格*/
	}

	/*4、打印右边界*/
	cct_showstr(X + 4, Y + 1, "┃", bg_color, fg_color);

	/*5、打印下边界*/
	cct_showstr(X, Y + 2, "┗━┛", bg_color, fg_color);

	cct_setcolor();  /*重置颜色*/
}

/***************************************************************************
  函数名称：block_blink
  功    能：使当前坐标下的元素对应色块闪烁
  输入参数：const int row：游戏列数（只读）
            const int coord：元素的一维坐标（只读）
			const int bg_color1：闪烁背景色1（只读）
			const int bg_color2：闪烁背景色2（只读）
			const int fg_color：前景色（只读）
  返 回 值：无
  说    明：本函数设置为闪烁2次
***************************************************************************/
void block_blink(const int row, const int coord, const int bg_color1, const int bg_color2, const int fg_color)
{
	const int J = coord % row;        /*将一维坐标转换为列标*/
	const int I = (coord - J) / row;  /*将一维坐标转换为行标*/
	const int rpt = 2;  /*重复次数：2次*/

	for (int i = 0; i < rpt; i++) {
		cct_gotoxy(6 * J + 2, 3 * I + 12);
		block_print('*' - '0', bg_color1, fg_color);
		Sleep(1);  /*延时1，控制速度*/

		cct_gotoxy(6 * J + 2, 3 * I + 12);
		block_print('*' - '0', bg_color2, fg_color);
		Sleep(1);  /*延时1，控制速度*/
	}
}

/***************************************************************************
  函数名称：gameboard_print
  功    能：打印游戏面板背景
  输入参数：const int line：游戏行数（只读）
			const int row：游戏列数（只读）
  返 回 值：无
  说    明：1、本函数在色块放置区上方预留了10行的空间
            2、输出制表符的同时横纵坐标变量同步改变
***************************************************************************/
void gameboard_print(const int line, const int row)
{
	int X = 0, Y = 0;  /*光标当前横纵坐标，初始均为0*/

	/*1、输出左上角制表符*/
	cct_showstr(X, Y, "┏", COLOR_HWHITE, COLOR_BLACK);
	X = X + 2;

	/*2、输出第一行中间制表符*/
	for (int i = 0; i < 3 * row; i++, X = X + 2)
		cct_showstr(X, Y, "━", COLOR_HWHITE, COLOR_BLACK);

	/*3、输出右上角制表符*/
	cct_showstr(X, Y, "┓", COLOR_HWHITE, COLOR_BLACK);
	Y = Y + 1, X = 0;

	/*4、循环输出中间每一行*/
	for (int i = 0; i < 3 * line + 11; i++, Y++, X = 0) {
		if (i == 10) {  /*输出第10行分界线*/
			cct_showstr(X, Y, "┣", COLOR_HWHITE, COLOR_BLACK);
			X = X + 2;

			for (int j = 0; j < 3 * row; j++, X = X + 2)
				cct_showstr(X, Y, "━", COLOR_HWHITE, COLOR_BLACK);

			cct_showstr(X, Y, "┫", COLOR_HWHITE, COLOR_HBLACK);
		}

		else {  /*输出其余空白行*/
			cct_showstr(X, Y, "┃", COLOR_HWHITE, COLOR_BLACK);
			X = X + 2;

			for (int j = 0; j < 6 * row; j++, X++)
				cct_showch(X, Y, ' ', COLOR_HWHITE, COLOR_BLACK);

			cct_showstr(X, Y, "┃", COLOR_HWHITE, COLOR_HBLACK);
		}
	}

	/*5、输出左下角制表符*/
	cct_showstr(X, Y, "┗", COLOR_HWHITE, COLOR_BLACK);
	X = X + 2;

	/*6、输出最后一行中间制表符*/
	for (int i = 0; i < 3 * row; i++, X = X + 2)
		cct_showstr(X, Y, "━", COLOR_HWHITE, COLOR_BLACK);

	/*7、输出右下角制表符*/
	cct_showstr(X, Y, "┛", COLOR_HWHITE, COLOR_BLACK);

	cct_setcolor();  /*重设颜色*/
}

/***************************************************************************
  函数名称：read_bomb_num
  功    能：读取剩余地雷数并转换成字符串
  输入参数：char* bomb_num：存放结果的字符数组
            const int BOMB_NUM：当前剩余地雷数（只读）
  返 回 值：char*：字符串形式的读取结果
  说    明：1、本函数在读取各个位数完成后，将多余的零转换为空格
			2、手动添加了尾零
			3、若读取的是负数，则添加了负号
***************************************************************************/
char* read_bomb_num(char* bomb_num, const int BOMB_NUM)
{
	if (BOMB_NUM) {
		int i;
		int b = int(fabs(BOMB_NUM));

		for (i = 0; i < 10; i++) {  /*读各个位数*/
			bomb_num[9 - i] = b % 10;
			b = (b - b % 10) / 10;
		}

		i = 0;
		bool if_bomb_num_char = false;

		while (i < 10) {
			if (bomb_num[i]) {
				if_bomb_num_char = true;  /*遇到第一位不为零的数，设置为真*/

				if (BOMB_NUM < 0)  /*若BOMB_NUM为负，第一位不为零的数前一位为负号*/
					bomb_num[i - 1] = '-';
			}
			if (if_bomb_num_char)
				bomb_num[i] = bomb_num[i] + '0';  /*当设置为真后，每一位数转换为对应数字的字符*/
			else
				bomb_num[i] = ' ';  /*未设置为真时，每一位数转换为空格*/
			i++;
		}
	}
	
	else {
		for (int i = 0; i < 9; i++)
			bomb_num[i] = ' ';
		bomb_num[9] = '0';
	}

	bomb_num[10] = '\0';  /*添加尾零*/
	return bomb_num;
}

/***************************************************************************
  函数名称：read_time
  功    能：读取用时并转换成字符串
  输入参数：char* time：存放结果的字符数组
  返 回 值：char*：字符串形式的读取结果
  说    明：1、本函数在读取各个位数完成后，将多余的零转换为空格
			2、手动添加了尾零
			3、仅读取用时的整数部分，单位为秒
***************************************************************************/
char* read_time(char* time, const LONGLONG TIME)
{
	if (TIME) {
		int i;
		LONGLONG t = TIME;  /*取当前用时*/

		for (i = 0; i < 10; i++) {  /*读各个位数*/
			time[9 - i] = t % 10;
			t = (t - t % 10) / 10;
		}

		i = 0;
		bool if_time_char = false;

		while (i < 10) {
			if (time[i])
				if_time_char = true;  /*遇到第一位不为零的数，设置为真*/
			if (if_time_char)
				time[i] = time[i] + '0';  /*当设置为真后，每一位数转换为对应数字的字符*/
			else
				time[i] = ' ';  /*未设置为真时，每一位数转换为空格*/
			i++;
		}
	}
	
	else {
		for (int i = 0; i < 9; i++)
			time[i] = ' ';
		time[9] = '0';
	}

	time[10] = '\0';  /*添加尾零*/
	return time;
}

/***************************************************************************
  函数名称：print_info
  功    能：输出游戏信息
  输入参数：const int row：游戏列数（只读）
            const int bomb_num：地雷数目（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void print_info(const int row, const int bomb_num)
{
	char bn[11];

	/*打印新游戏键*/
	cct_showstr(NEW_COORD_X, NEW_COORD_Y, "┏━┓", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 1, "┃", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X + 2, NEW_COORD_Y + 1, "\001", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X + 4, NEW_COORD_Y + 1, "┃", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 2, "┗━┛", NEW_BG_COLOR_D, NEW_FG_COLOR_D);

	/*打印剩余雷数*/
	cct_showstr(MINE_COORD_X, MINE_COORD_Y, "┏━━━━━┓", MINE_BG_COLOR, MINE_FG_COLOR);
	cct_showstr(MINE_COORD_X, MINE_COORD_Y + 1, "┃          ┃", MINE_BG_COLOR, MINE_FG_COLOR);
	cct_showstr(MINE_COORD_X, MINE_COORD_Y + 2, "┃          ┃", MINE_BG_COLOR, MINE_FG_COLOR);
	cct_showstr(MINE_COORD_X, MINE_COORD_Y + 3, "┗━━━━━┛", MINE_BG_COLOR, MINE_FG_COLOR);
	cct_showstr(MINE_COORD_X + 2, MINE_COORD_Y + 1, "剩余雷数：", MINE_BG_COLOR, MINE_FG_COLOR);
	cct_showstr(MINE_COORD_X + 2, MINE_COORD_Y + 2, read_bomb_num(bn, bomb_num), MINE_BG_COLOR, MINE_FG_COLOR);

	/*打印用时*/
	cct_showstr(TIME_COORD_X, TIME_COORD_Y, "┏━━━━━┓", TIME_BG_COLOR, TIME_FG_COLOR);
	cct_showstr(TIME_COORD_X, TIME_COORD_Y + 1, "┃          ┃", TIME_BG_COLOR, TIME_FG_COLOR);
	cct_showstr(TIME_COORD_X, TIME_COORD_Y + 2, "┃          ┃", TIME_BG_COLOR, TIME_FG_COLOR);
	cct_showstr(TIME_COORD_X, TIME_COORD_Y + 3, "┗━━━━━┛", TIME_BG_COLOR, TIME_FG_COLOR);
	cct_showstr(TIME_COORD_X + 2, TIME_COORD_Y + 1, "时间：", TIME_BG_COLOR, TIME_FG_COLOR);
	cct_showstr(TIME_COORD_X + 2, TIME_COORD_Y + 2, "         0", TIME_BG_COLOR, TIME_FG_COLOR);
}

/***************************************************************************
  函数名称：update_bomb_num
  功    能：更新剩余雷数
  输入参数：const int row：游戏列数（只读）
            const int bomb_num：地雷数目（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void update_bomb_num(const int row, const int bomb_num)
{
	char bn[11];

	cct_showstr(MINE_COORD_X + 2, MINE_COORD_Y + 2, read_bomb_num(bn, bomb_num), MINE_BG_COLOR, MINE_FG_COLOR);
}

/***************************************************************************
  函数名称：update_time
  功    能：更新用时
  输入参数：const int row：游戏列数（只读）
			const LARGE_INTEGER tick：存放计数器频率信息的结构体（只读）
			const LARGE_INTEGER begin：存放初始硬件计数器计数信息的结构体（只读）
			const LARGE_INTEGER end：存放终止硬件计数器计数信息的结构体（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void update_time(const int row, const LARGE_INTEGER tick, const LARGE_INTEGER begin, const LARGE_INTEGER end)
{
	char time[11];
	const LONGLONG TIME = (end.QuadPart - begin.QuadPart) / tick.QuadPart;

	cct_showstr(TIME_COORD_X + 2, TIME_COORD_Y + 2, read_time(time, TIME), TIME_BG_COLOR, TIME_FG_COLOR);
}

/***************************************************************************
  函数名称：if_block
  功    能：判断鼠标位置是否在某一色块上
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
            const int X：鼠标位置横坐标（只读）
			const int Y：鼠标位置纵坐标（只读）
            const int line：游戏行数（只读）
			const int row：游戏列数（只读）
  返 回 值：int：色块对应元素的一维坐标（若在范围外则返回零）
  说    明：无
***************************************************************************/
int if_block(matrix MATRIX[], const int X, const int Y, const int line, const int row)
{
	int ret = INT_MAX;  /*返回值，先设为一不可能值*/

	for (int i = 0; i < line * row; i++) {  /*逐个检查所有元素位置，若发现鼠标在某个色块内，设置返回值、做标记并结束检查*/
		const int J = i % row;        /*将一维坐标转换为列标*/
		const int I = (i - J) / row;  /*将一维坐标转换为行标*/

		if (X >= 6 * J + 2 && X <= 6 * J + 7 && Y >= 3 * I + 12 && Y <= 3 * I + 14) {
			ret = I * row + J;  /*设置返回值*/
			MATRIX[ret].coord_mark = true;  /*设置对应元素的坐标标记*/
			break;
		}
	}

	return ret;
}

/***************************************************************************
  函数名称：if_new_button
  功    能：判断鼠标位置是否在新游戏键上
  输入参数：const int X：鼠标位置横坐标（只读）
			const int Y：鼠标位置纵坐标（只读）
			const int row：游戏列数（只读）
  返 回 值：bool：鼠标位置是否在新游戏键上
  说    明：由于宏定义中有运算过程，故先进行运算并将值赋给常变量，再进行位置判断
***************************************************************************/
bool if_new_button(const int X, const int Y, const int row)
{
	const int coord_x = NEW_COORD_X;  //取新游戏键左上角横坐标
	const int coord_y = NEW_COORD_Y;  //取新游戏键左上角纵坐标

	if (X >= coord_x && X <= coord_x + 5 && Y >= coord_y && Y <= coord_y + 2)
		return true;
	else
		return false;
}

/***************************************************************************
  函数名称：new_button_default
  功    能：新游戏键取消高亮
  输入参数：const int row：游戏列数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void new_button_default(const int row)
{
	cct_showstr(NEW_COORD_X, NEW_COORD_Y, "┏━┓", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 1, "┃", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X + 2, NEW_COORD_Y + 1, "\001", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X + 4, NEW_COORD_Y + 1, "┃", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 2, "┗━┛", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
}

/***************************************************************************
  函数名称：new_button_activate
  功    能：新游戏键设置高亮
  输入参数：const int row：游戏列数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void new_button_activate(const int row)
{
	cct_showstr(NEW_COORD_X, NEW_COORD_Y, "┏━┓", NEW_BG_COLOR_A, NEW_FG_COLOR_A);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 1, "┃", NEW_BG_COLOR_A, NEW_FG_COLOR_A);
	cct_showstr(NEW_COORD_X + 2, NEW_COORD_Y + 1, "\001", NEW_BG_COLOR_A, NEW_FG_COLOR_A);
	cct_showstr(NEW_COORD_X + 4, NEW_COORD_Y + 1, "┃", NEW_BG_COLOR_A, NEW_FG_COLOR_A);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 2, "┗━┛", NEW_BG_COLOR_A, NEW_FG_COLOR_A);
}

/***************************************************************************
  函数名称：selective_default
  功    能：选择性地为某一色块取消高亮
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int coord：上一个设置高亮色块对应元素的一维坐标（只读）
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
  返 回 值：无
  说    明：对应元素为以下条件进行操作：有坐标标记、未被翻开、未被插旗
***************************************************************************/
void selective_default(matrix MATRIX[], const int line, const int row, const int coord)
{
	for (int i = 0; i < line * row; i++) {
		const int J = i % row;        /*将一维坐标转换为列标*/
		const int I = (i - J) / row;  /*将一维坐标转换为行标*/

		/*若当前元素被坐标标记，且不是上一个设置高亮色块对应元素，未被翻开也未被插旗，则进行操作*/
		if (MATRIX[i].coord_mark && i != coord && !MATRIX[i].if_turned && !MATRIX[i].if_flag) {
			cct_gotoxy(6 * J + 2, 3 * I + 12);  /*移动光标至相应位置*/
			block_print(NUM_SPACE, COLOR_WHITE, COLOR_BLACK);  /*打印中间为空的初始色块*/
			MATRIX[i].coord_mark = false;  /*取消坐标标记*/
		}
	}
}

/***************************************************************************
  函数名称：selective_activate
  功    能：选择性地为某一色块设置高亮
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int coord：色块对应元素的一维坐标（只读）
			const int X：鼠标位置横坐标（只读）
			const int Y：鼠标位置纵坐标（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void selective_activate(matrix MATRIX[], const int line, const int row, const int coord, const int X, const int Y)
{
	const int J = coord % row;        /*将一维坐标转换为列标*/
	const int I = (coord - J) / row;  /*将一维坐标转换为行标*/

	/*若鼠标位置在某一色块内，且对应元素未被翻开，则进行操作*/
	if (X >= 2 && X <= 6 * row && Y >= 12 && Y <= 3 * line + 10 && !MATRIX[coord].if_turned) {
		cct_gotoxy(6 * J + 2, 3 * I + 12);  /*移动光标至相应位置*/

		if (!MATRIX[coord].if_flag)
			block_print(NUM_SPACE, COLOR_HWHITE, COLOR_BLACK);  /*若该元素未被插旗，则打印中间为空的高亮色块*/
	}
}

/***************************************************************************
  函数名称：turn
  功    能：翻开一个元素
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int coord：内部数组中对应元素的一维坐标（只读）
  返 回 值：int：翻开情况
  说    明：正常翻开返回0，若翻开地雷，则返回对应值
***************************************************************************/
int turn(matrix MATRIX[], const int line, const int row, const int coord)
{
	int ret = 0;  /*返回值，先设为0*/

	if (!MATRIX[coord].if_turned && !MATRIX[coord].if_flag) {  /*只有在目标元素未被翻开且未被插旗的情况下才开始操作*/
		switch (MATRIX[coord].num) {
		case '0':
			matrix m[LINE_MAX * ROW_MAX];

			while (!matrix_compare(m, MATRIX, line, row)) {  /*第一轮标记：标记相连的所有零元素*/
				matrix_copy(m, MATRIX, line, row);

				for (int i = 0; i < line * row; i++) {
					zero_check1(MATRIX, line, row, i);
				}
			}

			for (int i = 0; i < line * row; i++)  /*第二轮标记：标记所有被标记零元素周围的所有元素*/
				zero_check2(MATRIX, line, row, i);

			for (int i = 0; i < line * row; i++) {  /*翻开所有被标记的元素*/
				if (MATRIX[i].mark) {
					const int L = i % row;        /*将一维坐标转换为列标*/
					const int K = (i - L) / row;  /*将一维坐标转换为行标*/
					cct_gotoxy(6 * L + 2, 3 * K + 12);
					block_print(MATRIX[i].num - '0', COLOR_HWHITE, num_trans_color(MATRIX[i].num - '0'));
					MATRIX[i].mark = false;      /*取消一般标记*/
					MATRIX[i].if_turned = true;  /*元素设为已被翻开状态*/
				}
			}

			break;
		case '*':
			failure(MATRIX, line, row, coord);  /*播放失败效果动画*/
			ret = FAILURE;  /*返回对应值*/
			break;
		default:
			const int J = coord % row;        /*将一维坐标转换为列标*/
			const int I = (coord - J) / row;  /*将一维坐标转换为行标*/
			cct_gotoxy(6 * J + 2, 3 * I + 12);
			block_print(MATRIX[coord].num - '0', COLOR_HWHITE, num_trans_color(MATRIX[coord].num - '0'));
			MATRIX[coord].mark = false;      /*取消一般标记*/
			MATRIX[coord].if_turned = true;  /*元素设为已被翻开状态*/
			break;
		}
	}

	return ret;
}

/***************************************************************************
  函数名称：wheel_click_turn
  功    能：按鼠标中键时的翻开操作
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int coord：内部数组中对应元素的一维坐标（只读）
  返 回 值：int：翻开情况
  说    明：1、正常翻开返回0，若翻开地雷，则返回对应值
			2、仅有在该元素周围的插旗数目等于其数值时才进行操作
***************************************************************************/
int wheel_click_turn(matrix MATRIX[], const int line, const int row, const int coord)
{
	int RET = 0;  /*返回值，先设为0*/

	if (MATRIX[coord].if_turned && !MATRIX[coord].if_flag  /*只有在该元素已被翻开且未被插旗的情况下才进行操作*/
		&& flag_check(MATRIX, line, row, coord) == MATRIX[coord].num - '0') {
		const int J = coord % row;        /*将一维坐标转换为列标*/
		const int I = (coord - J) / row;  /*将一维坐标转换为行标*/
		int ret[8] = { 0 };  /*接收turn()函数返回值的数组，全部设为0*/

		if (I) {  /*若目标元素不在第一行，检查其上面一个元素*/
			if (!MATRIX[coord - row].if_flag) {
				MATRIX[coord - row].mark = true;
				ret[0] = turn(MATRIX, line, row, coord - row);
			}
		}

		if (J) {  /*若目标元素不在第一列，检查其左边一个元素*/
			if (!MATRIX[coord - 1].if_flag) {
				MATRIX[coord - 1].mark = true;
				ret[1] = turn(MATRIX, line, row, coord - 1);
			}
		}

		if (I < line - 1) {  /*若目标元素不在最后一行，检查其下面一个元素*/
			if (!MATRIX[coord + row].if_flag) {
				MATRIX[coord + row].mark = true;
				ret[2] = turn(MATRIX, line, row, coord + row);
			}
		}

		if (J < row - 1) { /*若目标元素不在最后一列，检查其右边一个元素*/
			if (!MATRIX[coord + 1].if_flag) {
				MATRIX[coord + 1].mark = true;
				ret[3] = turn(MATRIX, line, row, coord + 1);
			}
		}

		if (I && J) { /*检查目标元素左上角的元素*/
			if (!MATRIX[coord - row - 1].if_flag) {
				MATRIX[coord - row - 1].mark = true;
				ret[4] = turn(MATRIX, line, row, coord - row - 1);
			}
		}

		if (I && J < row - 1) { /*检查目标元素右上角的元素*/
			if (!MATRIX[coord - row + 1].if_flag) {
				MATRIX[coord - row + 1].mark = true;
				ret[5] = turn(MATRIX, line, row, coord - row + 1);
			}
		}

		if (I < line - 1 && J) { /*检查目标元素左下角的元素*/
			if (!MATRIX[coord + row - 1].if_flag) {
				MATRIX[coord + row - 1].mark = true;
				ret[6] = turn(MATRIX, line, row, coord + row - 1);
			}
		}

		if (I < line - 1 && J < row - 1) { /*检查目标元素右下角的元素*/
			if (!MATRIX[coord + row + 1].if_flag) {
				MATRIX[coord + row + 1].mark = true;
				ret[7] = turn(MATRIX, line, row, coord + row + 1);
			}
		}

		for (int i = 0; i < 8; i++) {  /*逐个检查所有返回值，若发现返回值不为零，则将该值设为返回值并结束检查*/
			if (ret[i] == FAILURE) {
				RET = ret[i];
				break;
			}
		}
	}

	return RET;
}

/***************************************************************************
  函数名称：failure
  功    能：播放游戏失败效果动画
  输入参数：const matrix MATRIX[]：整个游戏的内部结构体数组（只读）
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int coord：失败时点击位置对应的一维坐标（只读）
  返 回 值：无
  说    明：动画内容为各个雷所在的色块逐个闪烁
***************************************************************************/
void failure(const matrix MATRIX[], const int line, const int row, const int coord)
{
	block_blink(row, coord, COLOR_RED, COLOR_HRED, COLOR_BLACK);  /*踩中地雷位置闪烁红色色块*/

	for (int i = 0; i < line * row; i++) {
		if (MATRIX[i].num == '*' && i != coord)  /*除红色色块外，其他有雷的位置闪烁亮黄色色块*/
			block_blink(row, i, COLOR_YELLOW, COLOR_HYELLOW, COLOR_BLACK);
	}
}

/***************************************************************************
  函数名称：failure
  功    能：播放游戏胜利效果动画
  输入参数：const matrix MATRIX[]：整个游戏的内部结构体数组（只读）
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
  返 回 值：无
  说    明：动画内容为各个雷所在的色块逐个变色
***************************************************************************/
void victory(const matrix MATRIX[], const int line, const int row)
{
	update_bomb_num(row, 0);  /*更新剩余地雷数为0*/

	for (int i = 0; i < line * row; i++) {
		if (MATRIX[i].num == '*') {
			const int J = i % row;        /*将一维坐标转换为列标*/
			const int I = (i - J) / row;  /*将一维坐标转换为行标*/

			cct_gotoxy(6 * J + 2, 3 * I + 12);
			block_print('√', COLOR_GREEN, COLOR_BLACK);  /*所有有雷的位置显示为中间有√的绿色色块*/
			Sleep(10);  /*延时10，控制速度*/
		}
	}
}

/***************************************************************************
  函数名称：flag
  功    能：进行关于用旗子标记的操作
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			int* bomb_num：剩余雷数
			const int flag_mode：操作模式（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void flag(matrix MATRIX[], const int line, const int row, const int coord, int* bomb_num, const int flag_mode)
{
	const int J = coord % row;        /*将一维坐标转换为列标*/
	const int I = (coord - J) / row;  /*将一维坐标转换为行标*/

	switch (flag_mode) {
	case PLACE_FLAG:  /*插旗*/
		(*bomb_num)--;
		update_bomb_num(row, *bomb_num);
		cct_gotoxy(6 * J + 2, 3 * I + 12);
		block_print('F' - '0', COLOR_HBLACK, COLOR_HWHITE);
		MATRIX[coord].if_flag = true;
		break;
	case REMOVE_FLAG:  /*移除旗子*/
		(*bomb_num)++;
		update_bomb_num(row, *bomb_num);
		cct_gotoxy(6 * J + 2, 3 * I + 12);
		block_print(NUM_SPACE, COLOR_HBLACK, COLOR_HWHITE);
		MATRIX[coord].if_flag = false;
		break;
	}
}

/***************************************************************************
  函数名称：control
  功    能：用键鼠进行游戏操作
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int bomb_num：地雷数目（只读）
			bool* if_initialized：内部结构体数组是否初始化
  返 回 值：int：操作结果
  说    明：本函数保证第一次点击后才进行内部数组初始化，使得第一次点击不会点到雷
***************************************************************************/
int control(matrix MATRIX[], const int line, const int row, const int BOMB_NUM, bool* if_initialized)
{
	int X = 0, Y = 0;  /*横纵坐标，初始均为零*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0, RESULT = 0;  /*函数的返回值、对话框操作函数的返回值*/
	int bomb_num = BOMB_NUM;     /*剩余地雷数，先置为总地雷数*/
	bool if_ai = false;          /*是否进行了自动操作的标志*/

	cct_enable_mouse();  /*启用鼠标*/

	LARGE_INTEGER tick, begin{}, end;  /*计时用的结构体*/

	QueryPerformanceFrequency(&tick);  /*获得计数器频率*/

	while (loop) {
		if (if_end(MATRIX, line, row)) {  /*判断游戏是否结束*/
			victory(MATRIX, line, row);
			result = VICTORY;
			break;
		}

		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*读鼠标/键盘*/

		if (if_ai)  /*若进行了自动操作，用时显示为不可用*/
			cct_showstr(TIME_COORD_X + 2, TIME_COORD_Y + 2, "    不可用", TIME_BG_COLOR, TIME_FG_COLOR);

		else if (*if_initialized) {  /*若内部数组已初始化，则计时并显示用时*/
			QueryPerformanceCounter(&end);
			update_time(row, tick, begin, end);
		}

		int RET[4];  /*各种函数的返回值*/
		RET[0] = if_block(MATRIX, X, Y, line, row);  /*判断此时鼠标的位置是否在某个色块中*/
		RET[1] = if_new_button(X, Y, row);           /*判断此时鼠标的位置是否在新游戏键上*/
		RET[2] = 0;                    /*翻开操作函数的返回值，先设为0*/
		const int J = RET[0] % row;        /*将一维坐标转换为列标*/
		const int I = (RET[0] - J) / row;  /*将一维坐标转换为行标*/
		selective_default(MATRIX, line, row, RET[0]);         /*取消前一个高亮色块的高亮*/
		selective_activate(MATRIX, line, row, RET[0], X, Y);  /*设置当前位置上色块的高亮*/

		/*新游戏键的显示效果*/
		if (RET[1])
			new_button_activate(row);
		else
			new_button_default(row);

		/*1、若返回的是鼠标事件，同时鼠标在某一色块上*/
		if (ret == CCT_MOUSE_EVENT && RET[0] != INT_MAX) {
			switch (maction) {
			/*单击左键*/
			case MOUSE_LEFT_BUTTON_CLICK:
				MATRIX[RET[0]].mark = true;  /*当前色块设置一般标记，方便后续翻开操作时的检查*/

				switch (*if_initialized) {
				case true:
					RET[2] = turn(MATRIX, line, row, RET[0]);  /*若内部数组已初始化，则进行翻开操作*/
					break;
				case false:
					matrix_initialize(MATRIX, line, row, BOMB_NUM, J, I);  /*若内部数组未初始化，则取第一次点击位置并进行初始化*/
					*if_initialized = true;  /*是否初始化标记记为真*/

					QueryPerformanceCounter(&begin);  /*获得初始硬件计数器计数*/

					RET[2] = turn(MATRIX, line, row, RET[0]);  /*对第一次点击位置的元素进行翻开操作*/
					break;
				}

				if (RET[2])  /*若本次翻开不为正常翻开，则设置返回值后结束循环*/
					result = RET[2], loop = 0;
				break;
			/*单击右键*/
			case MOUSE_RIGHT_BUTTON_CLICK:
				if (!MATRIX[RET[0]].if_turned) {   /*只有在当前色块对应元素未被翻开时才进行操作*/
					switch (MATRIX[RET[0]].if_flag) {
					case true:
						flag(MATRIX, line, row, RET[0], &bomb_num, REMOVE_FLAG);  /*插旗操作*/
						break;
					case false:
						flag(MATRIX, line, row, RET[0], &bomb_num, PLACE_FLAG);   /*移除旗子操作*/
						break;
					}
				}

				break;
			/*单击滚轮*/
			case MOUSE_WHEEL_CLICK:
				MATRIX[RET[0]].mark = true;  /*当前色块设置一般标记，方便后续翻开操作时的检查*/
				RET[2] = wheel_click_turn(MATRIX, line, row, RET[0]);  /*滚轮式翻开操作*/

				if (RET[2])  /*若本次翻开不为正常翻开，则设置返回值后结束循环*/
					result = FAILURE, loop = 0;
				break;
			}
		}

		/*1、若鼠标单击左键，同时鼠标在新游戏键上*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK && RET[1] != 0)
			result = NEW, loop = 0;

		if (ret == CCT_KEYBOARD_EVENT) {
			switch (keycode1) {
			case 'A':
			case 'a':
				RET[2] = ai_control(MATRIX, line, row, &bomb_num, if_initialized);  /*进行自动操作*/
				if_ai = true;  /*是否进行自动操作标志置为真*/

				if (RET[2])  /*若本次翻开不为正常翻开，则设置返回值后结束循环*/
					result = FAILURE, loop = 0;
				break;
			case 'Q':
			case 'q':
				GAME_MAILBOX.print(BUTTON_TWO, line, row, "您是否要退出游戏？");  /*弹出对话框询问是否退出游戏*/
				RET[3] = GAME_MAILBOX.control(line, row);  /*用返回值读取对话框操作*/

				switch (RET[3]) {
				case GMMB_RET_YES:
					result = QUIT, loop = 0;  /*若按“是”，则函数返回QUIT，表示退出状态*/
					break;
				case GMMB_RET_NO:
					GAME_MAILBOX.erase(MATRIX, line, row);  /*若按“否”，则启用鼠标并继续循环*/
					cct_enable_mouse();
					break;
				}
				break;
			}
		}
	}

	cct_disable_mouse();	//禁用鼠标
	return result;
}