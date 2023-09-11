#include<windows.h>
#include"interface-optionsbox.h"

/***************************************************************************
  �������ƣ�get_width
  ��    �ܣ�ȡ���öԻ�����
  �����������
  �� �� ֵ��int�����öԻ���Ŀ��
  ˵    �����ú����ɷ���˽�г�Աֵ
***************************************************************************/
int optionsbox::get_width()
{
	return OPBX_WIDTH;
}

/***************************************************************************
  �������ƣ�get_if_sound
  ��    �ܣ�ȡ�Ƿ�������
  �����������
  �� �� ֵ��bool���Ƿ�������
  ˵    �����ú����ɷ���˽�г�Աֵ
***************************************************************************/
bool optionsbox::get_if_sound()
{
	return if_sound;
}

/***************************************************************************
  �������ƣ�get_fontsize
  ��    �ܣ�ȡ�����С
  �����������
  �� �� ֵ��int�������С
  ˵    �����ú����ɷ���˽�г�Աֵ
***************************************************************************/
int optionsbox::get_fontsize()
{
	return fontsize;
}

/***************************************************************************
  �������ƣ�get_fontsize
  ��    �ܣ���ȡ�����С��ת�����ַ���
  ���������char* String����Ž�����ַ�����
  �� �� ֵ��char*���ַ�����ʽ�Ķ�ȡ���
  ˵    ����1����Ž�����ַ������������Ԫ��
			2���ֶ������β��
***************************************************************************/
char* optionsbox::read_fontsize(char* String)
{
	if (fontsize >= 10) {  /*�������С����10����ֱ��ȡ��λ��*/
		String[0] = (fontsize - fontsize % 10) / 10 + '0';
		String[1] = fontsize % 10 + '0';
	}

	else {  /*�������СС��10�����ȡ��λ�������һ���ո�*/
		String[0] = fontsize % 10 + '0';
		String[1] = ' ';
	}

	String[2] = '\0';  /*���β��*/
	return String;
}

/***************************************************************************
  �������ƣ�print
  ��    �ܣ���ӡ���öԻ���
  ���������const char* prompt����ʾ�ֻ����Ĭ��Ϊ��ָ�룩
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void optionsbox::print(const char* prompt)
{
	/*1����ӡ���öԻ�������*/
	cct_showstr(OPBX_COORD_X, OPBX_COORD_Y, "������������������������", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	cct_showstr(OPBX_COORD_X - 2, OPBX_COORD_Y + 1, "����                    ����", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	for (int i = 0; i < OPBX_WIDTH - 4; i++) {
		cct_showstr(OPBX_COORD_X - 2, OPBX_COORD_Y + 2 + i, "��                        ��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	}
	cct_showstr(OPBX_COORD_X - 2, OPBX_COORD_Y + OPBX_WIDTH - 2, "����                    ����", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	cct_showstr(OPBX_COORD_X, OPBX_COORD_Y + OPBX_WIDTH - 1, "������������������������", OPBX_BG_COLOR, OPBX_FG_COLOR_D);

	/*2����ӡ���öԻ�����ʾ��*/
	cct_showstr(OPPROM_COORD_X1, OPPROM_COORD_Y1, prompt, OPBX_BG_COLOR, OPBX_FG_COLOR_D);

	/*3����ӡ���öԻ��򰴼�*/
	button_setsound.act(DEFAULT);
	button_setfont.act(DEFAULT);
	button_sure.act(DEFAULT);
	button_cancel.act(DEFAULT);

	/*4���������������ӡ����״̬*/
	switch (if_sound) {
	case true:
		cct_showstr(SETSOUND_COORD_X + 2, SETSOUND_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
		break;
	case false:
		cct_showstr(SETSOUND_COORD_X + 2, SETSOUND_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
		break;
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
int optionsbox::mouse_if_button(const int X, const int Y)
{
	int ret = 0;  /*����ֵ*/
	bool p[OPBX_BUTTON_NUM];
	for (int i = 0; i < OPBX_BUTTON_NUM; i++)
		p[i] = false;

	if (X >= SETSOUND_COORD_X && X <= SETSOUND_COORD_X + 5 && Y >= SETSOUND_COORD_Y && Y <= SETSOUND_COORD_Y + 2)  /*�ж��Ƿ����������ÿ���*/
		p[0] = true;
	if (X >= SETFONT_COORD_X && X <= SETFONT_COORD_X + 5 && Y >= SETFONT_COORD_Y && Y <= SETFONT_COORD_Y + 2)      /*�ж��Ƿ��������С���ÿ���*/
		p[1] = true;
	if (X >= OPSURE_COORD_X && X <= OPSURE_COORD_X + 5 && Y >= OPSURE_COORD_Y && Y <= OPSURE_COORD_Y + 1)          /*�ж��Ƿ��ڡ�ȷ��������*/
		p[2] = true;
	if (X >= OPCANCEL_COORD_X && X <= OPCANCEL_COORD_X + 5 && Y >= OPCANCEL_COORD_Y && Y <= OPCANCEL_COORD_Y + 1)  /*�ж��Ƿ��ڡ�ȡ��������*/
		p[3] = true;

	/*������λ�õ��������������ȡ��Ӧ����ֵ��������*/
	for (int i = 0; i < OPBX_BUTTON_NUM; i++) {
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
void optionsbox::selective_default(const int selection)
{
	switch (selection) {
	case 1:
		button_setsound.act(DEFAULT);  /*�������ÿ�ȡ������*/
		break;
	case 2:
		button_setfont.act(DEFAULT);   /*�����С���ÿ�ȡ������*/
		break;
	case 3:
		button_sure.act(DEFAULT);      /*��ȷ������ȡ������*/
		break;
	case 4:
		button_cancel.act(DEFAULT);    /*��ȡ������ȡ������*/
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < OPBX_BUTTON_NUM; i++)  /*���а���ȡ������*/
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
void optionsbox::selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		button_setsound.act(ACTIVATE);  /*�������ÿ����ø���*/
		break;
	case 2:
		button_setfont.act(ACTIVATE);   /*�����С���ÿ����ø���*/
		break;
	case 3:
		button_sure.act(ACTIVATE);      /*��ȷ���������ø���*/
		break;
	case 4:
		button_cancel.act(ACTIVATE);    /*��ȡ���������ø���*/
		break;
	}
}

/***************************************************************************
  �������ƣ�move_cursor
  ��    �ܣ����ݲ������������λ�����ƶ��������Ӧλ��
  ���������const bool pblock���Ƿ����ڲ���������ֻ����
			const int ppos�����ڲ�����λ����ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void optionsbox::move_cursor(const bool pblock, const int ppos)
{
	if (pblock) {  /*�����ڲ�����������������ڲ�����λ���ƶ��������Ӧλ��*/
		switch (ppos) {
		case 1:
			cct_gotoxy(SETFONT_COORD_X + 2, SETFONT_COORD_Y + 1);  /*���������С��һλ*/
			break;
		case 2:
			cct_gotoxy(SETFONT_COORD_X + 3, SETFONT_COORD_Y + 1);  /*���������С�ڶ�λ*/
			break;
		}
	}
}

/***************************************************************************
  �������ƣ�keyboard_input
  ��    �ܣ����ݲ������������λ������������ֵ���ı��Ӧ������ֵ
  ���������const bool pblock���������������ֻ����
			const int ppos�����ڲ�����λ����ֻ����
			const int keycode�����̵�����ֵ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void optionsbox::keyboard_input(const bool pblock, const int ppos, const int keycode)
{
	if (pblock && keycode >= '0' && keycode <= '9') {  /*�����ڲ����������Ҽ�������1-9�����Ӷ�Ӧ������ֵ*/
		switch (ppos) {
		case 1:
			fontsize = fontsize + keycode - '0';  /*���������С�ĵ�һλ������ֵ�ӵ���λ��*/
			break;
		case 2:
			if (fontsize < 10)
				fontsize = fontsize * 10 + keycode - '0';  /*���������С�ĵڶ�λ���������С����һλ������ֵ�ӵ�ʮλ��*/
			else
				fontsize = fontsize - fontsize % 10 + keycode - '0';  /*���������С�ĵڶ�λ���������С����λ������ֵ�ı䵽��λ��*/
			break;
		}
	}

	else if (pblock && keycode == '\b') {  /*�����ڲ����������Ҽ��������˸񣬼��ٶ�Ӧ������ֵ*/
		switch (ppos) {
		case 1:
			fontsize = 0;  /*���������С�ĵ�һλ��ֱ��ʹ����ȡ��*/
			break;
		case 2:
			fontsize = (fontsize - fontsize % 10) / 10;  /*���������С�ĵڶ�λ��ʹ�����Сȡ����ǰ��ʮλ��*/
			break;
		}
	}
}

/***************************************************************************
  �������ƣ�info_check
  ��    �ܣ��������������Ƿ����
  �����������
  �� �� ֵ��int���������Ƿ����
  ˵    �����������������������������������������ʾ��Ӧ����ʾ��
***************************************************************************/
int optionsbox::info_check()
{
	int ret = 0;  /*����ֵ������Ϊ0*/

	if (fontsize == 0) {  /*�����СΪ������*/
		cct_showstr(OPPROM_COORD_X2, OPPROM_COORD_Y2, "�����С����Ϊ�㣡", OPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(OPPROM_COORD_X2, OPPROM_COORD_Y2, "                  ", OPBX_BG_COLOR, COLOR_RED);
	}

	else if (fontsize % 2 == 1) {  /*�����СΪ���������*/
		cct_showstr(OPPROM_COORD_X2, OPPROM_COORD_Y2, "�����С����Ϊ������", OPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(OPPROM_COORD_X2, OPPROM_COORD_Y2, "                    ", OPBX_BG_COLOR, COLOR_BLUE);
	}

	else  /*����������������ֵ��Ϊ1*/
		ret = 1;

	return ret;
}

/***************************************************************************
  �������ƣ�control
  ��    �ܣ��ü��������öԻ����ڽ��в���
  ���������bool* IF_SOUND���Ƿ�������
            int* FONTSIZE�������С
  �� �� ֵ��int�����еĲ���
  ˵    ������
***************************************************************************/
int optionsbox::control(bool* IF_SOUND, int* FONTSIZE)
{
	int X = 0, Y = 0;  /*�������꣬��ʼ��Ϊ��*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*�����ķ���ֵ*/

	bool pblock = false;  /*�����������������Ϊ��*/
	int ppos = 0;         /*ָ��λ����ָ�룬����Ϊ��*/
	char font[3];         /*��������С��ȡ������ַ�����*/

	/*���������Сȡppos�ĳ�ֵ*/
	if (fontsize >= 10)
		ppos = 2;
	else
		ppos = 1;

	cct_showstr(SETFONT_COORD_X + 2, SETFONT_COORD_Y + 1, read_fontsize(font), OPBX_BG_COLOR, OPBX_FG_COLOR_D);  /*�������С���ÿ�����ʾ��ȡ���*/
	cct_enable_mouse();  /*�������*/

	while (loop) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*�����/����*/
		selective_default(DEFAULT_ALL);  /*ȡ���Ի������а����ĸ���*/

		int RET1 = mouse_if_button(X, Y);  /*�жϴ�ʱ����λ���Ƿ���ĳ��������*/
		selective_activate(RET1);          /*�������ĳ�������У�����Ӧ�İ������ø���*/

		if (pblock)  /*�����ڲ����������ƶ��������Ӧλ��*/
			move_cursor(pblock, ppos);

		/*1�������ص�������¼����Ұ������*/
		if (ret == CCT_MOUSE_EVENT && maction == MOUSE_LEFT_BUTTON_CLICK) {
			selective_default(RET1);  /*ȡ����������ʱ�����ø�����Ӫ�찴��Ч��*/
			Sleep(100);
			selective_activate(RET1);

			switch (RET1) {
			case 1:
				pblock = false;  /*δ���в��������������Ϊ��*/
				cct_setcursor(CURSOR_INVISIBLE);  /*���ع��*/

				switch (if_sound) {
				case true:
					if_sound = false;  /*������ǰ������������Ϊ�٣��������ÿ����ַ���Ϊ��*/
					cct_showstr(SETSOUND_COORD_X + 2, SETSOUND_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				case false:
					if_sound = true;  /*������ǰû������������Ϊ�棬�������ÿ����ַ���Ϊ��*/
					cct_showstr(SETSOUND_COORD_X + 2, SETSOUND_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				}
				break;
			case 2:
				pblock = true;  /*���в��������������Ϊ��*/
				cct_setcursor(CURSOR_VISIBLE_NORMAL);  /*��ʾ���*/
				break;
			case 3:
				cct_setcursor(CURSOR_INVISIBLE);  /*�����˳����öԻ������ع��*/

				switch (info_check()) {  /*��������������Ƿ���������������������룬��������ȡ����ֵ���������*/
				case 0:
					continue;
					break;
				case 1:
					result = OPBX_RET_SURE, loop = 0;
					break;
				}
				break;
			case 4:
				cct_setcursor(CURSOR_INVISIBLE);  /*�����˳����öԻ������ع��*/
				result = OPBX_RET_CANCEL, loop = 0;  /*ȡ����ֵ���������*/
				break;
			}
		}

		/*2�������ص��Ǽ����¼�*/
		else if (ret == CCT_KEYBOARD_EVENT) {
			int x, y;

			switch (keycode1) {
			case '\n':
			case '\r':
				cct_setcursor(CURSOR_INVISIBLE);  /*�����˳����öԻ������ع��*/

				switch (info_check()) {  /*��������������Ƿ���������������������룬��������ȡ����ֵ���������*/
				case 0:
					continue;
					break;
				case 1:
					result = OPBX_RET_SURE, loop = 0;
					break;
				}
				break;
			case 'C':
			case 'c':
				cct_setcursor(CURSOR_INVISIBLE);  /*�����˳����öԻ������ع��*/
				result = OPBX_RET_CANCEL, loop = 0;  /*ȡ����ֵ���������*/
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
				keyboard_input(pblock, ppos, keycode1);  /*�ı��Ӧ������ֵ*/

				if (pblock) {  /*�����ڲ����������������²���*/
					if (ppos == 1)  /*�����ڲ�����һλ�������λ������*/
						ppos++;

					cct_getxy(x, y);  /*�ڵ�ǰ���λ����ʾ����������ַ�*/
					cct_showch(x, y, keycode1, OPBX_BG_COLOR, OPBX_FG_COLOR_D);
				}

				move_cursor(pblock, ppos);  /*��ɲ������ƶ��������Ӧλ��*/
				break;
			case '\b':
				keyboard_input(pblock, ppos, keycode1);  /*�ı��Ӧ������ֵ*/

				if (pblock) {  /*�����ڲ����������������²���*/
					cct_getxy(x, y);  /*ȡ��ǰ���λ��*/

					if (ppos == 2 && fontsize == 0)  /*�����ڲ����ڶ�λ�Ҳ���������Ϊ�㣬˵������ǰ�ڶ�λ��Ϊ�գ������λ���Լ������������Լ�*/
						ppos--, x--;

					cct_showch(x, y, ' ', OPBX_BG_COLOR, OPBX_FG_COLOR_D);  /*�ڶ�Ӧλ��������ո񣬸���ԭ���֣�Ӫ���˸�Ч��*/
				}

				move_cursor(pblock, ppos);  /*��ɲ������ƶ��������Ӧλ��*/
				break;
			}
		}
	}

	cct_disable_mouse();	//�������

	switch (result) {
	case OPBX_RET_SURE:  /*������ȷ�������������úõ�ֵ���ظ�ʵ�Σ��ﵽ����Ч��*/
		*IF_SOUND = if_sound, * FONTSIZE = fontsize;
		break;
	case OPBX_RET_CANCEL:  /*������ȡ����������ʵ�θ�ֵ���ڲ�ֵ���ﵽȡ��Ч��*/
		if_sound = *IF_SOUND, fontsize = *FONTSIZE;
		break;
	}

	return result;
}