const plusOne = digits => {
    const len = digits.length;

    for (let i = len - 1; i >= 0; i--) {
        digits[i]++;
        digits[i] %= 10;
        if (digits[i] !== 0) {
            return digits;
        }
    }
    digits = [...Array(len + 1)].map(() => 0);
    digits[0] = 1;
    return digits;
};

console.log(plusOne([1, 2, 3]));
console.log(plusOne([9]));
// console.log(plusOne([1, 9, 9]));



