#include<windows.h>
#include"90-b4.h"
#include"interface-mailbox.h"

/***************************************************************************
  �������ƣ�set_button_coord
  ��    �ܣ����������긳ֵ
  �����������
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void game_mailbox::set_button_coord(const int line, const int row)
{
	button_yes.set_coord(GMYES_COORD_X, GMYES_COORD_Y);           /*���ǡ������긳ֵ*/
	button_no.set_coord(GMNO_COORD_X, GMNO_COORD_Y);              /*���񡱼����긳ֵ*/
	button_sure.set_coord(GMSURE_COORD_X, GMSURE_COORD_Y);        /*��ȷ���������긳ֵ*/
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
void game_mailbox::print(const int button_mode, const int line, const int row, const char* prompt1, const char* prompt2, const char* prompt3)
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

	/*3�����ݰ�����ʽ��ӡ�Ի���ť*/
	if (button_mode == BUTTON_TWO) {  /*˫��ʽ*/
		button_yes.act(DEFAULT);  /*��ӡ���ǡ���*/
		button_no.act(DEFAULT);   /*��ӡ���񡱼�*/
	}

	else if (button_mode == BUTTON_ONE)  /*����ʽ*/
		button_sure.act(DEFAULT);  /*��ӡ��ȷ������*/
}

/***************************************************************************
  �������ƣ�mouse_if_button
  ��    �ܣ��ж����λ���Ƿ���ĳһ������
  ���������const int X�����λ�ú����ֻ꣨����
			const int Y�����λ�������ֻ꣨����
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
  �� �� ֵ��int���������һ������
  ˵    ������
***************************************************************************/
int game_mailbox::mouse_if_button(const int X, const int Y, const int line, const int row)
{
	int ret = 0;  /*����ֵ*/
	bool p[GMMB_BUTTON_NUM];
	for (int i = 0; i < GMMB_BUTTON_NUM; i++)
		p[i] = false;

	if ((X == GMYES_COORD_X || X == GMYES_COORD_X + 1) && (Y == GMYES_COORD_Y || Y == GMYES_COORD_Y + 1))    /*�ж��Ƿ��ڡ��ǡ�����*/
		p[0] = true;
	if ((X == GMNO_COORD_X || X == GMNO_COORD_X + 1) && (Y == GMNO_COORD_Y || Y == GMNO_COORD_Y + 1))        /*�ж��Ƿ��ڡ��񡱼���*/
		p[1] = true;
	if (X >= GMSURE_COORD_X && X <= GMSURE_COORD_X + 3 && (Y == GMSURE_COORD_Y || Y == GMSURE_COORD_Y + 1))  /*�ж��Ƿ��ڡ�ȷ��������*/
		p[2] = true;

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
		if (IF_GMMB == BUTTON_ONE)   /*��ȷ������ȡ������*/
			button_sure.act(DEFAULT);
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
		if (IF_GMMB == BUTTON_ONE)   /*��ȷ���������ø���*/
			button_sure.act(ACTIVATE);
		break;
	}
}

/***************************************************************************
  �������ƣ�control
  ��    �ܣ��ü�������Ϸ�ڶԻ����ڽ��в���
  ���������const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
  �� �� ֵ��int�����еĲ���
  ˵    ������
***************************************************************************/
int game_mailbox::control(const int line, const int row)
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

		int RET1 = mouse_if_button(X, Y, line, row);  /*�жϴ�ʱ����λ���Ƿ���ĳ��������*/
		int RET2 = keyboard_if_button(keycode1);      /*�жϴ�ʱ���̰��µİ�ť�Ƿ�Ϊĳ������*/
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
			}
		}
	}

	cct_disable_mouse();	//�������
	return result;
}

/***************************************************************************
  �������ƣ�erase
  ��    �ܣ��ػ���Ϸ��壬�ﵽ�����Ի����Ч��
  ���������const matrix MATRIX[]��������Ϸ���ڲ��ṹ�����飨ֻ����
            const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
  �� �� ֵ����
  ˵    �����������ػ��˶Ի����Ӧ���Ǽ����Լ�����ɫ��
***************************************************************************/
void game_mailbox::erase(const matrix MATRIX[], const int line, const int row)
{
	const int line_min = line % 2 ? line / 2 - 1 : line / 2 - 2;  /*��������ȡ��С���������Ի���ռ��������һ�е�������*/

	for (int i = line_min * row; i < (line_min + 3) * row; i++) {
		const int J = i % row;        /*��һά����ת��Ϊ�б�*/
		const int I = (i - J) / row;  /*��һά����ת��Ϊ�б�*/
		cct_gotoxy(6 * J + 2, 3 * I + 12);  /*�ƶ��������Ӧɫ������Ͻ�*/

		if (MATRIX[i].if_flag)  /*����Ԫ���ѱ����죬���ӡ����ɫ��*/
			block_print('F' - '0', COLOR_HBLACK, COLOR_HWHITE);

		else {  /*��Ԫ��δ����������*/
			switch (MATRIX[i].if_turned) {
			case true:
				if (MATRIX[i].num)
					block_print(MATRIX[i].num - '0', COLOR_HWHITE, num_trans_color(MATRIX[i].num - '0'));  /*������������ֵ��Ϊ�㣬���ӡ��Ӧɫ��*/
				else
					block_print(0, COLOR_HWHITE, COLOR_HWHITE);  /*������������ֵΪ�㣬���ӡ�հ�ɫ��*/
				break;
			case false:
				block_print(NUM_SPACE, COLOR_WHITE, COLOR_BLACK);  /*��δ�����������ӡ��ʼɫ��*/
				break;
			}
		}
	}
}