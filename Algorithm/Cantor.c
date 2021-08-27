#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char *str=(char*)malloc(sizeof(char)*21);
    scanf("%s",str);//输入待计算Cantor展开的组合
    int Cantor=0;
    for(int i=0;str[i]!='\0';i++)
    {
        int temp=0;//用于统计每一位数字在所有未出场数字中的位次
        int temp2=1;//阶乘
        for(int j=i+1;str[j]!='\0';j++)//每次从待统计数字的后一位开始
        {
            if(str[i]>str[j])temp++;
            temp2*=j-i;
        }
        Cantor+=temp*temp2;
    }
    printf("比%s小的组合有%d个，故%s的位次为%d",str,Cantor,str,Cantor+1);
}