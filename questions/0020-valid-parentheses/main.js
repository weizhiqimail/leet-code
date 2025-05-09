class Stack {

    constructor() {
        this._data = [];
    }

    push(e) {
        this._data.push(e);
    }

    pop() {
        const value = this._data[this._data.length - 1];
        this._data.splice(this._data.length - 1, 1);
        return value;
    }

    peek() {
        return this._data[this._data.length - 1];
    }

    isEmpty() {
        return this._data.length === 0;
    }

}

const isValidParentheses = s => {
    const stack = new Stack();
    if (s.length % 2 !== 0) {
        return false;
    }

    for (let i = 0; i < s.length; i++) {
        const c = s[i];
        if (c === '(' || c === '[' || c === '{') {
            stack.push(s[i]);
        } else {
            if (stack.isEmpty()) {
                return false;
            }
            const top = stack.pop();

            if (c === ')' && top !== '(') {
                return false;
            } else if (c === ']' && top !== '[') {
                return false;
            } else if (c === '}' && top !== '{') {
                return false;
            }

        }
    }

    return stack.isEmpty();
};

console.log(isValidParentheses('[{}]'));
// console.log(isValidParentheses('()()'));
// console.log(isValidParentheses('()()['));
// console.log(isValidParentheses('(]'));

