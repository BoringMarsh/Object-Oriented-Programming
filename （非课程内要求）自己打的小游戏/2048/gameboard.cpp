#include"90-b3.h"

/***************************************************************************
  �������ƣ�print_background
  ��    �ܣ���ӡ��ײ㱳��
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void gameboard::print_background()
{
	int Y = 0;  /*����*/

	/*��ӡ��һ��*/
	cct_showstr(0, Y, "��", GMBD_BG_COLOR, GMBD_FG_COLOR);
	cct_showstr(2, Y, "��", GMBD_BG_COLOR, GMBD_FG_COLOR, 4 * __GAME.order + 11);
	cct_showstr(__GAME.order * 8 + 24, Y, "��", GMBD_BG_COLOR, GMBD_FG_COLOR);

	/*��ӡ�м���*/
	for (Y = 1; Y < __GAME.order * 4 + 16; Y++) {
		cct_showstr(0, Y, "��", GMBD_BG_COLOR, GMBD_FG_COLOR);
		cct_showstr(2, Y, "  ", GMBD_BG_COLOR, GMBD_FG_COLOR, 4 * __GAME.order + 11);
		cct_showstr(__GAME.order * 8 + 24, Y, "��", GMBD_BG_COLOR, GMBD_FG_COLOR);
	}

	/*��ӡ���һ��*/
	cct_showstr(0, __GAME.order * 4 + 16, "��", GMBD_BG_COLOR, GMBD_FG_COLOR);
	cct_showstr(2, __GAME.order * 4 + 16, "��", GMBD_BG_COLOR, GMBD_FG_COLOR, 4 * __GAME.order + 11);
	cct_showstr(__GAME.order * 8 + 24, __GAME.order * 4 + 16, "��", GMBD_BG_COLOR, GMBD_FG_COLOR);
}

/***************************************************************************
  �������ƣ�read_score
  ��    �ܣ���ȡ�÷ֲ�ת�����ַ���
  ���������char* max����Ž�����ַ�����
  �� �� ֵ��char*���ַ�����ʽ�Ķ�ȡ���
  ˵    ����1���������ڶ�ȡ����λ����ɺ󣬽��������ת��Ϊ�ո�
			2���ֶ������β��
***************************************************************************/
char* gameboard::read_score(char* score)
{
	int i;
	int s = __GAME.score;  /*ȡ��ǰ�÷�*/

	for (i = 0; i < 10; i++) {  /*������λ��*/
		score[9 - i] = s % 10;
		s = (s - s % 10) / 10;
	}

	i = 0;
	bool if_score_char = false;

	while (i < 10) {
		if (score[i])
			if_score_char = true;  /*������һλ��Ϊ�����������Ϊ��*/
		if (if_score_char)
			score[i] = score[i] + '0';  /*������Ϊ���ÿһλ��ת��Ϊ��Ӧ���ֵ��ַ�*/
		else
			score[i] = ' ';  /*δ����Ϊ��ʱ��ÿһλ��ת��Ϊ�ո�*/
		i++;
	}

	score[10] = '\0';  /*���β��*/
	return score;
}

/***************************************************************************
  �������ƣ�read_max
  ��    �ܣ���ȡ����Ԫ���е����ֵ��ת�����ַ���
  ���������char* max����Ž�����ַ�����
  �� �� ֵ��char*���ַ�����ʽ�Ķ�ȡ���
  ˵    ����1���������ڶ�ȡ����λ����ɺ󣬽��������ת��Ϊ�ո�
			2���ֶ������β��
***************************************************************************/
char* gameboard::read_max(char* max)
{
	int i;
	int m = matrix_getmax();  /*ȡ���Ԫ��*/

	for (i = 0; i < 10; i++) {  /*������λ��*/
		max[9 - i] = m % 10;
		m = (m - m % 10) / 10;
	}

	i = 0;
	bool if_max_char = false;

	while (i < 10) {
		if (max[i])
			if_max_char = true;  /*������һλ��Ϊ�����������Ϊ��*/
		if (if_max_char)
			max[i] = max[i] + '0';  /*������Ϊ���ÿһλ��ת��Ϊ��Ӧ���ֵ��ַ�*/
		else
			max[i] = ' ';  /*δ����Ϊ��ʱ��ÿһλ��ת��Ϊ�ո�*/
		i++;
	}

	max[10] = '\0';  /*���β��*/
	return max;
}

/***************************************************************************
  �������ƣ�read_solution
  ��    �ܣ���ȡѰ�ҳ������ŽⲢת��Ϊ�ַ���
  �����������
  �� �� ֵ��const char*�����Ž⣨�ַ�����ʽ��
  ˵    ����1���������ڶ�ȡ����λ����ɺ󣬽��������ת��Ϊ�ո�
			2���ֶ������β��
***************************************************************************/
const char* gameboard::read_solution()
{
	int ret = __GAME.ai_player.find_best_solution();
	const char* RET = NULL;

	switch (ret) {
	case AI_SLN_UP:
		RET = "  ���Ϻϳ�";
		break;
	case AI_SLN_DOWN:
		RET = "  ���ºϳ�";
		break;
	case AI_SLN_LEFT:
		RET = "  ����ϳ�";
		break;
	case AI_SLN_RIGHT:
		RET = "  ���Һϳ�";
		break;
	}

	return RET;
}

/***************************************************************************
  �������ƣ�read_stepnumber
  ��    �ܣ���ȡ������ת��Ϊ�ַ���
  �����������
  �� �� ֵ��char*���ַ�����ʽ�Ķ�ȡ���
  ˵    ����1���������ڶ�ȡ����λ����ɺ󣬽��������ת��Ϊ�ո�
			2���ֶ������β��
***************************************************************************/
char* gameboard::read_stepnumber(char* stepnumber)
{
	int i;
	int s = __GAME.stepnumber;  /*ȡ����*/

	for (i = 0; i < 10; i++) {  /*������λ��*/
		stepnumber[9 - i] = s % 10;
		s = (s - s % 10) / 10;
	}

	i = 0;
	bool if_max_char = false;

	while (i < 10) {
		if (stepnumber[i])
			if_max_char = true;  /*������һλ��Ϊ�����������Ϊ��*/
		if (if_max_char)
			stepnumber[i] = stepnumber[i] + '0';  /*������Ϊ���ÿһλ��ת��Ϊ��Ӧ���ֵ��ַ�*/
		else
			stepnumber[i] = ' ';  /*δ����Ϊ��ʱ��ÿһλ��ת��Ϊ�ո�*/
		i++;
	}

	stepnumber[10] = '\0';  /*���β��*/
	return stepnumber;
}

/***************************************************************************
  �������ƣ�print_info
  ��    �ܣ���ʾ��Ϸ�����Ϣ
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void gameboard::print_info()
{
	const int X = __GAME.order * 8 + 8;
	const int Y = 2;

	cct_showstr(SCORE_COORD_X, SCORE_COORD_Y, "��������������", SCORE_BG_COLOR, SCORE_FG_COLOR);
	cct_showstr(SCORE_COORD_X, SCORE_COORD_Y + 1, "��          ��", SCORE_BG_COLOR, SCORE_FG_COLOR);
	cct_showstr(SCORE_COORD_X, SCORE_COORD_Y + 2, "��          ��", SCORE_BG_COLOR, SCORE_FG_COLOR);
	cct_showstr(SCORE_COORD_X, SCORE_COORD_Y + 3, "��������������", SCORE_BG_COLOR, SCORE_FG_COLOR);
	cct_showstr(SCORE_COORD_X + 2, SCORE_COORD_Y + 1, "�÷֣�", SCORE_BG_COLOR, SCORE_FG_COLOR);
	cct_showstr(SCORE_COORD_X + 2, SCORE_COORD_Y + 2, "         0", SCORE_BG_COLOR, SCORE_FG_COLOR);

	cct_showstr(MAX_COORD_X, MAX_COORD_Y, "��������������", MAX_BG_COLOR, MAX_FG_COLOR);
	cct_showstr(MAX_COORD_X, MAX_COORD_Y + 1, "��          ��", MAX_BG_COLOR, MAX_FG_COLOR);
	cct_showstr(MAX_COORD_X, MAX_COORD_Y + 2, "��          ��", MAX_BG_COLOR, MAX_FG_COLOR);
	cct_showstr(MAX_COORD_X, MAX_COORD_Y + 3, "��������������", MAX_BG_COLOR, MAX_FG_COLOR);
	cct_showstr(MAX_COORD_X + 2, MAX_COORD_Y + 1, "���ֵ��", MAX_BG_COLOR, MAX_FG_COLOR);
	cct_showstr(MAX_COORD_X + 2, MAX_COORD_Y + 2, "         0", MAX_BG_COLOR, MAX_FG_COLOR);

	cct_showstr(TIPS_COORD_X, TIPS_COORD_Y, "��������������", TIPS_BG_COLOR, TIPS_FG_COLOR);
	cct_showstr(TIPS_COORD_X, TIPS_COORD_Y + 1, "��          ��", TIPS_BG_COLOR, TIPS_FG_COLOR);
	cct_showstr(TIPS_COORD_X, TIPS_COORD_Y + 2, "��          ��", TIPS_BG_COLOR, TIPS_FG_COLOR);
	cct_showstr(TIPS_COORD_X, TIPS_COORD_Y + 3, "��������������", TIPS_BG_COLOR, TIPS_FG_COLOR);
	cct_showstr(TIPS_COORD_X + 2, TIPS_COORD_Y + 1, "��ʾ��", TIPS_BG_COLOR, TIPS_FG_COLOR);

	if (__GAME.if_tips)
		cct_showstr(TIPS_COORD_X + 2, TIPS_COORD_Y + 2, "������ƶ�", COLOR_HWHITE, COLOR_BLACK);
	else
		cct_showstr(TIPS_COORD_X + 6, TIPS_COORD_Y + 2, "�ѹر�", COLOR_HWHITE, COLOR_BLACK);

	cct_showstr(STEPNUM_COORD_X, STEPNUM_COORD_Y, "��������������", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
	cct_showstr(STEPNUM_COORD_X, STEPNUM_COORD_Y + 1, "��          ��", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
	cct_showstr(STEPNUM_COORD_X, STEPNUM_COORD_Y + 2, "��          ��", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
	cct_showstr(STEPNUM_COORD_X, STEPNUM_COORD_Y + 3, "��������������", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
	cct_showstr(STEPNUM_COORD_X + 2, STEPNUM_COORD_Y + 1, "��ǰ������", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
	cct_showstr(STEPNUM_COORD_X + 2, STEPNUM_COORD_Y + 2, "         0", STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
}

/***************************************************************************
  �������ƣ�update_info
  ��    �ܣ�������Ϸ�����Ϣ
  �����������
  �� �� ֵ����
  ˵    ������
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
		cct_showstr(X + 2, Y + 12, "    �ѹر�", TIPS_BG_COLOR, TIPS_FG_COLOR);
	cct_showstr(X + 2, Y + 17, read_stepnumber(stepnumber), STEPNUM_BG_COLOR, STEPNUM_FG_COLOR);
}

/***************************************************************************
  �������ƣ�block_single_print
  ��    �ܣ���ӡһ�����������ֵ�����ɫ�ķ���
  ���������const int num�������м�����֣�ֻ����
            const int bg_color�����鱳��ɫ��ֻ����
			const int fg_color������ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ����1���������Թ�굱ǰλ��Ϊ��������Ͻ�
			2���м����ֿ�����ʾ����λ����
***************************************************************************/
void gameboard::block_single_print(const int num, const int bg_color, const int fg_color)
{
	int X, Y;         /*��������*/
	cct_getxy(X, Y);  /*ȡ��굱ǰ����*/

	/*1����ӡ�ϱ߽�*/
	cct_showstr(X, Y, "������", bg_color, fg_color);

	/*2����ӡ��߽�*/
	if (num >= 100) {  /*��������λ���������֣���߽�Ϊ|�Լ�ǧλ���λ��*/
		cct_showch(X, Y + 1, '|', bg_color, fg_color);

		if (num < 1000)  /*��λ����ӡ��λ*/
			cct_showch(X + 1, Y + 1, char((num - num % 100) / 100 + '0'), bg_color, fg_color);
		else             /*��λ����ӡǧλ*/
			cct_showch(X + 1, Y + 1, char((num - num % 1000) / 1000 + '0'), bg_color, fg_color);
	}

	else  /*��ֻ������ͷ���������������λ�������£���ֻ��ӡ�Ʊ��*/
		cct_showstr(X, Y + 1, "��", bg_color, fg_color);

	/*3����ӡ�м�*/
	const int num1 = num % 10;                          /*ȡ��λ*/
	const int num2 = ((num - num % 10) / 10) % 10;      /*ȡʮλ*/
	const int num3 = ((num - num % 100) / 100) % 10;    /*ȡ��λ*/
	const int num4 = ((num - num % 1000) / 1000) % 10;  /*ȡǧλ*/

	int NUM1, NUM2;

	if (num < 10)                       /*��numΪһλ�������������һ���ո�*/
		NUM1 = num1, NUM2 = 0;
	else if (num >= 10 && num < 100)    /*��numΪ��λ�����������������ͬλ�ϵ���*/
		NUM1 = num2, NUM2 = num1;
	else if (num >= 100 && num < 1000)  /*��numΪ��λ�����������ʮλ�͸�λ�ϵ���*/
		NUM1 = num2, NUM2 = num1;
	else                                /*��numΪ��λ�������������λ��ʮλ�ϵ���*/
		NUM1 = num3, NUM2 = num2;

	cct_showch(X + 2, Y + 1, char(NUM1 + '0'), bg_color, fg_color);  /*�����һ������*/
	const char c = NUM2 ? char(NUM2 + '0') : ' ';                    /*����ڶ������֣���������λ��ʱ����ո�*/
	cct_showch(X + 3, Y + 1, c, bg_color, fg_color);

	/*4����ӡ�ұ߽�*/
	if (num >= 1000) {  /*��������λ�����ұ߽�Ϊ|�Լ���λ��*/
		cct_showch(X + 4, Y + 1, char(num % 10 + '0'), bg_color, fg_color);
		cct_showch(X + 5, Y + 1, '|', bg_color, fg_color);
	}
	else  /*�������ֻ��ӡ�Ʊ��*/
		cct_showstr(X + 4, Y + 1, "��", bg_color, fg_color);

	/*5����ӡ�±߽�*/
	cct_showstr(X, Y + 2, "������", bg_color, fg_color);
	
	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�block_multiple_print
  ��    �ܣ����ݵ�ǰ�ڲ�����ֵ��ӡɫ��
  �����������
  �� �� ֵ����
  ˵    ����Ԫ��Ϊ��ʱ�����Ӧɫ��
***************************************************************************/
void gameboard::block_multiple_print()
{
	int i;  /*��������*/

	for (i = 0; i < __GAME.order * __GAME.order; i++) {
		const int J = i % __GAME.order;        /*��һά����ת��Ϊ�б�*/
		const int I = (i - J) / __GAME.order;  /*��һά����ת��Ϊ�б�*/

		if (__GAME.matrix[i]) {  /*��Ԫ�ز�Ϊ����ػ���Ӧɫ�飬��֤��ϷЧ��*/
			cct_gotoxy(8 * J + CSBD_COORD_X + 2, 4 * I + CSBD_COORD_Y + 1);
			block_single_print(__GAME.matrix[i], color_number(__GAME.matrix[i]), COLOR_BLACK);
		}

		else {  /*��Ԫ��Ϊ��ʱ�����Ӧɫ�飬��֤��ϷЧ��*/
			cct_gotoxy(8 * J + CSBD_COORD_X + 2, 4 * I + CSBD_COORD_Y + 1);
			block_clear();
		}
	}
}

/***************************************************************************
  �������ƣ�block_clear
  ��    �ܣ�����ǰ�����¶�Ӧ��ɫ�����
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void gameboard::block_clear()
{
	int X, Y;
	cct_getxy(X, Y);
	cct_showstr(X, Y, "      ", CSBD_BG_COLOR);      /*�ð�ɫ������һ��*/
	cct_showstr(X, Y + 1, "      ", CSBD_BG_COLOR);  /*�ð�ɫ�����ڶ���*/
	cct_showstr(X, Y + 2, "      ", CSBD_BG_COLOR);  /*�ð�ɫ����������*/
	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�chessboard_single_line
  ��    �ܣ������Ϸ����ĳһ��
  ���������int Y�������ú���ǰ��������
			const char* ch1�����е�һ���Ʊ����ֻ����
			const char* ch2�������м���Ʊ����ֻ����
			const char* ch3�������м�������Ʊ����ֻ����
			const char* ch4���������һ���Ʊ����ֻ����
			const bool if_delay:�Ƿ���ʱ��ֻ����
  �� �� ֵ����
  ˵    ����1��ÿ�ж��Ǵ�X=2����ʼ��ӡ
			2��ÿ���һ���Ʊ����X��������2�Ĳ���
***************************************************************************/
void gameboard::chessboard_single_line(int Y, const char* ch1, const char* ch2, const char* ch3, const char* ch4, const bool if_delay)
{
	int i;      /*��������*/
	int X = CSBD_COORD_X;  /*�����꣬��ʼΪ2*/

	/*1�������һ���Ʊ��*/
	cct_showstr(X, Y, ch1, CSBD_BG_COLOR, CSBD_FG_COLOR);
	X = X + 2;

	/*2������м�Ķ���Ʊ��*/
	for (i = 0; i < 3 * __GAME.order; i++) {

		/*2.1������м��һ���Ʊ��*/
		cct_showstr(X, Y, ch2, CSBD_BG_COLOR, CSBD_FG_COLOR);
		X = X + 2;

		/*2.2����ָ��λ�ô�ӡ�����Ʊ��*/
		if (X % 8 == CSBD_COORD_X && X != CSBD_COORD_X + __GAME.order * 8) {
			cct_showstr(X, Y, ch3, CSBD_BG_COLOR, CSBD_FG_COLOR);
			X = X + 2;
		}

		/*2.3��ÿִ������ֹͣ1�����ƴ�ӡ�ٶ�*/
		if (i % 3 == 1 && if_delay)
			Sleep(1);
	}

	/*3��������һ���Ʊ����������ɫ*/
	cct_showstr(X, Y, ch4, CSBD_BG_COLOR, CSBD_FG_COLOR);
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�chessboard_multiple_lines
  ��    �ܣ������Ϸ���ĸ���
  ���������const int Y��������ֻ����
            const bool if_delay:�Ƿ���ʱ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void gameboard::chessboard_multiple_lines(const int Y, const bool if_delay)
{
	/*���е����*/
	if (Y == CSBD_COORD_Y)
		chessboard_single_line(Y, "��", "��", "��", "��", if_delay);

	/*���һ�е����*/
	else if (Y == 4 * __GAME.order + CSBD_COORD_Y)
		chessboard_single_line(Y, "��", "��", "��", "��", if_delay);

	/*�����е����*/
	else if (Y % 4 == CSBD_COORD_Y)
		chessboard_single_line(Y, "��", "��", "��", "��", if_delay);

	/*һ���е����*/
	else
		chessboard_single_line(Y, "��", "  ", "��", "��", if_delay);
}

/***************************************************************************
  �������ƣ�print_chessboard
  ��    �ܣ���ӡ��Ϸ���
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void gameboard::print_chessboard()
{
	int Y;          /*������*/

	/*�ӵڶ��п�ʼ�����д�ӡ����*/
	for (Y = CSBD_COORD_Y; Y <= 4 * __GAME.order + CSBD_COORD_Y; Y++) {
		chessboard_multiple_lines(Y, true);  /*�����ͬ��ʽ��ÿһ��*/

		cct_gotoxy(CSBD_COORD_X, Y + 1);
	}
}

/***************************************************************************
  �������ƣ�block_activate
  ��    �ܣ�����ǰ�����¶�Ӧ��ɫ�����ø���
  ���������const int coord��Ԫ�ص�һά���ֻ꣨����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void gameboard::block_activate(const int coord)
{
	const int J = coord % __GAME.order;        /*��һά����ת��Ϊ�б�*/
	const int I = (coord - J) / __GAME.order;  /*��һά����ת��Ϊ�б�*/
	cct_gotoxy(J * 8 + CSBD_COORD_X + 2, I * 4 + CSBD_COORD_Y + 1);   /*�ƶ������ָ��λ�ã����ڽ������ػ�ɫ��*/
	block_single_print(__GAME.matrix[coord], color_number(__GAME.matrix[coord]), COLOR_WHITE);  /*�ػ�ɫ�飬��ɫ���䣬ǰ��ɫΪ��ɫ*/
	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�block_default
  ��    �ܣ�����ǰ�����¶�Ӧ��ɫ�����ȡ��
  ���������const int coord��Ԫ�ص�һά���ֻ꣨����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void gameboard::block_default(const int coord)
{
	const int J = coord % __GAME.order;        /*��һά����ת��Ϊ�б�*/
	const int I = (coord - J) / __GAME.order;  /*��һά����ת��Ϊ�б�*/
	cct_gotoxy(J * 8 + CSBD_COORD_X + 2, I * 4 + CSBD_COORD_Y + 1);   /*�ƶ������ָ��λ�ã����ڽ������ػ�ɫ��*/
	block_single_print(__GAME.matrix[coord], color_number(__GAME.matrix[coord]), COLOR_BLACK);  /*�ػ�ɫ�飬��ɫ���䣬ǰ��ɫΪ��ɫ*/
	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�blink_block
  ��    �ܣ�ʹ��ǰ�����µ�Ԫ�ض�Ӧɫ����˸
  ���������const int coord��Ԫ�ص�һά���ֻ꣨����
  �� �� ֵ����
  ˵    ��������������Ϊ��˸10��
***************************************************************************/
void gameboard::blink_block(const int coord)
{
	const int J = coord % __GAME.order;        /*��һά����ת��Ϊ�б�*/
	const int I = (coord - J) / __GAME.order;  /*��һά����ת��Ϊ�б�*/
	const int rpt = 10;       /*�ظ�������10��*/
	int i;  /*��������*/

	for (i = 0; i < rpt; i++) {
		block_activate(coord);  /*���ø���*/
		Sleep(10);  /*��ʱ10�������ٶ�*/

		block_default(coord);   /*����ȡ��*/
		Sleep(10);  /*��ʱ10�������ٶ�*/
	}
}