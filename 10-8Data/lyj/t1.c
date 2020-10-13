//
// Created by Muxxs on 2020/10/8.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef void status;

typedef struct
{
    char data[10];
} SElementType;

typedef struct
{
    SElementType *top;
    SElementType *base;
    int StackSize;
} SqStack;

void DataAdd(SElementType *ptr, char mid);

status InitStack(SqStack *s) // 初始化
{
    (*s).base = (SElementType *)malloc(sizeof(SElementType) * STACK_INIT_SIZE);
    (*s).top = (*s).base;
    (*s).StackSize = STACK_INIT_SIZE;
}

status DestroyStack(SqStack *s) // 删除
{
    free((*s).base);
}

status ClearStack(SqStack *s) // 清空
{
    (*s).top = (*s).base;
}

status push(SqStack *s, SElementType e) // 插入
{
    if ((*s).StackSize == (*s).top - (*s).base)
    {
        (*s).base = (SElementType *)realloc((*s).base, sizeof(SElementType) * ((*s).StackSize + STACKINCREMENT));
        (*s).top = (*s).base + (*s).StackSize;
    }
    *(*s).top = e;
    (*s).top++;
}

status pop(SqStack *s) // 栈顶去除一个元素
{
    (*s).top--;
}

status GetTop(SqStack s, SElementType *e) // 获取栈顶
{
    *e = *(s.top-1);
}

int isEmpty(SqStack s) // 判断是否为空
{
    if (s.top == s.base)
    {
        return 1;
    }else
    {
        return 0;
}
}

SqStack StackTraverse(SqStack *s) // 反转
{
    SqStack S;
    SElementType mid;
    InitStack(&S);
    while (!isEmpty(*s))
    {
        GetTop(*s,&mid);
        pop(&s);
        push(&S, mid);
    }
    return S;
}

status Show(SqStack *s){ // 输出栈的元素
    int count = 1;
    SElementType *mid = (*s).base;
    while (mid != (*s).top)
    {
        printf("Num : %d Data : %s\n",count++,mid++->data);
    }
}

void DataAdd(SElementType *ptr, char mid) {
    for (int i = 0; i < 10; ++i) {
        if((*ptr).data[i]=='\0'){
            (*ptr).data[i]=mid;
        }
    }
}


int main() {
    SqStack OPTR; // 符号
    SqStack OPND; // 数字
    SElementType last;
    InitStack(&OPND);
    InitStack(&OPTR);
    char Target[] = "3*(7-2)",mid;
    int Statu = 0;
    // 0代表直接录入
    // 1代表数字未结束
    // sin cos
    printf("Size : %d\n",sizeof(Target)/sizeof(Target[0]));
    for (int i = 0; i < sizeof(Target)/sizeof(Target[0]); ++i) {
        mid = Target[i];
        if ((int)mid<=57 && (int)mid >= 48){
            if (Statu==1){
                GetTop(OPND,&last);
                pop(&OPND);
                sprintf(last.data, "%d",atoi(last.data)*10+atoi(mid));
                push(&OPND,last);
            } else if (Statu == 0){
                Statu = 1;
                push(&OPND, last);
            }
        } else{
            if (mid == 's' || mid == 'c' || mid == 'i' || mid== 'o' || mid== 'n'){
                if (Statu == 2){
                    GetTop(OPND,&last);
                    DataAdd(&last,mid);
                    push(&OPND,last);
                } else{
                    DataAdd(&last,mid);
                    push(&OPND,last);
                    Statu = 2;
                }
            } else{
                DataAdd(&last,mid);
                push(&OPND,last);
                Statu = 0;
            }
        }
        strcpy(last.data,"");
        printf("%c",Target[i]);
    }
    printf("\n");
    Show(&OPND);
    Show(&OPTR);
    //
}