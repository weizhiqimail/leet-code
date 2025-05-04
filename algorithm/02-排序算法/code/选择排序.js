
let str = "";

function selectionSort(arr) {
  for (let i = 0; i < arr.length - 1; i++) {
    let minIndex = i;

    // 从 i+1 到 arr.length 查找最小元素
    for (let j = i + 1; j < arr.length; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
        str += `i = ${i} \t minIndex = ${minIndex} \t arr: [${arr.toString()}]\n`;
      }
    }

    // 交换最小元素和当前元素
    if (minIndex !== i) {
      let temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
      str += `i = ${i} \t minIndex = ${minIndex} \t arr: [${arr.toString()}]\n`;
    }
  }
}

// 测试
let arr = [64, 34, 25, 12, 22, 11, 90];
selectionSort(arr);
console.log("Sorted array:", arr);
console.log(str);