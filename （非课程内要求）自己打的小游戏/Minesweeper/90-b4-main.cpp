/*2151294 信11 马威*/
#include<iostream>
#include"cmd_console_tools.h"
#include"90-b4.h"
#include"interface-cover.h"
#include"interface-inputbox.h"
#include"interface-mailbox.h"
#include"interface-optionsbox.h"
using namespace std;

/*游戏内对话框对象*/
game_mailbox GAME_MAILBOX;

/*标题画面对象*/
cover COVER;

/*输入框对象*/
inputbox INPUTBOX;

/*设置对话框对象*/
optionsbox OPTIONSBOX;

int main()
{
	srand((unsigned int)(time(0)));     /*生成伪随机数的种子*/
	cct_setcursor(CURSOR_INVISIBLE);    /*隐藏光标*/
	int loop[2] = { 1,1 };
	bool if_sound = true, * ps = &if_sound;
	int fontsize = 28, * pf = &fontsize;
	COVER.print();

	while (loop[0]) {
		loop[1] = 1;

		int DIFFICULTY = 0;

		switch (COVER.control()) {  /*设置游戏难度*/
		case COVER_EASY:
			DIFFICULTY = EASY;
			break;
		case COVER_MEDIUM:
			DIFFICULTY = MEDIUM;
			break;
		case COVER_HARD:
			DIFFICULTY = HARD;
			break;
		case COVER_DIY:
			DIFFICULTY = DIY;
			break;
		case COVER_OPTIONS:
			OPTIONSBOX.print("声音：    字体大小：");

			switch (OPTIONSBOX.control(ps, pf)) {
			case OPBX_RET_SURE:
				cct_setfontsize("新宋体", *pf, *pf);
				optionsbox_erase();
				continue;
				break;
			case OPBX_RET_CANCEL:
				optionsbox_erase();
				continue;
				break;
			}

			break;
		case COVER_QUIT:
			loop[0] = 0, loop[1] = 0;
			break;
		}

		int LINE = 0, * pl = &LINE;
		int ROW = 0, * pr = &ROW;
		int BOMB_NUM = 0, * pb = &BOMB_NUM;
		/*设置行数、列数、地雷数

			 以下是Minesweeper Classic的数据：
			 难度    行数    列数     地雷数

			 初级    8       8        10

			 中级    16      16       40

			 高级    30      16       99

			 自定义  30      30       行数*列数的80%

			*/
		switch (DIFFICULTY) {
		case DIY:
			INPUTBOX.print("行数：    列数：    地雷数：");

			switch (INPUTBOX.control(pl, pr, pb)) {
			case IPBX_RET_SURE:
				cct_setfontsize("新宋体", *pf, *pf);
				break;
			case IPBX_RET_CANCEL:
				LINE = 0, ROW = 0, BOMB_NUM = 0;
				inputbox_erase();
				continue;
				break;
			}

			break;
		default:
			cct_setfontsize("新宋体", *pf, *pf);  /*设置窗口字体大小*/
			LINE = set_info(DIFFICULTY, INFO_LINE);
			ROW = set_info(DIFFICULTY, INFO_ROW);
			BOMB_NUM = set_info(DIFFICULTY, INFO_BOMB_NUM);
			break;
		}
		bool if_initialized = false, * pi = &if_initialized;

		GAME_MAILBOX.set_button_coord(LINE, ROW);
		matrix MATRIX[LINE_MAX * ROW_MAX];  /*定义所需数组，a[Y_MAX][X_MAX]是表示各个格子的字符数组*/

		cct_setconsoleborder(6 * ROW + 4, 3 * LINE + 15);

		while (loop[1]) {
			* pi = false;

			gameboard_print(LINE, ROW);
			for (int i = 0; i < LINE * ROW; i++) {
				const int J = i % ROW;               /*将一维坐标转换为列标*/
				const int I = (i - J) / ROW;  /*将一维坐标转换为行标*/
				cct_gotoxy(6 * J + 2, 3 * I + 12);
				block_print(NUM_SPACE, COLOR_WHITE, COLOR_BLACK);
			}
			print_info(ROW, BOMB_NUM);

			for (int i = 0; i < LINE * ROW; i++) {
				MATRIX[i].mark = false;
				MATRIX[i].coord_mark = false;
				MATRIX[i].if_turned = false;
				MATRIX[i].if_flag = false;
			}

			int ret[2];
			ret[0] = control(MATRIX, LINE, ROW, BOMB_NUM, pi);

			switch (ret[0]) {
			case FAILURE:
				Sleep(1000);
				if (*ps)
					cout << '\007';
				GAME_MAILBOX.print(BUTTON_TWO, LINE, ROW, "游戏失败！", "  是否开始一局新游戏？");
				ret[1] = GAME_MAILBOX.control(LINE, ROW);

				switch (ret[1]) {
				case GMMB_RET_YES:
					continue;
					break;
				case GMMB_RET_NO:
					loop[1] = 0;
					COVER.print();
					break;
				}

				break;
			case VICTORY:
				Sleep(1000);
				if (*ps)
					cout << '\007';
				GAME_MAILBOX.print(BUTTON_ONE, LINE, ROW, "游戏胜利！");
				GAME_MAILBOX.control(LINE, ROW);
				loop[1] = 0;
				COVER.print();
				break;
			case NEW:
				continue;
				break;
			case QUIT:
				loop[1] = 0;
				COVER.print();
				break;
			}
		}
	}
	
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	cct_setfontsize("新宋体", 28, 28);
	cct_setconsoleborder(83, 34);
	return 0;
}

/****************************************
待解决：
    1、自定义地雷数的三位数输入
****************************************/