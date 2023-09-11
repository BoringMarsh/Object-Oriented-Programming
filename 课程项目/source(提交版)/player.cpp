#define _CRT_SECURE_NO_WARNINGS
#include<Windows.h>
#include<string>
#include"player.h"
#include"colorball.h"
#include"ball.h"
#include"interface-messagebox.h"

/*��̬��Ա���г�ʼ��*/
bool player::if_blink = true;
bool player::if_show = true;

/***************************************************************************
  �������ƣ�matrix_clear
  ��    �ܣ�����ڲ�����
  ���������ball b[]����Ϸ�ڲ��Ķ�������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void player::matrix_clear(ball b[])
{
	ball clear;  /*ʹ��Ĭ�Ϲ��캯������һ��clear����*/

	for (int i = 0; i < 81; i++) {
		b[i] = clear;  /*��clear���󸳸���ǰλ���ϵĶ���*/
		ball::if_ball[i] = false;  /*����ǰλ���ϵı����Ϊ��*/
	}

	score = 0;  /*�÷ֹ���*/
	if_select = false;  /*ѡ��״̬��Ϊ��*/
	select_x = -1;  /*ѡ��λ��������Ϊ-1*/
	select_y = -1;  /*ѡ��λ��������Ϊ-1*/
}

/***************************************************************************
  �������ƣ�read_score
  ��    �ܣ���ȡ�÷ֲ�ת�����ַ���
  ���������char* s����Ž�����ַ�����
  �� �� ֵ��char*���ַ�����ʽ�Ķ�ȡ���
  ˵    ����1���������ڶ�ȡ����λ����ɺ󣬽��������ת��Ϊ�ո�
			2���ֶ������β��
***************************************************************************/
char* player::read_score(char* s)
{
	if (score) {  /*��������Ϊ�㣬��������ȡ*/
		int i;
		int S = score;

		for (i = 0; i < 10; i++) {  /*������λ��*/
			s[9 - i] = S % 10;
			S = (S - S % 10) / 10;
		}

		i = 0;
		bool if_score_char = false;

		while (i < 10) {
			if (s[i])
				if_score_char = true;  /*������һλ��Ϊ�����������Ϊ��*/

			if (if_score_char)
				s[i] = s[i] + '0';  /*������Ϊ���ÿһλ��ת��Ϊ��Ӧ���ֵ��ַ�*/
			else
				s[i] = ' ';  /*δ����Ϊ��ʱ��ÿһλ��ת��Ϊ�ո�*/
			i++;
		}
	}

	else {  /*������Ϊ�㣬���ַ������һλΪ'0'������Ϊ�ո�*/
		for (int i = 0; i < 9; i++)
			s[i] = ' ';
		s[9] = '0';
	}

	s[10] = '\0';  /*���β��*/
	return s;
}

/***************************************************************************
  �������ƣ�read_color
  ��    �ܣ���ȡ�´γ��ֵ���ɫ��ת�����ַ���
  ���������char* c����Ž�����ַ�����
  �� �� ֵ��char*���ַ�����ʽ�Ķ�ȡ���
  ˵    �����ֶ������β��
***************************************************************************/
char* player::read_color(char* c)
{
	int i;

	for (i = 0; i < 4; i++)  /*ͷ4���ַ���Ϊ�ո񣬲�������'\0'������֮������ַ�������*/
		c[i] = ' ';
	c[4] = '\0';

	for (i = 0; i < 3; i++) {  /*��ȡ��ɫ��ÿ�ν���ɫת��Ϊ�ַ��������ӵ�ԭ�ַ�����*/
		char color[3];
		strcat(c, color_trans_string(next_color[i], color));
	}

	c[10] = '\0';  /*���β��*/
	return c;
}

/***************************************************************************
  �������ƣ�update_score
  ��    �ܣ����µ÷�
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void player::update_score()
{
	char s[11];
	cct_showstr(SCORE_COORD_X + 2, SCORE_COORD_Y + 2, read_score(s), COLOR_CYAN, COLOR_HWHITE);
}

/***************************************************************************
  �������ƣ�update_color
  ��    �ܣ�������ɫ
  �����������
  �� �� ֵ����
  ˵    ��������Ҫʹ�ò�ͬ����ɫ��������޷�һ���Խ������ַ������
***************************************************************************/
void player::update_color()
{
	char color[11];

	for (int i = 0; i < 4; i++)  /*����ո�*/
		cct_showch(COLOR_COORD_X + 2, COLOR_COORD_Y + 2, read_color(color)[i]);

	for (int i = 0; i < 3; i++) {  /*�ö�Ӧ��ɫ����ַ���*/
		cct_showch(COLOR_COORD_X + 2 * (i + 3), COLOR_COORD_Y + 2, read_color(color)[4 + 2 * i], COLOR_BLACK, next_color[i]);
		cct_showch(COLOR_COORD_X + 2 * (i + 3), COLOR_COORD_Y + 2, read_color(color)[5 + 2 * i], COLOR_BLACK, next_color[i]);
	}
}

/***************************************************************************
  �������ƣ�update_state
  ��    �ܣ�����״̬
  ���������const char* state��״̬��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void player::update_state(const char* state)
{
	cct_showstr(STATE_COORD_X + 2, STATE_COORD_Y + 2, state, COLOR_HRED, COLOR_HWHITE);
}

/***************************************************************************
  �������ƣ�blink_blockborder
  ��    �ܣ�ʹһ�����ӵı߽���˸
  ���������const int coord�����ӵ�һά���ֻ꣨����
            const int blink_times����˸������ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void player::blink_blockborder(const int coord, const int blink_times)
{
	const int X = coord % 9;        /*��һά����ת��Ϊ����*/
	const int Y = (coord - X) / 9;  /*��һά����ת��Ϊ����*/

	for (int i = 0; i < blink_times; i++) {
		cct_gotoxy(10 * X, 5 * Y);
		print_blockborder(9 * Y + X, COLOR_HBLACK, COLOR_WHITE);
		Sleep(10);

		cct_gotoxy(10 * X, 5 * Y);
		print_blockborder(9 * Y + X, COLOR_WHITE, COLOR_BLACK);
		Sleep(10);
	}
}

/***************************************************************************
  �������ƣ�summon
  ��    �ܣ�����������ɸ�����
  ���������ball b[]����Ϸ�ڲ��Ķ�������
			const int summon_times�����ɸ�����ֻ����
			bool* if_sound���Ƿ�������
  �� �� ֵ����
  ˵    ���������������ɵ�ͬʱ�������������һ�γ��ֵ���ɫ
***************************************************************************/
void player::summon(ball b[], const int summon_times, bool* if_sound)
{
	for (int i = 0; i < summon_times; i++) {
		int COLOR = 0;  /*���ɵ���ɫ*/
		if (summon_times == 7)  /*������7������˵����Ϸ�տ�ʼ��ֱ��ȡ������ɵ���ɫ*/
			COLOR = num_trans_color(rand() % 6);
		int X, Y;  /*����������*/

		if (if_end(b))  /*������������������ѭ����ֹͣ�������ӣ�����������ѭ��*/
			break;

		while (1) {
			X = rand() % 9;  /*���ȡ����*/
			Y = rand() % 9;  /*���ȡ����*/
			const int coord = Y * 9 + X;  /*������������ת��Ϊһά����*/

			if (ball::if_ball[coord])  /*�����ѡ�е�λ���������ӣ�������ѡ������*/
				continue;
			else {  /*�����ѡ�е�λ���������ӣ����ڴ���������*/
				if (summon_times != 7)  /*������������Ϊ7����˵������3��������һ�γ��ֵ���ɫ����COLOR*/
					COLOR = next_color[i];
				b[coord].set(X, Y, COLOR);  /*�趨���ӵ�λ�ú���ɫ*/
				ball::if_ball[Y * 9 + X] = true;  /*��ǰλ�õı�־��Ϊ��*/

				if (*if_sound)  /*������Ҫ��������*/
					Beep(SOUND_LLA, 100);

				b[coord].print();  /*��ӡ������*/

				if (if_blink)  /*������Ҫ������˸*/
					blink_blockborder(coord, 10);

				Sleep(100);  /*��ʱ�������ٶ�*/
				break;
			}
		}//end of while(1)
	}//end of for (int i = 0...

	for (int i = 0; i < 3; i++) {  /*�������3����һ�γ��ֵ���ɫ��������next_color*/
		const int COLOR = num_trans_color(rand() % 6);
		next_color[i] = COLOR;
	}
}

/***************************************************************************
  �������ƣ�move
  ��    �ܣ��ƶ�����
  ���������ball b[]����Ϸ�ڲ��Ķ�������
            const int src_x���������������ֻ����
			const int src_y���������������ֻ����
			const int dst_x�������յ�������ֻ����
			const int dst_y�������յ�������ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void player::move(ball b[], const int src_x, const int src_y, const int dst_x, const int dst_y)
{
	const int src = 9 * src_y + src_x;  /*���������������ת��Ϊһά����*/
	const int dst = 9 * dst_y + dst_x;  /*���յ�����������ת��Ϊһά����*/

	/*�����λ�������ӡ��յ�λ�������ӣ�������ƶ�����*/
	if (ball::if_ball[src] && !ball::if_ball[dst]) {
		b[dst].set(dst_x, dst_y, b[src].color);  /*�����յ�λ�����ӵ��������ɫ*/
		ball::if_ball[dst] = true;  /*�յ�λ�õı�־��Ϊ��*/

		b[src].color = COLOR_WHITE;  /*���λ�����ӵ���ɫ��Ϊ��ɫ*/
		ball::if_ball[src] = false;  /*���λ�õı�־��Ϊ��*/

		b[src].print();  /*��ӡ���λ�õ����ӣ�����Ϊ�٣���ӡ�հף�*/
		b[dst].print();  /*��ӡ�յ�λ�õ�����*/

		b[src].x = -1;  /*�������λ�����ӵ������������ߣ���Ϊ-1��*/
		b[src].y = -1;  /*�������λ�����ӵ������������ߣ���Ϊ-1��*/
	}
}

/***************************************************************************
  �������ƣ�scan
  ��    �ܣ�ɨ�������������
  ���������ball b[]����Ϸ�ڲ��Ķ�������
  �� �� ֵ����
  ˵    ����������һ����ɨ�����ĸ������Ͽ�����������
***************************************************************************/
void player::scan(ball b[])
{
	ball* p[2];  /*����ָ���ڲ������ָ��*/
	int count;   /*������ͬɫ���Ӽ�����*/

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			const int coord = 9 * i + j;  /*������������ת��Ϊһά����*/

			/*����ǰλ�������Ӳ��ǰ�ɫ������λ���������ӣ������Ҳ�������ɫҲ����ͬ��ɫ���������һ���ж�*/
			if (b[coord].color == b[coord + 1].color && b[coord].color != COLOR_WHITE) {
				p[0] = &b[coord + 1];  /*p[0]ָ���Ҳ�����*/
				p[1] = &b[(i + 1) * 9 - 1];  /*p[1]ָ��ǰ�����һ������*/
				count = 1;  /*��������Ϊ1*/

				/*��p[0]ָ���������ɫ��Ȼһ�£���p[0]λ�ò���p[1]֮�󣨼�û�г�����ǰ�У����������������p[0]��ǰ�ƶ�*/
				while (p[0]->color == b[coord].color && p[0] <= p[1]) {
					count++;
					p[0]++;
				}

				/*��ɨ����ɣ���������С��5���򽫷������������Ķ���������ϱ��*/
				if (count >= 5) {
					for (int k = 0; k < count; k++)
						b[coord + k].mark = true;
					j = j + count;  /*j����count������ѭ������*/
				}
			}

			count = 0;  /*ÿ��ɨ����ɺ����������Ϊ��*/
		}
	}

	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			const int coord = 9 * i + j;  /*������������ת��Ϊһά����*/

			/*����ǰλ�������Ӳ��ǰ�ɫ������λ���������ӣ������·�������ɫҲ����ͬ��ɫ���������һ���ж�*/
			if (b[coord].color == b[coord + 9].color && b[coord].color != COLOR_WHITE) {
				p[0] = &b[coord + 9];  /*p[0]ָ���·�����*/
				p[1] = &b[72 + j];  /*p[1]ָ��ǰ�����һ������*/
				count = 1;  /*��������Ϊ1*/

				/*��p[0]ָ���������ɫ��Ȼһ�£���p[0]λ�ò���p[1]֮�󣨼�û�г�����ǰ�У����������������p[0]��ǰ�ƶ�*/
				while (p[0]->color == b[coord].color && p[0] <= p[1]) {
					count++;
					p[0] = p[0] + 9;
				}

				/*��ɨ����ɣ���������С��5���򽫷������������Ķ���������ϱ��*/
				if (count >= 5) {
					for (int k = 0; k < count; k++)
						b[coord + k * 9].mark = true;
					i = i + count;  /*i����count������ѭ������*/
				}
			}

			count = 0;  /*ÿ��ɨ����ɺ����������Ϊ��*/
		}
	}

	for (int i = 0; i < 9; i++) {
		const int j_lim = (i <= 4) ? (5 + i) : (13 - i);  /*��������ȡÿһб�е����Ӹ���*/

		for (int j = 0; j < j_lim; j++) {
			const int coord = (i <= 4) ? ((4 - i) + j * 10) : ((i - 4) * 9 + j * 10);  /*��������ȡһά����*/

			/*����ǰλ�������Ӳ��ǰ�ɫ������λ���������ӣ��������·�������ɫҲ����ͬ��ɫ���������һ���ж�*/
			if (b[coord].color == b[coord + 10].color && b[coord].color != COLOR_WHITE) {
				p[0] = &b[coord + 10];  /*p[0]ָ�����·�����*/
				p[1] = &b[(i <= 4) ? ((5 + i) * 9 - 1) : (84 - i)];  /*p[1]ָ��ǰб�����һ������*/
				count = 1;  /*��������Ϊ1*/

				/*��p[0]ָ���������ɫ��Ȼһ�£���p[0]λ�ò���p[1]֮�󣨼�û�г�����ǰб�У����������������p[0]��ǰ�ƶ�*/
				while (p[0]->color == b[coord].color && p[0] <= p[1]) {
					count++;
					p[0] = p[0] + 10;
				}

				/*��ɨ����ɣ���������С��5���򽫷������������Ķ���������ϱ��*/
				if (count >= 5) {
					for (int k = 0; k < count; k++)
						b[coord + k * 10].mark = true;
					j = j + count;  /*j����count������ѭ������*/
				}
			}

			count = 0;  /*ÿ��ɨ����ɺ����������Ϊ��*/
		}
	}

	for (int i = 0; i < 9; i++) {
		const int j_lim = (i <= 4) ? (5 + i) : (13 - i);  /*��������ȡÿһб�е����Ӹ���*/

		for (int j = 0; j < j_lim; j++) {
			const int coord = (i <= 4) ? ((4 + i) + j * 8) : ((i - 3) * 9 - 1 + j * 8);  /*��������ȡһά����*/

			/*����ǰλ�������Ӳ��ǰ�ɫ������λ���������ӣ��������·�������ɫҲ����ͬ��ɫ���������һ���ж�*/
			if (b[coord].color == b[coord + 8].color && b[coord].color != COLOR_WHITE) {
				p[0] = &b[coord + 8];  /*p[0]ָ�����·�����*/
				p[1] = &b[(i <= 4) ? ((i + 4) * 9) : (68 + i)];  /*p[1]ָ��ǰб�����һ������*/
				count = 1;  /*��������Ϊ1*/

				/*��p[0]ָ���������ɫ��Ȼһ�£���p[0]λ�ò���p[1]֮�󣨼�û�г�����ǰб�У����������������p[0]��ǰ�ƶ�*/
				while (p[0]->color == b[coord].color && p[0] <= p[1]) {
					count++;
					p[0] = p[0] + 8;
				}

				/*��ɨ����ɣ���������С��5���򽫷������������Ķ���������ϱ��*/
				if (count >= 5) {
					for (int k = 0; k < count; k++)
						b[coord + k * 8].mark = true;
					j = j + count;  /*j����count������ѭ������*/
				}
			}

			count = 0;  /*ÿ��ɨ����ɺ����������Ϊ��*/
		}
	}
}

/***************************************************************************
  �������ƣ�get_mark_num
  ��    �ܣ�ȡ����ǵ����Ӹ���
  ���������const ball b[]����Ϸ�ڲ��Ķ������飨ֻ����
  �� �� ֵ��int������ǵ����Ӹ���
  ˵    ������
***************************************************************************/
int player::get_mark_num(const ball b[])
{
	int ret = 0;  /*����ֵ*/

	for (int i = 0; i < 81; i++) {
		if (b[i].mark)
			ret++;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�if_end
  ��    �ܣ��ж���Ϸ�Ƿ����
  ���������const ball b[]����Ϸ�ڲ��Ķ������飨ֻ����
  �� �� ֵ��bool����Ϸ�Ƿ����
  ˵    �����������������������Ƿ�ռ�����жϣ�ռ�����ܷ������Լ���������ѽ�����������ʵ��
***************************************************************************/
bool player::if_end(const ball b[])
{
	int count = 0;  /*������*/

	for (int i = 0; i < 81; i++) {
		if (ball::if_ball[i])  /*����ǰλ�������ӣ������������*/
			count++;
	}

	if (count == 81)  /*��������81�������棻���򷵻ؼ�*/
		return true;
	else
		return false;
}

/***************************************************************************
  �������ƣ�clear
  ��    �ܣ���������
  ���������ball b[]����Ϸ�ڲ��Ķ�������
            bool* if_sound���Ƿ�������
  �� �� ֵ����
  ˵    �������������������ӵ�ͬʱ���з������ۼ�
***************************************************************************/
void player::clear(ball b[], bool* if_sound)
{
	int count = 0;  /*�����������Ӹ���*/

	if (*if_sound)  /*������Ҫ��������*/
		Beep(SOUND_HDO, 200);

	for (int i = 0; i < 81; i++) {
		if (b[i].mark && if_show) {  /*�������Ч�������ڱ���ǵ�����λ�ô�ӡ���ӱ߽�*/
			const int J = i % 9;
			const int I = (i - J) / 9;
			cct_gotoxy(10 * J, 5 * I);
			print_blockborder(i, COLOR_HBLACK, COLOR_WHITE);
			Sleep(10);  /*��ʱ�������ٶ�*/
		}
	}

	Sleep(500);  /*��ʱ�������ٶ�*/

	for (int i = 0; i < 81; i++) {
		if (b[i].mark) {
			ball::if_ball[i] = false;  /*��ǰλ�õı�־��Ϊ��*/

			const int J = i % 9;        /*��һά����ת��Ϊ����*/
			const int I = (i - J) / 9;  /*��һά����ת��Ϊ����*/
			cct_gotoxy(10 * J, 5 * I);
			print_blockborder(i, COLOR_WHITE, COLOR_BLACK);  /*��ԭ�и��ӱ߽�����*/

			b[i].color = COLOR_WHITE;  /*��ǰλ����������ɫ��Ϊ��ɫ*/
			b[i].print();  /*�ڵ�ǰλ���ϴ�ӡ��ɫ����Ӫ�����Ч��*/

			b[i].x = -1;  /*��ǰλ�������ӱ�������������Ϊ-1*/
			b[i].y = -1;  /*��ǰλ�������ӱ�������������Ϊ-1*/
			count++;
			b[i].mark = false;  /*�����ȥ��*/
			Sleep(10);  /*��ʱ�������ٶ�*/
		}
	}

	score = score + count * 2;  /*�������������Ӹ����Ʒ�*/
}

/***************************************************************************
  �������ƣ�if_block
  ��    �ܣ��ж����λ���Ƿ���ĳһ������
  ���������ball b[]����Ϸ�ڲ��Ķ�������
            const int X�����λ�ú����ֻ꣨����
			const int Y�����λ�������ֻ꣨����
  �� �� ֵ��int���������һ������
  ˵    ������
***************************************************************************/
int player::if_block(ball b[], const int X, const int Y)
{
	int ret = -1;  /*����ֵ������Ϊ-1*/
	int loop = 1;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (X >= j * 10 + 2 && X <= j * 10 + 9 && Y >= i * 5 + 1 && Y <= i * 5 + 4) {
				ret = 9 * i + j;
				b[ret].spmark = true;  /*����λ���ϵĶ��������ر��ǣ���������������ӱ߽�*/
				loop = 0;  /*ѭ�������Ϊ��*/
				break;
			}
		}

		if (!loop)  /*��ȷ����λ�ã���ѭ������������ѭ������*/
			break;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�print_blockborder
  ��    �ܣ���ӡһ�����ӵı߽�
  ���������const int coord�����ӵ�һά���ֻ꣨����
			const int bg_color������ɫ��ֻ����
			const int fg_color��ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void player::print_blockborder(const int coord, const int bg_color, const int fg_color)
{
	const int J = coord % 9;        /*��һά����ת��Ϊ����*/
	const int I = (coord - J) / 9;  /*��һά����ת��Ϊ����*/
	int X, Y;
	cct_getxy(X, Y);  /*ȡ��ǰ���ĺ�������*/

	/*����λ�ô�ӡÿ�����ӱ߽�����Ͻ��Ʊ��*/
	if (I == 0 && J == 0)
		cct_showstr(X, Y, "��", bg_color, fg_color);  /*���ϽǸ���*/
	else if (I == 0 && J != 0)
		cct_showstr(X, Y, "��", bg_color, fg_color);  /*�����Ͻ��⣬��һ�еĸ���*/
	else if (I != 0 && J == 0)
		cct_showstr(X, Y, "��", bg_color, fg_color);  /*�����Ͻ��⣬��һ�еĸ���*/
	else
		cct_showstr(X, Y, "��", bg_color, fg_color);  /*�����������������*/

	/*����λ�ô�ӡÿ�����ӱ߽�����Ͻ��Ʊ��*/
	if (I == 0 && J == 8)
		cct_showstr(X + 10, Y, "��", bg_color, fg_color);  /*���ϽǸ���*/
	else if (I == 0 && J != 8)
		cct_showstr(X + 10, Y, "��", bg_color, fg_color);  /*�����Ͻ��⣬��һ�еĸ���*/
	else if (I != 0 && J == 8)
		cct_showstr(X + 10, Y, "��", bg_color, fg_color);  /*�����Ͻ��⣬���һ�еĸ���*/
	else
		cct_showstr(X + 10, Y, "��", bg_color, fg_color);  /*�����������������*/

	/*����λ�ô�ӡÿ�����ӱ߽�����½��Ʊ��*/
	if (I == 8 && J == 0)
		cct_showstr(X, Y + 5, "��", bg_color, fg_color);  /*���½Ǹ���*/
	else if (I == 8 && J != 0)
		cct_showstr(X, Y + 5, "��", bg_color, fg_color);  /*�����½��⣬���һ�еĸ���*/
	else if (I != 8 && J == 0)
		cct_showstr(X, Y + 5, "��", bg_color, fg_color);  /*�����½��⣬��һ�еĸ���*/
	else
		cct_showstr(X, Y + 5, "��", bg_color, fg_color);  /*�����������������*/

	/*����λ�ô�ӡÿ�����ӱ߽�����½��Ʊ��*/
	if (I == 8 && J == 8)
		cct_showstr(X + 10, Y + 5, "��", bg_color, fg_color);  /*���½Ǹ���*/
	else if (I == 8 && J != 8)
		cct_showstr(X + 10, Y + 5, "��", bg_color, fg_color);  /*�����½��⣬���һ�еĸ���*/
	else if (I != 8 && J == 8)
		cct_showstr(X + 10, Y + 5, "��", bg_color, fg_color);  /*�����½��⣬���һ�еĸ���*/
	else
		cct_showstr(X + 10, Y + 5, "��", bg_color, fg_color);  /*�����������������*/

	/*��ӡÿ�����ӱ߽�������Ʊ��*/
	for (int i = 0; i < 4; i++) {
		cct_showstr(X + 2 * (i + 1), Y, "��", bg_color, fg_color);
		cct_showstr(X + 2 * (i + 1), Y + 5, "��", bg_color, fg_color);
		cct_showstr(X, Y + i + 1, "��", bg_color, fg_color);
		cct_showstr(X + 10, Y + i + 1, "��", bg_color, fg_color);
	}
}

/***************************************************************************
  �������ƣ�print_balls
  ��    �ܣ���ӡ��ǰ����������
  ���������ball b[]����Ϸ�ڲ��Ķ�������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void player::print_balls(ball b[])
{
	for (int i = 0; i < 81; i++) {
		if (ball::if_ball[i])  /*����ǰλ�������ӣ����ӡ*/
			b[i].print();
		else {  /*����ǰλ�������ӣ����ӡ�հ�����*/
			const int J = i % 9;        /*��һά����ת��Ϊ����*/
			const int I = (i - J) / 9;  /*��һά����ת��Ϊ����*/
			const int X = J * 10 + 2;   /*ȡ��ӡ�������ϽǺ�����*/
			const int Y = I * 5 + 1;    /*ȡ��ӡ�������Ͻ�������*/

			for (int j = 0; j < 4; j++)
				cct_showstr(X, Y + j, "        ", COLOR_WHITE);
		}
	}
}

/***************************************************************************
  �������ƣ�blocks_selective_default
  ��    �ܣ�ѡ���Ե�����ĳһ���ӵı߽�
  ���������ball b[]����Ϸ�ڲ��Ķ�������
            const int coord����굱ǰ���ڸ��ӵ�һά���ֻ꣨����
			const int bg_color������ɫ��ֻ����
			const int fg_color��ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void player::blocks_selective_default(ball b[], const int coord, const int bg_color, const int fg_color)
{
	for (int i = 0; i < 81; i++) {
		const int J = i % 9;        /*��һά����ת��Ϊ����*/
		const int I = (i - J) / 9;  /*��һά����ת��Ϊ����*/

		/*����ǰԪ�ر������ǣ��Ҳ�����һ�����ø���ɫ���ӦԪ�أ�����в���*/
		if (b[i].spmark && i != coord) {
			cct_gotoxy(10 * J, 5 * I);
			print_blockborder(i, bg_color, fg_color);
			b[i].spmark = false;  /*ȡ��������*/
		}
	}
}

/***************************************************************************
  �������ƣ�blocks_selective_default
  ��    �ܣ�ѡ���Եش�ӡĳһ���ӵı߽�
  ���������ball b[]����Ϸ�ڲ��Ķ�������
			const int coord�����ӵ�һά���ֻ꣨����
			const int bg_color������ɫ��ֻ����
			const int fg_color��ǰ��ɫ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void player::blocks_selective_activate(ball b[], const int coord, const int bg_color, const int fg_color)
{
	const int J = coord % 9;        /*��һά����ת��Ϊ����*/
	const int I = (coord - J) / 9;  /*��һά����ת��Ϊ����*/

	/*��coord��Ϊ�����������ĳһ�������ڣ�����ִ�в���*/
	if (coord >= 0) {
		cct_gotoxy(10 * J, 5 * I);
		print_blockborder(coord, bg_color, fg_color);
	}
}

/***************************************************************************
  �������ƣ�if_button
  ��    �ܣ��ж����λ���Ƿ���ĳһ������
  ���������const int X�����λ�ú����ֻ꣨����
			const int Y�����λ�������ֻ꣨����
  �� �� ֵ��int���������һ������
  ˵    ������
***************************************************************************/
int player::if_button(const int X, const int Y)
{
	int ret = 0;  /*����ֵ*/
	bool p[BUTTON_NUM];
	for (int i = 0; i < BUTTON_NUM; i++)
		p[i] = false;

	if (X >= OPTIONS_COORD_X && X <= OPTIONS_COORD_X + 9 && Y >= OPTIONS_COORD_Y && Y <= OPTIONS_COORD_Y + 2)  /*�ж��Ƿ��ڡ����á�����*/
		p[0] = true;
	if (X >= SAVE_COORD_X && X <= SAVE_COORD_X + 9 && Y >= SAVE_COORD_Y && Y <= SAVE_COORD_Y + 2)              /*�ж��Ƿ��ڡ����桱����*/
		p[1] = true;
	if (X >= DELETE_COORD_X && X <= DELETE_COORD_X + 9 && Y >= DELETE_COORD_Y && Y <= DELETE_COORD_Y + 2)      /*�ж��Ƿ��ڡ�ɾ��������*/
		p[2] = true;
	if (X >= QUIT_COORD_X && X <= QUIT_COORD_X + 9 && Y >= QUIT_COORD_Y && Y <= QUIT_COORD_Y + 2)              /*�ж��Ƿ��ڡ��˳�������*/
		p[3] = true;

	/*������λ�õ��������������ȡ��Ӧ����ֵ��������*/
	for (int i = 0; i < BUTTON_NUM; i++) {
		if (p[i]) {
			ret = i + 1;
			break;
		}
	}

	return ret;
}

/***************************************************************************
  �������ƣ�buttons_selective_default
  ��    �ܣ�ѡ���Ե�Ϊĳһ����ȡ������
  ���������const int selection������ѡ��ֻ����
  �� �� ֵ����
  ˵    ������ѡ��ΪDEFAULT_ALLʱ��ͨ���ݹ����ȡ�����а����ĸ���
***************************************************************************/
void player::buttons_selective_default(const int selection)
{
	switch (selection) {
	case 1:
		button_options.act(DEFAULT);  /*�����á���ȡ������*/
		break;
	case 2:
		button_save.act(DEFAULT);     /*�����桱��ȡ������*/
		break;
	case 3:
		button_delete.act(DEFAULT);   /*��ɾ������ȡ������*/
		break;
	case 4:
		button_quit.act(DEFAULT);     /*���˳�����ȡ������*/
		break;
	case DEFAULT_ALL:
		for (int i = 0; i < BUTTON_NUM; i++)  /*���а���ȡ������*/
			buttons_selective_default(i + 1);
		break;
	}
}

/***************************************************************************
  �������ƣ�buttons_selective_activate
  ��    �ܣ�ѡ���Ե�Ϊĳһ�������ø���
  ���������const int selection������ѡ��ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void player::buttons_selective_activate(const int selection)
{
	switch (selection) {
	case 1:
		button_options.act(ACTIVATE);  /*�����á������ø���*/
		break;
	case 2:
		button_save.act(ACTIVATE);     /*�����桱�����ø���*/
		break;
	case 3:
		button_delete.act(ACTIVATE);   /*��ɾ���������ø���*/
		break;
	case 4:
		button_quit.act(ACTIVATE);     /*���˳��������ø���*/
		break;
	}
}

/***************************************************************************
  �������ƣ�control
  ��    �ܣ��ü�������Ϸ����ڽ��в���
  ���������ball b[]����Ϸ�ڲ��Ķ�������
            bool* if_sound���Ƿ�������
  �� �� ֵ��int�����еĲ���
  ˵    ������
***************************************************************************/
int player::control(ball b[], bool* if_sound)
{
	int X = 0, Y = 0;  /*�������꣬��ʼ��Ϊ��*/
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int result = 0;  /*�����ķ���ֵ*/

	cct_enable_mouse();  /*�������*/

	while (loop) {
		if (if_end(b)) {  /*����Ϸ��������ȡ����ֵ������ѭ��*/
			result = GAME_RET_FAILURE;
			break;
		}

		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);  /*�����/����*/
		buttons_selective_default(DEFAULT_ALL);  /*ȡ����Ϸ������а����ĸ���*/

		int RET[2];
		RET[0] = if_block(b, X, Y);  /*�жϴ�ʱ����λ���Ƿ���ĳ��������*/
		RET[1] = if_button(X, Y);    /*�жϴ�ʱ����λ���Ƿ���ĳ��������*/
		buttons_selective_activate(RET[1]);  /*�������ĳ�������У�����Ӧ�İ������ø���*/
		const int J = RET[0] % 9;        /*��һά����ת��Ϊ����*/
		const int I = (RET[0] - J) / 9;  /*��һά����ת��Ϊ����*/

		switch (if_select) {
		case true:
			/*����ѡ����һ�����ӣ�����ѡ��λ�ô�ӡһ����ɫ�ı߽�*/
			cct_gotoxy(10 * select_x, 5 * select_y);
			print_blockborder(9 * select_y + select_x, COLOR_HPINK, COLOR_WHITE);

			/*��������ڵĸ��Ӳ���ѡ����λ�ã����ڵ�ǰλ�ô�ӡһ��ǳ��ɫ�ı߽�*/
			if (select_x != J || select_y != I) {
				blocks_selective_default(b, RET[0], COLOR_WHITE, COLOR_BLACK);
				blocks_selective_activate(b, RET[0], COLOR_HCYAN, COLOR_WHITE);
			}
			break;
		case false:
			/*��δѡ�����ӣ����ڵ�ǰλ�ô�ӡһ����ɫ�ı߽�*/
			blocks_selective_default(b, RET[0], COLOR_WHITE, COLOR_BLACK);
			blocks_selective_activate(b, RET[0], COLOR_HPINK, COLOR_WHITE);
			break;
		}

		update_score();  /*���µ÷�*/
		update_color();  /*������ɫ*/

		switch (ret) {
		/*1����������¼�*/
		case CCT_MOUSE_EVENT:
			switch (maction) {
			/*1.1���������*/
			case MOUSE_LEFT_BUTTON_CLICK:
				switch (if_select) {
				case true:
					/*��ѡ����һ�����ӣ��������һ���յĸ����ϣ��������һ������*/
					if (RET[0] >= 0 && !ball::if_ball[RET[0]]) {
						if (*if_sound)  /*������Ҫ��������*/
							Beep(SOUND_SO, 100);

						move(b, select_x, select_y, J, I);  /*�ƶ�����*/
						scan(b);  /*ɨ�������������*/
						cct_gotoxy(10 * select_x, 5 * select_y);  /*��ԭ��ѡ��λ�õ���ɫ���ӱ߽�����*/
						print_blockborder(9 * select_y + select_x, COLOR_WHITE, COLOR_BLACK);

						if (get_mark_num(b)) {  /*�������ӱ���ǣ������״̬���������*/
							update_state(STATE_CLEAR);
							clear(b, if_sound);
						}

						else {  /*��û�����ӱ���ǣ�������3���µ�����*/
							summon(b, 3, if_sound);
							scan(b);  /*��ɨ��һ�Σ��Է������ɵ�����������������*/

							if (get_mark_num(b)) {  /*����ɨ��һ����Ȼ�����ӱ���ǣ������״̬���������*/
								update_state(STATE_CLEAR);
								clear(b, if_sound);
							}
						}
						
						/*ԭ��ѡ��λ�õ���Ϣ��ѡ��״̬������ΪĬ��ֵ*/
						select_x = -1;
						select_y = -1;
						if_select = false;
					}
					break;
				case false:
					/*��δѡ������*/
					if (ball::if_ball[RET[0]] && !RET[1]) {  /*�����һ�������ӵ�λ���ϣ���洢ѡ��λ�õ���Ϣ������ѡ��״̬*/
						select_x = J;
						select_y = I;
						if_select = true;

						if (*if_sound)  /*������Ҫ��������*/
							Beep(SOUND_DO, 100);
					}

					else if (!ball::if_ball[RET[0]] && !RET[1]) {
						update_state(STATE_VACANT);

						if (*if_sound)  /*������Ҫ��������*/
							Beep(SOUND_LSI, 200);
					}
					break;
				}

				if (RET[1] && *if_sound)  /*����ĳ�������ϰ���������������Ҫ��������*/
					Beep(SOUND_MI, 100);

				/*�������ĳһ�������ϣ�����ݰ�������״̬��ȡ����ֵ������ѭ��*/
				switch (RET[1]) {
				case 1:  /*�����á���*/
					update_state(STATE_OPTIONS);
					result = GAME_RET_OPTIONS, loop = 0;
					break;
				case 2:  /*�����桱��*/
					update_state(STATE_SAVE);
					result = GAME_RET_SAVE, loop = 0;
					break;
				case 3:  /*��ɾ������*/
					update_state(STATE_DELETE);
					result = GAME_RET_DELETE, loop = 0;
					break;
				case 4:  /*���˳�����*/
					update_state(STATE_QUIT);
					result = GAME_RET_QUIT, loop = 0;
					break;
				}
				break;
			/*1.2�������Ҽ�*/
			case MOUSE_RIGHT_BUTTON_CLICK:
				if (if_select) {  /*��ѡ����һ�����ӣ���ԭ��ѡ��λ�õ���ɫ���ӱ߽�����*/
					cct_gotoxy(10 * select_x, 5 * select_y);
					print_blockborder(9 * select_y + select_x, COLOR_WHITE, COLOR_BLACK);

					/*ԭ��ѡ��λ�õ���Ϣ��ѡ��״̬������ΪĬ��ֵ*/
					select_x = -1;
					select_y = -1;
					if_select = false;

					/*����״̬Ϊȡ��ѡ��*/
					update_state(STATE_CANCEL);

					if (*if_sound)  /*������Ҫ��������*/
						Beep(SOUND_LSI, 100);
				}
				break;
			/*1.3������ƶ�*/
			case MOUSE_ONLY_MOVED:
				switch (if_select) {
				case true:
					update_state(STATE_MOVING);  /*����ѡ��һ�����ӣ������״̬Ϊѡ��λ��*/
					break;
				case false:
					update_state(STATE_SELECTING);  /*��δѡ�����ӣ������״̬Ϊѡ��Ŀ��*/
					break;
				}
			}
			break;
		/*2�����ؼ����¼�*/
		case CCT_KEYBOARD_EVENT:
			/*���ݼ��벥������������״̬��ȡ����ֵ������ѭ��*/
			switch (keycode1) {
			case 'O':  /*�����á���*/
			case 'o':
				if (*if_sound)
					Beep(SOUND_MI, 100);
				update_state(STATE_OPTIONS);
				result = GAME_RET_OPTIONS, loop = 0;
				break;
			case 'S':  /*�����桱��*/
			case 's':
				if (*if_sound)
					Beep(SOUND_MI, 100);
				update_state(STATE_SAVE);
				result = GAME_RET_SAVE, loop = 0;
				break;
			case 'D':  /*��ɾ������*/
			case 'd':
				if (*if_sound)
					Beep(SOUND_MI, 100);
				update_state(STATE_DELETE);
				result = GAME_RET_DELETE, loop = 0;
				break;
			case 'Q':  /*���˳�����*/
			case 'q':
				if (*if_sound)
					Beep(SOUND_MI, 100);
				update_state(STATE_QUIT);
				result = GAME_RET_QUIT, loop = 0;
				break;
			}
		}
	}

	cct_disable_mouse();	//�������
	return result;
}