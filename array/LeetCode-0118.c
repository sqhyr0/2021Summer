#include<stdio.h>
int** generate(int numRows, int* returnSize, int** returnColumnSizes)
{
    int**  res=(int**)malloc(sizeof(int*)*numRows);//二级指针，下辖numrows个一维数组，每个一维数组就是杨辉三角的一行
    *returnSize=numRows;//二位数组的行数，即numRows行
    *returnColumnSizes=(int*)malloc(sizeof(int)*numRows);//这个二维数组仅有一列，每行储存杨辉三角对应行的元素个数
    for(int i=0;i<numRows;i++)
    {
        res[i]=(int*)malloc(sizeof(int)*(i+1));
        res[i][0]=res[i][i]=1;//每行的首尾元素皆为1
        (*returnColumnSizes)[i]=i+1;//每行的元素个数为i+1
        for(int j=1;j<=i-1;j++)
        {
            res[i][j]=res[i-1][j-1]+res[i-1][j];
        }
    }
    return res;
}
int main()
{
    
}