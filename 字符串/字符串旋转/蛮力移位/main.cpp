/*
 *暴力移位法，将需要移动的字符一个一个的移动到字符串的尾部。
 *
 *时间复杂度 O(mn) 空间复杂度O(1)
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


/* ----------------------------------------------------------------------*/
/**
 * @brief:LeftShiftOne      旋转字符串的一个字符，将首字符旋转为尾字符
 *
 * @param:s                 字符串数组
 * @param:n                 字符串长度
 */
/* ----------------------------------------------------------------------*/
void LeftShiftOne(char *s, int n)
{
    char t = s[0];
    for(int i = 1; i < n; ++i)
    {
        s[i - 1] = s[i];
    }
    s[n - 1] = t;
}


/* ----------------------------------------------------------------------*/
/**
 * @brief:LeftRotataString  旋转字符串的前n个字符，即将字符串的前n个字符变
 *                          为尾部的n个字符
 *
 * @param:s                 字符串数组
 * @param:n                 字符串的长度
 * @param:m                 旋转的字符个数
 */
/* ----------------------------------------------------------------------*/
void LeftRotataString(char *s, int n, int m)
{
    while( m-- )
    {
        LeftShiftOne(s, n);
    }
}


int main(int argc, char *argv[])
{
    if(argc <= 2)
    {
        printf("Para less [<=3] !!\n");
        return 1;
    }

    int n = strlen(argv[1]);
    int m = atoi(argv[2]);
    if(m >= n)
    {
        printf("Rotate Length[%d] >= string_len[%d]\n", m, n);
        return 0;
    }
    printf("Raw String[%s]\n", argv[1]);
    LeftRotataString(argv[1], n, m);
    printf("Rotate String[%s]\n", argv[1]);
    return 0;
}




