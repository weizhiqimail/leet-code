#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList {
private:
    // �ڲ��ڵ��࣬����ǰ���ڵ㡢�����Լ���̽ڵ�
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node* head;  // ����ͷ�ڵ�
    Node* tail;  // ����β�ڵ�
    int size;    // ��ǰ����Ԫ������
    int capacity; // ������������

public:
    // ���캯������ʼ�������������������
    explicit DoubleLinkedList(int capacity) : head(nullptr), tail(nullptr), size(0), capacity(capacity) {
        if (capacity <= 0) {
            throw invalid_argument("Capacity must be positive");  // �����������0
        }
    }

    // �����������ͷ������е����нڵ�
    ~DoubleLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    // ��ȡ��������
    int getCapacity() const {
        return capacity;
    }

    // ��ȡ��ǰ����Ԫ������
    int getSize() const {
        return size;
    }

    // ��ȡͷԪ�أ�������Ϊ�����׳��쳣
    T getFirst() const {
        if (size == 0) {
            throw runtime_error("List is empty");
        }
        return head->data;
    }

    // ��ȡβԪ�أ�������Ϊ�����׳��쳣
    T getLast() const {
        if (size == 0) {
            throw runtime_error("List is empty");
        }
        return tail->data;
    }

    // β�����Ԫ��
    void addLast(const T& data) {
        if (size >= capacity) {
            throw runtime_error("List is full");
        }
        Node* newNode = new Node(data);  // �����½ڵ�
        if (size == 0) {  // �������Ϊ�գ��½ڵ��Ϊͷ��β
            head = tail = newNode;
        } else {  // ���򣬲��뵽β��
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // �ײ����Ԫ��
    void addFirst(const T& data) {
        if (size >= capacity) {
            throw runtime_error("List is full");
        }
        Node* newNode = new Node(data);  // �����½ڵ�
        if (size == 0) {  // �������Ϊ�գ��½ڵ��Ϊͷ��β
            head = tail = newNode;
        } else {  // ���򣬲��뵽ͷ��
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // Ĭ��β�����Ԫ��
    void add(const T& data) {
        addLast(data);
    }

    // ɾ��Ԫ�أ�ɾ���׸�ƥ���Ԫ�أ�
    bool remove(const T& data) {
        if (size == 0) {
            return false;  // ����Ϊ�գ��޷�ɾ��
        }
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {  // �ҵ�ƥ��Ԫ��
                if (current == head) {  // ɾ��ͷԪ��
                    head = current->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    } else {
                        tail = nullptr;  // �������Ϊ�գ�β��ҲΪnullptr
                    }
                } else if (current == tail) {  // ɾ��βԪ��
                    tail = current->prev;
                    tail->next = nullptr;
                } else {  // ɾ���м�Ԫ��
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;  // �ͷŽڵ��ڴ�
                size--;
                return true;
            }
            current = current->next;
        }
        return false;  // û���ҵ�Ԫ��
    }

    // ɾ����Ԫ��
    T removeFirst() {
        if (size == 0) {
            throw runtime_error("List is empty");
        }
        Node* temp = head;
        T data = temp->data;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;  // ���ɾ��������Ϊ�գ�β��ҲΪnullptr
        }
        delete temp;
        size--;
        return data;
    }

    // ɾ��βԪ��
    T removeLast() {
        if (size == 0) {
            throw runtime_error("List is empty");
        }
        Node* temp = tail;
        T data = temp->data;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;  // ���ɾ��������Ϊ�գ�ͷ��ҲΪnullptr
        }
        delete temp;
        size--;
        return data;
    }

    // ���������������Ԫ��
    void traverse() const {
        Node* current = head;
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

// ���Դ���
int main() {
    try {
        // ����һ������Ϊ 5 ��˫������
        DoubleLinkedList<int> list(5);

        // ���Ԫ�ص�����
        list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);
        list.add(50);

        // �����������
        cout << "�������ݣ�";
        list.traverse();  // ��� 10 20 30 40 50

        // ɾ��ͷ��Ԫ��
        list.removeFirst();
        cout << "ɾ��ͷ��Ԫ�غ��������ݣ�";
        list.traverse();  // ��� 20 30 40 50

        // ɾ��β��Ԫ��
        list.removeLast();
        cout << "ɾ��β��Ԫ�غ��������ݣ�";
        list.traverse();  // ��� 20 30 40

        // ɾ��Ԫ�� 30
        list.remove(30);
        cout << "ɾ��Ԫ�� 30 ���������ݣ�";
        list.traverse();  // ��� 20 40

        // ���Ԫ�ص�����
        list.add(60);
        cout << "���Ԫ�� 60 ���������ݣ�";
        list.traverse();  // ��� 20 40 60

        // ��������ͷԪ��
        cout << "ͷԪ�أ�";
        cout << list.getFirst() << endl;  // ��� 20

        // ��������βԪ��
        cout << "βԪ�أ�";
        cout << list.getLast() << endl;  // ��� 60

    } catch (const runtime_error& e) {
        cout << "����: " << e.what() << endl;
    } catch (const invalid_argument& e) {
        cout << "����: " << e.what() << endl;
    }

    return 0;
}

/*
�������ݣ�10 20 30 40 50

ɾ��ͷ��Ԫ�غ��������ݣ�20 30 40 50

ɾ��β��Ԫ�غ��������ݣ�20 30 40

ɾ��Ԫ�� 30 ���������ݣ�20 40

���Ԫ�� 60 ���������ݣ�20 40 60

ͷԪ�أ�20
βԪ�أ�60

 */