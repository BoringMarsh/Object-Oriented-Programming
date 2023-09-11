#include"90-b3.h"

/***************************************************************************
  函数名称：move_left
  功    能：将面板上所有的数字堆积在左侧
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void move_left()
{
	int i, j;

	for (i = 0; i < __GAME.order; i++) {
		for (j = 1; j < __GAME.order; j++) {   /*直接从每一行的第二个元素开始检查*/
			int coord = __GAME.order * i + j;  /*将行标和列标转换为一维坐标*/

			if (__GAME.matrix[coord] != 0 && __GAME.matrix[coord - 1] == 0) {  /*若当前元素不为零且其左边元素为零，两元素交换*/
				__GAME.matrix[coord - 1] = __GAME.matrix[coord];
				__GAME.matrix[coord] = 0;

				if (j != 1)  /*每交换一次元素列标回退，以应付同一元素需要多次交换的情况*/
					j = j - 2;
			}
		}
	}
}

/***************************************************************************
  函数名称：add_left
  功    能：左侧方向上合成数字
  输入参数：无
  返 回 值：无
  说    明：1、每一行有多种合成情况时，从左到右寻找到的第一组相同数进行合成
            2、不使用新合成的数再次合成
			3、合成的同时，按新合成的数值计分
***************************************************************************/
void add_left()
{
	int i, j;

	for (i = 0; i < __GAME.order; i++) {
		for (j = 1; j < __GAME.order; j++) {
			int coord = __GAME.order * i + j;  /*将行标和列标转换为一维坐标*/

			if (__GAME.matrix[coord] == __GAME.matrix[coord - 1] && __GAME.matrix[coord] != 0) {  /*若当前元素不为零且等于其左边元素，两元素堆叠至左侧*/
				__GAME.matrix[coord - 1] = __GAME.matrix[coord - 1] * 2;
				__GAME.matrix[coord] = 0;
				__GAME.score = __GAME.score + __GAME.matrix[coord - 1];  /*按新合成的数值统计得分*/
			}
		}
	}
}

/***************************************************************************
  函数名称：act_left
  功    能：按一次方向左键的操作
  输入参数：无
  返 回 值：无
  说    明：先堆积，后合成计分，再堆积
***************************************************************************/
void act_left()
{
	move_left();     /*一次堆叠*/
	add_left();      /*向左合成*/
	move_left();     /*二次堆叠*/
	__GAME.stepnumber++;  /*步数自增*/
	__GAME.gameboard.block_multiple_print();  /*重画色块*/
	__GAME.gameboard.update_info();  /*更新信息*/
}

/***************************************************************************
  函数名称：move_right
  功    能：将面板上所有的数字堆积在右侧
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void move_right()
{
	int i, j;

	for (i = 0; i < __GAME.order; i++) {
		for (j = __GAME.order - 2; j >= 0; j--) {  /*直接从每一行的倒数第二个元素开始检查*/
			int coord = __GAME.order * i + j;  /*将行标和列标转换为一维坐标*/

			if (__GAME.matrix[coord] != 0 && __GAME.matrix[coord + 1] == 0) {  /*若当前元素不为零且其右边元素为零，两元素交换*/
				__GAME.matrix[coord + 1] = __GAME.matrix[coord];
				__GAME.matrix[coord] = 0;

				if (j != __GAME.order - 2)  /*每交换一次元素列标自增，以应付同一元素需要多次交换的情况*/
					j = j + 2;
			}
		}
	}
}

/***************************************************************************
  函数名称：add_right
  功    能：右侧方向上合成数字
  输入参数：无
  返 回 值：无
  说    明：1、每一行有多种合成情况时，从右到左寻找到的第一组相同数进行合成
			2、不使用新合成的数再次合成
			3、合成的同时，按新合成的数值计分
***************************************************************************/
void add_right()
{
	int i, j;

	for (i = 0; i < __GAME.order; i++) {
		for (j = __GAME.order - 2; j >= 0; j--) {
			int coord = __GAME.order * i + j;  /*将行标和列标转换为一维坐标*/

			if (__GAME.matrix[coord] == __GAME.matrix[coord + 1] && __GAME.matrix[coord] != 0) {  /*若当前元素不为零且等于其右边元素，两元素堆叠至右侧*/
				__GAME.matrix[coord + 1] = __GAME.matrix[coord + 1] * 2;
				__GAME.matrix[coord] = 0;
				__GAME.score = __GAME.score + __GAME.matrix[coord + 1];  /*按新合成的数值统计得分*/
			}
		}
	}
}

/***************************************************************************
  函数名称：act_right
  功    能：按一次方向右键的操作
  输入参数：无
  返 回 值：无
  说    明：先堆积，后合成计分，再堆积
***************************************************************************/
void act_right()
{
	move_right();    /*一次堆叠*/
	add_right();     /*向右合成*/
	move_right();    /*二次堆叠*/
	__GAME.stepnumber++;  /*步数自增*/
	__GAME.gameboard.block_multiple_print();  /*重画色块*/
	__GAME.gameboard.update_info();  /*更新信息*/
}

/***************************************************************************
  函数名称：move_up
  功    能：将面板上所有的数字堆积在上方
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void move_up()
{
	int i, j;

	for (j = 0; j < __GAME.order; j++) {
		for (i = 1; i < __GAME.order; i++) {  /*直接从每一列的第二个元素开始检查*/
			int coord = __GAME.order * i + j;  /*将行标和列标转换为一维坐标*/

			if (__GAME.matrix[coord] != 0 && __GAME.matrix[coord - __GAME.order] == 0) {  /*若当前元素不为零且其上方元素为零，两元素交换*/
				__GAME.matrix[coord - __GAME.order] = __GAME.matrix[coord];
				__GAME.matrix[coord] = 0;

				if (i != 1)  /*每交换一次元素行标回退，以应付同一元素需要多次交换的情况*/
					i = i - 2;
			}
		}
	}
}

/***************************************************************************
  函数名称：add_up
  功    能：往上方合成数字
  输入参数：无
  返 回 值：无
  说    明：1、每一行有多种合成情况时，从上到下寻找到的第一组相同数进行合成
			2、不使用新合成的数再次合成
			3、合成的同时，按新合成的数值计分
***************************************************************************/
void add_up()
{
	int i, j;

	for (j = 0; j < __GAME.order; j++) {
		for (i = 1; i < __GAME.order; i++) {
			int coord = __GAME.order * i + j;  /*将行标和列标转换为一维坐标*/

			if (__GAME.matrix[coord] == __GAME.matrix[coord - __GAME.order] && __GAME.matrix[coord] != 0) {  /*若当前元素不为零且等于其上方元素，两元素堆叠至上方*/
				__GAME.matrix[coord - __GAME.order] = __GAME.matrix[coord - __GAME.order] * 2;
				__GAME.matrix[coord] = 0;
				__GAME.score = __GAME.score + __GAME.matrix[coord - __GAME.order];  /*按新合成的数值统计得分*/
			}
		}
	}
}

/***************************************************************************
  函数名称：act_up
  功    能：按一次方向上键的操作
  输入参数：无
  返 回 值：无
  说    明：先堆积，后合成计分，再堆积
***************************************************************************/
void act_up()
{
	move_up();       /*一次堆叠*/
	add_up();        /*向上合成*/
	move_up();       /*二次堆叠*/
	__GAME.stepnumber++;  /*步数自增*/
	__GAME.gameboard.block_multiple_print();  /*重画色块*/
	__GAME.gameboard.update_info();  /*更新信息*/
}

/***************************************************************************
  函数名称：move_down
  功    能：将面板上所有的数字堆积在下方
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void move_down()
{
	int i, j;

	for (j = 0; j < __GAME.order; j++) {
		for (i = __GAME.order - 2; i >= 0; i--) {  /*直接从每一列的倒数第二个元素开始检查*/
			int coord = __GAME.order * i + j;  /*将行标和列标转换为一维坐标*/

			if (__GAME.matrix[coord] != 0 && __GAME.matrix[coord + __GAME.order] == 0) {  /*若当前元素不为零且其下方元素为零，两元素交换*/
				__GAME.matrix[coord + __GAME.order] = __GAME.matrix[coord];
				__GAME.matrix[coord] = 0;

				if (i != __GAME.order - 2)  /*每交换一次元素行标自增，以应付同一元素需要多次交换的情况*/
					i = i + 2;
			}
		}
	}
}

/***************************************************************************
  函数名称：add_down
  功    能：往下方合成数字
  输入参数：无
  返 回 值：无
  说    明：1、每一行有多种合成情况时，从下到上寻找到的第一组相同数进行合成
			2、不使用新合成的数再次合成
			3、合成的同时，按新合成的数值计分
***************************************************************************/
void add_down()
{
	int i, j;

	for (j = 0; j < __GAME.order; j++) {
		for (i = __GAME.order - 2; i >= 0; i--) {
			int coord = __GAME.order * i + j;  /*将行标和列标转换为一维坐标*/

			if (__GAME.matrix[coord] == __GAME.matrix[coord + __GAME.order] && __GAME.matrix[coord] != 0) {  /*若当前元素不为零且等于其下方元素，两元素堆叠至下方*/
				__GAME.matrix[coord + __GAME.order] = __GAME.matrix[coord + __GAME.order] * 2;
				__GAME.matrix[coord] = 0;
				__GAME.score = __GAME.score + __GAME.matrix[coord + __GAME.order];  /*按新合成的数值统计得分*/
			}
		}
	}
}

/***************************************************************************
  函数名称：act_down
  功    能：按一次方向下键的操作
  输入参数：无
  返 回 值：无
  说    明：先堆积，后合成计分，再堆积
***************************************************************************/
void act_down()
{
	move_down();     /*一次堆叠*/
	add_down();      /*向下合成*/
	move_down();     /*二次堆叠*/
	__GAME.stepnumber++;  /*步数自增*/
	__GAME.gameboard.block_multiple_print();  /*重画色块*/
	__GAME.gameboard.update_info();  /*更新信息*/
}

/***************************************************************************
  函数名称：matrix_getmax
  功    能：取数组中所有元素的最大数值
  输入参数：无
  返 回 值：int：最大数值
  说    明：无
***************************************************************************/
int matrix_getmax()
{
	int i, max = 0;  /*返回值先置为0*/

	for (i = 0; i < __GAME.order * __GAME.order; i++) {
		if (max < __GAME.matrix[i])  /*若当前元素的数值大于max当前值，将该数值赋给max*/
			max = __GAME.matrix[i];
	}

	return max;
}

/***************************************************************************
  函数名称：matrix_getmin
  功    能：取数组中所有元素的最小数值
  输入参数：无
  返 回 值：int：最小数值
  说    明：本函数取的是数组中非零元素的最小值
***************************************************************************/
int matrix_getmin()
{
	int i, count = 0;
	int matrix[ORDER_MAX * ORDER_MAX];  /*存放非零元素的数组*/

	for (i = 0; i < ORDER_MAX * ORDER_MAX; i++)  /*元素全部置零*/
		matrix[i] = 0;

	for (i = 0; i < __GAME.order * __GAME.order; i++) {  /*从内部数组中找出所有非零元素，存放到matrix[]中*/
		if (__GAME.matrix[i])
			matrix[count] = __GAME.matrix[i], count++;
	}

	int min = matrix[0];  /*返回值先置为寻找到的非零元素的第一个*/

	for (i = 0; i < count; i++) {
		if (min > matrix[i])  /*若matrix[]当前元素的数值小于min当前值，将该数值赋给min*/
			min = matrix[i];
	}

	return min;
}

/***************************************************************************
  函数名称：summon_two
  功    能：在面板上有空的位置随机生成一个2
  输入参数：无
  返 回 值：无
  说    明：在伪图形界面上，2的生成通过色块闪烁来显示
***************************************************************************/
void summon_two()
{
	int zeros[ORDER_MAX * ORDER_MAX], * p = zeros;  /*存放__GAME.matrix[]中为零元素一维坐标的数组，p指向首地址*/

	/*检查M__GAME.matrix[]中有无零元素，若有则将其一维坐标存入指针当前对应位置，p往下移动*/
	for (int i = 0; i < __GAME.order * __GAME.order; i++) {
		if (!__GAME.matrix[i])
			*p = i, p++;
	}

	const int zeros_num = p - zeros;        /*零元素的个数*/
	const int random = rand() % zeros_num;  /*生成一个0到zeros_num-1之间的随机数*/
	__GAME.matrix[zeros[random]] = 2;              /*根据随机数从zeros[]中取得对应的一维坐标zeros[random]，再用该坐标将__GAME.matrix[]中对应零元素赋上2*/

	if (__GAME.if_blink)
		__GAME.gameboard.blink_block(zeros[random]);     /*对应位置色块闪烁*/
}

/***************************************************************************
  函数名称：matrix_single_scan
  功    能：检查数组元素coord上下左右四个元素的情况，并做相应处理
  输入参数：matrix m[]：内部数组转换而来的结构体数组
			const int coord：内部数组中对应元素的一维坐标（只读）
  返 回 值：无
  说    明：相应处理为：若上下左右四个元素中存在与目标元素数值相同的元素，则在结构体数组中将其标记
***************************************************************************/
void matrix_single_scan(matrix m[], const int coord)
{
	if (m[coord].mark) {  /*只有在目标元素也被标记的情况下才开始检查*/
		const int J = coord % __GAME.order;        /*将一维坐标转换为列标*/
		const int I = (coord - J) / __GAME.order;  /*将一维坐标转换为行标*/

		if (I) {  /*若目标元素不在第一列，检查其上面一个元素*/
			if (m[coord].num == m[coord - __GAME.order].num)
				m[coord - __GAME.order].mark = 1;
		}

		if (J) {  /*若目标元素不在第一行，检查其左边一个元素*/
			if (m[coord].num == m[coord - 1].num)
				m[coord - 1].mark = 1;
		}

		if (I < __GAME.order - 1) {  /*若目标元素不在最后一行，检查其下面一个元素*/
			if (m[coord].num == m[coord + __GAME.order].num)
				m[coord + __GAME.order].mark = 1;
		}

		if (J < __GAME.order - 1) {  /*若目标元素不在最后一列，检查其右边一个元素*/
			if (m[coord].num == m[coord + 1].num)
				m[coord + 1].mark = 1;
		}
	}
}

/***************************************************************************
  函数名称：matrix_mark_count
  功    能：统计结构体数组中已标记的元素个数
  输入参数：matrix m[]：内部数组转换而来的结构体数组
  返 回 值：int：已标记的元素个数
  说    明：无
***************************************************************************/
int matrix_mark_count(matrix m[])
{
	int i, count = 0;

	for (i = 0; i < __GAME.order * __GAME.order; i++) {
		if (m[i].mark)  /*若已被标记，计数变量自增*/
			count++;
	}

	return count;
}

/***************************************************************************
  函数名称：matrix_mark_set
  功    能：去除结构体数组中所有元素的标记
  输入参数：matrix m[]：内部数组转换而来的结构体数组
  返 回 值：无
  说    明：无
***************************************************************************/
void matrix_mark_set(matrix m[])
{
	int i;  /*计数变量*/
	for (i = 0; i < __GAME.order * __GAME.order; i++) {
		m[i].mark = 0;  /*元素标记状态为0*/
	}
}

/***************************************************************************
  函数名称：if_end
  功    能：根据当前数组值，判断游戏是否结束
  输入参数：无
  返 回 值：bool：游戏是否结束（结束返回true，未结束返回false）
  说    明：无
***************************************************************************/
bool if_end()
{
	int i, count = 0;  /*count为统计周围无相同值元素数量的变量*/
	matrix m[ORDER_MAX * ORDER_MAX];  /*检查用的结构体数组*/

	/*将内部数组中的数值复制到结构体数组中，同时所有元素设为未标记状态*/
	for (i = 0; i < __GAME.order * __GAME.order; i++) {
		m[i].num = __GAME.matrix[i];
		m[i].mark = 0;
	}

	for (i = 0; i < __GAME.order * __GAME.order; i++) {
		m[i].mark = 1;  /*标记当前元素*/
		matrix_single_scan(m, i);    /*检查该元素周围有无相同值*/

		if (matrix_mark_count(m) == 1)  /*若整个数组被标记元素数量仍为1，说明该元素周围无相同值*/
			count++;  /*计数器自增*/

		matrix_mark_set(m);  /*重设所有元素的标记情况*/
	}

	if (count == __GAME.order * __GAME.order && if_full() == true)
		return true;   /*若周围无相同值元素数量=阶数的平方，且所有元素都不为零，说明所有元素都不可合成，游戏结束*/
	else
		return false;  /*若不等，说明仍有元素可以合成，游戏继续*/
}

/***************************************************************************
  函数名称：if_full
  功    能：根据当前数组值，判断所有元素是否都不为零
  输入参数：无
  返 回 值：bool：元素是否都不为零（结束返回true，未结束返回false）
  说    明：无
***************************************************************************/
bool if_full()
{
	int i, count = 0;

	for (i = 0; i < __GAME.order * __GAME.order; i++) {
		if (__GAME.matrix[i])  /*若遇到不为零元素，计数变量自增*/
			count++;
	}

	if (count == __GAME.order * __GAME.order)
		return true;   /*若不为零元素个数=阶数的平方，说明所有元素都不为零*/
	else
		return false;  /*若不等，说明仍有元素不为零*/
}