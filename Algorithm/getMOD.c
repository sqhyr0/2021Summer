/*
高次方求模
核心公式为p%q=((p1%q)*(p2%q)*...*(pn%q))%q，其中p1*p2*...*pn=p
利用快速幂算法降低复杂度
采用非递归形式，将n视作二进制，每次右移一位，并与1按位与计算
*/
#include<stdio.h>
int main()
{
    long long  p,n,q;
    scanf("%lld%lld%lld",&p,&n,&q);
    p%=q;
    long long res=1;
    while(n>0)
    {
        if(n&1)res=res*p%q;//此时由于p%=q，实际上在第一轮，对q连续求了两次模，但无影响
        p=p*p%q;
        n>>=1;
    }
    printf("%lld",res);

}