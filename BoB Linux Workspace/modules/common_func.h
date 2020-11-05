#ifndef __COMMON_FUNC_H__
#define __COMMON_FUNC_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define CMD_SIZE 40 // 최대 39개의 문자 입력
#define DIR_SIZE 40 // 최대 39개의 문자 입력
#define BUF_SIZE 102400

void next_quit(void);
int run_command(char valid_cmd[]);
int fake_run_command(char valid_cmd[]);
int fake_command(char valid_cmd[], char print_msg[]);
#endif
