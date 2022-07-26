#include <stdio.h>
#include <stdlib.h>

/* 请完成此函数功能：新建一个节点并添加到链表末尾，返回添加节点后的链表的头指针 */
struct link *AppendNode(struct link *head);

/*  请完成此函数的功能：显示链表中所有节点的节点号和该节点中数据项内容 */
void DisplyNode(struct link *head);

/*  请完成此函数的功能：释放head指向的链表中所有节点占用的内存 */
void DeleteMemory(struct link *head);

struct link
{
    int data;
    struct link *next;
};
//-------------------------------------------------------
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

//----------------------------------------------------------
int main(void)
{
    int i = 0;
    char c;
    struct link *head = NULL; /* 链表头指针 */
    scanf(" %c", &c);         /* %c前面有一个空格 */
    while (c == 'Y' || c == 'y')
    {
        head = AppendNode(head); /* 向head为头指针的链表末尾添加节点 */
        scanf(" %c", &c);        /* %c前面有一个空格 */
        i++;
    }
    DisplyNode(head);
    printf("%d new nodes have been appended!\n", i);
    DeleteMemory(head); /* 释放所有动态分配的内存 */
    return 0;
}
