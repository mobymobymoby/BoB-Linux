#include <stdio.h>

#define BUF_SIZE 1024

void training_rm()
{
	FILE*  fp = NULL;
    int    n  = 0;
	char   buf[BUF_SIZE] = {0,};

    system("touch rm_test_file");
    system("mkdir rm_test_dir");

	fp = fopen("rm.txt", "r");
	fread(buf, sizeof(buf), 1, fp);

	n = read_txt(buf, n);
	run_command("rm rm_test_file");

	n = read_txt(buf, n);
	run_command("rm -r rm_test_dir");
    
    n = read_txt(buf, n);
	fclose(fp);

	printf("\n");
}