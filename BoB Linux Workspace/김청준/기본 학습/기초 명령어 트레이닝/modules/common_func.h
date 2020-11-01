#ifndef __COMMON_FUNC_H__
#define __COMMON_FUNC_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define CMD_SIZE 40 // 理쒕? 39媛쒖쓽 臾몄옄 ?낅젰
#define DIR_SIZE 40 // 理쒕? 39媛쒖쓽 臾몄옄 ?낅젰
#define BUF_SIZE 102400

void next_quit(void);
int run_command(char valid_cmd[]);
#endif