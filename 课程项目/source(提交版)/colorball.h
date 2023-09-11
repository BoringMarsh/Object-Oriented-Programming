#pragma once
#include<fstream>
using namespace std;

//每局游戏的返回值
#define GAME_RET_FAILURE  0x1000  //失败
#define GAME_RET_OPTIONS  0x1001  //点击“设置”键
#define GAME_RET_SAVE     0x1002  //点击“保存”键
#define GAME_RET_DELETE   0x1003  //点击“删除”键
#define GAME_RET_QUIT     0x1004  //点击“退出”键

//游戏面板各部分坐标
#define SCORE_COORD_X    95  //得分显示框左上角横坐标
#define SCORE_COORD_Y    4   //得分显示框左上角纵坐标
#define COLOR_COORD_X    95  //下一颜色显示框左上角横坐标
#define COLOR_COORD_Y    11  //下一颜色显示框左上角纵坐标
#define STATE_COORD_X    95  //状态显示框左上角横坐标
#define STATE_COORD_Y    18  //状态显示框左上角纵坐标
#define OPTIONS_COORD_X  97  //“设置”键左上角横坐标
#define OPTIONS_COORD_Y  24  //“设置”键左上角纵坐标
#define SAVE_COORD_X     97  //“保存”键左上角横坐标
#define SAVE_COORD_Y     29  //“保存”键左上角纵坐标
#define DELETE_COORD_X   97  //“删除”键左上角横坐标
#define DELETE_COORD_Y   34  //“删除”键左上角纵坐标
#define QUIT_COORD_X     97  //“退出”键左上角横坐标
#define QUIT_COORD_Y     39  //“退出”键左上角纵坐标

//使用到的各种音效频率
#define SOUND_LLA  440   //频率：低6
#define SOUND_LSI  494   //频率：低7
#define SOUND_DO   523   //频率：1
#define SOUND_MI   659   //频率：3
#define SOUND_FA   698   //频率：4
#define SOUND_SO   784   //频率：5
#define SOUND_HDO  1046  //频率：高1

/***************************************************************************

  tools.cpp

***************************************************************************/
void pause();  //设置一个程序的间断点
int num_trans_color(const int num);  //输入一个0-5的数，返回表示颜色的量
char* color_trans_string(const int color, char* c);  //输入表示颜色的量，返回表示该颜色的字符串
void chessboard_single_line(int Y, const char* ch1, const char* ch2, const char* ch3, const char* ch4);  //输出游戏面板的某一行
void chessboard_multiple_lines(const int Y);  //输出游戏面板的各行
void print_chessboard();  //输出游戏面板
void print_info_block(const int X, const int Y, const char* title, const int bg_color, const int fg_color);  //打印一个游戏相关信息的显示框
void print_game_button(const int X, const int Y, const char* prompt, const int bg_color, const int fg_color);  //打印一个游戏内的按键
void print_cover_button(const char* prompt, const int bg_color, const int fg_color);  //在光标当前位置打印一个标题画面按键
void print_empty_block(const int bg_color, const int fg_color);  //在光标当前位置打印一个中心为空的色块
void print_switch_button(const int bg_color, const int fg_color);  //打印一个开关上的按键
int power(const int base_number, const int exponent);  //求一个数的n次方

/*存档管理类的声明*/
class file_tools {
private:
	ofstream writer;  //写对象
	ifstream reader;  //读对象
	char filename[10];  //文件名
public:
	char num_trans_char(const int num);  //输入一个0-15的数，返回对应十六进制表示的字符
	int char_trans_num(const char ch);   //输入一个十六进制表示的字符，返回对应的数
	void file_save(const class player& client, const class ball b[], const int save_slot);  //将游戏保存到文件中
	bool if_file_deleted(const int save_slot);  //判断当前位置上的文件是否被清空
	void file_load(player& client, ball b[], const int save_slot);  //读取游戏存档文件
	void file_delete(const int save_slot);  //清空游戏存档文件

	file_tools() :filename("save .txt") {}  //构造函数
};