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
//����ʹ���˽ṹ��������Ա����ֵ����䣬��ʹ��VISUAL STUDIO 2017����ó���
//�봴������Ŀ
//Cܳ����ҵ2018 �Ź����� ������
//
#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include<cstdio>
//#define ������ main
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
struct shezhi {//�����û����õ�
	char mima[33] = { 0 };
	char yonghuming[33] = { 0 };
	int zidong_paixu = 1;//�Զ�����Ĭ�Ͽ�
	int renshu = 0;
};
/*ȫ�ֱ���*/
jijin *zhizhenbiao = NULL;
int biaochang = 128;                                                        //ָ���ĳ��� ����ѡ������
shezhi *set = NULL;
fstream wenjian;
const string houzui = ".epic";
string wenjianming;
/*֧���Ժ���*/
void guangbiao(int x, int y);                                               //ת�ƹ�굽xy����
int anjian();                                                               //�ȴ����̰����������������ASCII��ֵ��72 ��80 ��75 ��77 �س�13 ESC27 y121 n110 �ո�32 ������-1
void cls() { system("cls"); }                                               //�����Ļ��ʾ
void pause() { cout << "\n    �밴�����" << endl; system("pause >nul"); }  //��ͣ����ִ��
int hang(int xiang) { return 2 * xiang + 5; }                               //�ڱ༭�з���һ�����ڵ�����
int xunzhao();                                                              //��0Ѱ�Ҳ�����ָ�����δʹ�õ���һ����±�
void logo(int x, int y);                                                    //��ָ������Ϊ���Ͻǣ����logo
/*�����Ժ���*/
void newbiao(jijin *&zzb);                                                  //����ָ����������
void zhengli();                                                             //����ָ����޳���ɾ����Ԫ�أ��ڿռ䲻��ʱ���ݱ�	
int chaoxie(char[], int);                                                   //�����볭д����ָ�����ȵ��ַ�����Ŀ�����棬������Ϊ9999���ַ��������ַ��������Ʒ��ط�0
void chazhao(char[], int[]);                                                //��ĳ�����ݲ��ҷ�����������ϵ��
void paixu();                                                               //�����֮��*����*����ϵ�˽�������ĸ��ƴ��ð������
void xieru();                                                               //����������ݵ��ļ�
void duqu();                                                                //���ļ���ȡ����
void zhuxiao();                                                             //ע��
/*�����Ժ���*/
void xianshi(jijin *zzb);                                                   //���ѷ�������ͷ��β��ʾȫ����ϵ��
void tianjia(jijin *&zzb);                                                  //����һ����ϵ��
void bianji(int[], int);                                                    //�޸Ļ���ɾ���� ����һ����ϵ��
void sousuokuang();                                                         //��ʾ������
int caidan();                                                               //��ʾ����ѡ��
void denglu();                                                              //����
void genggaimima();                                                         //��������
/*----------�����յ�----------*/

int main()
{
	while (1) {
		system("color f5");
		system("title SlaEpic�绰��");
		newbiao(zhizhenbiao);
		denglu();
		duqu();
		sousuokuang();
		zhuxiao();
	}
}
void denglu() {
	while (1) {
		cls();
		logo(25, 4);
		guangbiao(49, 17); cout << "ʹ������SlaEpic�˺�";
		guangbiao(45, 18); cout << "---------------------------";
		guangbiao(52, 20); cout << "[Enter]��һ��" << endl;
		do {//��ֹ������
			guangbiao(45, 19); chaoxie(set->yonghuming, 33);
		} while (!strlen(set->yonghuming));
		wenjianming = set->yonghuming + houzui;
		wenjian.open(wenjianming, ios::_Nocreate | ios::binary);
		for (int g = 17; g < 22; g++) { guangbiao(0, g); for (int i = 0; i < 119; i++)cout << " "; }
		if (!wenjian) {//��û������û�ʱ
			guangbiao((106 - strlen(set->yonghuming)) / 2 - 1, 17); cout << "�� " << set->yonghuming << " ����ݼ���";
			guangbiao((106 - strlen(set->yonghuming)) / 2 - 3, 18); for (unsigned int i = 0; i < strlen(set->yonghuming) + 18; i++)cout << "-";
			guangbiao(39, 20); cout << "�������32λ [Enter]�½��˻�  [ESC]ȡ��" << endl;
			char shuru[33] = { 0 }; int zifu = 0; int i = 0, esc = 0;
			while (1) {
				guangbiao(0, 19); for (int i = 0; i < 119; i++)cout << " ";
				guangbiao((120 - strlen(shuru)) / 2 - 1, 19); cout << shuru;
				zifu = anjian();
				if (zifu > 31 && zifu < 127) {
					if (i != 32) {
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
				if (zifu == 27) { esc++; break; }
				if (zifu == 13)if (strlen(shuru))break;
			}
			if (esc)continue;
			cout << endl;
			strcpy_s(set->mima, shuru);
			wenjian.open(wenjianming, ios::binary | ios::out);
			wenjian.seekp(0);
			wenjian.write((char*)set, sizeof(shezhi));//���´������ļ���д������
			wenjian.close();
			return;
		}
		if(wenjian){//�û�����
			wenjian.seekg(0);
			wenjian.read((char*)set, sizeof(shezhi));//��ȡ���õ�
			guangbiao((106 - strlen(set->yonghuming)) / 2 - 1, 17); cout << "�� " << set->yonghuming << " ����ݼ���";
			guangbiao((106 - strlen(set->yonghuming)) / 2 - 3, 18); for (unsigned int i = 0; i < strlen(set->yonghuming) + 18; i++)cout << "-";
			guangbiao(48, 20); cout << "[Enter]��¼  [ESC]ȡ��" << endl;
			char shuru[33] = { '\0' }; int zifu = 0; int i = 0, esc = 0;
			while (1) {
				guangbiao(0, 19); for (int i = 0; i < 119; i++)cout << " ";
				guangbiao((120 - strlen(shuru)) / 2 - 1, 19); for (unsigned int i = 0; i < strlen(shuru); i++)cout << "*";
				zifu = anjian();
				if (zifu > 31 && zifu < 127) {
					if (i != 32) {
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
				if (zifu == 27) { esc++; break; }
				if (zifu == 13) { 
					if(!strcmp(set->mima,shuru))break;
					else { guangbiao(55, 21); cout << "�������" << endl; }
				}
			}
			wenjian.close();
			if (esc)continue;
			cout << endl;
			return;
        }
	}
}
void genggaimima()
{
	guangbiao(9, 10);
	cout << "���ٰ�һ��" << endl;
	guangbiao(118, 16);
	int jianzhi = 0;
	jianzhi = anjian();
	if (jianzhi != 67&& jianzhi != 99)return;
	guangbiao(0, 16);
	cout << "+--------+--------------------------------------+\n|        |  ���������                          |\n|        |                                      |\n|  ����  |                                      |\n|  ����  |  ���������루32�ַ����ڣ�            |\n|        |                                      |\n|        |                                      |\n|        |                       [Enter]��һ��  |\n+--------+--------------------------------------+";
	while (1) {
		char jiumima[33] = { 0 };
		guangbiao(12, 18);
		if (!chaoxie(jiumima, 33)&&!strcmp(jiumima, set->mima))break;//������볬����ƥ����ͨ��
		guangbiao(23, 17); cout << "�������";
		guangbiao(12, 18); cout << "                                    |" << endl;
	}
	guangbiao(23, 17); cout << "        ";
	do{
		guangbiao(12, 21);
		chaoxie(set->mima, 33);
	} while (!strlen(set->mima));//��ֹ������
	guangbiao(12, 21); cout << "����Ϊ����������                    |";
	guangbiao(12, 22); cout << set->mima;
	wenjian.open(wenjianming, ios::in | ios::out | ios::binary);
	wenjian.seekp(0);
	wenjian.write((char*)set, sizeof(shezhi));
	wenjian.close();
	system("pause >nul");
	cout << endl;
	return;
}
int caidan() {
	cls();
	cout << "+-------+---------------------------------------+\n|       |                                       |\n|  OvO  |                                       |\n|       |                                       |\n+-------+---------------------------------------+\n|                                               |\n|  [ESC] ��ϵ��                        ����     |\n|                                               |\n|    [+] �½���ϵ��                             |\n|                                               |\n|    [C] ��������                               |\n|                                               |\n|    [O] �л��û�                               |\n|                                               |\n|[����X] �˳�����                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|                                               |\n|  �Ź�����������C++����ҵ                      |\n|  SlaEpic��ϵ�˳��� - 2018��6��                |\n|  ��Ŀ��ַ github.com/SlawnQiu/SlaEpic         |\n+-----------------------------------------------+";
	logo(50, 9);
	guangbiao(38, 6); cout << setw(4) << std::left << xunzhao();
	cout << endl;
	guangbiao(11, 2); cout << set->yonghuming;
	guangbiao(118, 16);
	while (1) {
		int zifu = anjian();
		switch (zifu) {
		case 27:return 0;
		case 43:tianjia(zhizhenbiao); return 0;
		case 79:;
		case 111: {guangbiao(9, 12);
			cout << "���ٰ�һ��" << endl;
			guangbiao(118, 16);
			int jianzhi = 0;
			jianzhi = anjian();
			if (jianzhi != 79&& jianzhi != 111)return 0;
			return 1; }//�ǳ�;
		case 67:;
		case 99:; genggaimima(); return 0;
		default:;
		}
	}
}
void newbiao(jijin *&zzb) {
	zzb = new jijin[biaochang];
	set = new shezhi;
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
	if ((jianzhi = _getch()) < 127) { rewind(stdin); return jianzhi; }
	rewind(stdin); return -1;
}
void tianjia(jijin *&zzb) {
	guangbiao(9, 8);
	cout << "���ٰ�һ��" << endl;
	guangbiao(118, 16);
		int jianzhi = 0;
		jianzhi = anjian();
		if (jianzhi != 43)return;
	cls();
	int i = xunzhao();
	zzb[i].zhizhen = new ren; zzb[i].zhuangtai = 1;
	cout << "    +--------------+\n    |  �½���ϵ��  |\n    +--------------+\n\n    �������20�ַ���:\n    �绰���15�ַ���:\n    ��ַ���40�ַ���:\n" << endl;
	guangbiao(26, 1); cout << "[Enter]��һ��";
	guangbiao(26, 4);
	rewind(stdin);
	chaoxie(zzb[i].zhizhen->mingzi, 20);
	guangbiao(26, 5);
	chaoxie(zzb[i].zhizhen->haoma, 15);
	guangbiao(26, 6);
	chaoxie(zzb[i].zhizhen->dizhi, 40);
	cout << "\n    " << std::left << setw(20) << zzb[i].zhizhen->mingzi << std::left << setw(15) << zzb[i].zhizhen->haoma << std::left << setw(40) << zzb[i].zhizhen->dizhi << "\n    �Ѿ��ɹ����" << endl;
	paixu();
	xieru();
	pause();
	return;
}
void bianji(int jieguo[],int shuchugeshu)
{
	int xiang = 1;
	guangbiao(72, 2); cout << "[��][��]�ƶ����  [Enter]ѡ��  [ESC]����";
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
					cout << "    +--------------+\n    |  �༭��ϵ��  |        [Enter]��һ��  �����ĸ���������\n    +--------------+\n\n    �������20�ַ���:\n\n    �绰���15�ַ���:\n\n    ��ַ���40�ַ���:\n" << endl;
					guangbiao(26, 1);
					guangbiao(26, 8); cout << zhizhenbiao[jieguo[xiang]].zhizhen->dizhi << "  ��Ϊ";
					guangbiao(26, 6); cout << zhizhenbiao[jieguo[xiang]].zhizhen->haoma << "  ��Ϊ";
					guangbiao(26, 4); cout << zhizhenbiao[jieguo[xiang]].zhizhen->mingzi << "  ��Ϊ";
					rewind(stdin);
					char linshi[41] = { 0 };
					guangbiao(26, 5);
					chaoxie(linshi, 20);
					if (strlen(linshi))strcpy_s(zhizhenbiao[jieguo[xiang]].zhizhen->mingzi,linshi);
					guangbiao(26, 7); 
					chaoxie(linshi, 15);
					if (strlen(linshi))strcpy_s(zhizhenbiao[jieguo[xiang]].zhizhen->haoma, linshi);
					guangbiao(26, 9);
					chaoxie(linshi, 40);
					if (strlen(linshi))strcpy_s(zhizhenbiao[jieguo[xiang]].zhizhen->dizhi, linshi);
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
	if (xunzhao() > biaochang - 10) biaochang *= 2;
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
	set->renshu = xunzhao();
}
int chaoxie(char mubiao[], int changdu)
{
	rewind(stdin);
	int fanhui = 0;
	char *huancun = new char[10000];
	gets_s(huancun, 10000);
	int i = 0;
	for (i = 0; i < changdu - 1&&huancun[i] != '\0'; i++) {
		mubiao[i] = huancun[i];
	}
	mubiao[i] = '\0';
	if (i == changdu - 1)if ((!(mubiao[changdu - 2] > 31 && mubiao[changdu - 2] < 127)) && (mubiao[changdu - 3] > 31 && mubiao[changdu - 3] < 127))mubiao[changdu - 2] = '\0';//��������β�����ַ���λ�ֽڶ�ʧ��������
	if (i == changdu - 1 && huancun[i] != '\0') {
		cout << "\7"; fanhui++;
	}
	delete[]huancun;   //�ͷŻ�����
	rewind(stdin);
	return fanhui;
}
void sousuokuang() {
	char shuru[40] = { '\0' }; int zifu = 0; int i = 0;
	while (1) {
		int *jieguo = new int[biaochang]; //�������������ָ����е��±꣬��-1Ϊ����
		chazhao(shuru,jieguo);
		cls();
		//ʵʱ����������
		cout << "+----------------+---------------------------------------------------------------------------------------------------+\n|                |                                                                                                   |\n|   ������ϵ��   |                                                                 [Enter]ѡ��  [ESC]�˵�            |\n|                |                                                                                                   |\n+----------------+---------------------------------------------------------------------------------------------------+" << endl;

			cout << "     ����                ����           ��ַ                                    \n" << endl;
			int g = 0, shuchugeshu = 0;
			for (g = 0; jieguo[g]!=-1; g++)cout << " " << std::left << setw(4) << ++shuchugeshu << std::left << setw(20) << zhizhenbiao[jieguo[g]].zhizhen->mingzi << std::left << setw(15) << zhizhenbiao[jieguo[g]].zhizhen->haoma << std::left << setw(40) << zhizhenbiao[jieguo[g]].zhizhen->dizhi << "\n" << endl;
			cout << "     ��ǰ��Ŀ��: " << shuchugeshu << endl;
		
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
		if (zifu == 27) { if(caidan())return;
		
		}
		if (zifu == 13)if (shuchugeshu) {
			bianji(jieguo, shuchugeshu); 
			paixu();
			xieru();
		}
		if (jieguo)delete[]jieguo;//��ȥ�ɵ��������
	}
}
void chazhao(char yiju[],int jieguo[]) {
	zhengli();
	int jieguogeshu = 0;
	if (yiju[0] == '\0') { for (int i = 0; i < xunzhao(); i++) { jieguo[jieguogeshu] = i; jieguogeshu++; } jieguo[jieguogeshu] = -1;  return; }  //���ǵ������ݵ�ʱ��

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
	system("title ������");
	int renshu = xunzhao();
	/*char **yiju = new char *[renshu];  //�½�һ�����ȵ�����ϵ�˸������ַ���ά���飬ÿ��������һ������Ϊ3��������
	for (int i = 0; i < renshu; i++)yiju[i] = new char[3];
	for (int i = 0; i < renshu; i++) {
		int g = 0,zhongwen=0;
		for (g = 0; g < 2 && zhizhenbiao[i].zhizhen->mingzi[g] != '\0'; g++) {
			if ((zhizhenbiao[i].zhizhen->mingzi[0] >= 'a'&&zhizhenbiao[i].zhizhen->mingzi[0] <= 'z') || (zhizhenbiao[i].zhizhen->mingzi[0] >= 'A'&&zhizhenbiao[i].zhizhen->mingzi[0] <= 'Z')) {
				switch (zhizhenbiao[i].zhizhen->mingzi[0]) {
				case'a':;
				case'A':yiju[i] = "��"; break;
				case'b':;
				case'B':yiju[i] = "��"; break;
				case'c':;
				case'C':yiju[i] = "��"; break;
				case'd':;
				case'D':yiju[i] = "��"; break;
				case'e':;
				case'E':yiju[i] = "��"; break;
				case'f':;
				case'F':yiju[i] = "��"; break;
				case'g':;
				case'G':yiju[i] = "��"; break;
				case'h':;
				case'H':yiju[i] = "��"; break;
				case'i':;
				case'I':yiju[i] = "��"; break;
				case'j':;
				case'J':yiju[i] = "��"; break;
				case'k':;
				case'K':yiju[i] = "��"; break;
				case'l':;
				case'L':yiju[i] = "��"; break;
				case'm':;
				case'M':yiju[i] = "��"; break;
				case'n':;
				case'N':yiju[i] = "��"; break;
				case'o':;
				case'O':yiju[i] = "Ŷ"; break;
				case'p':;
				case'P':yiju[i] = "ž"; break;
				case'q':;
				case'Q':yiju[i] = "��"; break;
				case'r':;
				case'R':yiju[i] = "Ȼ"; break;
				case's':;
				case'S':yiju[i] = "��"; break;
				case't':;
				case'T':yiju[i] = "��"; break;
				case'u':;
				case'U':yiju[i] = "��"; break;
				case'v':;
				case'V':yiju[i] = "��"; break;
				case'w':;
				case'W':yiju[i] = "��"; break;
				case'x':;
				case'X':yiju[i] = "��"; break;
				case'y':;
				case'Y':yiju[i] = "ѹ"; break;
				case'z':;
				case'Z':yiju[i] = "��"; break;
				}
				g = 2;
				break;
			}//��ĸת�����ֿ�ʼ��������break
			yiju[i][g] = zhizhenbiao[i].zhizhen->mingzi[g];
			zhongwen++;
		}
		if(zhongwen&&zhizhenbiao[i].zhizhen->mingzi[g] == '\0')yiju[i][g] = '\0';
	}
	//ð������//
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
				zhizhenbiao[i + 1].zhizhen = linshi;                          //ָ�����ָ��ֵ
				/*for (int g = 0; g < 3; g++) {
					linshizf = yiju[i][g];
					yiju[i][g] = yiju[i + 1][g];
					yiju[i + 1][g] = linshizf;
				}//�������ݱ�*/
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
	system("title SlaEpic�绰��");
}
void xieru() {
	wenjian.open(wenjianming, ios::in | ios::out | ios::binary | ios::trunc);
	wenjian.seekp(0);
	wenjian.write((char*)set, sizeof(shezhi));
	for (int i = 0; i < xunzhao(); i++)wenjian.write((char*)zhizhenbiao[i].zhizhen, sizeof(ren));
	wenjian.close();
}
void duqu()
{
	wenjian.open(wenjianming, ios::in | ios::binary);
	wenjian.read((char*)set, sizeof(shezhi));
	for (int i = 0; i < set->renshu; i++) {
		zhizhenbiao[i].zhizhen = new ren;
		wenjian.read((char*)zhizhenbiao[i].zhizhen, sizeof(ren));
		zhizhenbiao[i].zhuangtai++;
		if (i > biaochang - 10)zhengli();
	}
	wenjian.close();
}
void zhuxiao()
{
	delete set;
	for (int i = 0; i < xunzhao(); i++)delete zhizhenbiao[i].zhizhen;
	delete[] zhizhenbiao;
	return;
}