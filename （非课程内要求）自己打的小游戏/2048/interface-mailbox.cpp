#include"90-b3.h"

/***************************************************************************
  �������ƣ�set_button_type
  ��    �ܣ���������������
  �����������
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void game_mailbox::set_button_type()
{
	button_yes.set_type(GMMB_YES);        /*���ǡ�����������*/
	button_no.set_type(GMMB_NO);          /*���񡱼���������*/
	button_sure.set_type(GMMB_SURE);      /*��ȷ��������������*/
	button_one.set_type(GMMB_ONE);        /*��1������������*/
	button_two.set_type(GMMB_TWO);        /*��2������������*/
	button_three.set_type(GMMB_THREE);    /*��3������������*/
	button_four.set_type(GMMB_FOUR);      /*��4������������*/
	button_cancel.set_type(GMMB_CANCEL);  /*��ȡ��������������*/
	switch_one[0].set_type(GMMB_SW11);    /*����1����1��������*/
	switch_one[1].set_type(GMMB_SW12);    /*����1����2��������*/
	switch_two[0].set_type(GMMB_SW21);    /*����2����1��������*/
	switch_two[1].set_type(GMMB_SW22);    /*����2����2��������*/
}

/***************************************************************************
  �������ƣ�set_button_coord
  ��    �ܣ����������긳ֵ
  �����������
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void game_mailbox::set_button_coord()
{
	button_yes.set_coord(GMYES_COORD_X, GMYES_COORD_Y);           /*���ǡ������긳ֵ*/
	button_no.set_coord(GMNO_COORD_X, GMNO_COORD_Y);              /*���񡱼����긳ֵ*/
	button_sure.set_coord(GMSURE_COORD_X, GMSURE_COORD_Y);        /*��ȷ���������긳ֵ*/
	button_one.set_coord(GMONE_COORD_X, GMONE_COORD_Y);           /*��1�������긳ֵ*/
	button_two.set_coord(GMTWO_COORD_X, GMTWO_COORD_Y);           /*��2�������긳ֵ*/
	button_three.set_coord(GMTHREE_COORD_X, GMTHREE_COORD_Y);     /*��3�������긳ֵ*/
	button_four.set_coord(GMFOUR_COORD_X, GMFOUR_COORD_Y);        /*��4�������긳ֵ*/
	button_cancel.set_coord(GMCANCEL_COORD_X, GMCANCEL_COORD_Y);  /*��ȡ���������긳ֵ*/
	switch_one[0].set_coord(GMSW11_COORD_X, GMSW11_COORD_Y);      /*����1����1���긳ֵ*/
	switch_one[1].set_coord(GMSW12_COORD_X, GMSW12_COORD_Y);      /*����1����2���긳ֵ*/
	switch_two[0].set_coord(GMSW21_COORD_X, GMSW21_COORD_Y);      /*����2����1���긳ֵ*/
	switch_two[1].set_coord(GMSW22_COORD_X, GMSW22_COORD_Y);      /*����2����2���긳ֵ*/
}

/***************************************************************************
  �������ƣ�print
  ��    �ܣ���ӡ��Ϸ�ڶԻ���
  ���������const int button_mode��������ʽ��ֻ����
			const char* prompt1����ʾ��1��ֻ����Ĭ��Ϊ��ָ�룩
			const char* prompt2����ʾ��2��ֻ����Ĭ��Ϊ��ָ�룩
			const char* prompt3����ʾ��3��ֻ����Ĭ��Ϊ��ָ�룩
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void game_mailbox::print(const int button_mode, const char* prompt1, const char* prompt2, const char* prompt3)
{
	IF_GMMB = button_mode;       /*���ݶԻ��򰴼����������Ǳ�������־�Ի����ѳ���*/

	/*1����ӡ�Ի�������*/
	cct_showstr(GMMB_COORD_X, GMMB_COORD_Y, "��������������������������", GMMB_BG_COLOR, GMMB_FG_COLOR);
	cct_showstr(GMMB_COORD_X - 2, GMMB_COORD_Y + 1, "����                      ����", GMMB_BG_COLOR, GMMB_FG_COLOR);
	for (int i = 0; i < GMMB_WIDTH - 4; i++) {
		cct_showstr(GMMB_COORD_X - 2, GMMB_COORD_Y + 2 + i, "��                          ��", GMMB_BG_COLOR, GMMB_FG_COLOR);
	}
	cct_showstr(GMMB_COORD_X - 2, GMMB_COORD_Y + GMMB_WIDTH - 2, "����                      ����", GMMB_BG_COLOR, GMMB_FG_COLOR);
	cct_showstr(GMMB_COORD_X, GMMB_COORD_Y + GMMB_WIDTH - 1, "��������������������������", GMMB_BG_COLOR, GMMB_FG_COLOR);

	/*2����ӡ�Ի�����ʾ��*/
	cct_showstr(GMPROM_COORD_X, GMPROM_COORD_Y, prompt1, GMMB_BG_COLOR, COLOR_BLACK);
	cct_showstr(GMPROM_COORD_X - 2, GMPROM_COORD_Y + 1, prompt2, GMMB_BG_COLOR, COLOR_BLACK);
	cct_showstr(GMPROM_COORD_X - 2, GMPROM_COORD_Y + 2, prompt3, GMMB_BG_COLOR, COLOR_BLACK);

	/*3�����ݰ�����ʽ��ӡ�Ի��򰴼�*/
	if (button_mode == BUTTON_TWO) {  /*˫��ʽ*/
		button_yes.act(DEFAULT);  /*��ӡ���ǡ���*/
		button_no.act(DEFAULT);   /*��ӡ���񡱼�*/
	}

	else if (button_mode == BUTTON_ONE)  /*����ʽ*/
		button_sure.act(DEFAULT);  /*��ӡ��ȷ������*/

	else if (button_mode == BUTTON_FIVE) {  /*���ʽ*/
		button_one.act(DEFAULT);     /*��ӡ��1����*/
		button_two.act(DEFAULT);     /*��ӡ��2����*/
		button_three.act(DEFAULT);   /*��ӡ��3����*/
		button_four.act(DEFAULT);    /*��ӡ��4����*/
		button_cancel.act(DEFAULT);  /*��ӡ��ȡ������*/
	}

	else if (button_mode == BUTTON_SWITCH) {  /*����ʽ*/
		cct_showstr(GMSW11_COORD_X, GMSW11_COORD_Y + 1, "       ", COLOR_HCYAN);  /*��ӡ����1�Ļ�����*/
		cct_showstr(GMSW21_COORD_X, GMSW21_COORD_Y + 1, "       ", COLOR_HCYAN);  /*��ӡ����2�Ļ�����*/
		button_sure.act(DEFAULT);  /*��ӡ��ȷ������*/

		if (__GAME.if_blink) {  /*��ӡ����1����1�Լ���ǰ״̬*/
			cct_showstr(GMSW1P_COORD_X, GMSW1P_COORD_Y, "��", GMMB_BG_COLOR, GMMB_FG_COLOR);
			switch_one[0].act(DEFAULT);
		}
		else {  /*��ӡ����1����2�Լ���ǰ״̬*/
			cct_showstr(GMSW1P_COORD_X, GMSW1P_COORD_Y, "��", GMMB_BG_COLOR, GMMB_FG_COLOR);
			switch_one[1].act(DEFAULT);
		}
		if (__GAME.if_tips) {  /*��ӡ����2����1�Լ���ǰ״̬*/
			cct_showstr(GMSW2P_COORD_X, GMSW2P_COORD_Y, "��", GMMB_BG_COLOR, GMMB_FG_COLOR);
			switch_two[0].act(DEFAULT);
		}
		else {  /*��ӡ����2����2�Լ���ǰ״̬*/
			cct_showstr(GMSW2P_COORD_X, GMSW2P_COORD_Y, "��", GMMB_BG_COLOR, GMMB_FG_COLOR);
			switch_two[1].act(DEFAULT);
		}
	}
}

/***************************************************************************
  �������ƣ�mouse_if_button
  ��    �ܣ��ж����λ���Ƿ���ĳһ������
  ���������const int X�����λ�ú����ֻ꣨����
			const int Y�����λ�������ֻ꣨����
  �� �� ֵ��int���������һ������
  ˵    ������
***************************************************************************/
int game_mailbox::mouse_if_button(const int X, const int Y)
{
	int ret = 0;  /*����ֵ*/
	bool p[GMMB_BUTTON_NUM];
	for (int i = 0; i < GMMB_BUTTON_NUM; i++)
		p[i] = false;

	if ((X == GMYES_COORD_X || X == GMYES_COORD_X + 1) && (Y == GMYES_COORD_Y || Y == GMYES_COORD_Y + 1))            /*�ж��Ƿ��ڡ��ǡ�����*/
		p[0] = true;
	if ((X == GMNO_COORD_X || X == GMNO_COORD_X + 1) && (Y == GMNO_COORD_Y || Y == GMNO_COORD_Y + 1))                /*�ж��Ƿ��ڡ��񡱼���*/
		p[1] = true;
	if (X >= GMSURE_COORD_X && X <= GMSURE_COORD_X + 3 && (Y == GMSURE_COORD_Y || Y == GMSURE_COORD_Y + 1))          /*�ж��Ƿ��ڡ�ȷ��������*/
		p[2] = true;
	if ((X == GMONE_COORD_X || X == GMONE_COORD_X + 1) && (Y == GMONE_COORD_Y || Y == GMONE_COORD_Y + 1))            /*�ж��Ƿ��ڡ�1������*/
		p[3] = true;
	if ((X == GMTWO_COORD_X || X == GMTWO_COORD_X + 1) && (Y == GMTWO_COORD_Y || Y == GMTWO_COORD_Y + 1))            /*�ж��Ƿ��ڡ�2������*/
		p[4] = true;
	if ((X == GMTHREE_COORD_X || X == GMTHREE_COORD_X + 1) && (Y == GMTHREE_COORD_Y || Y == GMTHREE_COORD_Y + 1))    /*�ж��Ƿ��ڡ�3������*/
		p[5] = true;
	if ((X == GMFOUR_COORD_X || X == GMFOUR_COORD_X + 1) && (Y == GMFOUR_COORD_Y || Y == GMFOUR_COORD_Y + 1))        /*�ж��Ƿ��ڡ�4������*/
		p[6] = true;
	if (X >= GMCANCEL_COORD_X && X <= GMCANCEL_COORD_X + 3 && (Y == GMCANCEL_COORD_Y || Y == GMCANCEL_COORD_Y + 1))  /*�ж��Ƿ��ڡ�ȡ��������*/
		p[7] = true;
	if (X == GMSW11_COORD_X && (Y == GMSW11_COORD_Y || Y == GMSW11_COORD_Y + 1))  /*�ж��Ƿ��ڿ���1����1��*/
		p[8] = true;
	if (X == GMSW12_COORD_X && (Y == GMSW12_COORD_Y || Y == GMSW12_COORD_Y + 1))  /*�ж��Ƿ��ڿ���1����2��*/
		p[9] = true;
	if (X == GMSW21_COORD_X && (Y == GMSW21_COORD_Y || Y == GMSW21_COORD_Y + 1))  /*�ж��Ƿ��ڿ���2����1��*/
		p[10] = true;
	if (X == GMSW22_COORD_X && (Y == GMSW22_COORD_Y || Y == GMSW22_COORD_Y + 1))  /*�ж��Ƿ��ڿ���2����2��*/
		p[11] = true;

	/*������λ�õ�����������沢���밴����ʽ��Ӧ����ȡ��Ӧ����ֵ��������*/
	switch (IF_GMMB) {
	case BUTTON_TWO:
		for (int i = 0; i < 2; i++) {  /*˫��ʽ�����ļ��*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_ONE:
		for (int i = 2; i < 3; i++) {  /*����ʽ�����ļ��*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_FIVE:
		for (int i = 3; i < 8; i++) {  /*���ʽ�����ļ��*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_SWITCH:                /*����ʽ�����ļ��*/
		if (p[2])
			ret = 3;
		if (__GAME.if_blink && p[8])
			ret = 9;
		else if (!__GAME.if_blink && p[9])
			ret = 10;
		if (__GAME.if_tips && p[10])
			ret = 11;
		else if (!__GAME.if_tips && p[11])
			ret = 12;
		break;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�keyboard_if_button
  ��    �ܣ��жϼ��̰��µİ����Ƿ�Ϊ�Ի����ڵ�ĳһ����
  ���������const int keycode�����루ֻ����
  �� �� ֵ��int�����̰�������һ����
  ˵    ������
***************************************************************************/
int game_mailbox::keyboard_if_button(const int keycode)
{
	int ret = 0;

	if (keycode == 'Y' || keycode == 'y')         /*�ж��Ƿ����ˡ��ǡ���*/
		ret = 1;
	else if (keycode == 'N' || keycode == 'n')    /*�ж��Ƿ����ˡ��񡱼�*/
		ret = 2;
	else if (keycode == '\n' || keycode == '\r')  /*�ж��Ƿ����ˡ�ȷ������*/
		ret = 3;
	else if (keycode >= '1' && keycode <= '4')    /*�ж��Ƿ�����ĳ�����ּ�*/
		ret = keycode - '0' + 3;
	else if (keycode == 'C' || keycode == 'c')    /*�ж��Ƿ����ˡ�ȡ������*/
		ret = 8;

	return ret;
}

/***************************************************************************
  �������ƣ�selective_default
  ��    �ܣ�ѡ���Ե�Ϊĳһ����ȡ������
  ���������const int selection������ѡ��ֻ����
  �� �� ֵ����
  ˵    ����1����ѡ��ΪDEFAULT_ALLʱ��ͨ���ݹ����ȡ�����а����ĸ���
			2��ֻ�е�����ѡ���밴��ģʽ��Ӧʱ�Ž��в���
***************************************************************************/
void game_mailbox::selective_default(const int selection)
{
	switch (selection) {
	case 1:
		if (IF_GMMB == BUTTON_TWO)   /*���ǡ���ȡ������*/
			button_yes.act(DEFAULT);
		break;
	case 2:
		if (IF_GMMB == BUTTON_TWO)   /*���񡱼�ȡ������*/
			button_no.act(DEFAULT);
		break;
	case 3:
		if (IF_GMMB == BUTTON_ONE || IF_GMMB == BUTTON_SWITCH)   /*��ȷ������ȡ������*/
			button_sure.act(DEFAULT);
		break;
	case 4:
		if (IF_GMMB == BUTTON_FIVE)  /*��1����ȡ������*/
			button_one.act(DEFAULT);
		break;
	case 5:
		if (IF_GMMB == BUTTON_FIVE)  /*��2����ȡ������*/
			button_two.act(DEFAULT);
		break;
	case 6:
		if (IF_GMMB == BUTTON_FIVE)  /*��3����ȡ������*/
			button_three.act(DEFAULT);
		break;
	case 7:
		if (IF_GMMB == BUTTON_FIVE)  /*��4����ȡ������*/
			button_four.act(DEFAULT);
		break;
	case 8:
		if (IF_GMMB == BUTTON_FIVE)  /*��ȡ������ȡ������*/
			button_cancel.act(DEFAULT);
		break;
	case 9:
		if (IF_GMMB == BUTTON_SWITCH && __GAME.if_blink)   /*����1����1ȡ������*/
			switch_one[0].act(DEFAULT);
		break;
	case 10:
		if (IF_GMMB == BUTTON_SWITCH && !__GAME.if_blink)  /*����1����2ȡ������*/
			switch_one[1].act(DEFAULT);
		break;
	case 11:
		if (IF_GMMB == BUTTON_SWITCH && __GAME.if_tips)    /*����2����1ȡ������*/
			switch_two[0].act(DEFAULT);
		break;
	case 12:
		if (IF_GMMB == BUTTON_SWITCH && !__GAME.if_tips)   /*����2����2ȡ������*/
			switch_two[1].act(DEFAULT);
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < GMMB_BUTTON_NUM; i++)  /*���а���ȡ������*/
			selective_default(i + 1);
		break;
	}
}

/***************************************************************************
  �������ƣ�selective_activate
  ��    �ܣ�ѡ���Ե�Ϊĳһ�������ø���
  ���������const int selection������ѡ��ֻ����
  �� �� ֵ����
  ˵    ����ֻ�е�����ѡ���밴��ģʽ��Ӧʱ�Ž��в���
***************************************************************************/
void game_mailbox::selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		if (IF_GMMB == BUTTON_TWO)   /*���ǡ������ø���*/
			button_yes.act(ACTIVATE);
		break;
	case 2:
		if (IF_GMMB == BUTTON_TWO)   /*���񡱼����ø���*/
			button_no.act(ACTIVATE);
		break;
	case 3:
		if (IF_GMMB == BUTTON_ONE || IF_GMMB == BUTTON_SWITCH)   /*��ȷ���������ø���*/
			button_sure.act(ACTIVATE);
		break;
	case 4:
		if (IF_GMMB == BUTTON_FIVE)  /*��1�������ø���*/
			button_one.act(ACTIVATE);
		break;
	case 5:
		if (IF_GMMB == BUTTON_FIVE)  /*��2�������ø���*/
			button_two.act(ACTIVATE);
		break;
	case 6:
		if (IF_GMMB == BUTTON_FIVE)  /*��3�������ø���*/
			button_three.act(ACTIVATE);
		break;
	case 7:
		if (IF_GMMB == BUTTON_FIVE)  /*��4�������ø���*/
			button_four.act(ACTIVATE);
		break;
	case 8:
		if (IF_GMMB == BUTTON_FIVE)  /*��ȡ���������ø���*/
			button_cancel.act(ACTIVATE);
		break;
	case 9:
		if (IF_GMMB == BUTTON_SWITCH && __GAME.if_blink)   /*����1����1���ø���*/
			switch_one[0].act(ACTIVATE);
		break;
	case 10:
		if (IF_GMMB == BUTTON_SWITCH && !__GAME.if_blink)  /*����1����2���ø���*/
			switch_one[1].act(ACTIVATE);
		break;
	case 11:
		if (IF_GMMB == BUTTON_SWITCH && __GAME.if_tips)    /*����2����1���ø���*/
			switch_two[0].act(ACTIVATE);
		break;
	case 12:
		if (IF_GMMB == BUTTON_SWITCH && !__GAME.if_tips)   /*����2����2���ø���*/
			switch_two[1].act(ACTIVATE);
		break;
	}
}

/***************************************************************************
  �������ƣ�control
  ��    �ܣ��ü�������Ϸ�ڶԻ����ڽ��в���
  �����������
  �� �� ֵ��int�����еĲ���
  ˵    ������
***************************************************************************/
int game_mailbox::control()
{
	int X = 0, Y = 0;  /*�������꣬��ʼ��Ϊ��*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*�����ķ���ֵ*/

	cct_enable_mouse();  /*�������*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*�����/����*/
		selective_default(DEFAULT_ALL);  /*ȡ���Ի������а����ĸ���*/

		int RET1 = mouse_if_button(X, Y);         /*�жϴ�ʱ����λ���Ƿ���ĳ��������*/
		int RET2 = keyboard_if_button(keycode1);  /*�жϴ�ʱ���̰��µİ�ť�Ƿ�Ϊĳ������*/
		selective_activate(RET1);  /*�������ĳ�������У�����Ӧ�İ������ø���*/

		/*1�������ص�������¼����Ұ������*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {

			switch (IF_GMMB) {  /*���ݶ�Ӧ�ĶԻ���״̬���в��������ⰴ��֮�以�����*/
			case BUTTON_TWO:
				if (RET1 >= 1 && RET1 <= 2) {
					selective_default(RET1);       /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_GMMB = 0;         /*�Ի���״̬����*/
				}

				result = RET1 + GMMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			case BUTTON_ONE:
				if (RET1 == 3) {
					selective_default(RET1);       /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_GMMB = 0;         /*�Ի���״̬����*/
				}

				result = RET1 + GMMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			case BUTTON_FIVE:
				if (RET1 >= 4 && RET1 <= 8) {
					selective_default(RET1);       /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_GMMB = 0;         /*�Ի���״̬����*/
				}

				result = RET1 + GMMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			case BUTTON_SWITCH:
				if (RET1 == 3 || (RET1 >= 9 && RET1 <= 12)) {
					selective_default(RET1);       /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0;
				}

				if (RET1 == 3)                     /*������ȷ���������Ի���״̬����*/
					IF_GMMB = 0;
				result = RET1 + GMMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			}
		}

		/*2�������ص��Ǽ����¼�*/
		else if (ret == CCT_KEYBOARD_EVENT) {
			switch (IF_GMMB) {    /*���ݶ�Ӧ�ĶԻ���״̬���в��������ⰴ��֮�以�����*/
			case BUTTON_TWO:
				if (RET2 >= 1 && RET2 <= 2) {
					selective_activate(RET2);      /*���ø�������ʱ��ȡ��������Ӫ�찴��Ч��*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_GMMB = 0;         /*�Ի���״̬����*/
				}

				result = RET2 + GMMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			case BUTTON_ONE:
				if (RET2 == 3) {
					selective_activate(RET2);      /*���ø�������ʱ��ȡ��������Ӫ�찴��Ч��*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_GMMB = 0;         /*�Ի���״̬����*/
				}

				result = RET2 + GMMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			case BUTTON_FIVE:
				if (RET2 >= 4 && RET2 <= 8) {
					selective_activate(RET2);      /*���ø�������ʱ��ȡ��������Ӫ�찴��Ч��*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_GMMB = 0;         /*�Ի���״̬����*/
				}

				result = RET2 + GMMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			}
		}
	}

	cct_disable_mouse();	//�������
	return result;
}

/***************************************************************************
  �������ƣ�erase
  ��    �ܣ��ػ���Ϸ��壬�ﵽ�����Ի����Ч��
  �����������
  �� �� ֵ����
  ˵    �����������ػ��˶Ի����Ӧ���Ǽ����Լ�����ɫ��
***************************************************************************/
void game_mailbox::erase()
{
	cct_gotoxy(0, GMMB_COORD_Y);  /*�ƶ����*/
	cct_setcolor();            /*������ɫ*/

	for (int Y = GMMB_COORD_Y; Y <= GMMB_COORD_Y + GMMB_WIDTH - 1; Y++)/*�����ػ�������*/
		__GAME.gameboard.chessboard_multiple_lines(Y, false);  /*�����ͬ��ʽ��ÿһ��*/

	__GAME.gameboard.block_multiple_print();  /*�ػ�����ɫ��*/
}

/***************************************************************************
  �������ƣ�options
  ��    �ܣ������Ϸ�ڶԻ����еĸ�������
  ���������const int options�����ã�ֻ����
  �� �� ֵ����
  ˵    �������������ݶ�Ӧ���ã��ȸı䲼��ֵ������ԭ�����������ǰ״̬��Ȼ�����ػ�ԭ����
***************************************************************************/
void game_mailbox::options(const int options)
{
	switch (options) {
	case GMMB_RET_BLINK_OFF:  /*�ر�ɫ����˸*/
		__GAME.if_blink = false;
		cct_showch(GMSW11_COORD_X, GMSW11_COORD_Y, ' ', GMMB_BG_COLOR);
		cct_showch(GMSW11_COORD_X, GMSW11_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(GMSW1P_COORD_X, GMSW1P_COORD_Y, "��", GMMB_BG_COLOR, GMMB_FG_COLOR);
		switch_one[1].act(DEFAULT);
		break;
	case GMMB_RET_BLINK_ON:   /*����ɫ����˸*/
		__GAME.if_blink = true;
		cct_showch(GMSW12_COORD_X, GMSW12_COORD_Y, ' ', GMMB_BG_COLOR);
		cct_showch(GMSW12_COORD_X, GMSW12_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(GMSW1P_COORD_X, GMSW1P_COORD_Y, "��", GMMB_BG_COLOR, GMMB_FG_COLOR);
		switch_one[0].act(DEFAULT);
		break;
	case GMMB_RET_TIPS_OFF:   /*�ر���ʾ*/
		__GAME.if_tips = false;
		cct_showch(GMSW21_COORD_X, GMSW21_COORD_Y, ' ', GMMB_BG_COLOR);
		cct_showch(GMSW21_COORD_X, GMSW21_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(GMSW2P_COORD_X, GMSW2P_COORD_Y, "��", GMMB_BG_COLOR, GMMB_FG_COLOR);
		switch_two[1].act(DEFAULT);
		break;
	case GMMB_RET_TIPS_ON:    /*������ʾ*/
		__GAME.if_tips = true;
		cct_showch(GMSW22_COORD_X, GMSW22_COORD_Y, ' ', GMMB_BG_COLOR);
		cct_showch(GMSW22_COORD_X, GMSW22_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(GMSW2P_COORD_X, GMSW2P_COORD_Y, "��", GMMB_BG_COLOR, GMMB_FG_COLOR);
		switch_two[0].act(DEFAULT);
		break;
	}
}

/***************************************************************************
  �������ƣ�set_button_type
  ��    �ܣ���������������
  �����������
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void cover_mailbox::set_button_type()
{
	button_yes.set_type(CVMB_YES);        /*���ǡ�����������*/
	button_no.set_type(CVMB_NO);          /*���񡱼���������*/
	button_sure.set_type(CVMB_SURE);      /*��ȷ��������������*/
	button_one.set_type(CVMB_ONE);        /*��1������������*/
	button_two.set_type(CVMB_TWO);        /*��2������������*/
	button_three.set_type(CVMB_THREE);    /*��3������������*/
	button_four.set_type(CVMB_FOUR);      /*��4������������*/
	button_cancel.set_type(CVMB_CANCEL);  /*��ȡ��������������*/
	switch_one[0].set_type(CVMB_SW11);    /*����1����1��������*/
	switch_one[1].set_type(CVMB_SW12);    /*����1����2��������*/
	switch_two[0].set_type(CVMB_SW21);    /*����2����1��������*/
	switch_two[1].set_type(CVMB_SW22);    /*����2����2��������*/
}

/***************************************************************************
  �������ƣ�set_button_coord
  ��    �ܣ����������긳ֵ
  �����������
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void cover_mailbox::set_button_coord()
{
	button_yes.set_coord(CVYES_COORD_X, CVYES_COORD_Y);           /*���ǡ������긳ֵ*/
	button_no.set_coord(CVNO_COORD_X, CVNO_COORD_Y);              /*���񡱼����긳ֵ*/
	button_sure.set_coord(CVSURE_COORD_X, CVSURE_COORD_Y);        /*��ȷ���������긳ֵ*/
	button_one.set_coord(CVONE_COORD_X, CVONE_COORD_Y);           /*��1�������긳ֵ*/
	button_two.set_coord(CVTWO_COORD_X, CVTWO_COORD_Y);           /*��2�������긳ֵ*/
	button_three.set_coord(CVTHREE_COORD_X, CVTHREE_COORD_Y);     /*��3�������긳ֵ*/
	button_four.set_coord(CVFOUR_COORD_X, CVFOUR_COORD_Y);        /*��4�������긳ֵ*/
	button_cancel.set_coord(CVCANCEL_COORD_X, CVCANCEL_COORD_Y);  /*��ȡ���������긳ֵ*/
	switch_one[0].set_coord(CVSW11_COORD_X, CVSW11_COORD_Y);      /*����1����1���긳ֵ*/
	switch_one[1].set_coord(CVSW12_COORD_X, CVSW12_COORD_Y);      /*����1����2���긳ֵ*/
	switch_two[0].set_coord(CVSW21_COORD_X, CVSW21_COORD_Y);      /*����2����1���긳ֵ*/
	switch_two[1].set_coord(CVSW22_COORD_X, CVSW22_COORD_Y);      /*����2����2���긳ֵ*/
}

/***************************************************************************
  �������ƣ�print
  ��    �ܣ���ӡ���⻭��Ի���
  ���������const int button_mode��������ʽ��ֻ����
			const char* prompt1����ʾ��1��ֻ����Ĭ��Ϊ��ָ�룩
			const char* prompt2����ʾ��2��ֻ����Ĭ��Ϊ��ָ�룩
			const char* prompt3����ʾ��3��ֻ����Ĭ��Ϊ��ָ�룩
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover_mailbox::print(const int button_mode, const char* prompt1, const char* prompt2, const char* prompt3)
{
	IF_CVMB = button_mode;       /*���ݶԻ��򰴼����������Ǳ�������־�Ի����ѳ���*/

/*1����ӡ�Ի�������*/
	cct_showstr(CVMB_COORD_X, CVMB_COORD_Y, "��������������������������", CVMB_BG_COLOR, CVMB_FG_COLOR);
	cct_showstr(CVMB_COORD_X - 2, CVMB_COORD_Y + 1, "����                      ����", CVMB_BG_COLOR, CVMB_FG_COLOR);
	for (int i = 0; i < CVMB_WIDTH - 4; i++) {
		cct_showstr(CVMB_COORD_X - 2, CVMB_COORD_Y + 2 + i, "��                          ��", CVMB_BG_COLOR, CVMB_FG_COLOR);
	}
	cct_showstr(CVMB_COORD_X - 2, CVMB_COORD_Y + CVMB_WIDTH - 2, "����                      ����", CVMB_BG_COLOR, CVMB_FG_COLOR);
	cct_showstr(CVMB_COORD_X, CVMB_COORD_Y + CVMB_WIDTH - 1, "��������������������������", CVMB_BG_COLOR, CVMB_FG_COLOR);

	/*2����ӡ�Ի�������*/
	cct_showstr(CVPROM_COORD_X, CVPROM_COORD_Y, prompt1, CVMB_BG_COLOR, CVMB_FG_COLOR);
	cct_showstr(CVPROM_COORD_X - 2, CVPROM_COORD_Y + 1, prompt2, CVMB_BG_COLOR, CVMB_FG_COLOR);
	cct_showstr(CVPROM_COORD_X - 2, CVPROM_COORD_Y + 2, prompt3, CVMB_BG_COLOR, CVMB_FG_COLOR);

	/*3�����ݰ�����ʽ��ӡ�Ի���ť*/
	if (button_mode == BUTTON_TWO) {  /*˫��ʽ*/
		button_yes.act(DEFAULT);  /*��ӡ���ǡ���*/
		button_no.act(DEFAULT);   /*��ӡ���񡱼�*/
	}

	else if (button_mode == BUTTON_ONE)  /*����ʽ*/
		button_sure.act(DEFAULT);  /*��ӡ��ȷ������*/

	else if (button_mode == BUTTON_FIVE) {  /*���ʽ*/
		button_one.act(DEFAULT);     /*��ӡ��1����*/
		button_two.act(DEFAULT);     /*��ӡ��2����*/
		button_three.act(DEFAULT);   /*��ӡ��3����*/
		button_four.act(DEFAULT);    /*��ӡ��4����*/
		button_cancel.act(DEFAULT);  /*��ӡ��ȡ������*/
	}

	else if (button_mode == BUTTON_SWITCH) {  /*����ʽ*/
		cct_showstr(CVSW11_COORD_X, CVSW11_COORD_Y + 1, "       ", COLOR_HCYAN);  /*��ӡ����1�Ļ�����*/
		cct_showstr(CVSW21_COORD_X, CVSW21_COORD_Y + 1, "       ", COLOR_HCYAN);  /*��ӡ����2�Ļ�����*/
		button_sure.act(DEFAULT);  /*��ӡ��ȷ������*/

		if (__GAME.if_blink) {  /*��ӡ����1����1�Լ���ǰ״̬*/
			cct_showstr(CVSW1P_COORD_X, CVSW1P_COORD_Y, "��", CVMB_BG_COLOR, CVMB_FG_COLOR);
			switch_one[0].act(DEFAULT);
		}
		else {  /*��ӡ����1����2�Լ���ǰ״̬*/
			cct_showstr(CVSW1P_COORD_X, CVSW1P_COORD_Y, "��", CVMB_BG_COLOR, CVMB_FG_COLOR);
			switch_one[1].act(DEFAULT);
		}
		if (__GAME.if_tips) {  /*��ӡ����2����1�Լ���ǰ״̬*/
			cct_showstr(CVSW2P_COORD_X, CVSW2P_COORD_Y, "��", CVMB_BG_COLOR, CVMB_FG_COLOR);
			switch_two[0].act(DEFAULT);
		}
		else {  /*��ӡ����2����2�Լ���ǰ״̬*/
			cct_showstr(CVSW2P_COORD_X, CVSW2P_COORD_Y, "��", CVMB_BG_COLOR, CVMB_FG_COLOR);
			switch_two[1].act(DEFAULT);
		}
	}
}

/***************************************************************************
  �������ƣ�mouse_if_button
  ��    �ܣ��ж����λ���Ƿ���ĳһ������
  ���������const int X�����λ�ú����ֻ꣨����
			const int Y�����λ�������ֻ꣨����
  �� �� ֵ��int���������һ������
  ˵    ������
***************************************************************************/
int cover_mailbox::mouse_if_button(const int X, const int Y)
{
	int ret = 0;  /*����ֵ*/
	bool p[CVMB_BUTTON_NUM];
	for (int i = 0; i < CVMB_BUTTON_NUM; i++)
		p[i] = false;

	if ((X == CVYES_COORD_X || X == CVYES_COORD_X + 1) && (Y == CVYES_COORD_Y || Y == CVYES_COORD_Y + 1))            /*�ж��Ƿ��ڡ��ǡ�����*/
		p[0] = true;
	if ((X == CVNO_COORD_X || X == CVNO_COORD_X + 1) && (Y == CVNO_COORD_Y || Y == CVNO_COORD_Y + 1))                /*�ж��Ƿ��ڡ��񡱼���*/
		p[1] = true;
	if (X >= CVSURE_COORD_X && X <= CVSURE_COORD_X + 3 && (Y == CVSURE_COORD_Y || Y == CVSURE_COORD_Y + 1))          /*�ж��Ƿ��ڡ�ȷ��������*/
		p[2] = true;
	if ((X == CVONE_COORD_X || X == CVONE_COORD_X + 1) && (Y == CVONE_COORD_Y || Y == CVONE_COORD_Y + 1))            /*�ж��Ƿ��ڡ�1������*/
		p[3] = true;
	if ((X == CVTWO_COORD_X || X == CVTWO_COORD_X + 1) && (Y == CVTWO_COORD_Y || Y == CVTWO_COORD_Y + 1))            /*�ж��Ƿ��ڡ�2������*/
		p[4] = true;
	if ((X == CVTHREE_COORD_X || X == CVTHREE_COORD_X + 1) && (Y == CVTHREE_COORD_Y || Y == CVTHREE_COORD_Y + 1))    /*�ж��Ƿ��ڡ�3������*/
		p[5] = true;
	if ((X == CVFOUR_COORD_X || X == CVFOUR_COORD_X + 1) && (Y == CVFOUR_COORD_Y || Y == CVFOUR_COORD_Y + 1))        /*�ж��Ƿ��ڡ�4������*/
		p[6] = true;
	if (X >= CVCANCEL_COORD_X && X <= CVCANCEL_COORD_X + 3 && (Y == CVCANCEL_COORD_Y || Y == CVCANCEL_COORD_Y + 1))  /*�ж��Ƿ��ڡ�ȡ��������*/
		p[7] = true;
	if (X == CVSW11_COORD_X && (Y == CVSW11_COORD_Y || Y == CVSW11_COORD_Y + 1))  /*�ж��Ƿ��ڿ���1����1��*/
		p[8] = true;
	if (X == CVSW12_COORD_X && (Y == CVSW12_COORD_Y || Y == CVSW12_COORD_Y + 1))  /*�ж��Ƿ��ڿ���1����2��*/
		p[9] = true;
	if (X == CVSW21_COORD_X && (Y == CVSW21_COORD_Y || Y == CVSW21_COORD_Y + 1))  /*�ж��Ƿ��ڿ���2����1��*/
		p[10] = true;
	if (X == CVSW22_COORD_X && (Y == CVSW22_COORD_Y || Y == CVSW22_COORD_Y + 1))  /*�ж��Ƿ��ڿ���2����2��*/
		p[11] = true;

	/*������λ�õ�����������沢���밴����ʽ��Ӧ����ȡ��Ӧ����ֵ��������*/
	switch (IF_CVMB) {
	case BUTTON_TWO:
		for (int i = 0; i < 2; i++) {  /*˫��ʽ�����ļ��*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_ONE:
		for (int i = 2; i < 3; i++) {  /*����ʽ�����ļ��*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_FIVE:
		for (int i = 3; i < 8; i++) {  /*���ʽ�����ļ��*/
			if (p[i]) {
				ret = i + 1;
				break;
			}
		}
		break;
	case BUTTON_SWITCH:                /*����ʽ�����ļ��*/
		if (p[2])
			ret = 3;
		if (__GAME.if_blink && p[8])
			ret = 9;
		else if (!__GAME.if_blink && p[9])
			ret = 10;
		if (__GAME.if_tips && p[10])
			ret = 11;
		else if (!__GAME.if_tips && p[11])
			ret = 12;
		break;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�keyboard_if_button
  ��    �ܣ��жϼ��̰��µİ����Ƿ�Ϊ�Ի����ڵ�ĳһ����
  ���������const int keycode�����루ֻ����
  �� �� ֵ��int�����̰�������һ����
  ˵    ������
***************************************************************************/
int cover_mailbox::keyboard_if_button(const int keycode)
{
	int ret = 0;

	if (keycode == 'Y' || keycode == 'y')         /*�ж��Ƿ����ˡ��ǡ���*/
		ret = 1;
	else if (keycode == 'N' || keycode == 'n')    /*�ж��Ƿ����ˡ��񡱼�*/
		ret = 2;
	else if (keycode == '\n' || keycode == '\r')  /*�ж��Ƿ����ˡ�ȷ������*/
		ret = 3;
	else if (keycode >= '1' && keycode <= '4')    /*�ж��Ƿ�����ĳ�����ּ�*/
		ret = keycode - '0' + 3;
	else if (keycode == 'C' || keycode == 'c')    /*�ж��Ƿ����ˡ�ȡ������*/
		ret = 8;

	return ret;
}

/***************************************************************************
  �������ƣ�selective_default
  ��    �ܣ�ѡ���Ե�Ϊĳһ����ȡ������
  ���������const int selection������ѡ��ֻ����
  �� �� ֵ����
  ˵    ����1����ѡ��ΪDEFAULT_ALLʱ��ͨ���ݹ����ȡ�����а����ĸ���
			2��ֻ�е�����ѡ���밴��ģʽ��Ӧʱ�Ž��в���
***************************************************************************/
void cover_mailbox::selective_default(const int selection)
{
	switch (selection) {
	case 1:
		if (IF_CVMB == BUTTON_TWO)     /*���ǡ���ȡ������*/
			button_yes.act(DEFAULT);
		break;
	case 2:
		if (IF_CVMB == BUTTON_TWO)     /*���񡱼�ȡ������*/
			button_no.act(DEFAULT);
		break;
	case 3:
		if (IF_CVMB == BUTTON_ONE || IF_CVMB == BUTTON_SWITCH)     /*��ȷ������ȡ������*/
			button_sure.act(DEFAULT);
		break;
	case 4:
		if (IF_CVMB == BUTTON_FIVE)    /*��1����ȡ������*/
			button_one.act(DEFAULT);
		break;
	case 5:
		if (IF_CVMB == BUTTON_FIVE)    /*��2����ȡ������*/
			button_two.act(DEFAULT);
		break;
	case 6:
		if (IF_CVMB == BUTTON_FIVE)    /*��3����ȡ������*/
			button_three.act(DEFAULT);
		break;
	case 7:
		if (IF_CVMB == BUTTON_FIVE)    /*��4����ȡ������*/
			button_four.act(DEFAULT);
		break;
	case 8:
		if (IF_CVMB == BUTTON_FIVE)    /*��ȡ������ȡ������*/
			button_cancel.act(DEFAULT);
		break;
	case 9:
		if (IF_CVMB == BUTTON_SWITCH && __GAME.if_blink)   /*����1����1ȡ������*/
			switch_one[0].act(DEFAULT);
		break;
	case 10:
		if (IF_CVMB == BUTTON_SWITCH && !__GAME.if_blink)  /*����1����2ȡ������*/
			switch_one[1].act(DEFAULT);
		break;
	case 11:
		if (IF_CVMB == BUTTON_SWITCH && __GAME.if_tips)    /*����2����1ȡ������*/
			switch_two[0].act(DEFAULT);
		break;
	case 12:
		if (IF_CVMB == BUTTON_SWITCH && !__GAME.if_tips)   /*����2����2ȡ������*/
			switch_two[1].act(DEFAULT);
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < CVMB_BUTTON_NUM; i++)   /*���а���ȡ������*/
			selective_default(i + 1);
		break;
	}
}

/***************************************************************************
  �������ƣ�selective_activate
  ��    �ܣ�ѡ���Ե�Ϊĳһ�������ø���
  ���������const int selection������ѡ��ֻ����
  �� �� ֵ����
  ˵    ����ֻ�е�����ѡ���밴��ģʽ��Ӧʱ�Ž��в���
***************************************************************************/
void cover_mailbox::selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		if (IF_CVMB == BUTTON_TWO)   /*���ǡ������ø���*/
			button_yes.act(ACTIVATE);
		break;
	case 2:
		if (IF_CVMB == BUTTON_TWO)   /*���񡱼����ø���*/
			button_no.act(ACTIVATE);
		break;
	case 3:
		if (IF_CVMB == BUTTON_ONE || IF_CVMB == BUTTON_SWITCH)   /*��ȷ���������ø���*/
			button_sure.act(ACTIVATE);
		break;
	case 4:
		if (IF_CVMB == BUTTON_FIVE)  /*��1�������ø���*/
			button_one.act(ACTIVATE);
		break;
	case 5:
		if (IF_CVMB == BUTTON_FIVE)  /*��2�������ø���*/
			button_two.act(ACTIVATE);
		break;
	case 6:
		if (IF_CVMB == BUTTON_FIVE)  /*��3�������ø���*/
			button_three.act(ACTIVATE);
		break;
	case 7:
		if (IF_CVMB == BUTTON_FIVE)  /*��4�������ø���*/
			button_four.act(ACTIVATE);
		break;
	case 8:
		if (IF_CVMB == BUTTON_FIVE)  /*��ȡ���������ø���*/
			button_cancel.act(ACTIVATE);
		break;
	case 9:
		if (IF_CVMB == BUTTON_SWITCH && __GAME.if_blink)   /*����1����1���ø���*/
			switch_one[0].act(ACTIVATE);
		break;
	case 10:
		if (IF_CVMB == BUTTON_SWITCH && !__GAME.if_blink)  /*����1����2���ø���*/
			switch_one[1].act(ACTIVATE);
		break;
	case 11:
		if (IF_CVMB == BUTTON_SWITCH && __GAME.if_tips)    /*����2����1���ø���*/
			switch_two[0].act(ACTIVATE);
		break;
	case 12:
		if (IF_CVMB == BUTTON_SWITCH && !__GAME.if_tips)   /*����2����2���ø���*/
			switch_two[1].act(ACTIVATE);
		break;
	}
}

/***************************************************************************
  �������ƣ�control
  ��    �ܣ��ü����ڱ��⻭��Ի����ڽ��в���
  �����������
  �� �� ֵ��int�����еĲ���
  ˵    ������
***************************************************************************/
int cover_mailbox::control()
{
	int X = 0, Y = 0;  /*�������꣬��ʼ��Ϊ��*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*�����ķ���ֵ*/

	cct_enable_mouse();  /*�������*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*�����/����*/
		selective_default(DEFAULT_ALL);  /*ȡ���Ի������а����ĸ���*/

		int RET1 = mouse_if_button(X, Y);         /*�жϴ�ʱ����λ���Ƿ���ĳ��������*/
		int RET2 = keyboard_if_button(keycode1);  /*�жϴ�ʱ���̰��µİ�ť�Ƿ�Ϊĳ������*/
		selective_activate(RET1);  /*�������ĳ�������У�����Ӧ�İ������ø���*/

		/*1�������ص�������¼����Ұ������*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {

			switch (IF_CVMB) {  /*���ݶ�Ӧ�ĶԻ���״̬���в��������ⰴ��֮�以�����*/
			case BUTTON_TWO:
				if (RET1 >= 1 && RET1 <= 2) {
					selective_default(RET1);       /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_CVMB = 0;         /*�Ի���״̬����*/
				}

				result = RET1 + CVMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			case BUTTON_ONE:
				if (RET1 == 3) {
					selective_default(RET1);       /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_CVMB = 0;         /*�Ի���״̬����*/
				}

				result = RET1 + CVMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			case BUTTON_FIVE:
				if (RET1 >= 4 && RET1 <= 8) {
					selective_default(RET1);       /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0, IF_CVMB = 0;         /*�Ի���״̬����*/
				}

				result = RET1 + CVMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			case BUTTON_SWITCH:
				if (RET1 == 3 || (RET1 >= 9 && RET1 <= 12)) {
					selective_default(RET1);       /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
					Sleep(100);
					selective_activate(RET1);
					loop = 0;
				}

				if (RET1 == 3)                     /*������ȷ���������Ի���״̬����*/
					IF_CVMB = 0;
				result = RET1 + CVMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			}
		}

		/*2�������ص��Ǽ����¼�*/
		else if (ret == CCT_KEYBOARD_EVENT) {
			switch (IF_CVMB) {
			case BUTTON_TWO:
				if (RET2 >= 1 && RET2 <= 2) {
					selective_activate(RET2);       /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_CVMB = 0;         /*�Ի���״̬����*/
				}

				result = RET2 + CVMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			case BUTTON_ONE:
				if (RET2 == 3) {
					selective_activate(RET2);       /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_CVMB = 0;         /*�Ի���״̬����*/
				}

				result = RET2 + CVMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			case BUTTON_FIVE:
				if (RET2 >= 4 && RET2 <= 8) {
					selective_activate(RET2);       /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
					Sleep(100);
					selective_default(RET2);
					loop = 0, IF_CVMB = 0;         /*�Ի���״̬����*/
				}

				result = RET2 + CVMB_RET_YES - 1;  /*���ݲ���ȡ����ֵ*/
				break;
			}
		}
	}

	cct_disable_mouse();	//�������
	return result;
}

/***************************************************************************
  �������ƣ�erase
  ��    �ܣ��ػ����⻭�棬�ﵽ�����Ի����Ч��
  �����������
  �� �� ֵ����
  ˵    �����������ػ��˶Ի����Ӧ���Ǽ����Լ��������ֺͲ��ֱ���ס�İ���
***************************************************************************/
void cover_mailbox::erase()
{
	int i;

	/*1�����ϱ���*/
	for (i = 0; i < CVMB_WIDTH; i++)
		cct_showstr(0, CVMB_COORD_Y + i, "��                                        ��", COLOR_WHITE, COLOR_BLACK);

	/*2���ػ����֡�2��*/
	cct_showstr(TWO_COORD_X, TWO_COORD_Y, "     ", COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X + 4, TWO_COORD_Y + 1, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X + 4, TWO_COORD_Y + 2, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showstr(TWO_COORD_X, TWO_COORD_Y + 3, "     ", COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X, TWO_COORD_Y + 4, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showch(TWO_COORD_X, TWO_COORD_Y + 5, ' ', COLOR_HRED, COLOR_BLACK);
	cct_showstr(TWO_COORD_X, TWO_COORD_Y + 6, "     ", COLOR_HRED, COLOR_BLACK);

	/*3���ػ����֡�0��*/
	cct_showstr(ZERO_COORD_X, ZERO_COORD_Y, "     ", COLOR_HYELLOW, COLOR_BLACK);
	for (i = 0; i < 5; i++) {
		cct_showch(ZERO_COORD_X, ZERO_COORD_Y + 1 + i, ' ', COLOR_HYELLOW, COLOR_BLACK);
		cct_showch(ZERO_COORD_X + 4, ZERO_COORD_Y + 1 + i, ' ', COLOR_HYELLOW, COLOR_BLACK);
	}
	cct_showstr(ZERO_COORD_X, ZERO_COORD_Y + 6, "     ", COLOR_HYELLOW, COLOR_BLACK);

	/*4���ػ����֡�4��*/
	for (i = 0; i < 3; i++) {
		cct_showch(FOUR_COORD_X, FOUR_COORD_Y + i, ' ', COLOR_HBLUE, COLOR_BLACK);
		cct_showch(FOUR_COORD_X + 4, FOUR_COORD_Y + i, ' ', COLOR_HBLUE, COLOR_BLACK);
	}
	cct_showstr(FOUR_COORD_X, FOUR_COORD_Y + 3, "     ", COLOR_HBLUE, COLOR_BLACK);
	for (i = 0; i < 3; i++) {
		cct_showch(FOUR_COORD_X + 4, FOUR_COORD_Y + 4 + i, ' ', COLOR_HBLUE, COLOR_BLACK);
	}

	/*5���ػ����֡�8��*/
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

	/*6���ػ�����*/
	cct_gotoxy(NEW_COORD_X, NEW_COORD_Y);
	print_cover_button(" ����Ϸ ", COLOR_BLUE, COLOR_HWHITE);
	cct_gotoxy(LOAD_COORD_X, LOAD_COORD_Y);
	print_cover_button("������Ϸ", COLOR_PINK, COLOR_HWHITE);
}

/***************************************************************************
  �������ƣ�options
  ��    �ܣ���ɱ��⻭��Ի����еĸ�������
  ���������const int options�����ã�ֻ����
  �� �� ֵ����
  ˵    �������������ݶ�Ӧ���ã��ȸı䲼��ֵ������ԭ�����������ǰ״̬��Ȼ�����ػ�ԭ����
***************************************************************************/
void cover_mailbox::options(const int options)
{
	switch (options) {
	case CVMB_RET_BLINK_OFF:  /*�ر�ɫ����˸*/
		__GAME.if_blink = false;
		cct_showch(CVSW11_COORD_X, CVSW11_COORD_Y, ' ', CVMB_BG_COLOR);
		cct_showch(CVSW11_COORD_X, CVSW11_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(CVSW1P_COORD_X, CVSW1P_COORD_Y, "��", CVMB_BG_COLOR, CVMB_FG_COLOR);
		switch_one[1].act(DEFAULT);
		break;
	case CVMB_RET_BLINK_ON:   /*����ɫ����˸*/
		__GAME.if_blink = true;
		cct_showch(CVSW12_COORD_X, CVSW12_COORD_Y, ' ', CVMB_BG_COLOR);
		cct_showch(CVSW12_COORD_X, CVSW12_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(CVSW1P_COORD_X, CVSW1P_COORD_Y, "��", CVMB_BG_COLOR, CVMB_FG_COLOR);
		switch_one[0].act(DEFAULT);
		break;
	case CVMB_RET_TIPS_OFF:   /*�ر���ʾ*/
		__GAME.if_tips = false;
		cct_showch(CVSW21_COORD_X, CVSW21_COORD_Y, ' ', CVMB_BG_COLOR);
		cct_showch(CVSW21_COORD_X, CVSW21_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(CVSW2P_COORD_X, CVSW2P_COORD_Y, "��", CVMB_BG_COLOR, CVMB_FG_COLOR);
		switch_two[1].act(DEFAULT);
		break;
	case CVMB_RET_TIPS_ON:    /*������ʾ*/
		__GAME.if_tips = true;
		cct_showch(CVSW22_COORD_X, CVSW22_COORD_Y, ' ', CVMB_BG_COLOR);
		cct_showch(CVSW22_COORD_X, CVSW22_COORD_Y + 1, ' ', COLOR_HCYAN);
		cct_showstr(CVSW2P_COORD_X, CVSW2P_COORD_Y, "��", CVMB_BG_COLOR, CVMB_FG_COLOR);
		switch_two[0].act(DEFAULT);
		break;
	}
}