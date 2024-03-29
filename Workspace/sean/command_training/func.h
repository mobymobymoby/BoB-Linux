#ifndef __FUNC_H__
#define __FUNC_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pwd.h> // passwd 구조체 사용
#include <stdio_ext.h> // __fpurge(stdin)

#define CMD_SIZE 60 // 최대 59개의 문자 입력
#define DIR_SIZE 60 // 최대 59개의 문자 입력
#define BUF_SIZE 102400

char def_dir[DIR_SIZE];
char rst_dir[DIR_SIZE + 10];
char rm_dir[DIR_SIZE + 10];

void next_quit(void);
void next_line(void);
int run_command(char valid_cmd[]);
int just_run_command(char valid_cmd[]);
int fake_run_command(char valid_cmd[]);
int fake_command(char valid_cmd[], char print_msg[]);
int nothing_print_fake_run_command(char valid_cmd[]);
int call_training(char select[]);
int convert_name(char select[]);
void create_defdir();
void delete_defdir();
void advanced_trainer(void);
void essential_trainer(void);
void training_intro(void);
void print_banner(void);
void program_information(void);
void select_menu(void);
void training_whatislinux(void);
void training_linux_distro(void);
void training_whyneedlinux(void);
void training_linux_defdir(void);
void training_device_file(void);
void training_virtual_console(void);
void training_process_id(void);
/*
//로드맵

void roadmap_department(void);
void roadmap_department_seoul(void);
void roadmap_department_gyeonggido(void);
void roadmap_department_gangwondo(void);
void roadmap_department_daejeon(void);
void roadmap_department_chungcheongbukdo(void);
void roadmap_department_chungcheongnamdo(void);
void roadmap_department_busan(void);
void roadmap_department_gyeongsangbukdo(void);
void roadmap_department_gyeongsangnamdo(void);
void roadmap_department_gwangju(void);
void roadmap_department_jeollabukdo(void);
void roadmap_department_jeollanamdo(void);
void roadmap_department_ma(void);
*/
/* 함수 리스트 */
// 김기서 명령어
void training_clear(void);
void training_file(void);
void training_find(void);
void training_history(void);
void training_make(void);
void training_more_less(void);
void training_mount(void);
void training_rm(void);
void training_sort(void);
void training_tar(void);
void training_umask(void);
void training_uname(void);

// 김청준 명령어
void training_curl(void);
void training_group(void);
void training_head_tail(void);
void training_lsblk(void);
void training_mkfs(void);
void training_ping(void);
void training_sed(void);
void training_user_passwd(void);
void training_cat(void);
void training_mkdir(void);
void training_touch(void);

// 노무승 명령어
void training_cd(void);
void training_fsck(void);
void training_halt(void);
void training_ifconfig(void);
void training_init(void);
void training_kill(void);
void training_ls(void);
void training_nano(void);
void training_netstat(void);
void training_poweroff(void);
void training_reboot(void);
void training_runlevel(void);
void training_shutdown(void);
void training_su(void);
void training_sudo(void);
void training_top(void);
void training_wget(void);
 
// 백송선 명령어
void training_linux_basic(void);
void training_alias(void);
void training_apt(void);
void training_chsh(void);
void training_cmp(void);
void training_comm(void);
void training_diff(void);
void training_grep(void);
void training_locate(void);
void training_man(void);
void training_pipe(void);
void training_ps(void);
void training_pwd(void);
void training_vi(void);
void training_whereis(void);
void training_which(void);
void training_whoami(void);
void training_ssh(void);
void training_sftp(void);
void training_bg_fg_jobs(void);

// 이안나 명령어
void training_chmod(void);
void training_chown(void);
void training_chroot(void);
void training_cp(void);
void training_dd(void);
void training_echo(void);
void training_env(void);
void training_export(void);
void training_git(void);
void training_ln(void);
void training_mv(void);
void training_redirection(void);
void training_set_unset(void);
void training_users(void);
#endif
