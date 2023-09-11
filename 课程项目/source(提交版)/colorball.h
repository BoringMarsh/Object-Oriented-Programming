#pragma once
#include<fstream>
using namespace std;

//ÿ����Ϸ�ķ���ֵ
#define GAME_RET_FAILURE  0x1000  //ʧ��
#define GAME_RET_OPTIONS  0x1001  //��������á���
#define GAME_RET_SAVE     0x1002  //��������桱��
#define GAME_RET_DELETE   0x1003  //�����ɾ������
#define GAME_RET_QUIT     0x1004  //������˳�����

//��Ϸ������������
#define SCORE_COORD_X    95  //�÷���ʾ�����ϽǺ�����
#define SCORE_COORD_Y    4   //�÷���ʾ�����Ͻ�������
#define COLOR_COORD_X    95  //��һ��ɫ��ʾ�����ϽǺ�����
#define COLOR_COORD_Y    11  //��һ��ɫ��ʾ�����Ͻ�������
#define STATE_COORD_X    95  //״̬��ʾ�����ϽǺ�����
#define STATE_COORD_Y    18  //״̬��ʾ�����Ͻ�������
#define OPTIONS_COORD_X  97  //�����á������ϽǺ�����
#define OPTIONS_COORD_Y  24  //�����á������Ͻ�������
#define SAVE_COORD_X     97  //�����桱�����ϽǺ�����
#define SAVE_COORD_Y     29  //�����桱�����Ͻ�������
#define DELETE_COORD_X   97  //��ɾ���������ϽǺ�����
#define DELETE_COORD_Y   34  //��ɾ���������Ͻ�������
#define QUIT_COORD_X     97  //���˳��������ϽǺ�����
#define QUIT_COORD_Y     39  //���˳��������Ͻ�������

//ʹ�õ��ĸ�����ЧƵ��
#define SOUND_LLA  440   //Ƶ�ʣ���6
#define SOUND_LSI  494   //Ƶ�ʣ���7
#define SOUND_DO   523   //Ƶ�ʣ�1
#define SOUND_MI   659   //Ƶ�ʣ�3
#define SOUND_FA   698   //Ƶ�ʣ�4
#define SOUND_SO   784   //Ƶ�ʣ�5
#define SOUND_HDO  1046  //Ƶ�ʣ���1

/***************************************************************************

  tools.cpp

***************************************************************************/
void pause();  //����һ������ļ�ϵ�
int num_trans_color(const int num);  //����һ��0-5���������ر�ʾ��ɫ����
char* color_trans_string(const int color, char* c);  //�����ʾ��ɫ���������ر�ʾ����ɫ���ַ���
void chessboard_single_line(int Y, const char* ch1, const char* ch2, const char* ch3, const char* ch4);  //�����Ϸ����ĳһ��
void chessboard_multiple_lines(const int Y);  //�����Ϸ���ĸ���
void print_chessboard();  //�����Ϸ���
void print_info_block(const int X, const int Y, const char* title, const int bg_color, const int fg_color);  //��ӡһ����Ϸ�����Ϣ����ʾ��
void print_game_button(const int X, const int Y, const char* prompt, const int bg_color, const int fg_color);  //��ӡһ����Ϸ�ڵİ���
void print_cover_button(const char* prompt, const int bg_color, const int fg_color);  //�ڹ�굱ǰλ�ô�ӡһ�����⻭�水��
void print_empty_block(const int bg_color, const int fg_color);  //�ڹ�굱ǰλ�ô�ӡһ������Ϊ�յ�ɫ��
void print_switch_button(const int bg_color, const int fg_color);  //��ӡһ�������ϵİ���
int power(const int base_number, const int exponent);  //��һ������n�η�

/*�浵�����������*/
class file_tools {
private:
	ofstream writer;  //д����
	ifstream reader;  //������
	char filename[10];  //�ļ���
public:
	char num_trans_char(const int num);  //����һ��0-15���������ض�Ӧʮ�����Ʊ�ʾ���ַ�
	int char_trans_num(const char ch);   //����һ��ʮ�����Ʊ�ʾ���ַ������ض�Ӧ����
	void file_save(const class player& client, const class ball b[], const int save_slot);  //����Ϸ���浽�ļ���
	bool if_file_deleted(const int save_slot);  //�жϵ�ǰλ���ϵ��ļ��Ƿ����
	void file_load(player& client, ball b[], const int save_slot);  //��ȡ��Ϸ�浵�ļ�
	void file_delete(const int save_slot);  //�����Ϸ�浵�ļ�

	file_tools() :filename("save .txt") {}  //���캯��
};