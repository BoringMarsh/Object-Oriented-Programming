#include"90-b3.h"

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
  �������ƣ�print_base
  ��    �ܣ�ͼ�λ������ʼ�������������ڴ�С
  �����������
  �� �� ֵ����
  ˵    ������������һ��ʼȡ��ǰ�������꣬�������ʵ�δ�ֵ
***************************************************************************/
void console_print_base()
{
	const int LENGTH = __GAME.order * 8 + 26;  /*��������ȡ����*/
	const int WIDTH = __GAME.order * 4 + 20;   /*��������ȡ���*/

	cct_setconsoleborder(LENGTH, WIDTH);  /*����ȡ�õĳ��ȼ���ȣ���̬���ô��ڴ�С*/
	__GAME.gameboard.print_background();  /*��ӡ��ײ㱳��*/
	__GAME.gameboard.print_chessboard();  /*��ӡ��ɫ����*/

	cout << endl;  /*�����ɺ�������λ��*/
}

/***************************************************************************
  �������ƣ�color_number
  ��    �ܣ���������Ԫ��ֵ��ת��Ϊ��Ӧ����ɫ���
  ���������int initial_num��Ԫ��ʵ��ֵ/ת����ʼֵ
  �� �� ֵ��int����Ӧ��ɫ���
  ˵    ��������������Ԫ��ʵ��ֵΪ2�ļ��η�������ɫ���
***************************************************************************/
int color_number(int initial_num)
{
	int order = 0;  /*Ԫ��ֵ��������ʼΪ��*/

	/*ÿ��Ԫ��ֵ����2��order������ֱ��ֵ��Ϊ1�����յõ�����*/
	while (initial_num != 1) {
		initial_num = initial_num / 2;
		order++;
	}

	return order;
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
  �������ƣ�print_keyboard_button
  ��    �ܣ���ӡһ��С���̰������������ż�ͷ������ɫ�ķ���
  ���������const int print_mode����ӡģʽ��ֻ����
			const int bg_color�����鱳��ɫ��ֻ����
			const int fg_color������ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    �����������Թ�굱ǰλ��Ϊ��������Ͻ�
***************************************************************************/
void print_keyboard_button(const int print_mode, const int bg_color, const int fg_color)
{
	int X, Y;         /*��������*/
	cct_getxy(X, Y);  /*ȡ��굱ǰ����*/

	/*1����ӡ�ϱ߽�*/
	cct_showstr(X, Y, "������", bg_color, fg_color);

	/*2����ӡ��߽�*/
	cct_showstr(X, Y + 1, "��", bg_color, fg_color);

	/*3����ӡ�м�*/
	switch (print_mode) {
	case BLOCK_ARROW_MODE_UP:
		cct_showstr(X + 2, Y + 1, "��", bg_color, fg_color);  /*����ϼ�ͷ*/
		break;
	case BLOCK_ARROW_MODE_DOWN:
		cct_showstr(X + 2, Y + 1, "��", bg_color, fg_color);  /*����¼�ͷ*/
		break;
	case BLOCK_ARROW_MODE_LEFT:
		cct_showstr(X + 2, Y + 1, "��", bg_color, fg_color);  /*������ͷ*/
		break;
	case BLOCK_ARROW_MODE_RIGHT:
		cct_showstr(X + 2, Y + 1, "��", bg_color, fg_color);  /*����Ҽ�ͷ*/
		break;
	}

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