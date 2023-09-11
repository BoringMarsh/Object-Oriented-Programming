#include<iostream>
#include"colorball.h"
#include"ball.h"
#include"player.h"

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

	reader.open(filename, ios::in | ios::_Nocreate);  /*根据文件名打开文件，若打开失败则提示，然后返回假并结束*/
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