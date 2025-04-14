#include <iostream>
#include <stdexcept>
#include <functional>

using namespace std; // 使用命名空间 std

template<typename T>
class SingleLinkedList {
private:
    // 内部节点类
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
    // 构造函数
    explicit SingleLinkedList(int capacity) : head(nullptr), size(0), capacity(capacity) {
        if (capacity <= 0) {
            throw invalid_argument("Capacity must be positive");
        }
    }

    // 析构函数
    ~SingleLinkedList() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    // 获取链表容量
    int getCapacity() const {
        return capacity;
    }

    // 获取当前元素数量
    int getSize() const {
        return size;
    }

    // 获取头元素
    T getFirst() const {
        if (size == 0) {
            throw runtime_error("List is empty");
        }
        return head->data;
    }

    // 获取尾元素
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

    // 尾部添加元素
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

    // 首部添加元素
    void addFirst(const T &data) {
        if (size >= capacity) {
            throw runtime_error("List is full");
        }
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // 添加元素（默认尾部添加）
    void add(const T &data) {
        addLast(data);
    }

    // 删除元素（删除首个匹配的元素）
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

    // 删除首元素
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

    // 删除尾元素
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

    // 遍历链表并输出所有元素
    void traverse() const {
        Node *current = head;
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

// 测试示例
int main() {
    // 创建一个容量为 5 的链表
    SingleLinkedList<int> list(5);

    // 添加元素到链表
    list.add(1);  // 添加 1
    list.add(2);  // 添加 2
    list.add(3);  // 添加 3
    list.add(4);  // 添加 4
    list.add(5);  // 添加 5

    // 输出链表内容
    cout << "链表内容：";
    list.traverse();  // 输出 1 2 3 4 5

    // 删除头部元素
    list.removeFirst();
    cout << "删除头部元素后链表内容：";
    list.traverse();  // 输出 2 3 4 5

    // 删除尾部元素
    list.removeLast();
    cout << "删除尾部元素后链表内容：";
    list.traverse();  // 输出 2 3 4

    // 删除元素 3
    list.remove(3);
    cout << "删除元素 3 后链表内容：";
    list.traverse();  // 输出 2 4

    // 添加元素到链表
    list.add(6);
    cout << "添加元素 6 后链表内容：";
    list.traverse();  // 输出 2 4 6

    // 尝试访问头部元素
    cout << "头部元素：";
    cout << list.getFirst() << endl;  // 输出 2

    // 尝试访问尾部元素
    cout << "尾部元素：";
    cout << list.getLast() << endl;  // 输出 6

    return 0;
}
/*
链表内容：1 2 3 4 5

删除头部元素后链表内容：2 3 4 5

删除尾部元素后链表内容：2 3 4

删除元素 3 后链表内容：2 4

添加元素 6 后链表内容：2 4 6

头部元素：2
尾部元素：6
 */
