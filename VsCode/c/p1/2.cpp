#include <stdio.h>
#include <stdlib.h>
struct link *AppendNode(struct link *head);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);
struct link *DeleteNode(struct link *head, int nodeData);

struct link
{
    int data;
    struct link *next;
};
/*请在下方编写你的代码,仅需提交填写的部分*/

struct link *AppendNode(struct link *head)//创建链表
{
    struct link *p1, *p2;//首先创建两个链表结构体类型的指针，p1用来储存输入节点的值，p2用来方便p1的添加
    p1 = p2 = (struct link *)malloc(sizeof(struct link));
    scanf(" %d", &p1->data);//输入节点的值
    p1->next = NULL;//因为是添加在最后，所以将节点指向NULL
    if (head == NULL)//若head为空则将p1直接赋给head
    {
        head = p1;
    }
    else//接下来，另p2=head，然后逐步检查p2下一个节点，如果为NULL，说明p2是最后一个节点，将p1添加到p2后面
    {
        p2 = head;
        while (p2->next != NULL)
        {
            p2 = p2->next;
        }
        p2->next = p1;
    }
    return head;
}


void DisplyNode(struct link *head)//输出链表，逐步输出，遇到null结束
{
    int n = 1;
    struct link *p = head;
    while (p != NULL)
    {
        printf("%d %d\n", n++, p->data);
        p = p->next;
    }
}


void DeleteMemory(struct link *head)//释放空间，从head开始，逐步向后释放，遇到null结束
{
    struct link *p1 = head, *p2 = NULL;
    while (p1 != NULL)
    {
        p2 = p1;
        p1 = p1->next;
        free(p2);
    }
}


struct link *DeleteNode(struct link *head, int nodeData)
{
    struct link *p = (struct link *)malloc(sizeof(struct link));
    p = head;
    if (p == NULL)//如果p为NULL，直接输出  "Linked Table is empty!\n"
    {
        printf("Linked Table is empty!\n");
        return head;
    }
    else//p不为null时，对每个节点进行检查
    {
        if (p->data == nodeData)//先检查头节点，因为下面是不断检查p->next的值
        {
            return head->next;
        }
        else
        {
            while (p->next != NULL)//在p->next != NULL的情况下不断检查p->next的的值
            {
                if (p->next->data == nodeData)//若存在这样一个节点，则删去这个节点，即p指向p的下一个的下一个节点并返回head
                {
                    struct link *q = p->next;
                    p->next = q->next;
                    return head;
                }
                p = p->next;
            }
            //若是程序运行到此处说明没有返回，也就是没有找到对应的节点，打印出"This Node has not been found!\n"
            printf("This Node has not been found!\n");
            return head;
        }
    }
}

/*请在上方填写你的代码,仅需提交填写的部分*/
int main(void)
{
    int i = 0;
    int num;
    char c;
    struct link *head = NULL; /* 链表头指针 */
    scanf(" %c", &c);         /* %c前面有一个空格 */
    while (c == 'Y' || c == 'y')
    {
        head = AppendNode(head); /* 向head为头指针的链表末尾添加节点 */
        scanf(" %c", &c);        /* %c前面有一个空格 */
        i++;
    }
    scanf("%d", &num);
    head = DeleteNode(head, num);
    DisplyNode(head);
    DeleteMemory(head); /* 释放所有动态分配的内存 */
    return 0;
}