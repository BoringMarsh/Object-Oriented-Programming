#include<Windows.h>
#include"player.h"
#include"interface-optionsbox.h"
#include"interface-cover.h"

/***************************************************************************
  �������ƣ�read_fontsize
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
  ��    �ܣ���ӡ���⻭��Ի���
  ���������const char* prompt1����ʾ��1��ֻ����Ĭ��Ϊ��ָ�룩
			const char* prompt2����ʾ��2��ֻ����Ĭ��Ϊ��ָ�룩
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void optionsbox::print(const char* prompt1, const char* prompt2)
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
	cct_showstr(OPPROM_COORD_X1, OPPROM_COORD_Y1, prompt1, OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	cct_showstr(OPPROM_COORD_X2, OPPROM_COORD_Y2, prompt2, OPBX_BG_COLOR, OPBX_FG_COLOR_D);

	/*3����ӡ���öԻ��򰴼�*/
	button_setblink.act(DEFAULT);  /*��ӡ��˸���ÿ�*/
	button_setshow.act(DEFAULT);   /*��ӡ���Ч�����ÿ�*/
	button_setsound.act(DEFAULT);  /*��ӡ�������ÿ�*/
	button_setfont.act(DEFAULT);   /*��ӡ�����С���ÿ�*/
	button_sure.act(DEFAULT);      /*��ӡ��ȷ������*/
	button_cancel.act(DEFAULT);    /*��ӡ��ȡ������*/

	/*4���������������ӡ����״̬*/
	if (if_blink)  /*�Ƿ���˸*/
		cct_showstr(SETBLINK_COORD_X + 2, SETBLINK_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	else
		cct_showstr(SETBLINK_COORD_X + 2, SETBLINK_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);

	if (if_show)  /*�Ƿ������Ч��*/
		cct_showstr(SETSHOW_COORD_X + 2, SETSHOW_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	else
		cct_showstr(SETSHOW_COORD_X + 2, SETSHOW_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);

	if (if_sound)  /*�Ƿ�������*/
		cct_showstr(SETSOUND_COORD_X + 2, SETSOUND_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
	else
		cct_showstr(SETSOUND_COORD_X + 2, SETSOUND_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
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

	if (X >= SETBLINK_COORD_X && X <= SETBLINK_COORD_X + 5 && Y >= SETBLINK_COORD_Y && Y <= SETBLINK_COORD_Y + 2)  /*�ж��Ƿ�����˸���ÿ���*/
		p[0] = true;
	if (X >= SETSHOW_COORD_X && X <= SETSHOW_COORD_X + 5 && Y >= SETSHOW_COORD_Y && Y <= SETSHOW_COORD_Y + 2)      /*�ж��Ƿ������Ч�����ÿ���*/
		p[1] = true;
	if (X >= SETSOUND_COORD_X && X <= SETSOUND_COORD_X + 5 && Y >= SETSOUND_COORD_Y && Y <= SETSOUND_COORD_Y + 2)  /*�ж��Ƿ����������ÿ���*/
		p[2] = true;
	if (X >= SETFONT_COORD_X && X <= SETFONT_COORD_X + 5 && Y >= SETFONT_COORD_Y && Y <= SETFONT_COORD_Y + 2)      /*�ж��Ƿ��������С���ÿ���*/
		p[3] = true;
	if (X >= OPSURE_COORD_X && X <= OPSURE_COORD_X + 5 && Y >= OPSURE_COORD_Y && Y <= OPSURE_COORD_Y + 1)          /*�ж��Ƿ��ڡ�ȷ��������*/
		p[4] = true;
	if (X >= OPCANCEL_COORD_X && X <= OPCANCEL_COORD_X + 5 && Y >= OPCANCEL_COORD_Y && Y <= OPCANCEL_COORD_Y + 1)  /*�ж��Ƿ��ڡ�ȡ��������*/
		p[5] = true;

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
		button_setblink.act(DEFAULT);  /*��˸���ÿ�ȡ������*/
		break;
	case 2:
		button_setshow.act(DEFAULT);   /*���Ч�����ÿ�ȡ������*/
		break;
	case 3:
		button_setsound.act(DEFAULT);  /*�������ÿ�ȡ������*/
		break;
	case 4:
		button_setfont.act(DEFAULT);   /*�����С���ÿ�ȡ������*/
		break;
	case 5:
		button_sure.act(DEFAULT);      /*��ȷ������ȡ������*/
		break;
	case 6:
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
		button_setblink.act(ACTIVATE);  /*��˸���ÿ�ȡ������*/
		break;
	case 2:
		button_setshow.act(ACTIVATE);   /*���Ч�����ÿ�ȡ������*/
		break;
	case 3:
		button_setsound.act(ACTIVATE);  /*�������ÿ����ø���*/
		break;
	case 4:
		button_setfont.act(ACTIVATE);   /*�����С���ÿ����ø���*/
		break;
	case 5:
		button_sure.act(ACTIVATE);      /*��ȷ���������ø���*/
		break;
	case 6:
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
  �� �� ֵ��bool���������Ƿ����
  ˵    �����������������������������������������ʾ��Ӧ����ʾ��
***************************************************************************/
bool optionsbox::info_check()
{
	bool ret = false;  /*����ֵ������Ϊ��*/

	if (fontsize == 0) {  /*�����СΪ������*/
		cct_showstr(OPPROM_COORD_X3, OPPROM_COORD_Y3, "�����С����Ϊ�㣡", OPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(OPPROM_COORD_X3, OPPROM_COORD_Y3, "                  ", OPBX_BG_COLOR, COLOR_RED);
	}

	else if (fontsize % 2 == 1) {  /*�����СΪ���������*/
		cct_showstr(OPPROM_COORD_X3, OPPROM_COORD_Y3, "�����С����Ϊ������", OPBX_BG_COLOR, COLOR_RED);
		Sleep(500);
		cct_showstr(OPPROM_COORD_X3, OPPROM_COORD_Y3, "                    ", OPBX_BG_COLOR, COLOR_BLUE);
	}

	else  /*����������������ֵ��Ϊ��*/
		ret = true;

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

				switch (if_blink) {
				case true:
					if_blink = false;  /*������ǰ����˸������Ϊ�٣��������ÿ����ַ���Ϊ��*/
					cct_showstr(SETBLINK_COORD_X + 2, SETBLINK_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				case false:
					if_blink = true;  /*������ǰ����˸������Ϊ�٣��������ÿ����ַ���Ϊ��*/
					cct_showstr(SETBLINK_COORD_X + 2, SETBLINK_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				}
				break;
			case 2:
				pblock = false;  /*δ���в��������������Ϊ��*/
				cct_setcursor(CURSOR_INVISIBLE);  /*���ع��*/

				switch (if_show) {
				case true:
					if_show = false;  /*������ǰ�����Ч��������Ϊ�٣��������ÿ����ַ���Ϊ��*/
					cct_showstr(SETSHOW_COORD_X + 2, SETSHOW_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				case false:
					if_show = true;  /*������ǰ�����Ч��������Ϊ�٣��������ÿ����ַ���Ϊ��*/
					cct_showstr(SETSHOW_COORD_X + 2, SETSHOW_COORD_Y + 1, "��", OPBX_BG_COLOR, OPBX_FG_COLOR_D);
					break;
				}
				break;
			case 3:
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
			case 4:
				pblock = true;  /*���в��������������Ϊ��*/
				cct_setcursor(CURSOR_VISIBLE_NORMAL);  /*��ʾ���*/
				break;
			case 5:
				cct_setcursor(CURSOR_INVISIBLE);  /*�����˳����öԻ������ع��*/

				switch (info_check()) {  /*��������������Ƿ������������ȡ����ֵ��������룬������������������*/
				case true:
					result = OPBX_RET_SURE, loop = 0;
					break;
				case false:
					continue;
					break;
				}
				break;
			case 6:
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

				switch (info_check()) {  /*��������������Ƿ������������ȡ����ֵ��������룬������������������*/
				case true:
					result = OPBX_RET_SURE, loop = 0;
					break;
				case false:
					continue;
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
		*IF_SOUND = if_sound;
		*FONTSIZE = fontsize;
		player::if_blink = if_blink;
		player::if_show = if_show;
		break;
	case OPBX_RET_CANCEL:  /*������ȡ����������ʵ�θ�ֵ���ڲ�ֵ���ﵽȡ��Ч��*/
		if_sound = *IF_SOUND;
		fontsize = *FONTSIZE;
		if_blink = player::if_blink;
		if_show = player::if_show;
		break;
	}

	return result;
}

/***************************************************************************
  �������ƣ�erase
  ��    �ܣ��ػ����⻭�棬�ﵽ�����Ի����Ч��
  ���������cover& TitleScreen�����⻭�����
  �� �� ֵ����
  ˵    �����������ػ��˶Ի����Ӧ���Ǽ����Լ��������ֺ���������ס�Ĳ���
***************************************************************************/
void optionsbox::erase(cover& TitleScreen)
{
	int i;

	/*1�����ϱ���*/
	for (i = 0; i < OPBX_WIDTH; i++)
		cct_showstr(0, OPBX_COORD_Y + i, "��                                                                            ��", COLOR_WHITE, COLOR_BLACK);  /*�����ػ�����*/

	/*2�����ϱ��⻭���ϵ���������*/
	TitleScreen.O_print(1);  /*��һ����ĸO*/
	TitleScreen.O_print(2);  /*�ڶ�����ĸO*/
	TitleScreen.B_print();   /*��ĸB*/
	TitleScreen.A_print();   /*��ĸA*/
	TitleScreen.L_print(2);  /*�ڶ�����ĸL*/
	TitleScreen.L_print(3);  /*��������ĸL*/
	TitleScreen.ball_print(5, 10, COLOR_YELLOW);  /*��ɫ����*/
	TitleScreen.ball_print(22, 13, COLOR_GREEN);  /*��ɫ����*/
	TitleScreen.ball_print(60, 5, COLOR_BLUE);    /*��ɫ����*/
	TitleScreen.ball_print(72, 21, COLOR_PINK);   /*��ɫ����*/
	TitleScreen.button_new.act(DEFAULT);      /*������Ϸ����*/
	TitleScreen.button_load.act(DEFAULT);     /*��������Ϸ����*/
	TitleScreen.button_options.act(DEFAULT);  /*�����á���*/
}