#include "common_func.h"

void training_head(void)
{
	// 초기 작업 디렉토리 설정
	char def_dir[DIR_SIZE];
	// rst_dir은 앞에 mkdir, rm -rf의 명령어가 더 들어가기 때문에 문자열의 길이를 10 늘려줌
	char rst_dir[DIR_SIZE + 10];
	char rm_dir[DIR_SIZE + 10];

	// 현재 사용자 계정을 %s 위치에 삽입하여 디폴트 디렉토리 설정
	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());

	// 디폴트 디렉토리가 이미 있을 경우를 대비하여 삭제하는 명령어
	// rm -rf [디폴트 디렉토리]의 문자열을 rst_dir에 입력
	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	strncpy(rm_dir, rst_dir, sizeof(rm_dir));

	// 디폴트 디렉토리를 생성
	// mkdir [디폴트 디렉토리]의 문자열을 rst_dir에 입력
	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);

	// 디폴트 디렉토리로 change directory
	chdir(def_dir);

	//////////////////////////////////////////////////////////////////////////////////////////////////////

	int i = 0;
	char tmp[40];
	for(i=1; i<1000; i++)
	{
		snprintf(tmp, sizeof(tmp), "echo '%d번째 줄' >> textfile", i);
		system(tmp);
	}
	system("echo '마지막 줄' >> textfile");

    printf("이번에 학습할 명령어는 head와 tail입니다.\n");
	getchar();
	printf("우리는 기초 명령어 학습에서 'cat'에 대해서 배운적이 있습니다.\n");
	getchar();
	printf("cat은 특정 파일의 내용을 출력하는 명령어로 아주 자주 사용합니다.\n");
	getchar();
	printf("하지만, cat 명령어를 통해 어떤 파일을 볼 때 그 파일의 내용이 너무 많거나 줄(Line)수가 많다면 내용이 터미널에 표시되지 않거나 읽기 힘들 수 있습니다.\n");
	getchar();
	printf("이 때 사용할 수 있는 명령어가 바로 head와 tail입니다.\n");
	getchar();
	printf("head는 특정 파일의 내용을 맨 앞에서부터 출력할 수 있는 명령어입니다.\n");
	getchar();
	printf("아무런 옵션없이 파일이름만을 입력하면 맨 앞에서 10줄의 내용이 출력됩니다.\n");
	getchar();
	printf("사용법은 다음과 같습니다.\n$ head [옵션] [파일 이름]\n");
	getchar();
	printf("head 명령어를 이용해 아무런 옵션 없이 'textfile'의 내용을 출력해보세요.\n");
	run_command("head textfile");
	getchar();
	printf("1번째줄 부터 10번째줄까지 총 10개의 줄이 출력되었습니다.\n");
	getchar();
	printf("자신이 원하는 줄 갯수만큼 출력하기 위해서는 -n 옵션을 사용하면 됩니다.\n");
	getchar();
	printf("사용법은 다음과 같습니다.\n$ head -n [출력할 줄 개수] [파일명]");
	getchar();
	printf("head와 -n 옵션을 이용해 textfile의 내용을 20줄 출력해 보세요.\n");
	run_command("head -n 20 textfile");
	getchar();
	printf("파일의 내용이 20줄까지 정상적으로 출력되었습니다.\n");
	getchar();
	printf("-c 옵션을 이용해서 바이트(byte) 단위로 내용을 출력할 수도 있습니다.\n");
	getchar();
	printf("만약 head -c 200 textfile이라고 입력하면, 앞에서부터 200바이트 까지의 내용 만을 출력합니다.\n");
	getchar();

	printf("tail의 옵션은 head와 흡사합니다.\n");
	getchar();
	printf("다른 점이 있다면 tail은 파일의 맨 뒤의 내용을 읽어옵니다.\n");
	getchar();
	printf("tail을 아무런 옵션 없이 사용하면 맨 뒤부터 10줄까지의 내용을 출력합니다.\n");
	getchar();
	printf("tail을 옵션 없이 사용해서 textfile의 내용을 출력해보세요.\n");
	getchar();
	printf("$ tail [옵션] [파일명]\n");
	run_command("tail textfile");
	getchar();
	printf("맨 뒤에서부터 10줄의 내용이 출력됩니다.\n");
	getchar();
	printf("tail도 역시 -n 옵션을 이용해서 원하는 줄 개수 만큼 뒤에서 출력할 수 있습니다.\n");
	getchar();
	printf("tail을 이용해 뒤에서 20줄 만큼 textfile의 내용을 출력해보세요.\n");
	printf("사용법은 다음과 같습니다.\n$ tail -n [출력할 줄 개수] [파일명]\n");
	run_command("tail -n 20 textfile");
	getchar();
	printf("맨 뒤에서부터 20줄의 내용이 출력됩니다.\n");
	getchar();
	printf("head와 마찬가지로 -c 옵션을 이용해 바이트 단위로 파일의 내용을 뒤에서부터 출력할 수도 있습니다.\n");
	getchar();
	printf("tail을 이용한 특별한 기능은 어떤 파일을 모니터링 할 수 있다는 것입니다.\n");
	getchar();
	printf("로그 파일의 경우 새롭게 쌓인 내용이 맨 뒤에 추가되기 때문에 tail을 이용해 이를 추적할 수 있습니다.\n");
	getchar();
	printf("이 때 사용하는 옵션은 -f입니다. 해당 파일의 내용을 지속적으로 출력합니다.\n");
	getchar();
	printf("-f 옵션을 이용해 textfile의 내용을 추적해보세요.\n");
	printf("$ tail [옵션] [파일명]\n");
	fake_run_command("tail -f textfile");
	system("tail textfile");
	sleep(1);
	printf("잘 보고 계신가요.\n");
	sleep(1);
	printf("보시는 것 처럼 추가 되는 내용이 갱신됩니다.\n");
	sleep(1);
	printf("진행을 위해서 tail을 종료시키겠습니다. 평소 사용시에는 컨트롤 + C 키를 입력하여 tail을 종료할 수 있습니다.\n");
	printf("\n");
	printf("tail은 네트워크 모니터링 시에 쌓이는 로그를 확인하기 위해 사용하는 등 다양하게 사용할 수 있습니다.\n");
	getchar();
	printf("head와 tail의 학습이 끝났습니다.\n");

    // Delete default directory
	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}