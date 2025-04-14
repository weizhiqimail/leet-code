#include <stdexcept>
#include <iostream>

using namespace std;

template<typename T>
class DoubleLinkedList {
private:
    // 内部节点类，包含前驱节点、数据以及后继节点
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };

    Node* head;  // 链表头节点
    Node* tail;  // 链表尾节点
    int size;    // 当前链表元素数量
    int capacity; // 链表的最大容量

public:
    // 构造函数，初始化空链表并设置最大容量
    explicit DoubleLinkedList(int capacity) : head(nullptr), tail(nullptr), size(0), capacity(capacity) {
        if (capacity <= 0) {
            throw invalid_argument("Capacity must be positive");  // 容量必须大于0
        }
    }

    // 析构函数，释放链表中的所有节点
    ~DoubleLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    // 获取链表容量
    int getCapacity() const {
        return capacity;
    }

    // 获取当前链表元素数量
    int getSize() const {
        return size;
    }

    // 获取头元素，若链表为空则抛出异常
    T getFirst() const {
        if (size == 0) {
            throw runtime_error("List is empty");
        }
        return head->data;
    }

    // 获取尾元素，若链表为空则抛出异常
    T getLast() const {
        if (size == 0) {
            throw runtime_error("List is empty");
        }
        return tail->data;
    }

    // 尾部添加元素
    void addLast(const T& data) {
        if (size >= capacity) {
            throw runtime_error("List is full");
        }
        Node* newNode = new Node(data);  // 创建新节点
        if (size == 0) {  // 如果链表为空，新节点成为头和尾
            head = tail = newNode;
        } else {  // 否则，插入到尾部
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    // 首部添加元素
    void addFirst(const T& data) {
        if (size >= capacity) {
            throw runtime_error("List is full");
        }
        Node* newNode = new Node(data);  // 创建新节点
        if (size == 0) {  // 如果链表为空，新节点成为头和尾
            head = tail = newNode;
        } else {  // 否则，插入到头部
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    // 默认尾部添加元素
    void add(const T& data) {
        addLast(data);
    }

    // 删除元素（删除首个匹配的元素）
    bool remove(const T& data) {
        if (size == 0) {
            return false;  // 链表为空，无法删除
        }
        Node* current = head;
        while (current != nullptr) {
            if (current->data == data) {  // 找到匹配元素
                if (current == head) {  // 删除头元素
                    head = current->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    } else {
                        tail = nullptr;  // 如果链表为空，尾部也为nullptr
                    }
                } else if (current == tail) {  // 删除尾元素
                    tail = current->prev;
                    tail->next = nullptr;
                } else {  // 删除中间元素
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;  // 释放节点内存
                size--;
                return true;
            }
            current = current->next;
        }
        return false;  // 没有找到元素
    }

    // 删除首元素
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
            tail = nullptr;  // 如果删除后链表为空，尾部也为nullptr
        }
        delete temp;
        size--;
        return data;
    }

    // 删除尾元素
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
            head = nullptr;  // 如果删除后链表为空，头部也为nullptr
        }
        delete temp;
        size--;
        return data;
    }

    // 遍历链表并输出所有元素
    void traverse() const {
        Node* current = head;
        while (current != nullptr) {
            // 输出当前节点的值
            cout << current->data << " ";
            // 移动到下一个节点
            current = current->next;
        }
        cout << endl;
        cout << endl;
    }
};

// 测试代码
int main() {
    try {
        // 创建一个容量为 5 的双向链表
        DoubleLinkedList<int> list(5);

        // 添加元素到链表
        list.add(10);
        list.add(20);
        list.add(30);
        list.add(40);
        list.add(50);

        // 输出链表内容
        cout << "链表内容：";
        list.traverse();  // 输出 10 20 30 40 50

        // 删除头部元素
        list.removeFirst();
        cout << "删除头部元素后链表内容：";
        list.traverse();  // 输出 20 30 40 50

        // 删除尾部元素
        list.removeLast();
        cout << "删除尾部元素后链表内容：";
        list.traverse();  // 输出 20 30 40

        // 删除元素 30
        list.remove(30);
        cout << "删除元素 30 后链表内容：";
        list.traverse();  // 输出 20 40

        // 添加元素到链表
        list.add(60);
        cout << "添加元素 60 后链表内容：";
        list.traverse();  // 输出 20 40 60

        // 输出链表的头元素
        cout << "头元素：";
        cout << list.getFirst() << endl;  // 输出 20

        // 输出链表的尾元素
        cout << "尾元素：";
        cout << list.getLast() << endl;  // 输出 60

    } catch (const runtime_error& e) {
        cout << "错误: " << e.what() << endl;
    } catch (const invalid_argument& e) {
        cout << "错误: " << e.what() << endl;
    }

    return 0;
}

/*
链表内容：10 20 30 40 50

删除头部元素后链表内容：20 30 40 50

删除尾部元素后链表内容：20 30 40

删除元素 30 后链表内容：20 40

添加元素 60 后链表内容：20 40 60

头元素：20
尾元素：60

 */