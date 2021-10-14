//
//  main.c
//  HW1-2
//
//  Created by Apple on 2019/9/22.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <stdio.h>
#include <math.h>
double sqrt(double x);

int main() {
    float a,b,c,d,e,f,h,i,j,k,l;
    printf("Input vertex 1: ");
    scanf("%f %f",&a,&b);      //sacnf(%f %f) 不能写成（%f,%f)!!!!!
    printf("Input vertex 2: ");
    scanf("%f %f",&c,&d);
    printf("Input vertex 3: ");
    scanf("%f %f",&e,&f);
    h=(a+c+e)/3.0;
    i=(b+d+f)/3.0;
    printf("The center of the triangle is: %.1f %.1f\n",h,i);
    j=sqrt((a-h)*(a-h)+(b-i)*(b-i));
    k=sqrt((c-h)*(c-h)+(d-i)*(d-i));
    l=sqrt((e-h)*(e-h)+(f-i)*(f-i));
    if(k>=j&&k>=l){
        printf("The maximum distance between center and vertices: %.2f\n",k);
    }
    else if(l>=j&&l>=k){
        printf("The maximum distance between center and vertices: %.2f\n",l);
    }
    else if(j>=k&&j>=l){
        printf("The maximum distance between center and vertices: %.2f\n",j);
    }
    if(k<=j&&k<=l){
        printf("The minimum distance between center and vertices: %.2f\n",k);
    }
    else if(l<=j&&l<=k){
        printf("The minimum distance between center and vertices: %.2f\n",l);
    }
    else if(j<=k&&j<=l){
        printf("The minimum distance between center and vertices: %.2f\n",j);
    }
    return 0;
}
