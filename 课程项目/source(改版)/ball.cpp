#include"colorball.h"
#include"ball.h"

/*静态成员进行初始化，全部置为假*/
bool ball::if_ball[81] = { false };

/***************************************************************************
  函数名称：print
  功    能：打印珠子
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void ball::print()
{
	const int X = x * 10 + 2;  /*根据列数取打印区域的横坐标*/
	const int Y = y * 5 + 1;   /*根据行数取打印区域的纵坐标*/

	for (int i = 0; i < 4; i++) {
		switch (if_ball[9 * y + x]) {  /*根据标志判断当前位置是否要打印珠子*/
		case true:
			cct_showstr(X, Y + i, "        ", color);  /*若当前位置有珠子，则打印色块*/
			break;
		case false:
			cct_showstr(X, Y + i, "        ", COLOR_WHITE);  /*若当前位置无珠子，则打印空白区域*/
			break;
		}
	}

	if (if_ball[9 * y + x])
		cct_showstr(X + 2, Y + 1, "  ", COLOR_WHITE);  /*若当前位置有珠子，打印珠子高亮部分*/
	cct_setcolor();  /*重设颜色*/
}

/***************************************************************************
  函数名称：set
  功    能：设置珠子的位置和颜色
  输入参数：const int COORD_X：设置的列数（只读）
            const int COORD_Y：设置的行数（只读）
			const int COLOR：设置的颜色（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void ball::set(const int COORD_X, const int COORD_Y, const int COLOR)
{
	x = COORD_X;
	y = COORD_Y;
	color = COLOR;
}