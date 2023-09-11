#pragma once
#include"90-b3.h"

#define GMBD_BG_COLOR     COLOR_CYAN     //��Ϸ��ײ㱳��ɫ
#define GMBD_FG_COLOR     COLOR_HWHITE   //��Ϸ��ײ�ǰ��ɫ
#define CSBD_BG_COLOR     COLOR_WHITE    //��Ϸ��屳��ɫ
#define CSBD_FG_COLOR     COLOR_BLACK    //��Ϸ���ǰ��ɫ
#define SCORE_BG_COLOR    COLOR_GREEN    //������ʾ������ɫ
#define SCORE_FG_COLOR    COLOR_BLACK    //������ʾ��ǰ��ɫ
#define MAX_BG_COLOR      COLOR_YELLOW   //���ֵ��ʾ������ɫ
#define MAX_FG_COLOR      COLOR_BLACK    //���ֵ��ʾ��ǰ��ɫ
#define TIPS_BG_COLOR     COLOR_HWHITE   //��ʾ��ʾ������ɫ
#define TIPS_FG_COLOR     COLOR_BLACK    //��ʾ��ʾ��ǰ��ɫ
#define STEPNUM_BG_COLOR  COLOR_HYELLOW  //������ʾ������ɫ
#define STEPNUM_FG_COLOR  COLOR_BLACK    //������ʾ��ǰ��ɫ
#define CSBD_COORD_X     4                 //��Ϸ��������
#define CSBD_COORD_Y     2                 //��Ϸ���������
#define SCORE_COORD_X    __GAME.order*8+8  //������ʾ��������
#define SCORE_COORD_Y    2                 //������ʾ��������
#define MAX_COORD_X      __GAME.order*8+8  //���ֵ��ʾ��������
#define MAX_COORD_Y      7                 //���ֵ��ʾ��������
#define TIPS_COORD_X     __GAME.order*8+8  //��ʾ��ʾ��������
#define TIPS_COORD_Y     12                //��ʾ��ʾ��������
#define STEPNUM_COORD_X  __GAME.order*8+8  //������ʾ��������
#define STEPNUM_COORD_Y  17                //������ʾ��������

class gameboard {
private:
public:
	void print_background();  //��ӡ��ײ㱳��
	char* read_score(char* score);  //��ȡ�÷ֲ�ת�����ַ���
	char* read_max(char* max);  //��ȡ����Ԫ���е����ֵ��ת�����ַ���
	const char* read_solution();  //��ȡѰ�ҳ������ŽⲢת��Ϊ�ַ���
	char* read_stepnumber(char* stepnumber);  //��ȡ������ת��Ϊ�ַ���
	void print_info();   //��ʾ��Ϸ�����Ϣ
	void update_info();  //������Ϸ�����Ϣ
	void block_single_print(const int num, const int bg_color, const int fg_color);  //��ӡһ�����������ֵ�����ɫ�ķ���
	void block_multiple_print();  //���ݵ�ǰ�ڲ�����ֵ��ӡɫ��
	void block_clear();  //����ǰ�����¶�Ӧ��ɫ�����
	void chessboard_single_line(int Y, const char* ch1, const char* ch2, const char* ch3, const char* ch4, const bool if_delay);  //�����Ϸ����ĳһ��
	void chessboard_multiple_lines(const int Y, const bool if_delay);  //�����Ϸ���ĸ���
	void print_chessboard();  //��ӡ��Ϸ���
	void block_activate(const int coord);  //����ǰ�����¶�Ӧ��ɫ�����ø���
	void block_default(const int coord);   //����ǰ�����¶�Ӧ��ɫ�����ȡ��
	void blink_block(const int coord);     //ʹ��ǰ�����µ�Ԫ�ض�Ӧɫ����˸
};