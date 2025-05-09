// 使用 set 数据结构
const intersection01 = (nums1, nums2) => {
    const set1 = new Set(nums1);
    const res = new Set();

    for (let i = 0; i < nums2.length; i++) {
        const item = nums2[i];
        if (set1.has(item)) {
            res.add(item);
        }
    }

    return Array.from(res);
};

// 使用数组 includes
function intersection02(nums1, nums2) {
    let arr = [];
    nums1.forEach((v) => nums2.includes(v) && !arr.includes(v) && arr.push(v));
    return arr;
}
