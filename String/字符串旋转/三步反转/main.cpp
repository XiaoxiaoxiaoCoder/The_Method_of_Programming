
/*
 *三步反转法:
 *(1) 将原字符串分为 X 和 Y 两个部分， X 为需要旋转的部分， Y 为不需要旋转的部分
 *(2) 将X所有字符反转，再降Y所有字符反转
 *(3) 最后将上述素有字符整体反转
 *
 *时间复杂度O(n) 空间复杂度O(1)
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


/* ----------------------------------------------------------------------*/
/**
 * @brief:ReverseString     反转字符串
 *
 * @param:s                 字符串指针
 * @param:from              反转字符起始处
 * @param:to                反转字符结束处
 */
/* ----------------------------------------------------------------------*/
void ReverseString(char *s, int from, int to)
{
    while(from < to)
    {
        char t = s[from];
        s[from++] = s[to];
        s[to--] = t;
    }
}

/* ----------------------------------------------------------------------*/
/**
 * @brief:LeftRotateString  将字符串左旋转指定字符数
 *
 * @param:s                 字符串数组
 * @param:n                 字符串数组长度
 * @param:m                 反转的字符个数
 */
/* ----------------------------------------------------------------------*/
void LeftRotateString(char *s, int n, int m)
{
    m %= n;         //若要左移动大于n位，那么与%n等价
    ReverseString(s, 0, m - 1);
    ReverseString(s, m, n - 1);
    ReverseString(s, 0, n - 1);
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
    LeftRotateString(argv[1], n, m);
    printf("Rotate String[%s]\n", argv[1]);
    return 0;

}
