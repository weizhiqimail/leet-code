// 时间：80 ms  内存：32.3 MB
const letterCombinations1 = digits => {
    let map = ['', 1, 'abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];
    if (!digits) {
        return [];
    }
    let num = digits.split('');  // ['2', '3', '4'];
    if (digits.length === 1) {
        return map[digits].split('');
    }
    let code = [];  // 保留键盘映射后的内容 23=>['abc', 'def'];

    num.forEach(item => {
        item = parseInt(item, 10);
        if (map[item]) {
            code.push(map[item]);
        }
    });

    function compose(arr) {
        let temp = [];
        let item0 = arr[0];
        let item1 = arr[1];
        if (item1) {
            for (let i = 0; i < item0.length; i++) {
                for (let j = 0; j < item1.length; j++) {
                    temp.push(`${arr[0][i]}${arr[1][j]}`);
                }
            }
        }

        arr.splice(0, 2, temp);
        if (arr.length > 1) {
            return compose(arr);
        }
        return arr[0];
    }

    return compose(code);
};

// 时间：80 ms  内存：32.3 MB
const letterCombinations2 = digits => {
    const NUM_TO_LETTER = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z']
    };

    if (digits.length === 0) {
        return [];
    }
    if (digits.length === 1) {
        return NUM_TO_LETTER[digits];
    }

    let codeArr = [];
    for (let digit of digits) {
        codeArr.push(NUM_TO_LETTER[digit]);
    }
    return codeArr.reduce((prev, curr) => {
        let temp = [];
        prev.map(item => curr.map(item1 => temp.push(item + item1)));
        return temp;
    });

};
