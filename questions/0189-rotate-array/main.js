const rotateArray1 = (nums, k) => {
    for (let i = 0; i < k; i++) {
        let previous = nums[nums.length - 1];
        for (let j = 0; j < nums.length; j++) {
            let temp = nums[j];
            nums[j] = previous;
            previous = temp;
        }
    }
    return nums;
};

const rotateArray2 = (nums, k) => {
    let arr = [];
    for (let i = 0; i < nums.length; i++) {
        arr[(i + k) % nums.length] = nums[i];
    }
    for (let i = 0; i < nums.length; i++) {
        nums[i] = arr[i];
    }
    return nums;
};

console.log([1, 2, 3, 4, 5, 6, 7].toString());
console.log(rotateArray1([1, 2, 3, 4, 5, 6, 7], 1).toString());
console.log(rotateArray1([1, 2, 3, 4, 5, 6, 7], 2).toString());
console.log(rotateArray1([1, 2, 3, 4, 5, 6, 7], 3).toString());
