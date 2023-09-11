#include"90-b3.h"

/***************************************************************************
  �������ƣ�set_button_type
  ��    �ܣ���������������
  �����������
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void keyboard::set_button_type()
{
	button_up.set_type(KB_UP);        /*�ϼ�ͷ����������*/
	button_down.set_type(KB_DOWN);    /*�¼�ͷ����������*/
	button_left.set_type(KB_LEFT);    /*���ͷ����������*/
	button_right.set_type(KB_RIGHT);  /*�Ҽ�ͷ����������*/
	button_q.set_type(KB_Q);          /*���ܼ�Q��������*/
	button_r.set_type(KB_R);          /*���ܼ�R��������*/
	button_s.set_type(KB_S);          /*���ܼ�S��������*/
	button_d.set_type(KB_D);          /*���ܼ�H��������*/
	button_o.set_type(KB_O);          /*���ܼ�O��������*/
}

/***************************************************************************
  �������ƣ�set_button_coord
  ��    �ܣ����������긳ֵ
  �����������
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void keyboard::set_button_coord()
{
	button_up.set_coord(UP_COORD_X, UP_COORD_Y);           /*�ϼ�ͷ�����긳ֵ*/
	button_down.set_coord(DOWN_COORD_X, DOWN_COORD_Y);     /*�¼�ͷ�����긳ֵ*/
	button_left.set_coord(LEFT_COORD_X, LEFT_COORD_Y);     /*���ͷ�����긳ֵ*/
	button_right.set_coord(RIGHT_COORD_X, RIGHT_COORD_Y);  /*�Ҽ�ͷ�����긳ֵ*/
	button_q.set_coord(Q_COORD_X, Q_COORD_Y);  /*���ܼ�Q���긳ֵ*/
	button_r.set_coord(R_COORD_X, R_COORD_Y);  /*���ܼ�R���긳ֵ*/
	button_s.set_coord(S_COORD_X, S_COORD_Y);  /*���ܼ�S���긳ֵ*/
	button_d.set_coord(D_COORD_X, D_COORD_Y);  /*���ܼ�H���긳ֵ*/
	button_o.set_coord(O_COORD_X, O_COORD_Y);  /*���ܼ�O���긳ֵ*/
}

/***************************************************************************
  �������ƣ�print
  ��    �ܣ���ӡС����
  �����������
  �� �� ֵ����
  ˵    ����������ͬʱ��ӡ�������ߣ����ƹ۸�
***************************************************************************/
void keyboard::print()
{
	/*1����ӡ������*/
	cct_showstr(4 * __GAME.order + 4, 4 * __GAME.order + 3, "  ", COLOR_WHITE, COLOR_BLACK);
	cct_showstr(4 * __GAME.order + 2, 4 * __GAME.order + 4, "  ", COLOR_WHITE, COLOR_BLACK);
	cct_showstr(4 * __GAME.order + 4, 4 * __GAME.order + 5, "  ", COLOR_WHITE, COLOR_BLACK);

	/*2����ӡ�������*/
	cct_showstr(KB_COORD_X, KB_COORD_Y, "������������������������", COLOR_WHITE, COLOR_BLACK);
	cct_showstr(KB_COORD_X - 2, KB_COORD_Y + 1, "����                    ����", COLOR_WHITE, COLOR_BLACK);
	for (int i = 0; i < 5; i++) {
		cct_showstr(KB_COORD_X - 2, KB_COORD_Y + 2 + i, "��                        ��", COLOR_WHITE, COLOR_BLACK);
	}
	cct_showstr(KB_COORD_X - 2, KB_COORD_Y + 7, "����                    ����", COLOR_WHITE, COLOR_BLACK);
	cct_showstr(KB_COORD_X, KB_COORD_Y + 8, "������������������������", COLOR_WHITE, COLOR_BLACK);

	/*3����ӡ�����*/
	button_up.act(DEFAULT);     /*��ӡ�ϼ�ͷ*/
	button_down.act(DEFAULT);   /*��ӡ�¼�ͷ*/
	button_left.act(DEFAULT);   /*��ӡ���ͷ*/
	button_right.act(DEFAULT);  /*��ӡ�Ҽ�ͷ*/

	/*4����ӡ�汾������*/
	cct_showstr(KBVER_COORD_X, KBVER_COORD_Y, __GAME.version, COLOR_BLACK, COLOR_WHITE);

	/*5����ӡ���ܼ�*/
	button_q.act(DEFAULT);  /*��ӡ���ܼ�Q*/
	button_r.act(DEFAULT);  /*��ӡ���ܼ�R*/
	button_s.act(DEFAULT);  /*��ӡ���ܼ�S*/
	button_d.act(DEFAULT);  /*��ӡ���ܼ�D*/
	button_o.act(DEFAULT);  /*��ӡ���ܼ�O*/
}

/***************************************************************************
  �������ƣ�mouse_if_button
  ��    �ܣ��ж����λ���Ƿ���ĳһ������
  ���������const int X�����λ�ú����ֻ꣨����
		    const int Y�����λ�������ֻ꣨����
  �� �� ֵ��int���������һ������
  ˵    ������
***************************************************************************/
int keyboard::mouse_if_button(const int X, const int Y)
{
	int ret = 0;  /*����ֵ*/
	bool p[KB_BUTTON_NUM];
	for (int i = 0; i < KB_BUTTON_NUM; i++)
		p[i] = false;

	if (X >= UP_COORD_X && X <= UP_COORD_X + 5 && Y >= UP_COORD_Y && Y <= UP_COORD_Y + 2)              /*�ж��Ƿ����ϼ�ͷ����*/
		p[0] = true;
	if (X >= DOWN_COORD_X && X <= DOWN_COORD_X + 5 && Y >= DOWN_COORD_Y && Y <= DOWN_COORD_Y + 2)      /*�ж��Ƿ����¼�ͷ����*/
		p[1] = true;
	if (X >= LEFT_COORD_X && X <= LEFT_COORD_X + 5 && Y >= LEFT_COORD_Y && Y <= LEFT_COORD_Y + 2)      /*�ж��Ƿ������ͷ����*/
		p[2] = true;
	if (X >= RIGHT_COORD_X && X <= RIGHT_COORD_X + 5 && Y >= RIGHT_COORD_Y && Y <= RIGHT_COORD_Y + 2)  /*�ж��Ƿ����Ҽ�ͷ����*/
		p[3] = true;
	if (X == Q_COORD_X && Y == Q_COORD_Y)   /*�ж��Ƿ��ڹ��ܼ�Q��*/
		p[4] = true;
	if (X == R_COORD_X && Y == R_COORD_Y)   /*�ж��Ƿ��ڹ��ܼ�R��*/
		p[5] = true;
	if (X == S_COORD_X && Y == S_COORD_Y)   /*�ж��Ƿ��ڹ��ܼ�S��*/
		p[6] = true;
	if (X == D_COORD_X && Y == D_COORD_Y)   /*�ж��Ƿ��ڹ��ܼ�D��*/
		p[7] = true;
	if (X == O_COORD_X && Y == O_COORD_Y)   /*�ж��Ƿ��ڹ��ܼ�O��*/
		p[8] = true;

	for (int i = 0; i < KB_BUTTON_NUM; i++) {  /*������λ�õ��������������ȡ��Ӧ����ֵ��������*/
		if (p[i]) {
			ret = i + 1;
			break;
		}
	}

	return ret;
}

/***************************************************************************
  �������ƣ�keyboard_if_button
  ��    �ܣ��жϼ��̰��µİ����Ƿ�ΪС�����ϵ�ĳһ����
  ���������const int keycode1������1��ֻ����
		    const int keycode2������2��ֻ����
  �� �� ֵ��int�����̰�������һ����
  ˵    ������
***************************************************************************/
int keyboard::keyboard_if_button(const int keycode1, const int keycode2)
{
	int ret = 0;

	if (keycode1 == 224) {
		switch (keycode2) {
		case KB_ARROW_UP:     /*�ж��Ƿ������ϼ�ͷ��*/
			ret = 1;
			break;
		case KB_ARROW_DOWN:   /*�ж��Ƿ������¼�ͷ��*/
			ret = 2;
			break;
		case KB_ARROW_LEFT:   /*�ж��Ƿ��������ͷ��*/
			ret = 3;
			break;
		case KB_ARROW_RIGHT:  /*�ж��Ƿ������Ҽ�ͷ��*/
			ret = 4;
			break;
		}
	}
	else if (keycode1 == 'Q' || keycode1 == 'q')  /*�ж��Ƿ����˹��ܼ�Q*/
		ret = 5;
	else if (keycode1 == 'R' || keycode1 == 'r')  /*�ж��Ƿ����˹��ܼ�R*/
		ret = 6;
	else if (keycode1 == 'S' || keycode1 == 's')  /*�ж��Ƿ����˹��ܼ�S*/
		ret = 7;
	else if (keycode1 == 'D' || keycode1 == 'd')  /*�ж��Ƿ����˹��ܼ�D*/
		ret = 8;
	else if (keycode1 == 'O' || keycode1 == 'o')  /*�ж��Ƿ����˹��ܼ�O*/
		ret = 9;

	return ret;
}

/***************************************************************************
  �������ƣ�selective_default
  ��    �ܣ�ѡ���Ե�Ϊĳһ����ȡ������
  ���������const int selection������ѡ��ֻ����
  �� �� ֵ����
  ˵    ������ѡ��ΪDEFAULT_ALLʱ��ͨ���ݹ����ȡ�����а����ĸ���
***************************************************************************/
void keyboard::selective_default(const int selection)
{
	switch (selection) {
	case 1:
		button_up.act(DEFAULT);      /*�ϼ�ͷ��ȡ������*/
		break;
	case 2:
		button_down.act(DEFAULT);    /*�¼�ͷ��ȡ������*/
		break;
	case 3:
		button_left.act(DEFAULT);    /*���ͷ��ȡ������*/
		break;
	case 4:
		button_right.act(DEFAULT);   /*�Ҽ�ͷ��ȡ������*/
		break;
	case 5:
		button_q.act(DEFAULT);       /*���ܼ�Qȡ������*/
		break;
	case 6:
		button_r.act(DEFAULT);       /*���ܼ�Rȡ������*/
		break;
	case 7:
		button_s.act(DEFAULT);       /*���ܼ�Sȡ������*/
		break;
	case 8:
		button_d.act(DEFAULT);       /*���ܼ�Dȡ������*/
		break;
	case 9:
		button_o.act(DEFAULT);       /*���ܼ�Oȡ������*/
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < KB_BUTTON_NUM; i++)  /*���а���ȡ������*/
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
void keyboard::selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		button_up.act(ACTIVATE);     /*�ϼ�ͷ�����ø���*/
		break;
	case 2:
		button_down.act(ACTIVATE);   /*�¼�ͷ�����ø���*/
		break;
	case 3:
		button_left.act(ACTIVATE);   /*���ͷ�����ø���*/
		break;
	case 4:
		button_right.act(ACTIVATE);  /*�Ҽ�ͷ�����ø���*/
		break;
	case 5:
		button_q.act(ACTIVATE);      /*���ܼ�Q���ø���*/
		break;
	case 6:
		button_r.act(ACTIVATE);      /*���ܼ�R���ø���*/
		break;
	case 7:
		button_s.act(ACTIVATE);      /*���ܼ�S���ø���*/
		break;
	case 8:
		button_d.act(ACTIVATE);      /*���ܼ�D���ø���*/
		break;
	case 9:
		button_o.act(ACTIVATE);      /*���ܼ�O���ø���*/
		break;
	}
}

/***************************************************************************
  �������ƣ�control
  ��    �ܣ��ü�����С�����Ͻ��в���
  �����������
  �� �� ֵ��int�����еĲ���
  ˵    ������
***************************************************************************/
int keyboard::control()
{
	int X = 0, Y = 0;  /*�������꣬��ʼ��Ϊ��*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0, RESULT = 0;  /*�����ķ���ֵ���Ի�����������ķ���ֵ*/

	cct_enable_mouse();  /*�������*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*�����/����*/
		selective_default(DEFAULT_ALL);  /*ȡ��С�������а����ĸ���*/

		int RET1 = mouse_if_button(X, Y);                   /*�жϴ�ʱ����λ���Ƿ���ĳ��������*/
		int RET2 = keyboard_if_button(keycode1, keycode2);  /*�жϴ�ʱ���̰��µİ�ť�Ƿ�Ϊĳ������*/
		selective_activate(RET1);  /*�������ĳ�������У�����Ӧ�İ������ø���*/

		/*1�������ص�������¼����Ұ��������ͬʱ�����ĳһ������*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK && RET1 != 0) {
			selective_default(RET1);

			switch (RET1) {
			case 1:
				act_up();     /*���Ϻϳɲ���*/
				break;
			case 2:
				act_down();   /*���ºϳɲ���*/
				break;
			case 3:
				act_left();   /*����ϳɲ���*/
				break;
			case 4:
				act_right();  /*���Һϳɲ���*/
				break;
			case 5:
				__GAME.game_mailbox.print(BUTTON_TWO, "��ȷ��Ҫ�˳���Ϸ��", "  ����δ����Ľ��Ȼ���ʧ");  /*���ܼ�Q�������Ի���ѯ���Ƿ��˳�*/
				RESULT = __GAME.game_mailbox.control();  /*�÷���ֵ��ȡ�Ի������*/
				if (RESULT == GMMB_RET_YES)       /*�������ǡ�����������QUIT����ʾ�˳�״̬*/
					result = QUIT;
				else if (RESULT == GMMB_RET_NO)   /*�������񡱣���������CONTINUE����ʾ����״̬*/
					result = CONTINUE;
				break;
			case 6:
				__GAME.game_mailbox.print(BUTTON_TWO, "��ȷ��Ҫ���¿�ʼ��", "  ����δ����Ľ��Ȼ���ʧ");  /*���ܼ�R�������Ի���ѯ���Ƿ����¿�ʼ*/
				RESULT = __GAME.game_mailbox.control();  /*�÷���ֵ��ȡ�Ի������*/
				if (RESULT == GMMB_RET_YES)       /*�������ǡ�����������RESET����ʾ�ؿ�״̬*/
					result = RESET;
				else if (RESULT == GMMB_RET_NO)   /*�������񡱣���������CONTINUE����ʾ����״̬*/
					result = CONTINUE;
				break;
			case 7:
				__GAME.game_mailbox.print(BUTTON_FIVE, "���浽�ĸ�λ�ã�");    /*���ܼ�S�������Ի���ѯ���Ƿ�浵*/
				RESULT = __GAME.game_mailbox.control();                        /*�÷���ֵ��ȡ�Ի������*/
				if (RESULT >= GMMB_RET_ONE && RESULT <= GMMB_RET_FOUR)  /*����ĳһ���ּ����������ض�Ӧֵ����ʾ��Ϸ���浽��Ӧλ��*/
					result = SAVE_1 + RESULT - GMMB_RET_ONE;
				else if (RESULT == GMMB_RET_CANCEL)                     /*������ȡ��������������CONTINUE����ʾ����״̬*/
					result = CONTINUE;
				break;
			case 8:
				__GAME.game_mailbox.print(BUTTON_FIVE, "ɾ���ĸ�λ�õĴ浵��");  /*���ܼ�D�������Ի���ѯ���Ƿ�ɾ���浵*/
				RESULT = __GAME.game_mailbox.control();                          /*�÷���ֵ��ȡ�Ի������*/
				if (RESULT >= GMMB_RET_ONE && RESULT <= GMMB_RET_FOUR)    /*����ĳһ���ּ����������ض�Ӧֵ����ʾɾ����Ӧλ���ϵĴ浵*/
					result = DELETE_1 + RESULT - GMMB_RET_ONE;
				else if (RESULT == GMMB_RET_CANCEL)                       /*������ȡ��������������CONTINUE����ʾ����״̬*/
					result = CONTINUE;
				break;
			case 9:
				__GAME.game_mailbox.print(BUTTON_SWITCH, "ɫ����˸��  ��ʾ��");  /*���ܼ�O�������Ի����������*/
				while (1) {
					RESULT = __GAME.game_mailbox.control();
					if (RESULT == GMMB_RET_SURE)  /*����ȷ���������˳�*/
						break;
					else                          /*���������������Ӧ����*/
						__GAME.game_mailbox.options(RESULT);
				}
				result = CONTINUE;  /*��������CONTINUE����ʾ����״̬*/
				break;
			}

			Sleep(100);
			selective_activate(RET1);  /*��ʱ���Ӧ�������ø�����Ӫ�찴��Ч��*/
			loop = 0;
		}

		/*2�������ص��Ǽ����¼������Ұ���ĳһ����*/
		else if (ret == CCT_KEYBOARD_EVENT && RET2 != 0) {
			selective_activate(RET2);

			switch (RET2) {
			case 1:
				act_up();     /*���Ϻϳɲ���*/
				break;
			case 2:
				act_down();   /*���ºϳɲ���*/
				break;
			case 3:
				act_left();   /*����ϳɲ���*/
				break;
			case 4:
				act_right();  /*���Һϳɲ���*/
				break;
			case 5:
				__GAME.game_mailbox.print(BUTTON_TWO, "��ȷ��Ҫ�˳���Ϸ��", "  ����δ����Ľ��Ȼ���ʧ");  /*���ܼ�Q�������Ի���ѯ���Ƿ��˳�*/
				RESULT = __GAME.game_mailbox.control();  /*�÷���ֵ��ȡ�Ի������*/
				if (RESULT == GMMB_RET_YES)       /*�������ǡ�����������QUIT����ʾ�˳�״̬*/
					result = QUIT;
				else if (RESULT == GMMB_RET_NO)   /*�������񡱣���������CONTINUE����ʾ����״̬*/
					result = CONTINUE;
				break;
			case 6:
				__GAME.game_mailbox.print(BUTTON_TWO, "��ȷ��Ҫ���¿�ʼ��", "  ����δ����Ľ��Ȼ���ʧ");  /*���ܼ�R�������Ի���ѯ���Ƿ����¿�ʼ*/
				RESULT = __GAME.game_mailbox.control();  /*�÷���ֵ��ȡ�Ի������*/
				if (RESULT == GMMB_RET_YES)       /*�������ǡ�����������RESET����ʾ�ؿ�״̬*/
					result = RESET;
				else if (RESULT == GMMB_RET_NO)   /*�������񡱣���������CONTINUE����ʾ����״̬*/
					result = CONTINUE;
				break;
			case 7:
				__GAME.game_mailbox.print(BUTTON_FIVE, "���浽�ĸ�λ�ã�");    /*���ܼ�S�������Ի���ѯ���Ƿ�浵*/
				RESULT = __GAME.game_mailbox.control();                        /*�÷���ֵ��ȡ�Ի������*/
				if (RESULT >= GMMB_RET_ONE && RESULT <= GMMB_RET_FOUR)  /*����ĳһ���ּ����������ض�Ӧֵ����ʾ��Ϸ���浽��Ӧλ��*/
					result = SAVE_1 + RESULT - GMMB_RET_ONE;
				else if (RESULT == GMMB_RET_CANCEL)                     /*������ȡ��������������CONTINUE����ʾ����״̬*/
					result = CONTINUE;
				break;
			case 8:
				__GAME.game_mailbox.print(BUTTON_FIVE, "ɾ���ĸ�λ�õĴ浵��");  /*���ܼ�D�������Ի���ѯ���Ƿ�ɾ���浵*/
				RESULT = __GAME.game_mailbox.control();                          /*�÷���ֵ��ȡ�Ի������*/
				if (RESULT >= GMMB_RET_ONE && RESULT <= GMMB_RET_FOUR)    /*����ĳһ���ּ����������ض�Ӧֵ����ʾɾ����Ӧλ���ϵĴ浵*/
					result = DELETE_1 + RESULT - GMMB_RET_ONE;
				else if (RESULT == GMMB_RET_CANCEL)                       /*������ȡ��������������CONTINUE����ʾ����״̬*/
					result = CONTINUE;
				break;
			case 9:
				__GAME.game_mailbox.print(BUTTON_SWITCH, "ɫ����˸��  ��ʾ��");  /*���ܼ�O�������Ի����������*/
				while (1) {
					RESULT = __GAME.game_mailbox.control();
					if (RESULT == GMMB_RET_SURE)  /*����ȷ���������˳�*/
						break;
					else                          /*���������������Ӧ����*/
						__GAME.game_mailbox.options(RESULT);
				}
				result = CONTINUE;  /*��������CONTINUE����ʾ����״̬*/
				break;
			}

			Sleep(100);
			selective_default(RET2);  /*��ʱ���Ӧ�������ø�����Ӫ�찴��Ч��*/
			loop = 0;
		}
	}

	cct_disable_mouse();	//�������
	return result;
}