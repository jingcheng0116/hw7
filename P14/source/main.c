#define _CRT_SECURE_NO_WARNINGS // 添加这行来禁用相关警告，放在代码开头或者在包含头文件之前

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fptr;
	char ch;
	int Count = 0;

	errno_t err = fopen_s(&fptr, "welcome.txt", "r"); // 使用 fopen_s 替换 fopen
	if (err == 0 && fptr != NULL)
	{
		while ((ch = getc(fptr)) != EOF)
		{
			printf("%c", ch);
			Count++;
		}
		fclose(fptr);
		printf("\n總共有%d個字元\n", Count);
	}
	else
		printf("檔案開啟失敗!!\n");
	system("pause");
	return 0;
}