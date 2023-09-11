#include"90-b4.h"

/***************************************************************************
  �������ƣ�matrix_single_scan
  ��    �ܣ��������Ԫ��coord��Χ�˸�Ԫ�ص������������Ӧ����
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
            const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int coord���ڲ������ж�ӦԪ�ص�һά���ֻ꣨����
  �� �� ֵ����
  ˵    ������Ӧ����Ϊ������Χ�˸�Ԫ���д����ף���ǰ���Ԫ������
***************************************************************************/
void matrix_single_scan(matrix MATRIX[], const int line, const int row, const int coord)
{
	if (MATRIX[coord].num != '*') {  /*ֻ����Ŀ��Ԫ�ز����׵�����²ſ�ʼ���*/
		const int J = coord % row;        /*��һά����ת��Ϊ�б�*/
		const int I = (coord - J) / row;  /*��һά����ת��Ϊ�б�*/

		if (I) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У����������һ��Ԫ��*/
			if (MATRIX[coord - row].num == '*')
				MATRIX[coord].num++;
		}

		if (J) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У���������һ��Ԫ��*/
			if (MATRIX[coord - 1].num == '*')
				MATRIX[coord].num++;
		}

		if (I < line - 1) {  /*��Ŀ��Ԫ�ز������һ�У����������һ��Ԫ��*/
			if (MATRIX[coord + row].num == '*')
				MATRIX[coord].num++;
		}

		if (J < row - 1) {  /*��Ŀ��Ԫ�ز������һ�У�������ұ�һ��Ԫ��*/
			if (MATRIX[coord + 1].num == '*')
				MATRIX[coord].num++;
		}

		if (I && J) {  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
			if (MATRIX[coord - row - 1].num == '*')
				MATRIX[coord].num++;
		}

		if (I && J < row - 1) {  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
			if (MATRIX[coord - row + 1].num == '*')
				MATRIX[coord].num++;
		}

		if (I < line - 1 && J) {  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
			if (MATRIX[coord + row - 1].num == '*')
				MATRIX[coord].num++;
		}

		if (I < line - 1 && J < row - 1) {  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
			if (MATRIX[coord + row + 1].num == '*')
				MATRIX[coord].num++;
		}
	}
}

/***************************************************************************
  �������ƣ�zero_check1
  ��    �ܣ�����Ԫ����Χ�˸�Ԫ���е���Ԫ�ر��
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int coord���ڲ������ж�ӦԪ�ص�һά���ֻ꣨����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void zero_check1(matrix MATRIX[], const int line, const int row, const int coord)
{
	if (MATRIX[coord].num == '0' && MATRIX[coord].mark == true) {  /*ֻ����Ŀ��Ԫ��Ϊ��Ԫ���ұ���ǵ�����²ſ�ʼ���*/
		const int J = coord % row;        /*��һά����ת��Ϊ�б�*/
		const int I = (coord - J) / row;  /*��һά����ת��Ϊ�б�*/

		if (I) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У����������һ��Ԫ��*/
			if (MATRIX[coord - row].num == '0')
				MATRIX[coord - row].mark = true;
		}

		if (J) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У���������һ��Ԫ��*/
			if (MATRIX[coord - 1].num == '0')
				MATRIX[coord - 1].mark = true;
		}

		if (I < line - 1) {  /*��Ŀ��Ԫ�ز������һ�У����������һ��Ԫ��*/
			if (MATRIX[coord + row].num == '0')
				MATRIX[coord + row].mark = true;
		}

		if (J < row - 1) {  /*��Ŀ��Ԫ�ز������һ�У�������ұ�һ��Ԫ��*/
			if (MATRIX[coord + 1].num == '0')
				MATRIX[coord + 1].mark = true;
		}

		if (I && J) {  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
			if (MATRIX[coord - row - 1].num == '0')
				MATRIX[coord - row - 1].mark = true;
		}

		if (I && J < row - 1) {  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
			if (MATRIX[coord - row + 1].num == '0')
				MATRIX[coord - row + 1].mark = true;
		}

		if (I < line - 1 && J) {  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
			if (MATRIX[coord + row - 1].num == '0')
				MATRIX[coord + row - 1].mark = true;
		}

		if (I < line - 1 && J < row - 1) {  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
			if (MATRIX[coord + row + 1].num == '0')
				MATRIX[coord + row + 1].mark = true;
		}
	}
}

/***************************************************************************
  �������ƣ�zero_check2
  ��    �ܣ������б���ǵ���Ԫ�ص���Χ�˸�Ԫ��ȫ�����
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int coord���ڲ������ж�ӦԪ�ص�һά���ֻ꣨����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void zero_check2(matrix MATRIX[], const int line, const int row, const int coord)
{
	if (MATRIX[coord].num == '0' && MATRIX[coord].mark == true) {  /*ֻ����Ŀ��Ԫ��Ϊ��Ԫ���ұ���ǵ�����²ſ�ʼ���*/
		const int J = coord % row;        /*��һά����ת��Ϊ�б�*/
		const int I = (coord - J) / row;  /*��һά����ת��Ϊ�б�*/

		if (I)  /*��Ŀ��Ԫ�ز��ڵ�һ�У����������һ��Ԫ��*/
				MATRIX[coord - row].mark = true;

		if (J)  /*��Ŀ��Ԫ�ز��ڵ�һ�У���������һ��Ԫ��*/
				MATRIX[coord - 1].mark = true;

		if (I < line - 1)  /*��Ŀ��Ԫ�ز������һ�У����������һ��Ԫ��*/
				MATRIX[coord + row].mark = true;

		if (J < row - 1)  /*��Ŀ��Ԫ�ز������һ�У�������ұ�һ��Ԫ��*/
				MATRIX[coord + 1].mark = true;

		if (I && J)  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
				MATRIX[coord - row - 1].mark = true;

		if (I && J < row - 1)  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
				MATRIX[coord - row + 1].mark = true;

		if (I < line - 1 && J)  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
				MATRIX[coord + row - 1].mark = true;

		if (I < line - 1 && J < row - 1)  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
				MATRIX[coord + row + 1].mark = true;
	}
}

/***************************************************************************
  �������ƣ�flag_check
  ��    �ܣ�ͳ������Ԫ��coord��Χ�˸�Ԫ�صĲ�������
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int coord���ڲ������ж�ӦԪ�ص�һά���ֻ꣨����
  �� �� ֵ��int����Χ�˸�Ԫ�����ж���Ԫ���ѱ�����
  ˵    ������
***************************************************************************/
int flag_check(const matrix MATRIX[], const int line, const int row, const int coord)
{
	const int J = coord % row;        /*��һά����ת��Ϊ�б�*/
	const int I = (coord - J) / row;  /*��һά����ת��Ϊ�б�*/
	int ret = 0;  /*����ֵ*/

	if (I) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У����������һ��Ԫ��*/
		if (MATRIX[coord - row].if_flag)
			ret++;
	}

	if (J) {  /*��Ŀ��Ԫ�ز��ڵ�һ�У���������һ��Ԫ��*/
		if (MATRIX[coord - 1].if_flag)
			ret++;
	}

	if (I < line - 1) {  /*��Ŀ��Ԫ�ز������һ�У����������һ��Ԫ��*/
		if (MATRIX[coord + row].if_flag)
			ret++;
	}

	if (J < row - 1) {  /*��Ŀ��Ԫ�ز������һ�У�������ұ�һ��Ԫ��*/
		if (MATRIX[coord + 1].if_flag)
			ret++;
	}

	if (I && J) {  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
		if (MATRIX[coord - row - 1].if_flag)
			ret++;
	}

	if (I && J < row - 1) {  /*���Ŀ��Ԫ�����Ͻǵ�Ԫ��*/
		if (MATRIX[coord - row + 1].if_flag)
			ret++;
	}

	if (I < line - 1 && J) {  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
		if (MATRIX[coord + row - 1].if_flag)
			ret++;
	}

	if (I < line - 1 && J < row - 1) {  /*���Ŀ��Ԫ�����½ǵ�Ԫ��*/
		if (MATRIX[coord + row + 1].if_flag)
			ret++;
	}

	return ret;
}

/***************************************************************************
  �������ƣ�matrix_copy
  ��    �ܣ����ṹ������src[]���Ƶ��ṹ������dst[]��
  ���������matrix dst[]�������ƵĽṹ������
            const matrix src[]����Դ�ṹ�����飨ֻ����
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void matrix_copy(matrix dst[], const matrix src[], const int line, const int row)
{
	for (int i = 0; i < line * row; i++) {
		dst[i].num = src[i].num;                /*������ֵ*/
		dst[i].mark = src[i].mark;              /*����һ���ñ��*/
		dst[i].coord_mark = src[i].coord_mark;  /*����������*/
		dst[i].if_flag = src[i].if_flag;        /*���Ʋ������*/
		dst[i].if_turned = src[i].if_turned;    /*���Ʒ������*/
	}
}

/***************************************************************************
  �������ƣ�matrix_compare
  ��    �ܣ��Ƚ����ṹ������m1[]��m2[]
  ���������const matrix m1[]�����ȽϵĽṹ������1��ֻ����
			const matrix m2[]�����ȽϵĽṹ������2��ֻ����
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
  �� �� ֵ��bool�����ṹ�������Ƿ���ȫ���
  ˵    ������
***************************************************************************/
bool matrix_compare(const matrix m1[], const matrix m2[], const int line, const int row)
{
	bool ret = true;  /*����ֵ������Ϊ��*/

	for (int i = 0; i < line * row; i++) {  /*���Ԫ�ؽ��бȽϣ���������һ���Աֵ���ȣ�����ֵ��Ϊ�ٲ��������*/
		if (m1[i].num != m2[i].num) {  /*�Ƚ���ֵ*/
			ret = false;
			break;
		}

		if (m1[i].mark != m2[i].mark) {  /*�Ƚ�һ���ñ��*/
			ret = false;
			break;
		}

		if (m1[i].coord_mark != m2[i].coord_mark) {  /*�Ƚ�������*/
			ret = false;
			break;
		}

		if (m1[i].if_flag != m2[i].if_flag) {  /*�Ƚϲ������*/
			ret = false;
			break;
		}

		if (m1[i].if_turned != m2[i].if_turned) {  /*�ȽϷ������*/
			ret = false;
			break;
		}
	}

	return ret;
}

/***************************************************************************
  �������ƣ�matrix_initialize
  ��    �ܣ����ڲ��ṹ��������ֵ��ʼ��
  ���������matrix MATRIX[]��������Ϸ���ڲ��ṹ������
			const int line����Ϸ������ֻ����
			const int row����Ϸ������ֻ����
			const int bomb_num����������ֻ����
			const int first_x����һ�ε��λ�ú����ֻ꣨����
			const int first_y����һ�ε��λ�������ֻ꣨����
  �� �� ֵ����
  ˵    ����1���������������׺���ֵ�ĳ�ʼ��
            2���ѱ�֤ÿ����Ϸ�ĵ�һ�ε��λ�ö�Ϊ0������ΧһȦ��û���ף�
			3��������δ���������ݳ�Ա����һ���ǵȣ��ĳ�ʼ��
***************************************************************************/
void matrix_initialize(matrix MATRIX[], const int line, const int row, const int bomb_num, const int first_x, const int first_y)
{
	const int first_coord = first_y * row + first_x;  /*����һ�ε��λ�ú�������ת��Ϊһά����*/

	/*1�������ʼ����������Ԫ�س�ʼ��Ϊ�ַ�'0'*/
	for (int i = 0; i < line * row; i++)
		MATRIX[i].num = '0';

	/*2�����ף�ÿ�����ȡ��һ�����꣬���������ϵ�Ԫ�ر�Ϊ'*'�������������Ѿ����ף���i�Լ�������ȡ�����꣬��֤ʵ�ʵ������㹻*/
	for (int i = 0; i < bomb_num; i++) {
		int coord = rand() % (line * row);  /*ȡһά�������*/
		const int J = coord % row;          /*��һά����ת��Ϊ�б�*/
		const int I = (coord - J) / row;    /*��һά����ת��Ϊ�б�*/

		/*�����������Ԫ��Ϊ�ף�����λ��Ϊ��һ�ε��λ�ü�����ΧһȦ������������Լ�*/
		if (MATRIX[coord].num == '*' || (I >= first_y - 1 && I <= first_y + 1 && J >= first_x - 1 && J <= first_x + 1))
			i--;

		else
			MATRIX[coord].num = '*';
	}

	/*3����������Ԫ�ص���ֵ��ʼ��*/
	for (int i = 0; i < line * row; i++)
		matrix_single_scan(MATRIX, line, row, i);
}