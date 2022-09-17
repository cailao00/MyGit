#include<iostream>
#include<fstream>
#include<string>
#define MAXSIZE 10000
using namespace std;
/*
���Ĳ���
*/

typedef struct sentence {
	string word;	//��¼����
	int len;		//��¼����
}sentence;

sentence sen[MAXSIZE];	//��Ŷ����ԭ��
sentence csen[MAXSIZE];	//��Ŷ���ĳ���
int num[5000][5000];	//��¼״ֵ̬������ʶ���ַ��Ƿ���ͬ
int olen = 0;			//ԭ�ı�����
int clen = 0;			//���ı�����
double Num = 0;			//������
void LCS(int len);

void original(string file) {	//ԭ�ı�����
	ifstream ifs;
	ifs.open(file, ios::in);	//�Զ��ķ������ļ�
	if (!ifs.is_open()) {
		cout << "�ļ���ȡʧ��" << endl;
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

void copy(string file) {		//��Ϯ�ı�����
	ifstream ifs;
	ifs.open(file, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ���ʧ�ܣ�" << endl;
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
		cout << "�ļ��򿪳ɹ���" << endl;
	}
	ifs.close();
}

void LCS(int len) {			//�ö�̬�滮�㷨���
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
	cout << "copy rate:" << 2 * Num / (olen - 1) << endl;	//���в���
	//ofstream ofs;
	//ofs.open(argv[3], ios::app);
	//ofs << "copy rate:" << 2 * Num / (olen - 1) << endl;
	//ofs.close();
	system("pause");
	return 0;
}