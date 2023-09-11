#pragma once
#include"cmd_console_tools.h"

//����Ч������
#define ACTIVATE     0x10001  //ĳһ�������ø���
#define DEFAULT      0x10002  //ĳһ����ȡ������
#define DEFAULT_ALL  0x10003  //���а���ȡ������

//��Ϸ�ڶԻ��򰴼���ɫ
#define GMMB_KEYS_BG_COLOR    COLOR_HBLUE   //����ɫ
#define GMMB_KEYS_FG_COLOR_A  COLOR_HWHITE  //����ǰ��ɫ
#define GMMB_KEYS_FG_COLOR_D  COLOR_BLACK   //����ǰ��ɫ

//��Ϸ�ڶԻ��򿪹ذ�����ɫ
#define GMMBSW_BG_COLOR_A  COLOR_HWHITE  //��������ɫ
#define GMMBSW_BG_COLOR_D  COLOR_HBLACK  //��������ɫ
#define GMMBSW_FG_COLOR    COLOR_BLACK   //ǰ��ɫ

//���⻭��Ի��򰴼���ɫ
#define CVMB_KEYS_BG_COLOR    COLOR_CYAN    //����ɫ
#define CVMB_KEYS_FG_COLOR_A  COLOR_HWHITE  //����ǰ��ɫ
#define CVMB_KEYS_FG_COLOR_D  COLOR_BLACK   //����ǰ��ɫ

//���öԻ������ɫ
#define OPBX_BG_COLOR    COLOR_HBLACK  //����ɫ
#define OPBX_FG_COLOR_A  COLOR_HWHITE  //����ǰ��ɫ
#define OPBX_FG_COLOR_D  COLOR_BLACK   //����ǰ��ɫ

//��Ϸ�ڰ�������
#define GAME_OPTIONS  1001  //�����á���
#define GAME_SAVE     1002  //�����桱��
#define GAME_DELETE   1003  //��ɾ������
#define GAME_QUIT     1004  //���˳�����

//��Ϸ�ڶԻ��򰴼�����
#define GMMB_YES     2001  //���ǡ���
#define GMMB_NO      2002  //���񡱼�
#define GMMB_SURE    2003  //��ȷ������
#define GMMB_ONE     2004  //��1����
#define GMMB_TWO     2005  //��2����
#define GMMB_THREE   2006  //��3����
#define GMMB_FOUR    2007  //��4����
#define GMMB_CANCEL  2008  //��ȡ������
#define GMMB_SW11    2009  //����1����1
#define GMMB_SW12    2010  //����1����2
#define GMMB_SW21    2011  //����2����1
#define GMMB_SW22    2012  //����2����2

//���⻭�水������
#define CV_NEW      3001  //������Ϸ����
#define CV_LOAD     3002  //��������Ϸ����
#define CV_OPTIONS  3003  //�����á���
#define CV_HELP     3004  //����������
#define CV_HS       3005  //���߷ְ񡱼�
#define CV_EXIT     3006  //���˳�����

//���⻭��Ի��򰴼�����
#define CVMB_YES     4001  //���ǡ���
#define CVMB_NO      4002  //���񡱼�
#define CVMB_SURE    4003  //��ȷ������
#define CVMB_ONE     4004  //��1����
#define CVMB_TWO     4005  //��2����
#define CVMB_THREE   4006  //��3����
#define CVMB_FOUR    4007  //��4����
#define CVMB_CANCEL  4008  //��ȡ������

//���öԻ��򰴼�����
#define OPBX_SETBLINK  5001  //��˸���ÿ�
#define OPBX_SETSHOW   5002  //���Ч�����ÿ�
#define OPBX_SETSOUND  5003  //�������ÿ�
#define OPBX_SETFONT   5004  //�����С���ÿ�
#define OPBX_SURE      5005  //��ȷ������
#define OPBX_CANCEL    5006  //��ȡ������

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
	void act(const int act_mode);   //���ݰ�����������ְ���Ч��

	button(const int X, const int Y, const int TYPE) :x(X), y(Y), type(TYPE) {  //���캯��
		bg_color = COLOR_BLACK;
		fg_color = COLOR_BLACK;
	}
};