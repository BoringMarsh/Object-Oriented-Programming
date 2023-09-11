#include"90-b3.h"

/*存放所有全局变量及对象的结构体*/
game __GAME;

/***************************************************************************
  函数名称：order_input
  功    能：在正确性处理的前提下，输入游戏面板阶数
  输入参数：无
  返 回 值：无
  说    明：本函数直接改变外部全局变量__GAME.order的值
***************************************************************************/
void order_input()
{
	int n;  /*输入值*/

	while (1) {
		cct_gotoxy(CVMB_COORD_X + 12, CVMB_COORD_Y + 4);
		for (int i = 0; i < 5; i++)
			cout << ' ';
		cct_gotoxy(CVMB_COORD_X + 12, CVMB_COORD_Y + 4);
		n = _getche() - '0';

		if (n >= ORDER_MIN && n <= ORDER_MAX)
			break;
	}

	__GAME.order = n;  /*改变对应的实参值*/
}

/***************************************************************************
  函数名称：cover_in_progress
  功    能：游戏标题部分
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void cover_in_progress()
{
	while (1) {
		cct_setcursor(CURSOR_INVISIBLE);
		char PROMPT1[50], PROMPT2[50], PROMPT3[50];  /*标题画面对话框的三行提示语*/
		int RET1 = __GAME.cover.control();  /*标题画面操作返回值*/
		int RET2 = 0;  /*标题画面对话框操作返回值*/

		switch (RET1) {  /*在标题画面上进行操作*/

		/*显示关于*/
		case COVER_ABOUT:
			/*取相关信息*/
			strcpy(PROMPT1, "关于2048  ");
			strcat(PROMPT1, __GAME.version);
			strcpy(PROMPT2, "  开发者：无聊的人");
			strcpy(PROMPT3, "  已是最新版本");

			__GAME.cover_mailbox.print(BUTTON_ONE, PROMPT1, PROMPT2, PROMPT3);  /*显示对话框，列出信息*/
			__GAME.cover_mailbox.control();  /*操作后返回*/
			cct_setcolor();
			__GAME.cover_mailbox.erase();
			continue;
			break;

		case COVER_OPTIONS:
			__GAME.cover_mailbox.print(BUTTON_SWITCH, "色块闪烁：  提示：");
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

		/*开始新游戏*/
		case COVER_NEW:
		case COVER_AUTO:
			__GAME.score = 0;       /*分数清零*/
			__GAME.stepnumber = 0;  /*步数归零*/
			for (int i = 0; i < __GAME.order * __GAME.order; i++)  /*内部数组置零*/
				__GAME.matrix[i] = 0;

			/*取相关信息*/
			strcpy(PROMPT1, "请输入面板阶数( - )：");
			PROMPT1[15] = ORDER_MIN + '0';
			PROMPT1[17] = ORDER_MAX + '0';
			strcpy(PROMPT2, "按“是”进入，按“否”返回");

			__GAME.cover_mailbox.print(BUTTON_TWO, PROMPT1, PROMPT2);  /*显示对话框，要求输入合法的阶数值并询问是否继续*/

			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			order_input();  /*输入阶数*/
			cct_setcursor(CURSOR_INVISIBLE);

			if (__GAME.cover_mailbox.control() == CVMB_RET_NO) {  /*操作，若按“否”则返回，按“是”则继续*/
				cct_setcolor();
				__GAME.cover_mailbox.erase();
				continue;
			}

			__GAME.game_mailbox.set_button_coord();  /*游戏内对话框按键坐标赋值*/
			__GAME.keyboard.set_button_coord();      /*小键盘按键坐标赋值*/

			cct_setcolor();
			console_print_base();      /*打印游戏面板*/
			__GAME.gameboard.print_info();  /*显示游戏信息*/
			__GAME.keyboard.print();        /*打印小键盘*/

			summon_two();          /*随机生成两个2*/
			summon_two();

			if (RET1 == COVER_NEW)
				game_in_progress();    /*进入游戏主体*/
			else
				__GAME.ai_player.auto_game();
			break;

		/*载入已有游戏*/
		case COVER_LOAD:
			__GAME.cover_mailbox.print(BUTTON_FIVE, "载入哪一个存档？");  /*显示对话框，询问载入哪一个存档*/

			RET2 = __GAME.cover_mailbox.control();  /*操作，若按“取消”则返回，按数字键则继续*/
			if (RET2 == CVMB_RET_CANCEL) {
				cct_setcolor();
				__GAME.cover_mailbox.erase();
				continue;
			}

			if (!__GAME.files.if_file_deleted(RET2 - CVMB_RET_ONE + 1)) {  /*若选定位置上的文件未被清空*/
				__GAME.files.file_load(RET2 - CVMB_RET_ONE + 1);  /*读取存档*/
				__GAME.game_mailbox.set_button_coord();  /*游戏内对话框按键坐标赋值*/
				__GAME.keyboard.set_button_coord();      /*小键盘按键坐标赋值*/

				cct_setcolor();
				console_print_base();       /*打印游戏面板*/
				__GAME.gameboard.print_info();   /*显示游戏信息*/
				__GAME.gameboard.update_info();  /*更新游戏信息*/
				__GAME.gameboard.block_multiple_print();  /*打印已有色块*/
				__GAME.keyboard.print();        /*打印小键盘*/

				game_in_progress();    /*进入游戏主体*/
			}

			else {  /*若选定位置上的文件被清空*/
				strcpy(PROMPT1, "位置 上的存档为空");
				PROMPT1[4] = RET2 - CVMB_RET_ONE + '1';

				__GAME.cover_mailbox.print(BUTTON_ONE, PROMPT1);  /*显示对话框，提示选定位置上的文件被清空*/
				__GAME.cover_mailbox.control();  /*操作后返回*/
				cct_setcolor();
				__GAME.cover_mailbox.erase();
				continue;
			}

			break;

		/*退出2048*/
		case COVER_QUIT:
			__GAME.cover_mailbox.print(BUTTON_TWO, "您确定要退出游戏？");  /*显示对话框，询问是否退出游戏*/

			RET2 = __GAME.cover_mailbox.control();  /*操作，若按“否”则返回，按“是”则退出*/
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

		cct_setcolor();  /*重设颜色*/
		cct_cls();       /*清屏*/
		__GAME.cover.print();   /*重画标题画面*/
	}
}

/***************************************************************************
  函数名称：game_in_progress
  功    能：游戏主体部分
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void game_in_progress()
{
	int loop = 1;
	const char prompt[] = "无可合成项，游戏结束！";
	char prompt1[] = "游戏已保存到位置 ";
	char prompt2[] = "已删除位置 上的存档";

	while (loop) {
		if (if_end()) {  /*判断游戏是否结束*/
			__GAME.game_mailbox.print(BUTTON_ONE, prompt);  /*弹出对话框，提示游戏已结束*/
			__GAME.game_mailbox.control();  /*单击“确定”键后退出*/
			break;
		}

		int ret = __GAME.keyboard.control();  /*读键鼠，根据返回值判断操作*/

		switch (ret) {  /*根据上一步操作，决定下一步行动*/

		/*正常移动*/
		case 0:
			if (if_full() == false)
				summon_two();
			break;

		/*退出*/
		case QUIT:
			loop = 0;
			break;

		/*重开*/
		case RESET:
			for (int i = 0; i < __GAME.order * __GAME.order; i++)  /*内部数组置零*/
				__GAME.matrix[i] = 0;
			__GAME.score = 0;       /*分数清零*/
			__GAME.stepnumber = 0;  /*步数归零*/

			cct_setcolor();
			console_print_base();  /*重画界面*/
			__GAME.keyboard.print();
			summon_two();  /*随机生成两个2*/
			summon_two();
			__GAME.gameboard.print_info();   /*显示信息*/
			break;

		/*继续*/
		case CONTINUE:
			__GAME.game_mailbox.erase();     /*重画游戏面板*/
			__GAME.gameboard.update_info();  /*更新游戏信息*/
			break;

		/*存档*/
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

		/*清空存档*/
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
  函数名称：main
  功    能：主函数
  输入参数：无
  返 回 值：0
  说    明：无
***************************************************************************/
int main()
{
	/*以下操作在程序运行前执行一次即可*/
	srand((unsigned int)(time(0)));    /*生成伪随机数的种子*/
	__GAME.cover.set_button_type();           /*标题画面按键种类设置*/
	__GAME.cover.set_button_coord();          /*标题画面按键坐标赋值*/
	__GAME.cover_mailbox.set_button_type();   /*标题画面对话框按键种类设置*/
	__GAME.cover_mailbox.set_button_coord();  /*标题画面对话框按键坐标赋值*/
	__GAME.keyboard.set_button_type();        /*小键盘按键种类设置*/
	__GAME.game_mailbox.set_button_type();    /*游戏内对话框按键种类设置*/
	__GAME.cover.print();  /*打印标题画面*/

	cover_in_progress();  /*标题画面操作，作为整个程序的起点*/
	return 0;
}