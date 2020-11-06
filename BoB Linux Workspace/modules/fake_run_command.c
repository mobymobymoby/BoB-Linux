#include "common_func.h"

// fake_run_command는 run_command와 같지만, system 함수를 통해 실제로 명령어를 실행시키지는 않음
int fake_run_command(char valid_cmd[])
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
			// fakecommand에서는 입력 값 검증만 수행하며, 실제로 명령어를 실행시키지는 않음
			break;
		}
		else
		{
			printf("잘못된 명령어를 입력하셨습니다.\n");
		}
	}
	return 0;
}
