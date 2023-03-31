/*  ѧϰ����ָ��
	ѧϰ�ص�����
	����ָ����һ���������������һ�������ĵ�ַ
	����ָ�������Ӧ�ú�ָ��ĺ���������һ��
	�Զ����һ�������Ĳ�����һ������ָ��
	��һ������ָ���ʼ��Ϊһ��ͬ���͵ĺ�����
	��ͨ���Զ���ĺ���������ָ�봫�ݸ��βΣ��ﵽ���ú�����Ŀ��
*/
#include <iostream>
#include <string>
#include <ctype.h>
#define LEN 81
char* get_s(char* st, int n);

char show_meun();

/*�Ե�������ʣ��*/
void eating();

/*���뺯��ָ�� �ú���ָ����� str*/
void show(void (*fp)(char*), char* str);

/*���ַ�����Ϊ��д*/
void Toupper(char* str);

/*���ַ�����ΪСд*/
void Tolower(char* str);

/*��Сдת��*/
void Tarnspose(char*);

/*���ı��ַ���*/
void Dummy(char* str);

using namespace std;

int main() {
	char line[LEN] = "";
	char copy[LEN];
	char choice;
	void (*pfun)(char*) = NULL;					//����һ������ָ��
	puts("enter a string (empty line to quit!)");
	while (gets_s(line,LEN) != NULL && line[0] != '\0')
	{

		while ((choice = show_meun()) != 'n')
		{
			switch (choice) {
			case 'u':
				pfun = Toupper;
				break;
			case 'l':
				pfun = Tolower;
				break;
			case 't':
				pfun = Tarnspose;
				break;
			case 'o':
				pfun = Dummy;
				break;
			}
			strcpy_s(copy, line);
			show(pfun, copy);
		}
		puts("enter a next string or (enter empty lin to quit)");
	}
	puts("bye!");
	return 0;
}
/*���ı��ַ���*/
void Dummy(char* str) {

}
/*��Сдת��*/
void Tarnspose(char* str) {
	while (*str)
	{
		if (islower(*str)) {
			*str = toupper(*str);
		}
		else if (isupper(*str)) {
			*str = tolower(*str);
		}
		str++;
	}
}
/*���ַ�����ΪСд*/
void Tolower(char* str) {
	while (*str != '\0')
	{
		*str = tolower(*str);
		str++;
	}
}

/*���ַ�����Ϊ��д*/
void Toupper(char* str) {
	while (*str != '\0')
	{
		*str = toupper(*str);
		str++;
	}
}

/*���뺯��ָ�� �ú���ָ����� str*/
void show(void (*fp)(char*), char* str) {
	(fp)(str);
	puts(str);
}

/* ����˵����õ�ѡ�� ������ */
char show_meun() {
	char ans;
	puts("enter menu chios:");
	puts("u) uppercase        l)lowercase");
	puts("t)  transposed case  o) original case ");
	puts("n) next string ");
	ans = getchar();
	ans = tolower(ans);
	eating();
	while (strchr("ulton", ans) == NULL)				//�������Ĳ����������Χ
	{
		puts("please enter u l t o n ");
		ans = tolower(getchar());
		eating();
	}
	return ans;
}


/* ����ַ���n-1���ַ���  �Զ����*/
/* '\0' ���ַ��������������з�����!*/
char* get_s(char* st, int n) {

	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');		//�ҵ����з�
		if (find) {
			*find = '\0';
		}
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

/*�Ե�������ʣ��*/
void eating() {
	while (getchar() != '\n')
		continue;
}
