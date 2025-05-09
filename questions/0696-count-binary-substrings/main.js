// 输入： "00110011"
// 输出： “0011”，“01”，“1100”，“10”，“0011” 和 “01”。
const countBinarySubstrings = s => {
    let arr = s.replace(/10/g, '1 0').replace(/01/g, '0 1').split(/\s/);
    console.log(arr);
    let n = 0;
    for (let i = 0; i < arr.length - 1; i++) {
        console.log(arr[i].length, arr[i + 1].length);
        n += Math.min(arr[i].length, arr[i + 1].length);
    }
    return n;
};


console.log(countBinarySubstrings("110000110011"));
