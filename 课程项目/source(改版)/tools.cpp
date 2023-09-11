#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<string>
#include"cmd_console_tools.h"
#include"colorball.h"
using namespace std;

/***************************************************************************
  �������ƣ�pause
  ��    �ܣ�����һ������ļ�ϵ�
  �����������
  �� �� ֵ����
  ˵    ��������س��ż����������ַ��޻���
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
  �������ƣ�num_trans_color
  ��    �ܣ�����һ��0-5���������ر�ʾ��ɫ����
  ���������const int num�����������ֻ����
  �� �� ֵ��int�����ص���ɫ
  ˵    �����ú�����Ϊ�����������ɫʱ��0-5֮����������������ɫ���ж�Ӧ
***************************************************************************/
int num_trans_color(const int num)
{
	int ret = 0;  /*����ֵ*/

	switch (num) {
	case 0:
		ret = COLOR_RED;
		break;
	case 1:
		ret = COLOR_YELLOW;
		break;
	case 2:
		ret = COLOR_HYELLOW;
		break;
	case 3:
		ret = COLOR_GREEN;
		break;
	case 4:
		ret = COLOR_BLUE;
		break;
	case 5:
		ret = COLOR_PINK;
		break;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�color_trans_string
  ��    �ܣ������ʾ��ɫ���������ر�ʾ����ɫ���ַ���
  ���������const int color���������ɫ��ֻ����
            char* c����ŷ��ؽ�����ַ�����
  �� �� ֵ��char*��������ɫ��Ӧ���ַ���
  ˵    �����ú�����Ϊ��Ԥ����ɫʱ�����͵���ɫ�������ַ������ж�Ӧ
***************************************************************************/
char* color_trans_string(const int color, char* c)
{
	switch (color) {
	case COLOR_RED:
		strcpy(c, "��");
		break;
	case COLOR_YELLOW:
		strcpy(c, "��");
		break;
	case COLOR_HYELLOW:
		strcpy(c, "��");
		break;
	case COLOR_GREEN:
		strcpy(c, "��");
		break;
	case COLOR_BLUE:
		strcpy(c, "��");
		break;
	case COLOR_PINK:
		strcpy(c, "��");
		break;
	}

	return c;
}

/***************************************************************************
  �������ƣ�chessboard_single_line
  ��    �ܣ������Ϸ����ĳһ��
  ���������int Y�������ú���ǰ��������
			const char* ch1�����е�һ���Ʊ����ֻ����
			const char* ch2�������м���Ʊ����ֻ����
			const char* ch3�������м�������Ʊ����ֻ����
			const char* ch4���������һ���Ʊ����ֻ����
  �� �� ֵ����
  ˵    ����ÿ���һ���Ʊ����X��������2�Ĳ���
***************************************************************************/
void chessboard_single_line(int Y, const char* ch1, const char* ch2, const char* ch3, const char* ch4)
{
	int i;      /*��������*/
	int X = 0;  /*�����꣬��ʼΪ2*/

	/*1�������һ���Ʊ��*/
	cct_showstr(X, Y, ch1, COLOR_WHITE, COLOR_BLACK);
	X = X + 2;

	/*2������м�Ķ���Ʊ��*/
	for (i = 0; i < 36; i++) {

		/*2.1������м��һ���Ʊ��*/
		cct_showstr(X, Y, ch2, COLOR_WHITE, COLOR_BLACK);
		X = X + 2;

		/*2.2����ָ��λ�ô�ӡ�����Ʊ��*/
		if (X % 10 == 0 && X != 90) {
			cct_showstr(X, Y, ch3, COLOR_WHITE, COLOR_BLACK);
			X = X + 2;
		}
	}

	/*3��������һ���Ʊ����������ɫ*/
	cct_showstr(X, Y, ch4, COLOR_WHITE, COLOR_BLACK);
	cct_setcolor();
}

/***************************************************************************
  �������ƣ�chessboard_multiple_lines
  ��    �ܣ������Ϸ���ĸ���
  ���������const int Y��������ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void chessboard_multiple_lines(const int Y)
{
	/*���е����*/
	if (Y == 0)
		chessboard_single_line(Y, "��", "��", "��", "��");

	/*���һ�е����*/
	else if (Y == 45)
		chessboard_single_line(Y, "��", "��", "��", "��");

	/*�����е����*/
	else if (Y % 5 == 0)
		chessboard_single_line(Y, "��", "��", "��", "��");

	/*һ���е����*/
	else
		chessboard_single_line(Y, "��", "  ", "��", "��");
}

/***************************************************************************
  �������ƣ�print_chessboard
  ��    �ܣ������Ϸ���
  �����������
  �� �� ֵ����
  ˵    �������������˴�ӡ��ɫ�����⣬����ӡ����Ϸ�����Ϣ��ʾ���Լ���Ϸ�ڸ�������
***************************************************************************/
void print_chessboard()
{
	/*���д�ӡ����*/
	for (int Y = 0; Y <= 45; Y++) {
		chessboard_multiple_lines(Y);  /*�����ͬ��ʽ��ÿһ��*/

		cct_gotoxy(0, Y + 1);
	}

	/*���д�ӡ�����Ҳ�����*/
	for (int Y = 0; Y <= 45; Y++) {
		const int X = 92;
		switch (Y) {
		case 0:
			cct_showstr(X, Y, "��������������������", COLOR_HWHITE, COLOR_BLACK);
			break;
		case 45:
			cct_showstr(X, Y, "��������������������", COLOR_HWHITE, COLOR_BLACK);
			break;
		default:
			cct_showstr(X, Y, "��                ��", COLOR_HWHITE, COLOR_BLACK);
			break;
		}
	}

	cct_gotoxy(0, 0);

	/*��ӡ��Ϸ�����Ϣ��ʾ���Լ���Ϸ�ڸ�������*/
	print_info_block(SCORE_COORD_X, SCORE_COORD_Y, "�÷֣�", COLOR_CYAN, COLOR_HWHITE);         /*��ӡ�÷���ʾ��*/
	print_info_block(COLOR_COORD_X, COLOR_COORD_Y, "��һ��ɫ��", COLOR_BLACK, COLOR_HWHITE);    /*��ӡ��һ��ɫ��ʾ��*/
	print_info_block(STATE_COORD_X, STATE_COORD_Y, "״̬��", COLOR_HRED, COLOR_HWHITE);         /*��ӡ״̬��ʾ��*/
	print_game_button(OPTIONS_COORD_X, OPTIONS_COORD_Y, " ���� ", COLOR_HBLACK, COLOR_HWHITE);  /*��ӡ�����á���*/
	print_game_button(SAVE_COORD_X, SAVE_COORD_Y, " ���� ", COLOR_HBLUE, COLOR_HWHITE);         /*��ӡ�����桱��*/
	print_game_button(DELETE_COORD_X, DELETE_COORD_Y, " ɾ�� ", COLOR_HGREEN, COLOR_HWHITE);    /*��ӡ��ɾ������*/
	print_game_button(QUIT_COORD_X, QUIT_COORD_Y, " �˳� ", COLOR_BLACK, COLOR_HWHITE);         /*��ӡ���˳�����*/
}

/***************************************************************************
  �������ƣ�print_info_block
  ��    �ܣ���ӡһ����Ϸ�����Ϣ����ʾ��
  ���������cosnt int X����ʾ�����ϽǺ����ֻ꣨����
            cosnt int Y����ʾ�����Ͻ������ֻ꣨����
			const char* title����ʾ����⣨ֻ����
			const int bg_color����ʾ�򱳾�ɫ��ֻ����
			const int fg_color����ʾ��ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void print_info_block(const int X, const int Y, const char* title, const int bg_color, const int fg_color)
{
	cct_showstr(X, Y, "��������������", bg_color, fg_color);
	cct_showstr(X, Y + 1, "��          ��", bg_color, fg_color);
	cct_showstr(X, Y + 2, "��          ��", bg_color, fg_color);
	cct_showstr(X, Y + 3, "��������������", bg_color, fg_color);
	cct_showstr(X + 2, Y + 1, title, bg_color, fg_color);
}

/***************************************************************************
  �������ƣ�print_game_button
  ��    �ܣ���ӡһ����Ϸ�ڵİ���
  ���������cosnt int X���������ϽǺ����ֻ꣨����
			cosnt int Y���������Ͻ������ֻ꣨����
			const char* title���������ݣ�ֻ����
			const int bg_color����������ɫ��ֻ����
			const int fg_color������ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void print_game_button(const int X, const int Y, const char* prompt, const int bg_color, const int fg_color)
{
	cct_showstr(X, Y, "����������", bg_color, fg_color);
	cct_showstr(X, Y + 1, "��", bg_color, fg_color);
	cct_showstr(X + 2, Y + 1, prompt, bg_color, fg_color);
	cct_showstr(X + 8, Y + 1, "��", bg_color, fg_color);
	cct_showstr(X, Y + 2, "����������", bg_color, fg_color);
}

/***************************************************************************
  �������ƣ�print_cover_button
  ��    �ܣ��ڹ�굱ǰλ�ô�ӡһ�����⻭�水��
  ���������const char* prompt���������ݣ�ֻ����
			const int bg_color����������ɫ��ֻ����
			const int fg_color������ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void print_cover_button(const char* prompt, const int bg_color, const int fg_color)
{
	int X, Y;
	cct_getxy(X, Y);
	cct_showstr(X, Y, "������������", bg_color, fg_color);
	cct_showstr(X, Y + 1, "��", bg_color, fg_color);
	cct_showstr(X + 2, Y + 1, prompt, bg_color, fg_color);
	cct_showstr(X + 10, Y + 1, "��", bg_color, fg_color);
	cct_showstr(X, Y + 2, "������������", bg_color, fg_color);
}

/***************************************************************************
  �������ƣ�print_empty_block
  ��    �ܣ��ڹ�굱ǰλ�ô�ӡһ������Ϊ�յ�ɫ��
  ���������const int bg_color����������ɫ��ֻ����
			const int fg_color������ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ��������Ϊ��ָ��������λ�ý��д�ӡ
***************************************************************************/
void print_empty_block(const int bg_color, const int fg_color)
{
	int X, Y;         /*��������*/
	cct_getxy(X, Y);  /*ȡ��굱ǰ����*/

	/*1����ӡ�ϱ߽�*/
	cct_showstr(X, Y, "������", bg_color, fg_color);

	/*2����ӡ��߽�*/
	cct_showstr(X, Y + 1, "��", bg_color, fg_color);

	/*4����ӡ�ұ߽�*/
	cct_showstr(X + 4, Y + 1, "��", bg_color, fg_color);

	/*5����ӡ�±߽�*/
	cct_showstr(X, Y + 2, "������", bg_color, fg_color);

	cct_setcolor();  /*������ɫ*/
}

/***************************************************************************
  �������ƣ�print_switch_button
  ��    �ܣ���ӡһ�������ϵİ���
  ���������const int bg_color����������ɫ��ֻ����
			const int fg_color������ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void print_switch_button(const int bg_color, const int fg_color)
{
	int X, Y;         /*��������*/
	cct_getxy(X, Y);  /*ȡ��굱ǰ����*/

	cct_showch(X, Y, ' ', bg_color, fg_color);
	cct_showch(X, Y + 1, ' ', bg_color, fg_color);
}

/***************************************************************************
  �������ƣ�power
  ��    �ܣ���һ������n�η�
  ���������const int base_number��������ֻ����
			const int exponent��ָ����ֻ����
  �� �� ֵ��int��������n�η�
  ˵    ������
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

/***************************************************************************
  �������ƣ�highscore_compare
  ��    �ܣ��涨���򷽷�
  ���������const void* p1��ָ��1��ֻ����
			const void* p2��ָ��2��ֻ����
  �� �� ֵ��int���ȽϺ�ķ���ֵ�������򷽷��йأ��Ӵ�СΪ������С����Ϊ����
  ˵    ����1��������Ϊqsort��������
			2��������֧��int�͵����򣬷���Ϊ�Ӵ�С����
			3������������Ϊ�κ���ĳ�Ա��������qsortʱ�ᱨ��
***************************************************************************/
int highscore_compare(const void* p1, const void* p2)
{
	int* a = (int*)p1;  /*ת��p1������Ϊָ��int�͵�ָ�룬����ָ�����a���յ�ַ*/
	int* b = (int*)p2;  /*ת��p2������Ϊָ��int�͵�ָ�룬����ָ�����b���յ�ַ*/
	return *b - *a;  /*������ָ��ָ��ı����������*b - *a��ʾ�Ӵ�С����*/
}