#include"90-b3.h"

/***************************************************************************
  �������ƣ�set_button_type
  ��    �ܣ���������������
  �����������
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void cover::set_button_type()
{
	button_new.set_type(CV_NEW);          /*������Ϸ������������*/
	button_load.set_type(CV_LOAD);        /*��������Ϸ������������*/
	button_auto.set_type(CV_AUTO);        /*���Զ���Ϸ������������*/
	button_options.set_type(CV_OPTIONS);  /*�����á�����������*/
	button_about.set_type(CV_ABOUT);      /*�����ڡ�����������*/
	button_quit.set_type(CV_QUIT);        /*���˳���Ϸ������������*/
}

/***************************************************************************
  �������ƣ�set_button_coord
  ��    �ܣ����������긳ֵ
  �����������
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void cover::set_button_coord()
{
	button_new.set_coord(NEW_COORD_X, NEW_COORD_Y);              /*������Ϸ�������긳ֵ*/
	button_load.set_coord(LOAD_COORD_X, LOAD_COORD_Y);           /*��������Ϸ�������긳ֵ*/
	button_auto.set_coord(AUTO_COORD_X, AUTO_COORD_Y);           /*���Զ���Ϸ�������긳ֵ*/
	button_options.set_coord(OPTIONS_COORD_X, OPTIONS_COORD_Y);  /*�����á������긳ֵ*/
	button_about.set_coord(ABOUT_COORD_X, ABOUT_COORD_Y);        /*�����ڡ������긳ֵ*/
	button_quit.set_coord(QUIT_COORD_X, QUIT_COORD_Y);           /*���˳���Ϸ�������긳ֵ*/
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
	cct_setconsoleborder(44, COVER_WIDTH + 2);  /*���ô��ڴ�С����ȥ�ڱ�*/
	int i;

	/*1����ӡ���⻭�汳��*/
	cct_showstr(0, 0, "��������������������������������������������", COLOR_WHITE, COLOR_BLACK);
	for (i = 0; i < COVER_WIDTH - 2; i++) {
		cct_showstr(0, i + 1, "��                                        ��", COLOR_WHITE, COLOR_BLACK);
		Sleep(10);
	}
	cct_showstr(0, COVER_WIDTH - 1, "��������������������������������������������", COLOR_WHITE, COLOR_BLACK);

	/*2����ӡ���֡�2��*/
	Sleep(100);
	cct_showstr(TWO_COORD_X, TWO_COORD_Y, "     ", COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X + 4, TWO_COORD_Y + 1, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X + 4, TWO_COORD_Y + 2, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showstr(TWO_COORD_X, TWO_COORD_Y + 3, "     ", COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X, TWO_COORD_Y + 4, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X, TWO_COORD_Y + 5, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showstr(TWO_COORD_X, TWO_COORD_Y + 6, "     ", COLOR_HRED, COLOR_BLACK);

	/*3����ӡ���֡�0��*/
	Sleep(100);
	cct_showstr(ZERO_COORD_X, ZERO_COORD_Y, "     ", COLOR_HYELLOW, COLOR_BLACK);
	for (i = 0; i < 5; i++) {
		cct_showch(ZERO_COORD_X, ZERO_COORD_Y + 1 + i, ' ', COLOR_HYELLOW, COLOR_BLACK);
		cct_showch(ZERO_COORD_X + 4, ZERO_COORD_Y + 1 + i, ' ', COLOR_HYELLOW, COLOR_BLACK);
	}
	cct_showstr(ZERO_COORD_X, ZERO_COORD_Y + 6, "     ", COLOR_HYELLOW, COLOR_BLACK);

	/*4����ӡ���֡�4��*/
	Sleep(100);
	for (i = 0; i < 3; i++) {
		cct_showch(FOUR_COORD_X, FOUR_COORD_Y + i, ' ', COLOR_HBLUE, COLOR_BLACK);
		cct_showch(FOUR_COORD_X + 4, FOUR_COORD_Y + i, ' ', COLOR_HBLUE, COLOR_BLACK);
	}
	cct_showstr(FOUR_COORD_X, FOUR_COORD_Y + 3, "     ", COLOR_HBLUE, COLOR_BLACK);
	for (i = 0; i < 3; i++) {
		cct_showch(FOUR_COORD_X + 4, FOUR_COORD_Y + 4 + i, ' ', COLOR_HBLUE, COLOR_BLACK);
	}

	/*5����ӡ���֡�8��*/
	Sleep(100);
	cct_showstr(EIGHT_COORD_X, EIGHT_COORD_Y, "     ", COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X, EIGHT_COORD_Y + 1, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X + 4, EIGHT_COORD_Y + 1, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X, EIGHT_COORD_Y + 2, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X + 4, EIGHT_COORD_Y + 2, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showstr(EIGHT_COORD_X, EIGHT_COORD_Y + 3, "     ", COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X, EIGHT_COORD_Y + 4, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X + 4, EIGHT_COORD_Y + 4, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X, EIGHT_COORD_Y + 5, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showch(EIGHT_COORD_X + 4, EIGHT_COORD_Y + 5, ' ', COLOR_HGREEN, COLOR_BLACK);
	cct_showstr(EIGHT_COORD_X, EIGHT_COORD_Y + 6, "     ", COLOR_HGREEN, COLOR_BLACK);

	/*6����ӡ����*/
	Sleep(100);
	button_new.act(DEFAULT);
	button_load.act(DEFAULT);
	button_auto.act(DEFAULT);
	button_options.act(DEFAULT);
	button_about.act(DEFAULT);
	button_quit.act(DEFAULT);

	/*7����ӡ�汾��*/
	cct_showstr(CVVER_COORD_X, CVVER_COORD_Y, __GAME.version, COLOR_WHITE, COLOR_BLACK);
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

	if (X >= NEW_COORD_X && X <= NEW_COORD_X + 11 && Y >= NEW_COORD_Y && Y <= NEW_COORD_Y + 2)                  /*�ж��Ƿ��ڡ�����Ϸ������*/
		p[0] = true;
	if (X >= LOAD_COORD_X && X <= LOAD_COORD_X + 11 && Y >= LOAD_COORD_Y && Y <= LOAD_COORD_Y + 2)              /*�ж��Ƿ��ڡ�������Ϸ������*/
		p[1] = true;
	if (X >= AUTO_COORD_X && X <= AUTO_COORD_X + 11 && Y >= AUTO_COORD_Y && Y <= AUTO_COORD_Y + 2)              /*�ж��Ƿ��ڡ��Զ���Ϸ������*/
		p[2] = true;
	if (X >= OPTIONS_COORD_X && X <= OPTIONS_COORD_X + 11 && Y >= OPTIONS_COORD_Y && Y <= OPTIONS_COORD_Y + 2)  /*�ж��Ƿ��ڡ����á�����*/
		p[3] = true;
	if (X >= ABOUT_COORD_X && X <= ABOUT_COORD_X + 11 && Y >= ABOUT_COORD_Y && Y <= ABOUT_COORD_Y + 2)          /*�ж��Ƿ��ڡ����ڡ�����*/
		p[4] = true;
	if (X >= QUIT_COORD_X && X <= QUIT_COORD_X + 11 && Y >= QUIT_COORD_Y && Y <= QUIT_COORD_Y + 2)              /*�ж��Ƿ��ڡ��˳���Ϸ������*/
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
		button_auto.act(DEFAULT);     /*���Զ���Ϸ����ȡ������*/
		break;
	case 4:
		button_options.act(DEFAULT);  /*�����á���ȡ������*/
		break;
	case 5:
		button_about.act(DEFAULT);    /*�����ڡ���ȡ������*/
		break;
	case 6:
		button_quit.act(DEFAULT);     /*���˳���Ϸ����ȡ������*/
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
		button_auto.act(ACTIVATE);     /*���Զ���Ϸ�������ø���*/
		break;
	case 4:
		button_options.act(ACTIVATE);  /*�����á������ø���*/
		break;
	case 5:
		button_about.act(ACTIVATE);    /*�����ڡ������ø���*/
		break;
	case 6:
		button_quit.act(ACTIVATE);     /*���˳���Ϸ�������ø���*/
		break;
	}
}

/***************************************************************************
  �������ƣ�control
  ��    �ܣ��ü����ڱ��⻭���Ͻ��в���
  �����������
  �� �� ֵ��int�����еĲ���
  ˵    ������
***************************************************************************/
int cover::control()
{
	int X = 0, Y = 0;  /*�������꣬��ʼ��Ϊ��*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*�����ķ���ֵ*/

	cct_enable_mouse();  /*�������*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*�����/����*/
		selective_default(DEFAULT_ALL);  /*ȡ�����⻭�����а����ĸ���*/

		int RET = if_button(X, Y);  /*�жϴ�ʱ����λ���Ƿ���ĳ��������*/
		selective_activate(RET);    /*����ĳ�������У�����Ӧ�İ������ø���*/

		/*1�������ص�������¼����Ұ������*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {
			switch (RET) {
			case 1:
				result = COVER_NEW, loop = 0;       /*ȡ����ֵ������ѭ��*/
				break;
			case 2:
				result = COVER_LOAD, loop = 0;      /*ȡ����ֵ������ѭ��*/
				break;
			case 3:
				result = COVER_AUTO, loop = 0;      /*ȡ����ֵ������ѭ��*/
				break;
			case 4:
				result = COVER_OPTIONS, loop = 0;   /*ȡ����ֵ������ѭ��*/
				break;
			case 5:
				result = COVER_ABOUT, loop = 0;     /*ȡ����ֵ������ѭ��*/
				break;
			case 6:
				result = COVER_QUIT, loop = 0;      /*ȡ����ֵ������ѭ��*/
				break;
			}
		}
	}

	cct_disable_mouse();	//�������
	return result;
}