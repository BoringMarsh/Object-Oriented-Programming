#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<string>
#include"player.h"
#include"colorball.h"
#include"ball.h"
#include"interface-messagebox.h"

/*静态成员进行初始化*/
bool player::if_blink = true;
bool player::if_show = true;

/***************************************************************************
  函数名称：matrix_clear
  功    能：清空内部数组
  输入参数：ball b[]：游戏内部的对象数组
  返 回 值：无
  说    明：无
***************************************************************************/
void player::matrix_clear(ball b[])
{
	ball clear;  /*使用默认构造函数定义一个clear对象*/

	for (int i = 0; i < 81; i++) {
		b[i] = clear;  /*将clear对象赋给当前位置上的对象*/
		ball::if_ball[i] = false;  /*将当前位置上的标记置为假*/
	}

	score = 0;  /*得分归零*/
	if_select = false;  /*选定状态置为假*/
	select_x = -1;  /*选定位置列数置为-1*/
	select_y = -1;  /*选定位置行数置为-1*/
}

/***************************************************************************
  函数名称：read_score
  功    能：读取得分并转换成字符串
  输入参数：char* s：存放结果的字符数组
  返 回 值：char*：字符串形式的读取结果
  说    明：1、本函数在读取各个位数完成后，将多余的零转换为空格
			2、手动添加了尾零
***************************************************************************/
char* player::read_score(char* s)
{
	if (score) {  /*若分数不为零，则正常读取*/
		int i;
		int S = score;

		for (i = 0; i < 10; i++) {  /*读各个位数*/
			s[9 - i] = S % 10;
			S = (S - S % 10) / 10;
		}

		i = 0;
		bool if_score_char = false;

		while (i < 10) {
			if (s[i])
				if_score_char = true;  /*遇到第一位不为零的数，设置为真*/

			if (if_score_char)
				s[i] = s[i] + '0';  /*当设置为真后，每一位数转换为对应数字的字符*/
			else
				s[i] = ' ';  /*未设置为真时，每一位数转换为空格*/
			i++;
		}
	}

	else {  /*若分数为零，则字符串最后一位为'0'，其余为空格*/
		for (int i = 0; i < 9; i++)
			s[i] = ' ';
		s[9] = '0';
	}

	s[10] = '\0';  /*添加尾零*/
	return s;
}

/***************************************************************************
  函数名称：read_color
  功    能：读取下次出现的颜色并转换成字符串
  输入参数：char* c：存放结果的字符数组
  返 回 值：char*：字符串形式的读取结果
  说    明：手动添加了尾零
***************************************************************************/
char* player::read_color(char* c)
{
	int i;

	for (i = 0; i < 4; i++)  /*头4个字符设为空格，并随后添加'\0'，方便之后进行字符串连接*/
		c[i] = ' ';
	c[4] = '\0';

	for (i = 0; i < 3; i++) {  /*读取颜色。每次将颜色转换为字符串后连接到原字符串上*/
		char color[3];
		strcat(c, color_trans_string(next_color[i], color));
	}

	c[10] = '\0';  /*添加尾零*/
	return c;
}

/***************************************************************************
  函数名称：update_score
  功    能：更新得分
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void player::update_score()
{
	char s[11];
	cct_showstr(SCORE_COORD_X + 2, SCORE_COORD_Y + 2, read_score(s), COLOR_CYAN, COLOR_HWHITE);
}

/***************************************************************************
  函数名称：update_color
  功    能：更新颜色
  输入参数：无
  返 回 值：无
  说    明：由于要使用不同的颜色输出，故无法一次性将整个字符串输出
***************************************************************************/
void player::update_color()
{
	char color[11];

	for (int i = 0; i < 4; i++)  /*输出空格*/
		cct_showch(COLOR_COORD_X + 2, COLOR_COORD_Y + 2, read_color(color)[i]);

	for (int i = 0; i < 3; i++) {  /*用对应颜色输出字符串*/
		cct_showch(COLOR_COORD_X + 2 * (i + 3), COLOR_COORD_Y + 2, read_color(color)[4 + 2 * i], COLOR_BLACK, next_color[i]);
		cct_showch(COLOR_COORD_X + 2 * (i + 3), COLOR_COORD_Y + 2, read_color(color)[5 + 2 * i], COLOR_BLACK, next_color[i]);
	}
}

/***************************************************************************
  函数名称：update_state
  功    能：更新状态
  输入参数：const char* state：状态（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void player::update_state(const char* state)
{
	cct_showstr(STATE_COORD_X + 2, STATE_COORD_Y + 2, state, COLOR_HRED, COLOR_HWHITE);
}

/***************************************************************************
  函数名称：blink_blockborder
  功    能：使一个格子的边界闪烁
  输入参数：const int coord：格子的一维坐标（只读）
            const int blink_times：闪烁次数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void player::blink_blockborder(const int coord, const int blink_times)
{
	const int X = coord % 9;        /*将一维坐标转换为列数*/
	const int Y = (coord - X) / 9;  /*将一维坐标转换为行数*/

	for (int i = 0; i < blink_times; i++) {
		cct_gotoxy(10 * X, 5 * Y);
		print_blockborder(9 * Y + X, COLOR_HBLACK, COLOR_WHITE);
		Sleep(10);

		cct_gotoxy(10 * X, 5 * Y);
		print_blockborder(9 * Y + X, COLOR_WHITE, COLOR_BLACK);
		Sleep(10);
	}
}

/***************************************************************************
  函数名称：summon
  功    能：随机生成若干个珠子
  输入参数：ball b[]：游戏内部的对象数组
			const int summon_times：生成个数（只读）
			bool* if_sound：是否有声音
  返 回 值：无
  说    明：本函数在生成的同时还随机生成了下一次出现的颜色
***************************************************************************/
void player::summon(ball b[], const int summon_times, bool* if_sound)
{
	for (int i = 0; i < summon_times; i++) {
		int COLOR = 0;  /*生成的颜色*/
		if (summon_times == 7)  /*若生成7个，则说明游戏刚开始，直接取随机生成的颜色*/
			COLOR = num_trans_color(rand() % 6);
		int X, Y;  /*行数、列数*/

		if (if_end(b))  /*若棋盘已满，则跳出循环，停止生成珠子，否则会进入死循环*/
			break;

		while (1) {
			X = rand() % 9;  /*随机取列数*/
			Y = rand() % 9;  /*随机取行数*/
			const int coord = Y * 9 + X;  /*将行数、列数转换为一维坐标*/

			if (ball::if_ball[coord])  /*若随机选中的位置已有珠子，则重新选择坐标*/
				continue;
			else {  /*若随机选中的位置已有珠子，则在此生成珠子*/
				if (summon_times != 7)  /*若生成数量不为7，则说明生成3个，将下一次出现的颜色赋给COLOR*/
					COLOR = next_color[i];
				b[coord].set(X, Y, COLOR);  /*设定珠子的位置和颜色*/
				ball::if_ball[Y * 9 + X] = true;  /*当前位置的标志设为真*/

				if (*if_sound)  /*根据需要播放声音*/
					Beep(SOUND_LLA, 100);

				b[coord].print();  /*打印该珠子*/

				if (if_blink)  /*根据需要进行闪烁*/
					blink_blockborder(coord, 10);

				Sleep(100);  /*延时，控制速度*/
				break;
			}
		}//end of while(1)
	}//end of for (int i = 0...

	for (int i = 0; i < 3; i++) {  /*随机生成3个下一次出现的颜色，并赋给next_color*/
		const int COLOR = num_trans_color(rand() % 6);
		next_color[i] = COLOR;
	}
}

/***************************************************************************
  函数名称：move
  功    能：移动珠子
  输入参数：ball b[]：游戏内部的对象数组
            const int src_x：珠子起点列数（只读）
			const int src_y：珠子起点行数（只读）
			const int dst_x：珠子终点列数（只读）
			const int dst_y：珠子终点行数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void player::move(ball b[], const int src_x, const int src_y, const int dst_x, const int dst_y)
{
	const int src = 9 * src_y + src_x;  /*将起点列数、行数转换为一维坐标*/
	const int dst = 9 * dst_y + dst_x;  /*将终点列数、行数转换为一维坐标*/

	/*若起点位置有珠子、终点位置无珠子，则进行移动操作*/
	if (ball::if_ball[src] && !ball::if_ball[dst]) {
		b[dst].set(dst_x, dst_y, b[src].color);  /*设置终点位置珠子的坐标和颜色*/
		ball::if_ball[dst] = true;  /*终点位置的标志设为真*/

		b[src].color = COLOR_WHITE;  /*起点位置珠子的颜色设为白色*/
		ball::if_ball[src] = false;  /*起点位置的标志设为假*/

		b[src].print();  /*打印起点位置的珠子（已设为假，打印空白）*/
		b[dst].print();  /*打印终点位置的珠子*/

		b[src].x = -1;  /*设置起点位置珠子的列数（已移走，设为-1）*/
		b[src].y = -1;  /*设置起点位置珠子的行数（已移走，设为-1）*/
	}
}

/***************************************************************************
  函数名称：scan
  功    能：扫描可消除的珠子
  输入参数：ball b[]：游戏内部的对象数组
  返 回 值：无
  说    明：本函数一次性扫描了四个方向上可消除的珠子
***************************************************************************/
void player::scan(ball b[])
{
	ball* p[2];  /*两个指向内部数组的指针*/
	int count;   /*相邻且同色珠子计数器*/

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			const int coord = 9 * i + j;  /*将行数、列数转换为一维坐标*/

			/*若当前位置上珠子不是白色（即该位置上有珠子），且右侧珠子颜色也是相同颜色，则进行下一步判断*/
			if (b[coord].color == b[coord + 1].color && b[coord].color != COLOR_WHITE) {
				p[0] = &b[coord + 1];  /*p[0]指向右侧珠子*/
				p[1] = &b[(i + 1) * 9 - 1];  /*p[1]指向当前行最后一个珠子*/
				count = 1;  /*计数器置为1*/

				/*若p[0]指向的珠子颜色仍然一致，且p[0]位置不在p[1]之后（即没有超出当前行），则计数器自增、p[0]向前移动*/
				while (p[0]->color == b[coord].color && p[0] <= p[1]) {
					count++;
					p[0]++;
				}

				/*若扫描完成，计数器不小于5，则将符合消除条件的多个珠子做上标记*/
				if (count >= 5) {
					for (int k = 0; k < count; k++)
						b[coord + k].mark = true;
					j = j + count;  /*j增加count，减少循环次数*/
				}
			}

			count = 0;  /*每次扫描完成后计数器重置为零*/
		}
	}

	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			const int coord = 9 * i + j;  /*将行数、列数转换为一维坐标*/

			/*若当前位置上珠子不是白色（即该位置上有珠子），且下方珠子颜色也是相同颜色，则进行下一步判断*/
			if (b[coord].color == b[coord + 9].color && b[coord].color != COLOR_WHITE) {
				p[0] = &b[coord + 9];  /*p[0]指向下方珠子*/
				p[1] = &b[72 + j];  /*p[1]指向当前列最后一个珠子*/
				count = 1;  /*计数器置为1*/

				/*若p[0]指向的珠子颜色仍然一致，且p[0]位置不在p[1]之后（即没有超出当前列），则计数器自增、p[0]向前移动*/
				while (p[0]->color == b[coord].color && p[0] <= p[1]) {
					count++;
					p[0] = p[0] + 9;
				}

				/*若扫描完成，计数器不小于5，则将符合消除条件的多个珠子做上标记*/
				if (count >= 5) {
					for (int k = 0; k < count; k++)
						b[coord + k * 9].mark = true;
					i = i + count;  /*i增加count，减少循环次数*/
				}
			}

			count = 0;  /*每次扫描完成后计数器重置为零*/
		}
	}

	for (int i = 0; i < 9; i++) {
		const int j_lim = (i <= 4) ? (5 + i) : (13 - i);  /*根据行数取每一斜行的珠子个数*/

		for (int j = 0; j < j_lim; j++) {
			const int coord = (i <= 4) ? ((4 - i) + j * 10) : ((i - 4) * 9 + j * 10);  /*根据行数取一维坐标*/

			/*若当前位置上珠子不是白色（即该位置上有珠子），且右下方珠子颜色也是相同颜色，则进行下一步判断*/
			if (b[coord].color == b[coord + 10].color && b[coord].color != COLOR_WHITE) {
				p[0] = &b[coord + 10];  /*p[0]指向右下方珠子*/
				p[1] = &b[(i <= 4) ? ((5 + i) * 9 - 1) : (84 - i)];  /*p[1]指向当前斜行最后一个珠子*/
				count = 1;  /*计数器置为1*/

				/*若p[0]指向的珠子颜色仍然一致，且p[0]位置不在p[1]之后（即没有超出当前斜行），则计数器自增、p[0]向前移动*/
				while (p[0]->color == b[coord].color && p[0] <= p[1]) {
					count++;
					p[0] = p[0] + 10;
				}

				/*若扫描完成，计数器不小于5，则将符合消除条件的多个珠子做上标记*/
				if (count >= 5) {
					for (int k = 0; k < count; k++)
						b[coord + k * 10].mark = true;
					j = j + count;  /*j增加count，减少循环次数*/
				}
			}

			count = 0;  /*每次扫描完成后计数器重置为零*/
		}
	}

	for (int i = 0; i < 9; i++) {
		const int j_lim = (i <= 4) ? (5 + i) : (13 - i);  /*根据行数取每一斜行的珠子个数*/

		for (int j = 0; j < j_lim; j++) {
			const int coord = (i <= 4) ? ((4 + i) + j * 8) : ((i - 3) * 9 - 1 + j * 8);  /*根据行数取一维坐标*/

			/*若当前位置上珠子不是白色（即该位置上有珠子），且左下方珠子颜色也是相同颜色，则进行下一步判断*/
			if (b[coord].color == b[coord + 8].color && b[coord].color != COLOR_WHITE) {
				p[0] = &b[coord + 8];  /*p[0]指向左下方珠子*/
				p[1] = &b[(i <= 4) ? ((i + 4) * 9) : (68 + i)];  /*p[1]指向当前斜行最后一个珠子*/
				count = 1;  /*计数器置为1*/

				/*若p[0]指向的珠子颜色仍然一致，且p[0]位置不在p[1]之后（即没有超出当前斜行），则计数器自增、p[0]向前移动*/
				while (p[0]->color == b[coord].color && p[0] <= p[1]) {
					count++;
					p[0] = p[0] + 8;
				}

				/*若扫描完成，计数器不小于5，则将符合消除条件的多个珠子做上标记*/
				if (count >= 5) {
					for (int k = 0; k < count; k++)
						b[coord + k * 8].mark = true;
					j = j + count;  /*j增加count，减少循环次数*/
				}
			}

			count = 0;  /*每次扫描完成后计数器重置为零*/
		}
	}
}

/***************************************************************************
  函数名称：get_mark_num
  功    能：取被标记的珠子个数
  输入参数：const ball b[]：游戏内部的对象数组（只读）
  返 回 值：int：被标记的珠子个数
  说    明：无
***************************************************************************/
int player::get_mark_num(const ball b[])
{
	int ret = 0;  /*返回值*/

	for (int i = 0; i < 81; i++) {
		if (b[i].mark)
			ret++;
	}

	return ret;
}

/***************************************************************************
  函数名称：if_end
  功    能：判断游戏是否结束
  输入参数：const ball b[]：游戏内部的对象数组（只读）
  返 回 值：bool：游戏是否结束
  说    明：本函数仅仅根据棋盘是否被占满来判断，占满后能否消除以及其余操作已交由其它函数实现
***************************************************************************/
bool player::if_end(const ball b[])
{
	int count = 0;  /*计数器*/

	for (int i = 0; i < 81; i++) {
		if (ball::if_ball[i])  /*若当前位置有珠子，则计数器自增*/
			count++;
	}

	if (count == 81)  /*计数器够81，返回真；否则返回假*/
		return true;
	else
		return false;
}

/***************************************************************************
  函数名称：clear
  功    能：消除珠子
  输入参数：ball b[]：游戏内部的对象数组
            bool* if_sound：是否有声音
  返 回 值：无
  说    明：本函数在消除珠子的同时进行分数的累加
***************************************************************************/
void player::clear(ball b[], bool* if_sound)
{
	int count = 0;  /*本次消除珠子个数*/

	if (*if_sound)  /*根据需要播放声音*/
		Beep(SOUND_HDO, 200);

	for (int i = 0; i < 81; i++) {
		if (b[i].mark && if_show) {  /*若有清除效果，则在被标记的珠子位置打印格子边界*/
			const int J = i % 9;
			const int I = (i - J) / 9;
			cct_gotoxy(10 * J, 5 * I);
			print_blockborder(i, COLOR_HBLACK, COLOR_WHITE);
			Sleep(10);  /*延时，控制速度*/
		}
	}

	Sleep(500);  /*延时，控制速度*/

	for (int i = 0; i < 81; i++) {
		if (b[i].mark) {
			ball::if_ball[i] = false;  /*当前位置的标志设为真*/

			const int J = i % 9;        /*将一维坐标转换为列数*/
			const int I = (i - J) / 9;  /*将一维坐标转换为行数*/
			cct_gotoxy(10 * J, 5 * I);
			print_blockborder(i, COLOR_WHITE, COLOR_BLACK);  /*将原有格子边界消除*/

			b[i].color = COLOR_WHITE;  /*当前位置上珠子颜色设为白色*/
			b[i].print();  /*在当前位置上打印白色区域，营造清除效果*/

			b[i].x = -1;  /*当前位置上珠子被消除，列数设为-1*/
			b[i].y = -1;  /*当前位置上珠子被消除，行数设为-1*/
			count++;
			b[i].mark = false;  /*将标记去掉*/
			Sleep(10);  /*延时，控制速度*/
		}
	}

	score = score + count * 2;  /*根据消除的珠子个数计分*/
}

/***************************************************************************
  函数名称：if_block
  功    能：判断鼠标位置是否在某一格子上
  输入参数：ball b[]：游戏内部的对象数组
            const int X：鼠标位置横坐标（只读）
			const int Y：鼠标位置纵坐标（只读）
  返 回 值：int：鼠标在哪一格子上
  说    明：无
***************************************************************************/
int player::if_block(ball b[], const int X, const int Y)
{
	int ret = -1;  /*返回值，先置为-1*/
	int loop = 1;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (X >= j * 10 + 2 && X <= j * 10 + 9 && Y >= i * 5 + 1 && Y <= i * 5 + 4) {
				ret = 9 * i + j;
				b[ret].spmark = true;  /*将该位置上的对象做上特别标记，方便后续消除格子边界*/
				loop = 0;  /*循环标记置为假*/
				break;
			}
		}

		if (!loop)  /*若确定了位置，则循环结束，减少循环次数*/
			break;
	}

	return ret;
}

/***************************************************************************
  函数名称：print_blockborder
  功    能：打印一个格子的边界
  输入参数：const int coord：格子的一维坐标（只读）
			const int bg_color：背景色（只读）
			const int fg_color：前景色（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void player::print_blockborder(const int coord, const int bg_color, const int fg_color)
{
	const int J = coord % 9;        /*将一维坐标转换为列数*/
	const int I = (coord - J) / 9;  /*将一维坐标转换为行数*/
	int X, Y;
	cct_getxy(X, Y);  /*取当前光标的横纵坐标*/

	/*根据位置打印每个格子边界的左上角制表符*/
	if (I == 0 && J == 0)
		cct_showstr(X, Y, "┏", bg_color, fg_color);  /*左上角格子*/
	else if (I == 0 && J != 0)
		cct_showstr(X, Y, "┳", bg_color, fg_color);  /*除左上角外，第一行的格子*/
	else if (I != 0 && J == 0)
		cct_showstr(X, Y, "┣", bg_color, fg_color);  /*除左上角外，第一列的格子*/
	else
		cct_showstr(X, Y, "╋", bg_color, fg_color);  /*除以上外的其他格子*/

	/*根据位置打印每个格子边界的右上角制表符*/
	if (I == 0 && J == 8)
		cct_showstr(X + 10, Y, "┓", bg_color, fg_color);  /*右上角格子*/
	else if (I == 0 && J != 8)
		cct_showstr(X + 10, Y, "┳", bg_color, fg_color);  /*除右上角外，第一行的格子*/
	else if (I != 0 && J == 8)
		cct_showstr(X + 10, Y, "┫", bg_color, fg_color);  /*除右上角外，最后一列的格子*/
	else
		cct_showstr(X + 10, Y, "╋", bg_color, fg_color);  /*除以上外的其他格子*/

	/*根据位置打印每个格子边界的左下角制表符*/
	if (I == 8 && J == 0)
		cct_showstr(X, Y + 5, "┗", bg_color, fg_color);  /*左下角格子*/
	else if (I == 8 && J != 0)
		cct_showstr(X, Y + 5, "┻", bg_color, fg_color);  /*除左下角外，最后一行的格子*/
	else if (I != 8 && J == 0)
		cct_showstr(X, Y + 5, "┣", bg_color, fg_color);  /*除左下角外，第一列的格子*/
	else
		cct_showstr(X, Y + 5, "╋", bg_color, fg_color);  /*除以上外的其他格子*/

	/*根据位置打印每个格子边界的右下角制表符*/
	if (I == 8 && J == 8)
		cct_showstr(X + 10, Y + 5, "┛", bg_color, fg_color);  /*右下角格子*/
	else if (I == 8 && J != 8)
		cct_showstr(X + 10, Y + 5, "┻", bg_color, fg_color);  /*除右下角外，最后一行的格子*/
	else if (I != 8 && J == 8)
		cct_showstr(X + 10, Y + 5, "┫", bg_color, fg_color);  /*除右下角外，最后一列的格子*/
	else
		cct_showstr(X + 10, Y + 5, "╋", bg_color, fg_color);  /*除以上外的其他格子*/

	/*打印每个格子边界的其他制表符*/
	for (int i = 0; i < 4; i++) {
		cct_showstr(X + 2 * (i + 1), Y, "━", bg_color, fg_color);
		cct_showstr(X + 2 * (i + 1), Y + 5, "━", bg_color, fg_color);
		cct_showstr(X, Y + i + 1, "┃", bg_color, fg_color);
		cct_showstr(X + 10, Y + i + 1, "┃", bg_color, fg_color);
	}
}

/***************************************************************************
  函数名称：print_balls
  功    能：打印当前的所有珠子
  输入参数：ball b[]：游戏内部的对象数组
  返 回 值：无
  说    明：无
***************************************************************************/
void player::print_balls(ball b[])
{
	for (int i = 0; i < 81; i++) {
		if (ball::if_ball[i])  /*若当前位置有珠子，则打印*/
			b[i].print();
		else {  /*若当前位置无珠子，则打印空白区域*/
			const int J = i % 9;        /*将一维坐标转换为列数*/
			const int I = (i - J) / 9;  /*将一维坐标转换为行数*/
			const int X = J * 10 + 2;   /*取打印区域左上角横坐标*/
			const int Y = I * 5 + 1;    /*取打印区域左上角纵坐标*/

			for (int j = 0; j < 4; j++)
				cct_showstr(X, Y + j, "        ", COLOR_WHITE);
		}
	}
}

/***************************************************************************
  函数名称：blocks_selective_default
  功    能：选择性地消除某一格子的边界
  输入参数：ball b[]：游戏内部的对象数组
            const int coord：鼠标当前所在格子的一维坐标（只读）
			const int bg_color：背景色（只读）
			const int fg_color：前景色（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void player::blocks_selective_default(ball b[], const int coord, const int bg_color, const int fg_color)
{
	for (int i = 0; i < 81; i++) {
		const int J = i % 9;        /*将一维坐标转换为列数*/
		const int I = (i - J) / 9;  /*将一维坐标转换为行数*/

		/*若当前元素被坐标标记，且不是上一个设置高亮色块对应元素，则进行操作*/
		if (b[i].spmark && i != coord) {
			cct_gotoxy(10 * J, 5 * I);
			print_blockborder(i, bg_color, fg_color);
			b[i].spmark = false;  /*取消特殊标记*/
		}
	}
}

/***************************************************************************
  函数名称：blocks_selective_default
  功    能：选择性地打印某一格子的边界
  输入参数：ball b[]：游戏内部的对象数组
			const int coord：格子的一维坐标（只读）
			const int bg_color：背景色（只读）
			const int fg_color：前景色（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void player::blocks_selective_activate(ball b[], const int coord, const int bg_color, const int fg_color)
{
	const int J = coord % 9;        /*将一维坐标转换为列数*/
	const int I = (coord - J) / 9;  /*将一维坐标转换为行数*/

	/*若coord不为负（即鼠标在某一个格子内），则执行操作*/
	if (coord >= 0) {
		cct_gotoxy(10 * J, 5 * I);
		print_blockborder(coord, bg_color, fg_color);
	}
}

/***************************************************************************
  函数名称：if_button
  功    能：判断鼠标位置是否在某一按键上
  输入参数：const int X：鼠标位置横坐标（只读）
			const int Y：鼠标位置纵坐标（只读）
  返 回 值：int：鼠标在哪一按键上
  说    明：无
***************************************************************************/
int player::if_button(const int X, const int Y)
{
	int ret = 0;  /*返回值*/
	bool p[BUTTON_NUM];
	for (int i = 0; i < BUTTON_NUM; i++)
		p[i] = false;

	if (X >= OPTIONS_COORD_X && X <= OPTIONS_COORD_X + 9 && Y >= OPTIONS_COORD_Y && Y <= OPTIONS_COORD_Y + 2)  /*判断是否在“设置”键上*/
		p[0] = true;
	if (X >= SAVE_COORD_X && X <= SAVE_COORD_X + 9 && Y >= SAVE_COORD_Y && Y <= SAVE_COORD_Y + 2)              /*判断是否在“保存”键上*/
		p[1] = true;
	if (X >= DELETE_COORD_X && X <= DELETE_COORD_X + 9 && Y >= DELETE_COORD_Y && Y <= DELETE_COORD_Y + 2)      /*判断是否在“删除”键上*/
		p[2] = true;
	if (X >= QUIT_COORD_X && X <= QUIT_COORD_X + 9 && Y >= QUIT_COORD_Y && Y <= QUIT_COORD_Y + 2)              /*判断是否在“退出”键上*/
		p[3] = true;

	/*检查各个位置的情况，遇到真则取对应返回值后结束检查*/
	for (int i = 0; i < BUTTON_NUM; i++) {
		if (p[i]) {
			ret = i + 1;
			break;
		}
	}

	return ret;
}

/***************************************************************************
  函数名称：buttons_selective_default
  功    能：选择性地为某一按键取消高亮
  输入参数：const int selection：按键选择（只读）
  返 回 值：无
  说    明：当选择为DEFAULT_ALL时，通过递归调用取消所有按键的高亮
***************************************************************************/
void player::buttons_selective_default(const int selection)
{
	switch (selection) {
	case 1:
		button_options.act(DEFAULT);  /*“设置”键取消高亮*/
		break;
	case 2:
		button_save.act(DEFAULT);     /*“保存”键取消高亮*/
		break;
	case 3:
		button_delete.act(DEFAULT);   /*“删除”键取消高亮*/
		break;
	case 4:
		button_quit.act(DEFAULT);     /*“退出”键取消高亮*/
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < BUTTON_NUM; i++)  /*所有按键取消高亮*/
			buttons_selective_default(i + 1);
		break;
	}
}

/***************************************************************************
  函数名称：buttons_selective_activate
  功    能：选择性地为某一按键设置高亮
  输入参数：const int selection：按键选择（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void player::buttons_selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		button_options.act(ACTIVATE);  /*“设置”键设置高亮*/
		break;
	case 2:
		button_save.act(ACTIVATE);     /*“保存”键设置高亮*/
		break;
	case 3:
		button_delete.act(ACTIVATE);   /*“删除”键设置高亮*/
		break;
	case 4:
		button_quit.act(ACTIVATE);     /*“退出”键设置高亮*/
		break;
	}
}

/***************************************************************************
  函数名称：control
  功    能：用键鼠在游戏面板内进行操作
  输入参数：ball b[]：游戏内部的对象数组
            bool* if_sound：是否有声音
  返 回 值：int：进行的操作
  说    明：无
***************************************************************************/
int player::control(ball b[], bool* if_sound)
{
	int X = 0, Y = 0;  /*横纵坐标，初始均为零*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*函数的返回值*/

	cct_enable_mouse();  /*启用鼠标*/

	while (loop) {
		if (if_end(b)) {  /*若游戏结束，则取返回值后跳出循环*/
			result = GAME_RET_FAILURE;
			break;
		}

		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*读鼠标/键盘*/
		buttons_selective_default(DEFAULT_ALL);  /*取消游戏面板所有按键的高亮*/

		int RET[2];
		RET[0] = if_block(b, X, Y);  /*判断此时鼠标的位置是否在某个格子中*/
		RET[1] = if_button(X, Y);    /*判断此时鼠标的位置是否在某个按键中*/
		buttons_selective_activate(RET[1]);  /*若鼠标在某个按键中，将对应的按键设置高亮*/
		const int J = RET[0] % 9;        /*将一维坐标转换为列数*/
		const int I = (RET[0] - J) / 9;  /*将一维坐标转换为行数*/

		switch (if_select) {
		case true:
			/*若已选定了一个珠子，则在选定位置打印一个紫色的边界*/
			cct_gotoxy(10 * select_x, 5 * select_y);
			print_blockborder(9 * select_y + select_x, COLOR_HPINK, COLOR_WHITE);

			/*若鼠标所在的格子不在选定的位置，则在当前位置打印一个浅青色的边界*/
			if (select_x != J || select_y != I) {
				blocks_selective_default(b, RET[0], COLOR_WHITE, COLOR_BLACK);
				blocks_selective_activate(b, RET[0], COLOR_HCYAN, COLOR_WHITE);
			}
			break;
		case false:
			/*若未选定珠子，则在当前位置打印一个紫色的边界*/
			blocks_selective_default(b, RET[0], COLOR_WHITE, COLOR_BLACK);
			blocks_selective_activate(b, RET[0], COLOR_HPINK, COLOR_WHITE);
			break;
		}

		update_score();  /*更新得分*/
		update_color();  /*更新颜色*/

		switch (ret) {
		/*1、返回鼠标事件*/
		case CCT_MOUSE_EVENT:
			switch (maction) {
			/*1.1、按下左键*/
			case MOUSE_LEFT_BUTTON_CLICK:
				switch (if_select) {
				case true:
					/*若选定了一个珠子，且鼠标在一个空的格子上，则进行下一步操作*/
					if (RET[0] >= 0 && !ball::if_ball[RET[0]]) {
						if (*if_sound)  /*根据需要播放声音*/
							Beep(SOUND_SO, 100);

						move(b, select_x, select_y, J, I);  /*移动珠子*/
						scan(b);  /*扫描可消除的珠子*/
						cct_gotoxy(10 * select_x, 5 * select_y);  /*将原来选定位置的紫色格子边界消除*/
						print_blockborder(9 * select_y + select_x, COLOR_WHITE, COLOR_BLACK);

						if (get_mark_num(b)) {  /*若有珠子被标记，则更新状态并进行清除*/
							update_state(STATE_CLEAR);
							clear(b, if_sound);
						}

						else {  /*若没有珠子被标记，则生成3个新的珠子*/
							summon(b, 3, if_sound);
							scan(b);  /*再扫描一次，以防新生成的珠子满足消除条件*/

							if (get_mark_num(b)) {  /*若再扫描一次依然有珠子被标记，则更新状态并进行清除*/
								update_state(STATE_CLEAR);
								clear(b, if_sound);
							}
						}
						
						/*原先选定位置的信息和选定状态都重设为默认值*/
						select_x = -1;
						select_y = -1;
						if_select = false;
					}
					break;
				case false:
					/*若未选定珠子*/
					if (ball::if_ball[RET[0]] && !RET[1]) {  /*鼠标在一个有珠子的位置上，则存储选定位置的信息并更新选定状态*/
						select_x = J;
						select_y = I;
						if_select = true;

						if (*if_sound)  /*根据需要播放声音*/
							Beep(SOUND_DO, 100);
					}

					else if (!ball::if_ball[RET[0]] && !RET[1]) {
						update_state(STATE_VACANT);

						if (*if_sound)  /*根据需要播放声音*/
							Beep(SOUND_LSI, 200);
					}
					break;
				}

				if (RET[1] && *if_sound)  /*若在某个按键上按下左键，则根据需要播放声音*/
					Beep(SOUND_MI, 100);

				/*若鼠标在某一个按键上，则根据按键更新状态、取返回值并结束循环*/
				switch (RET[1]) {
				case 1:  /*“设置”键*/
					update_state(STATE_OPTIONS);
					result = GAME_RET_OPTIONS, loop = 0;
					break;
				case 2:  /*“保存”键*/
					update_state(STATE_SAVE);
					result = GAME_RET_SAVE, loop = 0;
					break;
				case 3:  /*“删除”键*/
					update_state(STATE_DELETE);
					result = GAME_RET_DELETE, loop = 0;
					break;
				case 4:  /*“退出”键*/
					update_state(STATE_QUIT);
					result = GAME_RET_QUIT, loop = 0;
					break;
				}
				break;
			/*1.2、按下右键*/
			case MOUSE_RIGHT_BUTTON_CLICK:
				if (if_select) {  /*若选定了一个珠子，则将原来选定位置的紫色格子边界消除*/
					cct_gotoxy(10 * select_x, 5 * select_y);
					print_blockborder(9 * select_y + select_x, COLOR_WHITE, COLOR_BLACK);

					/*原先选定位置的信息和选定状态都重设为默认值*/
					select_x = -1;
					select_y = -1;
					if_select = false;

					/*更新状态为取消选定*/
					update_state(STATE_CANCEL);

					if (*if_sound)  /*根据需要播放声音*/
						Beep(SOUND_LSI, 100);
				}
				break;
			/*1.3、鼠标移动*/
			case MOUSE_ONLY_MOVED:
				switch (if_select) {
				case true:
					update_state(STATE_MOVING);  /*若已选定一个珠子，则更新状态为选定位置*/
					break;
				case false:
					update_state(STATE_SELECTING);  /*若未选定珠子，则更新状态为选定目标*/
					break;
				}
			}
			break;
		/*2、返回键盘事件*/
		case CCT_KEYBOARD_EVENT:
			/*根据键码播放声音、更新状态、取返回值并结束循环*/
			switch (keycode1) {
			case 'O':  /*“设置”键*/
			case 'o':
				if (*if_sound)
					Beep(SOUND_MI, 100);
				update_state(STATE_OPTIONS);
				result = GAME_RET_OPTIONS, loop = 0;
				break;
			case 'S':  /*“保存”键*/
			case 's':
				if (*if_sound)
					Beep(SOUND_MI, 100);
				update_state(STATE_SAVE);
				result = GAME_RET_SAVE, loop = 0;
				break;
			case 'D':  /*“删除”键*/
			case 'd':
				if (*if_sound)
					Beep(SOUND_MI, 100);
				update_state(STATE_DELETE);
				result = GAME_RET_DELETE, loop = 0;
				break;
			case 'Q':  /*“退出”键*/
			case 'q':
				if (*if_sound)
					Beep(SOUND_MI, 100);
				update_state(STATE_QUIT);
				result = GAME_RET_QUIT, loop = 0;
				break;
			}
		}
	}

	cct_disable_mouse();	//禁用鼠标
	return result;
}