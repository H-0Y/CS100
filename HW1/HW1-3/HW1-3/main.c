//时间 心情
//  main.c
//  HW1-3
//
//  Created by Apple on 2019/9/22.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <stdio.h>
int breaktime(int a,int c,int d,int f){
    int i,g;
    if(f<c){
         i=(f+60-c);
         g=(d-a-1)*60;
        
    }
    else {
         i=(f-c);
         g=(d-a)*60;
        
    }
    //考虑f<c的负情况
    int j=g+i;
    return j;
}
int main() {
    int a,b=1,c,d,e = 0,f = 0,j,x,z=0,m=1;
    int k,l,o=0,p = 0,s;
    float i=0.0,n=100.0;
    printf("How many lectures today?\n");
    scanf("%d",&a);
    for(;b<=a;b++)
    {
        if(m==1){
        scanf("%d:%2d-%d:%2d",&c,&d,&e,&f);// %2d!!!强制两位形式输入
        j=breaktime(c,d,e,f);
        i=i+j;
        if(i>60){
            x=i-60;
            z=z+x;
            i=60;
        }
        n=n-(i*0.4+z*0.8);
            if(n<=0){
            printf("Gezi Wang has been sent to hospital.");
                break;}
        m=2;
    }

    else {
        i=0.0;
        z=0;//计算时记得把数值还原！ 一场讲座内60min才会发生变化 自己手动过一遍计算过程 printf出关键步骤的数值进行检查
        scanf("%d:%2d-%d:%2d",&k,&l,&o,&p);
        s=breaktime(e,f,k,l);
        e=o;
        f=p;
        n=n+s*0.5;
        if(n>100)
            n=100;
        j=breaktime(k,l,o,p);
        i=i+j;
        
        if(i>60){
            x=i-60;
            z=z+x;
            i=60;//计算时记得把数值还原！
            }
        n=n-(i*0.4+z*0.8);
        if(n<=0){
            printf("Gezi Wang has been sent to hospital.");
            break;}
    }

 }
        if(n>0){
            int t=22;
            int u=0;
            n=n+breaktime(o,p,t,u)*0.5;
            if(n>100)
                n=100;
            printf("His mood level is %.1f at the end of the day.",n);
        }
    
    
 
    
    return 0;
}
