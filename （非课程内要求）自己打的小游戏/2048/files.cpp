#include"90-b3.h"

/***************************************************************************
  函数名称：file_save
  功    能：将游戏保存到文件中
  输入参数：const int save_slot：存档位置（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void files::file_save(const int save_slot)
{
	filename[4] = save_slot + '0';  /*根据存档位置确定文件名*/

	writer.open(filename, ios::out | ios::binary);  /*根据文件名打开文件，若打开失败则提示后结束*/
	if (!writer) {
		cout << "存档" << filename << "打开失败！";
		return;
	}

	writer << "ORDER:" << __GAME.order << endl         /*写入面板阶数*/
		<< "SCORE:" << __GAME.score << endl            /*写入得分*/
		<< "STEPNUMBER:" << __GAME.stepnumber << endl  /*写入步数*/
		<< "MATRIX:" << endl;  /*写入内部数组*/

	for (int i = 0; i < __GAME.order * __GAME.order; i++) {
		writer << __GAME.matrix[i];
		if (i % __GAME.order == __GAME.order - 1)  /*一行写入__GAME.order个元素后换行*/
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
bool files::if_file_deleted(const int save_slot)
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
  输入参数：const int save_slot：存档位置（只读）
  返 回 值：无
  说    明：无
***************************************************************************/
void files::file_load(const int save_slot)
{
	filename[4] = save_slot + '0';  /*根据存档位置确定文件名*/

	reader.open(filename, ios::in);  /*根据文件名打开文件，若打开失败则提示，然后返回假并结束*/
	if (!reader) {
		cout << "存档" << filename << "打开失败！";
		return;
	}

	int count = 0;  /*文件指针的位置*/
	char score[10], * ps = score;   /*存放得分数值的字符数组，ps指向其首地址*/
	char stepnumber[10], * pS = stepnumber;   /*存放步数的字符数组，ps指向其首地址*/
	char matrix[5], * pm = matrix;  /*存放某一元素数值的字符数组，pm指向其首地址*/

	/*1、读取面板阶数*/
	count = count + 6;
	reader.seekg(count, ios::beg);
	__GAME.order = reader.peek() - '0';

	/*2、读取得分*/
	count = count + 8;
	reader.seekg(count, ios::beg);
	__GAME.score = 0;  /*读取前置零，避免多次读取导致累加*/

	while (reader.peek() != EOF && reader.peek() != '\n') {  /*得分不止一位，需要在未遇到结束符或换行符的情况下不断读取*/
		*ps = reader.peek();
		ps++, count++;
		reader.seekg(count, ios::beg);
	}

	for (int i = 0; i < ps - score; i++)  /*将每一位读取到的字符全部转换为数值得分*/
		__GAME.score = __GAME.score + (score[i] - '0') * power(10, ps - score - i - 1);

	/*3、读取步数*/
	count = count + 12;
	reader.seekg(count, ios::beg);
	__GAME.stepnumber = 0;  /*读取前置零，避免多次读取导致累加*/

	while (reader.peek() != EOF && reader.peek() != '\n') {  /*步数不止一位，需要在未遇到结束符或换行符的情况下不断读取*/
		*pS = reader.peek();
		pS++, count++;
		reader.seekg(count, ios::beg);
	}

	for (int i = 0; i < pS - stepnumber; i++)  /*将每一位读取到的字符全部转换为数值得分*/
		__GAME.stepnumber = __GAME.stepnumber + (stepnumber[i] - '0') * power(10, pS - stepnumber - i - 1);

	/*4、读取内部数组*/
	count = count + 9;
	reader.seekg(count, ios::beg);

	int* pM = __GAME.matrix;  /*pM指向内部数组首地址*/
	for (int i = 0; i < __GAME.order * __GAME.order; i++)  /*读取前置零，避免多次读取导致累加*/
		__GAME.matrix[i] = 0;

	while (reader.peek() != EOF) {
		while (reader.peek() != EOF && reader.peek() != '\n' && reader.peek() != ' ') {  /*元素不止一位，需要在未遇到结束符或换行符的情况下不断读取*/
			*pm = reader.peek();
			pm++, count++;
			reader.seekg(count, ios::beg);
		}

		if (reader.peek() == ' ' || reader.peek() == '\n') {  /*遇到空格或换行符，不断跳过直到这两种字符不再出现*/
			while (reader.peek() == ' ' || reader.peek() == '\n') {
				count++;
				reader.seekg(count, ios::beg);
			}
		}

		for (int i = 0; i < pm - matrix; i++)  /*将每一位读取到的字符全部转换为当前元素数值*/
			*pM = *pM + (matrix[i] - '0') * power(10, pm - matrix - i - 1);
		pm = matrix, pM++;  /*pm复位，pM向下移动*/
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
void files::file_delete(const int save_slot)
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