#include <stdio.h>
#include <stdlib.h>

// ��������ṹ
typedef struct Node {
    int data;               // �洢������
    struct Node *next;      // ָ����һ������ָ��
} Node;

// ������ṹ��
typedef struct SingleLinkedList {
    Node *head;             // �����ͷ���
    int size;               // ��ǰ������
    int capacity;           // �����������
} SingleLinkedList;

// ����һ���µĵ�������ʼ������
SingleLinkedList *createSingleLinkedList(int capacity) {
    if (capacity <= 0) {
        printf("���������������0\n");
        return NULL;
    }
    SingleLinkedList *list = (SingleLinkedList *) malloc(sizeof(SingleLinkedList));
    if (list == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    list->capacity = capacity;
    return list;
}

// ��ȡ��������
int getCapacity(SingleLinkedList *list) {
    return list->capacity;
}

// ��ȡ����ǰԪ�ظ���
int getSize(SingleLinkedList *list) {
    return list->size;
}

// �ж������Ƿ�Ϊ��
int isEmpty(SingleLinkedList *list) {
    return list->size == 0;
}

// ��ȡͷ��������
int getHeadNode(SingleLinkedList *list) {
    if (isEmpty(list)) {
        printf("����Ϊ��\n");
        exit(1);
    }
    return list->head->data;
}

// ��ȡβ��������
int getTailNode(SingleLinkedList *list) {
    if (isEmpty(list)) {
        printf("����Ϊ��\n");
        exit(1);
    }

    Node *currentNode = list->head;
    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }
    return currentNode->data;
}

// ������β�����һ���½��
void addLastNode(SingleLinkedList *list, int data) {
    if (list->size >= list->capacity) {
        printf("��������\n");
        exit(1);
    }

    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
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

// ������ͷ�����һ���½��
void addFirstNode(SingleLinkedList *list, int data) {
    if (list->size >= list->capacity) {
        printf("��������\n");
        exit(1);
    }

    Node *newNode = (Node *) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�ڴ����ʧ��\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

// ɾ���������׸�ƥ�� data �Ľ��
int removeNode(SingleLinkedList *list, int data) {
    if (isEmpty(list)) {
        printf("����Ϊ��\n");
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
    return 0;  // δ�ҵ�ƥ��Ԫ��
}

// ɾ������ͷ�����
int removeFirstNode(SingleLinkedList *list) {
    if (isEmpty(list)) {
        printf("����Ϊ��\n");
        exit(1);
    }

    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->size--;
    return 1;
}

// ɾ������β�����
int removeLastNode(SingleLinkedList *list) {
    if (isEmpty(list)) {
        printf("����Ϊ��\n");
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

// �ͷ���������ռ�õ��ڴ�
void freeSingleLinkedList(SingleLinkedList *list) {
    Node *currentNode = list->head;
    while (currentNode != NULL) {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    free(list);
}

// ����������ӡ����Ԫ��
void traverseList(SingleLinkedList *list) {
    if (isEmpty(list)) {
        printf("����Ϊ��\n");
        return;
    }

    printf("����Ԫ�أ�");
    Node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n\n");
}


// ���Ե�����Ĺ���
int main() {
    printf("��ʼ����...\n");

    // 1. ��������
    SingleLinkedList *list = createSingleLinkedList(5);
    printf("������������: %d���Ƿ�Ϊ��: %s\n", getCapacity(list), isEmpty(list) ? "��" : "��");
    traverseList(list);

    // 2. ���Ԫ��
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

    printf("���Ԫ�غ󣬵�ǰ��С: %d\n", getSize(list));

    // 3. ��ȡͷβ���
    printf("ͷ�������: %d\n", getHeadNode(list));
    printf("β�������: %d\n", getTailNode(list));

    // 4. ɾ��ָ��Ԫ��
    printf("����ɾ��Ԫ�� 20: %s\n", removeNode(list, 20) ? "�ɹ�" : "ʧ��");
    traverseList(list);

    printf("����ɾ��Ԫ�� 100�������ڣ�: %s\n", removeNode(list, 100) ? "�ɹ�" : "ʧ��");
    traverseList(list);

    // 5. ɾ��ͷ���
    removeFirstNode(list);
    printf("ɾ��ͷ�����µ�ͷ�������: %d\n", getHeadNode(list));
    traverseList(list);

    // 6. ɾ��β���
    int removed = removeLastNode(list);
    printf("ɾ��β��㣬ɾ����ֵΪ: %d\n", removed);
    traverseList(list);

    // 7. ��ӡʣ��Ԫ��
    printf("��������Ԫ�����£�\n");
    traverseList(list);

    // 8. �ͷ�����
    freeSingleLinkedList(list);
    printf("�������ͷš�\n");

    return 0;
}

/**
��ʼ����...
������������: 5���Ƿ�Ϊ��: ��
����Ϊ��

����Ԫ�أ�10

����Ԫ�أ�10 20

����Ԫ�أ�5 10 20

����Ԫ�أ�5 10 20 30

����Ԫ�أ�1 5 10 20 30

���Ԫ�غ󣬵�ǰ��С: 5
ͷ�������: 1
β�������: 30
����ɾ��Ԫ�� 20: �ɹ�
����Ԫ�أ�1 5 10 30

����ɾ��Ԫ�� 100�������ڣ�: ʧ��
����Ԫ�أ�1 5 10 30

ɾ��ͷ�����µ�ͷ�������: 5
����Ԫ�أ�5 10 30

ɾ��β��㣬ɾ����ֵΪ: 30
����Ԫ�أ�5 10

��������Ԫ�����£�
����Ԫ�أ�5 10

�������ͷš�
 */
