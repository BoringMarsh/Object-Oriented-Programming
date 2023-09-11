#pragma once
#include"cmd_console_tools.h"

//����Ч������
#define ACTIVATE     0x10001  //ĳһ�������ø���
#define DEFAULT      0x10002  //ĳһ����ȡ������
#define DEFAULT_ALL  0x10003  //���а���ȡ������

//��Ϸ�ڶԻ��򰴼���ɫ
#define GMMB_KEYS_BG_COLOR COLOR_HBLUE
#define GMMB_KEYS_FG_COLOR_A COLOR_HWHITE
#define GMMB_KEYS_FG_COLOR_D COLOR_BLACK

//��������ɫ
#define IPBX_BG_COLOR    COLOR_YELLOW  //����ɫ
#define IPBX_FG_COLOR_A  COLOR_HWHITE  //����ǰ��ɫ
#define IPBX_FG_COLOR_D  COLOR_BLACK   //����ǰ��ɫ

//���öԻ������ɫ
#define OPBX_BG_COLOR    COLOR_HBLACK
#define OPBX_FG_COLOR_A  COLOR_HWHITE
#define OPBX_FG_COLOR_D  COLOR_BLACK

//��Ϸ�ڶԻ��򰴼�����
#define GMMB_YES  1001  //���ǡ���
#define GMMB_NO   1002  //���񡱼�
#define GMMB_SURE 1003  //��ȷ������

//���⻭�水������
#define CV_EASY     2001  //���򵥡���
#define CV_MEDIUM   2002  //���еȡ���
#define CV_HARD     2003  //�����ѡ���
#define CV_DIY      2004  //���Զ��塱��
#define CV_OPTIONS  2005  //�����á���
#define CV_QUIT     2006  //���˳�����

//����򰴼�����
#define IPBX_IPLINE  3001  //���������
#define IPBX_IPROW   3002  //���������
#define IPBX_IPBOMB  3003  //�����������
#define IPBX_SURE    3004  //��ȷ������
#define IPBX_CANCEL  3005  //��ȡ������

//���öԻ��򰴼�����
#define OPBX_SETSOUND  4001  //�������ÿ�
#define OPBX_SETFONT   4002  //�����С���ÿ�
#define OPBX_SURE      4003  //��ȷ������
#define OPBX_CANCEL    4004  //��ȡ������

/*�����������*/
class button {
private:
	int x;         //�������ϽǺ�����
	int y;         //�������Ͻ�������
	int bg_color;  //��������ɫ
	int fg_color;  //����ǰ��ɫ
	int type;      //��������
public:
	void set_color(const int BG_COLOR, const int FG_COLOR);  //������������ɫ
	void set_coord(const int X, const int Y);  //�������������Ͻ�����
	void set_type(const int TYPE);  //��������������
	void act(const int act_mode);   //���ݰ�����������ְ���Ч��

	button(const int X, const int Y, const int TYPE) :x(X), y(Y), type(TYPE) {  //���캯��
		bg_color = COLOR_BLACK;
		fg_color = COLOR_BLACK;
	}
};