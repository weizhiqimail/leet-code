// 异或，两个值都是 1 才为 1

function singleNumber(nums) {
    let single = 0;

    for (let i = 0; i < nums.length; i++) {
        single ^= nums[i];
    }

    return single;
}
