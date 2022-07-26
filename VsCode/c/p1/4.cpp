#include <stdio.h>
#include <stdlib.h>
struct link *AppendNode(struct link *head);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);
struct link *DeleteNode(struct link *head, int location);

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

struct link *DeleteNode(struct link *head, int location)
{
    struct link *p = (struct link *)malloc(sizeof(struct link));
    p = head;
    if (p == NULL)//检测head是否为null
    {
        printf("Linked Table is empty!\n");
        return head;
    }
    else
    {
        //如果，location为1，返回head的下一个节点
        if(location==1){
            return head->next;
        }
        int n=2;//定义n为对应节点的位置，与location比较
        while (p->next!=NULL)//依次对下面节点检查
        {
            if(n==location){//若存在，则删除掉
                struct link *q=p->next;
                p->next=q->next;
                return head;
            }
            p=p->next;
            n++;
        }
        //运行到此说明没有找到
        printf("The location has not been found.\n");
        return NULL;
    }
}

/*请在上方填写你的代码,仅需提交填写的部分*/
int main(void)
{
    int i = 0;
    int location;
    char c;
    struct link *head = NULL; /* 链表头指针 */
    scanf(" %c", &c);         /* %c前面有一个空格 */
    while (c == 'Y' || c == 'y')
    {
        head = AppendNode(head); /* 向head为头指针的链表末尾添加节点 */
        scanf(" %c", &c);        /* %c前面有一个空格 */
        i++;
    }
    scanf("%d", &location);
    head = DeleteNode(head, location);
    DisplyNode(head);
    DeleteMemory(head); /* 释放所有动态分配的内存 */
    return 0;
}