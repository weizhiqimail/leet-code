#include <stdio.h>
#include <stdlib.h>

// 单链表结点结构
typedef struct Node {
    int data;               // 存储的数据
    struct Node *next;      // 指向下一个结点的指针
} Node;

// 单链表结构体
typedef struct SingleLinkedList {
    Node *head;             // 链表的头结点
    int size;               // 当前链表长度
    int capacity;           // 链表最大容量
} SingleLinkedList;

// 创建一个新的单链表，初始化容量
SingleLinkedList *createSingleLinkedList(int capacity) {
    if (capacity <= 0) {
        printf("链表容量必须大于0\n");
        return NULL;
    }
    SingleLinkedList *list = (SingleLinkedList *) malloc(sizeof(SingleLinkedList));
    if (list == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// 获取链表容量
int getCapacity(SingleLinkedList *list) {
    return list->capacity;
}

// 获取链表当前元素个数
int getSize(SingleLinkedList *list) {
    return list->size;
}

// 判断链表是否为空
int isEmpty(SingleLinkedList *list) {
    return list->size == 0;
}

// 获取头结点的数据
int getHeadNode(SingleLinkedList *list) {
    if (isEmpty(list)) {
        printf("链表为空\n");
        exit(1);
    }
    return list->head->data;
}

// 获取尾结点的数据
int getTailNode(SingleLinkedList *list) {
    if (isEmpty(list)) {
        printf("链表为空\n");
        exit(1);
    }

    Node *currentNode = list->head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

// 向链表尾部添加一个新结点
void addLastNode(SingleLinkedList *list, int data) {
    if (list->size >= list->capacity) {
        printf("链表已满\n");
        exit(1);
    }

    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *currentNode = list->head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    list->size++;
}

// 向链表头部添加一个新结点
void addFirstNode(SingleLinkedList *list, int data) {
    if (list->size >= list->capacity) {
        printf("链表已满\n");
        exit(1);
    }

    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

// 删除链表中首个匹配 data 的结点
int removeNode(SingleLinkedList *list, int data) {
    if (isEmpty(list)) {
        printf("链表为空\n");
        exit(1);
    }

    Node *currentNode = list->head;
    if (currentNode->data == data) {
        list->head = currentNode->next;
        free(currentNode);
        list->size--;
        return 1;
    }

    while (currentNode->next != NULL) {
        if (currentNode->next->data == data) {
            Node *temp = currentNode->next;
            currentNode->next = temp->next;
            free(temp);
            list->size--;
            return 1;
        }
        currentNode = currentNode->next;
    }
    return 0;  // 未找到匹配元素
}

// 删除链表头部结点
int removeFirstNode(SingleLinkedList *list) {
    if (isEmpty(list)) {
        printf("链表为空\n");
        exit(1);
    }

    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
    return 1;
}

// 删除链表尾部结点
int removeLastNode(SingleLinkedList *list) {
    if (isEmpty(list)) {
        printf("链表为空\n");
        exit(1);
    }

    if (list->size == 1) {
        int data = list->head->data;
        free(list->head);
        list->head = NULL;
        list->size--;
        return data;
    }

    Node *prevNode = list->head;
    while (prevNode->next->next != NULL) {
        prevNode = prevNode->next;
    }

    int data = prevNode->next->data;
    free(prevNode->next);
    prevNode->next = NULL;
    list->size--;
    return data;
}

// 释放整个链表占用的内存
void freeSingleLinkedList(SingleLinkedList *list) {
    Node *currentNode = list->head;
    while (currentNode != NULL) {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    free(list);
}

// 遍历链表并打印所有元素
void traverseList(SingleLinkedList *list) {
    if (isEmpty(list)) {
        printf("链表为空\n");
        return;
    }

    printf("链表元素：");
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n");
}


// 测试单链表的功能
int main() {
    printf("开始测试...\n");

    // 1. 创建链表
    SingleLinkedList *list = createSingleLinkedList(5);
    printf("创建链表，容量: %d，是否为空: %s\n", getCapacity(list), isEmpty(list) ? "是" : "否");
    traverseList(list);

    // 2. 添加元素
    addLastNode(list, 10);
    traverseList(list);

    addLastNode(list, 20);
    traverseList(list);

    addFirstNode(list, 5);
    traverseList(list);

    addLastNode(list, 30);
    traverseList(list);

    addFirstNode(list, 1);
    traverseList(list);

    printf("添加元素后，当前大小: %d\n", getSize(list));

    // 3. 获取头尾结点
    printf("头结点数据: %d\n", getHeadNode(list));
    printf("尾结点数据: %d\n", getTailNode(list));

    // 4. 删除指定元素
    printf("尝试删除元素 20: %s\n", removeNode(list, 20) ? "成功" : "失败");
    traverseList(list);

    printf("尝试删除元素 100（不存在）: %s\n", removeNode(list, 100) ? "成功" : "失败");
    traverseList(list);

    // 5. 删除头结点
    removeFirstNode(list);
    printf("删除头结点后，新的头结点数据: %d\n", getHeadNode(list));
    traverseList(list);

    // 6. 删除尾结点
    int removed = removeLastNode(list);
    printf("删除尾结点，删除的值为: %d\n", removed);
    traverseList(list);

    // 7. 打印剩余元素
    printf("最终链表元素如下：\n");
    traverseList(list);

    // 8. 释放链表
    freeSingleLinkedList(list);
    printf("链表已释放。\n");

    return 0;
}

/**
开始测试...
创建链表，容量: 5，是否为空: 是
链表为空

链表元素：10

链表元素：10 20

链表元素：5 10 20

链表元素：5 10 20 30

链表元素：1 5 10 20 30

添加元素后，当前大小: 5
头结点数据: 1
尾结点数据: 30
尝试删除元素 20: 成功
链表元素：1 5 10 30

尝试删除元素 100（不存在）: 失败
链表元素：1 5 10 30

删除头结点后，新的头结点数据: 5
链表元素：5 10 30

删除尾结点，删除的值为: 30
链表元素：5 10

最终链表元素如下：
链表元素：5 10

链表已释放。
 */
