/*  学习函数指针
	学习回调函数

*/
#include <iostream>
#include <string>
#include <ctype.h>
#define LEN 81
char* get_s(char* st, int n);

char show_meun();

/*吃掉输入行剩余*/
void eating();

/*传入函数指针 用函数指针输出 str*/
void show(void (*fp)(char*), char* str);

/*将字符串变为大写*/
void Toupper(char* str);

/*将字符串变为小写*/
void Tolower(char* str);

/*大小写转置*/
void Tarnspose(char*);

/*不改变字符串*/
void Dummy(char* str);

using namespace std;

int main() {
	char line[LEN] = "";
	char copy[LEN];
	char choice;
	void (*pfun)(char*) = NULL;					//声明一个函数指针
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
/*不改变字符串*/
void Dummy(char* str) {

}
/*大小写转置*/
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
/*将字符串变为小写*/
void Tolower(char* str) {
	while (*str != '\0')
	{
		*str = tolower(*str);
		str++;
	}
}

/*将字符串变为大写*/
void Toupper(char* str) {
	while (*str != '\0')
	{
		*str = toupper(*str);
		str++;
	}
}

/*传入函数指针 用函数指针输出 str*/
void show(void (*fp)(char*), char* str) {
	(fp)(str);
	puts(str);
}

/* 输出菜单，得到选择 并返回*/
char show_meun() {
	char ans;
	puts("enter menu chios:");
	puts("u) uppercase        l)lowercase");
	puts("t)  transposed case  o) original case ");
	puts("n) next string ");
	ans = getchar();
	ans = tolower(ans);
	eating();
	while (strchr("ulton", ans) == NULL)				//如果输入的不在这五个范围
	{
		puts("please enter u l t o n ");
		ans = tolower(getchar());
		eating();
	}
	return ans;
}


/* 获得字符串n-1个字符串  自动填充*/
/* '\0' 空字符，或者遇到换行符结束!*/
char* get_s(char* st, int n) {

	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n');		//找到换行符
		if (find) {
			*find = '\0';
		}
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}

/*吃掉输入行剩余*/
void eating() {
	while (getchar() != '\n')
		continue;
}
