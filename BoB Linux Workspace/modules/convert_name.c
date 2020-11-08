#include "func.h"

int convert_training(char select[])
{
    // 김기서 
    if (!strcmp(select, "file"))
        training_file();
    else if (!strcmp(select, "find"))
        training_find();
    else if (!strcmp(select, "history"))
        training_history();
    else if (!strcmp(select, "make"))
        training_make();
    else if (!strcmp(select, "more"))
        training_more_less();
    else if (!strcmp(select, "mount"))
        training_mount();
    else if (!strcmp(select, "sort"))
        training_sort();
    else if (!strcmp(select, "tar"))
        training_tar();
    else if (!strcmp(select, "umask"))
        training_umask();
    else if (!strcmp(select, "uname"))
        training_uselect();

    // 김청준
    else if (!strcmp(select, "curl"))
        training_curl();
    else if (!strcmp(select, "group"))
        training_group();
    else if (!strcmp(select, "head"))
        training_head_tail();
    else if (!strcmp(select, "lsblk"))
        training_lsblk();
    else if (!strcmp(select, "mkfs"))
        training_mkfs();
    else if (!strcmp(select, "ping"))
        training_ping();
    else if (!strcmp(select, "sed"))
        training_sed();
    else if (!strcmp(select, "user"))
        training_user_passwd();

    // 노무승
    else if (!strcmp(select, "fsck"))
        training_fsck();
    else if (!strcmp(select, "halt"))
        training_halt();
    else if (!strcmp(select, "ifconfig"))
        training_ifconfig();
    else if (!strcmp(select, "init"))
        training_init();
    else if (!strcmp(select, "kill"))
        training_kill();
    else if (!strcmp(select, "nano"))
        training_nano();
    else if (!strcmp(select, "netstat"))
        training_netstat();
    else if (!strcmp(select, "poweroff"))
        training_poweroff();
    else if (!strcmp(select, "reboot"))
        training_reboot();
    else if (!strcmp(select, "runlevel"))
        training_runlevel();
    else if (!strcmp(select, "shutdown"))
        training_shutdown();
    else if (!strcmp(select, "su"))
        training_su();
    else if (!strcmp(select, "sudo"))
        training_sudo();
    else if (!strcmp(select, "top"))
        training_top();
    else if (!strcmp(select, "wget"))
        training_wget();

    // 백송선
    else if (!strcmp(select, ""))
        training_();

    // 이안나
    else if (!strcmp(select, "chmod"))
        training_chmod();
    else if (!strcmp(select, "chown"))
        training_chown();
    else if (!strcmp(select, "chroot"))
        training_chroot();
    else if (!strcmp(select, "dd"))
        training_dd();
    else if (!strcmp(select, "echo"))
        training_echo();
    else if (!strcmp(select, "env"))
        training_env();
    else if (!strcmp(select, "export"))
        training_export();
    else if (!strcmp(select, "ln"))
        training_ln();
    else if (!strcmp(select, "redirection"))
        training_redirection();  
    else if (!strcmp(select, "users"))
        training_users();
    else
    {
        printf("잘못된 값을 입력하셨습니다.\n");
        return -1;
    }
    return 0;

}
