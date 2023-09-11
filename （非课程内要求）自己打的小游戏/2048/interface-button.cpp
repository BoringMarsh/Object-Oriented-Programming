#include"90-b3.h"

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
	case KB_UP:
		if (act_mode == ACTIVATE)
			set_color(COLOR_RED, COLOR_WHITE);  /*С�����ϼ�ͷ�����ø�����ɫ*/
		else
			set_color(COLOR_RED, COLOR_BLACK);  /*С�����ϼ�ͷ��ȡ��������ɫ*/
		print_keyboard_button(BLOCK_ARROW_MODE_UP, bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case KB_DOWN:
		if (act_mode == ACTIVATE)
			set_color(COLOR_YELLOW, COLOR_WHITE);  /*С�����¼�ͷ�����ø�����ɫ*/
		else
			set_color(COLOR_YELLOW, COLOR_BLACK);  /*С�����¼�ͷ��ȡ��������ɫ*/
		print_keyboard_button(BLOCK_ARROW_MODE_DOWN, bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case KB_LEFT:
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLUE, COLOR_WHITE);  /*С�������ͷ�����ø�����ɫ*/
		else
			set_color(COLOR_BLUE, COLOR_BLACK);  /*С�������ͷ��ȡ��������ɫ*/
		print_keyboard_button(BLOCK_ARROW_MODE_LEFT, bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case KB_RIGHT:
		if (act_mode == ACTIVATE)
			set_color(COLOR_GREEN, COLOR_WHITE);  /*С�����Ҽ�ͷ�����ø�����ɫ*/
		else
			set_color(COLOR_GREEN, COLOR_BLACK);  /*С�����Ҽ�ͷ��ȡ��������ɫ*/
		print_keyboard_button(BLOCK_ARROW_MODE_RIGHT, bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case KB_Q:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HRED, COLOR_WHITE);  /*С���̹��ܼ�Q���ø�����ɫ*/
		else
			set_color(COLOR_HRED, COLOR_BLACK);  /*С���̹��ܼ�Qȡ��������ɫ*/
		cct_showch(x, y, 'Q', bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case KB_R:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HYELLOW, COLOR_WHITE);  /*С���̹��ܼ�R���ø�����ɫ*/
		else
			set_color(COLOR_HYELLOW, COLOR_BLACK);  /*С���̹��ܼ�Rȡ��������ɫ*/
		cct_showch(x, y, 'R', bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case KB_S:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HBLUE, COLOR_WHITE);  /*С���̹��ܼ�S���ø�����ɫ*/
		else
			set_color(COLOR_HBLUE, COLOR_BLACK);  /*С���̹��ܼ�Sȡ��������ɫ*/
		cct_showch(x, y, 'S', bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case KB_D:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HGREEN, COLOR_WHITE);  /*С���̹��ܼ�D���ø�����ɫ*/
		else
			set_color(COLOR_HGREEN, COLOR_BLACK);  /*С���̹��ܼ�Dȡ��������ɫ*/
		cct_showch(x, y, 'D', bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case KB_O:
		if (act_mode == ACTIVATE)
			set_color(COLOR_HBLACK, COLOR_WHITE);  /*С���̹��ܼ�O���ø�����ɫ*/
		else
			set_color(COLOR_HBLACK, COLOR_BLACK);  /*С���̹��ܼ�Oȡ��������ɫ*/
		cct_showch(x, y, 'O', bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case GMMB_YES:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*��Ϸ�ڶԻ����ǡ������ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*��Ϸ�ڶԻ����ǡ���ȡ��������ɫ*/
		cct_showstr(x, y, "��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_NO:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*��Ϸ�ڶԻ��򡰷񡱼����ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*��Ϸ�ڶԻ��򡰷񡱼�ȡ��������ɫ*/
		cct_showstr(x, y, "��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_SURE:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*��Ϸ�ڶԻ���ȷ���������ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*��Ϸ�ڶԻ���ȷ������ȡ��������ɫ*/
		cct_showstr(x, y, "ȷ��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "����", bg_color, fg_color);
		break;
	case GMMB_ONE:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*��Ϸ�ڶԻ���1�������ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*��Ϸ�ڶԻ���1����ȡ��������ɫ*/
		cct_showstr(x, y, "1 ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_TWO:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*��Ϸ�ڶԻ���2�������ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*��Ϸ�ڶԻ���2����ȡ��������ɫ*/
		cct_showstr(x, y, "2 ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_THREE:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*��Ϸ�ڶԻ���3�������ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*��Ϸ�ڶԻ���3����ȡ��������ɫ*/
		cct_showstr(x, y, "3 ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_FOUR:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*��Ϸ�ڶԻ���4�������ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*��Ϸ�ڶԻ���4����ȡ��������ɫ*/
		cct_showstr(x, y, "4 ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_CANCEL:
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*��Ϸ�ڶԻ���ȡ���������ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*��Ϸ�ڶԻ���ȡ������ȡ��������ɫ*/
		cct_showstr(x, y, "ȡ��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "����", bg_color, fg_color);
		break;
	case GMMB_SW11:
	case GMMB_SW12:
	case GMMB_SW21:
	case GMMB_SW22:
		if (act_mode == ACTIVATE)
			set_color(GMMBSW_BG_COLOR_A, GMMBSW_FG_COLOR);  /*��Ϸ�ڶԻ��򿪹ذ������ø���*/
		else
			set_color(GMMBSW_BG_COLOR_D, GMMBSW_FG_COLOR);  /*��Ϸ�ڶԻ��򿪹ذ���ȡ������*/
		print_switch_button(bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CVMB_YES:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���⻭��Ի����ǡ������ø���*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*���⻭��Ի����ǡ���ȡ������*/
		cct_showstr(x, y, "��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_NO:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���⻭��Ի��򡰷񡱼����ø���*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*���⻭��Ի��򡰷񡱼�ȡ������*/
		cct_showstr(x, y, "��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_SURE:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���⻭��Ի���ȷ���������ø���*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*���⻭��Ի���ȷ������ȡ������*/
		cct_showstr(x, y, "ȷ��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "����", bg_color, fg_color);
		break;
	case CVMB_ONE:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���⻭��Ի���1�������ø���*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*���⻭��Ի���1����ȡ������*/
		cct_showstr(x, y, "1 ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_TWO:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���⻭��Ի���2�������ø���*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*���⻭��Ի���2����ȡ������*/
		cct_showstr(x, y, "2 ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_THREE:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���⻭��Ի���3�������ø���*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*���⻭��Ի���3����ȡ������*/
		cct_showstr(x, y, "3 ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_FOUR:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���⻭��Ի���4�������ø���*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*���⻭��Ի���4����ȡ������*/
		cct_showstr(x, y, "4 ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_CANCEL:
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���⻭��Ի���ȡ���������ø���*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*���⻭��Ի���ȡ������ȡ������*/
		cct_showstr(x, y, "ȡ��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "����", bg_color, fg_color);
		break;
	case CVMB_SW11:
	case CVMB_SW12:
	case CVMB_SW21:
	case CVMB_SW22:
		if (act_mode == ACTIVATE)
			set_color(CVMBSW_BG_COLOR_A, CVMBSW_FG_COLOR);  /*���⻭��Ի��򿪹ذ������ø���*/
		else
			set_color(CVMBSW_BG_COLOR_D, CVMBSW_FG_COLOR);  /*���⻭��Ի��򿪹ذ���ȡ������*/
		print_switch_button(bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_NEW:
		if (act_mode == ACTIVATE)
			set_color(COLOR_RED, COLOR_BLACK);  /*���⻭�桰����Ϸ�������ø���*/
		else
			set_color(COLOR_HRED, COLOR_BLACK);  /*���⻭�桰����Ϸ����ȡ������*/
		print_cover_button(" ����Ϸ ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_LOAD:
		if (act_mode == ACTIVATE)
			set_color(COLOR_YELLOW, COLOR_BLACK);  /*���⻭�桰������Ϸ�������ø���*/
		else
			set_color(COLOR_HYELLOW, COLOR_BLACK);  /*���⻭�桰������Ϸ����ȡ������*/
		print_cover_button("������Ϸ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_AUTO:
		if (act_mode == ACTIVATE)
			set_color(COLOR_CYAN, COLOR_BLACK);  /*���⻭�桰�Զ���Ϸ�������ø���*/
		else
			set_color(COLOR_HCYAN, COLOR_BLACK);  /*���⻭�桰�Զ���Ϸ����ȡ������*/
		print_cover_button("�Զ���Ϸ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_OPTIONS:
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLUE, COLOR_BLACK);  /*���⻭�桰���á������ø���*/
		else
			set_color(COLOR_HBLUE, COLOR_BLACK);  /*���⻭�桰���á���ȡ������*/
		print_cover_button("  ����  ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_ABOUT:
		if (act_mode == ACTIVATE)
			set_color(COLOR_GREEN, COLOR_BLACK);  /*���⻭�桰���ڡ������ø���*/
		else
			set_color(COLOR_HGREEN, COLOR_BLACK);  /*���⻭�桰���ڡ���ȡ������*/
		print_cover_button("  ����  ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_QUIT:
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLACK, COLOR_HWHITE);  /*���⻭�桰�˳���Ϸ�������ø���*/
		else
			set_color(COLOR_HBLACK, COLOR_HWHITE);  /*���⻭�桰�˳���Ϸ����ȡ������*/
		print_cover_button("�˳���Ϸ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	}
}