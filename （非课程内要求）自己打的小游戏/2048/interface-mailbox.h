#pragma once
#include"90-b3.h"

//�Ի��򰴼���ʽ
#define BUTTON_ONE     0x006  //����ʽ��ȷ����
#define BUTTON_TWO     0x007  //˫��ʽ���Ƿ�
#define BUTTON_FIVE    0x008  //���ʽ��1-4��ȡ����
#define BUTTON_SWITCH  0x009  //����ʽ�������رգ�

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
#define GMMB_RET_TIPS_OFF   0x310b  //�ر���ʾ
#define GMMB_RET_TIPS_ON    0x310c  //������ʾ

//��Ϸ�ڶԻ�������ֵ����꣨�ý�����ʾ��
#define GMMB_COORD_X      4*__GAME.order-6  //��Ϸ�ڶԻ������ϽǺ�����
#define GMMB_COORD_Y      2*__GAME.order-1  //��Ϸ�ڶԻ������Ͻ�������
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

/*��Ϸ�ڶԻ����������*/
class game_mailbox {
private:
	button button_yes;     //���ǡ���
	button button_no;      //���񡱼�
	button button_sure;    //��ȷ������
	button button_one;     //��1����
	button button_two;     //��2����
	button button_three;   //��3����
	button button_four;    //��4����
	button button_cancel;  //��ȡ������
	button switch_one[2];  //����1��������ť
	button switch_two[2];  //����2��������ť
	int IF_GMMB = 0;       //��Ϸ�ڶԻ���״̬��Ϊ���򲻳��֣���Ϊ������ֵ��Ӧ������ʽ��
	const int GMMB_BG_COLOR = COLOR_HBLUE;  //��Ϸ�ڶԻ��򱳾�ɫ
	const int GMMB_FG_COLOR = COLOR_BLACK;  //��Ϸ�ڶԻ���ǰ��ɫ
	const int GMMB_WIDTH = 8;               //��Ϸ�ڶԻ�����
public:
	void set_button_type();   //��������������
	void set_button_coord();  //���������긳ֵ
	void print(const int button_mode, const char* prompt1 = NULL, const char* prompt2 = NULL, const char* prompt3 = NULL);  //��ӡ��Ϸ�ڶԻ���
	int mouse_if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	int keyboard_if_button(const int keycode);      //�жϼ��̰��µİ����Ƿ�Ϊ�Ի����ڵ�ĳһ����
	void selective_default(const int selection);    //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);   //ѡ���Ե�Ϊĳһ�������ø���
	int control();  //�ü�������Ϸ�ڶԻ����ڽ��в���
	void erase();   //�ػ���Ϸ��壬�ﵽ�����Ի����Ч��
	void options(const int options);  //��ɱ��⻭��Ի����еĸ�������
};

//�����⻭��Ի����������ķ���ֵ
#define CVMB_RET_YES        0x3201  //�����ǡ���
#define CVMB_RET_NO         0x3202  //�����񡱼�
#define CVMB_RET_SURE       0x3203  //����ȷ������
#define CVMB_RET_ONE        0x3204  //����1����
#define CVMB_RET_TWO        0x3205  //����2����
#define CVMB_RET_THREE      0x3206  //����3����
#define CVMB_RET_FOUR       0x3207  //����4����
#define CVMB_RET_CANCEL     0x3208  //����ȡ������
#define CVMB_RET_BLINK_OFF  0x3209  //�ر�ɫ����˸
#define CVMB_RET_BLINK_ON   0x320a  //����ɫ����˸
#define CVMB_RET_TIPS_OFF   0x320b  //�ر���ʾ
#define CVMB_RET_TIPS_ON    0x320c  //������ʾ

//���⻭��Ի�������ֵ����꣨�ý�����ʾ��
#define CVMB_COORD_X      9  //���⻭��Ի������ϽǺ�����
#define CVMB_COORD_Y      7  //���⻭��Ի������Ͻ�������
#define CVPROM_COORD_X    CVMB_COORD_X+2   //���⻭��Ի����У���ʾ�����ϽǺ�����
#define CVPROM_COORD_Y    CVMB_COORD_Y+1   //���⻭��Ի����У���ʾ�����Ͻ�������
#define CVYES_COORD_X     CVMB_COORD_X+6   //���⻭��Ի����У��������ǡ����ϽǺ�����
#define CVYES_COORD_Y     CVMB_COORD_Y+5   //���⻭��Ի����У��������ǡ����Ͻ�������
#define CVNO_COORD_X      CVMB_COORD_X+18  //���⻭��Ի����У������������ϽǺ�����
#define CVNO_COORD_Y      CVMB_COORD_Y+5   //���⻭��Ի����У������������Ͻ�������
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
#define CVSW11_COORD_X    CVMB_COORD_X+2   //���⻭��Ի����У�����1����1���ϽǺ�����
#define CVSW11_COORD_Y    CVMB_COORD_Y+2   //���⻭��Ի����У�����1����1���Ͻ�������
#define CVSW12_COORD_X    CVMB_COORD_X+8   //���⻭��Ի����У�����1����2���ϽǺ�����
#define CVSW12_COORD_Y    CVMB_COORD_Y+2   //���⻭��Ի����У�����1����2���Ͻ�������
#define CVSW1P_COORD_X    CVMB_COORD_X+10  //���⻭��Ի����У�����1״̬��־���ϽǺ�����
#define CVSW1P_COORD_Y    CVMB_COORD_Y+3   //���⻭��Ի����У�����1״̬��־���Ͻ�������
#define CVSW21_COORD_X    CVMB_COORD_X+14  //���⻭��Ի����У�����2����1���ϽǺ�����
#define CVSW21_COORD_Y    CVMB_COORD_Y+2   //���⻭��Ի����У�����2����1���Ͻ�������
#define CVSW22_COORD_X    CVMB_COORD_X+20  //���⻭��Ի����У�����2����2���ϽǺ�����
#define CVSW22_COORD_Y    CVMB_COORD_Y+2   //���⻭��Ի����У�����2����2���Ͻ�������
#define CVSW2P_COORD_X    CVMB_COORD_X+22  //���⻭��Ի����У�����2״̬��־���ϽǺ�����
#define CVSW2P_COORD_Y    CVMB_COORD_Y+3   //���⻭��Ի����У�����2״̬��־���Ͻ�������

//���⻭��Ի��򰴼���
#define CVMB_BUTTON_NUM 12

/*���⻭��Ի����������*/
class cover_mailbox {
private:
	button button_yes;     //���ǡ���
	button button_no;      //���񡱼�
	button button_sure;    //��ȷ������
	button button_one;     //��1����
	button button_two;     //��2����
	button button_three;   //��3����
	button button_four;    //��4����
	button button_cancel;  //��ȡ������
	button switch_one[2];  //����1��������ť
	button switch_two[2];  //����2��������ť
	int IF_CVMB = 0;       //���⻭��Ի���״̬��Ϊ���򲻳��֣���Ϊ������ֵ��Ӧ������ʽ��
	const int CVMB_BG_COLOR = COLOR_CYAN;  //���⻭��Ի��򱳾�ɫ
	const int CVMB_FG_COLOR = COLOR_BLACK;  //���⻭��Ի���ǰ��ɫ
	const int CVMB_WIDTH = 8;               //���⻭��Ի�����
public:
	void set_button_type();   //��������������
	void set_button_coord();  //���������긳ֵ
	void print(const int button_mode, const char* prompt1 = NULL, const char* prompt2 = NULL, const char* prompt3 = NULL);  //��ӡ���⻭��Ի���
	int mouse_if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	int keyboard_if_button(const int keycode);      //�жϼ��̰��µİ����Ƿ�Ϊ�Ի����ڵ�ĳһ����
	void selective_default(const int selection);    //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);   //ѡ���Ե�Ϊĳһ�������ø���
	int control();  //�ü����ڱ��⻭��Ի����ڽ��в���
	void erase();   //�ػ����⻭�棬�ﵽ�����Ի����Ч��
	void options(const int options);  //��ɱ��⻭��Ի����еĸ�������
};