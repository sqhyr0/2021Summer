#include<stdio.h>
#include<string.h>
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    for(int i=m+n-1,p=m-1,q=n-1;i>=0;i--)
    {
        if(p<0&&q>=0)
        {
            nums1[i]=nums2[q];
            q--;
        }
        else if(p>=0&&q<0)
        {
            nums1[i]=nums1[p];
            p--;
        }
        else if(nums1[p]>=nums2[q])
        {
            nums1[i]=nums1[p];
            p--;
        }
        else
        {
            nums1[i]=nums2[q];
            q--;
        }
    }
}
int main()
{
    int nums1[1000],nums2[1000];
    memset(nums1,0,1000*sizeof(int));
    int m=0,n=0;
    while(scanf("%d",&nums1[m])!=EOF)m++;
    while(scanf("%d",&nums2[n])!=EOF)n++;
    int sum=m+n;
    merge(nums1,m+n,m,nums2,n,n);
    for(int i=0;i<sum;i++)printf("%d ",nums1[i]);
}