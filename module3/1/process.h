#ifndef PROCESS_H
#define PROCESS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

int is_number(const char *str);

void process_arguments(char *args[], int start, int end);

void process_with_fork(char *argv[], int argc);

#endif