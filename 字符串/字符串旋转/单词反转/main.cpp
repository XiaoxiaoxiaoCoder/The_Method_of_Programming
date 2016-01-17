
/*
 *题目:
 *    输入一个英文句子，翻转句子中单词的顺序。要求单词内的字符的顺序不变，句子中单词以空格符隔开。
 *为简单起见，标点符号和普通字符一样处理。例如: 输入 "I am a studeng.", 则输出 "student. a am I"
 */

/*
 *解法:
 *(1) 先将句子以空格为分隔符切分为单词  (特别注意连续的空格与最后一个单词)
 *(2) 将单词在单词内部反转
 *(3) 将单词反转后得到的句子整体反转一次
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
 * @brief:LeftRotateWord    翻转句子中的单词
 *
 * @param:s                 字符串数组
 * @param:n                 字符串长度
 */
/* ----------------------------------------------------------------------*/
void LeftRotateWord(char *s, int n)
{
    int from = -1;
    int to   = -1;
    for(int i = 0; i < n; ++i) 
    {
        if(from < 0 && s[i] == ' ')     //连续的空格，直接无视
        {
            continue;
        }

        if( from < 0 && s[i] != ' ')
        {
            from = i;
            continue;
        }

        if(from >= 0 && s[i] == ' ')    //单词尾部
        {
            to = i - 1;
            ReverseString(s, from, to);
            from = -1;
            to   = -1;
            continue;
        }

        if(from >=0 && i == n - 1)      //最后一个单词，没有空格了
        {
            ReverseString(s, from, i);
            from = -1;
            to   = -1;
            continue;
        }
    }
    ReverseString(s, 0, n -1);
}

int main(int argc, char *argv[])
{

    if(argc < 2)
    {
        printf("Param lee [%d <2 ]!\n", argc);
        return 0;    
    }
    printf("Raw_String[%s]\n", argv[1]);
    LeftRotateWord(argv[1], strlen(argv[1]));
    printf("Rotate_String[%s]\n", argv[1]);

    return 0;
}
