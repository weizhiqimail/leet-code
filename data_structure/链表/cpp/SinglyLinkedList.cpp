#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
  int data;
  Node *next;

  Node(int data) : data(data), next(nullptr) {}
};

class SingleLinkedList {
public:
  SingleLinkedList(int capacity)
      : head(nullptr), tail(nullptr), size(0), capacity(capacity) {
    if (capacity <= 0) {
      throw std::invalid_argument("容量必须为正数");
    }
  }

  ~SingleLinkedList() { clear(); }

  bool isEmpty() const { return this->size == 0; }
  bool isFull() const { return this->size == this->capacity; }

  bool addFromHead(int data) {
    if (this->isFull()) {
      cout << "无法从头部添加：链表已满。" << endl;
      return false;
    }

    try {
      Node *newNode = new Node(data);
      newNode->next = this->head;
      this->head = newNode;
      if (!this->tail) {
        this->tail = newNode;
      }
      ++this->size;
      return true;
    } catch (const std::bad_alloc &) {
      cout << "内存分配失败。" << endl;
      return false;
    }
  }

  bool addFromTail(int data) {
    if (this->isFull()) {
      cout << "无法从尾部添加：链表已满。" << endl;
      return false;
    }

    try {
      Node *newNode = new Node(data);
      if (this->head == nullptr) {
        this->head = newNode;
        this->tail = newNode;
      } else {
        this->tail->next = newNode;
        this->tail = newNode;
      }
      ++this->size;
      return true;
    } catch (const std::bad_alloc &) {
      cout << "内存分配失败。" << endl;
      return false;
    }
  }

  bool remove(int data) {
    if (this->isEmpty()) {
      cout << "无法删除：链表为空。" << endl;
      return false;
    }

    Node *currentNode = this->head;
    Node *prevNode = nullptr;

    while (currentNode && currentNode->data != data) {
      prevNode = currentNode;
      currentNode = currentNode->next;
    }

    if (!currentNode) {
      cout << "未找到值为 " << data << " 的节点。" << endl;
      return false;
    }

    if (prevNode) {
      prevNode->next = currentNode->next;
    } else {
      this->head = currentNode->next;
    }

    if (currentNode == this->tail) {
      this->tail = prevNode;
    }

    delete currentNode;
    --this->size;
    return true;
  }

  Node *find(int data) const {
    if (this->isEmpty()) {
      cout << "链表为空，无需查找。" << endl;
      return nullptr;
    }

    Node *currentNode = this->head;
    while (currentNode) {
      if (currentNode->data == data) {
        return currentNode;
      }
      currentNode = currentNode->next;
    }
    cout << "未找到值为 " << data << " 的节点。" << endl;
    return nullptr;
  }

  void traverse() const {
    if (this->isEmpty()) {
      cout << "链表为空。" << endl;
      return;
    }

    cout << "链表内容：[ ";
    Node *currentNode = this->head;
    while (currentNode) {
      cout << currentNode->data << " ";
      currentNode = currentNode->next;
    }
    cout << "] 长度：" << this->size << endl;
  }

  void clear() {
    while (this->head) {
      Node *temp = this->head;
      this->head = this->head->next;
      delete temp;
    }
    this->tail = nullptr;
    this->size = 0;
  }

private:
  Node *head;
  Node *tail;
  int size;
  int capacity;
};

int main() {
  try {
    SingleLinkedList list(5);

    cout << "--- 从尾部依次添加 1,2,3,4,5,6 共 6 个元素 ---" << endl;
    list.addFromTail(1);
    list.addFromTail(2);
    list.addFromTail(3);
    list.addFromTail(4);
    list.addFromTail(5);
    list.addFromTail(6);
    list.traverse();

    cout << "--- 删除节点 3,4,5 ---" << endl;
    list.remove(3);
    list.remove(4);
    list.remove(5);
    list.traverse();

    cout << "--- 从头部依次添加 6,7 共 2 个元素 ---" << endl;
    list.addFromHead(6);
    list.addFromHead(7);
    list.traverse();
  } catch (const std::exception &e) {
    cout << "错误：" << e.what() << endl;
  }
  return 0;
}