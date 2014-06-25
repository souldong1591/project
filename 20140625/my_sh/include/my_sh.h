#ifndef __MY_SH__
#define __MY_SH__
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <string.h>

void trim_space(char *str);

void del_command(char *str, char *arglist[]);

void path_name(char *str);


#endif
