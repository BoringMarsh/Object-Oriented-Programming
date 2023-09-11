#pragma once
#include"colorball.h"
#include"interface-button.h"

//��Ϸ�ڵĸ���״̬
#define STATE_SELECTING  "  ѡ��Ŀ��"
#define STATE_MOVING     "  ѡ��λ��"
#define STATE_VACANT     "  λ��Ϊ��"
#define STATE_CANCEL     "  ȡ��ѡ��"
#define STATE_CLEAR      "      ���"
#define STATE_OPTIONS    "      ����"
#define STATE_SAVE       "      ����"
#define STATE_DELETE     "      ɾ��"
#define STATE_QUIT       "  ׼���˳�"

//��Ϸ�ڰ�����
#define BUTTON_NUM  4

//����Ϊ�������͵���ǰ����
class ball;

//����Ϊ��Ԫ�����ǰ����
class game_messagebox;
class file_tools;
class optionsbox;

/*����������*/
class player {
private:
	button button_options{ OPTIONS_COORD_X,OPTIONS_COORD_Y,GAME_OPTIONS };  //�����á���
	button button_save   { SAVE_COORD_X,SAVE_COORD_Y,GAME_SAVE };           //�����桱��
	button button_delete { DELETE_COORD_X,DELETE_COORD_Y,GAME_DELETE };     //��ɾ������
	button button_quit   { QUIT_COORD_X,QUIT_COORD_Y,GAME_QUIT };           //���˳�����
	int score;  //�÷�
	bool if_select;  //�Ƿ�ѡ����һ������
	int select_x, select_y;  //ѡ�����ӵ�����������
	int next_color[3];  //��һ�γ��ֵ�3����ɫ
	static bool if_blink;  //�Ƿ���˸����̬��
	static bool if_show;   //�Ƿ������Ч������̬��
public:
	void matrix_clear(ball b[]);  //�������
	char* read_score(char* s);  //��ȡ�÷ֲ�ת��Ϊ�ַ���
	char* read_color(char* c);  //��ȡ��ɫ��ת��Ϊ�ַ���
	void update_score();  //���µ÷�
	void update_color();  //������ɫ
	void update_state(const char* state);  //����״̬
	void blink_blockborder(const int coord, const int blink_times);  //ʹһ�����ӵı߽���˸
	void summon(ball b[], const int summon_times, bool* if_sound);  //����������ɸ�����
	void move(ball b[], const int src_x, const int src_y, const int dst_x, const int dst_y);  //�ƶ�����
	void scan(ball b[]);  //ɨ�������������
	int get_mark_num(const ball b[]);  //ȡ����ǵ����Ӹ���
	bool if_end(const ball b[]);  //�ж���Ϸ�Ƿ����
	void clear(ball b[], bool* if_sound);  //��������
	int if_block(ball b[], const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	void print_blockborder(const int coord, const int bg_color, const int fg_color);  //��ӡһ�����ӵı߽�
	void print_balls(ball b[]);  //��ӡ��ǰ����������
	void blocks_selective_default(ball b[], const int coord, const int bg_color, const int fg_color);   //ѡ���Ե�����ĳһ���ӵı߽�
	void blocks_selective_activate(ball b[], const int coord, const int bg_color, const int fg_color);  //ѡ���Եش�ӡĳһ���ӵı߽�
	int if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	void buttons_selective_activate(const int selection);  //ѡ���Ե�Ϊĳһ����ȡ������
	void buttons_selective_default(const int selection);   //ѡ���Ե�Ϊĳһ�������ø���
	int control(ball b[], bool* if_sound);  //�ü�������Ϸ����ڽ��в���

	player() :score(0), if_select(false), select_x(-1), select_y(-1)  //���캯��
	{
		next_color[0] = COLOR_BLUE;
		next_color[1] = COLOR_HYELLOW;
		next_color[2] = COLOR_PINK;
	}

	//��Ԫ�������
	friend class game_messagebox;
	friend class file_tools;
	friend class optionsbox;
};