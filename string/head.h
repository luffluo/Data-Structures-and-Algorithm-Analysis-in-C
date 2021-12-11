#ifndef _STRING_HEAD_H
#define _STRING_HEAD_H

#include <stdio.h>

#define MAX_SIZE 255

typedef struct {
    char chars[MAX_SIZE];
    int length;
} string;

string str_new(const char *s);
int str_index(string *str, string *sub);
void str_copy(string *str, const char *s);
void str_print(string *str);
int str_len(string *str);
int str_sub(string *sub, string *str, int start, int length);
int str_compare(string *s1, string *s2);

#endif