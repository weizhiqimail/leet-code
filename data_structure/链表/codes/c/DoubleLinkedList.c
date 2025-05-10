#include <stdio.h>
#include <stdlib.h>

// 双链表节点
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

// 获取链表的头节点
Node *getHeadNode(DoubleLinkedList *list) {
  if (isEmpty(list)) {
    printf("当前链表为空。\n");
    return NULL;
  }
  return list->head;
}

// 获取链表的尾节点
Node *getTailNode(DoubleLinkedList *list) {
  if (isEmpty(list)) {
    printf("当前链表为空。\n");
    return NULL;
  }
  return list->tail;
}

// 从头节点添加元素
int addNodeFromHead(DoubleLinkedList *list, int data) {
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

// 从尾节点添加元素
int addNodeFromTail(DoubleLinkedList *list, int data) {
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

// 删除某个节点
int removeNode(DoubleLinkedList *list, int data) {
  if (isEmpty(list)) {
    printf("当前链表为空，不能删除节点。\n");
    return 0;
  }

  Node *currentNode = list->head;

  // 找到要删除的节点
  while (currentNode != NULL && currentNode->data != data) {
    currentNode = currentNode->next;
  }

  if (currentNode == NULL) {
    printf("未找到值为 %d 的节点，删除失败。\n", data);
    return 0;
  }

  // 修改节点的 prev 的指向
  // 当前节点的 prev 为 NULL，表示匹配到是首节点。
  // 此时将 list->head 指向首节点的 next。
  if (currentNode->prev == NULL) {
    list->head = currentNode->next;
  } else {
    // 否则，说明匹配到的不是首节点，是中间节点
    // 将前一个节点的 next 指向当前节点的 next。
    // 即去掉 currentNode 的 next 指向。
    currentNode->prev->next = currentNode->next;
  }

  // 修改节点的 next 的指向
  // 当前节点的 next 为 NULL，表示匹配到的是尾节点。
  // 此时将 list->tail 指向尾节点的 prev。
  if (currentNode->next == NULL) {
    list->tail = currentNode->prev;
  } else {
    // 否则，说明匹配到的不是尾节点，是中间节点
    // 将下一个节点的 prev 指向当前节点的 prev。
    // 即去掉 currentNode 的 prev 指向。
    currentNode->next->prev = currentNode->prev;
  }

  free(currentNode);
  list->size--;
  return 1;
}

// 查找元素
Node *findNode(DoubleLinkedList *list, int data) {
  if (list == NULL) {
    printf("当前链表为空，不能查找元素。\n");
    return NULL;
  }

  Node *currentNode = list->head;

  while (currentNode != NULL) {
    if (currentNode->data == data) {
      return currentNode;
    }
    currentNode = currentNode->next;
  }
  return NULL;
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

  printf("] 长度: %d\n\n", list->size);
}

// 释放整个链表所有内存
void freeList(DoubleLinkedList *list) {
  if (list == NULL) {
    printf("当前链表为空，无需释放内存。\n");
    return;
  }

  Node *currentNode = list->head;
  while (currentNode != NULL) {
    Node *tempNode = currentNode;
    currentNode = currentNode->next;
    free(tempNode);
  }

  list->size = 0;
  list->head = NULL;
  list->tail = NULL;
  free(list);
}

int main() {
  DoubleLinkedList *list = createDoubleLinkedList(5);
  printf("---链表依次从尾节点开始，添加 1,2,3,4,5 共 5 个元素---\n");
  addNodeFromTail(list, 1);
  addNodeFromTail(list, 2);
  addNodeFromTail(list, 3);
  addNodeFromTail(list, 4);
  addNodeFromTail(list, 5);
  traverseList(list);

  printf("---添加元素 6，此时链表已满，不能再添加---\n");
  addNodeFromTail(list, 6);
  traverseList(list);

  printf("---链表删除节点 1,2,3,4,5---\n");
  traverseList(list);
  removeNode(list, 1);
  traverseList(list);
  removeNode(list, 2);
  traverseList(list);
  removeNode(list, 3);
  traverseList(list);
  removeNode(list, 4);
  traverseList(list);
  removeNode(list, 5);
  traverseList(list);

  printf("---再次删除元素 1，此时链表为空，删除失败---\n");
  removeNode(list, 1);
  traverseList(list);
  printf("\n");

  printf("---链表依次从头节点开始，添加 6,7 共 2 个元素---\n");
  addNodeFromHead(list, 6);
  addNodeFromHead(list, 7);
  traverseList(list);
  printf("\n");

  freeList(list);
}
