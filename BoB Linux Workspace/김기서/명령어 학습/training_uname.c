#include <stdio.h>

#define BUF_SIZE 1024

void training_rm()
{
	FILE*  fp = NULL;
    int    n  = 0;
	char   buf[BUF_SIZE] = {0,};

	fp = fopen("uname.txt", "r");
	fread(buf, sizeof(buf), 1, fp);

	n = read_txt(buf, n);
	run_command("uname");

	n = read_txt(buf, n);
	run_command("uname -a");
    
    n = read_txt(buf, n);
	fclose(fp);

	printf("\n");
}