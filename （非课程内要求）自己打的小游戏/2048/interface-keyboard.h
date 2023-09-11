#pragma once
#include"90-b3.h"

//��С���̼�������ķ���ֵ
#define QUIT      0x2001  //�˳�
#define RESET     0x2002  //���¿�ʼ
#define CONTINUE  0x2003  //����
#define SAVE_1    0x2004  //������Ϸ��λ��1
#define SAVE_2    0x2005  //������Ϸ��λ��2
#define SAVE_3    0x2006  //������Ϸ��λ��3
#define SAVE_4    0x2007  //������Ϸ��λ��4
#define DELETE_1  0x2008  //ɾ��λ��1�ϵĴ浵
#define DELETE_2  0x2009  //ɾ��λ��1�ϵĴ浵
#define DELETE_3  0x200a  //ɾ��λ��1�ϵĴ浵
#define DELETE_4  0x200b  //ɾ��λ��1�ϵĴ浵

//С���̸����ֵ����꣨�ý�����ʾ��
#define KB_COORD_X     4*__GAME.order-7  //С�������ϽǺ�����
#define KB_COORD_Y     4*__GAME.order+6  //С�������Ͻ�������
#define Q_COORD_X      KB_COORD_X+3   //���ܼ�Q������
#define Q_COORD_Y      KB_COORD_Y+1   //���ܼ�Q������
#define R_COORD_X      KB_COORD_X+6   //���ܼ�R������
#define R_COORD_Y      KB_COORD_Y+1   //���ܼ�R������
#define S_COORD_X      KB_COORD_X+3   //���ܼ�S������
#define S_COORD_Y      KB_COORD_Y+7   //���ܼ�S������
#define D_COORD_X      KB_COORD_X+6   //���ܼ�D������
#define D_COORD_Y      KB_COORD_Y+7   //���ܼ�D������
#define O_COORD_X      KB_COORD_X+17  //���ܼ�O������
#define O_COORD_Y      KB_COORD_Y+7   //���ܼ�O������
#define KBVER_COORD_X  KB_COORD_X+17  //С���̰汾�����ϽǺ�����
#define KBVER_COORD_Y  KB_COORD_Y+1   //С���̰汾�����ϽǺ�����
#define UP_COORD_X     KB_COORD_X+9   //�ϼ�ͷ�����ϽǺ�����
#define UP_COORD_Y     KB_COORD_Y+1   //�ϼ�ͷ�����Ͻ�������
#define DOWN_COORD_X   KB_COORD_X+9   //�¼�ͷ�����ϽǺ�����
#define DOWN_COORD_Y   KB_COORD_Y+5   //�¼�ͷ�����Ͻ�������
#define LEFT_COORD_X   KB_COORD_X+2   //���ͷ�����ϽǺ�����
#define LEFT_COORD_Y   KB_COORD_Y+3   //���ͷ�����Ͻ�������
#define RIGHT_COORD_X  KB_COORD_X+16  //�Ҽ�ͷ�����ϽǺ�����
#define RIGHT_COORD_Y  KB_COORD_Y+3   //�Ҽ�ͷ�����Ͻ�������

//С���̰�����
#define KB_BUTTON_NUM 9

/*�����������*/
class keyboard {
private:
	button button_up;     //�ϼ�ͷ��
	button button_down;   //�¼�ͷ��
	button button_left;   //���ͷ��
	button button_right;  //�Ҽ�ͷ��
	button button_q;      //���ܼ�Q
	button button_r;      //���ܼ�R
	button button_s;      //���ܼ�S
	button button_d;      //���ܼ�D
	button button_o;      //���ܼ�O
public:
	void set_button_type();   //��������������
	void set_button_coord();  //���������긳ֵ
	void print();  //��ӡС����
	int mouse_if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	int keyboard_if_button(const int keycode1, const int keycode2);  //�жϼ��̰��µİ����Ƿ�ΪС�����ϵ�ĳһ����
	void selective_default(const int selection);   //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);  //ѡ���Ե�Ϊĳһ�������ø���
	int control();  //�ü�����С�����Ͻ��в���
};