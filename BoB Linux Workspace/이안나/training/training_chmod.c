#include "common_func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_chmod(void)
{
	char def_dir[DIR_SIZE];
	char rst_dir[DIR_SIZE + 10];
	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());
	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);

	chdir(def_dir);

	//////////////////////////////////////////////////////////////////////////////////////////////////////

    //실습할 파일&디렉토리 제공
    system("touch file1 file2");
	system("chmod 000 file1");
	system("chmod 000 file2");

	printf("이번에 학습할 명령어는 'chmod'입니다.\n\n");
	getchar();
	printf("chmod는 사용자가 파일이나 디렉터리에 접근할 수 있는 허가권을 설정하는 명령어입니다.\n\n");
	getchar();
	printf("chmod 명령어는 다음과 같은 형식으로 사용됩니다.\n$ chmod [option] mode file(s)\noption은 선택 사항이며 해당 명령어에 지정할 옵션,\nmode는 숫자 모드, 또는 문자 모드로 지정할 권한을 입력,\nfile(s)는 허가권을 변경할 파일명을 입력하여 사용합니다.\n\n");
	getchar();
	printf("chmod에서 자주 사용하는 옵션은 다음과 같습니다.\n -R, --recursive : 디렉토리 내부의 모든 하위 디렉토리와 파일의 접근 권한을 변경합니다.\n -c, --change : 변경 정보를 출력합니다.\n -f, --silent, --quite : 중요한 오류메시지가 아닌 경우 출력하지 않습니다.\n --version : 명령어의 버전 정보를 표시합니다.\n\n");
	getchar();
	printf("chmod 명령어는 두가지 모드가 존재합니다.\n\n");
	getchar();
	printf("[문자(symbolic) 모드]\n알파벳 기호를 사용해 허가권을 지정합니다.\n");
	getchar();
	printf("1) 사용자 기호\n u : 파일 소유자\n g : 그룹\n o : 다른 사용자\n a : 모든 그룹, 사용자\n");
	getchar();
	printf("2) 설정 기호\n + : 권한 설정\n - : 권한 설정 해제\n");
	getchar();
	printf("3) 권한 기호\n r : 읽기\n w : 쓰기\n x : 실행\n\n");
	getchar();
	printf("만약 모든 사용자 및 그룹에게 모든 권한을 부여하고 싶다면\n명령어는 'chmod ugo+rwx 파일명'\n또는 'chmod a+rwx 파일명'으로 사용됩니다.\n\n");
	getchar();
	printf("[숫자(numeric) 모드]\n8진수의 값(4, 2, 1, 0)을 사용해 허가권을 지정합니다.\n읽기 권한은 4, 쓰기 권한은 2, 실행 권한은 1 이라는 가중치의 값을 부여하고\n여러 권한을 지정할 경우 해당 값을 더해서 지정합니다.\n");
	getchar();
	printf("만약 읽기, 쓰기, 실행의 모든 권한을 지정하고 싶다면 값은 세 값을 모두 더한 4+2+1 = 7이 됩니다.");
	getchar();
	printf("명령어 사용 시 세자리 수의 값을 입력하여 각각 소유자, 그룹, 다른 사용자의 권한을 따로 지정하며\n100의 자리 위치는 소유자 권한,\n10의 자리 위치는 그룹 권한,\n1의자리 위치는 다른 사용자 권한,\n순서대로 'chmod 소유자권한 그룹권한 다른사용자권한' 입니다.\n");
	getchar();
	printf("예를 들어 소유자는 모든 권한, 그룹과 다른 사용자는 읽기 쓰기 권한만 부여하고 싶다면\n명령어는 'chmod 766 파일명'으로 사용됩니다.\n\n");
	getchar();

	system("ls -al");
	printf("\n현재 디렉토리에 file1, file2가 있습니다.\n\n");
	getchar();
	printf("chmod 명령의 기호 모드를 사용해 file1에 대한 소유자에게 쓰기 권한,\n그룹과 다른 사용자에게 읽기 권한을 부여해보세요.\n각 사용자마다 권한을 다르게 부여할 경우 콤마 기호(,)를 사용해 'u+x,go+r'과 같이 구분합니다.\n\n");
    run_command("chmod u+x,go+r file1");

	printf("chmod 명령의 숫자 모드를 사용해 file2에 대한 소유자에게 쓰기 권한,\n그룹과 다른 사용자에게 읽기 권한을 부여해보세요.\n(읽기 권한은 4, 쓰기 권한은 2, 실행 권한은 1입니다.)\n\n");
    run_command("chmod 244 file2");

	printf("\n");
	system("ls -al");
	printf("\n파일 목록을 출력하면 권한이 성공적으로 부여된 것을 확인할 수 있습니다.\n\n");
	
	printf("chmod 명령어에 대한 학습이 끝났습니다.");

    snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
}

int main()
{
	training_chmod();
	next_quit();
	printf("이 메시지가 출력된다면 next 기능이 정상적으로 실행된 것\n");
	return 0;
}
