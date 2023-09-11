#pragma once
#include"interface-button.h"

//�����öԻ����������ķ���ֵ
#define OPBX_RET_SURE    1  //ȷ��
#define OPBX_RET_CANCEL  2  //ȡ��

//���öԻ������ɫ
#define OPBX_BG_COLOR    COLOR_HBLACK
#define OPBX_FG_COLOR_A  COLOR_HWHITE
#define OPBX_FG_COLOR_D  COLOR_BLACK

//���öԻ�������ֵ�����
#define OPBX_COORD_X  29  //���öԻ������ϽǺ�����
#define OPBX_COORD_Y  10  //���öԻ������Ͻ�������
#define OPPROM_COORD_X1  OPBX_COORD_X+2    //���öԻ����У���ʾ��1���ϽǺ�����
#define OPPROM_COORD_Y1  OPBX_COORD_Y+2    //���öԻ����У���ʾ��1���Ͻ�������
#define OPPROM_COORD_X2  OPBX_COORD_X+2    //���öԻ����У���ʾ��2���ϽǺ�����
#define OPPROM_COORD_Y2  OPBX_COORD_Y+6    //���öԻ����У���ʾ��2���Ͻ�������
#define SETSOUND_COORD_X  OPBX_COORD_X+4   //���öԻ����У��������ÿ����ϽǺ�����
#define SETSOUND_COORD_Y  OPBX_COORD_Y+3   //���öԻ����У��������ÿ����Ͻ�������
#define SETFONT_COORD_X   OPBX_COORD_X+14  //���öԻ����У������С���ÿ����ϽǺ�����
#define SETFONT_COORD_Y   OPBX_COORD_Y+3   //���öԻ����У������С���ÿ����Ͻ�������
#define OPSURE_COORD_X    OPBX_COORD_X+4   //���öԻ����У���ȷ���������ϽǺ�����
#define OPSURE_COORD_Y    OPBX_COORD_Y+7   //���öԻ����У���ȷ���������Ͻ�������
#define OPCANCEL_COORD_X  OPBX_COORD_X+14  //���öԻ����У���ȡ���������ϽǺ�����
#define OPCANCEL_COORD_Y  OPBX_COORD_Y+7   //���öԻ����У���ȡ���������Ͻ�������

//���öԻ��򰴼���
#define OPBX_BUTTON_NUM  4

class optionsbox {
private:
	button button_setsound;  //�������ÿ�
	button button_setfont;   //�����С���ÿ�
	button button_sure;      //��ȷ������
	button button_cancel;    //��ȡ������
	bool if_sound;   //�Ƿ������������������ʱ�ı��ֵ���������ٸ���ʵ�Σ�
	int fontsize;    //�����С�����������ʱ�ı��ֵ���������ٸ���ʵ�Σ�
	const int OPBX_WIDTH;  //���öԻ���Ŀ��
public:
	int get_width();  //ȡ���öԻ�����
	bool get_if_sound();  //ȡ�Ƿ�������
	int get_fontsize();   //ȡ�����С
	char* read_fontsize(char* String);  //��ȡ�����С��ת�����ַ���
	void print(const char* prompt);  //��ӡ���öԻ���
	int mouse_if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	void selective_default(const int selection);    //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);   //ѡ���Ե�Ϊĳһ�������ø���
	void move_cursor(const bool pblock, const int ppos);  //���ݲ������������λ�����ƶ��������Ӧλ��
	void keyboard_input(const bool pblock, const int ppos, const int keycode);    //���ݲ������������λ������������ֵ���ı��Ӧ������ֵ
	int info_check();  //�������������Ƿ����
	int control(bool* IF_SOUND, int* FONTSIZE);  //�ü��������öԻ����ڽ��в���

	//���캯��
	optionsbox() :button_setsound(SETSOUND_COORD_X, SETSOUND_COORD_Y, OPBX_SETSOUND),
		button_setfont(SETFONT_COORD_X, SETFONT_COORD_Y, OPBX_SETFONT),
		button_sure(OPSURE_COORD_X, OPSURE_COORD_Y, OPBX_SURE),
		button_cancel(OPCANCEL_COORD_X, OPCANCEL_COORD_Y, OPBX_CANCEL),
		if_sound(true), fontsize(28), OPBX_WIDTH(10) {}
};