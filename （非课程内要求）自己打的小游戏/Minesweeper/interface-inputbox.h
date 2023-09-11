#pragma once
#include"interface-button.h"

//��������������ķ���ֵ
#define IPBX_RET_SURE    1  //ȷ��
#define IPBX_RET_CANCEL  2  //ȡ��

//��������ɫ
#define IPBX_BG_COLOR    COLOR_YELLOW  //����ɫ
#define IPBX_FG_COLOR_A  COLOR_HWHITE  //����ǰ��ɫ
#define IPBX_FG_COLOR_D  COLOR_BLACK   //����ǰ��ɫ

//���������ֵ�����
#define IPBX_COORD_X  24  //��������ϽǺ�����
#define IPBX_COORD_Y  10  //��������Ͻ�������
#define IPPROM_COORD_X1    IPBX_COORD_X+2  //������У���ʾ��1���ϽǺ�����
#define IPPROM_COORD_Y1    IPBX_COORD_Y+2  //������У���ʾ��1���Ͻ�������
#define IPPROM_COORD_X2    IPBX_COORD_X+2  //������У���ʾ��2���ϽǺ�����
#define IPPROM_COORD_Y2    IPBX_COORD_Y+6  //������У���ʾ��2���Ͻ�������
#define IPLINE_COORD_X    IPBX_COORD_X+4   //������У�������������ϽǺ�����
#define IPLINE_COORD_Y    IPBX_COORD_Y+3   //������У�������������Ͻ�������
#define IPROW_COORD_X     IPBX_COORD_X+14  //������У�������������ϽǺ�����
#define IPROW_COORD_Y     IPBX_COORD_Y+3   //������У�������������Ͻ�������
#define IPBOMB_COORD_X    IPBX_COORD_X+24  //������У���������������ϽǺ�����
#define IPBOMB_COORD_Y    IPBX_COORD_Y+3   //������У���������������Ͻ�������
#define IPSURE_COORD_X    IPBX_COORD_X+10  //������У���ȷ���������ϽǺ�����
#define IPSURE_COORD_Y    IPBX_COORD_Y+7   //������У���ȷ���������Ͻ�������
#define IPCANCEL_COORD_X  IPBX_COORD_X+20  //������У���ȡ���������ϽǺ�����
#define IPCANCEL_COORD_Y  IPBX_COORD_Y+7   //������У���ȡ���������Ͻ�������

//����򰴼���
#define IPBX_BUTTON_NUM  5

//������������
class inputbox {
private:
	button button_ipline;  //���������
	button button_iprow;   //���������
	button button_ipbomb;  //�����������
	button button_sure;    //��ȷ������
	button button_cancel;  //��ȡ������
	int line;        //���������������ʱ�ı��ֵ���������ٸ���ʵ�Σ�
	int row;         //���������������ʱ�ı��ֵ���������ٸ���ʵ�Σ�
	int bomb_num;    //�����������������ʱ�ı��ֵ���������ٸ���ʵ�Σ�
	const int IPBX_WIDTH;  //�������
public:
	int get_width();  //ȡ�������
	void print(const char* prompt);  //��ӡ�����
	int mouse_if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	void selective_default(const int selection);    //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);   //ѡ���Ե�Ϊĳһ�������ø���
	void move_cursor(const int pblock, const int ppos);  //�������ڲ����ı�����λ�����ƶ��������Ӧλ��
	void keyboard_input(const int pblock, const int ppos, const int keycode);  //�������ڲ����ı�����λ������������ֵ���ı��Ӧ������ֵ
	int info_check();  //�������������Ƿ����
	int control(int* LINE, int* ROW, int* BOMB_NUM);  //�ü�����������ڽ��в���

	//���캯��
	inputbox() :button_ipline(IPLINE_COORD_X, IPLINE_COORD_Y, IPBX_IPLINE),
		button_iprow(IPROW_COORD_X, IPROW_COORD_Y, IPBX_IPROW),
		button_ipbomb(IPBOMB_COORD_X, IPBOMB_COORD_Y, IPBX_IPBOMB),
		button_sure(IPSURE_COORD_X, IPSURE_COORD_Y, IPBX_SURE),
		button_cancel(IPCANCEL_COORD_X, IPCANCEL_COORD_Y, IPBX_CANCEL),
		line(0), row(0), bomb_num(0), IPBX_WIDTH(10) {}
};