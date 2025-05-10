
public class SingleLinkedList<E> {

  private class Node {
    E data;
    Node next;

    Node(E data) {
      this.data = data;
      this.next = null;
    }
  }


  private Node node;
  private int size;
  private final int capacity;

  // 构造函数，指定容量
  public SingleLinkedList(int capacity = 10) {
    if (capacity <= 0) {
      throw new IllegalArgumentException("Capacity must be greater than 0");
    }

    this.head = null;
    this.size = 0;
    this.capacity = capacity;
  }

  // 获取链表容量
  public int getCapacity() {
    return capacity;
  }

  // 获取链表大小
  public int getSize() {
    return size;
  }

  // 检查链表是否为空
  public boolean isEmpty() {
    return size == 0;
  }

  // 获取链表头节点
  public E getHeadNode() {
    if (isEmpty()) {
      throw new IllegalStateException("List is empty");
    }
    return head.data;
  }

  // 获取链表尾节点
  public E getTailNode() {
    if (isEmpty()) {
      throw new IllegalStateException("List is empty");
    }
    Node currentNode = head;
    while(currentNode.next != null) {
      currentNode = currentNode.next;
    }
    return currentNode.data;
  }

  // 添加节点到链表头部
  public void addFirst(E element) {
    if (size>capacity) {
      throw new IllegalStateException("List is full");
    }
    Node newNode = new Node(element);
    newNode.next = head;
    head = newNode;
    size++;
  }

  // 添加节点到链表尾部
  public void addLast(E element) {
    if (size>capacity) {
      throw new IllegalStateException("List is full");
    }

    Node newNode = new Node(element);
    if (isEmpty()) {
      head = newNode;
    } else {
      Node currentNode = head;
      while(currentNode.next != null) {
        currentNode = currentNode.next;
      }
      currentNode.next = newNode;
    }
    size++;
  }

  // 默认添加元素到链表尾部
  public void add(E element) {
    addLast(element);
  }

  // 删除元素（删除收个匹配到的元素）
  public boolean remove(E element) {
    if (isEmpty()) {
      return false;
    }
    if (element === null) {
      return false;
    }

    if (head.data.equals(element)) {
      head = head.next;
      size--;
      return true;
    }

    Node currentNode = head;
    while(currentNode.next != null) {
      if (currentNode.next.data.equals(element)) {
        currentNode.next = currentNode.next.next;
        size--;
        return true;
      }
      currentNode = currentNode.next;
    }


  }


}


