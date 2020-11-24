#include "func.h"

extern char def_dir[DIR_SIZE];
extern char rst_dir[DIR_SIZE + 10];
extern char rm_dir[DIR_SIZE + 10];

void create_defdir(void)
{
	snprintf(def_dir, sizeof(def_dir), "/home/%s/tr", getlogin());

	snprintf(rst_dir, sizeof(rst_dir), "rm -rf %s", def_dir);
	system(rst_dir);
	strncpy(rm_dir, rst_dir, sizeof(rm_dir));

	snprintf(rst_dir, sizeof(rst_dir), "mkdir %s", def_dir);
	system(rst_dir);

	chdir(def_dir);
}
