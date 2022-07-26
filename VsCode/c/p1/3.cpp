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

struct link *DeleteNode(struct link *head, int nodeData)
{
    int ret = 0;//ret用来检测是否找到nodedata
    struct link *p = (struct link *)malloc(sizeof(struct link));
    if (head == NULL)//判断是否为NULL
    {
        printf("Linked Table is empty!\n");
        return head;
    }
    else
    {
        //头指针不能直接指向下一个，因为下一个也可能是
        while (head->data == nodeData)
        //先检测头节点，若找到则ret=1，head=head->next，如何再对head检测直至为null或者head!=nodedata
        {
            ret=1;
            head = head->next;
            if (head == NULL)
            {
                return head;
            }
        }
        p = head;//此时p不为空且p!=nodedata
        while (p->next != NULL)//对剩下节点检测
        {
            if (p->next->data == nodeData)
            //这里如果检测到，会删去p->next,p->next实际为原来p->next->next因为下面还有令p = p->next，这样会跳过一个节点没有检测，所以直接continue，再检测一下
            {
                ret=1;
                struct link *q = p->next;
                p->next = q->next;
                continue; // p->next改变，再进行一次检查
            }
            p = p->next;
        }
        //最后，如果ret还是等于0，说明，没有检测到nodedata
        if(ret==0)printf("This Node has not been found!\n");
        return head;
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