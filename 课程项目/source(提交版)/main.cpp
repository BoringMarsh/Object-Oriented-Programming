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
	srand((unsigned int)(time(0)));     /*生成伪随机数的种子*/
	cct_setcolor();                     /*重设颜色*/
	cct_setcursor(CURSOR_INVISIBLE);    /*隐藏光标*/

	game_messagebox GameMessagebox;    /*游戏内对话框*/
	cover_messagebox CoverMessagebox;  /*标题画面对话框*/
	file_tools FileManager;  /*文档管理对象*/
	cover TitleScreen;       /*标题画面对象*/
	optionsbox OptionsBox;   /*设置对话框*/
	ball Ball[81];  /*游戏内部的对象数组*/
	player Client;  /*用户对象*/

	bool if_game = false;      /*是否进行游戏*/
	bool if_new = false;       /*是否开始新游戏*/
	bool if_colorball = true;  /*是否继续运行整个游戏程序*/
	bool if_sound = true, * ps = &if_sound;  /*是否有声音及指向其的指针*/
	int fontsize = 28, * pf = &fontsize;     /*字体大小及指向其的指针*/
	int ret = 0, num = 0;  /*标题画面对话框操作函数返回值、文件栏位*/
	cct_setfontsize("新宋体", fontsize);  /*设置字体大小*/
	TitleScreen.print();  /*显示标题画面*/

	while (if_colorball) {  /*若为真，则游戏不退出*/
		switch (TitleScreen.control(ps)) {  /*取标题画面操作*/

		/*1、按下“新游戏”键*/
		case COVER_RET_NEW:
			if_game = true;  /*标志着进行游戏*/
			if_new = true;   /*标志着进行新游戏*/
			break;

		/*2、按下“载入游戏”键*/
		case COVER_RET_LOAD:
			if_game = true;  /*标志着进行游戏*/

			CoverMessagebox.print(BUTTON_FIVE, "载入哪个位置的存档？");  /*打印对话框*/
			ret = CoverMessagebox.control();  /*取对话框操作*/
			num = ret - CVMB_RET_ONE + 1;     /*取文件栏位*/

			if (ret >= CVMB_RET_ONE && ret <= CVMB_RET_FOUR) {  /*若按了“1”到“4”键*/
				if (FileManager.if_file_deleted(num)) {  /*若选定的栏位存档为空，则告知用户存档为空*/
					char prompt[] = "位置 上的存档为空";
					prompt[4] = num + '0';
					CoverMessagebox.print(BUTTON_ONE, prompt);
					CoverMessagebox.control();
					CoverMessagebox.erase(TitleScreen);
					continue;
				}

				else  /*若选定栏位存档不为空，则读取存档*/
					FileManager.file_load(Client, Ball, num);
			}

			else {  /*若按了“取消”键，则仅擦除对话框*/
				CoverMessagebox.erase(TitleScreen);
				continue;
			}
			break;

		/*3、按下“设置”键*/
		case COVER_RET_OPTIONS:
			OptionsBox.print("闪烁：    清除效果：", "声音：    字体大小：");  /*打印设置对话框*/

			switch (OptionsBox.control(ps, pf)) {  /*取设置对话框操作*/
			case OPBX_RET_SURE:
				cct_setfontsize("新宋体", *pf);  /*字体大小无法在control函数内直接设置，若按下“确定”键，则改变字体大小*/
				OptionsBox.erase(TitleScreen);   /*擦除设置对话框*/
				continue;
				break;
			case OPBX_RET_CANCEL:
				OptionsBox.erase(TitleScreen);   /*若按下“取消”键，则仅擦除设置对话框*/
				continue;
				break;
			}
			
			break;

		/*4、按下“帮助”键*/
		case COVER_RET_HELP:
			CoverMessagebox.print(BUTTON_ONE, "每次移一颗珠子到空位上", "四个方向至少五个同色便消除", "不消除则有三颗珠子生成");  /*打印对话框*/
			CoverMessagebox.control();  /*取操作，使得用户可以完成点击“确定”键的动作*/
			CoverMessagebox.erase(TitleScreen);  /*擦除对话框*/
			continue;
			break;

		/*5、按下“关于”键*/
		case COVER_RET_ABOUT:
			CoverMessagebox.print(BUTTON_ONE, "关于colorball v1.0.0:", "  开发者：马威", "  学号：2151294");  /*打印对话框*/
			CoverMessagebox.control();  /*取操作，使得用户可以完成点击“确定”键的动作*/
			CoverMessagebox.erase(TitleScreen);  /*擦除对话框*/
			continue;
			break;

		/*6、按下“退出”键*/
		case COVER_RET_EXIT:
			CoverMessagebox.print(BUTTON_TWO, "您确定要退出colorball?");  /*打印对话框*/

			switch (CoverMessagebox.control()) {  /*取对话框操作*/
			case CVMB_RET_YES:
				if_colorball = false;  /*若按“是”键，则标志置为假，之后跳出循环，程序结束*/
				break;
			case CVMB_RET_NO:
				CoverMessagebox.erase(TitleScreen);  /*若按“否”键，则仅擦除对话框*/
				continue;
				break;
			}
			break;
		}

		if (if_game) {  /*若要进行游戏，进行准备工作*/
			cct_cls();  /*清屏*/
			cct_setconsoleborder(112, 48, 112, 48);  /*设置窗口及缓冲区大小*/
			cct_setfontsize("新宋体", fontsize);     /*设置字体大小*/
			print_chessboard();  /*打印白色棋盘*/

			if (if_new)
				Client.summon(Ball, 7, ps);  /*若进行新游戏，则直接随机生成7个珠子*/
			else
				Client.print_balls(Ball);  /*若不进行新的游戏，则打印已有的所有珠子*/

			Client.update_score();  /*更新得分*/
			Client.update_color();  /*更新颜色*/
			Client.update_state(STATE_SELECTING);  /*更新状态*/
		}

		while (if_game) {  /*若为真，则游戏进行，不退回标题画面*/
			int RET;  /*游戏内对话框操作函数返回值*/

			switch (Client.control(Ball, ps)) {  /*取用户操作*/

			/*1、按下“设置”键*/
			case GAME_RET_OPTIONS:
				GameMessagebox.print(BUTTON_SWITCH, "闪烁：      清除效果：");  /*打印对话框*/

				while (1) {
					RET = GameMessagebox.control();  /*取对话框操作*/

					if (RET >= GMMB_RET_BLINK_OFF && RET <= GMMB_RET_SHOW_ON)  /*若按下了滑动条上的按键，则进行对应的设置*/
						GameMessagebox.options(RET);
					else {  /*若按下“确定”键，则仅擦除对话框*/
						GameMessagebox.erase(Client, Ball);
						cct_enable_mouse();  /*从control函数出来时禁用了鼠标，需重新启用鼠标*/
						break;
					}
				}
				break;

			/*2、按下“保存”键*/
			case GAME_RET_SAVE:
				GameMessagebox.print(BUTTON_FIVE, "保存到哪个位置？");  /*打印对话框*/
				RET = GameMessagebox.control();  /*取对话框操作*/

				if (RET >= GMMB_RET_ONE && RET <= GMMB_RET_FOUR) {  /*若按了“1”到“4”键，则保存到对应栏位，并告知用户已保存*/
					FileManager.file_save(Client, Ball, RET - GMMB_RET_ONE + 1);

					char prompt[] = "文件已保存到位置 ";
					prompt[16] = RET - GMMB_RET_ONE + 1 + '0';
					GameMessagebox.print(BUTTON_ONE, prompt);
					GameMessagebox.control();
					GameMessagebox.erase(Client, Ball);
				}
				else  /*若按了“取消”键，则仅擦除对话框*/
					GameMessagebox.erase(Client, Ball);
				break;

			/*3、按下“删除”键*/
			case GAME_RET_DELETE:
				GameMessagebox.print(BUTTON_FIVE, "删除哪个位置的存档？");  /*打印对话框*/
				RET = GameMessagebox.control();  /*取对话框操作*/

				if (RET >= GMMB_RET_ONE && RET <= GMMB_RET_FOUR) {  /*若按了“1”到“4”键，则删除对应栏位的存档，并告知用户已删除*/
					FileManager.file_delete(RET - GMMB_RET_ONE + 1);

					char prompt[] = "已删除位置 上的存档";
					prompt[10] = RET - GMMB_RET_ONE + 1 + '0';
					GameMessagebox.print(BUTTON_ONE, prompt);
					GameMessagebox.control();
					GameMessagebox.erase(Client, Ball);
				}
				else  /*若按了“取消”键，则仅擦除对话框*/
					GameMessagebox.erase(Client, Ball);
				break;

			/*4、按下“退出”键*/
			case GAME_RET_QUIT:
				GameMessagebox.print(BUTTON_TWO, "您确定要退出游戏？", "  所有未保存的进度会消失");  /*打印对话框*/

				switch (GameMessagebox.control()) {  /*取对话框操作*/

				/*4.1、按下“是”键*/
				case GMMB_RET_YES:
					Client.matrix_clear(Ball);  /*清空内部数组*/
					if_game = false;  /*标志着不再进行游戏*/
					if_new = false;   /*标志着不再进行新游戏*/
					cct_setcolor();   /*重设颜色*/
					cct_setfontsize("新宋体", fontsize);  /*设置字体大小*/
					TitleScreen.print();  /*重画标题画面*/
					break;

				/*4.2、按下“否”键*/
				case GMMB_RET_NO:
					GameMessagebox.erase(Client, Ball);  /*仅擦除对话框并继续循环*/
					continue;
					break;
				}
				break;

			/*5、游戏失败*/
			case GAME_RET_FAILURE:
				Client.matrix_clear(Ball);  /*清空内部数组*/

				if (*ps)  /*根据需要播放声音*/
					cout << '\007';

				GameMessagebox.print(BUTTON_ONE, "游戏结束！");  /*打印对话框*/
				GameMessagebox.control();  /*取操作，使得用户可以完成点击“确定”键的动作*/

				if_game = false;  /*标志着不再进行游戏*/
				if_new = false;   /*标志着不再进行新游戏*/
				cct_setcolor();   /*重设颜色*/
				cct_setfontsize("新宋体", fontsize);  /*设置字体大小*/
				TitleScreen.print();  /*重画标题画面*/
				break;
			}
		}
	}
	
	/*退出整个游戏后的收尾工作*/
	cct_setfontsize("新宋体", 28);  /*设置字体大小*/
	cct_setcolor();  /*重设颜色*/
	cct_cls();       /*清屏*/
	return 0;
}