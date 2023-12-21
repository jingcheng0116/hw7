#define _CRT_SECURE_NO_WARNINGS // 添加这行来禁用相关警告，放在代码开头或者在包含头文件之前

#include <stdio.h>
#include <stdlib.h>
#define MAX 80

int main(void)
{
	FILE *fptr;
	char str[MAX];
	int bytes;

	errno_t err = fopen_s(&fptr, "output.txt", "r");
	if (err != 0 || fptr == NULL) {
		printf("檔案開啟失敗!!\n");
		return 1;
	}

	while ((bytes = fread(str, sizeof(char), MAX - 1, fptr)) > 0)
	{
		str[bytes] = '\0'; // 手动添加字符串的结束符号
		printf("%s\n", str);
	}

	fclose(fptr);
	system("pause");
	return 0;
}