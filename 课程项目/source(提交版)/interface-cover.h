#pragma once
#include"interface-button.h"

//�����⻭���������ķ���ֵ
#define COVER_RET_NEW      0x2001  //����Ϸ
#define COVER_RET_LOAD     0x2002  //������Ϸ
#define COVER_RET_OPTIONS  0x2003  //����
#define COVER_RET_HELP     0x2004  //����
#define COVER_RET_ABOUT    0x2005  //����
#define COVER_RET_EXIT     0x2006  //�˳���Ϸ

//���⻭���ڸ����ֵ�����
#define C_COORD_X   8   //��ĸC���ϽǺ�����
#define C_COORD_Y   2   //��ĸC���Ͻ�������
#define O_COORD_X1  17  //��һ����ĸO���ϽǺ�����
#define O_COORD_Y1  4   //��һ����ĸO���Ͻ�������
#define L_COORD_X1  26  //��һ����ĸL���ϽǺ�����
#define L_COORD_Y1  2   //��һ����ĸL���Ͻ�������
#define O_COORD_X2  35  //�ڶ�����ĸO���ϽǺ�����
#define O_COORD_Y2  4   //�ڶ�����ĸO���Ͻ�������
#define R_COORD_X   44  //��ĸR���ϽǺ�����
#define R_COORD_Y   2   //��ĸR���Ͻ�������
#define B_COORD_X   36  //��ĸB���ϽǺ�����
#define B_COORD_Y   11  //��ĸB���Ͻ�������
#define A_COORD_X   46  //��ĸA���ϽǺ�����
#define A_COORD_Y   11  //��ĸA���Ͻ�������
#define L_COORD_X2  59  //�ڶ�����ĸL���ϽǺ�����
#define L_COORD_Y2  11  //�ڶ�����ĸL���Ͻ�������
#define L_COORD_X3  68  //��������ĸL���ϽǺ�����
#define L_COORD_Y3  11  //��������ĸL���Ͻ�������
#define NEW_COORD_X    15  //������Ϸ�������ϽǺ�����
#define NEW_COORD_Y    18  //������Ϸ�������Ͻ�������
#define LOAD_COORD_X   34  //��������Ϸ�������ϽǺ�����
#define LOAD_COORD_Y   18  //��������Ϸ�������Ͻ�������
#define CVOP_COORD_X   53  //�����á������ϽǺ�����
#define CVOP_COORD_Y   18  //�����á������Ͻ�������
#define HELP_COORD_X   15  //�������������ϽǺ�����
#define HELP_COORD_Y   23  //�������������Ͻ�������
#define ABOUT_COORD_X  34  //�����ڡ������ϽǺ�����
#define ABOUT_COORD_Y  23  //�����ڡ������Ͻ�������
#define EXIT_COORD_X   53  //���˳��������ϽǺ�����
#define EXIT_COORD_Y   23  //���˳��������Ͻ�������

//���⻭�����ĸ��ɫ
#define C_COLOR    COLOR_RED     //��ĸC����ɫ
#define O_COLOR1   COLOR_YELLOW  //��һ����ĸO����ɫ
#define L_COLOR    COLOR_BLUE    //��һ����ĸL����ɫ
#define O_COLOR2   COLOR_GREEN   //�ڶ�����ĸO����ɫ
#define R_COLOR    COLOR_PINK    //��ĸR����ɫ
#define BALL_COLOR COLOR_CYAN    //����BALL����ɫ

//���⻭�水����
#define COVER_BUTTON_NUM  6

//��ӡ������ĸ
#define PRINT_ALL_LETTERS C_print();O_print(1);L_print(1);O_print(2);R_print();B_print();A_print();L_print(2);L_print(3)

//��ӡ��������
#define PRINT_ALL_BALLS ball_print(2, 24, COLOR_RED);ball_print(5, 10, COLOR_YELLOW);ball_print(22, 13, COLOR_GREEN);ball_print(60, 5, COLOR_BLUE);ball_print(72, 1, COLOR_HYELLOW);ball_print(72, 21, COLOR_PINK)

//����Ϊ��Ԫ�����ǰ����
class cover_messagebox;
class optionsbox;

/*���⻭���������*/
class cover {
private:
	button button_new    { NEW_COORD_X,NEW_COORD_Y,CV_NEW };        //������Ϸ����
	button button_load   { LOAD_COORD_X,LOAD_COORD_Y,CV_LOAD };     //��������Ϸ����
	button button_options{ CVOP_COORD_X,CVOP_COORD_Y,CV_OPTIONS };  //�����á���
	button button_help   { HELP_COORD_X,HELP_COORD_Y,CV_HELP };     //����������
	button button_about  { ABOUT_COORD_X,ABOUT_COORD_Y,CV_ABOUT };  //�����ڡ���
	button button_exit   { EXIT_COORD_X,EXIT_COORD_Y,CV_EXIT };     //���˳�����
	const int COVER_WIDTH;  //���⻭����
	int last_button;  //��һ��������ڵİ���
public:
	void C_print();  //��ӡһ����ĸC
	void O_print(const int O_num);  //��ӡһ����ĸO
	void L_print(const int L_num);  //��ӡһ����ĸL
	void R_print();  //��ӡһ����ĸR
	void B_print();  //��ӡһ����ĸB
	void A_print();  //��ӡһ����ĸA
	void ball_print(const int X, const int Y, const int bg_color);  //��ӡһ������
	void print();  //��ӡ���⻭��
	int if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	void selective_default(const int selection);   //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);  //ѡ���Ե�Ϊĳһ�������ø���
	int control(bool* if_sound);  //�ü����ڱ��⻭���Ͻ��в���

	cover() :COVER_WIDTH(30), last_button(0) {}  //���캯��

	//��Ԫ�������
	friend class cover_messagebox;
	friend class optionsbox;
};