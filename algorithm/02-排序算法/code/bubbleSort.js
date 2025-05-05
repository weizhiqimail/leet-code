let str = "";

function bubbleSort(arr) {
  for (let i = 0; i < arr.length - 1; i++) {
    let swapped = false;
    str += `--- 第 ${i + 1} 轮开始 ---\n`;

    for (let j = 0; j < arr.length - i - 1; j++) {
      str += `比较: arr[${j}] = ${arr[j]} 和 arr[${j + 1}] = ${arr[j + 1]}\n`;

      if (arr[j] > arr[j + 1]) {
        let temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = true;
        str += `  发生交换 → arr: [${arr.toString()}]\n`;
      } else {
        str += `  无需交换\n`;
      }
    }

    str += `--- 第 ${i + 1} 轮结束，当前数组: [${arr.toString()}] ---\n\n`;

    if (!swapped) {
      str += `在第 ${i + 1} 轮中未发生交换，数组已经有序，提前结束排序。\n`;
      break;
    }
  }
}

// 测试
let arr = [64, 34, 25, 12, 22, 11, 90];
bubbleSort(arr);
console.log("Sorted array:", arr);
console.log("详细日志输出:\n" + str);
