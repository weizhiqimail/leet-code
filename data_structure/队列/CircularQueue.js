class CircularQueue {
    constructor(size = 10) {
        this._size = size;
        this._data = Array.from({length: size + 1});
        this._front = 0;
        this._tail = 0;
    }

    get capacity() {
        return this._data.length - 1;
    }

    get size() {
        return this._size;
    }

    isEmpty() {
        return this._front === this._tail;
    }

    isFull() {
        return (this._tail + 1) % this._data.length === this._front;
    }

    enqueue(element) {
        if (this.isFull()) {
            return null;
        }

        this._data[this._tail] = element;
        this._tail = (this._tail + 1) % this._data.length;
    }

    dequeue() {
        if (this.isEmpty()) {
            return null;
        }

        const result = this._data[this._front];
        this._data[this._front] = null;
        this._front = (this._front + 1) % this._data.length;
        return result;
    }

    traverse() {
        const result = [];
        for (let i = this._front; i !== this._tail; i = (i + 1) % this._data.length) {
            result.push(this._data[i]);
        }
        return result;
    }


}