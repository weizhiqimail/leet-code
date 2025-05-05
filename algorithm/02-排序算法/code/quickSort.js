let arr = [64, 34, 25, 12, 22, 11, 90];
let log = [];

function quickSort(arr, low, high, depth = 0) {
  if (low < high) {
    log.push('');
    log.push(`${'  '.repeat(depth)}快速排序调用\tlow=${low}\thigh=${high}`);
    let pi = partition(arr, low, high, depth);
    log.push(`${'  '.repeat(depth)}分区结束\t索引=${pi}`);
    log.push(`${'  '.repeat(depth)}当前数组\t[${arr}]`);
    log.push(`${'  '.repeat(depth)}------------------------------`);
    quickSort(arr, low, pi - 1, depth + 1);
    quickSort(arr, pi + 1, high, depth + 1);
  }
}

function partition(arr, low, high, depth) {
  let pivot = arr[high];
  log.push(`${'  '.repeat(depth)}开始分区\tlow=${low}\thigh=${high}\tpivot=${pivot}`);
  log.push('');

  let i = low - 1;

  for (let j = low; j < high; j++) {
    log.push(`${'  '.repeat(depth)}状态 (for)\t i=${i}\tj=${j}\tlow=${low}\thigh=${high}`);
    log.push(`${'  '.repeat(depth)}比较\tarr[${j}]=${arr[j]} <= pivot(${pivot}) → ${arr[j] <= pivot}`);
    if (arr[j] <= pivot) {
      i++;
      log.push(`${'  '.repeat(depth)}状态 (if)\t i=${i}\tj=${j}\tlow=${low}\thigh=${high}`);
      [arr[i], arr[j]] = [arr[j], arr[i]];
      log.push(`${'  '.repeat(depth)}交换 arr[${i}] 和 arr[${j}] → [${arr}]`);
    }
  }

  [arr[i + 1], arr[high]] = [arr[high], arr[i + 1]];
  log.push('');
  log.push(`${'  '.repeat(depth)}放置基准\t交换 arr[${i + 1}] 和 arr[${high}]\t→ [${arr}]`);
  log.push(`${'  '.repeat(depth)}最终位置\ti=${i + 1}\tlow=${low}\thigh=${high}`);
  return i + 1;
}

// 执行排序
quickSort(arr, 0, arr.length - 1);

// 输出
console.log("排序后的数组:", arr);
console.log("详细排序过程:\n" + log.join('\n'));
