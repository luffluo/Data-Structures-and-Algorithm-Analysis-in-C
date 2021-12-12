#include "head.h"

int main(void)
{
    string str = str_new("Hello World");
    // string str2 = str_new("Hello Dream");

    // str_print(&str);
    printf("%d\n", str_len(&str));

    string hello = str_new("dd");
    // str_sub(&hello, &str, 1, 5);
    // str_print(&hello);
    // printf("%d\n", str_len(&hello));

    // printf("%d\n", str_compare(&str2, &hello));

    printf("%d\n", str_index(&str, &hello));

    return 0;
}

string str_new(const char *s)
{
    string str = {"", 0};
    str_copy(&str, s);

    return str;
}

void str_copy(string *str, const char *s)
{
    int i = 0;
    for ( ; ; i++) {
        if (s[i] == '\0') {
            break;
        }

        str->chars[i] = s[i];
    }

    str->length = i;
}

// 匹配模式 1
// 也就是查找子串在主串中的位置
int str_index1(string *str, string *sub)
{
    if (str->length < sub->length) {
        return -1;
    }

    string temp = str_new("");
    for (int i = 0, end = str->length - sub->length; i < end; i++) {
        if (!str_sub(&temp, str, i, sub->length)) {
            continue;
        }

        if (str_compare(&temp, sub) == 0) {
            return i;
        }
    }
    
    return -1;
}

int str_index(string *str, string *sub)
{
    int k = 0;
    int i = k, j = k;
    int valid_index = str->length - sub->length + 1;

    while (i < str->length && j < sub->length) {
        if (str->chars[i] == sub->chars[j]) {
            i++;
            j++;
        } else {
            k++;
            i = k;

            // 如果最后的字符不够字串的长度
            // 就结束匹配
            if (i > valid_index) {
                break;
            }

            j = 0;
        }
    }
    
    if (j == sub->length) {
        return k;
    }

    return -1;
}

int str_sub(string *sub, string *str, int start, int length)
{
    if ((str->length - start) < length) {
        return 0;
    }

    sub->length = length;

    for (int i = start, j = 0; j < length; i++) {
        sub->chars[j++] = str->chars[i];
    }

    return 1;
}

int str_len(string *str)
{
    return str->length;
}

int str_compare(string *s1, string *s2)
{
    for (int i = 0; i < s1->length; i++) {
        if (s1->chars[i] > s2->chars[i]) {
            return 1;
        } else if (s1->chars[i] < s2->chars[i]) {
            return -1;
        }
    }

    if (s1->length > s2->length) {
        return 1;
    } else if (s1->length < s2->length) {
        return -1;
    }

    return 0;
}

void str_print(string *str)
{
    printf("%s\n", str->chars);
}
