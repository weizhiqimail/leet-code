let str = "";

function bubbleSort(arr) {
  for (let i = 0; i < arr.length - 1; i++) {
    let swapped = false;

    // 每次遍历未排序部分的数组
    for (let j = 0; j < arr.length - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        // 交换相邻元素
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        str += `i = ${i} \t j = ${j} \t arr: [${arr.toString()}]\n`;
        swapped = true;
      }
    }

    // 如果没有发生交换，说明数组已经有序，可以提前终止
    if (!swapped) break;
  }
}

// 测试
let arr = [64, 34, 25, 12, 22, 11, 90];
bubbleSort(arr);
console.log("Sorted array:", arr);
console.log(str);