#include<windows.h>
#include"interface-cover.h"

/***************************************************************************
  �������ƣ�M_print
  ��    �ܣ���ӡһ����ĸM
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::M_print()
{
	for (int i = 0; i < 5; i++) {
		cct_showch(M_COORD_X, M_COORD_Y + i, ' ', COLOR_BLACK);
		cct_showch(M_COORD_X + i, M_COORD_Y + i, ' ', COLOR_BLACK);
		cct_showch(M_COORD_X + 10 - i - 2, M_COORD_Y + i, ' ', COLOR_BLACK);
		cct_showch(M_COORD_X + 8, M_COORD_Y + i, ' ', COLOR_BLACK);
	}
}

/***************************************************************************
  �������ƣ�I_print
  ��    �ܣ���ӡһ����ĸI
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::I_print()
{
	cct_showstr(I_COORD_X, I_COORD_Y, "     ", COLOR_BLACK);
	for (int i = 0; i < 3; i++)
		cct_showch(I_COORD_X + 2, I_COORD_Y + i + 1, ' ', COLOR_BLACK);
	cct_showstr(I_COORD_X, I_COORD_Y + 4, "     ", COLOR_BLACK);
}

/***************************************************************************
  �������ƣ�N_print
  ��    �ܣ���ӡһ����ĸN
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::N_print()
{
	for (int i = 0; i < 5; i++) {
		cct_showch(N_COORD_X, N_COORD_Y + i, ' ', COLOR_BLACK);
		cct_showch(N_COORD_X + i + 1, N_COORD_Y + i, ' ', COLOR_BLACK);
		cct_showch(N_COORD_X + 6, N_COORD_Y + i, ' ', COLOR_BLACK);
	}
}

/***************************************************************************
  �������ƣ�E_print
  ��    �ܣ���ӡһ����ĸE
  ���������const int E_num����ĸ�ı�ţ�ֻ����
  �� �� ֵ����
  ˵    ������Ҫ�����ֹһ����ĸE���ʸ��ݱ���ڲ�ͬλ�������ĸE
***************************************************************************/
void cover::E_print(const int E_num)
{
	int x = 0, y = 0;
	int bg_color = COLOR_BLACK;

	switch (E_num) {  /*����Ҫ��ӡ����ĸE�����������ɫ*/
	case 1:
		x = E_COORD_X1, y = E_COORD_Y1;
		break;
	case 2:
		x = E_COORD_X2, y = E_COORD_Y2;
		bg_color = E_COLOR2;
		break;
	case 3:
		x = E_COORD_X3, y = E_COORD_Y3;
		bg_color = E_COLOR3;
		break;
	case 4:
		x = E_COORD_X4, y = E_COORD_Y4;
		bg_color = E_COLOR4;
		break;
	}

	/*�������õ��������ɫ��ӡ��ĸ*/
	cct_showstr(x, y, "     ", bg_color);
	cct_showch(x, y + 1, ' ', bg_color);
	cct_showstr(x, y + 2, "     ", bg_color);
	cct_showch(x, y + 3, ' ', bg_color);
	cct_showstr(x, y + 4, "     ", bg_color);
}

/***************************************************************************
  �������ƣ�S_print
  ��    �ܣ���ӡһ����ĸS
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::S_print()
{
	cct_showstr(S_COORD_X, S_COORD_Y, "     ", S_COLOR);
	cct_showch(S_COORD_X, S_COORD_Y + 1, ' ', S_COLOR);
	cct_showstr(S_COORD_X, S_COORD_Y + 2, "     ", S_COLOR);
	cct_showch(S_COORD_X + 4, S_COORD_Y + 3, ' ', S_COLOR);
	cct_showstr(S_COORD_X, S_COORD_Y + 4, "     ", S_COLOR);
}

/***************************************************************************
  �������ƣ�W_print
  ��    �ܣ���ӡһ����ĸW
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::W_print()
{
	int i, j;

	for (i = 0; i < 2; i++)
		for (j = 0; j < 3; j++)
			cct_showch(W_COORD_X + 4 * j, W_COORD_Y + i, ' ', W_COLOR);

	for (i = 0; i < 2; i++)
		for (j = 0; j < 4; j++)
			cct_showch(W_COORD_X + 2 * j + 1, W_COORD_Y + 2 + i, ' ', W_COLOR);

	for (i = 0; i < 2; i++)
		cct_showch(W_COORD_X + 4 * i + 2, W_COORD_Y + 4, ' ', W_COLOR);
}

/***************************************************************************
  �������ƣ�P_print
  ��    �ܣ���ӡһ����ĸP
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover::P_print()
{
	cct_showstr(P_COORD_X, P_COORD_Y, "     ", P_COLOR);
	cct_showch(P_COORD_X, P_COORD_Y + 1, ' ', P_COLOR);
	cct_showch(P_COORD_X + 4, P_COORD_Y + 1, ' ', P_COLOR);
	cct_showstr(P_COORD_X, P_COORD_Y + 2, "     ", P_COLOR);
	cct_showch(P_COORD_X, P_COORD_Y + 3, ' ', P_COLOR);
	cct_showch(P_COORD_X, P_COORD_Y + 4, ' ', P_COLOR);
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
  �������ƣ�bomb_print
  ��    �ܣ���ӡ����
  �����������
  �� �� ֵ����
  ˵    ����1���������ڱ��⻭���ϴ�ӡ���ף���ǿ����Ч��
            2����ӡ��ͬʱ��ÿ�����׵�λ����Ϣ����ڶ�Ӧ�Ľṹ����
***************************************************************************/
void cover::bomb_print()
{
	for (int i = 0; i < 20; i++) {
		int x = rand() % 76 + 2;  /*���ȡ������*/
		int y = rand() % 16 + 1;  /*���ȡ������*/

		bomb_coord[i].x = x;  /*��¼��ǰ������*/
		bomb_coord[i].y = y;  /*��¼��ǰ������*/

		cct_showch(x, y, '*', COLOR_WHITE, COLOR_BLACK);  /*��ӡ����*/
	}
}

/***************************************************************************
  �������ƣ�bomb_reprint
  ��    �ܣ����ݵ�һ�δ�ӡʱ�洢��������Ϣ�����´�ӡ����
  �����������
  �� �� ֵ����
  ˵    �����������ڱ��⻭���ϴ�ӡ���ף���ǿ����Ч��
***************************************************************************/
void cover::bomb_reprint()
{
	for (int i = 0; i < 20; i++)
		cct_showch(bomb_coord[i].x, bomb_coord[i].y, '*', COLOR_WHITE, COLOR_BLACK);
}

/***************************************************************************
  �������ƣ�button_reprint
  ��    �ܣ����´�ӡ���⻭���е�һЩ����
  �����������
  �� �� ֵ����
  ˵    �������ػ�������������
***************************************************************************/
void cover::button_reprint()
{
	button_easy.act(DEFAULT);    /*�ػ����򵥡���*/
	button_medium.act(DEFAULT);  /*�ػ����еȡ���*/
	button_hard.act(DEFAULT);    /*�ػ������ѡ���*/
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
	int i;

	/*1����ӡ���⻭�汳��*/
	cct_showstr(0, 0, "��������������������������������������������������������������������������������", COLOR_WHITE, COLOR_BLACK);
	for (i = 0; i < COVER_WIDTH - 2; i++) {
		cct_showstr(0, i + 1, "��                                                                            ��", COLOR_WHITE, COLOR_BLACK);
		Sleep(10);
	}
	cct_showstr(0, COVER_WIDTH - 1, "��������������������������������������������������������������������������������", COLOR_WHITE, COLOR_BLACK);

	/*2����ӡ���׺�������ĸ*/
	bomb_print();
	PRINT_ALL_LETTERS
	
	/*3����ӡ����*/
	Sleep(100);
	button_easy.act(DEFAULT);
	button_medium.act(DEFAULT);
	button_hard.act(DEFAULT);
	button_diy.act(DEFAULT);
	button_options.act(DEFAULT);
	button_quit.act(DEFAULT);
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

	if (X >= EASY_COORD_X && X <= EASY_COORD_X + 11 && Y >= EASY_COORD_Y && Y <= EASY_COORD_Y + 2)              /*�ж��Ƿ��ڡ��򵥡�����*/
		p[0] = true;
	if (X >= MEDIUM_COORD_X && X <= MEDIUM_COORD_X + 11 && Y >= MEDIUM_COORD_Y && Y <= MEDIUM_COORD_Y + 2)      /*�ж��Ƿ��ڡ��еȡ�����*/
		p[1] = true;
	if (X >= HARD_COORD_X && X <= HARD_COORD_X + 11 && Y >= HARD_COORD_Y && Y <= HARD_COORD_Y + 2)              /*�ж��Ƿ��ڡ����ѡ�����*/
		p[2] = true;
	if (X >= DIY_COORD_X && X <= DIY_COORD_X + 11 && Y >= DIY_COORD_Y && Y <= DIY_COORD_Y + 2)                  /*�ж��Ƿ��ڡ��Զ��塱����*/
		p[3] = true;
	if (X >= OPTIONS_COORD_X && X <= OPTIONS_COORD_X + 11 && Y >= OPTIONS_COORD_Y && Y <= OPTIONS_COORD_Y + 2)  /*�ж��Ƿ��ڡ����á�����*/
		p[4] = true;
	if (X >= QUIT_COORD_X && X <= QUIT_COORD_X + 11 && Y >= QUIT_COORD_Y && Y <= QUIT_COORD_Y + 2)              /*�ж��Ƿ��ڡ��˳�������*/
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
		button_easy.act(DEFAULT);     /*���򵥡���ȡ������*/
		break;
	case 2:
		button_medium.act(DEFAULT);   /*���еȡ���ȡ������*/
		break;
	case 3:
		button_hard.act(DEFAULT);     /*�����ѡ���ȡ������*/
		break;
	case 4:
		button_diy.act(DEFAULT);      /*���Զ��塱��ȡ������*/
		break;
	case 5:
		button_options.act(DEFAULT);  /*�����á���ȡ������*/
		break;
	case 6:
		button_quit.act(DEFAULT);     /*���˳�����ȡ������*/
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
		button_easy.act(ACTIVATE);     /*���򵥡������ø���*/
		break;
	case 2:
		button_medium.act(ACTIVATE);   /*���еȡ������ø���*/
		break;
	case 3:
		button_hard.act(ACTIVATE);     /*�����ѡ������ø���*/
		break;
	case 4:
		button_diy.act(ACTIVATE);      /*���Զ��塱�����ø���*/
		break;
	case 5:
		button_options.act(ACTIVATE);  /*�����á������ø���*/
		break;
	case 6:
		button_quit.act(ACTIVATE);     /*���˳��������ø���*/
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
				result = COVER_EASY, loop = 0;     /*ȡ����ֵ������ѭ��*/
				break;
			case 2:
				result = COVER_MEDIUM, loop = 0;   /*ȡ����ֵ������ѭ��*/
				break;
			case 3:
				result = COVER_HARD, loop = 0;     /*ȡ����ֵ������ѭ��*/
				break;
			case 4:
				result = COVER_DIY, loop = 0;      /*ȡ����ֵ������ѭ��*/
				break;
			case 5:
				result = COVER_OPTIONS, loop = 0;  /*ȡ����ֵ������ѭ��*/
				break;
			case 6:
				result = COVER_QUIT, loop = 0;     /*ȡ����ֵ������ѭ��*/
				break;
			}
		}
	}

	cct_disable_mouse();	//�������
	return result;
}