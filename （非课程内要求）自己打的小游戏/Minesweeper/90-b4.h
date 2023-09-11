#pragma once
#include<windows.h>

/*��ʾ��Ϸ�ڶԻ�����ⲿȫ�ֶ���*/
extern class game_mailbox GAME_MAILBOX;

/*��ʾ���⻭����ⲿȫ�ֶ���*/
extern class cover COVER;

/*��ʾ�������ⲿȫ�ֶ���*/
extern class inputbox INPUTBOX;

/*��ʾ���öԻ�����ⲿȫ�ֶ���*/
extern class optionsbox OPTIONSBOX;

//��Ϸ�������߽�
#define LINE_MAX 30  //�������ֵ
#define ROW_MAX 30   //�������ֵ

//��Ϸ�Ѷ�
#define EASY    1  //��
#define MEDIUM  2  //�е�
#define HARD    3  //����
#define DIY     4  //�Զ���

//��Ϸ��Ϣ����
#define INFO_LINE      11  //������Ϣ
#define INFO_ROW       12  //������Ϣ
#define INFO_BOMB_NUM  13  //��������Ϣ

//��Ϸ����ϢԤ��ֵ
#define EASY_LINE        8   //���Ѷ�����
#define EASY_ROW         8   //���Ѷ�����
#define EASY_BOMB_NUM    10  //���Ѷȵ�����
#define MEDIUM_LINE      16  //�е��Ѷ�����
#define MEDIUM_ROW       16  //�е��Ѷ�����
#define MEDIUM_BOMB_NUM  40  //�е��Ѷȵ�����
#define HARD_LINE        30  //�����Ѷ�����
#define HARD_ROW         16  //�����Ѷ�����
#define HARD_BOMB_NUM    99  //�����Ѷȵ�����
#define DIY_LINE         30  //�Զ������������ֵ��
#define DIY_ROW          30  //�Զ������������ֵ��
#define DIY_BOMB_NUM     (line * row) * 0.8  //�Զ�������������ֵ��

//�ո����Ӧ��numֵ�����ڴ�ӡ�м�Ϊ�յ�ɫ�飩
#define NUM_SPACE  ' '-'0'

//��Ϸ������������
#define NEW_COORD_X   (row % 2 ? 6 * (row / 2) + 2 : 6 * (row / 2) - 1)  //����Ϸ�����ϽǺ�����
#define NEW_COORD_Y   5  //����Ϸ�����Ͻ�������
#define MINE_COORD_X  8  //ʣ����������ϽǺ�����
#define MINE_COORD_Y  4  //ʣ����������Ͻ�������
#define TIME_COORD_X  (6 * row - 18)  //��ʱ���ϽǺ�����
#define TIME_COORD_Y  4  //��ʱ���Ͻ�������

//��Ϸ����������ɫ
#define NEW_BG_COLOR_D  COLOR_WHITE   //����Ϸ����������ɫ
#define NEW_FG_COLOR_D  COLOR_YELLOW  //����Ϸ������ǰ��ɫ
#define NEW_BG_COLOR_A  COLOR_HBLACK  //����Ϸ����������ɫ
#define NEW_FG_COLOR_A  COLOR_YELLOW  //����Ϸ������ǰ��ɫ
#define MINE_BG_COLOR   COLOR_BLACK   //ʣ�����������ɫ
#define MINE_FG_COLOR   COLOR_RED     //ʣ�������ǰ��ɫ
#define TIME_BG_COLOR   COLOR_BLACK   //��ʱ����ɫ
#define TIME_FG_COLOR   COLOR_RED     //��ʱǰ��ɫ

//ÿһ����Ϸ�Ľ��
#define FAILURE  1  //ʧ��
#define VICTORY  2  //ʤ��
#define NEW      3  //����Ϸ
#define QUIT     4  //�˳�

//�������ӵĲ���
#define PLACE_FLAG   11  //����
#define REMOVE_FLAG  12  //�Ƴ�����

/*��Ϸ��ÿһ��Ԫ�ض�Ӧ�Ľṹ��*/
struct matrix {
	int num;
	bool mark;
	bool coord_mark;
	bool if_turned;
	bool if_flag;
};

/***************************************************************************

  90-b4-base.cpp

***************************************************************************/
void matrix_single_scan(matrix MATRIX[], const int line, const int row, const int coord);
void zero_check1(matrix MATRIX[], const int line, const int row, const int coord);
void zero_check2(matrix MATRIX[], const int line, const int row, const int coord);
int flag_check(const matrix MATRIX[], const int line, const int row, const int coord);
void matrix_copy(matrix dst[], const matrix src[], const int line, const int row);
bool matrix_compare(const matrix m1[], const matrix m2[], const int line, const int row);
void matrix_initialize(matrix MATRIX[], const int line, const int row, const int bomb_num, const int first_x, const int first_y);

/***************************************************************************

  90-b4-console.cpp

***************************************************************************/
void block_print(const int num, const int bg_color, const int fg_color);
void block_blink(const int row, const int coord, const int bg_color1, const int bg_color2, const int fg_color);
void gameboard_print(const int line, const int row);
char* read_bomb_num(char* bomb_num, const int BOMB_NUM);
char* read_time(char* time, const LONGLONG TIME);
void print_info(const int row, const int bomb_num);
void update_bomb_num(const int row, const int bomb_num);
void update_time(const int row, const LARGE_INTEGER tick, const LARGE_INTEGER begin, const LARGE_INTEGER end);
int if_block(matrix MATRIX[], const int X, const int Y, const int line, const int row);
bool if_new_button(const int X, const int Y, const int row);
void new_button_default(const int row);
void new_button_activate(const int row);
void selective_default(matrix MATRIX[], const int line, const int row, const int coord);
void selective_activate(matrix MATRIX[], const int line, const int row, const int coord, const int X, const int Y);
int turn(matrix MATRIX[], const int line, const int row, const int coord);
int wheel_click_turn(matrix MATRIX[], const int line, const int row, const int coord);
void failure(const matrix MATRIX[], const int line, const int row, const int coord);
void victory(const matrix MATRIX[], const int line, const int row);
void flag(matrix MATRIX[], const int line, const int row, const int coord, int* bomb_num, const int flag_mode);
int control(matrix MATRIX[], const int line, const int row, const int BOMB_NUM, bool* if_initialized);

/***************************************************************************

  90-b4-tools.cpp

***************************************************************************/
void pause();
int set_info(const int difficulty, const int info_type);
int num_trans_color(const int num);
bool if_end(const matrix MATRIX[], const int line, const int row);
void inputbox_erase();
void optionsbox_erase();

/***************************************************************************

  ai_player.cpp

***************************************************************************/
int unturned_check(const matrix MATRIX[], const int line, const int row, const int coord);
int ai_control(matrix MATRIX[], const int line, const int row, int* bomb_num, bool* if_initialized);