#include <stdio.h>
#include <windows.h>


void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArr(int arr[], int n) {
  printf("当前数组：");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void bubbleSort(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    printf("\n========== 外层第 %d 次遍历开始 (i = %d) ==========\n", i + 1, i);

    int swapped = 0;

    for (int j = 0; j < len - i - 1; j++) {
      printf("\n-- 内层第 %d 次比较开始 (i = %d, j = %d) --\n", j + 1, i, j);

      // 显示当前数组状态
      printArr(arr, len);

      printf("比较：arr[%d] = %d 和 arr[%d] = %d\n", j, arr[j], j + 1,
             arr[j + 1]);

      if (arr[j] > arr[j + 1]) {
        printf("=> 条件满足：%d > %d，执行交换\n", arr[j], arr[j + 1]);
        swap(&arr[j], &arr[j + 1]);

        printf(">> 交换后数组：\n");
        printArr(arr, len);

        swapped = 1;
      } else {
        printf("=> 条件不满足：%d <= %d，不交换\n", arr[j], arr[j + 1]);
      }
    }

    printf("\n>> 内层遍历结束 (i = %d)\n", i);
    printArr(arr, len);

    if (!swapped) {
      printf("\n※ 本轮未发生任何交换，数组已有序，提前结束排序\n");
      break;
    }

    printf("========== 外层第 %d 次遍历结束 ==========\n", i + 1);
  }
}

int main() {
  // 设置控制台输出为 UTF-8
  SetConsoleOutputCP(CP_UTF8);


  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组：\n");
  printArr(arr, len);

  bubbleSort(arr, len);

  printf("\n排序后数组：\n");
  printArr(arr, len);

  return 0;
}

/**
原始数组：
当前数组：64 34 25 12 22 11 90

========== 外层第 1 次遍历开始 (i = 0) ==========

-- 内层第 1 次比较开始 (i = 0, j = 0) --
当前数组：64 34 25 12 22 11 90
比较：arr[0] = 64 和 arr[1] = 34
=> 条件满足：64 > 34，执行交换
>> 交换后数组：
当前数组：34 64 25 12 22 11 90

-- 内层第 2 次比较开始 (i = 0, j = 1) --
当前数组：34 64 25 12 22 11 90
比较：arr[1] = 64 和 arr[2] = 25
=> 条件满足：64 > 25，执行交换
>> 交换后数组：
当前数组：34 25 64 12 22 11 90

-- 内层第 3 次比较开始 (i = 0, j = 2) --
当前数组：34 25 64 12 22 11 90
比较：arr[2] = 64 和 arr[3] = 12
=> 条件满足：64 > 12，执行交换
>> 交换后数组：
当前数组：34 25 12 64 22 11 90

-- 内层第 4 次比较开始 (i = 0, j = 3) --
当前数组：34 25 12 64 22 11 90
比较：arr[3] = 64 和 arr[4] = 22
=> 条件满足：64 > 22，执行交换
>> 交换后数组：
当前数组：34 25 12 22 64 11 90

-- 内层第 5 次比较开始 (i = 0, j = 4) --
当前数组：34 25 12 22 64 11 90
比较：arr[4] = 64 和 arr[5] = 11
=> 条件满足：64 > 11，执行交换
>> 交换后数组：
当前数组：34 25 12 22 11 64 90

-- 内层第 6 次比较开始 (i = 0, j = 5) --
当前数组：34 25 12 22 11 64 90
比较：arr[5] = 64 和 arr[6] = 90
=> 条件不满足：64 <= 90，不交换

>> 内层遍历结束 (i = 0)
当前数组：34 25 12 22 11 64 90
========== 外层第 1 次遍历结束 ==========

========== 外层第 2 次遍历开始 (i = 1) ==========

-- 内层第 1 次比较开始 (i = 1, j = 0) --
当前数组：34 25 12 22 11 64 90
比较：arr[0] = 34 和 arr[1] = 25
=> 条件满足：34 > 25，执行交换
>> 交换后数组：
当前数组：25 34 12 22 11 64 90

-- 内层第 2 次比较开始 (i = 1, j = 1) --
当前数组：25 34 12 22 11 64 90
比较：arr[1] = 34 和 arr[2] = 12
=> 条件满足：34 > 12，执行交换
>> 交换后数组：
当前数组：25 12 34 22 11 64 90

-- 内层第 3 次比较开始 (i = 1, j = 2) --
当前数组：25 12 34 22 11 64 90
比较：arr[2] = 34 和 arr[3] = 22
=> 条件满足：34 > 22，执行交换
>> 交换后数组：
当前数组：25 12 22 34 11 64 90

-- 内层第 4 次比较开始 (i = 1, j = 3) --
当前数组：25 12 22 34 11 64 90
比较：arr[3] = 34 和 arr[4] = 11
=> 条件满足：34 > 11，执行交换
>> 交换后数组：
当前数组：25 12 22 11 34 64 90

-- 内层第 5 次比较开始 (i = 1, j = 4) --
当前数组：25 12 22 11 34 64 90
比较：arr[4] = 34 和 arr[5] = 64
=> 条件不满足：34 <= 64，不交换

>> 内层遍历结束 (i = 1)
当前数组：25 12 22 11 34 64 90
========== 外层第 2 次遍历结束 ==========

========== 外层第 3 次遍历开始 (i = 2) ==========

-- 内层第 1 次比较开始 (i = 2, j = 0) --
当前数组：25 12 22 11 34 64 90
比较：arr[0] = 25 和 arr[1] = 12
=> 条件满足：25 > 12，执行交换
>> 交换后数组：
当前数组：12 25 22 11 34 64 90

-- 内层第 2 次比较开始 (i = 2, j = 1) --
当前数组：12 25 22 11 34 64 90
比较：arr[1] = 25 和 arr[2] = 22
=> 条件满足：25 > 22，执行交换
>> 交换后数组：
当前数组：12 22 25 11 34 64 90

-- 内层第 3 次比较开始 (i = 2, j = 2) --
当前数组：12 22 25 11 34 64 90
比较：arr[2] = 25 和 arr[3] = 11
=> 条件满足：25 > 11，执行交换
>> 交换后数组：
当前数组：12 22 11 25 34 64 90

-- 内层第 4 次比较开始 (i = 2, j = 3) --
当前数组：12 22 11 25 34 64 90
比较：arr[3] = 25 和 arr[4] = 34
=> 条件不满足：25 <= 34，不交换

>> 内层遍历结束 (i = 2)
当前数组：12 22 11 25 34 64 90
========== 外层第 3 次遍历结束 ==========

========== 外层第 4 次遍历开始 (i = 3) ==========

-- 内层第 1 次比较开始 (i = 3, j = 0) --
当前数组：12 22 11 25 34 64 90
比较：arr[0] = 12 和 arr[1] = 22
=> 条件不满足：12 <= 22，不交换

-- 内层第 2 次比较开始 (i = 3, j = 1) --
当前数组：12 22 11 25 34 64 90
比较：arr[1] = 22 和 arr[2] = 11
=> 条件满足：22 > 11，执行交换
>> 交换后数组：
当前数组：12 11 22 25 34 64 90

-- 内层第 3 次比较开始 (i = 3, j = 2) --
当前数组：12 11 22 25 34 64 90
比较：arr[2] = 22 和 arr[3] = 25
=> 条件不满足：22 <= 25，不交换

>> 内层遍历结束 (i = 3)
当前数组：12 11 22 25 34 64 90
========== 外层第 4 次遍历结束 ==========

========== 外层第 5 次遍历开始 (i = 4) ==========

-- 内层第 1 次比较开始 (i = 4, j = 0) --
当前数组：12 11 22 25 34 64 90
比较：arr[0] = 12 和 arr[1] = 11
=> 条件满足：12 > 11，执行交换
>> 交换后数组：
当前数组：11 12 22 25 34 64 90

-- 内层第 2 次比较开始 (i = 4, j = 1) --
当前数组：11 12 22 25 34 64 90
比较：arr[1] = 12 和 arr[2] = 22
=> 条件不满足：12 <= 22，不交换

>> 内层遍历结束 (i = 4)
当前数组：11 12 22 25 34 64 90
========== 外层第 5 次遍历结束 ==========

========== 外层第 6 次遍历开始 (i = 5) ==========

-- 内层第 1 次比较开始 (i = 5, j = 0) --
当前数组：11 12 22 25 34 64 90
比较：arr[0] = 11 和 arr[1] = 12
=> 条件不满足：11 <= 12，不交换

>> 内层遍历结束 (i = 5)
当前数组：11 12 22 25 34 64 90

※ 本轮未发生任何交换，数组已有序，提前结束排序

排序后数组：
当前数组：11 12 22 25 34 64 90

 */
