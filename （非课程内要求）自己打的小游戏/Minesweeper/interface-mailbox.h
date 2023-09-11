#pragma once
#include"interface-button.h"

//�Ի��򰴼���ʽ
#define BUTTON_TWO     0x007  //˫��ʽ���Ƿ�
#define BUTTON_ONE     0x008  //����ʽ��ȷ����

//����Ϸ�ڶԻ����������ķ���ֵ
#define GMMB_RET_YES        0x3101  //�����ǡ���
#define GMMB_RET_NO         0x3102  //�����񡱼�
#define GMMB_RET_SURE       0x3103  //����ȷ������

//��Ϸ�ڶԻ�������ֵ����꣨�ý�����ʾ��
#define GMMB_COORD_X      (row % 2 ? 6 * (row / 2) - 8 : 6 * (row / 2) - 11)  //��Ϸ�ڶԻ������ϽǺ�����
#define GMMB_COORD_Y      (line % 2 ? 3 * (line / 2) + 10 : 3 * (line / 2) + 7)  //��Ϸ�ڶԻ������Ͻ�������
#define GMPROM_COORD_X    GMMB_COORD_X+2   //��Ϸ�ڶԻ����У���ʾ�����ϽǺ�����
#define GMPROM_COORD_Y    GMMB_COORD_Y+1   //��Ϸ�ڶԻ����У���ʾ�����Ͻ�������
#define GMYES_COORD_X     GMMB_COORD_X+6   //��Ϸ�ڶԻ����У��������ǡ����ϽǺ�����
#define GMYES_COORD_Y     GMMB_COORD_Y+4   //��Ϸ�ڶԻ����У��������ǡ����Ͻ�������
#define GMNO_COORD_X      GMMB_COORD_X+18  //��Ϸ�ڶԻ����У������������ϽǺ�����
#define GMNO_COORD_Y      GMMB_COORD_Y+4   //��Ϸ�ڶԻ����У������������Ͻ�������
#define GMSURE_COORD_X    GMMB_COORD_X+11  //��Ϸ�ڶԻ����У�������ȷ�������ϽǺ�����
#define GMSURE_COORD_Y    GMMB_COORD_Y+4   //��Ϸ�ڶԻ����У�������ȷ�������Ͻ�������

//��Ϸ�ڶԻ��򰴼���
#define GMMB_BUTTON_NUM 3

/*��Ϸ�ڶԻ����������*/
class game_mailbox {
private:
	button button_yes   { 0,0,GMMB_YES };     //���ǡ���
	button button_no    { 0,0,GMMB_NO };      //���񡱼�
	button button_sure  { 0,0,GMMB_SURE };    //��ȷ������
	int IF_GMMB;        //��Ϸ�ڶԻ���״̬��Ϊ���򲻳��֣���Ϊ������ֵ��Ӧ������ʽ��
	const int GMMB_BG_COLOR;  //��Ϸ�ڶԻ��򱳾�ɫ
	const int GMMB_FG_COLOR;  //��Ϸ�ڶԻ���ǰ��ɫ
	const int GMMB_WIDTH;     //��Ϸ�ڶԻ�����
public:
	void set_button_coord(const int line, const int row);  //���������긳ֵ
	void print(const int button_mode, const int line, const int row, const char* prompt1 = NULL, const char* prompt2 = NULL, const char* prompt3 = NULL);  //��ӡ��Ϸ�ڶԻ���
	int mouse_if_button(const int X, const int Y, const int line, const int row);  //�ж����λ���Ƿ���ĳһ������
	int keyboard_if_button(const int keycode);      //�жϼ��̰��µİ����Ƿ�Ϊ�Ի����ڵ�ĳһ����
	void selective_default(const int selection);    //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);   //ѡ���Ե�Ϊĳһ�������ø���
	int control(const int line, const int row);  //�ü�������Ϸ�ڶԻ����ڽ��в���
	void erase(const struct matrix MATRIX[], const int line, const int row);   //�ػ���Ϸ��壬�ﵽ�����Ի����Ч��������һ��Ҫ��struct�����򱨴�!!!��
	void options(const int options);  //��ɱ��⻭��Ի����еĸ�������

	//���캯��
	game_mailbox() :button_yes(0, 0, GMMB_YES),
		button_no(0, 0, GMMB_NO),
		button_sure(0, 0, GMMB_SURE),
		IF_GMMB(0), GMMB_BG_COLOR(COLOR_HBLUE), GMMB_FG_COLOR(COLOR_BLACK), GMMB_WIDTH(7) {}
};