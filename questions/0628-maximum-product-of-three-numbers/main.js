// 数组排序，全部是正数，那就最后的三个数相乘。如果有负数，那就是两个最小负数的乘积和最大值的成绩
function maximumProduct01(nums) {
    nums.sort((a, b) => a - b);

    const len = nums.length;
    return Math.max(
        nums[0] * nums[1] * nums[len - 1],
        nums[len - 1] * nums[len - 2] * nums[len - 3]
    );
}

// 线性扫描，找到两个最小值，和三个最大值
function maximumProduct02(nums) {
    let [max1, max2, max3] = [-Infinity, -Infinity, -Infinity];
    let [min1, min2] = [Infinity, Infinity];
    for (const num of nums) {
        if (num < min1) {
            [min2, min1] = [min1, num];
        } else if (num > min2) {
            min2 = num;
        }
        if (num > max1) {
            [max3, max2, max1] = [max2, max1, num];
        } else if (num > max2) {
            [max3, max2] = [max2, num];
        } else if (num > max3) {
            max3 = num;
        }
    }
    return Math.max(min1 * min2 * max1, max1 * max2 * max3);
}
