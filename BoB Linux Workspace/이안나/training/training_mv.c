#include "func.h"

int run_command(char valid_cmd[]);
void next_quit();

void training_mv(void)
{
    create_defdir();
    system("clear");

	//////////////////////////////////////////////////////////////////////////////////////////////////////

    //실습할 파일&디렉토리 제공
    system("mkdir dir1 dir2");
    system("touch dir1/file1");


    printf("이번에 학습할 명령어는 'mv'입니다.\n\nmv는 파일이나 디렉터리를 이동할 때 사용되는 명령어입니다.\n");
    next_line();
    printf("mv 명령어는 다음과 같은 형식으로 사용합니다.\n$ mv [옵션] [source(s)] [destination]\n");
    next_line();
    printf("option은 선택 사항이며 해당 명령어에 지정할 옵션, \nsources는 옮기고자 하는 파일명 또는 디렉토리명,\ndestination에는 옮길 위치를 입력합니다.\n\n");
    next_line();
    printf("mv에서 자주 사용하는 옵션은 다음과 같습니다.\n");
    next_line();
    printf("-i : 이동할 디렉토리에 동일한 파일명이 존재할 경우 덮어 쓸 것인지 물어봅니다. (yes - y /no - n)\n-f : 같은 파일의 이름이 존재하는 경우에 강제로 덮어씁니다.\n-b : 덮어쓸 때 백업본 파일을 만듭니다.\n-v : 파일을 이동할 때 이동 내용을 출력합니다.\n-u : 이동할 디렉터리에 동일한 파일명이 있을 경우 검사하여 해당 파일이 최신 파일이면 이동하지 않습니다.\n\n");
    next_line();
    printf("그럼 dir1에 있는 file1을 dir2로 이동시켜 봅시다.\n");
    next_line();

    printf("우선 \'ls -al\'명령으로 파일 목록을 확인해봅시다.\n");
    system("ls -al");
    next_line();
    printf("[dir1]\n");
    system("ls -l dir1");

    printf("\n\n현재 dir1에는 file1이 들어있습니다.\n이동시킬 파일의 위치는 \"dir1/file1\"이고, 이동할 위치는 \"dir2\"입니다.\nmv 명령어를 입력해 파일을 이동시켜보세요.\n");
    run_command("mv dir1/file1 dir2");
    printf("\nls 명령으로 dir2에 file1이 잘 이동되었는지 확인해봅시다.\n\n\"ls -l dir2\"를 입력하세요.\n");
    run_command("ls -l dir2");
    //system("ls dir2");
    printf("\nmv는 파일이나 디렉토리를 이동할 때도 사용되지만, 이름을 변경하고자 할 때도 사용됩니다.\n파일을 동일한 디렉토리 안에서 이동할 경우 이름이 변경됩니다.\n\n");
    next_line();
    printf("같은 dir2안에서 file1을 file2로 이름을 바꿔봅시다.\n변경할 파일은 \"dir2/file1\" 이고 변경할 위치는 \"dir2/file2\"입니다.\nmv 명령어를 입력해 파일 이름을 변경해보세요.\n");
    run_command("mv dir2/file1 dir2/file2");
    printf("\nls 명령으로 dir2에 file1의 이름이 file2로 변경되었는지 확인해봅시다.\n\n \"ls -l dir2\"를 입력하세요.\n");
    run_command("ls -l dir2");
    //system("ls dir2");
    printf("\n파일 이름이 성공적으로 file2로 변경된 것이 보입니다.");
    next_line();
    printf("\nmv 명령어에 대한 학습이 끝났습니다. \n");

    delete_defdir();
}

