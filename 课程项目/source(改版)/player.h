#pragma once
#include"colorball.h"
#include"interface-button.h"

//游戏内的各种状态
#define STATE_SELECTING  "  选定目标"
#define STATE_MOVING     "  选定位置"
#define STATE_VACANT     "  位置为空"
#define STATE_BLOCKED    "  位置已占"
#define STATE_NOWAY      "无有效路径"
#define STATE_CANCEL     "  取消选定"
#define STATE_CLEAR      "      清除"
#define STATE_OPTIONS    "      设置"
#define STATE_SAVE       "      保存"
#define STATE_DELETE     "      删除"
#define STATE_QUIT       "  准备退出"

//游戏内按键数
#define BUTTON_NUM  4

//需作为参数类型的提前声明
class ball;

//需作为友元类的提前声明
class game_messagebox;
class file_tools;
class optionsbox;

/*玩家类的声明*/
class player {
private:
	button button_options{ OPTIONS_COORD_X,OPTIONS_COORD_Y,GAME_OPTIONS };  //“设置”键
	button button_save   { SAVE_COORD_X,SAVE_COORD_Y,GAME_SAVE };           //“保存”键
	button button_delete { DELETE_COORD_X,DELETE_COORD_Y,GAME_DELETE };     //“删除”键
	button button_quit   { QUIT_COORD_X,QUIT_COORD_Y,GAME_QUIT };           //“退出”键
	int score;  //得分
	bool if_select;  //是否选定了一个珠子
	int select_x, select_y;  //选定珠子的列数、行数
	int next_color[3];  //下一次出现的3个颜色
	int way_coord[81];  //存储最短路径的数组
	static bool if_blink;  //是否闪烁（静态）
	static bool if_show;   //是否有清除效果（静态）
public:
	void matrix_clear(ball b[]);  //清空数组
	char* read_score(char* s);  //读取得分并转换为字符串
	char* read_color(char* c);  //读取颜色并转换为字符串
	void update_score();  //更新得分
	void update_color();  //更新颜色
	void update_state(const char* state);  //更新状态
	void blink_blockborder(const int coord, const int blink_times);  //使一个格子的边界闪烁
	void summon(ball b[], const int summon_times, bool* if_sound);  //随机生成若干个珠子

	void matrix_waynum_copy(ball dst[], const ball src[]);  //将结构体数组src[]中的移动步数信息复制到结构体数组dst[]中
	bool matrix_waynum_compare(const ball b1[], const ball b2[]);  //比较两结构体数组b1[]和b2[]的移动步数信息
	void matrix_waynum_clear(ball b[]);    //清空内部数组的移动步数信息
	void matrix_waymark_clear(ball b[]);   //清空内部数组的路径标记
	void matrix_waycoord_clear(ball b[]);  //清空内部数组的路径位置记录
	void countway_single_scan(ball b[], const int coord);  //统计数组元素coord周围四个元素的移动步数情况
	void countway(ball b[], const int src_coord);  //统计内部数组所有元素周围四个元素的移动步数情况
	void findway(ball b[], const int src_coord, const int dst_coord);   //寻找一条最短路径
	void showway(const ball b[]);   //在最短路径查找完成的基础上，将其显示出来
	void eraseway(const ball b[]);  //将已经显示出来的路径擦除

	void move(ball b[], const int src_coord, const int dst_coord);  //移动珠子
	void scan(ball b[]);  //扫描可消除的珠子
	int get_mark_num(const ball b[]);  //取被标记的珠子个数
	bool if_end(const ball b[]);  //判断游戏是否结束
	void clear(ball b[], bool* if_sound);  //消除珠子
	int if_block(ball b[], const int X, const int Y);  //判断鼠标位置是否在某一格子上
	void print_blockborder(const int coord, const int bg_color, const int fg_color);  //打印一个格子的边界
	void print_balls(ball b[]);  //打印当前的所有珠子
	void blocks_selective_default(ball b[], const int coord, const int bg_color, const int fg_color);   //选择性地消除某一格子的边界
	void blocks_selective_activate(ball b[], const int coord, const int bg_color, const int fg_color);  //选择性地打印某一格子的边界
	int if_button(const int X, const int Y);  //判断鼠标位置是否在某一按键上
	void buttons_selective_activate(const int selection);  //选择性地为某一按键取消高亮
	void buttons_selective_default(const int selection);   //选择性地为某一按键设置高亮
	int control(ball b[], bool* if_sound);  //用键鼠在游戏面板内进行操作

	player() :score(0), if_select(false), select_x(-1), select_y(-1), next_color{ 0,0,0 }  //构造函数
	{
		for (int i = 0; i < 81; i++)
			way_coord[i] = -1;
	}

	//友元类的声明
	friend class game_messagebox;
	friend class file_tools;
	friend class optionsbox;
};