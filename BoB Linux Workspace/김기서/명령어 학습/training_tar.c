#include <stdio.h>

#define BUF_SIZE 1024

void training_tar()
{
	FILE*  fp = NULL;
    int    n  = 0;
	char   buf[BUF_SIZE] = {0,};

    system("touch file1 file2 file3");

	fp = fopen("tar.txt", "r");
	fread(buf, sizeof(buf), 1, fp);

	n = read_txt(buf, n);
	run_command("tar -cvf test.tar file1 file2 file3");

	n = read_txt(buf, n);
	run_command("tar -lf test.tar");
    
	n = read_txt(buf, n);
	run_command("tar -xvf test.tar");

    n = read_txt(buf, n);
	fclose(fp);

	system("rm file1 file2 file3 test.tar");

	printf("\n");
}