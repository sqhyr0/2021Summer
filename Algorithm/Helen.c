#include<stdio.h>
#include<math.h>
int main()
{
    double x1,y1,x2,y2,x3,y3,k1,k2,L,L1,L2,L3,A;
    scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
    k1=(y1-y2)/(x1-x2);
    k2=(y1-y3)/(x1-x3);
    if(k1==k2)
        printf("Impossible");
    else
    {
        L1=sqrt(pow(x1-x2,2)+pow(y1-y2,2));
        L2=sqrt(pow(x1-x3,2)+pow(y1-y3,2));
        L3=sqrt(pow(x2-x3,2)+pow(y2-y3,2));
        L=L1+L2+L3;
        A=sqrt(0.5*L*(L*0.5-L1)*(L*0.5-L2)*(L*0.5-L3));
        printf("L = %.2f, A = %.2f",L,A);
    }
    return 0;
}