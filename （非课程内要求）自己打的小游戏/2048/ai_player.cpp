#include"90-b3.h"

/***************************************************************************
  �������ƣ�matrix_copy
  ��    �ܣ�����Ϸ�ڲ����鸴�Ƶ�˽�г�Ա������
  �����������
  �� �� ֵ����
  ˵    �����ú�����Ϊ˽�г�Ա��ֵ
***************************************************************************/
void ai_player::matrix_copy()
{
	for (int i = 0; i < __GAME.order * __GAME.order; i++)
		matrix[i] = __GAME.matrix[i];
}

/***************************************************************************
  �������ƣ�two_order
  ��    �ܣ�����һ������2�ļ��η�
  ���������int initial_num����������
  �� �� ֵ��int��������2�ļ��η�
  ˵    ����1���ú�����Ϊ˽�г�Ա��ֵ
            2���ú���ֻ����0��2�Ĵη���
***************************************************************************/
int ai_player::two_order(int initial_num)
{
	int ret = 0;  /*����ֵ������Ϊ0*/

	if (initial_num == 0)  /*������Ϊ0������-1*/
		ret = -1;
	else {
		while (initial_num != 1) {  /*��������*/
			initial_num = initial_num / 2;
			ret++;
		}
	}

	return ret;
}

/***************************************************************************
  �������ƣ�matrix_trans
  ��    �ܣ���˽�г�Ա����ת�����Ա�Ѱ�����Ž�
  �����������
  �� �� ֵ����
  ˵    ����1���ú����ɸı�˽�г�Ա��ֵ
			2���ú�����ÿ��Ԫ��ת��Ϊ2�Ĵη������磺8ת��Ϊ3��
***************************************************************************/
void ai_player::matrix_trans()
{
	for (int i = 0; i < __GAME.order * __GAME.order; i++)
		matrix[i] = two_order(matrix[i]);
}

/***************************************************************************
  �������ƣ�check_up
  ��    �ܣ����ĳ��λ�õ�Ԫ���ܷ�ͨ�����Ϻϳ�����
  ���������const int line��������ֻ����
            const int row��������ֻ����
			const int num��Ԫ����ֵ��ֻ����
  �� �� ֵ����
  ˵    ����ֻҪ�Ӹ�λ�����Ͽ��������ĵ�һ�������������䱾�������ҵ�
***************************************************************************/
bool ai_player::check_up(const int line, const int row, const int num)
{
	if (!line || !num)  /*�������ڵ�һ�л�Ϊ�㣬���ؼ�*/
		return false;
	else {
		const int coord = line * __GAME.order + row;  /*���б���б�ת��Ϊһά����*/
		int count = 0;  /*��������*/

		while (count < line) {  /*����һ����Ѱ�ң�ֱ������������*/
			if (matrix[coord - (count + 1) * __GAME.order])
				break;
			else
				count++;
		}

		if (count == line)  /*��������������һ��ֵ����˵�������Ϸ�ȫΪ�㣬���ؼ�*/
			return false;
		else {
			if (matrix[coord - (count + 1) * __GAME.order] == matrix[coord])  /*�������Ϸ���һ�������������䱾���򷵻���*/
				return true;
			else  /*�������Ϸ���һ���������������䱾������Ȼ���ؼ�*/
				return false;
		}
	}
}

/***************************************************************************
  �������ƣ�check_down
  ��    �ܣ����ĳ��λ�õ�Ԫ���ܷ�ͨ�����ºϳ�����
  ���������const int line��������ֻ����
			const int row��������ֻ����
			const int num��Ԫ����ֵ��ֻ����
  �� �� ֵ����
  ˵    ����ֻҪ�Ӹ�λ�����¿��������ĵ�һ�������������䱾�������ҵ�
***************************************************************************/
bool ai_player::check_down(const int line, const int row, const int num)
{
	if (line == __GAME.order - 1 || !num)  /*�����������һ�л�Ϊ�㣬���ؼ�*/
		return false;
	else {
		const int coord = line * __GAME.order + row;  /*���б���б�ת��Ϊһά����*/
		int count = 0;  /*��������*/

		while (count < __GAME.order - 1 - line) {  /*����һ����Ѱ�ң�ֱ������������*/
			if (matrix[coord + (count + 1) * __GAME.order])
				break;
			else
				count++;
		}

		if (count == __GAME.order - 1 - line)  /*��������������һ��ֵ����˵�������·�ȫΪ�㣬���ؼ�*/
			return false;
		else {
			if (matrix[coord + (count + 1) * __GAME.order] == matrix[coord])  /*�������·���һ�������������䱾���򷵻���*/
				return true;
			else  /*�������·���һ���������������䱾������Ȼ���ؼ�*/
				return false;
		}
	}
}

/***************************************************************************
  �������ƣ�check_left
  ��    �ܣ����ĳ��λ�õ�Ԫ���ܷ�ͨ������ϳ�����
  ���������const int line��������ֻ����
			const int row��������ֻ����
			const int num��Ԫ����ֵ��ֻ����
  �� �� ֵ����
  ˵    ����ֻҪ�Ӹ�λ�����󿴣������ĵ�һ�������������䱾�������ҵ�
***************************************************************************/
bool ai_player::check_left(const int line, const int row, const int num)
{
	if (!row || !num)  /*�������ڵ�һ�л�Ϊ�㣬���ؼ�*/
		return false;
	else {
		const int coord = line * __GAME.order + row;  /*���б���б�ת��Ϊһά����*/
		int count = 0;  /*��������*/

		while (count < row) {  /*����һ����Ѱ�ң�ֱ������������*/
			if (matrix[coord - (count + 1)])
				break;
			else
				count++;
		}

		if (count == row)  /*��������������һ��ֵ����˵���������ȫΪ�㣬���ؼ�*/
			return false;
		else {
			if (matrix[coord - (count + 1)] == matrix[coord])  /*����������һ�������������䱾���򷵻���*/
				return true;
			else  /*����������һ���������������䱾������Ȼ���ؼ�*/
				return false;
		}
	}
}

/***************************************************************************
  �������ƣ�check_right
  ��    �ܣ����ĳ��λ�õ�Ԫ���ܷ�ͨ�����Һϳ�����
  ���������const int line��������ֻ����
			const int row��������ֻ����
			const int num��Ԫ����ֵ��ֻ����
  �� �� ֵ����
  ˵    ����ֻҪ�Ӹ�λ�����ҿ��������ĵ�һ�������������䱾�������ҵ�
***************************************************************************/
bool ai_player::check_right(const int line, const int row, const int num)
{
	if (row == __GAME.order - 1 || !num)  /*�����������һ�л�Ϊ�㣬���ؼ�*/
		return false;  /*��������*/
	else {
		const int coord = line * __GAME.order + row;  /*���б���б�ת��Ϊһά����*/
		int count = 0;

		while (count < __GAME.order - 1 - row) {  /*����һ����Ѱ�ң�ֱ������������*/
			if (matrix[coord + (count + 1)])
				break;
			else
				count++;
		}

		if (count == __GAME.order - 1 - row)  /*��������������һ��ֵ����˵�������Ҳ�ȫΪ�㣬���ؼ�*/
			return false;
		else {
			if (matrix[coord + (count + 1)] == matrix[coord])  /*�������Ҳ��һ�������������䱾���򷵻���*/
				return true;
			else  /*�������Ҳ��һ���������������䱾������Ȼ���ؼ�*/
				return false;
		}
	}
}

/***************************************************************************
  �������ƣ�check_and_answer
  ��    �ܣ���鲢��������ĳ��λ�õ�Ԫ�ص����Ž�
  ���������const int line��������ֻ����
			const int row��������ֻ����
			const int num��Ԫ����ֵ��ֻ����
  �� �� ֵ����
  ˵    ����1�������ºϳ������ºϳ�
            2��1����㣬������������Һϳɣ���ϳɣ���������
			3���Ǳ�Ҫ�����Ϻϳɣ���1��2������㣬�Ȳ��ϳɵ�ǰԪ��
***************************************************************************/
int ai_player::check_and_answer(const int line, const int row, const int num)
{
	bool prime1 = check_up(line, row, num);     /*������Ϻϳ�*/
	bool prime2 = check_down(line, row, num);   /*������ºϳ�*/
	bool prime3 = check_left(line, row, num);   /*�������ϳ�*/
	bool prime4 = check_right(line, row, num);  /*������Һϳ�*/

	/*���ݺϳɽ�����ھ����жϺ�ȡ��Ӧ����ֵ*/
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
  �������ƣ�find_best_solution
  ��    �ܣ�����������飬�ҳ����Ž�
  �����������
  �� �� ֵ��int�����Ž���ƶ���ʽ
  ˵    ����1���������ϣ���һ���ܺϳɵ���С�������ȣ��������Ϻϳɣ�
            2�������е�Ԫ�ض��޷�ͨ���������Ϻϳ�����ķ�ʽ�����������Ϻϳ�
***************************************************************************/
int ai_player::find_best_solution()
{
	if (if_end())  /*����Ϸ�ѽ�����ֱ�ӷ��ؽ���*/
		return AI_SLN_END;
	else {
		matrix_copy();   /*ȡԭʼ����*/
		matrix_trans();  /*ת��˽�г�Ա���飬�������*/
		const int MAX = two_order(matrix_getmax());  /*ȡԭʼ�������ֵ��2�Ĵη���ʽ��*/
		const int MIN = two_order(matrix_getmin());  /*ȡԭʼ������Сֵ��2�Ĵη���ʽ��*/
		int i, j, k;       /*Ŀ����������������*/
		bool loop = true;  /*�Ƿ���Ҫ��������*/
		int answer = 0;    /*�����ķ���ֵ*/

		for (i = MIN; i <= MAX && loop; i++) {
			for (j = __GAME.order - 1; j >= 0 && loop; j--) {
				for (k = 0; k < __GAME.order && loop; k++) {
					const int coord = j * __GAME.order + k;  /*���б���б�ת��Ϊһά����*/

					if (matrix[coord] == i) {  /*����ǰԪ�ص���ֵ����Ŀ�������ҳ�����������Ž�*/
						answer = check_and_answer(j, k, i);
						if (answer != AI_SLN_NOMOVE)  /*�����Žⲻ�������Ϻϳɣ������ҵ���loop��Ϊ�٣���������*/
							loop = false;
					}
				}
			}
		}

		if (!loop)  /*��������ɺ�loopΪ�٣��򷵻��ҵ������Ž�*/
			return answer;
		else  /*��������ɺ�loop��Ϊ�棬������Ԫ�ض��޷�ͨ���������Ϻϳ�����ķ�ʽ�����������ºϳ�*/
			return AI_SLN_DOWN;
	}
}

/***************************************************************************
  �������ƣ�if_limit
  ��    �ܣ�����ڲ������Ƿ�Ϊ����״̬
  �����������
  �� �� ֵ��bool���Ƿ�Ϊ����״̬
  ˵    ��������״ָ̬�����ڲ�������Ԫ�ؽ���һ�������
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
  �������ƣ�auto_game
  ��    �ܣ������Զ���Ϸ
  �����������
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void ai_player::auto_game()
{
	int loop = 1, count = 0;

	while (loop) {
		int ret = find_best_solution();  /*Ѱ�����Ž�*/
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

		if (if_limit())  /*��Ϊ����״̬�������Ž�ת��Ϊ��Ӧ����*/
			ret = AI_SLN_LIMIT;

		switch (ret) {  /*�������Ž������ز���*/
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

	__GAME.game_mailbox.print(BUTTON_ONE, "�޿ɺϳ����Ϸ������");  /*�����Ի�����ʾ��Ϸ�ѽ���*/
	__GAME.game_mailbox.control();  /*������ȷ���������˳�*/
}