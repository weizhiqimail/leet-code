/*
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围[−(2 ** 31), 2 ** 31 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***/

// 倒序遍历字符串，拼接字符串转成数字
/**
 * @param {number} num
 * @return {number}
 */
function reverseInteger1(num) {
    let isMinus = false;
    if (num < 0) {
        isMinus = true;
    }

    num = Math.abs(num);
    let result = '';
    const numStr = String(num);
    for (let i = numStr.length - 1; i >= 0; i--) {
        result += numStr[i];
    }
    result = Number(result);
    result = isMinus ? -result : result;
    if (result > ((2 ** 31) - 1) || result < -(2 ** 31)) {
        return 0;
    }
    return result;
}

// 数字不断除以 10 取余，得到的结果乘 10 再加上余数
/**
 * @param {number} num
 * @return {number}
 */
function reverseInteger2(num) {
    let result = 0;
    const MAX_VALUE = Math.pow(2, 31) - 1;
    const MIN_VALUE = -Math.pow(2, 31);

    while (num !== 0) {
        let pop = num % 10;
        result = result * 10 + pop;
        num = parseInt(num / 10);
    }
    if (result > MAX_VALUE || result < MIN_VALUE) {
        return 0;
    }
    return result;
}

module.exports = {
    reverseInteger1,
    reverseInteger2,
};
