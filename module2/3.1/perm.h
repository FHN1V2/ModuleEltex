#ifndef PERM_H
#define PERM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>

#define OWNER_SHIFT 6
#define GROUP_SHIFT 3
#define OTHER_SHIFT 0

mode_t parse_symbolic_perms(const char *perm_str);
mode_t parse_octal_perms(const char *perm_str);
void print_perm_modes(mode_t mode);
void show_file_permissions(const char *filename);
mode_t modify_perms(mode_t current, const char *cmd);

#endif
