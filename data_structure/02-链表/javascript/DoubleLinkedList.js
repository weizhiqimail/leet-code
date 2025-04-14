// 双链表节点类
class Node {
    constructor(value) {
        this.value = value; // 节点存储的值
        this.next = null;   // 指向下一个节点的指针
        this.prev = null;   // 指向前一个节点的指针
    }
}

// 双链表类
class DoubleLinkedList {
    /**
     * 构造函数，初始化双链表
     * @param {number} capacity - 链表最大容量，默认值为 10
     */
    constructor(capacity = 10) {
        if (capacity <= 0) {
            throw new Error("Capacity must be positive");
        }
        this._head = null;      // 链表头节点
        this._tail = null;      // 链表尾节点
        this._capacity = capacity; // 链表容量
        this._size = 0;         // 当前元素数量
    }

    /**
     * 获取链表容量
     * @returns {number} 链表的最大容量
     */
    get capacity() {
        return this._capacity;
    }

    /**
     * 获取当前元素数量
     * @returns {number} 链表中的元素数量
     */
    get size() {
        return this._size;
    }

    /**
     * 获取头节点
     * @returns {Node|null} 链表的头节点
     */
    get head() {
        return this._head;
    }

    /**
     * 获取尾节点
     * @returns {Node|null} 链表的尾节点
     */
    get tail() {
        return this._tail;
    }

    /**
     * 检查链表是否已满
     * @returns {boolean} 如果链表已满返回 true，否则返回 false
     */
    isFull() {
        return this._size === this._capacity;
    }

    /**
     * 检查链表是否为空
     * @returns {boolean} 如果链表为空返回 true，否则返回 false
     */
    isEmpty() {
        return this._size === 0;
    }

    /**
     * 在链表尾部添加元素
     * @param {*} value - 要添加的元素值
     * @returns {boolean} 添加成功返回 true
     * @throws {Error} 如果链表已满
     */
    append(value) {
        if (this.isFull()) {
            throw new Error("List is full");
        }

        const newNode = new Node(value);

        if (this.isEmpty()) {
            this._head = this._tail = newNode;
        } else {
            newNode.prev = this._tail;
            this._tail.next = newNode;
            this._tail = newNode;
        }
        this._size++;
        return true;
    }

    /**
     * 在链表首部添加元素
     * @param {*} value - 要添加的元素值
     * @returns {boolean} 添加成功返回 true
     * @throws {Error} 如果链表已满
     */
    prepend(value) {
        if (this.isFull()) {
            throw new Error("List is full");
        }

        const newNode = new Node(value);

        if (this.isEmpty()) {
            this._head = this._tail = newNode;
        } else {
            newNode.next = this._head;
            this._head.prev = newNode;
            this._head = newNode;
        }
        this._size++;
        return true;
    }

    /**
     * 在指定值后插入新元素
     * @param {*} value - 要插入的元素值
     * @param {*} prevValue - 插入位置前的元素值
     * @returns {boolean} 插入成功返回 true，失败（未找到 prevValue 或链表已满）返回 false
     * @throws {Error} 如果链表已满
     */
    insert(value, prevValue) {
        if (this.isFull()) {
            throw new Error("List is full");
        }

        if (this.isEmpty()) {
            return false;
        }

        let currentNode = this._head;
        while (currentNode) {
            if (currentNode.value === prevValue) {
                const newNode = new Node(value);
                newNode.next = currentNode.next;
                newNode.prev = currentNode;
                currentNode.next = newNode;
                if (newNode.next) {
                    newNode.next.prev = newNode;
                } else {
                    this._tail = newNode; // 更新尾节点
                }
                this._size++;
                return true;
            }
            currentNode = currentNode.next;
        }
        return false;
    }

    /**
     * 删除指定值的元素
     * @param {*} value - 要删除的元素值
     * @returns {boolean} 删除成功返回 true，失败（未找到值）返回 false
     * @throws {Error} 如果链表为空
     */
    remove(value) {
        if (this.isEmpty()) {
            throw new Error("List is empty");
        }

        let currentNode = this._head;
        while (currentNode) {
            if (currentNode.value === value) {
                if (currentNode === this._head) {
                    this.removeHead();
                } else if (currentNode === this._tail) {
                    this.removeTail();
                } else {
                    currentNode.prev.next = currentNode.next;
                    currentNode.next.prev = currentNode.prev;
                    this._size--;
                }
                return true;
            }
            currentNode = currentNode.next;
        }
        return false;
    }

    /**
     * 删除链表首元素
     * @returns {*} 删除的元素值
     * @throws {Error} 如果链表为空
     */
    removeHead() {
        if (this.isEmpty()) {
            throw new Error("List is empty");
        }

        const removedNode = this._head;
        const value = removedNode.value;

        this._head = this._head.next;
        if (this._head) {
            this._head.prev = null;
        } else {
            this._tail = null;
        }
        this._size--;
        return value;
    }

    /**
     * 删除链表尾元素
     * @returns {*} 删除的元素值
     * @throws {Error} 如果链表为空
     */
    removeTail() {
        if (this.isEmpty()) {
            throw new Error("List is empty");
        }

        const removedNode = this._tail;
        const value = removedNode.value;

        this._tail = this._tail.prev;
        if (this._tail) {
            this._tail.next = null;
        } else {
            this._head = null;
        }
        this._size--;
        return value;
    }

    /**
     * 遍历链表并执行回调函数
     * @param {function} [callback] - 可选的回调函数，接收每个节点的值
     * @returns {void}
     */
    traverse(callback = null) {
        let currentNode = this._head;
        while (currentNode) {
            if (callback) {
                callback(currentNode.value);
            } else {
                console.log(currentNode.value);
            }
            currentNode = currentNode.next;
        }
        console.log();
    }
}


/**
 * 测试 DoubleLinkedList 类的功能
 */
function testDoubleLinkedList() {
    console.log("=== Testing DoubleLinkedList ===");

    // 测试 1：初始化和基本属性
    console.log("\nTest 1: Initialization and Basic Properties");
    const list = new DoubleLinkedList(5);
    console.log("Capacity:", list.capacity); // 5
    console.log("Size:", list.size); // 0
    console.log("Is Empty:", list.isEmpty()); // true
    console.log("Is Full:", list.isFull()); // false
    console.log("Head:", list.head); // null
    console.log("Tail:", list.tail); // null

    // 测试 2：尾部和首部添加元素
    console.log("\nTest 2: Appending and Prepending Elements");
    list.append(1);
    list.append(2);
    list.prepend(0);
    console.log("After appending 1, 2 and prepending 0:");
    console.log("Size:", list.size); // 3
    console.log("Head value:", list.head.value); // 0
    console.log("Tail value:", list.tail.value); // 2
    console.log("Traverse:");
    list.traverse(); // 0 1 2

    // 测试 3：在指定值后插入元素
    console.log("\nTest 3: Inserting Elements");
    console.log("Insert 3 after 1:", list.insert(3, 1)); // true
    console.log("Size:", list.size); // 4
    console.log("Tail value:", list.tail.value); // 2
    console.log("Traverse:");
    list.traverse(); // 0 1 3 2

    console.log("Insert 4 after 2:", list.insert(4, 2)); // true
    console.log("Size:", list.size); // 5
    console.log("Tail value:", list.tail.value); // 4
    console.log("Traverse:");
    list.traverse(); // 0 1 3 2 4

    try {
        console.log("Insert 5 after 999 (non-existent):", list.insert(5, 999)); // false
    } catch (err) {
        console.log("Expected error:", err.message); // List is full
    }

    // 测试 4：满链表添加
    console.log("\nTest 4: Adding to Full List");
    try {
        list.append(5);
        console.log("Should not reach here");
    } catch (e) {
        console.log("Expected error:", e.message); // List is full
    }

    // 测试 5：删除元素
    console.log("\nTest 5: Removing Elements");
    console.log("Remove 3:", list.remove(3)); // true
    console.log("Size:", list.size); // 4
    console.log("Traverse:");
    list.traverse(); // 0 1 2 4

    console.log("Remove 999 (non-existent):", list.remove(999)); // false

    // 测试 6：删除首元素
    console.log("\nTest 6: Removing Head");
    console.log("Remove head:", list.removeHead()); // 0
    console.log("Size:", list.size); // 3
    console.log("Head value:", list.head.value); // 1
    console.log("Traverse:");
    list.traverse(); // 1 2 4

    // 测试 7：删除尾元素
    console.log("\nTest 7: Removing Tail");
    console.log("Remove tail:", list.removeTail()); // 4
    console.log("Size:", list.size); // 2
    console.log("Tail value:", list.tail.value); // 2
    console.log("Traverse:");
    list.traverse(); // 1 2

    // 测试 8：遍历使用回调
    console.log("\nTest 8: Traverse with Callback");
    const values = [];
    list.traverse((value) => values.push(value));
    console.log("Collected values:", values); // [1, 2]

    // 测试 9：单一元素链表
    console.log("\nTest 9: Single Element List");
    const singleList = new DoubleLinkedList(1);
    singleList.append(42);
    console.log("Size:", singleList.size); // 1
    console.log("Head value:", singleList.head.value); // 42
    console.log("Tail value:", singleList.tail.value); // 42
    console.log("Remove head:", singleList.removeHead()); // 42
    console.log("Is Empty:", singleList.isEmpty()); // true

    // 测试 10：空链表操作
    console.log("\nTest 10: Empty List Operations");
    const emptyList = new DoubleLinkedList(3);
    try {
        emptyList.removeHead();
        console.log("Should not reach here");
    } catch (e) {
        console.log("Expected error:", e.message); // List is empty
    }
    try {
        emptyList.removeTail();
        console.log("Should not reach here");
    } catch (e) {
        console.log("Expected error:", e.message); // List is empty
    }
    try {
        emptyList.remove(1);
        console.log("Should not reach here");
    } catch (e) {
        console.log("Expected error:", e.message); // List is empty
    }

    console.log("\n=== All Tests Completed ===");
}

// 执行测试
testDoubleLinkedList();