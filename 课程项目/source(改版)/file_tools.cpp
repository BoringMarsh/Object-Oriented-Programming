#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"colorball.h"
#include"ball.h"
#include"player.h"
#include"interface-messagebox.h"

/***************************************************************************
  函数名称：num_trans_char
  功    能：输入一个0-15的数，返回对应十六进制表示的字符
  输入参数：const int num：输入的数（只读）
  返 回 值：char：返回的字符
  说    明：该函数是为了存档时，各种颜色都可以用一个字符存储
***************************************************************************/
char file_tools::num_trans_char(const int num)
{
	if (num >= 0 && num <= 9)
		return num + '0';
	else
		return num - 10 + 'A';
}

/***************************************************************************
  函数名称：char_trans_num
  功    能：输入一个十六进制表示的字符，返回对应的数
  输入参数：const char ch：输入的字符（只读）
  返 回 值：int：返回的颜色
  说    明：该函数是为了读档时，一次性读取一个字符表示的颜色
***************************************************************************/
int file_tools::char_trans_num(const char ch)
{
	if (ch >= '0' && ch <= '9')
		return ch - '0';
	else
		return ch - 'A' + 10;
}

/***************************************************************************
  函数名称：file_save
  功    能：将游戏保存到文件中
  输入参数：const player& client：玩家对象（只读）
            const ball b[]：游戏内部的对象数组（只读）
            const int save_slot：存档位置（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void file_tools::file_save(const player& client, const ball b[], const int save_slot)
{
	filename[4] = save_slot + '0';  /*根据存档位置确定文件名*/

	writer.open(filename, ios::out | ios::binary);  /*根据文件名打开文件，若打开失败则提示后结束*/
	if (!writer) {
		cout << "存档" << filename << "打开失败！";
		return;
	}

	writer << "SCORE:" << client.score << endl                       /*写入得分*/
		<< "COLORS:" << num_trans_char(client.next_color[0]) << ' '  /*写入下三个颜色*/
		<< num_trans_char(client.next_color[1]) << ' '
		<< num_trans_char(client.next_color[2]) << ' ' << endl
		<< "MATRIX:" << endl;  /*写入内部数组*/

	for (int i = 0; i < 81; i++) {
		if (ball::if_ball[i])  /*若该位置有珠子，写入字符表示的颜色*/
			writer << num_trans_char(b[i].color);
		else  /*若该位置无珠子，写入一个空格*/
			writer << ' ';
		
		if (i % 9 == 8)  /*一行写入9个元素后换行*/
			writer << endl;
		else
			writer << ' ';
	}

	writer.close();  /*关闭文件*/
}

/***************************************************************************
  函数名称：if_file_deleted
  功    能：判断当前位置上的文件是否被清空
  输入参数：const int save_slot：存档位置（只读）
  返 回 值：bool：存档文件是否为空
  说    明：无
***************************************************************************/
bool file_tools::if_file_deleted(const int save_slot)
{
	filename[4] = save_slot + '0';  /*根据存档位置确定文件名*/

	reader.open(filename, ios::in);  /*根据文件名打开文件，若打开失败则提示，然后返回假并结束*/
	if (!reader) {
		cout << "存档" << filename << "打开失败！";
		return false;
	}

	char STATE[13], * pS = STATE;  /*存放文档状态的字符数组，pS指向其首地址*/
	int count = 0;  /*文件指针的位置*/
	reader.seekg(0, ios::beg);

	while (reader.peek() != EOF && pS - STATE < 12) {  /*在未遇到文件结束符的情况下读取文件的前12个字符*/
		*pS = reader.peek();
		pS++, count++;
		reader.seekg(count, ios::beg);
	}

	*pS = '\0';      /*补上尾零，为后续使用strcmp*/
	reader.close();  /*关闭文件*/

	if (!strcmp(STATE, "FILE_DELETED"))  /*将读取到的字符数组与状态FILE_DELETED比较，若相等则返回真，不等则返回假*/
		return true;
	else
		return false;
}

/***************************************************************************
  函数名称：file_load
  功    能：读取游戏存档文件
  输入参数：player& client：玩家对象
            ball b[]：游戏内部的对象数组
            const int save_slot：存档位置（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void file_tools::file_load(player& client, ball b[], const int save_slot)
{
	filename[4] = save_slot + '0';  /*根据存档位置确定文件名*/

	reader.open(filename, ios::in);  /*根据文件名打开文件，若打开失败则提示，然后返回假并结束*/
	if (!reader) {
		cout << "存档" << filename << "打开失败！";
		return;
	}

	int count = 0;  /*文件指针的位置*/
	char score[10], * ps = score;   /*存放得分数值的字符数组，ps指向其首地址*/

	/*1、读取得分*/
	count = count + 6;
	reader.seekg(count, ios::beg);
	client.score = 0;  /*读取前置零，避免多次读取导致累加*/

	while (reader.peek() != EOF && reader.peek() != '\n') {  /*得分不止一位，需要在未遇到结束符或换行符的情况下不断读取*/
		*ps = reader.peek();
		ps++, count++;
		reader.seekg(count, ios::beg);
	}

	for (int i = 0; i < ps - score; i++)  /*将每一位读取到的字符全部转换为数值得分*/
		client.score += (score[i] - '0') * power(10, ps - score - i - 1);

	/*2、读取下一颜色*/
	count = count + 8;
	reader.seekg(count, ios::beg);

	for (int i = 0; i < 3; i++) {  /*每次读取表示颜色的字符，并将文件指针往前移动2个单位*/
		client.next_color[i] = char_trans_num(reader.peek());
		count = count + 2;
		reader.seekg(count, ios::beg);
	}

	/*3、读取内部数组*/
	count = count + 9;
	reader.seekg(count, ios::beg);

	for (int i = 0; i < 81; i++) {
		const int J = i % 9;        /*将一维坐标转换为列标*/
		const int I = (i - J) / 9;  /*将一维坐标转换为行标*/

		char c[2];  /*每次读取两个字符*/
		c[0] = reader.peek();
		count++;
		reader.seekg(count, ios::beg);
		c[1] = reader.peek();

		if (c[0] >= '0' && c[0] <= '9' || c[0] >= 'A' && 'F') {  /*若第一个字符是表示颜色的字符，则说明该位置有珠子，进行读取*/
			b[i].set(J, I, char_trans_num(c[0]));  /*设置当前位置珠子的各项信息*/
			ball::if_ball[i] = true;  /*当前位置的标志设为真*/
			count++;
			reader.seekg(count, ios::beg);
		}

		else if (c[0] == ' ') {  /*若第一个字符是空格，则说明该位置无珠子，不进行读取*/
			count++;
			reader.seekg(count, ios::beg);
			ball::if_ball[i] = false;  /*当前位置的标志设为假*/
		}

		else if (c[1] == '\n') {  /*若第二个字符是换行符，则说明读取到了换行处，移动文件指针*/
			count = count++;
			reader.seekg(count, ios::beg);
		}
	}

	reader.close();  /*关闭文件*/
}

/***************************************************************************
  函数名称：file_delete
  功    能：清空游戏存档文件
  输入参数：const int save_slot：存档位置（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void file_tools::file_delete(const int save_slot)
{
	filename[4] = save_slot + '0';  /*根据存档位置确定文件名*/

	writer.open(filename, ios::out | ios::binary);  /*根据文件名打开文件，若打开失败则提示，然后返回假并结束*/
	if (!writer) {
		cout << "存档" << filename << "打开失败！";
		return;
	}

	writer << "FILE_DELETED";  /*写入清空状态*/
	writer.close();            /*关闭文件*/
}

/***************************************************************************
  函数名称：record
  功    能：记录一局游戏的结果
  输入参数：player& client：玩家对象
            const char* end_state：游戏结束时的状态（只读）
  返 回 值：无
  说    明：1、本函数记录了一局游戏的结束时间、最终得分、结束状态
            2、结束状态指的是游戏结束的原因，如主动退出（QUIT）、游戏失败（FAIL）等
***************************************************************************/
void file_tools::record(player& client, const char* end_state)
{
	writer.open("record.txt", ios::out | ios::binary | ios::app);  /*打开文件record.txt，若打开失败则提示，然后返回假并结束*/
	if (!writer) {
		cout << "文件record.txt打开失败！";
		return;
	}

	time_t t = time(NULL);
	tm* stime = localtime(&t);  /*取当前时间*/

	writer << "\n#COLORBALL RECORD\n"  /*写入游戏记录的标志*/
		<< "  TIME: " << stime->tm_year + 1900 << '-' << stime->tm_mon + 1 << '-' << stime->tm_mday << ' ';  /*写入当前时间的日期*/

	if (stime->tm_hour < 10)  /*写入当前时间的时（只有一位数时手动添加0）*/
		writer << '0' << stime->tm_hour << ':';
	else
		writer << stime->tm_hour << ':';

	if (stime->tm_min < 10)  /*写入当前时间的分（只有一位数时手动添加0）*/
		writer << '0' << stime->tm_min << ':';
	else
		writer << stime->tm_min << ':';

	if (stime->tm_sec < 10)  /*写入当前时间的秒（只有一位数时手动添加0）*/
		writer << '0' << stime->tm_sec << endl;
	else
		writer << stime->tm_sec << endl;


	writer << "  SCORE:" << client.score << endl  /*写入得分*/
		<< "  STATE:" << end_state << endl;  /*写入结束状态*/

	writer.close();  /*关闭文件*/
}

/***************************************************************************
  函数名称：get_highscore
  功    能：从文件中读取高分
  输入参数：无
  返 回 值：无
  说    明：无
***************************************************************************/
void file_tools::get_highscore()
{
	int count = 0;  /*文件指针的位置*/
	char score[10], * ps = score;  /*存放读取到的字符串型分数的字符数组*/
	bool if_end = false;  /*读取是否结束的标志*/

	reader.open("record.txt", ios::in);  /*打开文件record.txt，若打开失败则提示，然后返回假并结束*/
	if (!reader) {
		cout << "文件record.txt打开失败！";
		return;
	}

	for (int i = 0; i < HIGHSCORE_NUM && !if_end; i++) {  /*每循环一次读取一条记录中的得分，最多读取数量为HIGHSCORE_NUM*/
		while (1) {
			while (reader.peek() != EOF && reader.peek() != 'S') {  /*移动文件指针，直到遇到文件结束符或字母S才停下*/
				count++;
				reader.seekg(count, ios::beg);
			}

			if (reader.peek() == EOF) {  /*若遇到文件结束符，则标志读取结束并结束循环*/
				if_end = true;
				break;
			}

			else {  /*若没遇到文件结束符*/
				count++;
				reader.seekg(count, ios::beg);  /*将文件指针往前移动1个单位*/

				if (reader.peek() == 'C')  /*若遇到字母C，则是SCORE，说明读取到分数部分，结束循环*/
					break;
				else  /*若没有遇到字母C，则是STATE，说明读取到结束状态部分，继续循环*/
					continue;
			}
		}

		if (!if_end) {  /*若读取未结束并结束了循环，说明需往下读得分*/
			count = count + 5;
			reader.seekg(count, ios::beg);  /*将文件指针往前移动5个单位，指向得分的第一位*/
			ps = score;  /*ps指向score的首地址*/
			highscore[i] = 0;  /*数组当前元素置为0，防止读取多次时累加*/

			while (reader.peek() != '\n') {  /*得分不止一位，需要在未遇到结束符或换行符的情况下不断读取*/
				*ps = reader.peek();
				ps++, count++;
				reader.seekg(count, ios::beg);
			}

			for (int j = 0; j < ps - score; j++)  /*将每一位读取到的字符全部转换为数值得分*/
				highscore[i] += (score[j] - '0') * power(10, ps - score - j - 1);
		}
	}

	reader.close();  /*关闭文件*/
}

/***************************************************************************
  函数名称：show_highscore
  功    能：显示排序后的高分
  输入参数：无
  返 回 值：无
  说    明：本函数取读取到的分数前10位，在标题画面对话框中显示
***************************************************************************/
void file_tools::show_highscore()
{
	cct_setcolor(CVMB_KEYS_BG_COLOR, CVMB_KEYS_FG_COLOR_D);  /*设置颜色*/

	for (int i = 0; i < 3; i++) {  /*显示第1-3位*/
		cct_gotoxy(CVMB_COORD_X + 2 + 8 * i, CVMB_COORD_Y + 1);
		cout << i + 1 << ':' << highscore[i];
	}

	for (int i = 3; i < 6; i++) {  /*显示第4-6位*/
		cct_gotoxy(CVMB_COORD_X + 2 + 8 * (i - 3), CVMB_COORD_Y + 2);
		cout << i + 1 << ':' << highscore[i];
	}

	for (int i = 6; i < 9; i++) {  /*显示第7-9位*/
		cct_gotoxy(CVMB_COORD_X + 2 + 8 * (i - 6), CVMB_COORD_Y + 3);
		cout << i + 1 << ':' << highscore[i];
	}

	cct_gotoxy(CVMB_COORD_X + 9, CVMB_COORD_Y + 4);  /*显示第10位*/
	cout << "10:" << highscore[9];
}

/***************************************************************************
  函数名称：sort_compare
  功    能：将读取到的高分进行排序
  输入参数：无
  返 回 值：无
  说    明：本函数从大到小为存放分数的数组排序
***************************************************************************/
void file_tools::sort_highscore()
{
	qsort(highscore, HIGHSCORE_NUM, sizeof(int), highscore_compare);  //从大到小为存放分数的数组排序
}