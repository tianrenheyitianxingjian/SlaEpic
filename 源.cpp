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
//               ���汣��         ����BUG
//
//
//
#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
#include<windows.h>
#include<conio.h>
#include<cstdio>
#define ������ main
using namespace std;

/*----------�������----------*/
/*���ݽṹ��*/
struct ren {
	char mingzi[20] = { '\0' };
	char haoma[15] = { '\0' };
	char dizhi[40] = { '\0' };
};
struct jijin {             //����һ��jijin�ṹ����zhizhenbiao������ren�ṹ����
	int zhuangtai = 0;     //0δʹ�ã�1��ʹ�� -1��ɾ��
	ren *zhizhen = NULL;   //��new������ren�ṹ�����λ��
};
/*ȫ�ֱ���*/
jijin *zhizhenbiao = NULL;
int biaochang = 128;                                                            //ָ���ĳ��� ����ѡ������
/*֧���Ժ���*/
    void guangbiao(int x, int y);                                               //ת�ƹ�굽xy����
	int anjian();                                                               //�ȴ����̰����������������ASCII��ֵ��72 ��80 ��75 ��77 �س�13 ESC27 y121 n110 �ո�32 ������-1
    void cls() { system("cls"); }                                               //�����Ļ��ʾ
	void pause() { cout << "\n    �밴�����" << endl; system("pause >nul"); }  //��ͣ����ִ��
	int hang(int xiang) { return 2 * xiang + 5; }                               //�ڱ༭�з���һ�����ڵ�����
	int xunzhao();                                                              //��0Ѱ�Ҳ�����ָ�����δʹ�õ���һ����±�
	void logo(int x, int y);                                                    //��ָ������Ϊ���Ͻǣ����logo
/*�����Ժ���*/
	void newbiao(jijin *&zzb);                                                  //����ָ���
	void zhengli();                                                             //����ָ����޳���ɾ����Ԫ�أ��ڿռ䲻��ʱ���ݱ�	
	void chaoxie(char[], int);                                                  //�����볭д����ָ�����ȵ��ַ�����Ŀ�����棬������Ϊ9999���ַ�
	void chazhao(char[], int[]);                                                //��ĳ�����ݲ��ҷ�����������ϵ��
/*�����Ժ���*/
	void xianshi(jijin *zzb);                                                   //���ѷ�������ͷ��β��ʾȫ����ϵ��
	void tianjia(jijin *&zzb);                                                  //����һ����ϵ��
	void bianji(int [],int);                                                    //�޸Ļ���ɾ���� ����һ����ϵ��
	void sousuokuang();                                                         //��ʾ������
	void caidan();                                                              //��ʾ����ѡ��
/*----------�����յ�----------*/

int ������()
{
	system("color f5");
	newbiao(zhizhenbiao);
	logo(25,9);
	pause();
	sousuokuang();
}
void caidan() {
	cls();
	/*cout << "    ������ѡ��\n\n    1 ��ʾ��ϵ��\n    2 ������ϵ��\n    3 ���Һͱ༭\n    4 ����\n    5 ����\n\n    " << endl;
	char xuanxiang = 0;
	cin >> xuanxiang;
	switch (xuanxiang) {
		//case '1':xianshi(zhizhenbiao); break;
	case '2':tianjia(zhizhenbiao); break;
		//case '3':sousuokuang(); break;
		//case 4:chazhao(zhizhenbiao); break;
		//case 5:shezhi(); break;
	default:cout << "    �������������\n"; caidan(); break;
	}*/

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
	cout << "\n     ����                ����           ��ַ                                    \n" << endl;
	int i = 0, shuchugeshu = 0;
	for (i = 0; i < xunzhao(); i++)if (zzb[i].zhuangtai == 1) cout << " " << std::left << setw(4) << ++shuchugeshu << std::left << setw(20) << zzb[i].zhizhen->mingzi << std::left << setw(15) << zzb[i].zhizhen->haoma << std::left << setw(40) << zzb[i].zhizhen->dizhi << "\n" << endl;
	cout << "     ��ǰ��ϵ������: " << shuchugeshu << endl;
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
	cls();
	cout << "    \nȷ�������ϵ�˰��س��������ذ�ESC��" << endl;
	while (1) {
		int jianzhi = 0;
		cin.sync(); cin.clear();
		jianzhi = anjian();
		if (jianzhi == 13)break; 
		if (jianzhi == 27)return;
	}
	cls();
	int i = xunzhao();
	zzb[i].zhizhen = new ren; zzb[i].zhuangtai = 1;
	cout << "    +--------------+\n    |  �½���ϵ��  |\n    +--------------+\n\n    �������20�ַ���:\n    �绰���15�ַ���:\n    ��ַ���40�ַ���:\n" << endl;
	guangbiao(26, 4);
	rewind(stdin);
	chaoxie(zzb[i].zhizhen->mingzi, 20);
	guangbiao(26, 5);
	chaoxie(zzb[i].zhizhen->haoma, 15);
	guangbiao(26, 6);
	chaoxie(zzb[i].zhizhen->dizhi, 40);
	cout << "\n    " << std::left << setw(20) << zzb[i].zhizhen->mingzi << std::left << setw(15) << zzb[i].zhizhen->haoma << std::left << setw(40) << zzb[i].zhizhen->dizhi << "\n    �Ѿ��ɹ����" << endl;
	pause();
	return;
}
void bianji(int jieguo[],int shuchugeshu)
{
	int xiang = 1;
	/*cls();
	
	cout << "\n     ����                ����           ��ַ                                    \n" << endl;
	int g = 0, shuchugeshu = 0, xiang = 0;
	for (g = 0; jieguo[g] != -1; g++)cout << " " << std::left << setw(4) << ++shuchugeshu << std::left << setw(20) << zhizhenbiao[jieguo[g]].zhizhen->mingzi << std::left << setw(15) << zhizhenbiao[jieguo[g]].zhizhen->haoma << std::left << setw(40) << zhizhenbiao[jieguo[g]].zhizhen->dizhi << "\n" << endl;
	cout << "��ǰ�����������: " << shuchugeshu << "   �������ƶ���꣬�س���ѡ�����Ŀ���б༭��ESC������"<<endl;*/
	guangbiao(72, 2); cout << "[��][��]�ƶ����  [�س�]ѡ��  [ESC]����";
	guangbiao(0, hang(xiang));
	while (1) {
		int zifu = anjian();
		if (zifu ==72) {//��
			if (xiang == 1)xiang = shuchugeshu; else xiang--;
			guangbiao(0, hang(xiang));
			}
		if (zifu == 80) {//��
			if (xiang == shuchugeshu)xiang = 1; else xiang++;
			guangbiao(0, hang(xiang));
		}
		
		if (zifu == 13) {
			guangbiao(5, hang(xiang) + 1);
			cout << "+------------------+     \n     |�༭����س�����|     \n     |ɾ�����˸����    |     \n     |���أ�ESC��       |     \n     +------------------+     ";
			while (1) {
				int zifu = anjian();
				if (zifu == 13) {//enter
					//zhizhenbiao[jieguo[xiang]]
					cls();
					xiang--;
					cout << "    +--------------+\n    |  �༭��ϵ��  |\n    +--------------+\n\n    �������20�ַ���:\n\n    �绰���15�ַ���:\n\n    ��ַ���40�ַ���:\n" << endl;
					
					guangbiao(26, 8); cout << zhizhenbiao[jieguo[xiang]].zhizhen->dizhi << "  ��Ϊ";
					guangbiao(26, 6); cout << zhizhenbiao[jieguo[xiang]].zhizhen->haoma << "  ��Ϊ";
					guangbiao(26, 4); cout << zhizhenbiao[jieguo[xiang]].zhizhen->mingzi << "  ��Ϊ";
					rewind(stdin);
					guangbiao(26, 5);
					chaoxie(zhizhenbiao[jieguo[xiang]].zhizhen->mingzi, 20);
					guangbiao(26, 7); 
					chaoxie(zhizhenbiao[jieguo[xiang]].zhizhen->haoma, 15);
					guangbiao(26, 9);
					chaoxie(zhizhenbiao[jieguo[xiang]].zhizhen->dizhi, 40);
					cout << "\n    " << std::left << setw(20) << zhizhenbiao[jieguo[xiang]].zhizhen->mingzi << std::left << setw(15) << zhizhenbiao[jieguo[xiang]].zhizhen->haoma << std::left << setw(40) << zhizhenbiao[jieguo[xiang]].zhizhen->dizhi << "\n    �Ѿ��ɹ�����" << endl;
					pause();
					return;
				}
				if (zifu == 8) {//back
					guangbiao(6, hang(xiang) + 2); cout << "                  ";
					guangbiao(6, hang(xiang) + 3); cout << "�밴��һ��ȷ��";
					guangbiao(6, hang(xiang) + 4); cout << "                  "; guangbiao(30, hang(xiang) + 5);
					int zifu = anjian();
					if(zifu==8){
						xiang--;
						zhizhenbiao[jieguo[xiang]].zhuangtai = -1;
						cout << "\n    " << std::left << setw(20) << zhizhenbiao[jieguo[xiang]].zhizhen->mingzi << std::left << setw(15) << zhizhenbiao[jieguo[xiang]].zhizhen->haoma << std::left << setw(40) << zhizhenbiao[jieguo[xiang]].zhizhen->dizhi << "\n    ��ɾ��" << endl;
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
	int i1 = 0, i2 = 0;                   //i1Ϊ�ɱ��±꣬i2Ϊ�±��±�
	for (i1 = 0; i1 < xunzhao(); i1++)if (zhizhenbiao[i1].zhuangtai == 1) {                  //Ǩ������
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
	delete[]huancun;   //�ͷŻ�����
	rewind(stdin);
}
void sousuokuang() {
	char shuru[40] = { '\0' }; int zifu = 0; int i = 0;
	while (1) {
		int *jieguo = new int[biaochang]; //�������������ָ����е��±꣬��-1Ϊ����

		chazhao(shuru,jieguo);
		cls();
		          //ʵʱ����������

		cout << "+----------------+---------------------------------------------------------------------------------------------------+\n|                |                                                                                                   |\n|   ������ϵ��   |                                                                 [�س�]ѡ��  [ESC]�˵�             |\n|                |                                                                                                   |\n+----------------+---------------------------------------------------------------------------------------------------+" << endl;

			cout << "     ����                ����           ��ַ                                    \n" << endl;
			int g = 0, shuchugeshu = 0;
			for (g = 0; jieguo[g]!=-1; g++)cout << " " << std::left << setw(4) << ++shuchugeshu << std::left << setw(20) << zhizhenbiao[jieguo[g]].zhizhen->mingzi << std::left << setw(15) << zhizhenbiao[jieguo[g]].zhizhen->haoma << std::left << setw(40) << zhizhenbiao[jieguo[g]].zhizhen->dizhi << "\n" << endl;
			cout << "     ��ǰ�����������: " << shuchugeshu << endl;
		
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
		if (jieguo)delete[]jieguo;//��ȥ�ɵ��������



	}
}
void chazhao(char yiju[],int jieguo[]) {
	zhengli();
	int jieguogeshu = 0;
	if (yiju[0] == '\0') { for (int i = 0; i < xunzhao(); i++) { jieguo[jieguogeshu] = i; jieguogeshu++; } jieguo[jieguogeshu] = -1; return; }  //���ǵ������ݵ�ʱ��

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
	guangbiao(x, y + 5); cout << "  \\____\\ \\ \\\\ \\    |\\ \\__/\\ \\ \\\\ \\_/    |\\ \\  \\ \\ \\\\ \\ |\\ \\____/";
	guangbiao(x, y + 6); cout << "   ____| |  \\\\ \\___ \\\\ \\__\\\\ \\ \\\\ \\_____ \\\\ \\__\\ \\ \\\\ \\ \\\\ \\______";
	guangbiao(x, y + 7); cout << "  |\\_____/   \\\\____\\ \\\\____/\\_\\ \\\\______\\ \\\\  ____\\ \\\\_\\ \\\\_______\\ ";
	guangbiao(x, y + 8); cout << "   \\____/     \\____/  \\____/\\_/  \\______/  \\\\ \\___/  \\_/  \\_______/";
	guangbiao(x, y + 9); cout << "                                            \\\\ \\ ";
	guangbiao(x, y + 10); cout << "                                             \\\\_\\ ";
	guangbiao(x, y + 11); cout << "                                              \\_/";
}