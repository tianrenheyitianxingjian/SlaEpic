//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永无BUG
//
//
//
#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<cstdio>
#define 主函数 main
using namespace std;

/*----------声明起点----------*/
/*数据结构体*/
struct ren {
	char mingzi[20] = { '\0' };
	char haoma[15] = { '\0' };
	char dizhi[40] = { '\0' };
};
struct jijin {             //创建一个jijin结构数组zhizhenbiao来保存ren结构对象
	int zhuangtai = 0;     //0未使用，1已使用 -1已删除
	ren *zhizhen = NULL;   //存new出来的ren结构对象的位置
};
/*全局变量*/
jijin *zhizhenbiao = NULL;
int biaochang = 128;                                                            //指针表的长度 可以选择扩容
/*支持性函数*/
    void guangbiao(int x, int y);                                               //转移光标到xy坐标
	int anjian();                                                               //等待键盘按下任意键，并返回ASCII键值↑72 ↓80 ←75 →77 回车13 ESC27 y121 n110 空格32 出错返回-1
    void cls() { system("cls"); }                                               //清空屏幕显示
	void pause() { cout << "\n    请按任意键" << endl; system("pause >nul"); }  //暂停程序执行
	int hang(int xiang) { return 2 * xiang + 5; }                               //在编辑中返回一项所在的行数
	int xunzhao();                                                              //从0寻找并返回指针表中未使用的那一项的下标
	void logo(int x, int y);                                                    //以指定坐标为左上角，输出logo
/*操作性函数*/
	void newbiao(jijin *&zzb);                                                  //创建指针表
	void zhengli();                                                             //整理指针表，剔除已删除的元素，在空间不足时扩容表长	
	void chaoxie(char[], int);                                                  //从输入抄写限制指定长度的字符串到目标里面，缓存设为9999个字符
	void chazhao(char[], int[]);                                                //按某种依据查找符合条件的联系人
	void paixu();                                                               //*尝试*对联系人进行首字母和拼音冒泡排序
/*交互性函数*/
	void xianshi(jijin *zzb);                                                   //（已废弃）从头到尾显示全部联系人
	void tianjia(jijin *&zzb);                                                  //新增一个联系人
	void bianji(int [],int);                                                    //修改或者删除等 操作一个联系人
	void sousuokuang();                                                         //显示搜索框
	void caidan();                                                              //显示程序选单
/*----------声明终点----------*/

int 主函数()
{
	system("color f5");
	system("title SlaEpic电话本");
	newbiao(zhizhenbiao);
	logo(25,9);
	pause();
	sousuokuang();
}
void caidan() {
	cls();
	/*cout << "    请输入选项\n\n    1 显示联系人\n    2 新增联系人\n    3 查找和编辑\n    4 查找\n    5 设置\n\n    " << endl;
	char xuanxiang = 0;
	cin >> xuanxiang;
	switch (xuanxiang) {
		//case '1':xianshi(zhizhenbiao); break;
	case '2':tianjia(zhizhenbiao); break;
		//case '3':sousuokuang(); break;
		//case 4:chazhao(zhizhenbiao); break;
		//case 5:shezhi(); break;
	default:cout << "    输入出错，请重试\n"; caidan(); break;
	}*/
	cout << "+-------+---------------------------------------+\n|       |                                       |\n|  OvO  |  [当前登入用户]                       |\n|       |                                       |\n+-------+---------------------------------------+\n|                                               |\n|  [ESC] 联系人                        个数     |\n|                                               |\n|    [+] 新建联系人                             |\n|                                               |\n|    [C] 修改密码                               |\n|                                               |\n|    [O] 强制排序                               |\n|                                               |\n|[右上X] 退出程序                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|  信工二班周松毅C++大作业                      |\n|  SlaEpic联系人程序 - 2018年6月                |\n|  项目地址 github.com/SlawnQiu/SlaEpic         |\n+-----------------------------------------------+";
	logo(50, 9);
	guangbiao(38, 6); cout << setw(4) << std::left << xunzhao();
	cout << endl;
	//guangbiao(3,11);输出当前用户名

	guangbiao(118, 16);
	while (1) {
		int zifu = anjian();
		switch (zifu) {
		case 27:return;
		case 43:tianjia(zhizhenbiao); return;
		case 79:;
		case 111:paixu(); return;//cout << "\7"; return;
		case 67:;
		case 99:cout << "\7\7"; return;
		default:;
		}
	}
	cls();
}
void newbiao(jijin *&zzb) {
	zzb = new jijin[biaochang];
}
int xunzhao() {
	int i = 0;
	while (zhizhenbiao[i].zhuangtai != 0)i++;
	return i;
}
void xianshi(jijin *zzb) {
	cls();
	cout << "\n     姓名                号码           地址                                    \n" << endl;
	int i = 0, shuchugeshu = 0;
	for (i = 0; i < xunzhao(); i++)if (zzb[i].zhuangtai == 1) cout << " " << std::left << setw(4) << ++shuchugeshu << std::left << setw(20) << zzb[i].zhizhen->mingzi << std::left << setw(15) << zzb[i].zhizhen->haoma << std::left << setw(40) << zzb[i].zhizhen->dizhi << "\n" << endl;
	cout << "     当前联系人数量: " << shuchugeshu << endl;
	pause();
}
void guangbiao(int x, int y)
{
	HANDLE jubing;
	COORD weizhi = { x,y };
	jubing = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(jubing, weizhi);
}
int anjian() {
	int jianzhi = 0;
	cin.sync(); cin.clear(); 
	if ((jianzhi = _getch()) < 127) { rewind(stdin); return jianzhi; }
	rewind(stdin); return -1;
}
void tianjia(jijin *&zzb) {
	//cls();
	guangbiao(9, 8);
	cout << "请再按一次" << endl;
	guangbiao(118, 16);
	//while (1) {
		int jianzhi = 0;
		cin.sync(); cin.clear();
		jianzhi = anjian();
		//if (jianzhi == 13)break; 
		if (jianzhi != 43)return;
	//}
	cls();
	int i = xunzhao();
	zzb[i].zhizhen = new ren; zzb[i].zhuangtai = 1;
	cout << "    +--------------+\n    |  新建联系人  |\n    +--------------+\n\n    姓名（最长20字符）:\n    电话（最长15字符）:\n    地址（最长40字符）:\n" << endl;
	guangbiao(26, 4);
	rewind(stdin);
	chaoxie(zzb[i].zhizhen->mingzi, 20);
	guangbiao(26, 5);
	chaoxie(zzb[i].zhizhen->haoma, 15);
	guangbiao(26, 6);
	chaoxie(zzb[i].zhizhen->dizhi, 40);
	cout << "\n    " << std::left << setw(20) << zzb[i].zhizhen->mingzi << std::left << setw(15) << zzb[i].zhizhen->haoma << std::left << setw(40) << zzb[i].zhizhen->dizhi << "\n    已经成功添加" << endl;
	pause();
	return;
}
void bianji(int jieguo[],int shuchugeshu)
{
	int xiang = 1;
	/*cls();
	
	cout << "\n     姓名                号码           地址                                    \n" << endl;
	int g = 0, shuchugeshu = 0, xiang = 0;
	for (g = 0; jieguo[g] != -1; g++)cout << " " << std::left << setw(4) << ++shuchugeshu << std::left << setw(20) << zhizhenbiao[jieguo[g]].zhizhen->mingzi << std::left << setw(15) << zhizhenbiao[jieguo[g]].zhizhen->haoma << std::left << setw(40) << zhizhenbiao[jieguo[g]].zhizhen->dizhi << "\n" << endl;
	cout << "当前搜索结果数量: " << shuchugeshu << "   ↑↓键移动光标，回车键选择该条目进行编辑，ESC键返回"<<endl;*/
	guangbiao(72, 2); cout << "[↑][↓]移动光标  [回车]选择  [ESC]返回";
	guangbiao(0, hang(xiang));
	while (1) {
		int zifu = anjian();
		if (zifu ==72) {//↑
			if (xiang == 1)xiang = shuchugeshu; else xiang--;
			guangbiao(0, hang(xiang));
			}
		if (zifu == 80) {//↓
			if (xiang == shuchugeshu)xiang = 1; else xiang++;
			guangbiao(0, hang(xiang));
		}
		
		if (zifu == 13) {
			guangbiao(5, hang(xiang) + 1);
			cout << "+------------------+     \n     |编辑该项（回车键）|     \n     |删除（退格键）    |     \n     |返回（ESC）       |     \n     +------------------+     ";
			while (1) {
				int zifu = anjian();
				if (zifu == 13) {//enter
					//zhizhenbiao[jieguo[xiang]]
					cls();
					xiang--;
					cout << "    +--------------+\n    |  编辑联系人  |\n    +--------------+\n\n    姓名（最长20字符）:\n\n    电话（最长15字符）:\n\n    地址（最长40字符）:\n" << endl;
					
					guangbiao(26, 8); cout << zhizhenbiao[jieguo[xiang]].zhizhen->dizhi << "  改为";
					guangbiao(26, 6); cout << zhizhenbiao[jieguo[xiang]].zhizhen->haoma << "  改为";
					guangbiao(26, 4); cout << zhizhenbiao[jieguo[xiang]].zhizhen->mingzi << "  改为";
					rewind(stdin);
					guangbiao(26, 5);
					chaoxie(zhizhenbiao[jieguo[xiang]].zhizhen->mingzi, 20);
					guangbiao(26, 7); 
					chaoxie(zhizhenbiao[jieguo[xiang]].zhizhen->haoma, 15);
					guangbiao(26, 9);
					chaoxie(zhizhenbiao[jieguo[xiang]].zhizhen->dizhi, 40);
					cout << "\n    " << std::left << setw(20) << zhizhenbiao[jieguo[xiang]].zhizhen->mingzi << std::left << setw(15) << zhizhenbiao[jieguo[xiang]].zhizhen->haoma << std::left << setw(40) << zhizhenbiao[jieguo[xiang]].zhizhen->dizhi << "\n    已经成功更新" << endl;
					pause();
					return;
				}
				if (zifu == 8) {//back
					guangbiao(6, hang(xiang) + 2); cout << "                  ";
					guangbiao(6, hang(xiang) + 3); cout << "请按多一次确认";
					guangbiao(6, hang(xiang) + 4); cout << "                  "; guangbiao(30, hang(xiang) + 5);
					int zifu = anjian();
					if(zifu==8){
						xiang--;
						zhizhenbiao[jieguo[xiang]].zhuangtai = -1;
						cout << "\n    " << std::left << setw(20) << zhizhenbiao[jieguo[xiang]].zhizhen->mingzi << std::left << setw(15) << zhizhenbiao[jieguo[xiang]].zhizhen->haoma << std::left << setw(40) << zhizhenbiao[jieguo[xiang]].zhizhen->dizhi << "\n    已删除" << endl;
						delete zhizhenbiao[jieguo[xiang]].zhizhen;
						pause();
					}
					return;
				}
				if (zifu == 27) {//esc
					return;
				}
			}
		}
		if (zifu == 27)return;
	}
}
void zhengli()
{
	if (xunzhao() > 0.9*biaochang) biaochang *= 2;
	jijin *xinbiao = new jijin[biaochang];
	int i1 = 0, i2 = 0;                   //i1为旧表下标，i2为新表下标
	for (i1 = 0; i1 < xunzhao(); i1++)if (zhizhenbiao[i1].zhuangtai == 1) {                  //迁移数据
		xinbiao[i2].zhizhen = zhizhenbiao[i1].zhizhen;
		xinbiao[i2].zhuangtai = 1;
		i2++;
	}
	delete[]zhizhenbiao;
	zhizhenbiao = xinbiao;
	xinbiao = NULL;
}
void chaoxie(char mubiao[], int changdu)
{
	rewind(stdin);
	char *huancun = new char[10000];
	gets_s(huancun, 10000);
	int i = 0;
	for (i = 0; i < changdu - 1&&huancun[i] != '\0'; i++) {
		mubiao[i] = huancun[i];
	}
	mubiao[i] = '\0';
	if (i == changdu - 1 && huancun[i] != '\0')cout << "\7";
	delete[]huancun;   //释放缓冲区
	rewind(stdin);
}
void sousuokuang() {
	char shuru[40] = { '\0' }; int zifu = 0; int i = 0;
	while (1) {
		int *jieguo = new int[biaochang]; //储存搜索结果在指针表中的下标，以-1为结束
		chazhao(shuru,jieguo);
		cls();
		//实时输出搜索结果
		cout << "+----------------+---------------------------------------------------------------------------------------------------+\n|                |                                                                                                   |\n|   查找联系人   |                                                                 [回车]选择  [ESC]菜单             |\n|                |                                                                                                   |\n+----------------+---------------------------------------------------------------------------------------------------+" << endl;

			cout << "     姓名                号码           地址                                    \n" << endl;
			int g = 0, shuchugeshu = 0;
			for (g = 0; jieguo[g]!=-1; g++)cout << " " << std::left << setw(4) << ++shuchugeshu << std::left << setw(20) << zhizhenbiao[jieguo[g]].zhizhen->mingzi << std::left << setw(15) << zhizhenbiao[jieguo[g]].zhizhen->haoma << std::left << setw(40) << zhizhenbiao[jieguo[g]].zhizhen->dizhi << "\n" << endl;
			cout << "     当前条目数: " << shuchugeshu << endl;
		
			guangbiao(20, 2); cout << shuru;
		zifu = anjian();
		if (zifu > 31 && zifu < 127) {
			if (i != 39) {
				shuru[i] = (char)zifu;
				i++;
			}
		}
		if (zifu == 8) {
			if (i) {
				i--;
				shuru[i] = '\0';
			}
		}
		if (zifu == 27)caidan();
		if (zifu == 13)if(shuchugeshu)bianji(jieguo,shuchugeshu);
		if (jieguo)delete[]jieguo;//除去旧的搜索结果
	}
}
void chazhao(char yiju[],int jieguo[]) {
	zhengli();
	int jieguogeshu = 0;
	if (yiju[0] == '\0') { for (int i = 0; i < xunzhao(); i++) { jieguo[jieguogeshu] = i; jieguogeshu++; } jieguo[jieguogeshu] = -1;  return; }  //考虑到空依据的时候

	for (int i = 0; i < xunzhao(); i++){
		string mz = zhizhenbiao[i].zhizhen->mingzi;
		string hm = zhizhenbiao[i].zhizhen->haoma;
		string dz = zhizhenbiao[i].zhizhen->dizhi;
		if (mz.find(yiju) != -1 || hm.find(yiju) != -1 || dz.find(yiju) != -1) {
			jieguo[jieguogeshu] = i;
			jieguogeshu++;
		}
	}
	jieguo[jieguogeshu] = -1;
}
void logo(int x, int y) {
	guangbiao(x, y); cout << "  ____  __                 _______";
	guangbiao(x, y + 1); cout << " / ___\\|\\ \\               |\\  ____\\             __";
	guangbiao(x, y + 2); cout << "| |___/ \\\\ \\               \\\\ \\___/            |\\_\\ ";
	guangbiao(x, y + 3); cout << "|\\ \\___  \\\\ \\        ______ \\\\ \\___       _____ \\_/_     ______";
	guangbiao(x, y + 4); cout << " \\\\____ \\ \\\\ \\      / ____ \\ \\\\  __\\     / ___ \\ |\\ \\   / _____\\ ";
	guangbiao(x, y + 5); cout << "  \\____\\ \\ \\\\ \\    |\\ \\__/\\ \\ \\\\ \\_/    |\\ \\_/\\ \\ \\\\ \\ |\\ \\____/";
	guangbiao(x, y + 6); cout << "   ____| |  \\\\ \\___ \\\\ \\__\\\\ \\ \\\\ \\_____ \\\\ \\_\\\\ \\ \\\\ \\ \\\\ \\______";
	guangbiao(x, y + 7); cout << "  |\\_____/   \\\\____\\ \\\\____/\\_\\ \\\\______\\ \\\\  ____\\ \\\\_\\ \\\\_______\\ ";
	guangbiao(x, y + 8); cout << "   \\____/     \\____/  \\____/\\_/  \\______/  \\\\ \\___/  \\_/  \\_______/";
	guangbiao(x, y + 9); cout << "                                            \\\\ \\ ";
	guangbiao(x, y + 10); cout << "                                             \\\\_\\ ";
	guangbiao(x, y + 11); cout << "                                              \\_/";
}
void paixu() {
	zhengli();
	system("title 排序中");
	int renshu = xunzhao();
	/*char **yiju = new char *[renshu];  //新建一个长度等于联系人个数的字符二维数组，每个行里面一个长度为3的列数组
	for (int i = 0; i < renshu; i++)yiju[i] = new char[3];
	for (int i = 0; i < renshu; i++) {
		int g = 0,zhongwen=0;
		for (g = 0; g < 2 && zhizhenbiao[i].zhizhen->mingzi[g] != '\0'; g++) {
			if ((zhizhenbiao[i].zhizhen->mingzi[0] >= 'a'&&zhizhenbiao[i].zhizhen->mingzi[0] <= 'z') || (zhizhenbiao[i].zhizhen->mingzi[0] >= 'A'&&zhizhenbiao[i].zhizhen->mingzi[0] <= 'Z')) {
				switch (zhizhenbiao[i].zhizhen->mingzi[0]) {
				case'a':;
				case'A':yiju[i] = "啊"; break;
				case'b':;
				case'B':yiju[i] = "芭"; break;
				case'c':;
				case'C':yiju[i] = "擦"; break;
				case'd':;
				case'D':yiju[i] = "搭"; break;
				case'e':;
				case'E':yiju[i] = "蛾"; break;
				case'f':;
				case'F':yiju[i] = "发"; break;
				case'g':;
				case'G':yiju[i] = "噶"; break;
				case'h':;
				case'H':yiju[i] = "哈"; break;
				case'i':;
				case'I':yiju[i] = "击"; break;
				case'j':;
				case'J':yiju[i] = "圾"; break;
				case'k':;
				case'K':yiju[i] = "喀"; break;
				case'l':;
				case'L':yiju[i] = "垃"; break;
				case'm':;
				case'M':yiju[i] = "妈"; break;
				case'n':;
				case'N':yiju[i] = "拿"; break;
				case'o':;
				case'O':yiju[i] = "哦"; break;
				case'p':;
				case'P':yiju[i] = "啪"; break;
				case'q':;
				case'Q':yiju[i] = "期"; break;
				case'r':;
				case'R':yiju[i] = "然"; break;
				case's':;
				case'S':yiju[i] = "撒"; break;
				case't':;
				case'T':yiju[i] = "塌"; break;
				case'u':;
				case'U':yiju[i] = "挖"; break;
				case'v':;
				case'V':yiju[i] = "哇"; break;
				case'w':;
				case'W':yiju[i] = "蛙"; break;
				case'x':;
				case'X':yiju[i] = "昔"; break;
				case'y':;
				case'Y':yiju[i] = "压"; break;
				case'z':;
				case'Z':yiju[i] = "匝"; break;
				}
				g = 2;
				break;
			}//字母转换汉字开始，结束后break
			yiju[i][g] = zhizhenbiao[i].zhizhen->mingzi[g];
			zhongwen++;
		}
		if(zhongwen&&zhizhenbiao[i].zhizhen->mingzi[g] == '\0')yiju[i][g] = '\0';
	}
	//冒泡排序//
	cls();
	for (int i = 0; i < renshu; i++)cout << yiju[i] << endl;
	pause();*/
	ren *linshi = NULL; //char *linshizf = new char[3];
	for (int lun = 1; lun < renshu; lun++) {
		int meipai = 1;
		for (int i = 0; i < renshu - lun; i++) {
			if (strcmp(zhizhenbiao[i].zhizhen->mingzi, zhizhenbiao[i + 1].zhizhen->mingzi) > 0) {
				linshi = zhizhenbiao[i].zhizhen;
				zhizhenbiao[i].zhizhen = zhizhenbiao[i + 1].zhizhen;
				zhizhenbiao[i + 1].zhizhen = linshi;                          //指针表交换指针值
				/*for (int g = 0; g < 3; g++) {
					linshizf = yiju[i][g];
					yiju[i][g] = yiju[i + 1][g];
					yiju[i + 1][g] = linshizf;
				}//交换依据表*/
				//linshizf = yiju[i];
				//yiju[i] = yiju[i + 1];
				//yiju[i + 1] = linshizf;

				meipai = 0;
				linshi = NULL; //linshizf = 0;
			}
		}
		if (meipai)break;
	}
	//for (int i = 0; i < renshu; i++)delete[] yiju[i];
	//delete[] yiju;
	system("title SlaEpic电话本");
}