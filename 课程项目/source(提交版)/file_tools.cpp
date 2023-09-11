#include<iostream>
#include"colorball.h"
#include"ball.h"
#include"player.h"

/***************************************************************************
  �������ƣ�num_trans_char
  ��    �ܣ�����һ��0-15���������ض�Ӧʮ�����Ʊ�ʾ���ַ�
  ���������const int num�����������ֻ����
  �� �� ֵ��char�����ص��ַ�
  ˵    �����ú�����Ϊ�˴浵ʱ��������ɫ��������һ���ַ��洢
***************************************************************************/
char file_tools::num_trans_char(const int num)
{
	if (num >= 0 && num <= 9)
		return num + '0';
	else
		return num - 10 + 'A';
}

/***************************************************************************
  �������ƣ�char_trans_num
  ��    �ܣ�����һ��ʮ�����Ʊ�ʾ���ַ������ض�Ӧ����
  ���������const char ch��������ַ���ֻ����
  �� �� ֵ��int�����ص���ɫ
  ˵    �����ú�����Ϊ�˶���ʱ��һ���Զ�ȡһ���ַ���ʾ����ɫ
***************************************************************************/
int file_tools::char_trans_num(const char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	else
		return ch - 'A' + 10;
}

/***************************************************************************
  �������ƣ�file_save
  ��    �ܣ�����Ϸ���浽�ļ���
  ���������const player& client����Ҷ���ֻ����
            const ball b[]����Ϸ�ڲ��Ķ������飨ֻ����
            const int save_slot���浵λ�ã�ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void file_tools::file_save(const player& client, const ball b[], const int save_slot)
{
	filename[4] = save_slot + '0';  /*���ݴ浵λ��ȷ���ļ���*/

	writer.open(filename, ios::out | ios::binary);  /*�����ļ������ļ�������ʧ������ʾ�����*/
	if (!writer) {
		cout << "�浵" << filename << "��ʧ�ܣ�";
		return;
	}

	writer << "SCORE:" << client.score << endl                       /*д��÷�*/
		<< "COLORS:" << num_trans_char(client.next_color[0]) << ' '  /*д����������ɫ*/
		<< num_trans_char(client.next_color[1]) << ' '
		<< num_trans_char(client.next_color[2]) << ' ' << endl
		<< "MATRIX:" << endl;  /*д���ڲ�����*/

	for (int i = 0; i < 81; i++) {
		if (ball::if_ball[i])  /*����λ�������ӣ�д���ַ���ʾ����ɫ*/
			writer << num_trans_char(b[i].color);
		else  /*����λ�������ӣ�д��һ���ո�*/
			writer << ' ';
		
		if (i % 9 == 8)  /*һ��д��9��Ԫ�غ���*/
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
bool file_tools::if_file_deleted(const int save_slot)
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
  ���������player& client����Ҷ���
            ball b[]����Ϸ�ڲ��Ķ�������
            const int save_slot���浵λ�ã�ֻ����
  �� �� ֵ����
  ˵    ������
***************************************************************************/
void file_tools::file_load(player& client, ball b[], const int save_slot)
{
	filename[4] = save_slot + '0';  /*���ݴ浵λ��ȷ���ļ���*/

	reader.open(filename, ios::in | ios::_Nocreate);  /*�����ļ������ļ�������ʧ������ʾ��Ȼ�󷵻ؼٲ�����*/
	if (!reader) {
		cout << "�浵" << filename << "��ʧ�ܣ�";
		return;
	}

	int count = 0;  /*�ļ�ָ���λ��*/
	char score[10], * ps = score;   /*��ŵ÷���ֵ���ַ����飬psָ�����׵�ַ*/

	/*1����ȡ�÷�*/
	count = count + 6;
	reader.seekg(count, ios::beg);
	client.score = 0;  /*��ȡǰ���㣬�����ζ�ȡ�����ۼ�*/

	while (reader.peek() != EOF && reader.peek() != '\n') {  /*�÷ֲ�ֹһλ����Ҫ��δ�������������з�������²��϶�ȡ*/
		*ps = reader.peek();
		ps++, count++;
		reader.seekg(count, ios::beg);
	}

	for (int i = 0; i < ps - score; i++)  /*��ÿһλ��ȡ�����ַ�ȫ��ת��Ϊ��ֵ�÷�*/
		client.score += (score[i] - '0') * power(10, ps - score - i - 1);

	/*2����ȡ��һ��ɫ*/
	count = count + 8;
	reader.seekg(count, ios::beg);

	for (int i = 0; i < 3; i++) {  /*ÿ�ζ�ȡ��ʾ��ɫ���ַ��������ļ�ָ����ǰ�ƶ�2����λ*/
		client.next_color[i] = char_trans_num(reader.peek());
		count = count + 2;
		reader.seekg(count, ios::beg);
	}

	/*3����ȡ�ڲ�����*/
	count = count + 9;
	reader.seekg(count, ios::beg);

	for (int i = 0; i < 81; i++) {
		const int J = i % 9;        /*��һά����ת��Ϊ�б�*/
		const int I = (i - J) / 9;  /*��һά����ת��Ϊ�б�*/

		char c[2];  /*ÿ�ζ�ȡ�����ַ�*/
		c[0] = reader.peek();
		count++;
		reader.seekg(count, ios::beg);
		c[1] = reader.peek();

		if (c[0] >= '0' && c[0] <= '9' || c[0] >= 'A' && 'F') {  /*����һ���ַ��Ǳ�ʾ��ɫ���ַ�����˵����λ�������ӣ����ж�ȡ*/
			b[i].set(J, I, char_trans_num(c[0]));  /*���õ�ǰλ�����ӵĸ�����Ϣ*/
			ball::if_ball[i] = true;  /*��ǰλ�õı�־��Ϊ��*/
			count++;
			reader.seekg(count, ios::beg);
		}

		else if (c[0] == ' ') {  /*����һ���ַ��ǿո���˵����λ�������ӣ������ж�ȡ*/
			count++;
			reader.seekg(count, ios::beg);
			ball::if_ball[i] = false;  /*��ǰλ�õı�־��Ϊ��*/
		}

		else if (c[1] == '\n') {  /*���ڶ����ַ��ǻ��з�����˵����ȡ���˻��д����ƶ��ļ�ָ��*/
			count = count++;
			reader.seekg(count, ios::beg);
		}
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
void file_tools::file_delete(const int save_slot)
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