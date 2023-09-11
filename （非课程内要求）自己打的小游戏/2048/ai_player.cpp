#include"90-b3.h"

/***************************************************************************
  函数名称：matrix_copy
  功    能：将游戏内部数组复制到私有成员数组中
  输入参数：无
  返 回 值：无
  说    明：该函数可为私有成员赋值
***************************************************************************/
void ai_player::matrix_copy()
{
	for (int i = 0; i < __GAME.order * __GAME.order; i++)
		matrix[i] = __GAME.matrix[i];
}

/***************************************************************************
  函数名称：two_order
  功    能：返回一个数是2的几次方
  输入参数：int initial_num：待求解的数
  返 回 值：int：该数是2的几次方
  说    明：1、该函数可为私有成员赋值
            2、该函数只处理0和2的次方数
***************************************************************************/
int ai_player::two_order(int initial_num)
{
	int ret = 0;  /*返回值，先置为0*/

	if (initial_num == 0)  /*若该数为0，返回-1*/
		ret = -1;
	else {
		while (initial_num != 1) {  /*正常求算*/
			initial_num = initial_num / 2;
			ret++;
		}
	}

	return ret;
}

/***************************************************************************
  函数名称：matrix_trans
  功    能：将私有成员数组转换，以便寻找最优解
  输入参数：无
  返 回 值：无
  说    明：1、该函数可改变私有成员的值
			2、该函数将每个元素转换为2的次方数（如：8转换为3）
***************************************************************************/
void ai_player::matrix_trans()
{
	for (int i = 0; i < __GAME.order * __GAME.order; i++)
		matrix[i] = two_order(matrix[i]);
}

/***************************************************************************
  函数名称：check_up
  功    能：检查某个位置的元素能否通过向上合成消除
  输入参数：const int line：行数（只读）
            const int row：列数（只读）
			const int num：元素数值（只读）
  返 回 值：无
  说    明：只要从该位置向上看，遇到的第一个非零数等于其本身，就算找到
***************************************************************************/
bool ai_player::check_up(const int line, const int row, const int num)
{
	if (!line || !num)  /*若该数在第一行或为零，返回假*/
		return false;
	else {
		const int coord = line * __GAME.order + row;  /*将行标和列标转换为一维坐标*/
		int count = 0;  /*计数变量*/

		while (count < line) {  /*向上一行行寻找，直到遇到非零数*/
			if (matrix[coord - (count + 1) * __GAME.order])
				break;
			else
				count++;
		}

		if (count == line)  /*若计数变量等于一定值，则说明该数上方全为零，返回假*/
			return false;
		else {
			if (matrix[coord - (count + 1) * __GAME.order] == matrix[coord])  /*若该数上方第一个非零数等于其本身，则返回真*/
				return true;
			else  /*若该数上方第一个非零数不等于其本身，则仍然返回假*/
				return false;
		}
	}
}

/***************************************************************************
  函数名称：check_down
  功    能：检查某个位置的元素能否通过向下合成消除
  输入参数：const int line：行数（只读）
			const int row：列数（只读）
			const int num：元素数值（只读）
  返 回 值：无
  说    明：只要从该位置向下看，遇到的第一个非零数等于其本身，就算找到
***************************************************************************/
bool ai_player::check_down(const int line, const int row, const int num)
{
	if (line == __GAME.order - 1 || !num)  /*若该数在最后一行或为零，返回假*/
		return false;
	else {
		const int coord = line * __GAME.order + row;  /*将行标和列标转换为一维坐标*/
		int count = 0;  /*计数变量*/

		while (count < __GAME.order - 1 - line) {  /*向下一行行寻找，直到遇到非零数*/
			if (matrix[coord + (count + 1) * __GAME.order])
				break;
			else
				count++;
		}

		if (count == __GAME.order - 1 - line)  /*若计数变量等于一定值，则说明该数下方全为零，返回假*/
			return false;
		else {
			if (matrix[coord + (count + 1) * __GAME.order] == matrix[coord])  /*若该数下方第一个非零数等于其本身，则返回真*/
				return true;
			else  /*若该数下方第一个非零数不等于其本身，则仍然返回假*/
				return false;
		}
	}
}

/***************************************************************************
  函数名称：check_left
  功    能：检查某个位置的元素能否通过向左合成消除
  输入参数：const int line：行数（只读）
			const int row：列数（只读）
			const int num：元素数值（只读）
  返 回 值：无
  说    明：只要从该位置向左看，遇到的第一个非零数等于其本身，就算找到
***************************************************************************/
bool ai_player::check_left(const int line, const int row, const int num)
{
	if (!row || !num)  /*若该数在第一列或为零，返回假*/
		return false;
	else {
		const int coord = line * __GAME.order + row;  /*将行标和列标转换为一维坐标*/
		int count = 0;  /*计数变量*/

		while (count < row) {  /*向左一列列寻找，直到遇到非零数*/
			if (matrix[coord - (count + 1)])
				break;
			else
				count++;
		}

		if (count == row)  /*若计数变量等于一定值，则说明该数左侧全为零，返回假*/
			return false;
		else {
			if (matrix[coord - (count + 1)] == matrix[coord])  /*若该数左侧第一个非零数等于其本身，则返回真*/
				return true;
			else  /*若该数左侧第一个非零数不等于其本身，则仍然返回假*/
				return false;
		}
	}
}

/***************************************************************************
  函数名称：check_right
  功    能：检查某个位置的元素能否通过向右合成消除
  输入参数：const int line：行数（只读）
			const int row：列数（只读）
			const int num：元素数值（只读）
  返 回 值：无
  说    明：只要从该位置向右看，遇到的第一个非零数等于其本身，就算找到
***************************************************************************/
bool ai_player::check_right(const int line, const int row, const int num)
{
	if (row == __GAME.order - 1 || !num)  /*若该数在最后一列或为零，返回假*/
		return false;  /*计数变量*/
	else {
		const int coord = line * __GAME.order + row;  /*将行标和列标转换为一维坐标*/
		int count = 0;

		while (count < __GAME.order - 1 - row) {  /*向右一列列寻找，直到遇到非零数*/
			if (matrix[coord + (count + 1)])
				break;
			else
				count++;
		}

		if (count == __GAME.order - 1 - row)  /*若计数变量等于一定值，则说明该数右侧全为零，返回假*/
			return false;
		else {
			if (matrix[coord + (count + 1)] == matrix[coord])  /*若该数右侧第一个非零数等于其本身，则返回真*/
				return true;
			else  /*若该数右侧第一个非零数不等于其本身，则仍然返回假*/
				return false;
		}
	}
}

/***************************************************************************
  函数名称：check_and_answer
  功    能：检查并给出对于某个位置的元素的最优解
  输入参数：const int line：行数（只读）
			const int row：列数（只读）
			const int num：元素数值（只读）
  返 回 值：无
  说    明：1、能向下合成则向下合成
            2、1项不满足，若能向左或向右合成，则合成（优先向左）
			3、非必要不向上合成，若1、2项都不满足，先不合成当前元素
***************************************************************************/
int ai_player::check_and_answer(const int line, const int row, const int num)
{
	bool prime1 = check_up(line, row, num);     /*检查向上合成*/
	bool prime2 = check_down(line, row, num);   /*检查向下合成*/
	bool prime3 = check_left(line, row, num);   /*检查向左合成*/
	bool prime4 = check_right(line, row, num);  /*检查向右合成*/

	/*根据合成结果，在经过判断后取对应返回值*/
	if (prime2)
		return AI_SLN_DOWN;
	else if (prime3 || prime4) {
		if (prime3)
			return AI_SLN_LEFT;
		else
			return AI_SLN_RIGHT;
	}
	else
		return AI_SLN_NOMOVE;
}

/***************************************************************************
  函数名称：find_best_solution
  功    能：检查整个数组，找出最优解
  输入参数：无
  返 回 值：int：最优解的移动方式
  说    明：1、从下往上，第一个能合成的最小的数优先（不含向上合成）
            2、若所有的元素都无法通过除了向上合成以外的方式消除，则向上合成
***************************************************************************/
int ai_player::find_best_solution()
{
	if (if_end())  /*若游戏已结束，直接返回结束*/
		return AI_SLN_END;
	else {
		matrix_copy();   /*取原始数组*/
		matrix_trans();  /*转换私有成员数组，方便查找*/
		const int MAX = two_order(matrix_getmax());  /*取原始数组最大值（2的次方形式）*/
		const int MIN = two_order(matrix_getmin());  /*取原始数组最小值（2的次方形式）*/
		int i, j, k;       /*目标数、行数、列数*/
		bool loop = true;  /*是否需要继续查找*/
		int answer = 0;    /*函数的返回值*/

		for (i = MIN; i <= MAX && loop; i++) {
			for (j = __GAME.order - 1; j >= 0 && loop; j--) {
				for (k = 0; k < __GAME.order && loop; k++) {
					const int coord = j * __GAME.order + k;  /*将行标和列标转换为一维坐标*/

					if (matrix[coord] == i) {  /*若当前元素的数值等于目标数，找出对于其的最优解*/
						answer = check_and_answer(j, k, i);
						if (answer != AI_SLN_NOMOVE)  /*若最优解不等于向上合成，则已找到，loop置为假，结束查找*/
							loop = false;
					}
				}
			}
		}

		if (!loop)  /*若查找完成后loop为假，则返回找到的最优解*/
			return answer;
		else  /*若查找完成后loop仍为真，则所有元素都无法通过除了向上合成以外的方式消除，则向下合成*/
			return AI_SLN_DOWN;
	}
}

/***************************************************************************
  函数名称：if_limit
  功    能：检查内部数组是否为极限状态
  输入参数：无
  返 回 值：bool：是否为极限状态
  说    明：极限状态指整个内部数组零元素仅有一个的情况
***************************************************************************/
bool ai_player::if_limit()
{
	int count = 0;
	for (int i = 0; i < __GAME.order * __GAME.order; i++) {
		if (__GAME.matrix[i])
			count++;
	}

	if (count == __GAME.order * __GAME.order - 1)
		return true;
	else
		return false;
}

/***************************************************************************
  函数名称：auto_game
  功    能：进行自动游戏
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void ai_player::auto_game()
{
	int loop = 1, count = 0;

	while (loop) {
		int ret = find_best_solution();  /*寻找最优解*/
		//int ret = 0;

		//switch (count % 4) {
		//case 0:
			//ret = AI_SLN_UP;
			//break;
		//case 1:
			//ret = AI_SLN_DOWN;
			//break;
		//case 2:
			//ret = AI_SLN_LEFT;
			//break;
		//case 3:
			//ret = AI_SLN_RIGHT;
			//break;
		//}

		//if (if_end())
			//break;

		if (if_limit())  /*若为极限状态，则最优解转换为对应操作*/
			ret = AI_SLN_LIMIT;

		switch (ret) {  /*根据最优解进行相关操作*/
		case AI_SLN_UP:
			act_up();
			if (!if_full())
				summon_two();
			__GAME.gameboard.update_info();
			count++;
			break;
		case AI_SLN_DOWN:
			act_down();
			if (!if_full())
				summon_two();
			__GAME.gameboard.update_info();
			count++;
			break;
		case AI_SLN_LEFT:
			act_left();
			if (!if_full())
				summon_two();
			__GAME.gameboard.update_info();
			count++;
			break;
		case AI_SLN_RIGHT:
			act_right();
			if (!if_full())
				summon_two();
			__GAME.gameboard.update_info();
			count++;
			break;
		case AI_SLN_END:
			loop = 0;
			break;
		case AI_SLN_LIMIT:
			act_left();
			if (!if_full())
				summon_two();
			__GAME.gameboard.update_info();

			for (int i = 0; i < __GAME.order - 1; i++) {
				act_down();
				if (!if_full())
					summon_two();
				__GAME.gameboard.update_info();
			}

			break;
		}
	}

	__GAME.game_mailbox.print(BUTTON_ONE, "无可合成项，游戏结束！");  /*弹出对话框，提示游戏已结束*/
	__GAME.game_mailbox.control();  /*单击“确定”键后退出*/
}