#include"90-b4.h"

/***************************************************************************
  �������ƣ�unturned_check
  ��    �ܣ�ͳ������Ԫ��coord��Χ�˸�Ԫ�ص�δ����Ԫ������
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int coord���ڲ������ж�ӦԪ�ص�һά���ֻ꣨����
  �� �� ֵ��int����Χ�˸�Ԫ�����ж���Ԫ��δ������
  ˵    ������
***************************************************************************/
int unturned_check(const matrix MATRIX[], const int line, const int row, const int coord)
{
	const int J = coord % row;        /*��һά����ת��Ϊ�б�*/
	const int I = (coord - J) / row;  /*��һά����ת��Ϊ�б�*/
	int ret = 0;  /*����ֵ*/

	if (I) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У����������һ��Ԫ��*/
		if (!MATRIX[coord - row].if_turned)
			ret++;
	}

	if (J) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У���������һ��Ԫ��*/
		if (!MATRIX[coord - 1].if_turned)
			ret++;
	}

	if (I < line - 1) {  /*��Ŀ��Ԫ�ز������һ�У����������һ��Ԫ��*/
		if (!MATRIX[coord + row].if_turned)
			ret++;
	}

	if (J < row - 1) {  /*��Ŀ��Ԫ�ز������һ�У�������ұ�һ��Ԫ��*/
		if (!MATRIX[coord + 1].if_turned)
			ret++;
	}

	if (I && J) {  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
		if (!MATRIX[coord - row - 1].if_turned)
			ret++;
	}

	if (I && J < row - 1) {  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
		if (!MATRIX[coord - row + 1].if_turned)
			ret++;
	}

	if (I < line - 1 && J) {  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
		if (!MATRIX[coord + row - 1].if_turned)
			ret++;
	}

	if (I < line - 1 && J < row - 1) {  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
		if (!MATRIX[coord + row + 1].if_turned)
			ret++;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�wheel_click_flag
  ��    �ܣ����ư�����м�ʱ�ķ���������������Ԫ��coord��ΧһȦԪ��ȫ������
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int coord���ڲ������ж�ӦԪ�ص�һά���ֻ꣨����
			int* bomb_num��ʣ������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void wheel_click_flag(matrix MATRIX[], const int line, const int row, const int coord, int* bomb_num)
{
	const int J = coord % row;        /*��һά����ת��Ϊ�б�*/
	const int I = (coord - J) / row;  /*��һά����ת��Ϊ�б�*/

	if (I) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У����������һ��Ԫ��*/
		if (!MATRIX[coord - row].if_turned && !MATRIX[coord - row].if_flag)
			flag(MATRIX, line, row, coord - row, bomb_num, PLACE_FLAG);
	}

	if (J) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У���������һ��Ԫ��*/
		if (!MATRIX[coord - 1].if_turned && !MATRIX[coord - 1].if_flag)
			flag(MATRIX, line, row, coord - 1, bomb_num, PLACE_FLAG);
	}

	if (I < line - 1) {  /*��Ŀ��Ԫ�ز������һ�У����������һ��Ԫ��*/
		if (!MATRIX[coord + row].if_turned && !MATRIX[coord + row].if_flag)
			flag(MATRIX, line, row, coord + row, bomb_num, PLACE_FLAG);
	}

	if (J < row - 1) {  /*��Ŀ��Ԫ�ز������һ�У�������ұ�һ��Ԫ��*/
		if (!MATRIX[coord + 1].if_turned && !MATRIX[coord + 1].if_flag)
			flag(MATRIX, line, row, coord + 1, bomb_num, PLACE_FLAG);
	}

	if (I && J) {  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
		if (!MATRIX[coord - row - 1].if_turned && !MATRIX[coord - row - 1].if_flag)
			flag(MATRIX, line, row, coord - row - 1, bomb_num, PLACE_FLAG);
	}

	if (I && J < row - 1) {  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
		if (!MATRIX[coord - row + 1].if_turned && !MATRIX[coord - row + 1].if_flag)
			flag(MATRIX, line, row, coord - row + 1, bomb_num, PLACE_FLAG);
	}

	if (I < line - 1 && J) {  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
		if (!MATRIX[coord + row - 1].if_turned && !MATRIX[coord + row - 1].if_flag)
			flag(MATRIX, line, row, coord + row - 1, bomb_num, PLACE_FLAG);
	}

	if (I < line - 1 && J < row - 1) {  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
		if (!MATRIX[coord + row + 1].if_turned && !MATRIX[coord + row + 1].if_flag)
			flag(MATRIX, line, row, coord + row + 1, bomb_num, PLACE_FLAG);
	}
}

/***************************************************************************
  �������ƣ�ai_control
  ��    �ܣ������Զ������
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			int* bomb_num��ʣ������
			bool* if_initialized���Ƿ��ʼ��
  �� �� ֵ��int���������
  ˵    ������
***************************************************************************/
int ai_control(matrix MATRIX[], const int line, const int row, int* bomb_num, bool* if_initialized)
{
	matrix m[LINE_MAX * ROW_MAX];  /*���ҽ��õĽṹ������*/
	int RET1 = 0, RET2 = 0;        /*�������������ķ���ֵ�������ķ���ֵ��������Ϊ0*/
	int loop = 1;

	if (!*if_initialized) {  /*������δ��ʼ�������ʼ�����������һ��Ԫ��*/
		const int coord = rand() % (line * row);  /*���ѡȡ����*/
		const int J = coord % row;                /*��һά����ת��Ϊ�б�*/
		const int I = (coord - J) / row;          /*��һά����ת��Ϊ�б�*/

		matrix_initialize(MATRIX, line, row, *bomb_num, J, I);  /*��ʼ������*/
		*if_initialized = true;  /*��ʼ��״̬��Ϊ��*/

		MATRIX[coord].mark = true;
		turn(MATRIX, line, row, coord);
	}

	while (!matrix_compare(m, MATRIX, line, row) && loop) {  /*��������״̬�£�ֻ���ڲ���������δ�����仯��ֹͣ����*/
		matrix_copy(m, MATRIX, line, row);

		for (int i = 0; i < line * row; i++) {  /*����Ԫ���ѱ���������ֵ��Ϊ�㡢��Χδ����Ԫ�������պõ�������ֵ�ģ�������Χ������*/
			if (MATRIX[i].if_turned && MATRIX[i].num && unturned_check(MATRIX, line, row, i) == MATRIX[i].num - '0')
				wheel_click_flag(MATRIX, line, row, i, bomb_num);
		}

		for (int i = 0; i < line * row; i++) {
			if (MATRIX[i].if_turned && MATRIX[i].num)  /*����һ�ֲ��������Ԫ���ѱ���������ֵ��Ϊ�㣬�ڸ�Ԫ����ִ�й��ַ�������*/
				RET1 = wheel_click_turn(MATRIX, line, row, i);

			if (RET1) {  /*�����������������ף����ú�������ֵ���������*/
				RET2 = RET1;
				loop = 0;
				break;
			}
		}
	}

	return RET2;
}