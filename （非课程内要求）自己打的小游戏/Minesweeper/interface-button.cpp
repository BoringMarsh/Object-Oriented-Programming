#include"interface-button.h"

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
  �������ƣ�set_color
  ��    �ܣ�������������ɫ
  ���������const int BG_COLOR������ɫ��ֻ����
			const int FG_COLOR��ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void button::set_color(const int BG_COLOR, const int FG_COLOR)
{
	bg_color = BG_COLOR;
	fg_color = FG_COLOR;
}

/***************************************************************************
  �������ƣ�set_coord
  ��    �ܣ��������������Ͻ�����
  ���������const int X�����ϽǺ����ֻ꣨����
		    const int Y�����Ͻ������ֻ꣨����
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void button::set_coord(const int X, const int Y)
{
	x = X;
	y = Y;
}

/***************************************************************************
  �������ƣ�set_type
  ��    �ܣ���������������
  ���������const int TYPE���������ֻࣨ����
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void button::set_type(const int TYPE)
{
	type = TYPE;
}

/***************************************************************************
  �������ƣ�act
  ��    �ܣ����ݰ�����������ְ���Ч��
  ���������const int act_mode��Ч��ģʽ��ֻ����
  �� �� ֵ����
  ˵    �����ú�������Ϊĳһ����ȡ��������Ҳ���Դﵽ��ӡ�ð�����Ч��
***************************************************************************/
void button::act(const int act_mode)
{
	cct_gotoxy(x, y);  /*�ƶ������ָ��λ��*/

	switch (type) {  /*���ݰ������಻ͬ���ö�Ӧ��ɫ����ӡ*/
	case GMMB_YES:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);
		cct_showstr(x, y, "��", bg_color, fg_color);
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_NO:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);
		cct_showstr(x, y, "��", bg_color, fg_color);
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_SURE:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);
		cct_showstr(x, y, "ȷ��", bg_color, fg_color);
		cct_showstr(x, y + 1, "����", bg_color, fg_color);
		break;
	case CV_EASY:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HRED, COLOR_HWHITE);
		else
			set_color(COLOR_RED, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button("  ��  ", bg_color, fg_color);
		break;
	case CV_MEDIUM:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HBLUE, COLOR_HWHITE);
		else
			set_color(COLOR_BLUE, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button("  �е�  ", bg_color, fg_color);
		break;
	case CV_HARD:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HGREEN, COLOR_HWHITE);
		else
			set_color(COLOR_GREEN, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button("  ����  ", bg_color, fg_color);
		break;
	case CV_DIY:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HCYAN, COLOR_HWHITE);
		else
			set_color(COLOR_CYAN, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button(" �Զ��� ", bg_color, fg_color);
		break;
	case CV_OPTIONS:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HPINK, COLOR_HWHITE);
		else
			set_color(COLOR_PINK, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button("  ����  ", bg_color, fg_color);
		break;
	case CV_QUIT:
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLACK, COLOR_HWHITE);
		else
			set_color(COLOR_HBLACK, COLOR_HWHITE);
		cct_gotoxy(x, y);
		print_cover_button("  �˳�  ", bg_color, fg_color);
		break;
	case IPBX_IPLINE:
	case IPBX_IPROW:
	case IPBX_IPBOMB:
		if (act_mode == ACTIVATE)
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_A);
		else
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_D);
		cct_gotoxy(x, y);
		print_empty_block(bg_color, fg_color);
		break;
	case IPBX_SURE:
		if (act_mode == ACTIVATE)
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_A);
		else
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_D);
		cct_showstr(x, y, "ȷ��", bg_color, fg_color);
		cct_showstr(x, y + 1, "����", bg_color, fg_color);
		break;
	case IPBX_CANCEL:
		if (act_mode == ACTIVATE)
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_A);
		else
			set_color(IPBX_BG_COLOR, IPBX_FG_COLOR_D);
		cct_showstr(x, y, "ȡ��", bg_color, fg_color);
		cct_showstr(x, y + 1, "����", bg_color, fg_color);
		break;
	case OPBX_SETSOUND:
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);
		cct_gotoxy(x, y);
		print_empty_block(bg_color, fg_color);
		break;
	case OPBX_SETFONT:
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);
		cct_gotoxy(x, y);
		print_empty_block(bg_color, fg_color);
		break;
	case OPBX_SURE:
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);
		cct_showstr(x, y, " ȷ�� ", bg_color, fg_color);
		cct_showstr(x, y + 1, "������", bg_color, fg_color);
		break;
	case OPBX_CANCEL:
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);
		cct_showstr(x, y, " ȡ�� ", bg_color, fg_color);
		cct_showstr(x, y + 1, "������", bg_color, fg_color);
		break;
	}
}