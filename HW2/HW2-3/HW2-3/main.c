//
//  main.c
//  HW2-3
//
//  Created by Apple on 2019/10/3.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//int result2=10000000,q=0,result1=0;
//for(int i=0;i<=m-n;i++)
//{
//    for(int l=i;l<i+n;l++)
//    {
//        result1=result1+abs(a[l]-b[q]);
//        q++;//变量清零，不要忘
//    }
//    q=0;
//    if(result1<result2)
//    {
//        result2=result1;
//    }
//    result1=0;//变量清零，不要忘
//}
//return result2;
//}
//
//int opt(int *a,int *b,int m,int n,int result)
//{
//    int result2=100000000,q=0,result1=0;
//    int i=0;//循环中以及条件括号中声明的变量只能循环中用
//    while(result2!=result)
//    {
//        for(int l=i;l<i+n;l++)
//        {
//            result1=result1+abs(a[l]-b[q]);
//            q++;
//        }
//        q=0;
//        if(result1<result2)
//        {
//            result2=result1;
//        }
//        result1=0;//变量清零，不要忘
//        i++;
//
//    }
//    return i-1;
//}

int dif(int *a,int *b,int m,int n)
{
    int result1=0,result2=0,p=0,x=0;
    for(int i=0;i<=m-n;i++)
    {
        for(int l=i;l-i<n;l++)
        {
            result1=result1+abs(a[l]-b[p]);
            p++;
        }
        p=0;
        while(x==0)
        {
            result2=result1;
            x++;
        }
        if(result1<result2)
        {
            result2=result1;
        }
        result1=0;
    }
    return result2;
}

int opt(int *a,int *b,int m,int n,int result)
{
    int result1=0,result2=0,p=0,x=0,y=0;
    for(int i=0;i<=m-n;i++)
    {
        for(int l=i;l-i<n;l++)
        {
            result1=result1+abs(a[l]-b[p]);
            p++;
        }
        p=0;
        while(x==0)
        {
            result2=result1;
            x++;
        }
        if(result1<result2)
        {
            result2=result1;
        }
        result1=0;
        if(result2==result)
            break;
        y++;
    }
    return y;
}
int main() {
    int i=5,l=5,A=0,B=0,n=0,m=0,result=0,p=0;
    int *a=(int *)malloc(i*sizeof(int));
    int *b=(int *)malloc(l*sizeof(int));
    memset(a,0,i*sizeof(int));
    memset(b,0,i*sizeof(int));
    printf("Please input the set A:\n");
    while(A!=-1)
    {
        scanf("%d",&A);//scanf里非指针变量要加&,且不可加a newline
        if(A!=-1)
        {
            a[m]=A;
            m++;
            if(m==i)
            {
                printf("(resize) from %d to %d\n",i,i*2);
                i=i*2;
                a=(int *)realloc(a,i*sizeof(int));
            }
        }
    }
    printf("Please input the set B:\n");
    while(B!=-1)
    {
        scanf("%d",&B);
        if(B!=-1)
        {
            b[n]=B;
            n++;
            if(n==l)
            {
                printf("(resize) from %d to %d\n",l,l*2);
                l=l*2;
                b=(int *)realloc(b,l*sizeof(int));//细心！！！！！此处重新分配的是b,不是a! run time error 数组没有分配成功或者没有初始化
            }
        }
    }
    result=dif(a,b,m,n);
    p=opt(a,b,m,n,result);
    printf("---Result---\n");
    for(int k=p;k<p+n;k++)
    {
        printf("%d ",a[k]);
    }
    printf("\n");
    free(a);
    free(b);//用完动态数组要记得释放。
    return 0;
}
