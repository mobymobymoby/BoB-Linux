#include <stdio.h>

#define BUF_SIZE 1024

void training_more_less()
{
	FILE*  fp = NULL;
    int    n  = 0;
	char   buf[BUF_SIZE] = {0,};

	fp = fopen("moreLess.txt", "r");
	fread(buf, sizeof(buf), 1, fp);

	n = read_txt(buf, n);
	run_command("more more.txt");

    n = read_txt(buf, n);
	fclose(fp);

	printf("\n");
}