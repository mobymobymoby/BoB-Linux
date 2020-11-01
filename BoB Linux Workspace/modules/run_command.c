#include "common_func.h"

int run_command(char valid_cmd[])
{
	char cmd[CMD_SIZE];
	char dir_buf[DIR_SIZE];
	while (1)
	{
		printf("\n");
		getcwd(dir_buf, sizeof(dir_buf));
		printf("%s@BoB:%s$ ", getlogin(), dir_buf);
		int valid_len = strlen(valid_cmd);
		fgets(cmd, sizeof(cmd), stdin);

		// 나머지 입력 값 제거
        	cmd[strlen(cmd)-1] = '\0';

		// 입력값 검증 부분
		if (!strcmp(cmd, valid_cmd))
		{
			printf("잘 입력하셨습니다.\n\n");
			// 여기서 핵심은 system 함수의 인자로 valid_cmd가 입력된다는 것임. 즉 사용자의 입력값은 사용되지 않음
			system(valid_cmd);
			printf("\n");
			break;
		}
		else
		{
			printf("잘못된 명령어를 입력하셨습니다.\n");
		}
	}
	return 0;
}
