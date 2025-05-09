/*
* 普通队列
* */

class Queue {

    constructor(capacity = 10) {
        this._items = [];
        this._capacity = capacity;
    }

    get capacity() {
        return this._capacity;
    }

    get size() {
        return this._items.length;
    }

    isFull() {
        return this.size === this.capacity;
    }

    isEmpty() {
        return this.size === 0;
    }

    enqueue(e) {
        if (this.isFull()) {
            return false;
        }
        return this._items.push(e);
    }

    dequeue() {
        return this._items.unshift();
    }


    clear() {
        if (!this.isEmpty()) {
            this._items = [];
        }
        return true;
    }

    traverse() {
        return this._items;
    }
}