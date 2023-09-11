#include"90-b3.h"

/***************************************************************************
  函数名称：pause
  功    能：设置一个程序的间断点
  输入参数：无
  返 回 值：无
  说    明：输入回车才继续，其他字符无回显
***************************************************************************/
void pause()
{
	char c;
	while (1) {
		c = _getch();
		if (c == '\r')
			break;
	}
}

/***************************************************************************
  函数名称：print_base
  功    能：图形化输出初始背景，调整窗口大小
  输入参数：无
  返 回 值：无
  说    明：本函数中一开始取当前光标的坐标，无需接收实参传值
***************************************************************************/
void console_print_base()
{
	const int LENGTH = __GAME.order * 8 + 26;  /*根据列数取长度*/
	const int WIDTH = __GAME.order * 4 + 20;   /*根据行数取宽度*/

	cct_setconsoleborder(LENGTH, WIDTH);  /*根据取得的长度及宽度，动态设置窗口大小*/
	__GAME.gameboard.print_background();  /*打印最底层背景*/
	__GAME.gameboard.print_chessboard();  /*打印白色背景*/

	cout << endl;  /*输出完成后调整光标位置*/
}

/***************************************************************************
  函数名称：color_number
  功    能：根据数组元素值，转换为对应的颜色编号
  输入参数：int initial_num：元素实际值/转换初始值
  返 回 值：int：对应颜色编号
  说    明：本函数根据元素实际值为2的几次方返回颜色编号
***************************************************************************/
int color_number(int initial_num)
{
	int order = 0;  /*元素值阶数，初始为零*/

	/*每次元素值除以2，order自增，直到值变为1，最终得到阶数*/
	while (initial_num != 1) {
		initial_num = initial_num / 2;
		order++;
	}

	return order;
}

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
  函数名称：print_keyboard_button
  功    能：打印一个小键盘按键，即包含着箭头的有颜色的方块
  输入参数：const int print_mode：打印模式（只读）
			const int bg_color：方块背景色（只读）
			const int fg_color：方块前景色（只读）
  返 回 值：无
  说    明：本函数以光标当前位置为方块的左上角
***************************************************************************/
void print_keyboard_button(const int print_mode, const int bg_color, const int fg_color)
{
	int X, Y;         /*横纵坐标*/
	cct_getxy(X, Y);  /*取光标当前坐标*/

	/*1、打印上边界*/
	cct_showstr(X, Y, "┏━┓", bg_color, fg_color);

	/*2、打印左边界*/
	cct_showstr(X, Y + 1, "┃", bg_color, fg_color);

	/*3、打印中间*/
	switch (print_mode) {
	case BLOCK_ARROW_MODE_UP:
		cct_showstr(X + 2, Y + 1, "↑", bg_color, fg_color);  /*输出上箭头*/
		break;
	case BLOCK_ARROW_MODE_DOWN:
		cct_showstr(X + 2, Y + 1, "↓", bg_color, fg_color);  /*输出下箭头*/
		break;
	case BLOCK_ARROW_MODE_LEFT:
		cct_showstr(X + 2, Y + 1, "←", bg_color, fg_color);  /*输出左箭头*/
		break;
	case BLOCK_ARROW_MODE_RIGHT:
		cct_showstr(X + 2, Y + 1, "→", bg_color, fg_color);  /*输出右箭头*/
		break;
	}

	/*4、打印右边界*/
	cct_showstr(X + 4, Y + 1, "┃", bg_color, fg_color);

	/*5、打印下边界*/
	cct_showstr(X, Y + 2, "┗━┛", bg_color, fg_color);

	cct_setcolor();  /*重置颜色*/
}

/***************************************************************************
  函数名称：print_switch_button
  功    能：打印一个开关上的按键
  输入参数：const int bg_color：按键背景色（只读）
			const int fg_color：按键前景色（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void print_switch_button(const int bg_color, const int fg_color)
{
	int X, Y;         /*横纵坐标*/
	cct_getxy(X, Y);  /*取光标当前坐标*/

	cct_showch(X, Y, ' ', bg_color, fg_color);
	cct_showch(X, Y + 1, ' ', bg_color, fg_color);
}

/***************************************************************************
  函数名称：power
  功    能：求一个数的n次方
  输入参数：const int base_number：底数（只读）
            const int exponent：指数（只读）
  返 回 值：int：该数的n次方
  说    明：无
***************************************************************************/
int power(const int base_number, const int exponent)
{
	int ret = 1;

	if (exponent) {
		for (int i = 0; i < exponent; i++)
			ret = ret * base_number;
	}

	return ret;
}