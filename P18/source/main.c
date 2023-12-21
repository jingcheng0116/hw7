#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main(void)
{
	FILE *in, *out;
	char str[MAX];
	char *token;

	errno_t err1 = fopen_s(&in, "welcome.txt", "r");
	errno_t err2 = fopen_s(&out, "output.txt", "w");

	if (err1 != 0 || err2 != 0 || in == NULL || out == NULL) {
		printf("檔案開啟失敗!!\n");
		return 1;
	}

	while (fgets(str, sizeof(str), in) != NULL)
	{
		token = strtok(str, " \t\n"); // 以空格和制表符作为分隔符拆分单词
		while (token != NULL)
		{
			fprintf(out, "%s\n", token); // 每个单词单独写入一行
			token = strtok(NULL, " \t\n");
		}
	}

	fclose(in);
	fclose(out);
	system("pause");
	return 0;
}