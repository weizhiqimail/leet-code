class DoubleNode {
  public int data;
  DoubleNode prev;
  DoubleNode next;

  public DoubleNode(int data) {
    this.data = data;
    this.prev = null;
    this.next = null;
  }

}

public class DoubleLinkedList {

  public DoubleNode head;
  public DoubleNode tail;
  public int size;
  public int capacity;

  public DoubleLinkedList(int capacity) {
    if (capacity <= 0) {
      System.out.println("双链表的容量不能为空");
      this.capacity = 0;
      this.size = 0;
      this.head = null;
      this.tail = null;
      return;
    }
    this.capacity = capacity;
    this.size = 0;
    this.head = null;
    this.tail = null;
  }

  int getSize() {
    return this.size;
  }

  int getCapacity() {
    return this.capacity;
  }

  boolean isEmpty() {
    return this.size == 0;
  }

  boolean isFull() {
    return this.capacity == this.size;
  }

  DoubleNode getHeadNode() {
    return this.head;
  }

  DoubleNode getTailNode() {
    return this.tail;
  }

  // 从头节点添加元素
  int addNodeFromHead(int data) {
    if (this.isFull()) {
      System.out.println("从头节点添加元素，当前链表已满，不能添加新元素。");
      return 0;
    }

    DoubleNode newNode = new DoubleNode(data);
    newNode.prev = null;
    newNode.next = this.head;

    if (this.head != null) {
      this.head.prev = newNode;
    }
    this.head = newNode;

    if (this.tail == null) {
      this.tail = newNode;
    }

    this.size++;
    return 1;
  }

  // 从尾节点添加元素
  int addNodeFromTail(int data) {
    if (this.isFull()) {
     System.out.println("从尾节点添加元素，当前链表已满，不能添加新元素。");
      return 0;
    }

    DoubleNode newNode = new DoubleNode(data);
    newNode.prev = this.tail;
    newNode.next = null;

    if (this.tail != null) {
      this.tail.next = newNode;
    }
    this.tail = newNode;

    if (this.head == null) {
      this.head = newNode;
    }

    this.size++;
    return 1;
  }

  // 删除节点
  int removeNode(int data) {
    if (this.isEmpty()) {
      System.out.println("当前链表为空，无需遍历。");
      return 0;
    }

    DoubleNode currentNode = this.head;

    while (currentNode != null && currentNode.data != data) {
      currentNode = currentNode.next;
    }

    if (currentNode == null) {
      System.out.printf("未找到值为 %d 的节点，删除失败。\n", data);
      return 0;
    }

    // 说明是首结点
    if (currentNode.prev == null) {
      this.head = currentNode.next;
    } else {
      currentNode.prev.next = currentNode.next;
    }

    if (currentNode.next == null) {
      this.tail = currentNode.prev;
    } else {
      currentNode.next.prev = currentNode.prev;
    }

    this.size--;
    return 1;
  }

  // 查找节点
  DoubleNode findNode(int data) {
    if (this.isEmpty()) {
      System.out.println("当前链表为空，不能查找元素。");
      return null;
    }

    DoubleNode currentNode = this.head;
    while (currentNode != null) {
      if (currentNode.data == data) {
        return currentNode;
      }
      currentNode = currentNode.next;
    }
    return null;
  }


  // 遍历链表
  void traverse() {
    if (this.isEmpty()) {
      System.out.println("当前链表为空，无需遍历。");
      return;
    }

    DoubleNode currentNode = this.head;
    System.out.printf("开始遍历链表：[ ");
    while (currentNode != null) {
      System.out.printf("%d ", currentNode.data);
      currentNode = currentNode.next;
    }
    System.out.printf("] 长度: %d\n", this.size);
  }

}
