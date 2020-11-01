#include <stdio.h>

#define BUF_SIZE 1024

void training_find()
{
	FILE*  fp = NULL;
    int    n  = 0;
	char   buf[BUF_SIZE] = {0,};

	system("touch find_test_file");

	fp = fopen("find.txt", "r");
	fread(buf, sizeof(buf), 1, fp);

	n = read_txt(buf, n);
	run_command("find find_test_file");
    
    n = read_txt(buf, n);
	fclose(fp);

	system("rm find_test_file");

	printf("\n");
}