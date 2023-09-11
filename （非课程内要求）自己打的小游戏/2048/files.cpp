#include"90-b3.h"

/***************************************************************************
  �������ƣ�file_save
  ��    �ܣ�����Ϸ���浽�ļ���
  ���������const int save_slot���浵λ�ã�ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void files::file_save(const int save_slot)
{
	filename[4] = save_slot + '0';  /*���ݴ浵λ��ȷ���ļ���*/

	writer.open(filename, ios::out | ios::binary);  /*�����ļ������ļ�������ʧ������ʾ�����*/
	if (!writer) {
		cout << "�浵" << filename << "��ʧ�ܣ�";
		return;
	}

	writer << "ORDER:" << __GAME.order << endl         /*д��������*/
		<< "SCORE:" << __GAME.score << endl            /*д��÷�*/
		<< "STEPNUMBER:" << __GAME.stepnumber << endl  /*д�벽��*/
		<< "MATRIX:" << endl;  /*д���ڲ�����*/

	for (int i = 0; i < __GAME.order * __GAME.order; i++) {
		writer << __GAME.matrix[i];
		if (i % __GAME.order == __GAME.order - 1)  /*һ��д��__GAME.order��Ԫ�غ���*/
			writer << endl;
		else
			writer << ' ';
	}

	writer.close();  /*�ر��ļ�*/
}

/***************************************************************************
  �������ƣ�if_file_deleted
  ��    �ܣ��жϵ�ǰλ���ϵ��ļ��Ƿ����
  ���������const int save_slot���浵λ�ã�ֻ����
  �� �� ֵ��bool���浵�ļ��Ƿ�Ϊ��
  ˵    ������
***************************************************************************/
bool files::if_file_deleted(const int save_slot)
{
	filename[4] = save_slot + '0';  /*���ݴ浵λ��ȷ���ļ���*/

	reader.open(filename, ios::in);  /*�����ļ������ļ�������ʧ������ʾ��Ȼ�󷵻ؼٲ�����*/
	if (!reader) {
		cout << "�浵" << filename << "��ʧ�ܣ�";
		return false;
	}

	char STATE[13], * pS = STATE;  /*����ĵ�״̬���ַ����飬pSָ�����׵�ַ*/
	int count = 0;  /*�ļ�ָ���λ��*/
	reader.seekg(0, ios::beg);

	while (reader.peek() != EOF && pS - STATE < 12) {  /*��δ�����ļ�������������¶�ȡ�ļ���ǰ12���ַ�*/
		*pS = reader.peek();
		pS++, count++;
		reader.seekg(count, ios::beg);
	}

	*pS = '\0';      /*����β�㣬Ϊ����ʹ��strcmp*/
	reader.close();  /*�ر��ļ�*/

	if (!strcmp(STATE, "FILE_DELETED"))  /*����ȡ�����ַ�������״̬FILE_DELETED�Ƚϣ�������򷵻��棬�����򷵻ؼ�*/
		return true;
	else
		return false;
}

/***************************************************************************
  �������ƣ�file_load
  ��    �ܣ���ȡ��Ϸ�浵�ļ�
  ���������const int save_slot���浵λ�ã�ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void files::file_load(const int save_slot)
{
	filename[4] = save_slot + '0';  /*���ݴ浵λ��ȷ���ļ���*/

	reader.open(filename, ios::in);  /*�����ļ������ļ�������ʧ������ʾ��Ȼ�󷵻ؼٲ�����*/
	if (!reader) {
		cout << "�浵" << filename << "��ʧ�ܣ�";
		return;
	}

	int count = 0;  /*�ļ�ָ���λ��*/
	char score[10], * ps = score;   /*��ŵ÷���ֵ���ַ����飬psָ�����׵�ַ*/
	char stepnumber[10], * pS = stepnumber;   /*��Ų������ַ����飬psָ�����׵�ַ*/
	char matrix[5], * pm = matrix;  /*���ĳһԪ����ֵ���ַ����飬pmָ�����׵�ַ*/

	/*1����ȡ������*/
	count = count + 6;
	reader.seekg(count, ios::beg);
	__GAME.order = reader.peek() - '0';

	/*2����ȡ�÷�*/
	count = count + 8;
	reader.seekg(count, ios::beg);
	__GAME.score = 0;  /*��ȡǰ���㣬�����ζ�ȡ�����ۼ�*/

	while (reader.peek() != EOF && reader.peek() != '\n') {  /*�÷ֲ�ֹһλ����Ҫ��δ�������������з�������²��϶�ȡ*/
		*ps = reader.peek();
		ps++, count++;
		reader.seekg(count, ios::beg);
	}

	for (int i = 0; i < ps - score; i++)  /*��ÿһλ��ȡ�����ַ�ȫ��ת��Ϊ��ֵ�÷�*/
		__GAME.score = __GAME.score + (score[i] - '0') * power(10, ps - score - i - 1);

	/*3����ȡ����*/
	count = count + 12;
	reader.seekg(count, ios::beg);
	__GAME.stepnumber = 0;  /*��ȡǰ���㣬�����ζ�ȡ�����ۼ�*/

	while (reader.peek() != EOF && reader.peek() != '\n') {  /*������ֹһλ����Ҫ��δ�������������з�������²��϶�ȡ*/
		*pS = reader.peek();
		pS++, count++;
		reader.seekg(count, ios::beg);
	}

	for (int i = 0; i < pS - stepnumber; i++)  /*��ÿһλ��ȡ�����ַ�ȫ��ת��Ϊ��ֵ�÷�*/
		__GAME.stepnumber = __GAME.stepnumber + (stepnumber[i] - '0') * power(10, pS - stepnumber - i - 1);

	/*4����ȡ�ڲ�����*/
	count = count + 9;
	reader.seekg(count, ios::beg);

	int* pM = __GAME.matrix;  /*pMָ���ڲ������׵�ַ*/
	for (int i = 0; i < __GAME.order * __GAME.order; i++)  /*��ȡǰ���㣬�����ζ�ȡ�����ۼ�*/
		__GAME.matrix[i] = 0;

	while (reader.peek() != EOF) {
		while (reader.peek() != EOF && reader.peek() != '\n' && reader.peek() != ' ') {  /*Ԫ�ز�ֹһλ����Ҫ��δ�������������з�������²��϶�ȡ*/
			*pm = reader.peek();
			pm++, count++;
			reader.seekg(count, ios::beg);
		}

		if (reader.peek() == ' ' || reader.peek() == '\n') {  /*�����ո���з�����������ֱ���������ַ����ٳ���*/
			while (reader.peek() == ' ' || reader.peek() == '\n') {
				count++;
				reader.seekg(count, ios::beg);
			}
		}

		for (int i = 0; i < pm - matrix; i++)  /*��ÿһλ��ȡ�����ַ�ȫ��ת��Ϊ��ǰԪ����ֵ*/
			*pM = *pM + (matrix[i] - '0') * power(10, pm - matrix - i - 1);
		pm = matrix, pM++;  /*pm��λ��pM�����ƶ�*/
	}

	reader.close();  /*�ر��ļ�*/
}

/***************************************************************************
  �������ƣ�file_delete
  ��    �ܣ������Ϸ�浵�ļ�
  ���������const int save_slot���浵λ�ã�ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void files::file_delete(const int save_slot)
{
	filename[4] = save_slot + '0';  /*���ݴ浵λ��ȷ���ļ���*/

	writer.open(filename, ios::out | ios::binary);  /*�����ļ������ļ�������ʧ������ʾ��Ȼ�󷵻ؼٲ�����*/
	if (!writer) {
		cout << "�浵" << filename << "��ʧ�ܣ�";
		return;
	}

	writer << "FILE_DELETED";  /*д�����״̬*/
	writer.close();            /*�ر��ļ�*/
}