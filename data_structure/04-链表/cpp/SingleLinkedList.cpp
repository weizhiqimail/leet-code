#include <iostream>
#include <stdexcept>
#include <functional>

using namespace std; // ʹ�������ռ� std

template<typename T>
class SingleLinkedList {
private:
    // �ڲ��ڵ���
    struct Node {
        T data;
        Node *next;

        Node(const T &data) : data(data), next(nullptr) {
        }
    };

    Node *head;
    int size;
    int capacity;

public:
    // ���캯��
    explicit SingleLinkedList(int capacity) : head(nullptr), size(0), capacity(capacity) {
        if (capacity <= 0) {
            throw invalid_argument("Capacity must be positive");
        }
    }

    // ��������
    ~SingleLinkedList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // ��ȡ��������
    int getCapacity() const {
        return capacity;
    }

    // ��ȡ��ǰԪ������
    int getSize() const {
        return size;
    }

    // ��ȡͷԪ��
    T getFirst() const {
        if (size == 0) {
            throw runtime_error("List is empty");
        }
        return head->data;
    }

    // ��ȡβԪ��
    T getLast() const {
        if (size == 0) {
            throw runtime_error("List is empty");
        }
        Node *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return current->data;
    }

    // β�����Ԫ��
    void addLast(const T &data) {
        if (size >= capacity) {
            throw runtime_error("List is full");
        }
        Node *newNode = new Node(data);
        if (size == 0) {
            head = newNode;
        } else {
            Node *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    // �ײ����Ԫ��
    void addFirst(const T &data) {
        if (size >= capacity) {
            throw runtime_error("List is full");
        }
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // ���Ԫ�أ�Ĭ��β����ӣ�
    void add(const T &data) {
        addLast(data);
    }

    // ɾ��Ԫ�أ�ɾ���׸�ƥ���Ԫ�أ�
    bool remove(const T &data) {
        if (size == 0) {
            return false;
        }
        if (head->data == data) {
            Node *temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
        Node *current = head;
        while (current->next != nullptr) {
            if (current->next->data == data) {
                Node *temp = current->next;
                current->next = temp->next;
                delete temp;
                size--;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // ɾ����Ԫ��
    T removeFirst() {
        if (size == 0) {
            throw runtime_error("List is empty");
        }
        Node *temp = head;
        T data = temp->data;
        head = temp->next;
        delete temp;
        size--;
        return data;
    }

    // ɾ��βԪ��
    T removeLast() {
        if (size == 0) {
            throw runtime_error("List is empty");
        }
        if (size == 1) {
            T data = head->data;
            delete head;
            head = nullptr;
            size--;
            return data;
        }
        Node *current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        T data = current->next->data;
        delete current->next;
        current->next = nullptr;
        size--;
        return data;
    }

    // ���������������Ԫ��
    void traverse() const {
        Node *current = head;
        while (current != nullptr) {
            // �����ǰ�ڵ��ֵ
            cout << current->data << " ";
            // �ƶ�����һ���ڵ�
            current = current->next;
        }
        cout << endl;
        cout << endl;
    }
};

// ����ʾ��
int main() {
    // ����һ������Ϊ 5 ������
    SingleLinkedList<int> list(5);

    // ���Ԫ�ص�����
    list.add(1);  // ��� 1
    list.add(2);  // ��� 2
    list.add(3);  // ��� 3
    list.add(4);  // ��� 4
    list.add(5);  // ��� 5

    // �����������
    cout << "�������ݣ�";
    list.traverse();  // ��� 1 2 3 4 5

    // ɾ��ͷ��Ԫ��
    list.removeFirst();
    cout << "ɾ��ͷ��Ԫ�غ��������ݣ�";
    list.traverse();  // ��� 2 3 4 5

    // ɾ��β��Ԫ��
    list.removeLast();
    cout << "ɾ��β��Ԫ�غ��������ݣ�";
    list.traverse();  // ��� 2 3 4

    // ɾ��Ԫ�� 3
    list.remove(3);
    cout << "ɾ��Ԫ�� 3 ���������ݣ�";
    list.traverse();  // ��� 2 4

    // ���Ԫ�ص�����
    list.add(6);
    cout << "���Ԫ�� 6 ���������ݣ�";
    list.traverse();  // ��� 2 4 6

    // ���Է���ͷ��Ԫ��
    cout << "ͷ��Ԫ�أ�";
    cout << list.getFirst() << endl;  // ��� 2

    // ���Է���β��Ԫ��
    cout << "β��Ԫ�أ�";
    cout << list.getLast() << endl;  // ��� 6

    return 0;
}
/*
�������ݣ�1 2 3 4 5

ɾ��ͷ��Ԫ�غ��������ݣ�2 3 4 5

ɾ��β��Ԫ�غ��������ݣ�2 3 4

ɾ��Ԫ�� 3 ���������ݣ�2 4

���Ԫ�� 6 ���������ݣ�2 4 6

ͷ��Ԫ�أ�2
β��Ԫ�أ�6
 */
