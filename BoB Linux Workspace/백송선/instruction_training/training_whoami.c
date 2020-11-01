#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>

#include "common_func.h"

void main(void)
{
	char def_dir[DIR_SIZE];
	char rst_dir[DIR_SIZE + 10];
	char rm_dir[DIR_SIZE + 10];
	
	struct passwd *lpwd;
	lpwd = getpwuid(geteuid());

	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());

	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	strncpy(rm_dir, rst_dir, sizeof(rm_dir));
	
	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);
	
	chdir(def_dir);

	printf("\n\"whoami\" 명령어를 배워보겠습니다.\n\"whoami\" 명령어는 현재 로그인한 사용자 계정의 이름, 'EUID(Effective User ID)'를 보여줍니다.\n");
	getchar();
	printf("\"whoami\" 명령어는 영어에서 \"내가 누구인가\"를 말할 때 \"who am i?\" 라고 하는 것에서 비롯되었습니다.\n");
	getchar();
	printf("\"whoami\" 명령어는 '현재 로그인한 사용자의 이름'을 보여줍니다.\n");
	getchar();
	printf("만일 사용자가 'User1'으로 처음 로그인을 했다가 'User2'으로 로그인하여 계정을 바꾼 후 \"whoami\" 명령어를 입력한다면\n현재 로그인 되어있는 계정은 'User2'이기 때문에 'User2'를 보여줄 것입니다.\n");
	getchar();
	printf("\"whoami\" 명령어는 '현재 로그인 되어 있는 사용자의 이름'을 보여준다는 것을 기억하셔야 합니다.\n후에 나올 비슷한 명령어와의 차이점이 될 점입니다.\n");
	getchar();
	printf("\"whoami\" 명령어는 리눅스 시스템 내에서 'root' 디렉터리(폴더) 밑에 'usr' 디렉터리(폴더) 밑에 'bin' 디렉터리(폴더) 밑에 \"whoami\"로 있습니다.\n");
	getchar();
	printf("\"whoami\" 명령어가 보여주는 결과는 뒤에서 언급 될 \"id\" 명령어에 옵션 'u' 와 'n'을 줘서 \"id -un\"의 결과와 같습니다.\n");
	getchar();
	printf("\"whoami\" 명령어는 리눅스 이외에도 다른 Unix 계열의 운영체제와 윈도우 혹은 윈도우 서버에서도 사용 가능한 명령어입니다.\n");
	getchar();
	printf("\"whoami\" 명령어를 직접 입력하여 현재 로그인 되어 있는 사용자 계정의 이름을 확인해보세요.\n");
	run_command("whoami");
	printf("위에 보이시는 \"%s\"이 현재 로그인된 사용자 계정의 이름 즉, 'EUID'입니다.\n", lpwd->pw_name);
	getchar();
	printf("사용자 계정의 ID를 보여주는 명령어는 \"whoami\"와 비슷하게 생긴 \"who am i\"가 있습니다.\n");
	getchar();
	printf("\"whoami\"와 \"who am i\" 명령어의 차이점은 EUID를 보여주는지, UID를 보여주는지 입니다.\n");
	printf("즉 \"현재 로그인된 사용자 계정(EUID)\"를 보여주는지 \"특정 사용자를 나타내는 고유 숫자(UID)\"를 보여주는지 입니다.\n");
	getchar();
	printf("\"whoami\"는 현재 로그인이 되어있는 계정을 보여주지만\n");
	printf("\"who am i\"는 처음 'user1'으로 로그인 한 후 'User2'로 로그인하여 사용자 계정을 바꾼 후에도\n현재 로그인 되어 있는 'User2'가 아니라 처음 로그인 했던 'User1'을 보여줍니다.\n");
	getchar();
	printf("그리고 비슷한 명령어로는 다음의 것들이 있습니다.\n");
	printf("\"who\" - 현재 시스템에 로그인 되어 있는 사용자를 출력해줍니다.\n");
	printf("\"w\" - 로그인된 사용자와 수행 중인 작업을 출력해줍니다.\n");
	printf("\"users\" - 시스템에 로그인 되어있는 사용자의 아이디를 출력해줍니다.\n");
	printf("\"logname\" - 사용자의 계정을 출력해줍니다. (\"users\"와 같은 결과값을 보여줍니다.)\n");
	printf("\"id\" - 시스템에 등록된 아이디 정보를 출력해줍니다. 더 자세히는 현재 사용자 정보인 UID와 GID 등을 보여줍니다.\n");
	getchar();
	printf("\"whoami\" 명령어의 학습이 끝났습니다.\n다른 운영체제에서도 \"whoami\" 명령어를 사용해보시고 다른 명령어들도 한 번씩 실습하여 결과를 확인해보세요\n");
	getchar();

	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}
