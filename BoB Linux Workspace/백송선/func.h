#ifndef __FUNC_H__
#define __FUNC_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define CMD_SIZE 40 // 최대 39개의 문자 입력
#define DIR_SIZE 40 // 최대 39개의 문자 입력
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
int call_training(char select);
int convert_training(char select[]);
void create_defdir(void);
void delete_defdir(void);
void advanced_trainer(void);
void essential_trainer(void);


void training_whoami(void);
void training_pwd(void);
void training_which(void);
void training_whereis(void);
void training_alias(void);
void training_chsh(void);
void training_man(void);
void training_cmp(void);
void training_diff(void);
void training_comm(void);
void training_locate(void);
void training_pipe(void);
void training_ps(void);
void training_grep(void);
void training_apt(void);
void training_vi(void);
#endif
