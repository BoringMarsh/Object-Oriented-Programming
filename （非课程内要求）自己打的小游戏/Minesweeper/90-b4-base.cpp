#include"90-b4.h"

/***************************************************************************
  函数名称：matrix_single_scan
  功    能：检查数组元素coord周围八个元素的情况，并做相应处理
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
            const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int coord：内部数组中对应元素的一维坐标（只读）
  返 回 值：无
  说    明：相应处理为：若周围八个元素中存在雷，则当前检查元素自增
***************************************************************************/
void matrix_single_scan(matrix MATRIX[], const int line, const int row, const int coord)
{
	if (MATRIX[coord].num != '*') {  /*只有在目标元素不是雷的情况下才开始检查*/
		const int J = coord % row;        /*将一维坐标转换为列标*/
		const int I = (coord - J) / row;  /*将一维坐标转换为行标*/

		if (I) {  /*若目标元素不在第一行，检查其上面一个元素*/
			if (MATRIX[coord - row].num == '*')
				MATRIX[coord].num++;
		}

		if (J) {  /*若目标元素不在第一列，检查其左边一个元素*/
			if (MATRIX[coord - 1].num == '*')
				MATRIX[coord].num++;
		}

		if (I < line - 1) {  /*若目标元素不在最后一行，检查其下面一个元素*/
			if (MATRIX[coord + row].num == '*')
				MATRIX[coord].num++;
		}

		if (J < row - 1) {  /*若目标元素不在最后一列，检查其右边一个元素*/
			if (MATRIX[coord + 1].num == '*')
				MATRIX[coord].num++;
		}

		if (I && J) {  /*检查目标元素左上角的元素*/
			if (MATRIX[coord - row - 1].num == '*')
				MATRIX[coord].num++;
		}

		if (I && J < row - 1) {  /*检查目标元素右上角的元素*/
			if (MATRIX[coord - row + 1].num == '*')
				MATRIX[coord].num++;
		}

		if (I < line - 1 && J) {  /*检查目标元素左下角的元素*/
			if (MATRIX[coord + row - 1].num == '*')
				MATRIX[coord].num++;
		}

		if (I < line - 1 && J < row - 1) {  /*检查目标元素右下角的元素*/
			if (MATRIX[coord + row + 1].num == '*')
				MATRIX[coord].num++;
		}
	}
}

/***************************************************************************
  函数名称：zero_check1
  功    能：将零元素周围八个元素中的零元素标记
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int coord：内部数组中对应元素的一维坐标（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void zero_check1(matrix MATRIX[], const int line, const int row, const int coord)
{
	if (MATRIX[coord].num == '0' && MATRIX[coord].mark == true) {  /*只有在目标元素为零元素且被标记的情况下才开始检查*/
		const int J = coord % row;        /*将一维坐标转换为列标*/
		const int I = (coord - J) / row;  /*将一维坐标转换为行标*/

		if (I) {  /*若目标元素不在第一行，检查其上面一个元素*/
			if (MATRIX[coord - row].num == '0')
				MATRIX[coord - row].mark = true;
		}

		if (J) {  /*若目标元素不在第一列，检查其左边一个元素*/
			if (MATRIX[coord - 1].num == '0')
				MATRIX[coord - 1].mark = true;
		}

		if (I < line - 1) {  /*若目标元素不在最后一行，检查其下面一个元素*/
			if (MATRIX[coord + row].num == '0')
				MATRIX[coord + row].mark = true;
		}

		if (J < row - 1) {  /*若目标元素不在最后一列，检查其右边一个元素*/
			if (MATRIX[coord + 1].num == '0')
				MATRIX[coord + 1].mark = true;
		}

		if (I && J) {  /*检查目标元素左上角的元素*/
			if (MATRIX[coord - row - 1].num == '0')
				MATRIX[coord - row - 1].mark = true;
		}

		if (I && J < row - 1) {  /*检查目标元素右上角的元素*/
			if (MATRIX[coord - row + 1].num == '0')
				MATRIX[coord - row + 1].mark = true;
		}

		if (I < line - 1 && J) {  /*检查目标元素左下角的元素*/
			if (MATRIX[coord + row - 1].num == '0')
				MATRIX[coord + row - 1].mark = true;
		}

		if (I < line - 1 && J < row - 1) {  /*检查目标元素右下角的元素*/
			if (MATRIX[coord + row + 1].num == '0')
				MATRIX[coord + row + 1].mark = true;
		}
	}
}

/***************************************************************************
  函数名称：zero_check2
  功    能：将所有被标记的零元素的周围八个元素全部标记
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int coord：内部数组中对应元素的一维坐标（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void zero_check2(matrix MATRIX[], const int line, const int row, const int coord)
{
	if (MATRIX[coord].num == '0' && MATRIX[coord].mark == true) {  /*只有在目标元素为零元素且被标记的情况下才开始检查*/
		const int J = coord % row;        /*将一维坐标转换为列标*/
		const int I = (coord - J) / row;  /*将一维坐标转换为行标*/

		if (I)  /*若目标元素不在第一行，标记其上面一个元素*/
				MATRIX[coord - row].mark = true;

		if (J)  /*若目标元素不在第一列，标记其左边一个元素*/
				MATRIX[coord - 1].mark = true;

		if (I < line - 1)  /*若目标元素不在最后一行，标记其下面一个元素*/
				MATRIX[coord + row].mark = true;

		if (J < row - 1)  /*若目标元素不在最后一列，标记其右边一个元素*/
				MATRIX[coord + 1].mark = true;

		if (I && J)  /*标记目标元素左上角的元素*/
				MATRIX[coord - row - 1].mark = true;

		if (I && J < row - 1)  /*标记目标元素右上角的元素*/
				MATRIX[coord - row + 1].mark = true;

		if (I < line - 1 && J)  /*标记目标元素左下角的元素*/
				MATRIX[coord + row - 1].mark = true;

		if (I < line - 1 && J < row - 1)  /*标记目标元素右下角的元素*/
				MATRIX[coord + row + 1].mark = true;
	}
}

/***************************************************************************
  函数名称：flag_check
  功    能：统计数组元素coord周围八个元素的插旗数量
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int coord：内部数组中对应元素的一维坐标（只读）
  返 回 值：int：周围八个元素中有多少元素已被插旗
  说    明：无
***************************************************************************/
int flag_check(const matrix MATRIX[], const int line, const int row, const int coord)
{
	const int J = coord % row;        /*将一维坐标转换为列标*/
	const int I = (coord - J) / row;  /*将一维坐标转换为行标*/
	int ret = 0;  /*返回值*/

	if (I) {  /*若目标元素不在第一行，检查其上面一个元素*/
		if (MATRIX[coord - row].if_flag)
			ret++;
	}

	if (J) {  /*若目标元素不在第一列，检查其左边一个元素*/
		if (MATRIX[coord - 1].if_flag)
			ret++;
	}

	if (I < line - 1) {  /*若目标元素不在最后一行，检查其下面一个元素*/
		if (MATRIX[coord + row].if_flag)
			ret++;
	}

	if (J < row - 1) {  /*若目标元素不在最后一列，检查其右边一个元素*/
		if (MATRIX[coord + 1].if_flag)
			ret++;
	}

	if (I && J) {  /*检查目标元素左上角的元素*/
		if (MATRIX[coord - row - 1].if_flag)
			ret++;
	}

	if (I && J < row - 1) {  /*检查目标元素右上角的元素*/
		if (MATRIX[coord - row + 1].if_flag)
			ret++;
	}

	if (I < line - 1 && J) {  /*检查目标元素左下角的元素*/
		if (MATRIX[coord + row - 1].if_flag)
			ret++;
	}

	if (I < line - 1 && J < row - 1) {  /*检查目标元素右下角的元素*/
		if (MATRIX[coord + row + 1].if_flag)
			ret++;
	}

	return ret;
}

/***************************************************************************
  函数名称：matrix_copy
  功    能：将结构体数组src[]复制到结构体数组dst[]中
  输入参数：matrix dst[]：待复制的结构体数组
            const matrix src[]：来源结构体数组（只读）
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void matrix_copy(matrix dst[], const matrix src[], const int line, const int row)
{
	for (int i = 0; i < line * row; i++) {
		dst[i].num = src[i].num;                /*复制数值*/
		dst[i].mark = src[i].mark;              /*复制一般用标记*/
		dst[i].coord_mark = src[i].coord_mark;  /*复制坐标标记*/
		dst[i].if_flag = src[i].if_flag;        /*复制插旗情况*/
		dst[i].if_turned = src[i].if_turned;    /*复制翻开情况*/
	}
}

/***************************************************************************
  函数名称：matrix_compare
  功    能：比较两结构体数组m1[]和m2[]
  输入参数：const matrix m1[]：待比较的结构体数组1（只读）
			const matrix m2[]：待比较的结构体数组2（只读）
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
  返 回 值：bool：两结构体数组是否完全相等
  说    明：无
***************************************************************************/
bool matrix_compare(const matrix m1[], const matrix m2[], const int line, const int row)
{
	bool ret = true;  /*返回值，先设为真*/

	for (int i = 0; i < line * row; i++) {  /*逐个元素进行比较，若发现有一项成员值不等，返回值设为假并结束检查*/
		if (m1[i].num != m2[i].num) {  /*比较数值*/
			ret = false;
			break;
		}

		if (m1[i].mark != m2[i].mark) {  /*比较一般用标记*/
			ret = false;
			break;
		}

		if (m1[i].coord_mark != m2[i].coord_mark) {  /*比较坐标标记*/
			ret = false;
			break;
		}

		if (m1[i].if_flag != m2[i].if_flag) {  /*比较插旗情况*/
			ret = false;
			break;
		}

		if (m1[i].if_turned != m2[i].if_turned) {  /*比较翻开情况*/
			ret = false;
			break;
		}
	}

	return ret;
}

/***************************************************************************
  函数名称：matrix_initialize
  功    能：将内部结构体数组数值初始化
  输入参数：matrix MATRIX[]：整个游戏的内部结构体数组
			const int line：游戏行数（只读）
			const int row：游戏列数（只读）
			const int bomb_num：地雷数（只读）
			const int first_x：第一次点击位置横坐标（只读）
			const int first_y：第一次点击位置纵坐标（只读）
  返 回 值：无
  说    明：1、本函数包括埋雷和数值的初始化
            2、已保证每次游戏的第一次点击位置都为0（即周围一圈都没有雷）
			3、本函数未做其他数据成员（如一般标记等）的初始化
***************************************************************************/
void matrix_initialize(matrix MATRIX[], const int line, const int row, const int bomb_num, const int first_x, const int first_y)
{
	const int first_coord = first_y * row + first_x;  /*将第一次点击位置横纵坐标转换为一维坐标*/

	/*1、数组初始化，将所有元素初始化为字符'0'*/
	for (int i = 0; i < line * row; i++)
		MATRIX[i].num = '0';

	/*2、埋雷，每次随机取定一个坐标，将该坐标上的元素变为'*'，若该坐标上已经是雷，则i自减，重新取定坐标，保证实际地雷数足够*/
	for (int i = 0; i < bomb_num; i++) {
		int coord = rand() % (line * row);  /*取一维随机坐标*/
		const int J = coord % row;          /*将一维坐标转换为列标*/
		const int I = (coord - J) / row;    /*将一维坐标转换为行标*/

		/*若随机坐标上元素为雷，或其位置为第一次点击位置及其周围一圈，则计数变量自减*/
		if (MATRIX[coord].num == '*' || (I >= first_y - 1 && I <= first_y + 1 && J >= first_x - 1 && J <= first_x + 1))
			i--;

		else
			MATRIX[coord].num = '*';
	}

	/*3、除雷以外元素的数值初始化*/
	for (int i = 0; i < line * row; i++)
		matrix_single_scan(MATRIX, line, row, i);
}