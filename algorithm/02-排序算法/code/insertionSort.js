let log = [];

function insertionSort(arr) {
  for (let i = 1; i < arr.length; i++) {
    let key = arr[i];
    let j = i - 1;

    log.push(`--- 第 ${i} 次插入 ---`);
    log.push(`插入前数组: [${arr.toString()}]`);
    log.push(`当前 key = arr[${i}] = ${key}`);

    // 移动大于 key 的元素到右边
    while (j >= 0 && arr[j] > key) {
      log.push(`比较: arr[${j}] = ${arr[j]} > key = ${key} → 移动 arr[${j}] 到 arr[${j + 1}]`);
      arr[j + 1] = arr[j];
      j--;
      log.push(`当前数组: [${arr.toString()}]`);
    }

    arr[j + 1] = key;
    log.push(`将 key = ${key} 插入到位置 ${j + 1}`);
    log.push(`插入后数组: [${arr.toString()}]`);
    log.push(`-------------------------\n`);
  }
}

// 测试
let arr = [64, 34, 25, 12, 22, 11, 90];
insertionSort(arr);

console.log("Sorted array:", arr);
console.log("详细排序过程:\n\n" + log.join("\n"));
