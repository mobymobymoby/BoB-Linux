#include <stdio.h>

#define BUF_SIZE 1024

void training_rm()
{
	FILE*  fp = NULL;
    int    n  = 0;
	char   buf[BUF_SIZE] = {0,};

    system("ls -f /etc > sort_test_file");

	fp = fopen("sort.txt", "r");
	fread(buf, sizeof(buf), 1, fp);

	n = read_txt(buf, n);
	run_command("cat sort_test_file");

	n = read_txt(buf, n);
	run_command("sort sort_test_file");
    
    n = read_txt(buf, n);
	fclose(fp);

	system("rm sort_test_file");

	printf("\n");
}