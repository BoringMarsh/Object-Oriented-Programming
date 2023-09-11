#include<Windows.h>
#include"colorball.h"
#include"interface-cover.h"

/***************************************************************************
  �������ƣ�C_print
  ��    �ܣ���ӡһ����ĸC
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::C_print()
{
	cct_showstr(C_COORD_X, C_COORD_Y, "     ", C_COLOR);
	for (int i = 0; i < 3; i++)
		cct_showch(C_COORD_X, C_COORD_Y + 1 + i, ' ', C_COLOR);
	cct_showstr(C_COORD_X, C_COORD_Y + 4, "     ", C_COLOR);
}

/***************************************************************************
  �������ƣ�O_print
  ��    �ܣ���ӡһ����ĸO
  ���������const int O_num����ĸ�ı�ţ�ֻ����
  �� �� ֵ����
  ˵    ������Ҫ�����ֹһ����ĸO���ʸ��ݱ���ڲ�ͬλ�������ĸO
***************************************************************************/
void cover::O_print(const int O_num)
{
	int x = 0, y = 0;
	int bg_color = COLOR_BLACK;

	switch (O_num) {  /*����Ҫ��ӡ����ĸE�����������ɫ*/
	case 1:
		x = O_COORD_X1, y = O_COORD_Y1;
		bg_color = O_COLOR1;
		break;
	case 2:
		x = O_COORD_X2, y = O_COORD_Y2;
		bg_color = O_COLOR2;
		break;
	}

	/*�������õ��������ɫ��ӡ��ĸ*/
	cct_showstr(x, y, "     ", bg_color);
	for (int i = 0; i < 3; i++) {
		cct_showch(x, y + 1 + i, ' ', bg_color);
		cct_showch(x + 4, y + 1 + i, ' ', bg_color);
	}
	cct_showstr(x, y + 4, "     ", bg_color);
}

/***************************************************************************
  �������ƣ�L_print
  ��    �ܣ���ӡһ����ĸL
  ���������const int L_num����ĸ�ı�ţ�ֻ����
  �� �� ֵ����
  ˵    ������Ҫ�����ֹһ����ĸL���ʸ��ݱ���ڲ�ͬλ�������ĸL
***************************************************************************/
void cover::L_print(const int L_num)
{
	int x = 0, y = 0;
	int bg_color = COLOR_BLACK;

	switch (L_num) {  /*����Ҫ��ӡ����ĸE�����������ɫ*/
	case 1:
		x = L_COORD_X1, y = L_COORD_Y1;
		bg_color = L_COLOR;
		break;
	case 2:
		x = L_COORD_X2, y = L_COORD_Y2;
		bg_color = BALL_COLOR;
		break;
	case 3:
		x = L_COORD_X3, y = L_COORD_Y3;
		bg_color = BALL_COLOR;
		break;
	}

	/*�������õ��������ɫ��ӡ��ĸ*/
	for (int i = 0; i < 4; i++)
		cct_showch(x, y + i, ' ', bg_color);
	cct_showstr(x, y + 4, "     ", bg_color);
}

/***************************************************************************
  �������ƣ�R_print
  ��    �ܣ���ӡһ����ĸR
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::R_print()
{
	cct_showstr(R_COORD_X, R_COORD_Y, "     ", R_COLOR);
	cct_showch(R_COORD_X, R_COORD_Y + 1, ' ', R_COLOR);
	cct_showch(R_COORD_X + 4, R_COORD_Y + 1, ' ', R_COLOR);
	cct_showstr(R_COORD_X, R_COORD_Y + 2, "     ", R_COLOR);
	cct_showch(R_COORD_X, R_COORD_Y + 3, ' ', R_COLOR);
	cct_showch(R_COORD_X + 3, R_COORD_Y + 3, ' ', R_COLOR);
	cct_showch(R_COORD_X, R_COORD_Y + 4, ' ', R_COLOR);
	cct_showch(R_COORD_X + 4, R_COORD_Y + 4, ' ', R_COLOR);
}

/***************************************************************************
  �������ƣ�B_print
  ��    �ܣ���ӡһ����ĸB
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::B_print()
{
	cct_showstr(B_COORD_X, B_COORD_Y, "    ", BALL_COLOR);
	cct_showch(B_COORD_X, B_COORD_Y + 1, ' ', BALL_COLOR);
	cct_showch(B_COORD_X + 3, B_COORD_Y + 1, ' ', BALL_COLOR);
	cct_showstr(B_COORD_X, B_COORD_Y + 2, "      ", BALL_COLOR);
	cct_showch(B_COORD_X, B_COORD_Y + 3, ' ', BALL_COLOR);
	cct_showch(B_COORD_X + 5, B_COORD_Y + 3, ' ', BALL_COLOR);
	cct_showstr(B_COORD_X, B_COORD_Y + 4, "      ", BALL_COLOR);
}

/***************************************************************************
  �������ƣ�A_print
  ��    �ܣ���ӡһ����ĸA
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::A_print()
{
	cct_showch(A_COORD_X + 4, A_COORD_Y, ' ', BALL_COLOR);
	for (int i = 0; i < 4; i++) {
		cct_showch(A_COORD_X + 3 - i, A_COORD_Y + 1 + i, ' ', BALL_COLOR);
		cct_showch(A_COORD_X + 5 + i, A_COORD_Y + 1 + i, ' ', BALL_COLOR);
	}
	cct_showstr(A_COORD_X + 2, A_COORD_Y + 3, "     ", BALL_COLOR);
}

/***************************************************************************
  �������ƣ�ball_print
  ��    �ܣ���ӡһ������
  ���������const int X���������ϽǺ����ֻ꣨����
            const int Y���������Ͻ������ֻ꣨����
			const int bg_color��������ɫ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::ball_print(const int X, const int Y, const int bg_color)
{
	for (int i = 0; i < 3; i++)
		cct_showstr(X, Y + i, "      ", bg_color);
	cct_showch(X + 2, Y + 1, ' ', COLOR_WHITE);
}

/***************************************************************************
  �������ƣ�print
  ��    �ܣ���ӡ���⻭��
  �����������
  �� �� ֵ����
  ˵    ����������ͬʱ���ݱ��⻭���������˴��ڴ�С�����ٺ�ɫ����
***************************************************************************/
void cover::print()
{
	cct_setconsoleborder(80, COVER_WIDTH + 2);  /*���ô��ڴ�С����ȥ�ڱ�*/

	/*1����ӡ���⻭�汳��*/
	cct_showstr(0, 0, "��������������������������������������������������������������������������������", COLOR_WHITE, COLOR_BLACK);
	for (int i = 0; i < COVER_WIDTH - 2; i++) {
		cct_showstr(0, i + 1, "��                                                                            ��", COLOR_WHITE, COLOR_BLACK);
		Sleep(10);
	}
	cct_showstr(0, COVER_WIDTH - 1, "��������������������������������������������������������������������������������", COLOR_WHITE, COLOR_BLACK);

	/*2����ӡ��ɫ���������ĸ*/
	PRINT_ALL_BALLS;
	PRINT_ALL_LETTERS;

	/*3����ӡ����*/
	Sleep(100);
	button_new.act(DEFAULT);
	button_load.act(DEFAULT);
	button_options.act(DEFAULT);
	button_help.act(DEFAULT);
	button_about.act(DEFAULT);
	button_exit.act(DEFAULT);
}

/***************************************************************************
  �������ƣ�if_button
  ��    �ܣ��ж����λ���Ƿ���ĳһ������
  ���������const int X�����λ�ú����ֻ꣨����
			const int Y�����λ�������ֻ꣨����
  �� �� ֵ��int���������һ������
  ˵    ������
***************************************************************************/
int cover::if_button(const int X, const int Y)
{
	int ret = 0;    /*����ֵ*/
	bool p[COVER_BUTTON_NUM];
	for (int i = 0; i < COVER_BUTTON_NUM; i++)
		p[i] = false;

	if (X >= NEW_COORD_X && X <= NEW_COORD_X + 11 && Y >= NEW_COORD_Y && Y <= NEW_COORD_Y + 2)          /*�ж��Ƿ��ڡ�����Ϸ������*/
		p[0] = true;
	if (X >= LOAD_COORD_X && X <= LOAD_COORD_X + 11 && Y >= LOAD_COORD_Y && Y <= LOAD_COORD_Y + 2)      /*�ж��Ƿ��ڡ�������Ϸ������*/
		p[1] = true;
	if (X >= CVOP_COORD_X && X <= CVOP_COORD_X + 11 && Y >= CVOP_COORD_Y && Y <= CVOP_COORD_Y + 2)      /*�ж��Ƿ��ڡ����á�����*/
		p[2] = true;
	if (X >= HELP_COORD_X && X <= HELP_COORD_X + 11 && Y >= HELP_COORD_Y && Y <= HELP_COORD_Y + 2)      /*�ж��Ƿ��ڡ�����������*/
		p[3] = true;
	if (X >= ABOUT_COORD_X && X <= ABOUT_COORD_X + 11 && Y >= ABOUT_COORD_Y && Y <= ABOUT_COORD_Y + 2)  /*�ж��Ƿ��ڡ����ڡ�����*/
		p[4] = true;
	if (X >= EXIT_COORD_X && X <= EXIT_COORD_X + 11 && Y >= EXIT_COORD_Y && Y <= EXIT_COORD_Y + 2)      /*�ж��Ƿ��ڡ��˳�������*/
		p[5] = true;

	for (int i = 0; i < COVER_BUTTON_NUM; i++) {  /*������λ�õ��������������ȡ��Ӧ����ֵ��������*/
		if (p[i]) {
			ret = i + 1;
			break;
		}
	}

	return ret;
}

/***************************************************************************
  �������ƣ�selective_default
  ��    �ܣ�ѡ���Ե�Ϊĳһ����ȡ������
  ���������const int selection������ѡ��ֻ����
  �� �� ֵ����
  ˵    ������ѡ��ΪDEFAULT_ALLʱ��ͨ���ݹ����ȡ�����а����ĸ���
***************************************************************************/
void cover::selective_default(const int selection)
{
	switch (selection) {  /*����ѡ����ж�Ӧ����*/
	case 1:
		button_new.act(DEFAULT);      /*������Ϸ����ȡ������*/
		break;
	case 2:
		button_load.act(DEFAULT);     /*��������Ϸ����ȡ������*/
		break;
	case 3:
		button_options.act(DEFAULT);  /*�����á���ȡ������*/
		break;
	case 4:
		button_help.act(DEFAULT);     /*����������ȡ������*/
		break;
	case 5:
		button_about.act(DEFAULT);    /*�����ڡ���ȡ������*/
		break;
	case 6:
		button_exit.act(DEFAULT);     /*���˳�����ȡ������*/
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < COVER_BUTTON_NUM; i++)  /*���а���ȡ������*/
			selective_default(i + 1);
		break;
	}
}

/***************************************************************************
  �������ƣ�selective_activate
  ��    �ܣ�ѡ���Ե�Ϊĳһ�������ø���
  ���������const int selection������ѡ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::selective_activate(const int selection)
{
	switch (selection) {  /*����ѡ����ж�Ӧ����*/
	case 1:
		button_new.act(ACTIVATE);      /*������Ϸ�������ø���*/
		break;
	case 2:
		button_load.act(ACTIVATE);     /*��������Ϸ�������ø���*/
		break;
	case 3:
		button_options.act(ACTIVATE);  /*�����á������ø���*/
		break;
	case 4:
		button_help.act(ACTIVATE);     /*�������������ø���*/
		break;
	case 5:
		button_about.act(ACTIVATE);    /*�����ڡ������ø���*/
		break;
	case 6:
		button_exit.act(ACTIVATE);     /*���˳��������ø���*/
		break;
	}
}

/***************************************************************************
  �������ƣ�control
  ��    �ܣ��ü����ڱ��⻭���Ͻ��в���
  ���������bool* if_sound���Ƿ�������
  �� �� ֵ��int�����еĲ���
  ˵    ������
***************************************************************************/
int cover::control(bool* if_sound)
{
	int X = 0, Y = 0;  /*�������꣬��ʼ��Ϊ��*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*�����ķ���ֵ*/

	cct_enable_mouse();  /*�������*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*�����/����*/
		int RET = if_button(X, Y);  /*�жϴ�ʱ����λ���Ƿ���ĳ��������*/

		if(!RET)
			selective_default(DEFAULT_ALL);  /*ȡ�����⻭�����а����ĸ���*/

		if (!last_button) {
			last_button = RET;
			selective_activate(RET);    /*����ĳ�������У�����Ӧ�İ������ø���*/

			if (RET && *if_sound)  /*������Ҫ��������*/
				Beep(SOUND_FA, 100);
		}

		else {
			if (RET != last_button) {
				last_button = RET;
				selective_activate(RET);    /*����ĳ�������У�����Ӧ�İ������ø���*/

				if (RET && *if_sound)  /*������Ҫ��������*/
					Beep(SOUND_FA, 100);
			}
		}

		/*1�������ص�������¼����Ұ������*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {
			switch (RET) {
			case 1:
				result = COVER_RET_NEW, loop = 0;      /*ȡ����ֵ������ѭ��*/
				break;
			case 2:
				result = COVER_RET_LOAD, loop = 0;     /*ȡ����ֵ������ѭ��*/
				break;
			case 3:
				result = COVER_RET_OPTIONS, loop = 0;  /*ȡ����ֵ������ѭ��*/
				break;
			case 4:
				result = COVER_RET_HELP, loop = 0;     /*ȡ����ֵ������ѭ��*/
				break;
			case 5:
				result = COVER_RET_ABOUT, loop = 0;    /*ȡ����ֵ������ѭ��*/
				break;
			case 6:
				result = COVER_RET_EXIT, loop = 0;     /*ȡ����ֵ������ѭ��*/
				break;
			}
		}
	}

	last_button = 0;  /*���������һ��λ����Ϣ*/
	cct_disable_mouse();	//�������
	return result;
}