/*
read_txt : 한 글자씩 읽어오고, 마지막으로 읽은 위치를 리턴하는 함수 
mkdir 명령어 기준으로 작성
by 김청준 
*/

#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 1024

int read_txt(char buf[], int n)
{
  // txt 파일을 읽어온 'buf' array에서 한 글자씩 읽어옴
  // 글자를 읽는 것은 '@'를 만나거나 파일의 끝(NULL)이 될 때 까지
  // 즉 @를 한 문장을 끝내는 플래그로 사용
	for(; buf[n] != '@' && buf[n] != '\0'; n++)
	{
    
		printf("%c", buf[n]);
		// 출력 버퍼 비우기
		fflush(stdout);
		// 한 글자씩 출력되는 효과를 위한 sleep
		usleep(30000);
		
	}
	
	return n+1;
}
	

void training_mkdir(void)
{
	FILE *fp;
	fp = fopen("1.txt", "r");
	char buf[BUF_SIZE] = {0,};
	fread(buf, sizeof(buf), 1, fp);
	
	int n = 0;
	n = read_txt(buf, n);
	
	fclose(fp);
}

int main()
{
	training_mkdir();
	
	return 0;
}
	 
