
let str = "";

function selectionSort(arr) {
  for (let i = 0; i < arr.length - 1; i++) {
    let minIndex = i;
    str += `--- 第 ${i + 1} 轮开始 ---\n`;
    str += `初始最小值: arr[${minIndex}] = ${arr[minIndex]}\n`;

    // 找出当前位置后面最小的元素
    for (let j = i + 1; j < arr.length; j++) {
      str += `比较: arr[${j}] = ${arr[j]} 和 arr[${minIndex}] = ${arr[minIndex]}`;
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
        str += ` → 更新最小值索引为 ${minIndex}\n`;
      } else {
        str += ` → 保持不变\n`;
      }
    }

    // 交换最小值和当前位置元素
    if (minIndex !== i) {
      let temp = arr[i];
      arr[i] = arr[minIndex];
      arr[minIndex] = temp;
      str += `交换 arr[${i}] 和 arr[${minIndex}] → arr: [${arr.toString()}]\n`;
    } else {
      str += `当前位置已经是最小值，无需交换。\n`;
    }

    str += `--- 第 ${i + 1} 轮结束，数组: [${arr.toString()}] ---\n\n`;
  }
}

// 测试
let arr = [64, 34, 25, 12, 22, 11, 90];
selectionSort(arr);
console.log("Sorted array:", arr);
console.log(str);