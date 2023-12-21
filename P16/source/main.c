#define _CRT_SECURE_NO_WARNINGS // 添加这行来禁用相关警告，放在代码开头或者在包含头文件之前

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define ENTER 13
#define MAX 80

int main(void)
{
	FILE *fptr;
	char str[MAX], ch;
	int i = 0;
	errno_t err = fopen_s(&fptr, "output.txt", "a");
	if (err != 0 || fptr == NULL) {
		printf("檔案開啟失敗!!\n");
		return 1;
	}

	printf("請輸入字串,按ENTER鍵結束輸入:\n");
	while ((ch = _getche()) != ENTER && i < MAX - 1) {
		str[i++] = ch;
	}
	str[i] = '\0'; // 添加字符串结束符

	putc('\n', fptr); // 换行以分隔输入和之前的内容
	fwrite(str, sizeof(char), i, fptr);
	fclose(fptr);
	printf("\n檔案附加完成!!\n");
	system("pause");
	return 0;
}