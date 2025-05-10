#include <stdio.h>
#include <stdlib.h>

// 双链表节点
typedef struct DNode {
    int data;                 // 数据域
    struct DNode* prev;       // 指向前一个节点
    struct DNode* next;       // 指向下一个节点
} DNode;

// 双链表结构体
typedef struct DoubleLinkedList {
    DNode* head;              // 指向头节点
    DNode* tail;              // 指向尾节点
    int size;                 // 当前元素数量
    int capacity;             // 最大容量
} DoubleLinkedList;

// 初始化双向链表
DoubleLinkedList* createDoubleLinkedList(int capacity) {
    if (capacity <= 0) {
        printf("链表容量必须为正数\n");
        exit(1);
    }
    DoubleLinkedList* list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// 获取链表容量
int getCapacity(DoubleLinkedList* list) {
    return list->capacity;
}

// 获取链表当前元素个数
int getSize(DoubleLinkedList* list) {
    return list->size;
}

// 获取头节点元素
int getFirst(DoubleLinkedList* list) {
    if (list->size == 0) {
        printf("链表为空\n");
        exit(1);
    }
    return list->head->data;
}

// 获取尾节点元素
int getLast(DoubleLinkedList* list) {
    if (list->size == 0) {
        printf("链表为空\n");
        exit(1);
    }
    return list->tail->data;
}

// 在尾部添加元素
void addLast(DoubleLinkedList* list, int data) {
    if (list->size >= list->capacity) {
        printf("链表已满\n");
        return;
    }
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = list->tail;

    if (list->size == 0) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// 在头部添加元素
void addFirst(DoubleLinkedList* list, int data) {
    if (list->size >= list->capacity) {
        printf("链表已满\n");
        return;
    }
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = list->head;

    if (list->size == 0) {
        list->head = list->tail = newNode;
    } else {
        list->head->prev = newNode;
        list->head = newNode;
    }
    list->size++;
}

// 默认添加方法（尾部添加）
void add(DoubleLinkedList* list, int data) {
    addLast(list, data);
}

// 删除首个匹配的元素
int removeElement(DoubleLinkedList* list, int data) {
    if (list->size == 0) {
        return 0;
    }

    DNode* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            // 删除头节点
            if (current == list->head) {
                list->head = current->next;
                if (list->head != NULL) {
                    list->head->prev = NULL;
                } else {
                    list->tail = NULL;
                }
            }
            // 删除尾节点
            else if (current == list->tail) {
                list->tail = current->prev;
                list->tail->next = NULL;
            }
            // 删除中间节点
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            free(current);
            list->size--;
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// 删除头节点
int removeFirst(DoubleLinkedList* list) {
    if (list->size == 0) {
        printf("链表为空\n");
        exit(1);
    }

    DNode* temp = list->head;
    int data = temp->data;

    list->head = temp->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }

    free(temp);
    list->size--;
    return data;
}

// 删除尾节点
int removeLast(DoubleLinkedList* list) {
    if (list->size == 0) {
        printf("链表为空\n");
        exit(1);
    }

    DNode* temp = list->tail;
    int data = temp->data;

    list->tail = temp->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }

    free(temp);
    list->size--;
    return data;
}

// 遍历链表并打印所有元素
void traverseDoubleLinkedList(DoubleLinkedList* list) {
    if (list->size == 0) {
        printf("链表为空\n\n");
        return;
    }

    DNode* current = list->head;
    printf("链表元素：");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n");
}

// 释放链表内存
void freeDoubleLinkedList(DoubleLinkedList* list) {
    DNode* current = list->head;
    while (current != NULL) {
        DNode* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}

int main() {
    // 创建容量为10的双向链表
    DoubleLinkedList* list = createDoubleLinkedList(10);

    printf("初始化链表，容量：%d\n", getCapacity(list));
    printf("当前元素个数：%d\n\n", getSize(list));

    // 添加元素到尾部
    addLast(list, 10);
    addLast(list, 20);
    addLast(list, 30);
    printf("尾部添加元素 10, 20, 30：\n");
    traverseDoubleLinkedList(list);

    // 添加元素到头部
    addFirst(list, 5);
    addFirst(list, 2);
    printf("头部添加元素 5, 2：\n");
    traverseDoubleLinkedList(list);

    // 删除指定元素
    printf("删除元素 20：\n");
    removeElement(list, 20);
    traverseDoubleLinkedList(list);

    // 删除头元素
    printf("删除头元素：%d\n", removeFirst(list));
    traverseDoubleLinkedList(list);

    // 删除尾元素
    printf("删除尾元素：%d\n", removeLast(list));
    traverseDoubleLinkedList(list);

    // 尾部再添加两个
    addLast(list, 40);
    addLast(list, 50);
    printf("再次尾部添加 40, 50：\n");
    traverseDoubleLinkedList(list);

    // 打印头尾数据
    printf("当前头元素：%d\n", getFirst(list));
    printf("当前尾元素：%d\n", getLast(list));
    printf("当前链表大小：%d\n\n", getSize(list));

    // 清空并释放链表
    freeDoubleLinkedList(list);
    printf("链表已释放。\n");

    return 0;
}

/**
初始化链表，容量：10
当前元素个数：0

尾部添加元素 10, 20, 30：
链表元素：10 20 30

头部添加元素 5, 2：
链表元素：2 5 10 20 30

删除元素 20：
链表元素：2 5 10 30

删除头元素：2
链表元素：5 10 30

删除尾元素：30
链表元素：5 10

再次尾部添加 40, 50：
链表元素：5 10 40 50

当前头元素：5
当前尾元素：50
当前链表大小：4

链表已释放。
 */