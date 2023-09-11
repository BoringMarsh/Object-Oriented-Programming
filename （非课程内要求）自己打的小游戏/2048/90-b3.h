#pragma once

//ȫ�����迪ͷ������ͷ�ļ�
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include"cmd_console_tools.h"
#include"gameboard.h"
#include"interface-button.h"
#include"interface-keyboard.h"
#include"interface-mailbox.h"
#include"interface-cover.h"
using namespace std;

//��Ϸ�������߽�
#define ORDER_MIN 3  //������Сֵ
#define ORDER_MAX 7  //�������ֵ

//ɫ���Ͱ�ť��ӡģʽ
#define BLOCK_ARROW_MODE_UP    0x001  //�����ϼ�ͷ
#define BLOCK_ARROW_MODE_DOWN  0x002  //�����¼�ͷ
#define BLOCK_ARROW_MODE_LEFT  0x003  //�������ͷ
#define BLOCK_ARROW_MODE_RIGHT 0x004  //�����Ҽ�ͷ

//С���̰�������
#define KB_UP      0x101  //�ϼ�ͷ��
#define KB_DOWN    0x102  //�¼�ͷ��
#define KB_LEFT    0x103  //���ͷ��
#define KB_RIGHT   0x104  //�Ҽ�ͷ��
#define KB_Q       0x105  //���ܼ�Q
#define KB_R       0x106  //���ܼ�R
#define KB_S       0x107  //���ܼ�S
#define KB_D       0x108  //���ܼ�D
#define KB_O       0x109  //���ܼ�O

//��Ϸ�ڶԻ��򰴼�����
#define GMMB_YES     0x201  //���ǡ���
#define GMMB_NO      0x202  //���񡱼�
#define GMMB_SURE    0x203  //��ȷ������
#define GMMB_ONE     0x204  //��1����
#define GMMB_TWO     0x205  //��2����
#define GMMB_THREE   0x206  //��3����
#define GMMB_FOUR    0x207  //��4����
#define GMMB_CANCEL  0x208  //��ȡ������
#define GMMB_SW11    0x209  //����1����1
#define GMMB_SW12    0x20a  //����1����2
#define GMMB_SW21    0x20b  //����2����1
#define GMMB_SW22    0x20c  //����2����2

//���⻭��Ի��򰴼�����
#define CVMB_YES     0x301  //���ǡ���
#define CVMB_NO      0x302  //���񡱼�
#define CVMB_SURE    0x303  //��ȷ������
#define CVMB_ONE     0x304  //��1����
#define CVMB_TWO     0x305  //��2����
#define CVMB_THREE   0x306  //��3����
#define CVMB_FOUR    0x307  //��4����
#define CVMB_CANCEL  0x308  //��ȡ������
#define CVMB_SW11    0x309  //����1����1
#define CVMB_SW12    0x30a  //����1����2
#define CVMB_SW21    0x30b  //����2����1
#define CVMB_SW22    0x30c  //����2����2

//���水������
#define CV_NEW      0x401  //������Ϸ����
#define CV_LOAD     0x402  //��������Ϸ����
#define CV_AUTO     0x403  //���Զ���Ϸ����
#define CV_OPTIONS  0x404  //�����á���
#define CV_ABOUT    0x405  //�����ڡ���
#define CV_QUIT     0x406  //���˳���Ϸ����

//����Ч������
#define ACTIVATE     0x10001  //ĳһ�������ø���
#define DEFAULT      0x10002  //ĳһ����ȡ������
#define DEFAULT_ALL  0x10003  //���а���ȡ������

/***************************************************************************

  90-b3-base.cpp

***************************************************************************/
void move_left();
void add_left();
void act_left();
void move_right();
void add_right();
void act_right();
void move_up();
void add_up();
void act_up();
void move_down();
void add_down();
void act_down();
int matrix_getmax();
int matrix_getmin();
void summon_two();

struct matrix {  //�����Ϸ�Ƿ����ʱ�õĽṹ��
	int num;
	int mark;
};
void matrix_single_scan(matrix m[], const int coord);
int matrix_mark_count(matrix m[]);
void matrix_mark_set(matrix m[]);
bool if_end();
bool if_full();

/***************************************************************************

  90-b3-tools.cpp

***************************************************************************/
void pause();
void console_print_base();
void print_cover_button(const char* prompt, const int bg_color, const int fg_color);
void print_keyboard_button(const int print_mode, const int bg_color, const int fg_color);
void print_switch_button(const int bg_color, const int fg_color);
int color_number(int initial_num);
int power(const int base_number, const int exponent);

/***************************************************************************

  90-b3-main.cpp

***************************************************************************/
void order_input();
void cover_in_progress();
void game_in_progress();

/*�浵�����������*/
class files {
private:
	ofstream writer;  //д����
	ifstream reader;  //������
	char filename[10] = "save .txt";  //�ļ���
public:
	void file_save(const int save_slot);  //����Ϸ���浽�ļ���
	bool if_file_deleted(const int save_slot);  //�жϵ�ǰλ���ϵ��ļ��Ƿ����
	void file_load(const int save_slot);  //��ȡ��Ϸ�浵�ļ�
	void file_delete(const int save_slot);  //�����Ϸ�浵�ļ�
};

//Ѱ�ҵ������Ž��ж�
#define AI_SLN_UP      0x4001  //���Ϻϳ�
#define AI_SLN_DOWN    0x4002  //���ºϳ�
#define AI_SLN_LEFT    0x4003  //����ϳ�
#define AI_SLN_RIGHT   0x4004  //���Һϳ�
#define AI_SLN_NOMOVE  0x4005  //��Ԫ�ز��ϳ�
#define AI_SLN_END     0x4006  //������Ϸ
#define AI_SLN_LIMIT   0x4099  //����״̬��ֻʣһ��

/*�Զ���Ϸ�������*/
class ai_player {
private:
	int matrix[ORDER_MAX * ORDER_MAX];  //������Ž��õ�����
public:
	void matrix_copy();  //����Ϸ�ڲ����鸴�Ƶ�˽�г�Ա������
	int two_order(int initial_num);  //����һ������2�ļ��η�
	void matrix_trans();       //��˽�г�Ա����ת�����Ա�Ѱ�����Ž�
	int find_best_solution();  //����������飬�ҳ����Ž�
	bool check_up(const int line, const int row, const int num);     //���ĳ��λ�õ�Ԫ���ܷ�ͨ�����Ϻϳ�����
	bool check_down(const int line, const int row, const int num);   //���ĳ��λ�õ�Ԫ���ܷ�ͨ�����ºϳ�����
	bool check_left(const int line, const int row, const int num);   //���ĳ��λ�õ�Ԫ���ܷ�ͨ������ϳ�����
	bool check_right(const int line, const int row, const int num);  //���ĳ��λ�õ�Ԫ���ܷ�ͨ�����Һϳ�����
	int check_and_answer(const int line, const int row, const int num);  //��鲢��������ĳ��λ�õ�Ԫ�ص����Ž�
	bool if_limit();   //����ڲ������Ƿ�Ϊ����״̬
	void auto_game();  //�����Զ���Ϸ
};

//��������ⲿȫ�ֱ��������Ľṹ��
struct game {
	int order = 0;  //������
	int matrix[ORDER_MAX * ORDER_MAX];  //�ڲ�����
	int score = 0;       //�÷�
	int stepnumber = 0;  //����
	const char* version = "v3.0";  //��Ϸ�汾��
	bool if_blink = true;  //�Ƿ���ɫ����˸
	bool if_tips = true;   //�Ƿ�����ʾ
	ai_player ai_player;   //�Զ���Ϸ����
	gameboard gameboard;   //��Ϸ������
	keyboard keyboard;     //С���̶���
	cover_mailbox cover_mailbox;  //���⻭��Ի���
	game_mailbox game_mailbox;    //��Ϸ�ڶԻ���
	cover cover;  //���⻭�����
	files files;  //�浵�������
};

/*�ڸ���Դ�ļ��ж���ʹ�õ�����*/
extern struct game __GAME;