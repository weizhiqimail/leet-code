#include <stdio.h>
#include <stdlib.h>

// 单个节点
typedef struct Node {
  int data;
  struct Node *next;
} Node;

// 单链表的结构
typedef struct SinglyLinkedList {
  // 链表的首节点
  Node *head;
  // 链表的大小（长度）
  int size;
  // 链表的容量
  int capacity;
} SinglyLinkedList;

// 创建单链表
SinglyLinkedList *createSinglyLinkedList(int capacity) {
  if (capacity <= 0) {
    printf("单链表的容量不能为 0。\n");
    return NULL;
  }

  SinglyLinkedList *list = (SinglyLinkedList *)malloc(sizeof(SinglyLinkedList));

  if (!list) {
    printf("创建单链表时，申请内存失败。\n");
    return NULL;
  }

  list->head = NULL;
  list->capacity = capacity;
  list->size = 0;
  return list;
}

// 查询单链表的容量
int getCapacity(SinglyLinkedList *list) { return list->capacity; }

// 查询单链表当前的长度
int getSize(SinglyLinkedList *list) { return list->size; }

// 判断当前链表是否为空
int isEmpty(SinglyLinkedList *list) { return list->size == 0; }

// 判断当前链表是否满了
int isFull(SinglyLinkedList *list) { return list->size == list->capacity; }

// 获取链表的头节点
Node *getHeadNode(SinglyLinkedList *list) {
  if (isEmpty(list)) {
    printf("获取链表的头节点，当前链表为空。\n");
    return NULL;
  }

  return list->head;
}

// 获取链表的尾节点
Node *getLastNode(SinglyLinkedList *list) {
  if (isEmpty(list)) {
    printf("获取链表的尾节点，当前链表为空。\n");
    return NULL;
  }

  Node *currentNode = list->head;
  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }
  return currentNode;
}

// 从头节点添加元素
int addNodeFromHead(SinglyLinkedList *list, int data) {
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
  newNode->next = list->head;
  list->head = newNode;
  list->size++;
  return 1;
}

// 从尾节点添加元素
int addNodeFromTail(SinglyLinkedList *list, int data) {
  if (isFull(list)) {
    printf("从尾节点添加元素，当前链表已满，不能添加新元素。\n");
    return 0;
  }

  Node *newNode = (Node *)malloc(sizeof(Node));
  if (!newNode) {
    printf("从尾节点添加元素，创建新节点时，申请内存失败。\n");
    return 0;
  }
  newNode->data = data;
  newNode->next = NULL;

  Node *lastNode = getLastNode(list);

  if (lastNode) {
    lastNode->next = newNode;
  } else {
    list->head = newNode;
  }
  list->size++;
  return 1;
}

// 删除某个节点
int removeNode(SinglyLinkedList *list, int data) {
  if (isEmpty(list)) {
    printf("当前链表为空，不能删除节点。\n");
    return 0;
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
      Node *tempNode = currentNode->next;
      currentNode->next = tempNode->next;
      free(tempNode);
      list->size--;
      return 1;
    }
    currentNode = currentNode->next;
  }
  printf("未找到值为 %d 的节点，删除失败。\n", data);
  return 0;
}

// 释放整个链表所有内存
void freeList(SinglyLinkedList *list) {
  if (list == NULL) {
    printf("当前链表为空，无需释放内存。\n");
    return;
  }

  Node *currentNode = list->head;
  while (currentNode != NULL) {
    Node *temp = currentNode;
    currentNode = currentNode->next;
    free(temp);
  }

  list->head = NULL;
  list->size = 0;

  free(list);
}

// 遍历整个链表，并输出
void traverseList(SinglyLinkedList *list) {
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
  SinglyLinkedList *list = createSinglyLinkedList(5);

  printf("---链表依次从尾节点开始，添加 1,2,3,4,5,6 共 6 个元素---\n");
  addNodeFromTail(list, 1);
  addNodeFromTail(list, 2);
  addNodeFromTail(list, 3);
  addNodeFromTail(list, 4);
  addNodeFromTail(list, 5);
  addNodeFromTail(list, 6);
  traverseList(list);
  printf("\n");

  printf("---链表删除节点 3,4,5---\n");
  removeNode(list, 3);
  removeNode(list, 4);
  removeNode(list, 5);
  traverseList(list);
  printf("\n");

  printf("---链表依次从头节点开始，添加 6,7 共 2 个元素---\n");
  addNodeFromHead(list, 6);
  addNodeFromHead(list, 7);
  traverseList(list);
  printf("\n");

  freeList(list);

  return 0;
};
