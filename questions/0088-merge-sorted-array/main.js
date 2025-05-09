const mergeTwoArray = (nums1, m, nums2, n) => {
    let i1 = m - 1;
    let i2 = n - 1;
    let tail = m + n - 1;
    while (i2 >= 0) {
        if (nums1[i1] > nums2[i2]) {
            nums1[tail] = nums1[i1];
            i1--;
        } else {
            nums1[tail] = nums2[i2];
            i2--;
        }
        tail--;
    }
};


let nums1 = [1, 2, 8];
let nums2 = [2, 4, 6];
let m = 3;
let n = 3;
mergeTwoArray(nums1, m, nums2, n);
console.log(nums1);