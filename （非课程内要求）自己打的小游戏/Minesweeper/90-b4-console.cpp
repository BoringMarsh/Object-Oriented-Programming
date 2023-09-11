#include<cmath>
#include"cmd_console_tools.h"
#include"90-b4.h"
#include"interface-mailbox.h"

/***************************************************************************
  �������ƣ�block_single_print
  ��    �ܣ���ӡһ���������ַ�������ɫ�ķ���
  ���������const int num�������м�����֣�ֻ����
			const int bg_color�����鱳��ɫ��ֻ����
			const int fg_color������ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ����1���������Թ�굱ǰλ��Ϊ��������Ͻ�
			2������Ϸ���м�ֻ������һ���ַ����ʽ�����һ���ַ������
			3������ֵΪ'*'-'0'ʱ����м��ַ�Ϊ'*'��ɫ��
			4����������м��ַ�Ϊ'��'��ɫ��
***************************************************************************/
void block_print(const int num, const int bg_color, const int fg_color)
{
	int X, Y;         /*��������*/
	cct_getxy(X, Y);  /*ȡ��굱ǰ����*/

	/*1����ӡ�ϱ߽�*/
	cct_showstr(X, Y, "������", bg_color, fg_color);

	/*2����ӡ��߽�*/
	cct_showstr(X, Y + 1, "��", bg_color, fg_color);

	/*3����ӡ�м�*/
	if (num == '*' - '0') {
		cct_showch(X + 2, Y + 1, '*', bg_color, fg_color);
		cct_showch(X + 3, Y + 1, ' ', bg_color, fg_color);
	}

	else if (num == '��')
		cct_showstr(X + 2, Y + 1, "��", bg_color, fg_color);

	else {
		cct_showch(X + 2, Y + 1, char(num + '0'), bg_color, fg_color);  /*�����һ������*/
		cct_showch(X + 3, Y + 1, ' ', bg_color, fg_color);  /*�����һ�����ֺ�Ŀո�*/
	}

	/*4����ӡ�ұ߽�*/
	cct_showstr(X + 4, Y + 1, "��", bg_color, fg_color);

	/*5����ӡ�±߽�*/
	cct_showstr(X, Y + 2, "������", bg_color, fg_color);

	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�block_blink
  ��    �ܣ�ʹ��ǰ�����µ�Ԫ�ض�Ӧɫ����˸
  ���������const int row����Ϸ������ֻ����
            const int coord��Ԫ�ص�һά���ֻ꣨����
			const int bg_color1����˸����ɫ1��ֻ����
			const int bg_color2����˸����ɫ2��ֻ����
			const int fg_color��ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ��������������Ϊ��˸2��
***************************************************************************/
void block_blink(const int row, const int coord, const int bg_color1, const int bg_color2, const int fg_color)
{
	const int J = coord % row;        /*��һά����ת��Ϊ�б�*/
	const int I = (coord - J) / row;  /*��һά����ת��Ϊ�б�*/
	const int rpt = 2;  /*�ظ�������2��*/

	for (int i = 0; i < rpt; i++) {
		cct_gotoxy(6 * J + 2, 3 * I + 12);
		block_print('*' - '0', bg_color1, fg_color);
		Sleep(1);  /*��ʱ1�������ٶ�*/

		cct_gotoxy(6 * J + 2, 3 * I + 12);
		block_print('*' - '0', bg_color2, fg_color);
		Sleep(1);  /*��ʱ1�������ٶ�*/
	}
}

/***************************************************************************
  �������ƣ�gameboard_print
  ��    �ܣ���ӡ��Ϸ��屳��
  ���������const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
  �� �� ֵ����
  ˵    ����1����������ɫ��������Ϸ�Ԥ����10�еĿռ�
            2������Ʊ����ͬʱ�����������ͬ���ı�
***************************************************************************/
void gameboard_print(const int line, const int row)
{
	int X = 0, Y = 0;  /*��굱ǰ�������꣬��ʼ��Ϊ0*/

	/*1��������Ͻ��Ʊ��*/
	cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK);
	X = X + 2;

	/*2�������һ���м��Ʊ��*/
	for (int i = 0; i < 3 * row; i++, X = X + 2)
		cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK);

	/*3��������Ͻ��Ʊ��*/
	cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK);
	Y = Y + 1, X = 0;

	/*4��ѭ������м�ÿһ��*/
	for (int i = 0; i < 3 * line + 11; i++, Y++, X = 0) {
		if (i == 10) {  /*�����10�зֽ���*/
			cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK);
			X = X + 2;

			for (int j = 0; j < 3 * row; j++, X = X + 2)
				cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK);

			cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_HBLACK);
		}

		else {  /*�������հ���*/
			cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK);
			X = X + 2;

			for (int j = 0; j < 6 * row; j++, X++)
				cct_showch(X, Y, ' ', COLOR_HWHITE, COLOR_BLACK);

			cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_HBLACK);
		}
	}

	/*5��������½��Ʊ��*/
	cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK);
	X = X + 2;

	/*6��������һ���м��Ʊ��*/
	for (int i = 0; i < 3 * row; i++, X = X + 2)
		cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK);

	/*7��������½��Ʊ��*/
	cct_showstr(X, Y, "��", COLOR_HWHITE, COLOR_BLACK);

	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�read_bomb_num
  ��    �ܣ���ȡʣ���������ת�����ַ���
  ���������char* bomb_num����Ž�����ַ�����
            const int BOMB_NUM����ǰʣ���������ֻ����
  �� �� ֵ��char*���ַ�����ʽ�Ķ�ȡ���
  ˵    ����1���������ڶ�ȡ����λ����ɺ󣬽��������ת��Ϊ�ո�
			2���ֶ������β��
			3������ȡ���Ǹ�����������˸���
***************************************************************************/
char* read_bomb_num(char* bomb_num, const int BOMB_NUM)
{
	if (BOMB_NUM) {
		int i;
		int b = int(fabs(BOMB_NUM));

		for (i = 0; i < 10; i++) {  /*������λ��*/
			bomb_num[9 - i] = b % 10;
			b = (b - b % 10) / 10;
		}

		i = 0;
		bool if_bomb_num_char = false;

		while (i < 10) {
			if (bomb_num[i]) {
				if_bomb_num_char = true;  /*������һλ��Ϊ�����������Ϊ��*/

				if (BOMB_NUM < 0)  /*��BOMB_NUMΪ������һλ��Ϊ�����ǰһλΪ����*/
					bomb_num[i - 1] = '-';
			}
			if (if_bomb_num_char)
				bomb_num[i] = bomb_num[i] + '0';  /*������Ϊ���ÿһλ��ת��Ϊ��Ӧ���ֵ��ַ�*/
			else
				bomb_num[i] = ' ';  /*δ����Ϊ��ʱ��ÿһλ��ת��Ϊ�ո�*/
			i++;
		}
	}
	
	else {
		for (int i = 0; i < 9; i++)
			bomb_num[i] = ' ';
		bomb_num[9] = '0';
	}

	bomb_num[10] = '\0';  /*���β��*/
	return bomb_num;
}

/***************************************************************************
  �������ƣ�read_time
  ��    �ܣ���ȡ��ʱ��ת�����ַ���
  ���������char* time����Ž�����ַ�����
  �� �� ֵ��char*���ַ�����ʽ�Ķ�ȡ���
  ˵    ����1���������ڶ�ȡ����λ����ɺ󣬽��������ת��Ϊ�ո�
			2���ֶ������β��
			3������ȡ��ʱ���������֣���λΪ��
***************************************************************************/
char* read_time(char* time, const LONGLONG TIME)
{
	if (TIME) {
		int i;
		LONGLONG t = TIME;  /*ȡ��ǰ��ʱ*/

		for (i = 0; i < 10; i++) {  /*������λ��*/
			time[9 - i] = t % 10;
			t = (t - t % 10) / 10;
		}

		i = 0;
		bool if_time_char = false;

		while (i < 10) {
			if (time[i])
				if_time_char = true;  /*������һλ��Ϊ�����������Ϊ��*/
			if (if_time_char)
				time[i] = time[i] + '0';  /*������Ϊ���ÿһλ��ת��Ϊ��Ӧ���ֵ��ַ�*/
			else
				time[i] = ' ';  /*δ����Ϊ��ʱ��ÿһλ��ת��Ϊ�ո�*/
			i++;
		}
	}
	
	else {
		for (int i = 0; i < 9; i++)
			time[i] = ' ';
		time[9] = '0';
	}

	time[10] = '\0';  /*���β��*/
	return time;
}

/***************************************************************************
  �������ƣ�print_info
  ��    �ܣ������Ϸ��Ϣ
  ���������const int row����Ϸ������ֻ����
            const int bomb_num��������Ŀ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void print_info(const int row, const int bomb_num)
{
	char bn[11];

	/*��ӡ����Ϸ��*/
	cct_showstr(NEW_COORD_X, NEW_COORD_Y, "������", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 1, "��", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X + 2, NEW_COORD_Y + 1, "\001", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X + 4, NEW_COORD_Y + 1, "��", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 2, "������", NEW_BG_COLOR_D, NEW_FG_COLOR_D);

	/*��ӡʣ������*/
	cct_showstr(MINE_COORD_X, MINE_COORD_Y, "��������������", MINE_BG_COLOR, MINE_FG_COLOR);
	cct_showstr(MINE_COORD_X, MINE_COORD_Y + 1, "��          ��", MINE_BG_COLOR, MINE_FG_COLOR);
	cct_showstr(MINE_COORD_X, MINE_COORD_Y + 2, "��          ��", MINE_BG_COLOR, MINE_FG_COLOR);
	cct_showstr(MINE_COORD_X, MINE_COORD_Y + 3, "��������������", MINE_BG_COLOR, MINE_FG_COLOR);
	cct_showstr(MINE_COORD_X + 2, MINE_COORD_Y + 1, "ʣ��������", MINE_BG_COLOR, MINE_FG_COLOR);
	cct_showstr(MINE_COORD_X + 2, MINE_COORD_Y + 2, read_bomb_num(bn, bomb_num), MINE_BG_COLOR, MINE_FG_COLOR);

	/*��ӡ��ʱ*/
	cct_showstr(TIME_COORD_X, TIME_COORD_Y, "��������������", TIME_BG_COLOR, TIME_FG_COLOR);
	cct_showstr(TIME_COORD_X, TIME_COORD_Y + 1, "��          ��", TIME_BG_COLOR, TIME_FG_COLOR);
	cct_showstr(TIME_COORD_X, TIME_COORD_Y + 2, "��          ��", TIME_BG_COLOR, TIME_FG_COLOR);
	cct_showstr(TIME_COORD_X, TIME_COORD_Y + 3, "��������������", TIME_BG_COLOR, TIME_FG_COLOR);
	cct_showstr(TIME_COORD_X + 2, TIME_COORD_Y + 1, "ʱ�䣺", TIME_BG_COLOR, TIME_FG_COLOR);
	cct_showstr(TIME_COORD_X + 2, TIME_COORD_Y + 2, "         0", TIME_BG_COLOR, TIME_FG_COLOR);
}

/***************************************************************************
  �������ƣ�update_bomb_num
  ��    �ܣ�����ʣ������
  ���������const int row����Ϸ������ֻ����
            const int bomb_num��������Ŀ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void update_bomb_num(const int row, const int bomb_num)
{
	char bn[11];

	cct_showstr(MINE_COORD_X + 2, MINE_COORD_Y + 2, read_bomb_num(bn, bomb_num), MINE_BG_COLOR, MINE_FG_COLOR);
}

/***************************************************************************
  �������ƣ�update_time
  ��    �ܣ�������ʱ
  ���������const int row����Ϸ������ֻ����
			const LARGE_INTEGER tick����ż�����Ƶ����Ϣ�Ľṹ�壨ֻ����
			const LARGE_INTEGER begin����ų�ʼӲ��������������Ϣ�Ľṹ�壨ֻ����
			const LARGE_INTEGER end�������ֹӲ��������������Ϣ�Ľṹ�壨ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void update_time(const int row, const LARGE_INTEGER tick, const LARGE_INTEGER begin, const LARGE_INTEGER end)
{
	char time[11];
	const LONGLONG TIME = (end.QuadPart - begin.QuadPart) / tick.QuadPart;

	cct_showstr(TIME_COORD_X + 2, TIME_COORD_Y + 2, read_time(time, TIME), TIME_BG_COLOR, TIME_FG_COLOR);
}

/***************************************************************************
  �������ƣ�if_block
  ��    �ܣ��ж����λ���Ƿ���ĳһɫ����
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
            const int X�����λ�ú����ֻ꣨����
			const int Y�����λ�������ֻ꣨����
            const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
  �� �� ֵ��int��ɫ���ӦԪ�ص�һά���꣨���ڷ�Χ���򷵻��㣩
  ˵    ������
***************************************************************************/
int if_block(matrix MATRIX[], const int X, const int Y, const int line, const int row)
{
	int ret = INT_MAX;  /*����ֵ������Ϊһ������ֵ*/

	for (int i = 0; i < line * row; i++) {  /*����������Ԫ��λ�ã������������ĳ��ɫ���ڣ����÷���ֵ������ǲ��������*/
		const int J = i % row;        /*��һά����ת��Ϊ�б�*/
		const int I = (i - J) / row;  /*��һά����ת��Ϊ�б�*/

		if (X >= 6 * J + 2 && X <= 6 * J + 7 && Y >= 3 * I + 12 && Y <= 3 * I + 14) {
			ret = I * row + J;  /*���÷���ֵ*/
			MATRIX[ret].coord_mark = true;  /*���ö�ӦԪ�ص�������*/
			break;
		}
	}

	return ret;
}

/***************************************************************************
  �������ƣ�if_new_button
  ��    �ܣ��ж����λ���Ƿ�������Ϸ����
  ���������const int X�����λ�ú����ֻ꣨����
			const int Y�����λ�������ֻ꣨����
			const int row����Ϸ������ֻ����
  �� �� ֵ��bool�����λ���Ƿ�������Ϸ����
  ˵    �������ں궨������������̣����Ƚ������㲢��ֵ�������������ٽ���λ���ж�
***************************************************************************/
bool if_new_button(const int X, const int Y, const int row)
{
	const int coord_x = NEW_COORD_X;  //ȡ����Ϸ�����ϽǺ�����
	const int coord_y = NEW_COORD_Y;  //ȡ����Ϸ�����Ͻ�������

	if (X >= coord_x && X <= coord_x + 5 && Y >= coord_y && Y <= coord_y + 2)
		return true;
	else
		return false;
}

/***************************************************************************
  �������ƣ�new_button_default
  ��    �ܣ�����Ϸ��ȡ������
  ���������const int row����Ϸ������ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void new_button_default(const int row)
{
	cct_showstr(NEW_COORD_X, NEW_COORD_Y, "������", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 1, "��", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X + 2, NEW_COORD_Y + 1, "\001", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X + 4, NEW_COORD_Y + 1, "��", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 2, "������", NEW_BG_COLOR_D, NEW_FG_COLOR_D);
}

/***************************************************************************
  �������ƣ�new_button_activate
  ��    �ܣ�����Ϸ�����ø���
  ���������const int row����Ϸ������ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void new_button_activate(const int row)
{
	cct_showstr(NEW_COORD_X, NEW_COORD_Y, "������", NEW_BG_COLOR_A, NEW_FG_COLOR_A);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 1, "��", NEW_BG_COLOR_A, NEW_FG_COLOR_A);
	cct_showstr(NEW_COORD_X + 2, NEW_COORD_Y + 1, "\001", NEW_BG_COLOR_A, NEW_FG_COLOR_A);
	cct_showstr(NEW_COORD_X + 4, NEW_COORD_Y + 1, "��", NEW_BG_COLOR_A, NEW_FG_COLOR_A);
	cct_showstr(NEW_COORD_X, NEW_COORD_Y + 2, "������", NEW_BG_COLOR_A, NEW_FG_COLOR_A);
}

/***************************************************************************
  �������ƣ�selective_default
  ��    �ܣ�ѡ���Ե�Ϊĳһɫ��ȡ������
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int coord����һ�����ø���ɫ���ӦԪ�ص�һά���ֻ꣨����
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
  �� �� ֵ����
  ˵    ������ӦԪ��Ϊ�����������в������������ǡ�δ��������δ������
***************************************************************************/
void selective_default(matrix MATRIX[], const int line, const int row, const int coord)
{
	for (int i = 0; i < line * row; i++) {
		const int J = i % row;        /*��һά����ת��Ϊ�б�*/
		const int I = (i - J) / row;  /*��һά����ת��Ϊ�б�*/

		/*����ǰԪ�ر������ǣ��Ҳ�����һ�����ø���ɫ���ӦԪ�أ�δ������Ҳδ�����죬����в���*/
		if (MATRIX[i].coord_mark && i != coord && !MATRIX[i].if_turned && !MATRIX[i].if_flag) {
			cct_gotoxy(6 * J + 2, 3 * I + 12);  /*�ƶ��������Ӧλ��*/
			block_print(NUM_SPACE, COLOR_WHITE, COLOR_BLACK);  /*��ӡ�м�Ϊ�յĳ�ʼɫ��*/
			MATRIX[i].coord_mark = false;  /*ȡ��������*/
		}
	}
}

/***************************************************************************
  �������ƣ�selective_activate
  ��    �ܣ�ѡ���Ե�Ϊĳһɫ�����ø���
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int coord��ɫ���ӦԪ�ص�һά���ֻ꣨����
			const int X�����λ�ú����ֻ꣨����
			const int Y�����λ�������ֻ꣨����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void selective_activate(matrix MATRIX[], const int line, const int row, const int coord, const int X, const int Y)
{
	const int J = coord % row;        /*��һά����ת��Ϊ�б�*/
	const int I = (coord - J) / row;  /*��һά����ת��Ϊ�б�*/

	/*�����λ����ĳһɫ���ڣ��Ҷ�ӦԪ��δ������������в���*/
	if (X >= 2 && X <= 6 * row && Y >= 12 && Y <= 3 * line + 10 && !MATRIX[coord].if_turned) {
		cct_gotoxy(6 * J + 2, 3 * I + 12);  /*�ƶ��������Ӧλ��*/

		if (!MATRIX[coord].if_flag)
			block_print(NUM_SPACE, COLOR_HWHITE, COLOR_BLACK);  /*����Ԫ��δ�����죬���ӡ�м�Ϊ�յĸ���ɫ��*/
	}
}

/***************************************************************************
  �������ƣ�turn
  ��    �ܣ�����һ��Ԫ��
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int coord���ڲ������ж�ӦԪ�ص�һά���ֻ꣨����
  �� �� ֵ��int���������
  ˵    ����������������0�����������ף��򷵻ض�Ӧֵ
***************************************************************************/
int turn(matrix MATRIX[], const int line, const int row, const int coord)
{
	int ret = 0;  /*����ֵ������Ϊ0*/

	if (!MATRIX[coord].if_turned && !MATRIX[coord].if_flag) {  /*ֻ����Ŀ��Ԫ��δ��������δ�����������²ſ�ʼ����*/
		switch (MATRIX[coord].num) {
		case '0':
			matrix m[LINE_MAX * ROW_MAX];

			while (!matrix_compare(m, MATRIX, line, row)) {  /*��һ�ֱ�ǣ����������������Ԫ��*/
				matrix_copy(m, MATRIX, line, row);

				for (int i = 0; i < line * row; i++) {
					zero_check1(MATRIX, line, row, i);
				}
			}

			for (int i = 0; i < line * row; i++)  /*�ڶ��ֱ�ǣ�������б������Ԫ����Χ������Ԫ��*/
				zero_check2(MATRIX, line, row, i);

			for (int i = 0; i < line * row; i++) {  /*�������б���ǵ�Ԫ��*/
				if (MATRIX[i].mark) {
					const int L = i % row;        /*��һά����ת��Ϊ�б�*/
					const int K = (i - L) / row;  /*��һά����ת��Ϊ�б�*/
					cct_gotoxy(6 * L + 2, 3 * K + 12);
					block_print(MATRIX[i].num - '0', COLOR_HWHITE, num_trans_color(MATRIX[i].num - '0'));
					MATRIX[i].mark = false;      /*ȡ��һ����*/
					MATRIX[i].if_turned = true;  /*Ԫ����Ϊ�ѱ�����״̬*/
				}
			}

			break;
		case '*':
			failure(MATRIX, line, row, coord);  /*����ʧ��Ч������*/
			ret = FAILURE;  /*���ض�Ӧֵ*/
			break;
		default:
			const int J = coord % row;        /*��һά����ת��Ϊ�б�*/
			const int I = (coord - J) / row;  /*��һά����ת��Ϊ�б�*/
			cct_gotoxy(6 * J + 2, 3 * I + 12);
			block_print(MATRIX[coord].num - '0', COLOR_HWHITE, num_trans_color(MATRIX[coord].num - '0'));
			MATRIX[coord].mark = false;      /*ȡ��һ����*/
			MATRIX[coord].if_turned = true;  /*Ԫ����Ϊ�ѱ�����״̬*/
			break;
		}
	}

	return ret;
}

/***************************************************************************
  �������ƣ�wheel_click_turn
  ��    �ܣ�������м�ʱ�ķ�������
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int coord���ڲ������ж�ӦԪ�ص�һά���ֻ꣨����
  �� �� ֵ��int���������
  ˵    ����1��������������0�����������ף��򷵻ض�Ӧֵ
			2�������ڸ�Ԫ����Χ�Ĳ�����Ŀ��������ֵʱ�Ž��в���
***************************************************************************/
int wheel_click_turn(matrix MATRIX[], const int line, const int row, const int coord)
{
	int RET = 0;  /*����ֵ������Ϊ0*/

	if (MATRIX[coord].if_turned && !MATRIX[coord].if_flag  /*ֻ���ڸ�Ԫ���ѱ�������δ�����������²Ž��в���*/
		&& flag_check(MATRIX, line, row, coord) == MATRIX[coord].num - '0') {
		const int J = coord % row;        /*��һά����ת��Ϊ�б�*/
		const int I = (coord - J) / row;  /*��һά����ת��Ϊ�б�*/
		int ret[8] = { 0 };  /*����turn()��������ֵ�����飬ȫ����Ϊ0*/

		if (I) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У����������һ��Ԫ��*/
			if (!MATRIX[coord - row].if_flag) {
				MATRIX[coord - row].mark = true;
				ret[0] = turn(MATRIX, line, row, coord - row);
			}
		}

		if (J) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У���������һ��Ԫ��*/
			if (!MATRIX[coord - 1].if_flag) {
				MATRIX[coord - 1].mark = true;
				ret[1] = turn(MATRIX, line, row, coord - 1);
			}
		}

		if (I < line - 1) {  /*��Ŀ��Ԫ�ز������һ�У����������һ��Ԫ��*/
			if (!MATRIX[coord + row].if_flag) {
				MATRIX[coord + row].mark = true;
				ret[2] = turn(MATRIX, line, row, coord + row);
			}
		}

		if (J < row - 1) { /*��Ŀ��Ԫ�ز������һ�У�������ұ�һ��Ԫ��*/
			if (!MATRIX[coord + 1].if_flag) {
				MATRIX[coord + 1].mark = true;
				ret[3] = turn(MATRIX, line, row, coord + 1);
			}
		}

		if (I && J) { /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
			if (!MATRIX[coord - row - 1].if_flag) {
				MATRIX[coord - row - 1].mark = true;
				ret[4] = turn(MATRIX, line, row, coord - row - 1);
			}
		}

		if (I && J < row - 1) { /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
			if (!MATRIX[coord - row + 1].if_flag) {
				MATRIX[coord - row + 1].mark = true;
				ret[5] = turn(MATRIX, line, row, coord - row + 1);
			}
		}

		if (I < line - 1 && J) { /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
			if (!MATRIX[coord + row - 1].if_flag) {
				MATRIX[coord + row - 1].mark = true;
				ret[6] = turn(MATRIX, line, row, coord + row - 1);
			}
		}

		if (I < line - 1 && J < row - 1) { /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
			if (!MATRIX[coord + row + 1].if_flag) {
				MATRIX[coord + row + 1].mark = true;
				ret[7] = turn(MATRIX, line, row, coord + row + 1);
			}
		}

		for (int i = 0; i < 8; i++) {  /*���������з���ֵ�������ַ���ֵ��Ϊ�㣬�򽫸�ֵ��Ϊ����ֵ���������*/
			if (ret[i] == FAILURE) {
				RET = ret[i];
				break;
			}
		}
	}

	return RET;
}

/***************************************************************************
  �������ƣ�failure
  ��    �ܣ�������Ϸʧ��Ч������
  ���������const matrix MATRIX[]��������Ϸ���ڲ��ṹ�����飨ֻ����
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int coord��ʧ��ʱ���λ�ö�Ӧ��һά���ֻ꣨����
  �� �� ֵ����
  ˵    ������������Ϊ���������ڵ�ɫ�������˸
***************************************************************************/
void failure(const matrix MATRIX[], const int line, const int row, const int coord)
{
	block_blink(row, coord, COLOR_RED, COLOR_HRED, COLOR_BLACK);  /*���е���λ����˸��ɫɫ��*/

	for (int i = 0; i < line * row; i++) {
		if (MATRIX[i].num == '*' && i != coord)  /*����ɫɫ���⣬�������׵�λ����˸����ɫɫ��*/
			block_blink(row, i, COLOR_YELLOW, COLOR_HYELLOW, COLOR_BLACK);
	}
}

/***************************************************************************
  �������ƣ�failure
  ��    �ܣ�������Ϸʤ��Ч������
  ���������const matrix MATRIX[]��������Ϸ���ڲ��ṹ�����飨ֻ����
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
  �� �� ֵ����
  ˵    ������������Ϊ���������ڵ�ɫ�������ɫ
***************************************************************************/
void victory(const matrix MATRIX[], const int line, const int row)
{
	update_bomb_num(row, 0);  /*����ʣ�������Ϊ0*/

	for (int i = 0; i < line * row; i++) {
		if (MATRIX[i].num == '*') {
			const int J = i % row;        /*��һά����ת��Ϊ�б�*/
			const int I = (i - J) / row;  /*��һά����ת��Ϊ�б�*/

			cct_gotoxy(6 * J + 2, 3 * I + 12);
			block_print('��', COLOR_GREEN, COLOR_BLACK);  /*�������׵�λ����ʾΪ�м��С̵���ɫɫ��*/
			Sleep(10);  /*��ʱ10�������ٶ�*/
		}
	}
}

/***************************************************************************
  �������ƣ�flag
  ��    �ܣ����й��������ӱ�ǵĲ���
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			int* bomb_num��ʣ������
			const int flag_mode������ģʽ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void flag(matrix MATRIX[], const int line, const int row, const int coord, int* bomb_num, const int flag_mode)
{
	const int J = coord % row;        /*��һά����ת��Ϊ�б�*/
	const int I = (coord - J) / row;  /*��һά����ת��Ϊ�б�*/

	switch (flag_mode) {
	case PLACE_FLAG:  /*����*/
		(*bomb_num)--;
		update_bomb_num(row, *bomb_num);
		cct_gotoxy(6 * J + 2, 3 * I + 12);
		block_print('F' - '0', COLOR_HBLACK, COLOR_HWHITE);
		MATRIX[coord].if_flag = true;
		break;
	case REMOVE_FLAG:  /*�Ƴ�����*/
		(*bomb_num)++;
		update_bomb_num(row, *bomb_num);
		cct_gotoxy(6 * J + 2, 3 * I + 12);
		block_print(NUM_SPACE, COLOR_HBLACK, COLOR_HWHITE);
		MATRIX[coord].if_flag = false;
		break;
	}
}

/***************************************************************************
  �������ƣ�control
  ��    �ܣ��ü��������Ϸ����
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int bomb_num��������Ŀ��ֻ����
			bool* if_initialized���ڲ��ṹ�������Ƿ��ʼ��
  �� �� ֵ��int���������
  ˵    ������������֤��һ�ε����Ž����ڲ������ʼ����ʹ�õ�һ�ε������㵽��
***************************************************************************/
int control(matrix MATRIX[], const int line, const int row, const int BOMB_NUM, bool* if_initialized)
{
	int X = 0, Y = 0;  /*�������꣬��ʼ��Ϊ��*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0, RESULT = 0;  /*�����ķ���ֵ���Ի�����������ķ���ֵ*/
	int bomb_num = BOMB_NUM;     /*ʣ�������������Ϊ�ܵ�����*/
	bool if_ai = false;          /*�Ƿ�������Զ������ı�־*/

	cct_enable_mouse();  /*�������*/

	LARGE_INTEGER tick, begin{}, end;  /*��ʱ�õĽṹ��*/

	QueryPerformanceFrequency(&tick);  /*��ü�����Ƶ��*/

	while (loop) {
		if (if_end(MATRIX, line, row)) {  /*�ж���Ϸ�Ƿ����*/
			victory(MATRIX, line, row);
			result = VICTORY;
			break;
		}

		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*�����/����*/

		if (if_ai)  /*���������Զ���������ʱ��ʾΪ������*/
			cct_showstr(TIME_COORD_X + 2, TIME_COORD_Y + 2, "    ������", TIME_BG_COLOR, TIME_FG_COLOR);

		else if (*if_initialized) {  /*���ڲ������ѳ�ʼ�������ʱ����ʾ��ʱ*/
			QueryPerformanceCounter(&end);
			update_time(row, tick, begin, end);
		}

		int RET[4];  /*���ֺ����ķ���ֵ*/
		RET[0] = if_block(MATRIX, X, Y, line, row);  /*�жϴ�ʱ����λ���Ƿ���ĳ��ɫ����*/
		RET[1] = if_new_button(X, Y, row);           /*�жϴ�ʱ����λ���Ƿ�������Ϸ����*/
		RET[2] = 0;                    /*�������������ķ���ֵ������Ϊ0*/
		const int J = RET[0] % row;        /*��һά����ת��Ϊ�б�*/
		const int I = (RET[0] - J) / row;  /*��һά����ת��Ϊ�б�*/
		selective_default(MATRIX, line, row, RET[0]);         /*ȡ��ǰһ������ɫ��ĸ���*/
		selective_activate(MATRIX, line, row, RET[0], X, Y);  /*���õ�ǰλ����ɫ��ĸ���*/

		/*����Ϸ������ʾЧ��*/
		if (RET[1])
			new_button_activate(row);
		else
			new_button_default(row);

		/*1�������ص�������¼���ͬʱ�����ĳһɫ����*/
		if (ret == CCT_MOUSE_EVENT && RET[0] != INT_MAX) {
			switch (maction) {
			/*�������*/
			case MOUSE_LEFT_BUTTON_CLICK:
				MATRIX[RET[0]].mark = true;  /*��ǰɫ������һ���ǣ����������������ʱ�ļ��*/

				switch (*if_initialized) {
				case true:
					RET[2] = turn(MATRIX, line, row, RET[0]);  /*���ڲ������ѳ�ʼ��������з�������*/
					break;
				case false:
					matrix_initialize(MATRIX, line, row, BOMB_NUM, J, I);  /*���ڲ�����δ��ʼ������ȡ��һ�ε��λ�ò����г�ʼ��*/
					*if_initialized = true;  /*�Ƿ��ʼ����Ǽ�Ϊ��*/

					QueryPerformanceCounter(&begin);  /*��ó�ʼӲ������������*/

					RET[2] = turn(MATRIX, line, row, RET[0]);  /*�Ե�һ�ε��λ�õ�Ԫ�ؽ��з�������*/
					break;
				}

				if (RET[2])  /*�����η�����Ϊ���������������÷���ֵ�����ѭ��*/
					result = RET[2], loop = 0;
				break;
			/*�����Ҽ�*/
			case MOUSE_RIGHT_BUTTON_CLICK:
				if (!MATRIX[RET[0]].if_turned) {   /*ֻ���ڵ�ǰɫ���ӦԪ��δ������ʱ�Ž��в���*/
					switch (MATRIX[RET[0]].if_flag) {
					case true:
						flag(MATRIX, line, row, RET[0], &bomb_num, REMOVE_FLAG);  /*�������*/
						break;
					case false:
						flag(MATRIX, line, row, RET[0], &bomb_num, PLACE_FLAG);   /*�Ƴ����Ӳ���*/
						break;
					}
				}

				break;
			/*��������*/
			case MOUSE_WHEEL_CLICK:
				MATRIX[RET[0]].mark = true;  /*��ǰɫ������һ���ǣ����������������ʱ�ļ��*/
				RET[2] = wheel_click_turn(MATRIX, line, row, RET[0]);  /*����ʽ��������*/

				if (RET[2])  /*�����η�����Ϊ���������������÷���ֵ�����ѭ��*/
					result = FAILURE, loop = 0;
				break;
			}
		}

		/*1������굥�������ͬʱ���������Ϸ����*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK && RET[1] != 0)
			result = NEW, loop = 0;

		if (ret == CCT_KEYBOARD_EVENT) {
			switch (keycode1) {
			case 'A':
			case 'a':
				RET[2] = ai_control(MATRIX, line, row, &bomb_num, if_initialized);  /*�����Զ�����*/
				if_ai = true;  /*�Ƿ�����Զ�������־��Ϊ��*/

				if (RET[2])  /*�����η�����Ϊ���������������÷���ֵ�����ѭ��*/
					result = FAILURE, loop = 0;
				break;
			case 'Q':
			case 'q':
				GAME_MAILBOX.print(BUTTON_TWO, line, row, "���Ƿ�Ҫ�˳���Ϸ��");  /*�����Ի���ѯ���Ƿ��˳���Ϸ*/
				RET[3] = GAME_MAILBOX.control(line, row);  /*�÷���ֵ��ȡ�Ի������*/

				switch (RET[3]) {
				case GMMB_RET_YES:
					result = QUIT, loop = 0;  /*�������ǡ�����������QUIT����ʾ�˳�״̬*/
					break;
				case GMMB_RET_NO:
					GAME_MAILBOX.erase(MATRIX, line, row);  /*�������񡱣���������겢����ѭ��*/
					cct_enable_mouse();
					break;
				}
				break;
			}
		}
	}

	cct_disable_mouse();	//�������
	return result;
}