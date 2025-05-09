#include <stdio.h>
#include <stdlib.h>

// 双链表结点
typedef struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
} Node;

// 双链表的结构
typedef struct DoubleLinkedList {
  Node *head;
  Node *tail;
  int size;
  int capacity;
} DoubleLinkedList;

// 创建双链表
DoubleLinkedList *createDoubleLinkedList(int capacity) {
  if (capacity <= 0) {
    printf("链表的容量不能为 0。\n");
    return NULL;
  }

  DoubleLinkedList *list = (DoubleLinkedList *)malloc(sizeof(DoubleLinkedList));

  if (!list) {
    printf("创建双链表时，申请内存失败。\n");
    return NULL;
  }

  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  list->capacity = capacity;
  return list;
}

// 查询双链表的容量
int getCapacity(DoubleLinkedList *list) { return list->capacity; }

// 查询双链表当前的长度
int getSize(DoubleLinkedList *list) { return list->size; }

// 判断当前链表是否为空
int isEmpty(DoubleLinkedList *list) { return list->size == 0; }

// 判断当前链表是否满了
int isFull(DoubleLinkedList *list) { return list->size == list->capacity; }

// 获取链表的头结点
Node *getHeadNode(DoubleLinkedList *list) {
  if (isEmpty(list)) {
    printf("当前链表为空。\n");
    return NULL;
  }
  return list->head;
}

// 获取链表的尾结点
Node *getTailNode(DoubleLinkedList *list) {
  if (isEmpty(list)) {
    printf("当前链表为空。\n");
    return NULL;
  }
  return list->tail;
}

// 从头结点添加元素
int addNodeFromHead(DoubleLinkedList *list, int data) {
  if (isFull(list)) {
    printf("从头结点添加元素，当前链表已满，不能添加新元素。\n");
    return 0;
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    printf("从头结点添加元素，创建新结点时，申请内存失败。\n");
    return 0;
  }

  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = list->head;

  if (list->head != NULL) {
    list->head->prev = newNode;
  }
  list->head = newNode;

  if (list->tail == NULL) {
    list->tail = newNode;
  }
  list->size++;
  return 1;
}

// 从尾结点添加元素
int addNodeFromTail(DoubleLinkedList *list, int data) {
  if (isFull(list)) {
    printf("从尾结点添加元素，当前链表已满，不能添加新元素。\n");
    return 0;
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    printf("从尾结点添加元素，创建新结点时，申请内存失败。\n");
    return 0;
  }

  newNode->data = data;
  newNode->prev = list->tail;
  newNode->next = NULL;

  if (list->tail != NULL) {
    list->tail->next = newNode;
  }
  list->tail = newNode;

  if (list->head == NULL) {
    list->head = newNode;
  }

  list->size++;
  return 1;
}

// 遍历整个链表，并输出
void traverseList(DoubleLinkedList *list) {
  if (list == NULL || list->head == NULL) {
    printf("当前链表为空，无需遍历。\n");
    return;
  }
  Node *currentNode = list->head;
  printf("开始遍历链表：[ ");
  while (currentNode != NULL) {
    printf("%d ", currentNode->data);
    currentNode = currentNode->next;
  }

  printf("] 长度: %d\n", list->size);
}

int main() {
  DoubleLinkedList *list = createDoubleLinkedList(5);
  addNodeFromTail(list, 1);
  addNodeFromTail(list, 2);
  addNodeFromTail(list, 3);
  addNodeFromTail(list, 4);
  addNodeFromTail(list, 5);
  addNodeFromTail(list, 6);
  traverseList(list);
  printf("\n");
}
