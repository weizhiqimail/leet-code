package org.zida;

class SinglyNode {
  public int data;
  public SinglyNode next;

  public SinglyNode(int data) {
    this.data = data;
    this.next = null;
  }

}

public class SinglyLinkedList {
  public SinglyNode head;
  public int size;
  public int capacity;

  SinglyLinkedList(int capacity) {
    if (capacity <= 0) {
      System.out.println("单链表的容量不能为空");
      this.capacity = 0;
      this.head = null;
      this.size = 0;
      return;
    }
    this.head = null;
    this.size = 0;
    this.capacity = capacity;
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

  SinglyNode getHeadNode() {
    if (this.isEmpty()) {
      System.out.println("获取链表的头节点，当前链表为空。");
      return null;
    }
    return this.head;
  }

  SinglyNode getTailNode() {
    if (this.isEmpty()) {
      System.out.println("获取链表的尾节点，当前链表为空。");
      return null;
    }

    SinglyNode currentNode = this.head;

    while (currentNode.next != null) {
      currentNode = currentNode.next;
    }
    return currentNode;
  }

  // 从头节点添加元素
  int addNodeFromHead(int data) {
    if (this.isFull()) {
      System.out.println("从头节点添加元素，当前链表已满，不能添加新元素。");
      return 0;
    }

    SinglyNode newNode = new SinglyNode(data);

    newNode.next = this.head;
    this.head = newNode;
    this.size++;
    return 1;
  }

  // 从尾节点添加元素
  int addNodeFromTail(int data) {
    if (this.isFull()) {
      System.out.println("从尾节点添加元素，当前链表已满，不能添加新元素。");
      return 0;
    }

    SinglyNode newNode = new SinglyNode(data);

    newNode.next = null;

    SinglyNode lastNode = this.getTailNode();

    if (lastNode != null) {
      lastNode.next = newNode;
    } else {
      this.head = newNode;
    }
    this.size++;
    return 1;
  }

  // 删除某个节点
  int removeNode(int data) {
    if (this.isEmpty()) {
      System.out.println("当前链表为空，不能删除节点。");
      return 0;
    }

    SinglyNode currentNode = this.head;

    if (currentNode.data == data) {
      this.head = currentNode.next;
      this.size--;
      return 1;
    }

    while (currentNode != null && currentNode.next != null) {
      if ( currentNode.next.data == data) {
        currentNode.next = currentNode.next.next;
        this.size--;
        return 1;
      }

      currentNode = currentNode.next;
    }
    System.out.printf("未找到值为 %d 的节点，删除失败。\n", data);
    return 0;

  }

  // 查找节点
  SinglyNode findNode(int data) {
    if (this.isEmpty()) {
      System.out.println("当前链表为空，不能查找元素。");
      return null;
    }

    SinglyNode currentNode = this.head;
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

    SinglyNode currentNode = this.head;
    System.out.printf("开始遍历链表：[ ");
    while (currentNode != null) {
      System.out.printf("%d ", currentNode.data);
      currentNode = currentNode.next;
    }
    System.out.printf("] 长度: %d\n", this.size);
  }
}





