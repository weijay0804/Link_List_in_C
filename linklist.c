/**
 * @file linklist.c
 * @author jay
 * @brief
 * @version 0.1
 * @date 2023-03-01
 */

#include <stdio.h>
#include <stdlib.h>
#include "./linklist.h"

/**
 * @brief 由傳入的 arr 建立 Link List
 *
 * @param arr 包含 Link List 資料的陣列
 * @param len 陣列長度
 * @return NODEp 回傳指向第一個節點的 pointer
 */
NODEp createList(int *arr, int len)
{

    NODEp first, current, previous; // 定義 3 個 NODE 類型的 pointer，之後會用到

    for (int i = 0; i < len; i++)
    {

        current = (NODE *)malloc(sizeof(NODE)); // 建立一個新節點，並用 current 指向

        current->data = arr[i];

        // 如果是第一個節點，就將 first 指向該節點
        if (i == 0)
        {
            first = current;
        }

        else
        {
            previous->next = current;
        }

        current->next = NULL;
        previous = current;
    }

    return first;
}

/**
 * @brief 在 node 節點後插入新節點
 *
 * @param node 要插入的節點位置
 * @param item 新節點的資料值
 */
void insertNode(NODEp node, int item)
{

    NODEp new_node = (NODE *)malloc(sizeof(NODE));

    new_node->data = item;
    new_node->next = node->next;
    node->next = new_node;
}

/**
 * @brief 新增首節點
 *
 * @param first 指向第一個節點的 pointer
 * @param item 新節點的資料值
 * @return NODEp 回傳指向第一個節點的 pointer
 */
NODEp insertFirst(NODEp first, int item)
{

    NODEp new_node = (NODE *)malloc(sizeof(NODE));

    new_node->data = item;
    new_node->next = first;
    first = new_node;

    return first;
}

/**
 * @brief 在 Link List 尋找節點
 *
 * @param first 指向第一個節點的 pointer
 * @param item 要尋找的節點的資料值
 * @return NODEp 回傳指向要尋找的節點的 pointer，如果沒有找到回傳 NULL
 */
NODEp searchNode(NODEp first, int item)
{

    NODEp p = first;

    while (p != NULL)
    {

        if (p->data == item)
        {
            return p;
        }

        p = p->next;
    }

    return NULL;
}

/**
 * @brief 刪除節點
 *
 * @param first 指向第一個節點的 pointer
 * @param node 指向要刪除的節點的 pointer
 * @return NODEp 回傳指向第一個節點的 pointer
 */
NODEp deleteNode(NODEp first, NODEp node)
{

    if (first == NULL)
    {
        return NULL;
    }

    // 如果要刪除的是第一個節點，就將 first 指標指向下一個節點
    if (first == node)
    {
        first = first->next;
    }
    else
    {

        NODEp p = first;

        // 將 p 指向要刪除的節點之前的一個節點
        while (p->next != node)
        {
            p = p->next;
        }

        // 將節點重新指向
        p->next = node->next;
    }

    // 清除節點
    free(node);

    return first;
}

/**
 * @brief 清除 Link List 產生的動態記憶體
 *
 * @param first 指向第一個節點的 pointer
 */
void freeList(NODEp first)
{

    NODEp p = first;

    while (p != NULL)
    {

        first = first->next; // 先將 first 指標指向下一個節點
        free(p);
        p = first;
    }
}

/**
 * @brief 遍歷 Link List 並將其元素顯示出來
 *
 * @param first 指向第一個節點的 pointer
 */
void display(NODEp first)
{

    NODEp p = first;

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}