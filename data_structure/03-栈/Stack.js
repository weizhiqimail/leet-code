class Stack {

    constructor(capacity = 10) {
        this._data = [];
        this._capacity = capacity;
    }

    get size() {
        return this._data.length;
    }

    get capacity() {
        return this._capacity;
    }

    isFull() {
        return this.size === this.capacity;
    }

    isEmpty() {
        return this.size === 0;
    }

    push(e) {
        if (this.isFull()) {
            return null;
        }
        this._data.push(e);
    }

    pop() {
        if (this.isEmpty()) {
            return null;
        }
        let res = this._data[this.size - 1];
        this._data.splice(this.size - 1, 1);
        return res;
    }

}

function matchBracket(str) {
    const stack = new Stack(100);

    for (let i = 0; i < str.length; i++) {
        const alpha = str[i];
        const pop = stack.pop();
        console.log('pop', pop);
        switch (alpha) {
        case ')':
            if (pop!== '(') {
                return false;
            }
            break;
        case ']':
            if (pop !== '[') {
                return false;
            }
            break;
        case '}':
            if (pop !== '{') {
                return false;
            }
            break;
        default:
            stack.push(alpha);
        }
    }

    return stack.isEmpty();

}

console.log(matchBracket('[][][]'));
console.log(matchBracket('()())'));
