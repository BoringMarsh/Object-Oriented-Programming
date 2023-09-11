#include"colorball.h"
#include"interface-button.h"

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
  �������ƣ�act
  ��    �ܣ����ݰ�����������ְ���Ч��
  ���������const int act_mode��Ч��ģʽ��ֻ����
  �� �� ֵ����
  ˵    ����1���ú�������Ϊĳһ����ȡ��������Ҳ���Դﵽ��ӡ�ð�����Ч��
            2���ú����洢�����а����ĸ������Ч��
***************************************************************************/
void button::act(const int act_mode)
{
	cct_gotoxy(x, y);  /*�ƶ������ָ��λ��*/

	switch (type) {  /*���ݰ������಻ͬ���ö�Ӧ��ɫ����ӡ*/
	case GAME_OPTIONS:  /*��Ϸ�ڣ������á���*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLACK, COLOR_HWHITE);  /*���ø�����ɫ*/
		else
			set_color(COLOR_HBLACK, COLOR_HWHITE);  /*ȡ��������ɫ*/
		print_game_button(x, y, " ���� ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case GAME_SAVE:  /*��Ϸ�ڣ������桱��*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLUE, COLOR_HWHITE);  /*���ø�����ɫ*/
		else
			set_color(COLOR_HBLUE, COLOR_HWHITE);  /*ȡ��������ɫ*/
		print_game_button(x, y, " ���� ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case GAME_DELETE:  /*��Ϸ�ڣ���ɾ������*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_GREEN, COLOR_HWHITE);  /*���ø�����ɫ*/
		else
			set_color(COLOR_HGREEN, COLOR_HWHITE);  /*ȡ��������ɫ*/
		print_game_button(x, y, " ɾ�� ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case GAME_QUIT:  /*��Ϸ�ڣ����˳�����*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HBLACK, COLOR_HWHITE);  /*���ø�����ɫ*/
		else
			set_color(COLOR_BLACK, COLOR_HWHITE);  /*ȡ��������ɫ*/
		print_game_button(x, y, " �˳� ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case GMMB_YES:  /*��Ϸ�ڶԻ��򣺡��ǡ���*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_NO:  /*��Ϸ�ڶԻ��򣺡��񡱼�*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_SURE:  /*��Ϸ�ڶԻ��򣺡�ȷ������*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "ȷ��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "����", bg_color, fg_color);
		break;
	case GMMB_ONE:  /*��Ϸ�ڶԻ��򣺡�1����*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "1", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_TWO:  /*��Ϸ�ڶԻ��򣺡�2����*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "2", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_THREE:  /*��Ϸ�ڶԻ��򣺡�3����*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "3", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_FOUR:  /*��Ϸ�ڶԻ��򣺡�4����*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "4", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case GMMB_CANCEL:  /*��Ϸ�ڶԻ��򣺡�ȡ������*/
		if (act_mode == ACTIVATE)
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(GMMB_KEYS_BG_COLOR, GMMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "ȡ��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "����", bg_color, fg_color);
		break;
	case GMMB_SW11:  /*��Ϸ�ڶԻ��򣺿���1����1*/
	case GMMB_SW12:  /*��Ϸ�ڶԻ��򣺿���1����2*/
	case GMMB_SW21:  /*��Ϸ�ڶԻ��򣺿���2����1*/
	case GMMB_SW22:  /*��Ϸ�ڶԻ��򣺿���2����2*/
		if (act_mode == ACTIVATE)
			set_color(GMMBSW_BG_COLOR_A, GMMBSW_FG_COLOR);  /*���ø�����ɫ*/
		else
			set_color(GMMBSW_BG_COLOR_D, GMMBSW_FG_COLOR);  /*ȡ��������ɫ*/
		print_switch_button(bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_NEW:  /*���⻭�棺������Ϸ����*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HRED, COLOR_HWHITE);  /*���ø�����ɫ*/
		else
			set_color(COLOR_RED, COLOR_HWHITE);  /*ȡ��������ɫ*/
		print_cover_button(" ����Ϸ ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_LOAD:  /*���⻭�棺��������Ϸ����*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HBLUE, COLOR_HWHITE);  /*���ø�����ɫ*/
		else
			set_color(COLOR_BLUE, COLOR_HWHITE);  /*ȡ��������ɫ*/
		print_cover_button("������Ϸ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_OPTIONS:  /*���⻭�棺�����á���*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HGREEN, COLOR_HWHITE);  /*���ø�����ɫ*/
		else
			set_color(COLOR_GREEN, COLOR_HWHITE);  /*ȡ��������ɫ*/
		print_cover_button("  ����  ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_HELP:  /*���⻭�棺����������*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HCYAN, COLOR_HWHITE);  /*���ø�����ɫ*/
		else
			set_color(COLOR_CYAN, COLOR_HWHITE);  /*ȡ��������ɫ*/
		print_cover_button("  ����  ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_HS:  /*���⻭�棺���߷ְ񡱼�*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_HPINK, COLOR_HWHITE);  /*���ø�����ɫ*/
		else
			set_color(COLOR_PINK, COLOR_HWHITE);  /*ȡ��������ɫ*/
		print_cover_button(" �߷ְ� ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CV_EXIT:  /*���⻭�棺���˳�����*/
		if (act_mode == ACTIVATE)
			set_color(COLOR_BLACK, COLOR_HWHITE);  /*���ø�����ɫ*/
		else
			set_color(COLOR_HBLACK, COLOR_HWHITE);  /*ȡ��������ɫ*/
		print_cover_button("  �˳�  ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case CVMB_YES:  /*���⻭��Ի��򣺡��ǡ���*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_NO:  /*���⻭��Ի��򣺡��񡱼�*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_SURE:  /*���⻭��Ի��򣺡�ȷ������*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "ȷ��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "����", bg_color, fg_color);
		break;
	case CVMB_ONE:  /*���⻭��Ի��򣺡�1����*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "1", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_TWO:  /*���⻭��Ի��򣺡�2����*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "2", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_THREE:  /*���⻭��Ի��򣺡�3����*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "3", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_FOUR:  /*���⻭��Ի��򣺡�4����*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "4", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "��", bg_color, fg_color);
		break;
	case CVMB_CANCEL:  /*���⻭��Ի��򣺡�ȡ������*/
		if (act_mode == ACTIVATE)
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, "ȡ��", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "����", bg_color, fg_color);
		break;
	case OPBX_SETBLINK:  /*���öԻ�����˸���ÿ�*/
	case OPBX_SETSHOW:   /*���öԻ������Ч�����ÿ�*/
	case OPBX_SETSOUND:  /*���öԻ����������ÿ�*/
	case OPBX_SETFONT:   /*���öԻ��������С���ÿ�*/
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);  /*ȡ��������ɫ*/
		print_empty_block(bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		break;
	case OPBX_SURE:  /*���öԻ��򣺡�ȷ������*/
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, " ȷ�� ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "������", bg_color, fg_color);
		break;
	case OPBX_CANCEL:  /*���öԻ��򣺡�ȡ������*/
		if (act_mode == ACTIVATE)
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_A);  /*���ø�����ɫ*/
		else
			set_color(OPBX_BG_COLOR, OPBX_FG_COLOR_D);  /*ȡ��������ɫ*/
		cct_showstr(x, y, " ȡ�� ", bg_color, fg_color);  /*���ú���ɫ���ӡ�ð���*/
		cct_showstr(x, y + 1, "������", bg_color, fg_color);
		break;
	}
}