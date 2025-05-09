class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

const removeLinkedListElements1 = (head, val) => {
    // 判断空节点
    while (head !== null && head.val === val) {
        const delNode = head;
        head = head.next;
        delNode.next = null;
    }

    if (head === null) {
        return null;
    }

    let prev = head;

    while (prev.next !== null) {
        if (prev.next.val === val) {
            const delNode = prev.next;
            prev.next = delNode.next;
            delNode.next = null;
        } else {
            prev = prev.next;
        }
    }

    return head;
};

// 使用虚拟头节点
const removeLinkedListElements2 = (head, val) => {
    const dummyHead = new ListNode(-1);
    dummyHead.next = head;

    // 从虚拟节点开始判断
    let prev = dummyHead;

    while (prev.next !== null) {
        if (prev.next.val === val) {
            const delNode = prev.next;
            prev.next = delNode.next;
            delNode.next = null;
        } else {
            prev = prev.next;
        }
    }

    return dummyHead.next;
};

// 使用递归
const removeLinkedListElements3 = (head, val) => {
    if (head === null) {
        return null;
    }

    head.next = removeLinkedListElements3(head.next, val);

    if (head.val === val) {
        return head.next;
    } else {
        return head;
    }
};

