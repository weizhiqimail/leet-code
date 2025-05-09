class ListNode {
    constructor(val) {
        this.val = val;
        this.next = null;
    }
}

const mergeTwoLists1 = (l1, l2) => {
    if (!l1) {
        return l2;
    }
    if (!l2) {
        return l1;
    }

    if (l1.val < l2.val) {
        l1.next = mergeTwoLists1(l1.next, l2);
        return l1;
    } else {
        l2.next = mergeTwoLists1(l2.next, l1);
        return l2;
    }
};


const mergeTwoLists2 = (l1, l2) => {
    const preHead = new ListNode(-1);

    let prev = preHead;

    while (l1 !== null && l2 !== null) {
        if (l1.value <= l2.value) {
            prev.next = l1;
            l1 = l1.next;
        } else {
            prev.next = l2;
            l2 = l2.next;
        }
        prev = prev.next;
    }
    prev.next = l1 === null ? l2 : l1;
    return preHead.next;
};



