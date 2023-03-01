/**
 * @file main.c
 * @author jay
 * @version 0.1
 * @date 2023-03-01
 */

#include <stdio.h>
#include <ctype.h>
#include "./linklist.h"

int main(void)
{

    int size;

    while (1)
    {
        printf("輸入節點數量: ");

        scanf("%d", &size);
        fflush(stdin);

        if (size > 0)
        {
            break;
        }

        printf("輸入必須大於 0\n");
    }

    int arr[size];

    for (int i = 0; i < size; i++)
    {

        printf("輸入節點 %d 資料值: ", i + 1);
        scanf("%d", &arr[i]);
        fflush(stdin);
    }

    NODEp first = createList(arr, size);

    char input;
    int flag = 1;
    int is_free = 0;

    while (flag)
    {

        printf("----------\n");
        printf(" 'q': 退出\n");
        printf("-----\n");
        printf(" 'i': 插入節點\n");
        printf("-----\n");
        printf(" 'f': 新增首節點\n");
        printf("-----\n");
        printf(" 'd': 刪除節點\n");
        printf("-----\n");
        printf(" 'c': 變更節點\n");
        printf("-----\n");
        printf(" 's': 遍歷節點\n");
        printf("-----\n");
        printf("輸入要執行的指令: ");

        scanf("%c", &input);
        fflush(stdin);

        switch (input)
        {
        case 'q':
        {
            flag = 0;
            printf("退出...\n");

            if (!is_free)
            {
                printf("釋放記憶體...\n");
                freeList(first);
                printf("釋放成功\n");
            }

            break;
        }

        case 'c':
        {
            if (first == NULL)
            {
                printf("Link List 為空，請先新增節點\n");
                break;
            }

            int node_n, item;
            printf("輸入要變更的節點: ");
            scanf("%d", &node_n);
            fflush(stdin);

            NODEp p = searchNode(first, node_n);

            if (p == NULL)
            {
                printf("查無此節點\n");
                break;
            }

            printf("輸入新的資料值: ");
            scanf("%d", &item);
            fflush(stdin);

            p->data = item;

            printf("變更完成\n");

            break;
        }

        case 'f':
        {
            int node_n;

            printf("輸入新節點資料值: ");
            scanf("%d", &node_n);
            fflush(stdin);

            first = insertFirst(first, node_n);

            printf("新增成功\n");

            break;
        }
        case 'i':
        {
            int node_n;

            if (first == NULL)
            {
                printf("輸入新節點資料值: ");
                scanf("%d", &node_n);
                fflush(stdin);

                first = insertFirst(first, node_n);
                break;
            }
            printf("選擇要插入在哪個節點之後: ");
            scanf("%d", &node_n);
            fflush(stdin);

            NODEp p = searchNode(first, node_n);

            if (p == NULL)
            {
                printf("查無此節點\n");
                break;
            }
            else
            {
                int item;
                printf("輸入新節點的資料值: ");
                scanf("%d", &item);
                fflush(stdin);

                insertNode(first, item);
                printf("新增成功!\n");
                break;
            }
        }

        case 'd':
        {
            if (first == NULL)
            {
                printf("Link List 為空，請先新增節點\n");
                break;
            }

            int node_n;
            printf("選擇要刪除的節點: ");
            scanf("%d", &node_n);
            fflush(stdin);

            NODEp p = searchNode(first, node_n);

            if (p == NULL)
            {
                printf("查無此節點\n");
                break;
            }

            first = deleteNode(first, p);

            printf("刪除成功\n");

            break;
        }

        case 's':
        {
            printf("--> ");
            if (first == NULL)
            {
                printf(" Link List 為空\n");
                break;
            }
            display(first);
            break;
        }
        default:
            flag = 0;
            printf("退出....\n");
            if (!is_free)
            {
                printf("釋放記憶體....\n");
                freeList(first);
                printf("釋放成功\n");
            }
            break;
        }
    }
}