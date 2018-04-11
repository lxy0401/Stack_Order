#include <stddef.h>
#include "seqstack1.h"

int StackOrder(char input[],size_t input_size,char output[],size_t output_size)
{
    //循环把Input元素入栈
    SeqStact stack;
    SeqStactInit(&stack);
    size_t output_index=0;
    size_t i=0;
    for(;i<input_size;++i)
    {
        SeqStactPush(&stack,input[i]);
        char top;
        int ret=SeqStactTop(&stack,&top);
        if(ret == 0)
        {
            break;
        }
        //取栈顶元素与output_index做比较
        while(1)
        {
            //若栈顶元素!=output_index,则结束循环，让下一个input元素入栈
            //若栈顶元素=output_index
            //(1)移进output_index
            //(2)把栈顶元素移出栈
            //(3)循环到比较栈顶元素与output_index指向的值
            if(output_index>=output_size)
            {
                //output遍历完了
                break;
            }
            if(top!=output[output_index])
            {
                break;
            }
            ++output_index;
            SeqStactPop(&stack);
        }
    }
    //若最终栈为空，output_index指向output中最后一个元素的next元素，则返回能够为“1”
    //否则为不能，返回“0”
    if(stack.size==0&&output_index==output_size)
    {
        return 1;
    }
    return 0;
}

/***
 *
 * 以下为测试代码
 *
 * ***/

#include <stdio.h>
#define TEST_HEADER printf("\n========%s=========\n",__FUNCTION__)
void Test()
{
    TEST_HEADER;
    SeqStact stack;
    SeqStactInit(&stack);
    //SeqStactPush(&stack,'a');
    //SeqStactPush(&stack,'b');
    //SeqStactPush(&stack,'c');
    //SeqStactPush(&stack,'d');
    char a[]={'a','b','c','d'};
    char b[]={'a','b','c','d'};
    int ret;
    ret = StackOrder(a,4,b,4);
    printf("ret expected 1,actuall %d\n",ret);

    char c[]={'a','d','b','c'};
    ret = StackOrder(a,4,c,4);
    printf("ret expected 0,actuall %d\n",ret);
}

int main()
{
    Test();
    return 0;
}
