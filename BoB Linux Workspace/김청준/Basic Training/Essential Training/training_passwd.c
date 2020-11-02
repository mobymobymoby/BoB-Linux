#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "common_func.h"

void training_passwd(void)
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

    printf("이번에 학습할 명령어는 'adduser', 'userdel', 'passwd'입니다.\n");
    getchar();
    printf("이 명령어들은 사용자 계정과 관련된 동작들을 합니다.\n");
    getchar();
    printf("계정을 관리하는 역할은 일반적으로 관리자 계정인 'root'의 역할이므로, 일반 사용자는 해당 명령어들을 사용하지 못합니다.\n");
    getchar();
    printf("따라서 이 명령어 들은 root 계정을 통해 수행할 수 있습니다.\n");
    getchar();
    printf("이름에서도 충분히 유추할 수 있듯, adduser 명령어는 새로운 사용자 계정을 생성합니다.\n");
    getchar();
    printf("기본적인 사용법은 다음과 같습니다.\n");
    getchar();
    printf("$ adduser [옵션] [생성할 계정 이름]");
    getchar();
    printf("아무런 옵션을 주지 않고, adduser [생성할 계정 이름]의 문법으로 사용하면 지정한 이름으로 계정을 생성합니다.\n");
    getchar();
    printf("이 때 사용할 계정의 비밀번호를 입력하게 되고, 추가적으로 이름이나 전화번호 등 인적사항을 기입하게 됩니다.\n");
    getchar();
    printf("다만, 인적사항은 필수로 기입해야하는 것은 아니며 Enter를 입력하여 넘어가도 큰 문제는 없습니다.\n");
    getchar();
    printf("adduser를 이용해 'user1'이라는 이름을 가진 사용자 계정을 생성해보세요.\n");
    printf("(이번 트레이닝을 진행할 동안 계정을 관리할 수 있도록 당신의 권한을 잠시 상승시켜 드리겠습니다.)\n");
    
    fake_run_command("adduser user1");
    printf("Adding user `user1' ...\n");
    printf("Adding new group `user1' (1001) ...\n");
    printf("Adding new user `user1' (1001) with group `user1' ...");
    printf("Creating home directory `/home/user1' ...\n");
    printf("Copying files from `/etc/skel' ...\n");
    getchar();

    printf("user1이라는 계정을 만들기 위해 여러 가지 작업을 수행하는 모습이 출력됩니다.\n");
    getchar();
    printf("출력 결과를 하나 하나 살펴보겠습니다.\n");
    getchar();
    printf("Adding user `user1' ... : 우리가 지정한 이름인 'user1'을 계정에 추가하고 있다는 의미입니다.\n");
    getchar();
    printf("Adding new group `user1' (1001) ... : user1의 '그룹'을 따로 지정해주지 않았기 때문에\n");
    printf("지정한 사용자 계정 이름과 동일한 이름(user1)으로 group을 생성합니다. (1001)은 생성한 그룹의 GID(Group ID)입니다.\n");
    getchar();
    printf("이 때 일반적으로 GID는 생성된 계정의 UID와 일치합니다.\n");
    getchar();
    printf("Adding new user `user1' (1001) with group `user1' ... : 생성한 'user1' 그룹에 'user1' 계정을 포함시킨다는 의미입니다.\n");
    getchar();
    printf("Creating home directory `/home/user1' ... : 생성한 계정의 홈 디렉토리를 '/home/user1'로 지정합니다.\n");
    printf("일반적으로 홈 디렉토리는 '/home/[사용자 계정 이름]'으로 지정됩니다.\n");
    getchar();
    printf("Copying files from `/etc/skel' ... : /etc/skel에는 계정 생성시에 홈 디렉토리에 복사될 파일을 놓을 수 있습니다.\n");
    getchar();
    printf("계정을 새로 생성하면 /etc/skel에 저장되어 있는 파일이 자동으로 홈 디렉토리에 복사됩니다.\n");
    getchar();

    printf("다시 'adduser user1'을 입력한 상태로 돌아오겠습니다.\n");
    getchar();
    printf("현재 우리가 입력한 것에서는 사용자 계정 이름만 지정했고, 비밀번호를 입력하지 않았습니다.\n");
    getchar();
    printf("위에서 출력된 내용들이 나온 후에 사용자 계정의 비밀번호를 입력하라는 메시지('Enter new UNIX password')와 재확인(Retype) 메시지가 나옵니다.\n");
    getchar();
    printf("user1 계정의 비밀번호를 'BoB-Linux'로 설정하세요.\n");
    getchar();
    fake_command("BoB-Linux", "Enter new UNIX password: ");
    fake_command("BoB-Linux", "Retype new UNIX password: ");
    printf("passwd: password updated successfully\n");
    getchar();

    printf("비밀번호를 입력한 후에는 패스워드가 성공적으로 업데이트 되었다는 메시지 후에 user1의 정보를 입력하라는 메시지가 나옵니다.\n");
    getchar();
    printf("이 정보들은 선택사항이며, 이름, 방 번호, 전화번호, 집 전화번호 등을 입력할 수 있습니다.\n");
    getchar();
    printf("아무 정보나 입력해보세요.\n");
    getchar();
    printf("Changing the user information for user1\nEnter the new value, or press ENTER for the default\n");
    usleep(3000);
    char tmp_buf[40];
    printf("	Full Name []: ");
    fgets(tmp_buf, 30, stdin);
    printf("	Room Number []: ");
    fgets(tmp_buf, 30, stdin);
    printf("	Work Phone []: ");
    fgets(tmp_buf, 30, stdin);
    printf("	Home Phone []: ");
    fgets(tmp_buf, 30, stdin);
    printf("	Other []: ");
    fgets(tmp_buf, 30, stdin);
    printf("마지막으로는 입력한 정보가 맞는지 확인하는 메시지가 출력됩니다. Y를 입력하세요.\n");
    getchar();
    fake_command("Y","Is the information correct? [Y/n] ");
    
    printf("위에서는 입력값을 Y로 제한했지만, 원래는 Y를 입력하지 않고, n을 입력한다면 다시 정보들을 입력받게 됩니다.\n");
    getchar();
    
    printf("아래는 adduser의 옵션입니다.\n");
    printf("$ adduser [옵션] [생성할 계정 이름]\n");
    printf("-u : 사용자 계정의 UID를 지정하여 생성합니다. 앞에서는 이 옵션을 주지 않아 UID가 자동 할당 되었습니다.\n");
    printf("-g : 사용자 계정의 GID를 지정합니다. 앞에서는 이 옵션을 주지 않아 UID가 자동 할당 되었습니다.\n");
    printf("-d : 사용자의 홈 디렉토리를 지정합니다. 이 옵션을 주지 않으면 '/home/[사용자 계정명]' 디렉토리로 지정됩니다.\n");
    printf("-e : 사용자의 계정 만기일을 지정합니다.\n");
    getchar();

    printf("계정을 생성하는 방법을 알았으니, 삭제하는 방법도 알아야 할 것입니다.\n");
    getchar();
    printf("'userdel' 명령어는 간단하게 사용자 계정을 삭제할 수 있습니다.\n");
    getchar();
    printf("기본 사용법은 다음과 같습니다.\n");
    getchar();


    printf("passwd 명령어는 'password'의 약자로, 계정의 비밀번호와 관련된 명령어입니다.\n");
    getchar();
    printf("기본적인 사용법은 아무런 옵션도 주지 않고 사용하는 것입니다.\n");
    getchar();
    printf("$ passwd\n");
    getchar();
    printf("해당 명령어를 입력하면 현재 로그인 된 사용자의 비밀번호를 변경하게 됩니다.\n");
    getchar();
    printf("이 때 현재 로그인된 사용자의 비밀번호를 알고 있어야 비밀번호를 변경할 수 있습니다.\n");
    getchar();

    printf("passwd 명령어는 옵션을 주어 사용하기도 합니다.\n");
    getchar();
    printf("주로 여러 계정을 관리하는 관리자(root)에 의해서 passwd 명령어가 수행됩니다.\n");
    getchar();
    printf("옵션과 함께 사용할 때 기본 문법은 다음과 같습니다.\n");
    getchar();
    printf("$ passwd [옵션] [사용자 계정]\n");
    getchar();

    printf("옵션을 주지 않고 passwd [사용자 계정]으로 사용하면 [사용자 계정]에 해당하는 계정의 비밀번호를 변경할 수 있습니다.\n");
    getchar();
    printf("위에서 언급했듯, passwd 명령어는 보통 root 계정에 의해 수행됩니다.\n");
    getchar();
    printf("루트 권한이 없는 일반 사용자는 passwd 명령어를 자신의 계정 비밀번호를 변경하는 용도로 밖에 사용하지 못합니다.\n");
    getchar();
    printf("root 계정은 관리자 계정이기 때문에 다른 사용자의 비밀번호와 다양한 설정을 변경할 수 있습니다.\n");
    getchar();
    printf("이렇듯, root 계정은 다른 사용자에 비해 막강한 권한을 가지고 있기 때문에 root 계정이 유출되서는 안되는 것입니다.\n");

    printf("다시 passwd 명령어로 돌아와서, 사용자의 정보을 보기 위해서는 -S(status의 약자) 옵션을 사용합니다.\n");
    getchar();
    

    // Delete default directory
	chdir(def_dir);
	chdir("..");
	system(rm_dir);
}