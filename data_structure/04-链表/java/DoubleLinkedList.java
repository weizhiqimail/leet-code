public class DoubleLinkedList<E> {
  // 内部节点类
  private class Node {
    E data;
    Node prev;
    Node next;

    Node(E data) {
      this.data = data;
      this.prev = null;
      this.next = null;
    }
  }

  private Node head; // 头节点
  private Node tail; // 尾节点
  private int size;  // 当前元素数量
  private final int capacity; // 链表容量

  // 构造函数，指定容量
  public DoubleLinkedList(int capacity) {
    if (capacity <= 0) {
      throw new IllegalArgumentException("Capacity must be positive");
    }
    this.head = null;
    this.tail = null;
    this.size = 0;
    this.capacity = capacity;
  }

  // 获取链表容量
  public int getCapacity() {
    return capacity;
  }

  // 获取当前实际元素数量
  public int getSize() {
    return size;
  }

  // 获取头元素
  public E getFirst() {
    if (isEmpty()) {
      throw new IllegalStateException("List is empty");
    }
    return head.data;
  }

  // 获取尾元素
  public E getLast() {
    if (isEmpty()) {
      throw new IllegalStateException("List is empty");
    }
    return tail.data;
  }

  // 尾部添加元素
  public void addLast(E element) {
    if (size >= capacity) {
      throw new IllegalStateException("List is full");
    }
    Node newNode = new Node(element);
    if (isEmpty()) {
      head = tail = newNode;
    } else {
      newNode.prev = tail;
      tail.next = newNode;
      tail = newNode;
    }
    size++;
  }

  // 首部添加元素
  public void addFirst(E element) {
    if (size >= capacity) {
      throw new IllegalStateException("List is full");
    }
    Node newNode = new Node(element);
    if (isEmpty()) {
      head = tail = newNode;
    } else {
      newNode.next = head;
      head.prev = newNode;
      head = newNode;
    }
    size++;
  }

  // 添加元素（默认尾部添加）
  public void add(E element) {
    addLast(element);
  }

  // 删除元素（删除首个匹配的元素）
  public boolean remove(E element) {
    if (isEmpty() || element == null) {
      return false;
    }
    Node current = head;
    while (current != null) {
      if (current.data.equals(element)) {
        unlink(current);
        return true;
      }
      current = current.next;
    }
    return false;
  }

  // 删除首元素
  public E removeFirst() {
    if (isEmpty()) {
      throw new IllegalStateException("List is empty");
    }
    Node oldHead = head;
    E data = oldHead.data;
    unlink(oldHead);
    return data;
  }

  // 删除尾元素
  public E removeLast() {
    if (isEmpty()) {
      throw new IllegalStateException("List is empty");
    }
    Node oldTail = tail;
    E data = oldTail.data;
    unlink(oldTail);
    return data;
  }

  // 辅助方法：从链表中移除指定节点
  private void unlink(Node node) {
    if (node == head && node == tail) {
      head = tail = null;
    } else if (node == head) {
      head = head.next;
      head.prev = null;
    } else if (node == tail) {
      tail = tail.prev;
      tail.next = null;
    } else {
      node.prev.next = node.next;
      node.next.prev = node.prev;
    }
    size--;
  }

  // 辅助方法：检查是否为空
  private boolean isEmpty() {
    return size == 0;
  }
}