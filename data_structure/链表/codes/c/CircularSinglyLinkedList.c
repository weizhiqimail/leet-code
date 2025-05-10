#include <stdio.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct CircularSinglyLinkedList {
  Node *head;
  int size;
  int capacity;
} CircularSinglyLinkedList;

// 创建空链表
CircularSinglyLinkedList *createCircularSinglyLinkedList(int capacity) {
  CircularSinglyLinkedList *list =
      (CircularSinglyLinkedList *)malloc(sizeof(CircularSinglyLinkedList));

  if (!list) {
    printf("创建单向循环链表时，申请内存失败。\n");
    return NULL;
  }

  list->head = NULL;
  list->size = 0;
  list->capacity = capacity;
  return list;
}

// 查询单向循环链表的容量
int getCapacity(CircularSinglyLinkedList *list) { return list->capacity; }

// 查询单向循环链表当前的长度
int getSize(CircularSinglyLinkedList *list) { return list->size; }

// 判断单向循环链表是否为空
int isEmpty(CircularSinglyLinkedList *list) { return list->size == 0; }

// 判断单向循环链表是否满了
int isFull(CircularSinglyLinkedList *list) {
  return list->size == list->capacity;
}

// 获取单向循环链表的头节点
Node *getFirstNode(CircularSinglyLinkedList *list) {
  if (isEmpty(list)) {
    printf("获取单向循环链表的头节点，当前链表为空。\n");
    return NULL;
  }

  return list->head;
}

// 获取单向循环链表的尾节点
Node *getLastNode(CircularSinglyLinkedList *list) {
  if (isEmpty(list)) {
    printf("获取单向循环链表的尾节点，当前链表为空。\n");
    return NULL;
  }

  Node *currentNode = list->head;

  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  return currentNode;
}

// 从尾节点添加元素
int addNodeFromTail(CircularSinglyLinkedList *list, int data) {
  if (isFull(list)) {
    printf("从头节点添加元素，当前链表已满，不能添加新元素。\n");
    return 0;
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    printf("从头节点添加元素，创建新节点时，申请内存失败。\n");
    return 0;
  }

  newNode->data = data;
  newNode->next = NULL;

  // 链表首节点是空的，说明是空链表
  // 直接添加新节点，此时只有一个节点，让新节点自己指向自己。
  if (list->head == NULL) {
    list->head = newNode;
    newNode->next = newNode;
  } else {
    Node *tempNode = list->head;

    while (tempNode->next != list->head) {
      tempNode = tempNode->next;
    }

    tempNode->next = newNode;
    newNode->next = list->head;
  }
  list->size++;
  return 1;
}


int main() { return 0; }