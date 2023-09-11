#pragma once
#include"cmd_console_tools.h"

//����Ϊ��Ԫ�����ǰ����
class player;
class game_messagebox;
class file_tools;

/*���������*/
class ball {
private:
	int x, y, color;  //�С��С���ɫ
	bool mark;        //��־�����ں�������������
	bool spmark;      //�����־������ʵ�ֹ��Ч����
	static bool if_ball[81];  //����λ���Ƿ������ӵı�־����̬��Ա���ڸ�������乲��
public:
	void print();  //��ӡ����
	void set(const int COORD_X, const int COORD_Y, const int COLOR);  //�������ӵ�λ�ú���ɫ

	ball() :x(-1), y(-1), color(COLOR_WHITE), mark(false), spmark(false) {}  //���캯��

	//��Ԫ�������
	friend class player;
	friend class game_messagebox;
	friend class file_tools;
};