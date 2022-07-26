#include <stdio.h>
#include <stdlib.h>
struct link *AppendNode(struct link *head);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);
struct link *InsertOrderNode(struct link *head, int nodeData);

struct link
{
    int data;
    struct link *next;
};

/*请在下方编写你的代码,仅需提交填写的部分*/

struct link *AppendNode(struct link *head)
{
    struct link *p1, *p2;
    p1 = p2 = (struct link *)malloc(sizeof(struct link));
    scanf(" %d", &p1->data);
    p1->next = NULL;
    if (head == NULL)
    {
        head = p1;
    }
    else
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

void DisplyNode(struct link *head)
{
    int n = 1;
    struct link *p = head;
    while (p != NULL)
    {
        printf("%d %d\n", n++, p->data);
        p = p->next;
    }
}

void DeleteMemory(struct link *head)
{
    struct link *p1 = head, *p2 = NULL;
    while (p1 != NULL)
    {
        p2 = p1;
        p1 = p1->next;
        free(p2);
    }
}

struct link *InsertOrderNode(struct link *head, int nodeData)
{
    //令p节点为插入的节点
    struct link *p = (struct link *)malloc(sizeof(struct link));
    p->data = nodeData;
    p->next = NULL;
    if (head == NULL)//为null直接插入，返回
    {
        head = p;
        return head;
    }
    else
    {
        //先比较头节点和nodedata大小
        struct link *q = head;
        if (head->data >= nodeData)//头节点大，则插入head前面
        {
            p->next = head;
            head = p;
        }
        else if (head->next->data > nodeData)//head比nodedata小，第二个节点大则插在第二个位置
        {
            p->next = head->next;
            head->next = p;
        }
        else//检测剩下的节点
        {
            //找到比nodedata大的节点插入到它前面 或者 没有找到，插入尾部
            while (q->next != NULL && q->next->data < nodeData)
            //这个地方有点不严谨，利用了&&运行时前面的条件若是不成立则不会再判断后面的条件，如果这个地方调一下顺序就会报错
            {
                q = q->next;
            }
            p->next = q->next;
            q->next = p;
        }
        return head;
    }
}

/*请在上方填写你的代码,仅需提交填写的部分*/
int main(void)
{
    int i = 0;
    int value;
    char c;
    struct link *head = NULL; /* 链表头指针 */
    scanf(" %c", &c);         /* %c前面有一个空格 */
    while (c == 'Y' || c == 'y')
    {
        head = AppendNode(head); /* 向head为头指针的链表末尾添加节点 */
        scanf(" %c", &c);        /* %c前面有一个空格 */
        i++;
    }
    scanf("%d", &value);
    head = InsertOrderNode(head, value);
    DisplyNode(head);
    DeleteMemory(head); /* 释放所有动态分配的内存 */
    return 0;
}