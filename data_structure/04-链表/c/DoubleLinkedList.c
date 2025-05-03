#include <stdio.h>
#include <stdlib.h>

// ˫����ڵ�
typedef struct DNode {
    int data;                 // ������
    struct DNode* prev;       // ָ��ǰһ���ڵ�
    struct DNode* next;       // ָ����һ���ڵ�
} DNode;

// ˫����ṹ��
typedef struct DoubleLinkedList {
    DNode* head;              // ָ��ͷ�ڵ�
    DNode* tail;              // ָ��β�ڵ�
    int size;                 // ��ǰԪ������
    int capacity;             // �������
} DoubleLinkedList;

// ��ʼ��˫������
DoubleLinkedList* createDoubleLinkedList(int capacity) {
    if (capacity <= 0) {
        printf("������������Ϊ����\n");
        exit(1);
    }
    DoubleLinkedList* list = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// ��ȡ��������
int getCapacity(DoubleLinkedList* list) {
    return list->capacity;
}

// ��ȡ����ǰԪ�ظ���
int getSize(DoubleLinkedList* list) {
    return list->size;
}

// ��ȡͷ�ڵ�Ԫ��
int getFirst(DoubleLinkedList* list) {
    if (list->size == 0) {
        printf("����Ϊ��\n");
        exit(1);
    }
    return list->head->data;
}

// ��ȡβ�ڵ�Ԫ��
int getLast(DoubleLinkedList* list) {
    if (list->size == 0) {
        printf("����Ϊ��\n");
        exit(1);
    }
    return list->tail->data;
}

// ��β�����Ԫ��
void addLast(DoubleLinkedList* list, int data) {
    if (list->size >= list->capacity) {
        printf("��������\n");
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

// ��ͷ�����Ԫ��
void addFirst(DoubleLinkedList* list, int data) {
    if (list->size >= list->capacity) {
        printf("��������\n");
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

// Ĭ����ӷ�����β����ӣ�
void add(DoubleLinkedList* list, int data) {
    addLast(list, data);
}

// ɾ���׸�ƥ���Ԫ��
int removeElement(DoubleLinkedList* list, int data) {
    if (list->size == 0) {
        return 0;
    }

    DNode* current = list->head;
    while (current != NULL) {
        if (current->data == data) {
            // ɾ��ͷ�ڵ�
            if (current == list->head) {
                list->head = current->next;
                if (list->head != NULL) {
                    list->head->prev = NULL;
                } else {
                    list->tail = NULL;
                }
            }
            // ɾ��β�ڵ�
            else if (current == list->tail) {
                list->tail = current->prev;
                list->tail->next = NULL;
            }
            // ɾ���м�ڵ�
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

// ɾ��ͷ�ڵ�
int removeFirst(DoubleLinkedList* list) {
    if (list->size == 0) {
        printf("����Ϊ��\n");
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

// ɾ��β�ڵ�
int removeLast(DoubleLinkedList* list) {
    if (list->size == 0) {
        printf("����Ϊ��\n");
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

// ����������ӡ����Ԫ��
void traverseDoubleLinkedList(DoubleLinkedList* list) {
    if (list->size == 0) {
        printf("����Ϊ��\n\n");
        return;
    }

    DNode* current = list->head;
    printf("����Ԫ�أ�");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n");
}

// �ͷ������ڴ�
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
    // ��������Ϊ10��˫������
    DoubleLinkedList* list = createDoubleLinkedList(10);

    printf("��ʼ������������%d\n", getCapacity(list));
    printf("��ǰԪ�ظ�����%d\n\n", getSize(list));

    // ���Ԫ�ص�β��
    addLast(list, 10);
    addLast(list, 20);
    addLast(list, 30);
    printf("β�����Ԫ�� 10, 20, 30��\n");
    traverseDoubleLinkedList(list);

    // ���Ԫ�ص�ͷ��
    addFirst(list, 5);
    addFirst(list, 2);
    printf("ͷ�����Ԫ�� 5, 2��\n");
    traverseDoubleLinkedList(list);

    // ɾ��ָ��Ԫ��
    printf("ɾ��Ԫ�� 20��\n");
    removeElement(list, 20);
    traverseDoubleLinkedList(list);

    // ɾ��ͷԪ��
    printf("ɾ��ͷԪ�أ�%d\n", removeFirst(list));
    traverseDoubleLinkedList(list);

    // ɾ��βԪ��
    printf("ɾ��βԪ�أ�%d\n", removeLast(list));
    traverseDoubleLinkedList(list);

    // β�����������
    addLast(list, 40);
    addLast(list, 50);
    printf("�ٴ�β����� 40, 50��\n");
    traverseDoubleLinkedList(list);

    // ��ӡͷβ����
    printf("��ǰͷԪ�أ�%d\n", getFirst(list));
    printf("��ǰβԪ�أ�%d\n", getLast(list));
    printf("��ǰ�����С��%d\n\n", getSize(list));

    // ��ղ��ͷ�����
    freeDoubleLinkedList(list);
    printf("�������ͷš�\n");

    return 0;
}

/**
��ʼ������������10
��ǰԪ�ظ�����0

β�����Ԫ�� 10, 20, 30��
����Ԫ�أ�10 20 30

ͷ�����Ԫ�� 5, 2��
����Ԫ�أ�2 5 10 20 30

ɾ��Ԫ�� 20��
����Ԫ�أ�2 5 10 30

ɾ��ͷԪ�أ�2
����Ԫ�أ�5 10 30

ɾ��βԪ�أ�30
����Ԫ�أ�5 10

�ٴ�β����� 40, 50��
����Ԫ�أ�5 10 40 50

��ǰͷԪ�أ�5
��ǰβԪ�أ�50
��ǰ�����С��4

�������ͷš�
 */