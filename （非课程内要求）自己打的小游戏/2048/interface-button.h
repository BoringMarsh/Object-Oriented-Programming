#pragma once
#include"90-b3.h"

//��Ϸ�ڶԻ��򰴼���ɫ
#define GMMB_KEYS_BG_COLOR COLOR_HBLUE
#define GMMB_KEYS_FG_COLOR_A COLOR_HWHITE
#define GMMB_KEYS_FG_COLOR_D COLOR_BLACK

//��Ϸ�ڶԻ��򿪹ذ�����ɫ
#define GMMBSW_BG_COLOR_A COLOR_HWHITE
#define GMMBSW_BG_COLOR_D COLOR_HBLACK
#define GMMBSW_FG_COLOR COLOR_BLACK

//���⻭��Ի��򰴼���ɫ
#define CVMB_KEYS_BG_COLOR COLOR_CYAN
#define CVMB_KEYS_FG_COLOR_A COLOR_HWHITE
#define CVMB_KEYS_FG_COLOR_D COLOR_BLACK

//���⻭��Ի��򿪹ذ�����ɫ
#define CVMBSW_BG_COLOR_A COLOR_HWHITE
#define CVMBSW_BG_COLOR_D COLOR_HBLACK
#define CVMBSW_FG_COLOR COLOR_BLACK

/*�����������*/
class button {
private:
	int x = -1;                  //�������ϽǺ�����
	int y = -1;                  //�������Ͻ�������
	int bg_color = COLOR_BLACK;  //��������ɫ
	int fg_color = COLOR_BLACK;  //����ǰ��ɫ
	int type = 0;                //��������
public:
	void set_color(const int BG_COLOR, const int FG_COLOR);  //������������ɫ
	void set_coord(const int X, const int Y);  //�������������Ͻ�����
	void set_type(const int TYPE);  //��������������
	void act(const int act_mode);   //���ݰ�����������ְ���Ч��
};