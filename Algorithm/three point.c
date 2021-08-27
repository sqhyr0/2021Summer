/*
三点顺序
利用矢量叉乘判断
以A为向量起点，对于AB*AC，由向量积的右手定则可知
AB*AC>0 逆时针
AB*AC<0 顺时针
AB*AC=0 ABC三点共线
*/
#include<stdio.h>
int main()
{
    int x1,y1;
    int x2,y2;
    int x3,y3;
    scanf("%d%d",&x1,&y1);//A
    scanf("%d%d",&x2,&y2);//B
    scanf("%d%d",&x3,&y3);//C
    int ax=x2-x1;
    int ay=y2-y1;
    int bx=x3-x1;
    int by=y3-y1;
    int res=ax*by-bx*ay;
    if(res>0)printf("三点按逆时针给出\n");
    else if(res<0)printf("三点按顺时针给出\n");
    else printf("三点共线\n");


}