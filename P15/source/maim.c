#define _CRT_SECURE_NO_WARNINGS // 添加这行来禁用相关警告，放在代码开头或者在包含头文件之前

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fptrl, *fptr2;
	char ch;
	errno_t err1 = fopen_s(&fptrl, "welcome.txt", "r");
	errno_t err2 = fopen_s(&fptr2, "output.txt", "w");

	if (err1 == 0 && err2 == 0 && fptrl != NULL && fptr2 != NULL)
	{
		while ((ch = getc(fptrl)) != EOF)
			putc(ch, fptr2);

		fclose(fptrl);
		fclose(fptr2);
		printf("檔案拷貝完成!!\n");
	}
	else
		printf("檔案開啟失敗!!\n");

	system("pause");
	return 0;
}
