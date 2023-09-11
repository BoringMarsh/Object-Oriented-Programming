#pragma once
#include<iostream>
#include"interface-button.h"

//�Ի��򰴼���ʽ
#define BUTTON_ONE     0x20001  //����ʽ��ȷ����
#define BUTTON_TWO     0x20002  //˫��ʽ���Ƿ�
#define BUTTON_FIVE    0x20003  //���ʽ��1-4��ȡ����
#define BUTTON_SWITCH  0x20004  //����ʽ�������رգ�

//����Ϸ�ڶԻ����������ķ���ֵ
#define GMMB_RET_YES        0x3101  //�����ǡ���
#define GMMB_RET_NO         0x3102  //�����񡱼�
#define GMMB_RET_SURE       0x3103  //����ȷ������
#define GMMB_RET_ONE        0x3104  //����1����
#define GMMB_RET_TWO        0x3105  //����2����
#define GMMB_RET_THREE      0x3106  //����3����
#define GMMB_RET_FOUR       0x3107  //����4����
#define GMMB_RET_CANCEL     0x3108  //����ȡ������
#define GMMB_RET_BLINK_OFF  0x3109  //�ر�ɫ����˸
#define GMMB_RET_BLINK_ON   0x310a  //����ɫ����˸
#define GMMB_RET_SHOW_OFF   0x310b  //�ر����Ч��
#define GMMB_RET_SHOW_ON    0x310c  //�������Ч��

//��Ϸ�ڶԻ�������ֵ����꣨�ý�����ʾ��
#define GMMB_COORD_X      33  //��Ϸ�ڶԻ������ϽǺ�����
#define GMMB_COORD_Y      19  //��Ϸ�ڶԻ������Ͻ�������
#define GMPROM_COORD_X    GMMB_COORD_X+2   //��Ϸ�ڶԻ����У���ʾ�����ϽǺ�����
#define GMPROM_COORD_Y    GMMB_COORD_Y+1   //��Ϸ�ڶԻ����У���ʾ�����Ͻ�������
#define GMYES_COORD_X     GMMB_COORD_X+6   //��Ϸ�ڶԻ����У��������ǡ����ϽǺ�����
#define GMYES_COORD_Y     GMMB_COORD_Y+4   //��Ϸ�ڶԻ����У��������ǡ����Ͻ�������
#define GMNO_COORD_X      GMMB_COORD_X+18  //��Ϸ�ڶԻ����У������������ϽǺ�����
#define GMNO_COORD_Y      GMMB_COORD_Y+4   //��Ϸ�ڶԻ����У������������Ͻ�������
#define GMSURE_COORD_X    GMMB_COORD_X+11  //��Ϸ�ڶԻ����У�������ȷ�������ϽǺ�����
#define GMSURE_COORD_Y    GMMB_COORD_Y+5   //��Ϸ�ڶԻ����У�������ȷ�������Ͻ�������
#define GMONE_COORD_X     GMMB_COORD_X+4   //��Ϸ�ڶԻ����У�������1�����ϽǺ�����
#define GMONE_COORD_Y     GMMB_COORD_Y+3   //��Ϸ�ڶԻ����У�������1�����Ͻ�������
#define GMTWO_COORD_X     GMMB_COORD_X+10  //��Ϸ�ڶԻ����У�������2�����ϽǺ�����
#define GMTWO_COORD_Y     GMMB_COORD_Y+3   //��Ϸ�ڶԻ����У�������2�����Ͻ�������
#define GMTHREE_COORD_X   GMMB_COORD_X+4   //��Ϸ�ڶԻ����У�������3�����ϽǺ�����
#define GMTHREE_COORD_Y   GMMB_COORD_Y+5   //��Ϸ�ڶԻ����У�������3�����Ͻ�������
#define GMFOUR_COORD_X    GMMB_COORD_X+10  //��Ϸ�ڶԻ����У�������4�����ϽǺ�����
#define GMFOUR_COORD_Y    GMMB_COORD_Y+5   //��Ϸ�ڶԻ����У�������4�����Ͻ�������
#define GMCANCEL_COORD_X  GMMB_COORD_X+18  //��Ϸ�ڶԻ����У�������ȡ�������ϽǺ�����
#define GMCANCEL_COORD_Y  GMMB_COORD_Y+5   //��Ϸ�ڶԻ����У�������ȡ�������Ͻ�������
#define GMSW11_COORD_X    GMMB_COORD_X+2   //��Ϸ�ڶԻ����У�����1����1���ϽǺ�����
#define GMSW11_COORD_Y    GMMB_COORD_Y+2   //��Ϸ�ڶԻ����У�����1����1���Ͻ�������
#define GMSW12_COORD_X    GMMB_COORD_X+8   //��Ϸ�ڶԻ����У�����1����2���ϽǺ�����
#define GMSW12_COORD_Y    GMMB_COORD_Y+2   //��Ϸ�ڶԻ����У�����1����2���Ͻ�������
#define GMSW1P_COORD_X    GMMB_COORD_X+10  //��Ϸ�ڶԻ����У�����1״̬��־���ϽǺ�����
#define GMSW1P_COORD_Y    GMMB_COORD_Y+3   //��Ϸ�ڶԻ����У�����1״̬��־���Ͻ�������
#define GMSW21_COORD_X    GMMB_COORD_X+14  //��Ϸ�ڶԻ����У�����2����1���ϽǺ�����
#define GMSW21_COORD_Y    GMMB_COORD_Y+2   //��Ϸ�ڶԻ����У�����2����1���Ͻ�������
#define GMSW22_COORD_X    GMMB_COORD_X+20  //��Ϸ�ڶԻ����У�����2����2���ϽǺ�����
#define GMSW22_COORD_Y    GMMB_COORD_Y+2   //��Ϸ�ڶԻ����У�����2����2���Ͻ�������
#define GMSW2P_COORD_X    GMMB_COORD_X+22  //��Ϸ�ڶԻ����У�����2״̬��־���ϽǺ�����
#define GMSW2P_COORD_Y    GMMB_COORD_Y+3   //��Ϸ�ڶԻ����У�����2״̬��־���Ͻ�������

//��Ϸ�ڶԻ��򰴼���
#define GMMB_BUTTON_NUM 12

//����Ϊ�������͵���ǰ����
class player;
class ball;

/*��Ϸ�ڶԻ����������*/
class game_messagebox {
private:
	button button_yes   { GMYES_COORD_X,GMYES_COORD_Y,GMMB_YES };           //���ǡ���
	button button_no    { GMNO_COORD_X,GMNO_COORD_Y,GMMB_NO };              //���񡱼�
	button button_sure  { GMSURE_COORD_X,GMSURE_COORD_Y,GMMB_SURE };        //��ȷ�ϡ���
	button button_one   { GMONE_COORD_X,GMONE_COORD_Y,GMMB_ONE };           //��1����
	button button_two   { GMTWO_COORD_X,GMTWO_COORD_Y,GMMB_TWO };           //��2����
	button button_three { GMTHREE_COORD_X,GMTHREE_COORD_Y,GMMB_THREE };     //��3����
	button button_four  { GMFOUR_COORD_X,GMFOUR_COORD_Y,GMMB_FOUR };        //��4����
	button button_cancel{ GMCANCEL_COORD_X,GMCANCEL_COORD_Y,GMMB_CANCEL };  //��ȡ������
	button switch_one[2]{ {GMSW11_COORD_X,GMSW11_COORD_Y,GMMB_SW11},{GMSW12_COORD_X,GMSW12_COORD_Y,GMMB_SW12} };  //����1��������ť
	button switch_two[2]{ {GMSW21_COORD_X,GMSW21_COORD_Y,GMMB_SW21},{GMSW22_COORD_X,GMSW22_COORD_Y,GMMB_SW22} };  //����2��������ť
	int IF_GMMB;  //��Ϸ�ڶԻ���״̬��Ϊ���򲻳��֣���Ϊ������ֵ��Ӧ������ʽ��
	const int GMMB_BG_COLOR;  //��Ϸ�ڶԻ��򱳾�ɫ
	const int GMMB_FG_COLOR;  //��Ϸ�ڶԻ���ǰ��ɫ
	const int GMMB_WIDTH;     //��Ϸ�ڶԻ�����
public:
	void print(const int button_mode, const char* prompt1 = NULL, const char* prompt2 = NULL, const char* prompt3 = NULL);  //��ӡ��Ϸ�ڶԻ���
	int mouse_if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	int keyboard_if_button(const int keycode);      //�жϼ��̰��µİ����Ƿ�Ϊ�Ի����ڵ�ĳһ����
	void selective_default(const int selection);    //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);   //ѡ���Ե�Ϊĳһ�������ø���
	int control(bool* if_sound);  //�ü�������Ϸ�ڶԻ����ڽ��в���
	void erase(player& client, ball b[]);   //�ػ���Ϸ��壬�ﵽ�����Ի����Ч��
	void options(const int options);  //��ɱ��⻭��Ի����еĸ�������

	game_messagebox() :IF_GMMB(0), GMMB_BG_COLOR(COLOR_HBLUE), GMMB_FG_COLOR(COLOR_BLACK), GMMB_WIDTH(8) {}  //���캯��
};

//�����⻭��Ի����������ķ���ֵ
#define CVMB_RET_YES     0x3201  //�����ǡ���
#define CVMB_RET_NO      0x3202  //�����񡱼�
#define CVMB_RET_SURE    0x3203  //����ȷ������
#define CVMB_RET_ONE     0x3204  //����1����
#define CVMB_RET_TWO     0x3205  //����2����
#define CVMB_RET_THREE   0x3206  //����3����
#define CVMB_RET_FOUR    0x3207  //����4����
#define CVMB_RET_CANCEL  0x3208  //����ȡ������

//���⻭��Ի�������ֵ����꣨�ý�����ʾ��
#define CVMB_COORD_X      27  //���⻭��Ի������ϽǺ�����
#define CVMB_COORD_Y      11  //���⻭��Ի������Ͻ�������
#define CVPROM_COORD_X    CVMB_COORD_X+2   //���⻭��Ի����У���ʾ�����ϽǺ�����
#define CVPROM_COORD_Y    CVMB_COORD_Y+1   //���⻭��Ի����У���ʾ�����Ͻ�������
#define CVYES_COORD_X     CVMB_COORD_X+6   //���⻭��Ի����У��������ǡ����ϽǺ�����
#define CVYES_COORD_Y     CVMB_COORD_Y+4   //���⻭��Ի����У��������ǡ����Ͻ�������
#define CVNO_COORD_X      CVMB_COORD_X+18  //���⻭��Ի����У������������ϽǺ�����
#define CVNO_COORD_Y      CVMB_COORD_Y+4   //���⻭��Ի����У������������Ͻ�������
#define CVSURE_COORD_X    CVMB_COORD_X+11  //���⻭��Ի����У�������ȷ�������ϽǺ�����
#define CVSURE_COORD_Y    CVMB_COORD_Y+5   //���⻭��Ի����У�������ȷ�������Ͻ�������
#define CVONE_COORD_X     CVMB_COORD_X+4   //���⻭��Ի����У�������1�����ϽǺ�����
#define CVONE_COORD_Y     CVMB_COORD_Y+3   //���⻭��Ի����У�������1�����Ͻ�������
#define CVTWO_COORD_X     CVMB_COORD_X+10  //���⻭��Ի����У�������2�����ϽǺ�����
#define CVTWO_COORD_Y     CVMB_COORD_Y+3   //���⻭��Ի����У�������2�����Ͻ�������
#define CVTHREE_COORD_X   CVMB_COORD_X+4   //���⻭��Ի����У�������3�����ϽǺ�����
#define CVTHREE_COORD_Y   CVMB_COORD_Y+5   //���⻭��Ի����У�������3�����Ͻ�������
#define CVFOUR_COORD_X    CVMB_COORD_X+10  //���⻭��Ի����У�������4�����ϽǺ�����
#define CVFOUR_COORD_Y    CVMB_COORD_Y+5   //���⻭��Ի����У�������4�����Ͻ�������
#define CVCANCEL_COORD_X  CVMB_COORD_X+18  //���⻭��Ի����У�������ȡ�������ϽǺ�����
#define CVCANCEL_COORD_Y  CVMB_COORD_Y+5   //���⻭��Ի����У�������ȡ�������Ͻ�������

//���⻭��Ի��򰴼���
#define CVMB_BUTTON_NUM 8

//����Ϊ�������͵���ǰ����
class cover;

/*���⻭��Ի����������*/
class cover_messagebox {
private:
	button button_yes   { CVYES_COORD_X,CVYES_COORD_Y,CVMB_YES };           //���ǡ���
	button button_no    { CVNO_COORD_X,CVNO_COORD_Y,CVMB_NO };              //���񡱼�
	button button_sure  { CVSURE_COORD_X,CVSURE_COORD_Y,CVMB_SURE };        //��ȷ�ϡ���
	button button_one   { CVONE_COORD_X,CVONE_COORD_Y,CVMB_ONE };           //��1����
	button button_two   { CVTWO_COORD_X,CVTWO_COORD_Y,CVMB_TWO };           //��2����
	button button_three { CVTHREE_COORD_X,CVTHREE_COORD_Y,CVMB_THREE };     //��3����
	button button_four  { CVFOUR_COORD_X,CVFOUR_COORD_Y,CVMB_FOUR };        //��4����
	button button_cancel{ CVCANCEL_COORD_X,CVCANCEL_COORD_Y,CVMB_CANCEL };  //��ȡ������
	int IF_CVMB = 0;  //���⻭��Ի���״̬��Ϊ���򲻳��֣���Ϊ������ֵ��Ӧ������ʽ��
	const int CVMB_BG_COLOR = COLOR_CYAN;   //���⻭��Ի��򱳾�ɫ
	const int CVMB_FG_COLOR = COLOR_BLACK;  //���⻭��Ի���ǰ��ɫ
	const int CVMB_WIDTH = 8;               //���⻭��Ի�����
public:
	void print(const int button_mode, const char* prompt1 = NULL, const char* prompt2 = NULL, const char* prompt3 = NULL, const char* prompt4 = NULL);  //��ӡ���⻭��Ի���
	int mouse_if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	int keyboard_if_button(const int keycode);      //�жϼ��̰��µİ����Ƿ�Ϊ�Ի����ڵ�ĳһ����
	void selective_default(const int selection);    //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);   //ѡ���Ե�Ϊĳһ�������ø���
	int control(bool* if_sound);  //�ü����ڱ��⻭��Ի����ڽ��в���
	void erase(cover& TitleScreen);  //�ػ����⻭�棬�ﵽ�����Ի����Ч��

	cover_messagebox() :IF_CVMB(0), CVMB_BG_COLOR(COLOR_CYAN), CVMB_FG_COLOR(COLOR_BLACK), CVMB_WIDTH(8) {}  //���캯��
};