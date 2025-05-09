// 时间：88 ms  内存：36.2 MB
const moveZeroes01 = nums => {
    let j = 0;

    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            nums[j] = nums[i];
            if (i !== j) {
                nums[i] = 0;
            }
            j++;
        }
    }
    return nums;
};

// 时间：64 ms  空间：37.4 MB
// 把所有的非零项移动到数组的前边，记录最后一个非零项的索引。然后从非零项的索引开始，把后边所有项的值都置为 0
const moveZeroes02 = nums => {
    let index = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            nums[index] = nums[i];
            index++;
        }
    }
    for (let i = index; i < nums.length; i++) {
        nums[i] = 0;
    }
    return nums;
};

const moveZeroes03 = nums => {
    let i = 0, j = 0;
    for (; i < nums.length; i++) {
        if (nums[i] !== 0) {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            j++;
        }
    }
    return nums;
};

// 时间复杂度为 O(n^2)，最好不要使用
const removeZeroes04 = nums => {
    for (let i = nums.length; i >= 0; i--) {
        if (nums[i] === 0) {
            nums.splice(i, 1);
            nums.push(0);
        }
    }
    return nums;
};

console.log(removeZeroes04([1, 4, 0, 0, 6, 0]));