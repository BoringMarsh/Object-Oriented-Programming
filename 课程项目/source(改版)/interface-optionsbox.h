#pragma once
#include"interface-button.h"

//�����öԻ����������ķ���ֵ
#define OPBX_RET_SURE    0x4001  //ȷ��
#define OPBX_RET_CANCEL  0x4002  //ȡ��

//���öԻ������ɫ
#define OPBX_BG_COLOR    COLOR_HBLACK  //����ɫ
#define OPBX_FG_COLOR_A  COLOR_HWHITE  //����ǰ��ɫ
#define OPBX_FG_COLOR_D  COLOR_BLACK   //����ǰ��ɫ

//���öԻ�������ֵ�����
#define OPBX_COORD_X  28  //���öԻ������ϽǺ�����
#define OPBX_COORD_Y  7   //���öԻ������Ͻ�������
#define OPPROM_COORD_X1  OPBX_COORD_X+2    //���öԻ����У���ʾ��1���ϽǺ�����
#define OPPROM_COORD_Y1  OPBX_COORD_Y+2    //���öԻ����У���ʾ��1���Ͻ�������
#define OPPROM_COORD_X2  OPBX_COORD_X+2    //���öԻ����У���ʾ��2���ϽǺ�����
#define OPPROM_COORD_Y2  OPBX_COORD_Y+7    //���öԻ����У���ʾ��2���Ͻ�������
#define OPPROM_COORD_X3  OPBX_COORD_X+2    //���öԻ����У���ʾ��3���ϽǺ�����
#define OPPROM_COORD_Y3  OPBX_COORD_Y+11   //���öԻ����У���ʾ��3���Ͻ�������
#define SETBLINK_COORD_X  OPBX_COORD_X+4   //���öԻ����У���˸���ÿ����ϽǺ�����
#define SETBLINK_COORD_Y  OPBX_COORD_Y+3   //���öԻ����У���˸���ÿ����Ͻ�������
#define SETSHOW_COORD_X   OPBX_COORD_X+14  //���öԻ����У����Ч�����ÿ����ϽǺ�����
#define SETSHOW_COORD_Y   OPBX_COORD_Y+3   //���öԻ����У����Ч�����ÿ����Ͻ�������
#define SETSOUND_COORD_X  OPBX_COORD_X+4   //���öԻ����У��������ÿ����ϽǺ�����
#define SETSOUND_COORD_Y  OPBX_COORD_Y+8   //���öԻ����У��������ÿ����Ͻ�������
#define SETFONT_COORD_X   OPBX_COORD_X+14  //���öԻ����У������С���ÿ����ϽǺ�����
#define SETFONT_COORD_Y   OPBX_COORD_Y+8   //���öԻ����У������С���ÿ����Ͻ�������
#define OPSURE_COORD_X    OPBX_COORD_X+4   //���öԻ����У���ȷ���������ϽǺ�����
#define OPSURE_COORD_Y    OPBX_COORD_Y+12  //���öԻ����У���ȷ���������Ͻ�������
#define OPCANCEL_COORD_X  OPBX_COORD_X+14  //���öԻ����У���ȡ���������ϽǺ�����
#define OPCANCEL_COORD_Y  OPBX_COORD_Y+12  //���öԻ����У���ȡ���������Ͻ�������

//���öԻ��򰴼���
#define OPBX_BUTTON_NUM  6

//����Ϊ�������͵���ǰ����
class cover;

/*���öԻ����������*/
class optionsbox {
private:
	button button_setblink{ SETBLINK_COORD_X,SETBLINK_COORD_Y,OPBX_SETBLINK };  //��˸���ÿ�
	button button_setshow { SETSHOW_COORD_X,SETSHOW_COORD_Y,OPBX_SETSHOW };     //���Ч�����ÿ�
	button button_setsound{ SETSOUND_COORD_X,SETSOUND_COORD_Y,OPBX_SETSOUND };  //�������ÿ�
	button button_setfont { SETFONT_COORD_X,SETFONT_COORD_Y,OPBX_SETFONT };     //�����С���ÿ�
	button button_sure    { OPSURE_COORD_X,OPSURE_COORD_Y,OPBX_SURE };          //��ȷ������
	button button_cancel  { OPCANCEL_COORD_X,OPCANCEL_COORD_Y,OPBX_CANCEL };    //��ȡ������
	const int OPBX_WIDTH;  //���öԻ�����

	/*���³�Ա�ڲ��������ʱ�ı�ֵ���������ٸ���ʵ��*/
	bool if_blink;  //�Ƿ���˸
	bool if_show;   //�Ƿ������Ч��
	bool if_sound;  //�Ƿ�������
	int fontsize;   //�����С
public:
	char* read_fontsize(char* String);  //��ȡ�����С��ת�����ַ���
	void print(const char* prompt1, const char* prompt2);  //��ӡ���öԻ���
	int mouse_if_button(const int X, const int Y);  //�ж����λ���Ƿ���ĳһ������
	void selective_default(const int selection);    //ѡ���Ե�Ϊĳһ����ȡ������
	void selective_activate(const int selection);   //ѡ���Ե�Ϊĳһ�������ø���
	void move_cursor(const bool pblock, const int ppos);  //���ݲ������������λ�����ƶ��������Ӧλ��
	void keyboard_input(const bool pblock, const int ppos, const int keycode);    //���ݲ������������λ������������ֵ���ı��Ӧ������ֵ
	bool info_check();  //�������������Ƿ����
	int control(bool* IF_SOUND, int* FONTSIZE);  //�ü��������öԻ����ڽ��в���
	void erase(cover& TitleScreen);  //�ػ����⻭�棬�ﵽ�����Ի����Ч��

	optionsbox() :if_blink(true), if_show(true), if_sound(true), fontsize(28), OPBX_WIDTH(15) {}  //���캯��
};