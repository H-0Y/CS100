//
//  main.c
//  HW2-1
//
//  Created by Apple on 2019/9/29.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    float newscore=0,average=0,sum=0;
    
    int i=5;
    int a=0,b=0;
    
    float *score=NULL;
    score = (float *) malloc(i*sizeof(float));
    
    
    printf("Please type scores to be calculated:\n");
    float *ori=score;
    while(newscore!=-1)
    {
        scanf("%f",&newscore);
        
        if(newscore!=-1)
        {
            *(score++)=newscore;//没有问题
            sum+=newscore;
            a++;
            b++;
            
            if(b>=i)
            {
                printf("(resize) from %d to %d\n",i,i*2);
                i=i*2;
                ori = (float *) realloc(ori,i*sizeof(float));//不能用ori，用score才行
            }
        }
    }

    average=sum/a;
    
    free(ori);//用完要释放掉，不要占内存,score相当于索引，free和realloc里都用内存首位地址 如ori.
    
    //用完要清除
    
    printf("Average score: %.2f\n",average);
    
    
    return 0;//ori有问题！！！就用score就OK
}
//重写版
//#include <stdio.h>
//#include<stdlib.h>
//int main() {
//    float newscore=0,sum=0,average;
//    int i=5,b=0;
//    float *score=(float *)malloc(i*sizeof(float));
//    memset(score,0,i*sizeof(float));
//    printf("Please type scores to be calculated:\n");
//    while(newscore!=-1)
//    {
//        scanf("%f",&newscore);
//        if(newscore!=-1)
//        {
//            score[b]=newscore;
//            sum=sum+newscore;
//            b++;
//            if(b==i)
//            {
//                printf("(resize) from %d to %d\n",i,i*2);
//                i=i*2;
//                score=(float *)realloc(score,i*sizeof(float));
//            }
//        }
//    }
//    average=sum/b;
//    free(score);
//    printf("Average score: %.2f\n",average);
//
//    return 0;
//}
