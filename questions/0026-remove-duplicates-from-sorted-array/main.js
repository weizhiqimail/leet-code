const removeDuplicates1 = nums => {
    if (!nums && nums.length === 0) {
        return 0;
    }

    for (let i = nums.length; i > 0; i--) {
        if (nums[i] === nums[i - 1]) {
            nums.splice(i, 1);
        }
    }

    return nums.length;
};

const removeDuplicates2 = nums => {
    if (!nums && nums.length === 0) {
        return 0;
    }

    let i = 0;
    for (let j = 1; j < nums.length; j++) {
        if (nums[j] !== nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
};

let nums = [1, 1, 2];

console.log(removeDuplicates2(nums));
