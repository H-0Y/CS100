//
//  main.c
//  HW3
//
//  Created by Apple on 2019/10/13.
//  Copyright © 2019 huangly. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define RES_SIZE 128
#define NAME_SIZE 64

int compare (const char* str1, const char* str2)
{
    int c1=0;
    do
    {
        if(str1[c1]>str2[c1])
            return 1;
        else if(str1[c1]<str2[c1])
            return -1;
        else
        {
            //            if(sizeof(str1)/sizeof(char)==(c1-1)&&sizeof(str2)/sizeof(char)==(c1-1))
            if(str1[c1]==str2[c1]&&str1[c1]=='\0')//数组越界 假设只有\0,c1-1???
                return 0;
            c1++;
        }
    }
    while(1);//while中写（1）是一直循环直到return一个值跳出，但如果写str1==str2就会直接跳过前面两步
}

void string_sort (char* strings[], int size)//char* strings[]代表储存数组的数组，or字符串指针的指针
{
    int result=0;
    char* str3;
    for(int i=0;i<size;i++)
    {
        for(int j=1;j<size;j++)
        {
            result = compare(strings[j-1],strings[j]);
            if(result==1)
            {
                str3=strings[j-1];
                strings[j-1]=strings[j];
                strings[j]=str3;
            }
        }
    }
}

int length(const char *string)
{
    int count = 0;
    while(*(string+count))
        count++;
    return count;
}

typedef struct
{
    char name[NAME_SIZE];
    float score;
} Student;

Student* new_student(const char* _name, float _score)//声明一个返回Student型结构体指针的函数
{
    int len;
    len = length(_name);
    Student *newstudent =(Student *)malloc(sizeof(Student));//可以用结构体作为类型名来声明指针
    for(int i=0;i<=len;i++)
    {
        (*newstudent).name[i] = _name[i];
    }
    (*newstudent).score= _score;//((*newstudent).score==newstudent->score
    
    return newstudent;
    
}
typedef struct _node
{
    Student *data;
    struct _node *next;//完整结构体声明才能再次结构体中声明指向该结构体的指针
} Node;

typedef struct
{
    Node *head;//先有Node才能有Linkedlist的结构体，因为该结构体中会有Node型的head and tail 指针
    Node *tail;
    int size;
} LinkedList;

void list_init(LinkedList* l)
{
    l->head=NULL;
    l->tail=NULL;
    l->size=0;
}


void list_insert(LinkedList* l, Student* stu_ptr)
{
    Node* p;
    if(l->size==0)//从0到1，特殊
    {
        p=(Node *)malloc(sizeof(Node));//开辟内存空间给p 开辟时才用malloc
        l->head=p;
        l->tail=p;
        l->size++;
        p->data=stu_ptr;
    }
    else
    {
        p=(Node *)malloc(sizeof(Node));
        l->tail->next=p;//必须是tail的next
        l->tail=p;
        l->size++;
        p->data=stu_ptr;
    }//非从0到1d时，tail->next指向p；p值赋给tail,不要忘size变化和数据添加；然后tail的next不用再管了，结束时tail的next也就是p->next无赋值
}

void list_erase(LinkedList* l)
{
    Node* p;
    Node* q;
    for(p=l->head;p;p=q)//使用->时一定要判断左边是否是NULL(机械化固定操作）
    {
        q=p->next;
        free(p);
    }
    list_init(l);
}

Node* list_remove(LinkedList* l, Node* target)
{
    Node* q;
    Node* p;
    for (q=NULL, p=l->head;p;q=p,p=p->next)
    {
        
        if(p->data==target->data)
        {
            if (p==l->tail)
            {
                if(l->size==1)
                {
                    free(p);
                    list_init(l);
                    return NULL;
                }
                else
                {
                    l->tail=q;
                    q->next=NULL;
                    free(p);
                    l->size--;
                    return NULL;
                }
            }
            
            
            if (q)
            {
                q->next=p->next;
                free(p);// 注意三个点 每种情况都要 free，size--，return
                l->size--;
                return q->next;
            }
            else if(q==NULL)
            {
                l->head=p->next;
                free(p);
                l->size--;
                return l->head;
            }
        }
    }
    return NULL;
}
Node* list_search_by_name(LinkedList* l, char* search_name)
{
    Node *p;
    for( p=l->head;p;p=p->next)
    {
        if(compare(p->data->name, search_name)==0)//p->data->name是一个数组；字符串指针 char* x
            return p;
    }
    return NULL;
}

int list_search_by_score(LinkedList* l,
                         float lower_bound,
                         float upper_bound,
                         char* result[RES_SIZE])//char* result[RES_SIZE]是储存数组的数组；
{
    Node *p;
    int i=0;
    for( p=l->head;p;p=p->next)
    {
        if(p->data->score >= lower_bound && p->data->score <= upper_bound)
        {
            result[i]=p->data->name;
            i++;
        }
    }
    string_sort (result, i);
    return i;
    
}

//#include <stdio.h>
////计算char* string 中字符串多少的两种算法,不能用sizeof或/sizeof(char),只有char _name[]才行
//int length2(char* string)
//{
//    int count=0;
//    while(*(string+count))//\0的指针是NULL string+1表示下一个字母的指针 *(string+1)表示取这个指针指向的值 &是取其地址而不是取其值
//        count++;
//    return count;
//}
//int length1(char string[])
//{
//    int count = 0;
//    while (string[count] != '\0')
//        count++;
//    return count;
//}// 此方法也不包括\0
//int main() {
//    char* _name;
//    _name="Hello world";//赋字符用"" 此方法不包括\0
//    int i,p;
//    i=length2(_name);
//    p=length1(_name);
//    printf("%d %d\n",i,p);
//    return 0;
//}
