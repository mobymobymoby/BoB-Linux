#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void usage()
{
    puts("syntax : check <file_name>\n");
    puts("sample : check document1\n");
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        usage();
        return -1;
    }
    
    //변수 선언
    int fp = 0;
    FILE *f = NULL;
    char *buf=NULL;
    int val_size=0, file_size=0, check=0, i=0;
    int mode = O_RDONLY|O_CREAT;
    
    if(access(argv[1], F_OK))
    {
        perror("Can't access to file");
        return -2;
    }

    //파일 open
    if((fp = open(argv[1], O_RDONLY|O_CREAT)) == -1)
    {
        perror("Failed to open the file");
        return -3;
    }

    //파일 discriptor을 전달하여 fopen으로 연 것처럼 함
    if((f = fdopen(fp, "r")) == NULL)
    {
        perror("Failed to associate file descriptor with a stream");
        return -3;
    }
   
    /* 
    f = fopen(argv[1], "r");
    if(f == NULL)
    {
        perror("fopen() error\n");
        return -3;
    }
    */

    check = fseek(f, 0, SEEK_END);
    if(check != 0)
    {
        perror("fseek() error\n");
        return -4;
    }
    file_size = ftell(f);
    
    buf = malloc(file_size + 1);
    memset(buf, 0, file_size + 1);
    
    if((check = fseek(f, 0, SEEK_SET)) != 0)
    {
        perror("fseek() error\n");
        return -4;
    }

    val_size = fread(buf, file_size, 1, f);
    if(val_size != 1)
    {
        fputs("Reading error", stderr);
        exit(3);
    }
   
    char *ptr = strtok(buf, ";\n");
    while(ptr != NULL)
    {    
        printf("(%d)%s\n", ++i, ptr);
        ptr = strtok(NULL, ";\n");
    }

    fclose(f);
    close(fp);
    free(buf);

    return 0;
}
