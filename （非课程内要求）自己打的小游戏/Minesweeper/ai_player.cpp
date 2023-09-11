#include"90-b4.h"

/***************************************************************************
  函数名称：unturned_check
  功    能：统计数组元素coord周围八个元素的未翻开元素数量
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int coord：内部数组中对应元素的一维坐标（只读）
  返 回 值：int：周围八个元素中有多少元素未被翻开
  说    明：无
***************************************************************************/
int unturned_check(const matrix MATRIX[], const int line, const int row, const int coord)
{
	const int J = coord % row;        /*将一维坐标转换为列标*/
	const int I = (coord - J) / row;  /*将一维坐标转换为行标*/
	int ret = 0;  /*返回值*/

	if (I) {  /*若目标元素不在第一行，检查其上面一个元素*/
		if (!MATRIX[coord - row].if_turned)
			ret++;
	}

	if (J) {  /*若目标元素不在第一列，检查其左边一个元素*/
		if (!MATRIX[coord - 1].if_turned)
			ret++;
	}

	if (I < line - 1) {  /*若目标元素不在最后一行，检查其下面一个元素*/
		if (!MATRIX[coord + row].if_turned)
			ret++;
	}

	if (J < row - 1) {  /*若目标元素不在最后一列，检查其右边一个元素*/
		if (!MATRIX[coord + 1].if_turned)
			ret++;
	}

	if (I && J) {  /*检查目标元素左上角的元素*/
		if (!MATRIX[coord - row - 1].if_turned)
			ret++;
	}

	if (I && J < row - 1) {  /*检查目标元素右上角的元素*/
		if (!MATRIX[coord - row + 1].if_turned)
			ret++;
	}

	if (I < line - 1 && J) {  /*检查目标元素左下角的元素*/
		if (!MATRIX[coord + row - 1].if_turned)
			ret++;
	}

	if (I < line - 1 && J < row - 1) {  /*检查目标元素右下角的元素*/
		if (!MATRIX[coord + row + 1].if_turned)
			ret++;
	}

	return ret;
}

/***************************************************************************
  函数名称：wheel_click_flag
  功    能：类似按鼠标中键时的翻开操作，将数组元素coord周围一圈元素全部插旗
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int coord：内部数组中对应元素的一维坐标（只读）
			int* bomb_num：剩余雷数
  返 回 值：无
  说    明：无
***************************************************************************/
void wheel_click_flag(matrix MATRIX[], const int line, const int row, const int coord, int* bomb_num)
{
	const int J = coord % row;        /*将一维坐标转换为列标*/
	const int I = (coord - J) / row;  /*将一维坐标转换为行标*/

	if (I) {  /*若目标元素不在第一行，检查其上面一个元素*/
		if (!MATRIX[coord - row].if_turned && !MATRIX[coord - row].if_flag)
			flag(MATRIX, line, row, coord - row, bomb_num, PLACE_FLAG);
	}

	if (J) {  /*若目标元素不在第一列，检查其左边一个元素*/
		if (!MATRIX[coord - 1].if_turned && !MATRIX[coord - 1].if_flag)
			flag(MATRIX, line, row, coord - 1, bomb_num, PLACE_FLAG);
	}

	if (I < line - 1) {  /*若目标元素不在最后一行，检查其下面一个元素*/
		if (!MATRIX[coord + row].if_turned && !MATRIX[coord + row].if_flag)
			flag(MATRIX, line, row, coord + row, bomb_num, PLACE_FLAG);
	}

	if (J < row - 1) {  /*若目标元素不在最后一列，检查其右边一个元素*/
		if (!MATRIX[coord + 1].if_turned && !MATRIX[coord + 1].if_flag)
			flag(MATRIX, line, row, coord + 1, bomb_num, PLACE_FLAG);
	}

	if (I && J) {  /*检查目标元素左上角的元素*/
		if (!MATRIX[coord - row - 1].if_turned && !MATRIX[coord - row - 1].if_flag)
			flag(MATRIX, line, row, coord - row - 1, bomb_num, PLACE_FLAG);
	}

	if (I && J < row - 1) {  /*检查目标元素右上角的元素*/
		if (!MATRIX[coord - row + 1].if_turned && !MATRIX[coord - row + 1].if_flag)
			flag(MATRIX, line, row, coord - row + 1, bomb_num, PLACE_FLAG);
	}

	if (I < line - 1 && J) {  /*检查目标元素左下角的元素*/
		if (!MATRIX[coord + row - 1].if_turned && !MATRIX[coord + row - 1].if_flag)
			flag(MATRIX, line, row, coord + row - 1, bomb_num, PLACE_FLAG);
	}

	if (I < line - 1 && J < row - 1) {  /*检查目标元素右下角的元素*/
		if (!MATRIX[coord + row + 1].if_turned && !MATRIX[coord + row + 1].if_flag)
			flag(MATRIX, line, row, coord + row + 1, bomb_num, PLACE_FLAG);
	}
}

/***************************************************************************
  函数名称：ai_control
  功    能：进行自动解操作
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			int* bomb_num：剩余雷数
			bool* if_initialized：是否初始化
  返 回 值：int：操作结果
  说    明：无
***************************************************************************/
int ai_control(matrix MATRIX[], const int line, const int row, int* bomb_num, bool* if_initialized)
{
	matrix m[LINE_MAX * ROW_MAX];  /*查找解用的结构体数组*/
	int RET1 = 0, RET2 = 0;        /*翻开操作函数的返回值、函数的返回值，均先设为0*/
	int loop = 1;

	if (!*if_initialized) {  /*若数组未初始化，则初始化并随机翻开一个元素*/
		const int coord = rand() % (line * row);  /*随机选取坐标*/
		const int J = coord % row;                /*将一维坐标转换为列标*/
		const int I = (coord - J) / row;          /*将一维坐标转换为行标*/

		matrix_initialize(MATRIX, line, row, *bomb_num, J, I);  /*初始化数组*/
		*if_initialized = true;  /*初始化状态设为真*/

		MATRIX[coord].mark = true;
		turn(MATRIX, line, row, coord);
	}

	while (!matrix_compare(m, MATRIX, line, row) && loop) {  /*正常翻开状态下，只有在操作后数组未发生变化才停止操作*/
		matrix_copy(m, MATRIX, line, row);

		for (int i = 0; i < line * row; i++) {  /*若有元素已被翻开、数值不为零、周围未翻开元素数量刚好等于其数值的，在其周围插满旗*/
			if (MATRIX[i].if_turned && MATRIX[i].num && unturned_check(MATRIX, line, row, i) == MATRIX[i].num - '0')
				wheel_click_flag(MATRIX, line, row, i, bomb_num);
		}

		for (int i = 0; i < line * row; i++) {
			if (MATRIX[i].if_turned && MATRIX[i].num)  /*经过一轮插旗后，若有元素已被翻开、数值不为零，在该元素上执行滚轮翻开操作*/
				RET1 = wheel_click_turn(MATRIX, line, row, i);

			if (RET1) {  /*若翻开过程遇到地雷，设置函数返回值后结束操作*/
				RET2 = RET1;
				loop = 0;
				break;
			}
		}
	}

	return RET2;
}