/*
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。例如，121 是回文，而 123 不是。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***/

// 使用字符串拆分反转
/**
 * @param {number} num
 * @return {boolean}
 */
function palindromeNumber1(num) {
    const str = num.toString().split('').reverse().join('');
    return num.toString() === str;
}

// 从字符串的第n个和倒数第n个不断比较，如果都相等，那么就是回文。
/**
 * @param {number} num
 * @return {boolean}
 */
function palindromeNumber2(num) {
    if (num < 0) {
        return false;
    }

    const str = num.toString();

    for (let i = 0; i < str.length / 2; i++) {
        if (str[i] !== str[str.length - 1 - i]) {
            return false;
        }
    }

    return true;
}

// 数字除以 10 取余，新数字乘 10 加余数，最终两个数字相等，就是回文
/**
 * @param {number} num
 * @return {boolean}
 */
function palindromeNumber3(num) {
    if (num < 0) {
        return false;
    }

    const original = num;
    let reverse = 0;
    while (num > 0) {
        reverse = reverse * 10 + num % 10;
        num = Math.floor(num / 10);
    }
    return original === reverse;
}

module.exports = {
    palindromeNumber1,
    palindromeNumber2,
    palindromeNumber3,
};

