#include <stdio.h>
#include <stdlib.h>
struct link *AppendNode(struct link *head);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);
struct link *InsertLocNode(struct link *head, int location, int nodeData);

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

struct link *InsertLocNode(struct link *head, int location, int nodeData)
{
    //令p节点的值为nodedata等待插入
    struct link *p = (struct link *)malloc(sizeof(struct link));
    p->data = nodeData;
    p->next = NULL;
    //location<1，不在范围内
    if (location < 1)
    {
        printf("Insert failure.\n"); // Insert success.
        return head;
    }
    //等于1，插在head前面，再令head=p
    else if (location == 1)
    {
        p->next = head;
        head = p;
        printf("Insert success.\n");
        return head;
    }

    else
    {
        int n = 2;
        struct link *q = head;
        //这两个条件都满足就一直向下，第一个条件判断是否检查到location，第二个条件检测是否超出
        while (n != location && q->next != NULL)
        {
            q = q->next;
            n++;
        }
        if (n == location)//若n==location说明检测到位置，插入
        {
            p->next = q->next;
            q->next = p;
            printf("Insert success.\n");
        }
        else if (location - n == 1)//说明location正好在最后，插入最后节点的后面
        {
            q->next = p;
            printf("Insert success.\n");
        }
        else//否则就是没有检测到，检测到最后也没有检测到
        {
            printf("Insert failure.\n");
        }
        return head;
    }
}

/*请在上方填写你的代码,仅需提交填写的部分*/
int main(void)
{
    int i = 0;
    int value, location;
    char c;
    struct link *head = NULL; /* 链表头指针 */
    scanf(" %c", &c);         /* %c前面有一个空格 */
    while (c == 'Y' || c == 'y')
    {
        head = AppendNode(head); /* 向head为头指针的链表末尾添加节点 */
        scanf(" %c", &c);        /* %c前面有一个空格 */
        i++;
    }
    scanf("%d %d", &location, &value);
    head = InsertLocNode(head, location, value);
    DisplyNode(head);
    DeleteMemory(head); /* 释放所有动态分配的内存 */
    return 0;
}