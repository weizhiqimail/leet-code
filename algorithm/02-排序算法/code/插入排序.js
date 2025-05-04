
let str = "";

function insertionSort(arr) {
  for (let i = 1; i < arr.length; i++) {
    let key = arr[i];
    let j = i - 1;
    str += `i = ${i} \t j = ${j} \t  key = ${key} \t arr: [${arr.toString()}]\n`;

    // 移动大于 key 的元素到右边
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      str += `i = ${i} \t j = ${j} \t  key = ${key} \t arr: [${arr.toString()}]\n`;
      j--;
    }

    arr[j + 1] = key;
  }
}

// 测试
let arr = [64, 34, 25, 12, 22, 11, 90];
insertionSort(arr);
console.log("Sorted array:", arr);
console.log(str);