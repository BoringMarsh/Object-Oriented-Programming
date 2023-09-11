#pragma once
#include"interface-button.h"

//�����⻭���������ķ���ֵ
#define COVER_EASY     0x1001  //��
#define COVER_MEDIUM   0x1002  //�е�
#define COVER_HARD     0x1003  //����
#define COVER_DIY      0x1004  //�Զ���
#define COVER_OPTIONS  0x1005  //����
#define COVER_QUIT     0x1006  //�˳���Ϸ

//���⻭���ڸ����ֵ�����
#define M_COORD_X   15            //��ĸM���ϽǺ�����
#define M_COORD_Y   2             //��ĸM���Ͻ�������
#define I_COORD_X   M_COORD_X+17  //��ĸI���ϽǺ�����
#define I_COORD_Y   2             //��ĸI���Ͻ�������
#define N_COORD_X   M_COORD_X+30  //��ĸN���ϽǺ�����
#define N_COORD_Y   2             //��ĸN���Ͻ�������
#define E_COORD_X1  M_COORD_X+45  //��һ����ĸE���ϽǺ�����
#define E_COORD_Y1  2             //��һ����ĸE���Ͻ�������
#define S_COORD_X   5             //��ĸS���ϽǺ�����
#define S_COORD_Y   9             //��ĸS���Ͻ�������
#define W_COORD_X   S_COORD_X+10  //��ĸW���ϽǺ�����
#define W_COORD_Y   11            //��ĸW���Ͻ�������
#define E_COORD_X2  S_COORD_X+24  //�ڶ�����ĸE���ϽǺ�����
#define E_COORD_Y2  9             //�ڶ�����ĸE���Ͻ�������
#define E_COORD_X3  S_COORD_X+34  //��������ĸE���ϽǺ�����
#define E_COORD_Y3  11            //��������ĸE���Ͻ�������
#define P_COORD_X   S_COORD_X+44  //��ĸP���ϽǺ�����
#define P_COORD_Y   9             //��ĸP���Ͻ�������
#define E_COORD_X4  S_COORD_X+54  //���ĸ���ĸE���ϽǺ�����
#define E_COORD_Y4  11            //���ĸ���ĸE���Ͻ�������
#define R_COORD_X   S_COORD_X+64  //��ĸR���ϽǺ�����
#define R_COORD_Y   9             //��ĸR���Ͻ�������
#define EASY_COORD_X     15  //���򵥡������ϽǺ�����
#define EASY_COORD_Y     18  //���򵥡������Ͻ�������
#define MEDIUM_COORD_X   34  //���еȡ������ϽǺ�����
#define MEDIUM_COORD_Y   18  //���еȡ������Ͻ�������
#define HARD_COORD_X     53  //�����ѡ������ϽǺ�����
#define HARD_COORD_Y     18  //�����ѡ������Ͻ�������
#define DIY_COORD_X      15  //���Զ��塱�����ϽǺ�����
#define DIY_COORD_Y      23  //���Զ��塱�����Ͻ�������
#define OPTIONS_COORD_X  34  //�����á������ϽǺ�����
#define OPTIONS_COORD_Y  23  //�����á������Ͻ�������
#define QUIT_COORD_X     53  //���˳��������ϽǺ�����
#define QUIT_COORD_Y     23  //���˳��������Ͻ�������

//���⻭�����ĸ��ɫ
#define S_COLOR  COLOR_RED     //��ĸS����ɫ
#define W_COLOR  COLOR_YELLOW  //��ĸW����ɫ
#define E_COLOR2 COLOR_BLUE    //�ڶ�����ĸE����ɫ
#define E_COLOR3 COLOR_GREEN   //��������ĸE����ɫ
#define P_COLOR  COLOR_CYAN    //��ĸP����ɫ
#define E_COLOR4 COLOR_PINK    //���ĸ���ĸE����ɫ
#define R_COLOR  COLOR_HBLACK  //��ĸR����ɫ

//���⻭�水����
#define COVER_BUTTON_NUM  6

//��ӡ������ĸ
#define PRINT_ALL_LETTERS M_print();I_print();N_print();E_print(1);S_print();W_print();E_print(2);E_print(3);P_print();E_print(4);R_print();

//��ű��⻭���������Ľṹ��
struct coord {
	int x;
	int y;
};

/*���⻭���������*/
class cover {
private:
	button button_easy;     //���򵥡���
	button button_medium;   //���еȡ���
	button button_hard;     //�����ѡ���
	button button_diy;      //���Զ��塱��
	button button_options;  //�����á���
	button button_quit;     //���˳�����
	coord bomb_coord[20];   //�������׵�����
	const int COVER_WIDTH;  //���⻭����
public:
	void M_print();  //��ӡһ����ĸM
	void I_print();  //��ӡһ����ĸI
	void N_print();  //��ӡһ����ĸN
	void E_print(const int E_num);  //��ӡһ����ĸE
	void S_print();  //��ӡһ����ĸS
	void W_print();  //��ӡһ����ĸW
	void P_print();  //��ӡһ����ĸP
	void R_print();  //��ӡһ����ĸR
	void bomb_print();  //��ӡ����
	void bomb_reprint();  //���ݵ�һ�δ�ӡʱ�洢��������Ϣ�����´�ӡ����
	void button_reprint();  //���´�ӡ���⻭���е�һЩ����
	void print();  //��ӡ���⻭��
	int if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	void selective_default(const int selection);   //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);  //ѡ���Ե�Ϊĳһ�������ø���
	int control();  //�ü����ڱ��⻭���Ͻ��в���

	//���캯��
	cover() : button_easy(EASY_COORD_X, EASY_COORD_Y, CV_EASY),
		button_medium(MEDIUM_COORD_X, MEDIUM_COORD_Y, CV_MEDIUM),
		button_hard(HARD_COORD_X, HARD_COORD_Y, CV_HARD),
		button_diy(DIY_COORD_X, DIY_COORD_Y, CV_DIY),
		button_options(OPTIONS_COORD_X, OPTIONS_COORD_Y, CV_OPTIONS),
		button_quit(QUIT_COORD_X, QUIT_COORD_Y, CV_QUIT),
		COVER_WIDTH(30) 
	{
		for (int i = 0; i < 20; i++)
			bomb_coord[i].x = 0, bomb_coord[i].y = 0;
	}
};