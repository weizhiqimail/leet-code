/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那两个整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***/

// 双重暴力循环
/**
 * @param {Array<number>} nums
 * @param {number} target
 * @return {Array<number>}
 */
function twoSum1(nums, target) {
    const result = [];
    for (let i = 0; i < nums.length; i++) {
        for (let j = i + 1; j < nums.length; j++) {
            if (nums[i] + nums[j] === target) {
                result.push(i);
                result.push(j);
                break;
            }
        }
    }
    return result;
}

// 哈希表，空间换时间
/**
 * @param {Array<number>} nums
 * @param {number} target
 * @return {Array<number>}
 */
function twoSum2(nums, target) {
    const obj = {};
    for (let i = 0; i < nums.length; i++) {
        const diff = target - nums[i];
        if (obj[diff] >= 0) {
            return [obj[diff], i];
        }
        obj[nums[i]] = i;
    }
    return [];
}

module.exports = {
    twoSum1,
    twoSum2,
};
