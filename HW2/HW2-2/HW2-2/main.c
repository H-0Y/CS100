//
//  main.c
//  HW2-2
//
//  Created by Apple on 2019/10/2.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Please type scores to be calculated:\n");
    int i=5,a=0;
    float newscore=0,score1=0;
    int nsm=0,sm1=0;
    int *stunum=(int *)malloc(i*sizeof(int));
    float *score=(float *)malloc(i*sizeof(float));
    memset(score,0,i*sizeof(float));
    memset(stunum,0,i*sizeof(int));
    while(newscore!=-1)
    {
        scanf("%d %f",&nsm,&newscore);
        if(nsm!=-1)
        {
            stunum[a]=nsm;
            score[a]=newscore;
            a++;
            if(a==i)
            {
                printf("(resize) from %d to %d\n",i,i*2);//文本空格！
                printf("(resize) from %d to %d\n",i,i*2);
                i=i*2;
                stunum=(int *)realloc(stunum,i*sizeof(int));
                score=(float *)realloc(score,i*sizeof(float));
            }
                
        }
    }
    printf("---Result---\n");
    for (int i=0;i<=a-1;i++)
    {
        for (int j=1;j<=a-1;j++)
        {
        if(score[j-1]>score[j])
        {
            score1=score[j-1];
            score[j-1]=score[j];
            score[j]=score1;
            sm1=stunum[j-1];
            stunum[j-1]=stunum[j];
            stunum[j]=sm1;
        }
        else if(score[j-1]==score[j])
        {
            if(stunum[j-1]>stunum[j])
                    {
                        score1=score[j-1];
                        score[j-1]=score[j];
                        score[j]=score1;
                        sm1=stunum[j-1];
                        stunum[j-1]=stunum[j];
                        stunum[j]=sm1;
                    }
        }
        }
    }
    for(int i=0;i<a;i++)
    {
        printf("%d %.1f\n",stunum[i],score[i]);//printf和scanf括号里的%与%之间都不要加逗号
    }
    free(stunum);
    free(score);
    
    return 0;
}
