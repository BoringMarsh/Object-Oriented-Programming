#include<iostream>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include"cmd_console_tools.h"
#include"90-b4.h"
#include"interface-inputbox.h"
#include"interface-cover.h"
#include"interface-optionsbox.h"
using namespace std;

/***************************************************************************
  �������ƣ�tick
  ��    �ܣ�ֹͣһ��ʱ�䲢���м�ʱ
  ���������const int sleep_length��ֹͣʱ�䳤�ȣ�ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void tick(const int sleep_length)
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//��ü�����Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ������������

	Sleep(sleep_length);

	QueryPerformanceCounter(&end);		//�����ֹӲ������������

	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;  //���������Ƶ��
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;  //�������������
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;  //���ݼ�����Ƶ�ʼ������������ʱ�䳤�Ȳ����
}

/***************************************************************************
  �������ƣ�pause
  ��    �ܣ�����һ������ļ�ϵ�
  �����������
  �� �� ֵ����
  ˵    ��������س��ż����������ַ��޻���
***************************************************************************/
void pause()
{
	char c;
	while (1) {
		c = _getch();
		if (c == '\r')
			break;
	}
}

/***************************************************************************
  �������ƣ�set_info
  ��    �ܣ�������Ϸ����
  ���������const int difficulty����Ϸ�Ѷȣ�ֻ����
            const int info_type���������ͣ�ֻ����
  �� �� ֵ��int����Ӧ�Ĳ���
  ˵    ������
***************************************************************************/
int set_info(const int difficulty, const int info_type)
{
	int ret = 0;  /*����ֵ*/

	switch (difficulty) {
	/*��*/
	case EASY:
		switch (info_type) {
		case INFO_LINE:
			ret = EASY_LINE;  /*���Ѷ��µ�����*/
			break;
		case INFO_ROW:
			ret = EASY_ROW;  /*���Ѷ��µ�����*/
			break;
		case INFO_BOMB_NUM:
			ret = EASY_BOMB_NUM;  /*���Ѷ��µĵ�����*/
			break;
		}
		break;
	/*�е�*/
	case MEDIUM:
		switch (info_type) {
		case INFO_LINE:
			ret = MEDIUM_LINE;  /*�е��Ѷ��µ�����*/
			break;
		case INFO_ROW:
			ret = MEDIUM_ROW;  /*�е��Ѷ��µ�����*/
			break;
		case INFO_BOMB_NUM:
			ret = MEDIUM_BOMB_NUM;  /*�е��Ѷ��µĵ�����*/
			break;
		}
		break;
	/*����*/
	case HARD:
		switch (info_type) {
		case INFO_LINE:
			ret = HARD_LINE;  /*�����Ѷ��µ�����*/
			break;
		case INFO_ROW:
			ret = HARD_ROW;  /*�����Ѷ��µ�����*/
			break;
		case INFO_BOMB_NUM:
			ret = HARD_BOMB_NUM;  /*�����Ѷ��µĵ�����*/
			break;
		}
		break;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�num_trans_color
  ��    �ܣ�������ֵȡ��Ӧ����ɫ
  ���������const int num����������ֵ��ֻ����
  �� �� ֵ��int����Ӧ��ֵ����ɫ
  ˵    ������
***************************************************************************/
int num_trans_color(const int num)
{
	int ret = 0;  /*����ֵ������Ϊ0*/

	switch (num) {
	case '*' - '0':
		ret = COLOR_BLACK;  /*���ף���Ӧ��ɫ*/
		break;
	case 0:
		ret = COLOR_HWHITE;  /*0����Ӧ����ɫ*/
		break;
	case 1:
		ret = COLOR_BLUE;    /*1����Ӧ��ɫ*/
		break;
	case 2:
		ret = COLOR_GREEN;   /*2����Ӧ��ɫ*/
		break;
	case 3:
		ret = COLOR_HRED;    /*3����Ӧ����ɫ*/
		break;
	case 4:
		ret = COLOR_PINK;    /*4����Ӧ��ɫ*/
		break;
	case 5:
		ret = COLOR_RED;     /*5����Ӧ��ɫ*/
		break;
	case 6:
		ret = COLOR_HCYAN;   /*6����Ӧ����ɫ*/
		break;
	case 7:
		ret = COLOR_BLACK;   /*7����Ӧ��ɫ*/
		break;
	case 8:
		ret = COLOR_HBLACK;  /*8����Ӧ����ɫ*/
		break;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�if_end
  ��    �ܣ��ж���Ϸ�Ƿ����
  ���������const matrix MATRIX[]��������Ϸ���ڲ��ṹ�����飨ֻ����
            const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
  �� �� ֵ��bool����Ϸ�Ƿ����
  ˵    ������
***************************************************************************/
bool if_end(const matrix MATRIX[], const int line, const int row)
{
	bool ret = true;  /*����ֵ������Ϊ��*/

	for (int i = 0; i < line * row; i++) {  /*����������Ԫ�أ���δ������Ԫ�����в����׵�Ԫ�أ�����Ϸδ����*/
		if (!MATRIX[i].if_turned && MATRIX[i].num != '*') {
			ret = false;  /*����ֵ��Ϊ�ٲ��������*/
			break;
		}
	}

	return ret;
}

/***************************************************************************
  �������ƣ�inputbox_erase
  ��    �ܣ��ػ����⻭�棬�ﵽ�����Ի����Ч��
  �����������
  �� �� ֵ����
  ˵    �����������ػ���������Ӧ���Ǽ����Լ��������ֺͲ��ֱ���ס�İ���
***************************************************************************/
void inputbox_erase()
{
	cct_gotoxy(0, IPBX_COORD_Y);
	const char* String = "��                                                                            ��";

	/*1�����ϱ���*/
	for (int i = 0; i < INPUTBOX.get_width(); i++)
		cct_showstr(0, IPBX_COORD_Y + i, String, COLOR_WHITE, COLOR_BLACK);

	/*2���ػ����׼�����������*/
	COVER.bomb_reprint();
	COVER.button_reprint();

	/*3���ػ�������ĸ*/
	COVER.M_print();
	COVER.I_print();
	COVER.N_print();
	COVER.E_print(1);
	COVER.S_print();
	COVER.W_print();
	COVER.E_print(2);
	COVER.E_print(3);
	COVER.P_print();
	COVER.E_print(4);
	COVER.R_print();
}

/***************************************************************************
  �������ƣ�optionsbox_erase
  ��    �ܣ��ػ����öԻ��򣬴ﵽ�����Ի����Ч��
  �����������
  �� �� ֵ����
  ˵    �����������ػ������öԻ����Ӧ���Ǽ����Լ��������ֺͲ��ֱ���ס�İ���
***************************************************************************/
void optionsbox_erase()
{
	cct_gotoxy(0, OPBX_COORD_Y);
	const char* String = "��                                                                            ��";

	/*1�����ϱ���*/
	for (int i = 0; i < OPTIONSBOX.get_width(); i++)
		cct_showstr(0, OPBX_COORD_Y + i, String, COLOR_WHITE, COLOR_BLACK);

	/*2���ػ����׼�����������*/
	COVER.bomb_reprint();
	COVER.button_reprint();

	/*3���ػ�������ĸ*/
	COVER.M_print();
	COVER.I_print();
	COVER.N_print();
	COVER.E_print(1);
	COVER.S_print();
	COVER.W_print();
	COVER.E_print(2);
	COVER.E_print(3);
	COVER.P_print();
	COVER.E_print(4);
	COVER.R_print();
}