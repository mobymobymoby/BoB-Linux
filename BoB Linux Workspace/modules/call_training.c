#include "func.h"

int call_training(char select)
{
    // 문자열 정수로 변환
    int num = atoi(select);
    
    // 김기서 명령어
    switch(num)
    {
    case 1:
        training_file();
        break;
    case 2:
        training_find();
        break;
    case 3:
        training_history();
        break;
    case 4:
        training_make();
        break;
    case 5:
        training_more_less();
        break;
    case 6:
        training_mount();
        break;
    case 7:
        training_sort();
        break;
    case 8:
        training_tar();
        break;
    case 9:
        training_umask();
        break;
    case 10:
        training_uname();
        break;

    // 김청준 명령어
    case 11:
        training_curl();
        break;
    case 12:
        training_group();
        break;
    case 13:
        training_head_tail();
        break;
    case 14:
        training_lsblk();
        break;
    case 15:
        training_mkfs();
        break;
    case 16:
        training_ping();
        break;
    case 17:
        training_sed();
        break;
    case 18:
        training_user_passwd();
        break;

    // 노무승 명령어
    case 19:
        training_fsck();
        break;
    case 20:
        training_halt();
        break;
    case 21:
        training_ifconfig();
        break;
    case 22:
        training_init();
        break;
    case 23:
        training_kill();
        break;
    case 24:
        training_nano();
        break;
    case 25:
        training_netstat();
        break;
    case 26:
        training_poweroff();
        break;
    case 27:
        training_reboot();
        break;
    case 28:
        training_runlevel();
        break;
    case 29:
        training_shutdown();
        break;
    case 30:
        training_su();
        break;
    case 31:
        training_sudo();
        break;
    case 32:
        training_top();
        break;
    case 33:
        training_wget();
        break;

    // 백송선 명령어
    case 34:
        break;
    case 35:
        break;
    case 36:
        break;
    case 37:
        break;
    case 38:
        break;
    case 39:
        break;
    case 40:
        break;
    case 41:
        break;
    case 42:
        break;
    case 43:
        break;
    case 44:
        break;
    case 45:
        break;
    // 이안나 명령어
    case 46:
        training_chmod();
        break;
    case 47:
        training_chown();
        break;
    case 48:
        training_chroot();
        break;
    case 49:
        training_dd();
        break;
    case 50:
        training_echo();
        break;
    case 51:
        training_env();
        break;
    case 52:
        training_export();
        break;
    case 53:
        training_ln();
        break;
    case 54:
        training_redirection();
        break;
    case 55:
        training_users();
        break;
    default:
        printf("잘못된 값을 입력하셨습니다.\n");
        return -1;
    }
    return 0;
}
