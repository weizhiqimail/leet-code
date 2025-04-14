/*
* 双端队列
* */

class Deque {
    constructor(capacity) {
        this._items = [];
        this._capacity = capacity;
    }

    get capacity() {
        return this._capacity;
    }

    insertLast(value) {
        if (this.isFull()) {
            return false;
        }
        this._items.push(value);
        return true;
    }

    insertFront(value) {
        if (this.isFull()) {
            return false;
        }
        this._items.unshift(value);
        return true;
    }

    deleteFront() {
        if (this.isEmpty()) {
            return false;
        }
        this._items.shift();
        return true;
    }

    deleteLast() {
        if (this.isEmpty()) {
            return false;
        }
        this._items.pop();
        return true;
    }

    getFront() {
        if (this.isEmpty()) {
            return -1;
        }
        return this._items[0];
    }

    getRear() {
        if (this.isEmpty()) {
            return -1;
        }
        return this._items[this._items.length - 1];
    }

    isEmpty() {
        return this._items.length === 0;
    }

    isFull() {
        return this._items.length === this.capacity;
    }
}
