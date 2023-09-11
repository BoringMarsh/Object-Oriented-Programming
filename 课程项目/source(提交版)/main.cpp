#include<iostream>
#include<Windows.h>
#include"colorball.h"
#include"ball.h"
#include"player.h"
#include"interface-messagebox.h"
#include"interface-cover.h"
#include"interface-optionsbox.h"
using namespace std;

int main()
{
	srand((unsigned int)(time(0)));     /*����α�����������*/
	cct_setcolor();                     /*������ɫ*/
	cct_setcursor(CURSOR_INVISIBLE);    /*���ع��*/

	game_messagebox GameMessagebox;    /*��Ϸ�ڶԻ���*/
	cover_messagebox CoverMessagebox;  /*���⻭��Ի���*/
	file_tools FileManager;  /*�ĵ��������*/
	cover TitleScreen;       /*���⻭�����*/
	optionsbox OptionsBox;   /*���öԻ���*/
	ball Ball[81];  /*��Ϸ�ڲ��Ķ�������*/
	player Client;  /*�û�����*/

	bool if_game = false;      /*�Ƿ������Ϸ*/
	bool if_new = false;       /*�Ƿ�ʼ����Ϸ*/
	bool if_colorball = true;  /*�Ƿ��������������Ϸ����*/
	bool if_sound = true, * ps = &if_sound;  /*�Ƿ���������ָ�����ָ��*/
	int fontsize = 28, * pf = &fontsize;     /*�����С��ָ�����ָ��*/
	int ret = 0, num = 0;  /*���⻭��Ի��������������ֵ���ļ���λ*/
	cct_setfontsize("������", fontsize);  /*���������С*/
	TitleScreen.print();  /*��ʾ���⻭��*/

	while (if_colorball) {  /*��Ϊ�棬����Ϸ���˳�*/
		switch (TitleScreen.control(ps)) {  /*ȡ���⻭�����*/

		/*1�����¡�����Ϸ����*/
		case COVER_RET_NEW:
			if_game = true;  /*��־�Ž�����Ϸ*/
			if_new = true;   /*��־�Ž�������Ϸ*/
			break;

		/*2�����¡�������Ϸ����*/
		case COVER_RET_LOAD:
			if_game = true;  /*��־�Ž�����Ϸ*/

			CoverMessagebox.print(BUTTON_FIVE, "�����ĸ�λ�õĴ浵��");  /*��ӡ�Ի���*/
			ret = CoverMessagebox.control();  /*ȡ�Ի������*/
			num = ret - CVMB_RET_ONE + 1;     /*ȡ�ļ���λ*/

			if (ret >= CVMB_RET_ONE && ret <= CVMB_RET_FOUR) {  /*�����ˡ�1������4����*/
				if (FileManager.if_file_deleted(num)) {  /*��ѡ������λ�浵Ϊ�գ����֪�û��浵Ϊ��*/
					char prompt[] = "λ�� �ϵĴ浵Ϊ��";
					prompt[4] = num + '0';
					CoverMessagebox.print(BUTTON_ONE, prompt);
					CoverMessagebox.control();
					CoverMessagebox.erase(TitleScreen);
					continue;
				}

				else  /*��ѡ����λ�浵��Ϊ�գ����ȡ�浵*/
					FileManager.file_load(Client, Ball, num);
			}

			else {  /*�����ˡ�ȡ����������������Ի���*/
				CoverMessagebox.erase(TitleScreen);
				continue;
			}
			break;

		/*3�����¡����á���*/
		case COVER_RET_OPTIONS:
			OptionsBox.print("��˸��    ���Ч����", "������    �����С��");  /*��ӡ���öԻ���*/

			switch (OptionsBox.control(ps, pf)) {  /*ȡ���öԻ������*/
			case OPBX_RET_SURE:
				cct_setfontsize("������", *pf);  /*�����С�޷���control������ֱ�����ã������¡�ȷ����������ı������С*/
				OptionsBox.erase(TitleScreen);   /*�������öԻ���*/
				continue;
				break;
			case OPBX_RET_CANCEL:
				OptionsBox.erase(TitleScreen);   /*�����¡�ȡ������������������öԻ���*/
				continue;
				break;
			}
			
			break;

		/*4�����¡���������*/
		case COVER_RET_HELP:
			CoverMessagebox.print(BUTTON_ONE, "ÿ����һ�����ӵ���λ��", "�ĸ������������ͬɫ������", "����������������������");  /*��ӡ�Ի���*/
			CoverMessagebox.control();  /*ȡ������ʹ���û�������ɵ����ȷ�������Ķ���*/
			CoverMessagebox.erase(TitleScreen);  /*�����Ի���*/
			continue;
			break;

		/*5�����¡����ڡ���*/
		case COVER_RET_ABOUT:
			CoverMessagebox.print(BUTTON_ONE, "����colorball v1.0.0:", "  �����ߣ�����", "  ѧ�ţ�2151294");  /*��ӡ�Ի���*/
			CoverMessagebox.control();  /*ȡ������ʹ���û�������ɵ����ȷ�������Ķ���*/
			CoverMessagebox.erase(TitleScreen);  /*�����Ի���*/
			continue;
			break;

		/*6�����¡��˳�����*/
		case COVER_RET_EXIT:
			CoverMessagebox.print(BUTTON_TWO, "��ȷ��Ҫ�˳�colorball?");  /*��ӡ�Ի���*/

			switch (CoverMessagebox.control()) {  /*ȡ�Ի������*/
			case CVMB_RET_YES:
				if_colorball = false;  /*�������ǡ��������־��Ϊ�٣�֮������ѭ�����������*/
				break;
			case CVMB_RET_NO:
				CoverMessagebox.erase(TitleScreen);  /*�������񡱼�����������Ի���*/
				continue;
				break;
			}
			break;
		}

		if (if_game) {  /*��Ҫ������Ϸ������׼������*/
			cct_cls();  /*����*/
			cct_setconsoleborder(112, 48, 112, 48);  /*���ô��ڼ���������С*/
			cct_setfontsize("������", fontsize);     /*���������С*/
			print_chessboard();  /*��ӡ��ɫ����*/

			if (if_new)
				Client.summon(Ball, 7, ps);  /*����������Ϸ����ֱ���������7������*/
			else
				Client.print_balls(Ball);  /*���������µ���Ϸ�����ӡ���е���������*/

			Client.update_score();  /*���µ÷�*/
			Client.update_color();  /*������ɫ*/
			Client.update_state(STATE_SELECTING);  /*����״̬*/
		}

		while (if_game) {  /*��Ϊ�棬����Ϸ���У����˻ر��⻭��*/
			int RET;  /*��Ϸ�ڶԻ��������������ֵ*/

			switch (Client.control(Ball, ps)) {  /*ȡ�û�����*/

			/*1�����¡����á���*/
			case GAME_RET_OPTIONS:
				GameMessagebox.print(BUTTON_SWITCH, "��˸��      ���Ч����");  /*��ӡ�Ի���*/

				while (1) {
					RET = GameMessagebox.control();  /*ȡ�Ի������*/

					if (RET >= GMMB_RET_BLINK_OFF && RET <= GMMB_RET_SHOW_ON)  /*�������˻������ϵİ���������ж�Ӧ������*/
						GameMessagebox.options(RET);
					else {  /*�����¡�ȷ����������������Ի���*/
						GameMessagebox.erase(Client, Ball);
						cct_enable_mouse();  /*��control��������ʱ��������꣬�������������*/
						break;
					}
				}
				break;

			/*2�����¡����桱��*/
			case GAME_RET_SAVE:
				GameMessagebox.print(BUTTON_FIVE, "���浽�ĸ�λ�ã�");  /*��ӡ�Ի���*/
				RET = GameMessagebox.control();  /*ȡ�Ի������*/

				if (RET >= GMMB_RET_ONE && RET <= GMMB_RET_FOUR) {  /*�����ˡ�1������4�������򱣴浽��Ӧ��λ������֪�û��ѱ���*/
					FileManager.file_save(Client, Ball, RET - GMMB_RET_ONE + 1);

					char prompt[] = "�ļ��ѱ��浽λ�� ";
					prompt[16] = RET - GMMB_RET_ONE + 1 + '0';
					GameMessagebox.print(BUTTON_ONE, prompt);
					GameMessagebox.control();
					GameMessagebox.erase(Client, Ball);
				}
				else  /*�����ˡ�ȡ����������������Ի���*/
					GameMessagebox.erase(Client, Ball);
				break;

			/*3�����¡�ɾ������*/
			case GAME_RET_DELETE:
				GameMessagebox.print(BUTTON_FIVE, "ɾ���ĸ�λ�õĴ浵��");  /*��ӡ�Ի���*/
				RET = GameMessagebox.control();  /*ȡ�Ի������*/

				if (RET >= GMMB_RET_ONE && RET <= GMMB_RET_FOUR) {  /*�����ˡ�1������4��������ɾ����Ӧ��λ�Ĵ浵������֪�û���ɾ��*/
					FileManager.file_delete(RET - GMMB_RET_ONE + 1);

					char prompt[] = "��ɾ��λ�� �ϵĴ浵";
					prompt[10] = RET - GMMB_RET_ONE + 1 + '0';
					GameMessagebox.print(BUTTON_ONE, prompt);
					GameMessagebox.control();
					GameMessagebox.erase(Client, Ball);
				}
				else  /*�����ˡ�ȡ����������������Ի���*/
					GameMessagebox.erase(Client, Ball);
				break;

			/*4�����¡��˳�����*/
			case GAME_RET_QUIT:
				GameMessagebox.print(BUTTON_TWO, "��ȷ��Ҫ�˳���Ϸ��", "  ����δ����Ľ��Ȼ���ʧ");  /*��ӡ�Ի���*/

				switch (GameMessagebox.control()) {  /*ȡ�Ի������*/

				/*4.1�����¡��ǡ���*/
				case GMMB_RET_YES:
					Client.matrix_clear(Ball);  /*����ڲ�����*/
					if_game = false;  /*��־�Ų��ٽ�����Ϸ*/
					if_new = false;   /*��־�Ų��ٽ�������Ϸ*/
					cct_setcolor();   /*������ɫ*/
					cct_setfontsize("������", fontsize);  /*���������С*/
					TitleScreen.print();  /*�ػ����⻭��*/
					break;

				/*4.2�����¡��񡱼�*/
				case GMMB_RET_NO:
					GameMessagebox.erase(Client, Ball);  /*�������Ի��򲢼���ѭ��*/
					continue;
					break;
				}
				break;

			/*5����Ϸʧ��*/
			case GAME_RET_FAILURE:
				Client.matrix_clear(Ball);  /*����ڲ�����*/

				if (*ps)  /*������Ҫ��������*/
					cout << '\007';

				GameMessagebox.print(BUTTON_ONE, "��Ϸ������");  /*��ӡ�Ի���*/
				GameMessagebox.control();  /*ȡ������ʹ���û�������ɵ����ȷ�������Ķ���*/

				if_game = false;  /*��־�Ų��ٽ�����Ϸ*/
				if_new = false;   /*��־�Ų��ٽ�������Ϸ*/
				cct_setcolor();   /*������ɫ*/
				cct_setfontsize("������", fontsize);  /*���������С*/
				TitleScreen.print();  /*�ػ����⻭��*/
				break;
			}
		}
	}
	
	/*�˳�������Ϸ�����β����*/
	cct_setfontsize("������", 28);  /*���������С*/
	cct_setcolor();  /*������ɫ*/
	cct_cls();       /*����*/
	return 0;
}