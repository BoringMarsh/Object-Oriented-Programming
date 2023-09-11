#include<windows.h>
#include"90-b4.h"
#include"interface-inputbox.h"

/***************************************************************************
  �������ƣ�get_width
  ��    �ܣ�ȡ�������
  �����������
  �� �� ֵ��int�������Ŀ��
  ˵    �����ú����ɷ���˽�г�Աֵ
***************************************************************************/
int inputbox::get_width()
{
	return IPBX_WIDTH;
}

/***************************************************************************
  �������ƣ�print
  ��    �ܣ���ӡ�����
  ���������const int button_mode��������ʽ��ֻ����
			const char* prompt����ʾ�ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void inputbox::print(const char* prompt)
{
	/*1����ӡ���������*/
	cct_showstr(IPBX_COORD_X, IPBX_COORD_Y, "����������������������������������", IPBX_BG_COLOR, IPBX_FG_COLOR_D);
	cct_showstr(IPBX_COORD_X - 2, IPBX_COORD_Y + 1, "����                              ����", IPBX_BG_COLOR, IPBX_FG_COLOR_D);
	for (int i = 0; i < IPBX_WIDTH - 4; i++) {
		cct_showstr(IPBX_COORD_X - 2, IPBX_COORD_Y + 2 + i, "��                                  ��", IPBX_BG_COLOR, IPBX_FG_COLOR_D);
	}
	cct_showstr(IPBX_COORD_X - 2, IPBX_COORD_Y + IPBX_WIDTH - 2, "����                              ����", IPBX_BG_COLOR, IPBX_FG_COLOR_D);
	cct_showstr(IPBX_COORD_X, IPBX_COORD_Y + IPBX_WIDTH - 1, "����������������������������������", IPBX_BG_COLOR, IPBX_FG_COLOR_D);

	/*2����ӡ�������ʾ��*/
	cct_showstr(IPPROM_COORD_X1, IPPROM_COORD_Y1, prompt, IPBX_BG_COLOR, IPBX_FG_COLOR_D);

	/*3����ӡ����򰴼�*/
	button_ipline.act(DEFAULT);
	button_iprow.act(DEFAULT);
	button_ipbomb.act(DEFAULT);
	button_sure.act(DEFAULT);
	button_cancel.act(DEFAULT);
}

/***************************************************************************
  �������ƣ�mouse_if_button
  ��    �ܣ��ж����λ���Ƿ���ĳһ������
  ���������const int X�����λ�ú����ֻ꣨����
			const int Y�����λ�������ֻ꣨����
  �� �� ֵ��int���������һ������
  ˵    ������
***************************************************************************/
int inputbox::mouse_if_button(const int X, const int Y)
{
	int ret = 0;  /*����ֵ*/
	bool p[IPBX_BUTTON_NUM];
	for (int i = 0; i < IPBX_BUTTON_NUM; i++)
		p[i] = false;

	if (X >= IPLINE_COORD_X && X <= IPLINE_COORD_X + 5 && Y >= IPLINE_COORD_Y && Y <= IPLINE_COORD_Y + 2)          /*�ж��Ƿ��������������*/
		p[0] = true;
	if (X >= IPROW_COORD_X && X <= IPROW_COORD_X + 5 && Y >= IPROW_COORD_Y && Y <= IPROW_COORD_Y + 2)              /*�ж��Ƿ��������������*/
		p[1] = true;
	if (X >= IPBOMB_COORD_X && X <= IPBOMB_COORD_X + 5 && Y >= IPBOMB_COORD_Y && Y <= IPBOMB_COORD_Y + 2)          /*�ж��Ƿ��ڵ������������*/
		p[2] = true;
	if (X >= IPSURE_COORD_X && X <= IPSURE_COORD_X + 3 && Y >= IPSURE_COORD_Y && Y <= IPSURE_COORD_Y + 1)          /*�ж��Ƿ��ڡ�ȷ��������*/
		p[3] = true;
	if (X >= IPCANCEL_COORD_X && X <= IPCANCEL_COORD_X + 3 && Y >= IPCANCEL_COORD_Y && Y <= IPCANCEL_COORD_Y + 1)  /*�ж��Ƿ��ڡ�ȡ��������*/
		p[4] = true;

	/*������λ�õ��������������ȡ��Ӧ����ֵ��������*/
	for (int i = 0; i < IPBX_BUTTON_NUM; i++) {
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
void inputbox::selective_default(const int selection)
{
	switch (selection) {
	case 1:
		button_ipline.act(DEFAULT);  /*���������ȡ������*/
		break;
	case 2:
		button_iprow.act(DEFAULT);   /*���������ȡ������*/
		break;
	case 3:
		button_ipbomb.act(DEFAULT);  /*�����������ȡ������*/
		break;
	case 4:
		button_sure.act(DEFAULT);    /*��ȷ������ȡ������*/
		break;
	case 5:
		button_cancel.act(DEFAULT);  /*��ȡ������ȡ������*/
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < IPBX_BUTTON_NUM; i++)  /*���а���ȡ������*/
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
void inputbox::selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		button_ipline.act(ACTIVATE);  /*������������ø���*/
		break;
	case 2:
		button_iprow.act(ACTIVATE);   /*������������ø���*/
		break;
	case 3:
		button_ipbomb.act(ACTIVATE);  /*��������������ø���*/
		break;
	case 4:
		button_sure.act(ACTIVATE);    /*��ȷ���������ø���*/
		break;
	case 5:
		button_cancel.act(ACTIVATE);  /*��ȡ���������ø���*/
		break;
	}
}

/***************************************************************************
  �������ƣ�move_cursor
  ��    �ܣ��������ڲ����ı�����λ�����ƶ��������Ӧλ��
  ���������const int pblock�����ڲ����ı�����ֻ����
            const int ppos�����ڲ�����λ����ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void inputbox::move_cursor(const int pblock, const int ppos)
{
	int x = 0, y = 0;  /*��������*/

	switch (pblock) {  /*�������ڲ����ı�����ȡ��Ӧ��������Ͻǵ�����*/
	case 0:
		x = IPLINE_COORD_X, y = IPLINE_COORD_Y;
		break;
	case 1:
		x = IPROW_COORD_X, y = IPROW_COORD_Y;
		break;
	case 2:
		x = IPBOMB_COORD_X, y = IPBOMB_COORD_Y;
		break;
	}

	switch (ppos) {  /*�������ڲ�����λ�����ƶ��������Ӧλ��*/
	case 1:
		cct_gotoxy(x + 2, y + 1);
		break;
	case 2:
		cct_gotoxy(x + 3, y + 1);
		break;
	}
}

/***************************************************************************
  �������ƣ�keyboard_input
  ��    �ܣ��������ڲ����ı�����λ������������ֵ���ı��Ӧ������ֵ
  ���������const int pblock�����ڲ����ı�����ֻ����
			const int ppos�����ڲ�����λ����ֻ����
			const int keycode�����̵�����ֵ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void inputbox::keyboard_input(const int pblock, const int ppos, const int keycode)
{
	if (keycode >= '0' && keycode <= '9') {  /*��������1-9�����Ӷ�Ӧ������ֵ*/
		switch (pblock) {
		case 0:
			switch (ppos) {
			case 1:
				line = line + keycode - '0';  /*���������ĵ�һλ������ֵ�ӵ���λ��*/
				break;
			case 2:
				if (line < 10)
					line = line * 10 + keycode - '0';  /*���������ĵڶ�λ������������һλ������ֵ�ӵ�ʮλ��*/
				else
					line = line - line % 10 + keycode - '0';  /*���������ĵڶ�λ������������λ������ֵ�ı䵽��λ��*/
				break;
			}
			break;
		case 1:
			switch (ppos) {
			case 1:
				row = row + keycode - '0';  /*���������ĵ�һλ������ֵ�ӵ���λ��*/
				break;
			case 2:
				if (row < 10)
					row = row * 10 + keycode - '0';  /*���������ĵڶ�λ������������һλ������ֵ�ӵ�ʮλ��*/
				else
					row = row - row % 10 + keycode - '0';  /*���������ĵڶ�λ������������λ������ֵ�ı䵽��λ��*/
				break;
			}
			break;
		case 2:
			switch (ppos) {
			case 1:
				bomb_num = bomb_num + keycode - '0';  /*�����������ĵ�һλ������ֵ�ӵ���λ��*/
				break;
			case 2:
				if (bomb_num < 10)
					bomb_num = bomb_num * 10 + keycode - '0';  /*�����������ĵڶ�λ��������������һλ������ֵ�ӵ�ʮλ��*/
				else
					bomb_num = bomb_num - bomb_num % 10 + keycode - '0';  /*�����������ĵڶ�λ��������������λ������ֵ�ı䵽��λ��*/
				break;
			}
			break;
		}
	}
	
	else if (keycode == '\b') {  /*���������˸񣬼��ٶ�Ӧ������ֵ*/
		switch (pblock) {
		case 0:
			switch (ppos) {
			case 1:
				line = 0;  /*���������ĵ�һλ��ֱ��ʹ����ȡ��*/
				break;
			case 2:
				line = (line - line % 10) / 10;  /*���������ĵڶ�λ��ʹ����ȡ����ǰ��ʮλ��*/
				break;
			}
			break;
		case 1:
			switch (ppos) {
			case 1:
				row = 0;  /*���������ĵ�һλ��ֱ��ʹ����ȡ��*/
				break;
			case 2:
				row = (row - row % 10) / 10;  /*���������ĵڶ�λ��ʹ����ȡ����ǰ��ʮλ��*/
				break;
			}
			break;
		case 2:
			switch (ppos) {
			case 1:
				bomb_num = 0;  /*�����������ĵ�һλ��ֱ��ʹ����ȡ��*/
				break;
			case 2:
				bomb_num = (bomb_num - bomb_num % 10) / 10;  /*�����������ĵڶ�λ��ʹ����ȡ����ǰ��ʮλ��*/
				break;
			}
			break;
		}
	}
}

/***************************************************************************
  �������ƣ�info_check
  ��    �ܣ��������������Ƿ����
  �����������
  �� �� ֵ��int�������������Ƿ����
  ˵    �����������������������������������������ʾ��Ӧ����ʾ��
***************************************************************************/
int inputbox::info_check()
{
	int ret = 0;  /*����ֵ������Ϊ0*/

	if (line == 0) {  /*����Ϊ������*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "��������Ϊ�㣡", IPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "              ", IPBX_BG_COLOR, COLOR_RED);
	}

	else if (line > LINE_MAX) {  /*������������*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "��������", IPBX_BG_COLOR, COLOR_GREEN);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "          ", IPBX_BG_COLOR, COLOR_GREEN);
	}

	else if (row == 0) {  /*����Ϊ������*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "��������Ϊ�㣡", IPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "              ", IPBX_BG_COLOR, COLOR_RED);
	}

	else if (row > ROW_MAX) {  /*������������*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "��������", IPBX_BG_COLOR, COLOR_GREEN);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "          ", IPBX_BG_COLOR, COLOR_GREEN);
	}

	else if (bomb_num == 0) {  /*������Ϊ������*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "����������Ϊ�㣡", IPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "                ", IPBX_BG_COLOR, COLOR_RED);
	}

	else if (bomb_num > int(line * row * 0.8)) {  /*��������������*/
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "���������࣡", IPBX_BG_COLOR, COLOR_BLUE);
		Sleep(500);
		cct_showstr(IPPROM_COORD_X2, IPPROM_COORD_Y2, "            ", IPBX_BG_COLOR, COLOR_BLUE);
	}

	else  /*��������������������ֵ��Ϊ1*/
		ret = 1;

	return ret;
}

/***************************************************************************
  �������ƣ�control
  ��    �ܣ��ü�����������ڽ��в���
  �����������
  �� �� ֵ��int�����еĲ���
  ˵    ������
***************************************************************************/
int inputbox::control(int* LINE, int* ROW, int* BOMB_NUM)
{
	int X = 0, Y = 0;  /*�������꣬��ʼ��Ϊ��*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*�����ķ���ֵ*/

	int pblock = 0, ppos[3] = { 1,1,1 };  /*ָ�����ڲ���������λ����ָ��*/

	cct_enable_mouse();  /*�������*/
	cct_setcursor(CURSOR_VISIBLE_NORMAL);  /*��ʾ���*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*�����/����*/
		selective_default(DEFAULT_ALL);  /*ȡ���Ի������а����ĸ���*/

		int RET1 = mouse_if_button(X, Y);  /*�жϴ�ʱ����λ���Ƿ���ĳ��������*/
		selective_activate(RET1);          /*�������ĳ�������У�����Ӧ�İ������ø���*/

		move_cursor(pblock, ppos[pblock]);  /*�ƶ��������Ӧλ��*/

		/*1�������ص�������¼����Ұ������*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {
			selective_default(RET1);  /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
			Sleep(100);
			selective_activate(RET1);

			switch (RET1) {
			case 1:
			case 2:
			case 3:
				pblock = RET1 - 1;  /*�ı����ڲ����ı���*/
				break;
			case 4:
				switch (info_check()) {  /*��������������Ƿ���������������������룬��������ȡ����ֵ���������*/
				case 0:
					continue;
					break;
				case 1:
					result = IPBX_RET_SURE, loop = 0;
					break;
				}
				break;
			case 5:
				result = IPBX_RET_CANCEL, loop = 0;  /*ȡ����ֵ���������*/
				break;
			}
		}

		/*2�������ص��Ǽ����¼�*/
		else if (ret == CCT_KEYBOARD_EVENT) {
			int x, y;

			switch (keycode1) {
			case '\n':
			case '\r':
				switch (info_check()) {  /*��������������Ƿ���������������������룬��������ȡ����ֵ���������*/
				case 0:
					continue;
					break;
				case 1:
					result = IPBX_RET_SURE, loop = 0;
					break;
				}
				break;
			case 'C':
			case 'c':
				result = IPBX_RET_CANCEL, loop = 0;  /*ȡ����ֵ���������*/
				break;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				keyboard_input(pblock, ppos[pblock], keycode1);  /*�ı��Ӧ������ֵ*/
				if (ppos[pblock] == 1)  /*�����ڲ�����һλ�������λ������*/
					ppos[pblock]++;

				cct_getxy(x, y);  /*�ڵ�ǰ���λ����ʾ����������ַ�*/
				cct_showch(x, y, keycode1, IPBX_BG_COLOR, COLOR_BLACK);
				move_cursor(pblock, ppos[pblock]);  /*��ɲ������ƶ��������Ӧλ��*/
				break;
			case '\b':
				keyboard_input(pblock, ppos[pblock], keycode1);  /*�ı��Ӧ������ֵ*/
				cct_getxy(x, y);  /*ȡ��ǰ���λ��*/

				if (ppos[pblock] == 2) {  /*�����ڲ����ڶ�λ����������*/
					switch (pblock) {
					case 0:
						if (line == 0)  /*������������Ϊ�㣬˵������ǰ�ڶ�λ��Ϊ�գ������λ���Լ������������Լ�*/
							ppos[pblock]--, x--;
						break;
					case 1:
						if (row == 0)  /*������������Ϊ�㣬˵������ǰ�ڶ�λ��Ϊ�գ������λ���Լ������������Լ�*/
							ppos[pblock]--, x--;
						break;
					case 2:
						if (bomb_num == 0)  /*�������������Ϊ�㣬˵������ǰ�ڶ�λ��Ϊ�գ������λ���Լ������������Լ�*/
							ppos[pblock]--, x--;
						break;
					}
				}

				cct_showch(x, y, ' ', IPBX_BG_COLOR, COLOR_BLACK);  /*�ڶ�Ӧλ��������ո񣬸���ԭ���֣�Ӫ���˸�Ч��*/
				move_cursor(pblock, ppos[pblock]);  /*��ɲ������ƶ��������Ӧλ��*/
				break;
			}
		}
	}

	cct_disable_mouse();	//�������
	cct_setcursor(CURSOR_INVISIBLE);  /*���ع��*/
	*LINE = line, * ROW = row, * BOMB_NUM = bomb_num;  /*������õ�ֵ����ʵ��*/
	line = 0, row = 0, bomb_num = 0;  /*�ڲ�ֵ�������㣬�Ա���һ�δ������ʱ��Ϊ��*/

	return result;
}