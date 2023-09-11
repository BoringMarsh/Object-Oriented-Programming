#pragma once
#include"90-b3.h"

//�����⻭���������ķ���ֵ
#define COVER_NEW     0x1001  //����Ϸ
#define COVER_LOAD    0x1002  //������Ϸ
#define COVER_AUTO    0x1003  //�Զ���Ϸ
#define COVER_OPTIONS 0x1004  //����
#define COVER_ABOUT   0x1005  //����
#define COVER_QUIT    0x1006  //�˳���Ϸ

//���⻭���ڸ����ֵ�����
#define TWO_COORD_X      6   //����2���ϽǺ�����
#define TWO_COORD_Y      2   //����2���Ͻ�������
#define ZERO_COORD_X     15  //����0���ϽǺ�����
#define ZERO_COORD_Y     4   //����0���Ͻ�������
#define FOUR_COORD_X     24  //����4���ϽǺ�����
#define FOUR_COORD_Y     2   //����4���Ͻ�������
#define EIGHT_COORD_X    33  //����8���ϽǺ�����
#define EIGHT_COORD_Y    4   //����8���Ͻ�������
#define CVVER_COORD_X    38  //����汾�����ϽǺ�����
#define CVVER_COORD_Y    22  //����汾�����Ͻ�������
#define NEW_COORD_X      8   //������Ϸ�������ϽǺ�����
#define NEW_COORD_Y      12  //������Ϸ�������Ͻ�������
#define LOAD_COORD_X     24  //��������Ϸ�������ϽǺ�����
#define LOAD_COORD_Y     12  //��������Ϸ�������Ͻ�������
#define AUTO_COORD_X     8   //���Զ���Ϸ�������ϽǺ�����
#define AUTO_COORD_Y     16  //���Զ���Ϸ�������Ͻ�������
#define OPTIONS_COORD_X  24  //�����á������Ͻ�������
#define OPTIONS_COORD_Y  16  //�����á������Ͻ�������
#define ABOUT_COORD_X    8   //�����ڡ������ϽǺ�����
#define ABOUT_COORD_Y    20  //�����ڡ������Ͻ�������
#define QUIT_COORD_X     24  //���˳���Ϸ�������ϽǺ�����
#define QUIT_COORD_Y     20  //���˳���Ϸ�������Ͻ�������

//���⻭�水����
#define COVER_BUTTON_NUM 6

/*���⻭���������*/
class cover {
private:
	button button_new;      //������Ϸ����
	button button_load;     //��������Ϸ����
	button button_auto;     //���Զ���Ϸ����
	button button_options;  //�����á���
	button button_about;    //�����ڡ���
	button button_quit;     //���˳���Ϸ����
	const int COVER_WIDTH = 24;      //���⻭����
public:
	void set_button_type();   //��������������
	void set_button_coord();  //���������긳ֵ
	void print();  //��ӡ���⻭��
	int if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	void selective_default(const int selection);   //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);  //ѡ���Ե�Ϊĳһ�������ø���
	int control();  //�ü����ڱ��⻭���Ͻ��в���
};