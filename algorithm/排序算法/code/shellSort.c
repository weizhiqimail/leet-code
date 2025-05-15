#include <stdio.h>
#include <windows.h>


// 打印数组函数，带前缀缩进，用于标识打印来源
void printArr(int arr[], int n, const char *prefix) {
  printf("%s当前数组：", prefix);
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

// 希尔排序函数：对数组进行排序，使用逐步缩小的增量分组插入排序
void shellSortWhile(int arr[], int n) {
  // 初始化 gap 为数组长度的一半，然后不断缩小 gap（直到为 1）
  for (int gap = n / 2; gap > 0; gap = gap / 2) {
    printf("\n==> 当前 gap = %d\n", gap);

    // 从 gap 开始，逐个处理后续元素，进行插入排序
    for (int i = gap; i < n; i++) {
      int temp = arr[i];  // 保存当前待插入的元素
      int j = i;

      printf("  插入元素 arr[%d] = %d，开始向前比较并插入\n", i, temp);

      // 对当前 gap 分组进行插入排序：向前比较并移动元素
      while (j >= gap && arr[j - gap] > temp) {
        printf("    arr[%d] = %d > temp = %d，移动 arr[%d] 到 arr[%d]\n",
               j - gap, arr[j - gap], temp, j - gap, j);
        arr[j] = arr[j - gap];  // 元素后移
        j -= gap;               // 向前跳 gap 个单位
      }

      // 将当前元素插入到正确位置（j 是最终位置）
      if (j != i) {
        printf("  插入 temp = %d 到 arr[%d] 位置\n", temp, j);
        arr[j] = temp;
      } else {
        printf("  无需移动，元素保持在原位 arr[%d] = %d\n", i, temp);
      }

      printArr(arr, n, "");  // 打印当前插入后的数组
    }

    printf("== gap = %d 排序结束 ==\n", gap);
    printArr(arr, n, "");
    printf("-----------------------------------------\n");
  }
}

// 希尔排序函数（带详细日志和缩进）
void shellSort(int arr[], int n) {
  // gap 为每轮分组间的间隔，从 n/2 开始，每轮减半，直到 gap 为 0 停止
  for (int gap = n / 2; gap > 0; gap /= 2) {
    printf("当前 gap = %d\n", gap);

    // 从 gap 开始，依次处理每一个元素
    for (int i = gap; i < n; i++) {
      int temp = arr[i];  // 临时变量保存当前要插入的元素
      int j;

      printf("  处理元素 arr[%d] = %d\n", i, temp);
      printf("  [i = %d, temp = %d, gap = %d]\n", i, temp, gap);
      printArr(arr, n, "    ");

      // 将 arr[i] 插入到其所在分组的正确位置
      // 当 gap = 1 的时候，这里的 for 相当于 for(int j = i; j >= 1; j--)
      // 相当于从索引 i 开始，逐个向前遍历比较
      for (j = i; j >= gap; j -= gap) {
        printf("    比较 arr[%d] = %d 和 temp = %d\n", j - gap, arr[j - gap],
               temp);
        printf("    [i = %d, j = %d, temp = %d, gap = %d]\n", i, j, temp, gap);
        if (arr[j - gap] > temp) {
          arr[j] = arr[j - gap];  // 将大的元素向后移动
          printf("    arr[%d] > temp，移动 arr[%d] 到 arr[%d]\n", j - gap,
                 j - gap, j);
          printArr(arr, n, "      ");
        } else {
          printf("    arr[%d] <= temp，停止移动\n", j - gap);
          break;
        }
      }

      arr[j] = temp;
      printf("  插入 temp = %d 到 arr[%d]\n", temp, j);
      printArr(arr, n, "    ");
      printf("\n");
    }

    printf("完成 gap = %d 的一轮排序\n", gap);
    printf("=============================================\n\n");
  }
}

int main() {
  // 设置控制台输出为 UTF-8
  SetConsoleOutputCP(CP_UTF8);

  // 初始化数组
  int arr[] = {64, 34, 25, 12, 22, 11, 90, 66, 39, 48, 56};
  int len = sizeof(arr) / sizeof(arr[0]);  // 计算数组长度

  printf("原始数组：\n");
  printArr(arr, len, "");

  // 调用希尔排序
  shellSort(arr, len);

  printf("排序后数组：\n");
  printArr(arr, len, "");

  return 0;
}

/**
原始数组：
当前数组：64 34 25 12 22 11 90
当前 gap = 3
  处理元素 arr[3] = 12
  [i = 3, temp = 12, gap = 3]
    当前数组：64 34 25 12 22 11 90
    比较 arr[0] = 64 和 temp = 12
    [i = 3, j = 3, temp = 12, gap = 3]
    arr[0] > temp，移动 arr[0] 到 arr[3]
      当前数组：64 34 25 64 22 11 90
  插入 temp = 12 到 arr[0]
    当前数组：12 34 25 64 22 11 90

  处理元素 arr[4] = 22
  [i = 4, temp = 22, gap = 3]
    当前数组：12 34 25 64 22 11 90
    比较 arr[1] = 34 和 temp = 22
    [i = 4, j = 4, temp = 22, gap = 3]
    arr[1] > temp，移动 arr[1] 到 arr[4]
      当前数组：12 34 25 64 34 11 90
  插入 temp = 22 到 arr[1]
    当前数组：12 22 25 64 34 11 90

  处理元素 arr[5] = 11
  [i = 5, temp = 11, gap = 3]
    当前数组：12 22 25 64 34 11 90
    比较 arr[2] = 25 和 temp = 11
    [i = 5, j = 5, temp = 11, gap = 3]
    arr[2] > temp，移动 arr[2] 到 arr[5]
      当前数组：12 22 25 64 34 25 90
  插入 temp = 11 到 arr[2]
    当前数组：12 22 11 64 34 25 90

  处理元素 arr[6] = 90
  [i = 6, temp = 90, gap = 3]
    当前数组：12 22 11 64 34 25 90
    比较 arr[3] = 64 和 temp = 90
    [i = 6, j = 6, temp = 90, gap = 3]
    arr[3] <= temp，停止移动
  插入 temp = 90 到 arr[6]
    当前数组：12 22 11 64 34 25 90

完成 gap = 3 的一轮排序
=============================================

当前 gap = 1
  处理元素 arr[1] = 22
  [i = 1, temp = 22, gap = 1]
    当前数组：12 22 11 64 34 25 90
    比较 arr[0] = 12 和 temp = 22
    [i = 1, j = 1, temp = 22, gap = 1]
    arr[0] <= temp，停止移动
  插入 temp = 22 到 arr[1]
    当前数组：12 22 11 64 34 25 90

  处理元素 arr[2] = 11
  [i = 2, temp = 11, gap = 1]
    当前数组：12 22 11 64 34 25 90
    比较 arr[1] = 22 和 temp = 11
    [i = 2, j = 2, temp = 11, gap = 1]
    arr[1] > temp，移动 arr[1] 到 arr[2]
      当前数组：12 22 22 64 34 25 90
    比较 arr[0] = 12 和 temp = 11
    [i = 2, j = 1, temp = 11, gap = 1]
    arr[0] > temp，移动 arr[0] 到 arr[1]
      当前数组：12 12 22 64 34 25 90
  插入 temp = 11 到 arr[0]
    当前数组：11 12 22 64 34 25 90

  处理元素 arr[3] = 64
  [i = 3, temp = 64, gap = 1]
    当前数组：11 12 22 64 34 25 90
    比较 arr[2] = 22 和 temp = 64
    [i = 3, j = 3, temp = 64, gap = 1]
    arr[2] <= temp，停止移动
  插入 temp = 64 到 arr[3]
    当前数组：11 12 22 64 34 25 90

  处理元素 arr[4] = 34
  [i = 4, temp = 34, gap = 1]
    当前数组：11 12 22 64 34 25 90
    比较 arr[3] = 64 和 temp = 34
    [i = 4, j = 4, temp = 34, gap = 1]
    arr[3] > temp，移动 arr[3] 到 arr[4]
      当前数组：11 12 22 64 64 25 90
    比较 arr[2] = 22 和 temp = 34
    [i = 4, j = 3, temp = 34, gap = 1]
    arr[2] <= temp，停止移动
  插入 temp = 34 到 arr[3]
    当前数组：11 12 22 34 64 25 90

  处理元素 arr[5] = 25
  [i = 5, temp = 25, gap = 1]
    当前数组：11 12 22 34 64 25 90
    比较 arr[4] = 64 和 temp = 25
    [i = 5, j = 5, temp = 25, gap = 1]
    arr[4] > temp，移动 arr[4] 到 arr[5]
      当前数组：11 12 22 34 64 64 90
    比较 arr[3] = 34 和 temp = 25
    [i = 5, j = 4, temp = 25, gap = 1]
    arr[3] > temp，移动 arr[3] 到 arr[4]
      当前数组：11 12 22 34 34 64 90
    比较 arr[2] = 22 和 temp = 25
    [i = 5, j = 3, temp = 25, gap = 1]
    arr[2] <= temp，停止移动
  插入 temp = 25 到 arr[3]
    当前数组：11 12 22 25 34 64 90

  处理元素 arr[6] = 90
  [i = 6, temp = 90, gap = 1]
    当前数组：11 12 22 25 34 64 90
    比较 arr[5] = 64 和 temp = 90
    [i = 6, j = 6, temp = 90, gap = 1]
    arr[5] <= temp，停止移动
  插入 temp = 90 到 arr[6]
    当前数组：11 12 22 25 34 64 90

完成 gap = 1 的一轮排序
=============================================

排序后数组：
当前数组：11 12 22 25 34 64 90
*/