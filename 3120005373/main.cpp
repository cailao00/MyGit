#include<iostream>
#include<fstream>
#include<string>
#define MAXSIZE 10000
using namespace std;
/*
论文查重
*/

typedef struct sentence {
	string word;	//记录句子
	int len;		//记录字数
}sentence;

sentence sen[MAXSIZE];	//存放读入的原文
sentence csen[MAXSIZE];	//存放读入的抄文
int num[5000][5000];	//记录状态值，用于识别字符是否相同
int olen = 0;			//原文本长度
int clen = 0;			//抄文本长度
double Num = 0;			//查重数
void LCS(int len);

void original(string file) {	//原文本输入
	ifstream ifs;
	ifs.open(file, ios::in);	//以读的方法打开文件
	if (!ifs.is_open()) {
		cout << "文件读取失败" << endl;
		return;
	}
	else {
		string s;
		while (getline(ifs, s)) {
			sen[olen].word = s;
			sen[olen].len = s.length();
			olen++;
		}
	}
	ifs.close();
}

void copy(string file) {		//抄袭文本输入
	ifstream ifs;
	ifs.open(file, ios::in);
	if (!ifs.is_open()) {
		cout << "文件打开失败！" << endl;
		return;
	}
	else {
		string s;
		while (getline(ifs, s)) {
			csen[clen].word = s;
			csen[clen].len = s.length();
			LCS(clen);
			clen++;
		}
		cout << "文件打开成功！" << endl;
	}
	ifs.close();
}

void LCS(int len) {			//用动态规划算法求解
	int max = 0;
	string a, b;
	for (int i = 0; i < sen[len].len; i++) {
		for (int j = 0; j < csen[len].len; j++) {
			a = sen[len].word;
			b = csen[len].word;
			if (a[i] == b[j]) {
				num[i + 1][j + 1] = num[i][j] + 1;
				max = num[i + 1][j + 1] > max ? num[i + 1][j + 1] : max;
				if (max >= 7) {
					Num++;
					break;
				}
			}
			else if (num[i][j + 1] > num[i + 1][j]) {
				num[i + 1][j + 1] = num[i][j + 1];
			}
			else {
				num[i + 1][j + 1] = num[i + 1][j];
			}
		}
		if (max >= 7) {
			break;
		}
	}
}

//int main(int argc, char * argv[]) {
int main(){
	original("E://Visual Studio//text//orig.txt");
	copy("E://Visual Studio//text//orig_0.8_add.txt");
	//cout << "original file:" << argv[1] << endl;
	//cout << "copy file:" << argv[2] << endl;
	//cout << "output file:" << argv[3] << endl;
	//original(argv[1]);
	//copy(argv[2]);
	memset(num, 0, olen);
	cout << "copy rate:" << 2 * Num / (olen - 1) << endl;	//空行不算
	//ofstream ofs;
	//ofs.open(argv[3], ios::app);
	//ofs << "copy rate:" << 2 * Num / (olen - 1) << endl;
	//ofs.close();
	system("pause");
	return 0;
}