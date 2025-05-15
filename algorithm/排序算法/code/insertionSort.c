#include <stdio.h>
#include <tgmath.h>
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

void insertionSort(int arr[], int len) {
  for (int i = 1; i < len; i++) {
    int key = arr[i];
    int j = i - 1;

    printf("\n========== 外层第 %d 次插入 (i = %d) ==========\n", i, i);
    printf("要插入的元素：key = arr[%d] = %d\n", i, key);
    printArr(arr, len);

    while (j >= 0 && arr[j] > key) {
      printf("内层 arr[%d] = %d > key = %d，移动 arr[%d] 到 arr[%d]\n", j,
             arr[j], key, j, j + 1);
      arr[j + 1] = arr[j];
      printArr(arr, len);
      j--;
      printf("内层 j 减 1 后：j = %d\n", j);
    }

    arr[j + 1] = key;
    printf("插入 key = %d 到位置 arr[%d]\n", key, j + 1);
    printArr(arr, len);

    printf("========== 外层第 %d 次插入结束 ==========\n", i);
  }
}

void insertionSort2(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}


int main() {
  // 设置控制台输出为 UTF-8
  SetConsoleOutputCP(CP_UTF8);


  int arr[] = {64, 34, 25, 12, 22, 11, 90};
  int len = sizeof(arr) / sizeof(arr[0]);

  printf("原始数组：\n");
  printArr(arr, len);

  insertionSort(arr, len);

  printf("\n排序后数组：\n");
  printArr(arr, len);

  return 0;
}

/**
原始数组：
当前数组：64 34 25 12 22 11 90

========== 外层第 1 次插入 (i = 1) ==========
要插入的元素：key = arr[1] = 34
当前数组：64 34 25 12 22 11 90
内层 arr[0] = 64 > key = 34，移动 arr[0] 到 arr[1]
当前数组：64 64 25 12 22 11 90
内层 j 减 1 后：j = -1
插入 key = 34 到位置 arr[0]
当前数组：34 64 25 12 22 11 90
========== 外层第 1 次插入结束 ==========

========== 外层第 2 次插入 (i = 2) ==========
要插入的元素：key = arr[2] = 25
当前数组：34 64 25 12 22 11 90
内层 arr[1] = 64 > key = 25，移动 arr[1] 到 arr[2]
当前数组：34 64 64 12 22 11 90
内层 j 减 1 后：j = 0
内层 arr[0] = 34 > key = 25，移动 arr[0] 到 arr[1]
当前数组：34 34 64 12 22 11 90
内层 j 减 1 后：j = -1
插入 key = 25 到位置 arr[0]
当前数组：25 34 64 12 22 11 90
========== 外层第 2 次插入结束 ==========

========== 外层第 3 次插入 (i = 3) ==========
要插入的元素：key = arr[3] = 12
当前数组：25 34 64 12 22 11 90
内层 arr[2] = 64 > key = 12，移动 arr[2] 到 arr[3]
当前数组：25 34 64 64 22 11 90
内层 j 减 1 后：j = 1
内层 arr[1] = 34 > key = 12，移动 arr[1] 到 arr[2]
当前数组：25 34 34 64 22 11 90
内层 j 减 1 后：j = 0
内层 arr[0] = 25 > key = 12，移动 arr[0] 到 arr[1]
当前数组：25 25 34 64 22 11 90
内层 j 减 1 后：j = -1
插入 key = 12 到位置 arr[0]
当前数组：12 25 34 64 22 11 90
========== 外层第 3 次插入结束 ==========

========== 外层第 4 次插入 (i = 4) ==========
要插入的元素：key = arr[4] = 22
当前数组：12 25 34 64 22 11 90
内层 arr[3] = 64 > key = 22，移动 arr[3] 到 arr[4]
当前数组：12 25 34 64 64 11 90
内层 j 减 1 后：j = 2
内层 arr[2] = 34 > key = 22，移动 arr[2] 到 arr[3]
当前数组：12 25 34 34 64 11 90
内层 j 减 1 后：j = 1
内层 arr[1] = 25 > key = 22，移动 arr[1] 到 arr[2]
当前数组：12 25 25 34 64 11 90
内层 j 减 1 后：j = 0
插入 key = 22 到位置 arr[1]
当前数组：12 22 25 34 64 11 90
========== 外层第 4 次插入结束 ==========

========== 外层第 5 次插入 (i = 5) ==========
要插入的元素：key = arr[5] = 11
当前数组：12 22 25 34 64 11 90
内层 arr[4] = 64 > key = 11，移动 arr[4] 到 arr[5]
当前数组：12 22 25 34 64 64 90
内层 j 减 1 后：j = 3
内层 arr[3] = 34 > key = 11，移动 arr[3] 到 arr[4]
当前数组：12 22 25 34 34 64 90
内层 j 减 1 后：j = 2
内层 arr[2] = 25 > key = 11，移动 arr[2] 到 arr[3]
当前数组：12 22 25 25 34 64 90
内层 j 减 1 后：j = 1
内层 arr[1] = 22 > key = 11，移动 arr[1] 到 arr[2]
当前数组：12 22 22 25 34 64 90
内层 j 减 1 后：j = 0
内层 arr[0] = 12 > key = 11，移动 arr[0] 到 arr[1]
当前数组：12 12 22 25 34 64 90
内层 j 减 1 后：j = -1
插入 key = 11 到位置 arr[0]
当前数组：11 12 22 25 34 64 90
========== 外层第 5 次插入结束 ==========

========== 外层第 6 次插入 (i = 6) ==========
要插入的元素：key = arr[6] = 90
当前数组：11 12 22 25 34 64 90
插入 key = 90 到位置 arr[6]
当前数组：11 12 22 25 34 64 90
========== 外层第 6 次插入结束 ==========

排序后数组：
当前数组：11 12 22 25 34 64 90
*/