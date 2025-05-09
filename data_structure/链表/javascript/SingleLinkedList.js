// 单链表节点类
class Node {
    constructor(value) {
        this.value = value; // 节点存储的值
        this.next = null;   // 指向下一个节点的指针
    }
}

// 单链表类
class SingleLinkedList {
    /**
     * 构造函数，初始化单链表
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
     * @returns {boolean} 添加成功返回 true，失败（链表已满）抛出错误
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
            this._tail.next = newNode;
            this._tail = newNode;
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
                currentNode.next = newNode;
                if (currentNode === this._tail) {
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
        if (this._head === null) {
            this._tail = null; // 链表变空时更新尾节点
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

        const value = this._tail.value;

        if (this._size === 1) {
            this._head = this._tail = null; // 链表变空时更新头尾节点
        } else {
            let currentNode = this._head;
            while (currentNode.next !== this._tail) {
                currentNode = currentNode.next;
            }
            currentNode.next = null;
            this._tail = currentNode;
        }
        this._size--;
        return value;
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

        if (this._head.value === value) {
            this.removeHead();
            return true;
        }

        let currentNode = this._head;
        let prevNode = null;

        while (currentNode) {
            if (currentNode.value === value) {
                if (currentNode === this._tail) {
                    this.removeTail();
                } else {
                    prevNode.next = currentNode.next;
                    this._size--;
                }
                return true;
            }
            prevNode = currentNode;
            currentNode = currentNode.next;
        }
        return false;
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
    }
}

/**
 * 测试 SingleLinkedList 类的功能
 */
function testSingleLinkedList() {
    console.log("=== Testing SingleLinkedList ===");

    // 测试 1：初始化和基本属性
    console.log("\nTest 1: Initialization and Basic Properties");
    const list = new SingleLinkedList(5);
    console.log("Capacity:", list.capacity); // 5
    console.log("Size:", list.size); // 0
    console.log("Is Empty:", list.isEmpty()); // true
    console.log("Is Full:", list.isFull()); // false
    console.log("Head:", list.head); // null
    console.log("Tail:", list.tail); // null

    // 测试 2：尾部添加元素
    console.log("\nTest 2: Appending Elements");
    list.append(1);
    list.append(2);
    list.append(3);
    console.log("After appending 1, 2, 3:");
    console.log("Size:", list.size); // 3
    console.log("Head value:", list.head.value); // 1
    console.log("Tail value:", list.tail.value); // 3
    console.log("Traverse:");
    list.traverse(); // 1 2 3

    // 测试 3：在指定值后插入元素
    console.log("\nTest 3: Inserting Elements");
    console.log("Insert 4 after 2:", list.insert(4, 2)); // true
    console.log("Size:", list.size); // 4
    console.log("Tail value:", list.tail.value); // 3
    console.log("Traverse:");
    list.traverse(); // 1 2 4 3

    console.log("Insert 5 after 3:", list.insert(5, 3)); // true
    console.log("Size:", list.size); // 5
    console.log("Tail value:", list.tail.value); // 5
    console.log("Traverse:");
    list.traverse(); // 1 2 4 3 5

    try {
        console.log("Insert 6 after 999 (non-existent):", list.insert(6, 999)); // false
    } catch (e) {
        console.log("Expected error:", e.message); // List is full
    }

    // 测试 4：满链表添加
    console.log("\nTest 4: Adding to Full List");
    try {
        list.append(6);
        console.log("Should not reach here");
    } catch (e) {
        console.log("Expected error:", e.message); // List is full
    }

    // 测试 5：删除元素
    console.log("\nTest 5: Removing Elements");
    console.log("Remove 4:", list.remove(4)); // true
    console.log("Size:", list.size); // 4
    console.log("Traverse:");
    list.traverse(); // 1 2 3 5
    console.log("Remove 999 (non-existent):", list.remove(999)); // false

    // 测试 6：删除首元素
    console.log("\nTest 6: Removing Head");
    console.log("Remove head:", list.removeHead()); // 1
    console.log("Size:", list.size); // 3
    console.log("Head value:", list.head.value); // 2
    console.log("Traverse:");
    list.traverse(); // 2 3 5

    // 测试 7：删除尾元素
    console.log("\nTest 7: Removing Tail");
    console.log("Remove tail:", list.removeTail()); // 5
    console.log("Size:", list.size); // 2
    console.log("Tail value:", list.tail.value); // 3
    console.log("Traverse:");
    list.traverse(); // 2 3

    // 测试 8：遍历使用回调
    console.log("\nTest 8: Traverse with Callback");
    const values = [];
    list.traverse((value) => values.push(value));
    console.log("Collected values:", values); // [2, 3]

    // 测试 9：单一元素链表
    console.log("\nTest 9: Single Element List");
    const singleList = new SingleLinkedList(1);
    singleList.append(42);
    console.log("Size:", singleList.size); // 1
    console.log("Head value:", singleList.head.value); // 42
    console.log("Tail value:", singleList.tail.value); // 42
    console.log("Remove head:", singleList.removeHead()); // 42
    console.log("Is Empty:", singleList.isEmpty()); // true

    // 测试 10：空链表操作
    console.log("\nTest 10: Empty List Operations");
    const emptyList = new SingleLinkedList(3);
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
testSingleLinkedList();

/**
 === Testing SingleLinkedList ===

 Test 1: Initialization and Basic Properties
 Capacity: 5
 Size: 0
 Is Empty: true
 Is Full: false
 Head: null
 Tail: null
 Test 2: Appending Elements
 After appending 1, 2, 3:
 Size: 3
 Head value: 1
 Tail value: 3
 Traverse:
 1
 2
 Test 3: Inserting Elements
 Insert 4 after 2: true
 Size: 4
 Tail value: 3
 Traverse:
 1
 2
 4
 3
 Insert 5 after 3: true
 Size: 5
 Tail value: 5
 Traverse:
 1
 2
 4
 3
 5
 Expected error: List is full

 Test 4: Adding to Full List
 Expected error: List is full

 Test 5: Removing Elements
 Remove 4: true
 Size: 4
 Traverse:
 1
 2
 3
 5
 Remove 999 (non-existent): false

 Test 6: Removing Head
 Remove head: 1
 Size: 3
 Head value: 2
 Traverse:
 2
 3
 5

 Test 7: Removing Tail
 Remove tail: 5
 Size: 2
 Tail value: 3
 Traverse:
 2
 3

 Test 8: Traverse with Callback
 Collected values: [ 2, 3 ]

 Test 9: Single Element List
 Size: 1
 Head value: 42
 Tail value: 42
 Remove head: 42
 Is Empty: true

 Test 10: Empty List Operations
 Expected error: List is empty
 Expected error: List is empty
 Expected error: List is empty

 === All Tests Completed ===

 */