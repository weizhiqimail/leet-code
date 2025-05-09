const reverseList1 = head => {
    if (!head || !head.next) {
        return head;
    }
    let prev = null, curr = head;
    while (curr) {
        let next = curr.next;
        curr.next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
};

const reverseList2 = head => {
    if (!head || !head.next) {
        return head;
    }

    head = reverse(null, head);
    return head;


    function reverse(prev, curr) {
        if (!curr) {
            return prev;
        }
        let next = curr.next;
        curr.next = prev;
        return reverse(curr, next);
    }
};

