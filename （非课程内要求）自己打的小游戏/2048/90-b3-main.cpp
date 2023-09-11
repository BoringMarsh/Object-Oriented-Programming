#include"90-b3.h"

/*�������ȫ�ֱ���������Ľṹ��*/
game __GAME;

/***************************************************************************
  �������ƣ�order_input
  ��    �ܣ�����ȷ�Դ����ǰ���£�������Ϸ������
  �����������
  �� �� ֵ����
  ˵    ����������ֱ�Ӹı��ⲿȫ�ֱ���__GAME.order��ֵ
***************************************************************************/
void order_input()
{
	int n;  /*����ֵ*/

	while (1) {
		cct_gotoxy(CVMB_COORD_X + 12, CVMB_COORD_Y + 4);
		for (int i = 0; i < 5; i++)
			cout << ' ';
		cct_gotoxy(CVMB_COORD_X + 12, CVMB_COORD_Y + 4);
		n = _getche() - '0';

		if (n >= ORDER_MIN && n <= ORDER_MAX)
			break;
	}

	__GAME.order = n;  /*�ı��Ӧ��ʵ��ֵ*/
}

/***************************************************************************
  �������ƣ�cover_in_progress
  ��    �ܣ���Ϸ���ⲿ��
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void cover_in_progress()
{
	while (1) {
		cct_setcursor(CURSOR_INVISIBLE);
		char PROMPT1[50], PROMPT2[50], PROMPT3[50];  /*���⻭��Ի����������ʾ��*/
		int RET1 = __GAME.cover.control();  /*���⻭���������ֵ*/
		int RET2 = 0;  /*���⻭��Ի����������ֵ*/

		switch (RET1) {  /*�ڱ��⻭���Ͻ��в���*/

		/*��ʾ����*/
		case COVER_ABOUT:
			/*ȡ�����Ϣ*/
			strcpy(PROMPT1, "����2048  ");
			strcat(PROMPT1, __GAME.version);
			strcpy(PROMPT2, "  �����ߣ����ĵ���");
			strcpy(PROMPT3, "  �������°汾");

			__GAME.cover_mailbox.print(BUTTON_ONE, PROMPT1, PROMPT2, PROMPT3);  /*��ʾ�Ի����г���Ϣ*/
			__GAME.cover_mailbox.control();  /*�����󷵻�*/
			cct_setcolor();
			__GAME.cover_mailbox.erase();
			continue;
			break;

		case COVER_OPTIONS:
			__GAME.cover_mailbox.print(BUTTON_SWITCH, "ɫ����˸��  ��ʾ��");
			while (1) {
				RET2 = __GAME.cover_mailbox.control();
				if (RET2 == CVMB_RET_SURE)
					break;
				else
					__GAME.cover_mailbox.options(RET2);
			}
			__GAME.cover_mailbox.erase();
			continue;
			break;

		/*��ʼ����Ϸ*/
		case COVER_NEW:
		case COVER_AUTO:
			__GAME.score = 0;       /*��������*/
			__GAME.stepnumber = 0;  /*��������*/
			for (int i = 0; i < __GAME.order * __GAME.order; i++)  /*�ڲ���������*/
				__GAME.matrix[i] = 0;

			/*ȡ�����Ϣ*/
			strcpy(PROMPT1, "������������( - )��");
			PROMPT1[15] = ORDER_MIN + '0';
			PROMPT1[17] = ORDER_MAX + '0';
			strcpy(PROMPT2, "�����ǡ����룬�����񡱷���");

			__GAME.cover_mailbox.print(BUTTON_TWO, PROMPT1, PROMPT2);  /*��ʾ�Ի���Ҫ������Ϸ��Ľ���ֵ��ѯ���Ƿ����*/

			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			order_input();  /*�������*/
			cct_setcursor(CURSOR_INVISIBLE);

			if (__GAME.cover_mailbox.control() == CVMB_RET_NO) {  /*���������������򷵻أ������ǡ������*/
				cct_setcolor();
				__GAME.cover_mailbox.erase();
				continue;
			}

			__GAME.game_mailbox.set_button_coord();  /*��Ϸ�ڶԻ��򰴼����긳ֵ*/
			__GAME.keyboard.set_button_coord();      /*С���̰������긳ֵ*/

			cct_setcolor();
			console_print_base();      /*��ӡ��Ϸ���*/
			__GAME.gameboard.print_info();  /*��ʾ��Ϸ��Ϣ*/
			__GAME.keyboard.print();        /*��ӡС����*/

			summon_two();          /*�����������2*/
			summon_two();

			if (RET1 == COVER_NEW)
				game_in_progress();    /*������Ϸ����*/
			else
				__GAME.ai_player.auto_game();
			break;

		/*����������Ϸ*/
		case COVER_LOAD:
			__GAME.cover_mailbox.print(BUTTON_FIVE, "������һ���浵��");  /*��ʾ�Ի���ѯ��������һ���浵*/

			RET2 = __GAME.cover_mailbox.control();  /*������������ȡ�����򷵻أ������ּ������*/
			if (RET2 == CVMB_RET_CANCEL) {
				cct_setcolor();
				__GAME.cover_mailbox.erase();
				continue;
			}

			if (!__GAME.files.if_file_deleted(RET2 - CVMB_RET_ONE + 1)) {  /*��ѡ��λ���ϵ��ļ�δ�����*/
				__GAME.files.file_load(RET2 - CVMB_RET_ONE + 1);  /*��ȡ�浵*/
				__GAME.game_mailbox.set_button_coord();  /*��Ϸ�ڶԻ��򰴼����긳ֵ*/
				__GAME.keyboard.set_button_coord();      /*С���̰������긳ֵ*/

				cct_setcolor();
				console_print_base();       /*��ӡ��Ϸ���*/
				__GAME.gameboard.print_info();   /*��ʾ��Ϸ��Ϣ*/
				__GAME.gameboard.update_info();  /*������Ϸ��Ϣ*/
				__GAME.gameboard.block_multiple_print();  /*��ӡ����ɫ��*/
				__GAME.keyboard.print();        /*��ӡС����*/

				game_in_progress();    /*������Ϸ����*/
			}

			else {  /*��ѡ��λ���ϵ��ļ������*/
				strcpy(PROMPT1, "λ�� �ϵĴ浵Ϊ��");
				PROMPT1[4] = RET2 - CVMB_RET_ONE + '1';

				__GAME.cover_mailbox.print(BUTTON_ONE, PROMPT1);  /*��ʾ�Ի�����ʾѡ��λ���ϵ��ļ������*/
				__GAME.cover_mailbox.control();  /*�����󷵻�*/
				cct_setcolor();
				__GAME.cover_mailbox.erase();
				continue;
			}

			break;

		/*�˳�2048*/
		case COVER_QUIT:
			__GAME.cover_mailbox.print(BUTTON_TWO, "��ȷ��Ҫ�˳���Ϸ��");  /*��ʾ�Ի���ѯ���Ƿ��˳���Ϸ*/

			RET2 = __GAME.cover_mailbox.control();  /*���������������򷵻أ������ǡ����˳�*/
			if (RET2 == CVMB_RET_YES) {
				cct_setcolor();
				cct_setconsoleborder(80, 25);
				cct_setcursor(CURSOR_VISIBLE_NORMAL);
				return;
			}

			else {
				cct_setcolor();
				__GAME.cover_mailbox.erase();
				continue;
			}
			break;
		}

		cct_setcolor();  /*������ɫ*/
		cct_cls();       /*����*/
		__GAME.cover.print();   /*�ػ����⻭��*/
	}
}

/***************************************************************************
  �������ƣ�game_in_progress
  ��    �ܣ���Ϸ���岿��
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void game_in_progress()
{
	int loop = 1;
	const char prompt[] = "�޿ɺϳ����Ϸ������";
	char prompt1[] = "��Ϸ�ѱ��浽λ�� ";
	char prompt2[] = "��ɾ��λ�� �ϵĴ浵";

	while (loop) {
		if (if_end()) {  /*�ж���Ϸ�Ƿ����*/
			__GAME.game_mailbox.print(BUTTON_ONE, prompt);  /*�����Ի�����ʾ��Ϸ�ѽ���*/
			__GAME.game_mailbox.control();  /*������ȷ���������˳�*/
			break;
		}

		int ret = __GAME.keyboard.control();  /*�����󣬸��ݷ���ֵ�жϲ���*/

		switch (ret) {  /*������һ��������������һ���ж�*/

		/*�����ƶ�*/
		case 0:
			if (if_full() == false)
				summon_two();
			break;

		/*�˳�*/
		case QUIT:
			loop = 0;
			break;

		/*�ؿ�*/
		case RESET:
			for (int i = 0; i < __GAME.order * __GAME.order; i++)  /*�ڲ���������*/
				__GAME.matrix[i] = 0;
			__GAME.score = 0;       /*��������*/
			__GAME.stepnumber = 0;  /*��������*/

			cct_setcolor();
			console_print_base();  /*�ػ�����*/
			__GAME.keyboard.print();
			summon_two();  /*�����������2*/
			summon_two();
			__GAME.gameboard.print_info();   /*��ʾ��Ϣ*/
			break;

		/*����*/
		case CONTINUE:
			__GAME.game_mailbox.erase();     /*�ػ���Ϸ���*/
			__GAME.gameboard.update_info();  /*������Ϸ��Ϣ*/
			break;

		/*�浵*/
		case SAVE_1:
		case SAVE_2:
		case SAVE_3:
		case SAVE_4:
			__GAME.files.file_save(ret - SAVE_1 + 1);
			prompt1[16] = ret - SAVE_1 + '1';

			__GAME.game_mailbox.print(BUTTON_ONE, prompt1);
			__GAME.game_mailbox.control();
			__GAME.game_mailbox.erase();
			break;

		/*��մ浵*/
		case DELETE_1:
		case DELETE_2:
		case DELETE_3:
		case DELETE_4:
			__GAME.files.file_delete(ret - DELETE_1 + 1);
			prompt2[10] = ret - DELETE_1 + '1';

			__GAME.game_mailbox.print(BUTTON_ONE, prompt2);
			__GAME.game_mailbox.control();
			__GAME.game_mailbox.erase();
			break;
		}
	}
}

/***************************************************************************
  �������ƣ�main
  ��    �ܣ�������
  �����������
  �� �� ֵ��0
  ˵    ������
***************************************************************************/
int main()
{
	/*���²����ڳ�������ǰִ��һ�μ���*/
	srand((unsigned int)(time(0)));    /*����α�����������*/
	__GAME.cover.set_button_type();           /*���⻭�水����������*/
	__GAME.cover.set_button_coord();          /*���⻭�水�����긳ֵ*/
	__GAME.cover_mailbox.set_button_type();   /*���⻭��Ի��򰴼���������*/
	__GAME.cover_mailbox.set_button_coord();  /*���⻭��Ի��򰴼����긳ֵ*/
	__GAME.keyboard.set_button_type();        /*С���̰�����������*/
	__GAME.game_mailbox.set_button_type();    /*��Ϸ�ڶԻ��򰴼���������*/
	__GAME.cover.print();  /*��ӡ���⻭��*/

	cover_in_progress();  /*���⻭���������Ϊ������������*/
	return 0;
}