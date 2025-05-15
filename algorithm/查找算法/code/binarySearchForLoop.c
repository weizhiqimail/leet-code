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
    printf("%d\t", arr[i]);
  }
  printf("\n");
  printf("数组索引：");
  for (int i = 0; i < n; i++) {
    printf("%d\t", i);
  }
  printf("\n");
  printf("\n");
}

int binarySearchForLoop(int arr[], int len, int target) {
  int low = 0;
  int high = len - 1;
  printf("开始二分查找：target = %d\n", target);

  while (low <= high) {
    int mid = low + (high - low) / 2;
    printf("\n[循环开始] 当前搜索区间：[low = %d, high = %d], 计算中点 mid = %d\n", low, high, mid);
    printf("arr[%d] = %d\n", mid, arr[mid]);

    if (arr[mid] < target) {
      printf("arr[%d] = %d 小于 target = %d，向右半区间继续查找\n", mid, arr[mid], target);
      low = mid + 1;
    } else if (arr[mid] > target) {
      printf("arr[%d] = %d 大于 target = %d，向左半区间继续查找\n", mid, arr[mid], target);
      high = mid - 1;
    } else {
      printf("找到目标元素：arr[%d] = %d，返回索引 %d\n", mid, arr[mid], mid);
      return mid;
    }

    // 循环结束后打印 low/high/mid 的值
    printf("[循环结束] low = %d, high = %d, mid = %d\n", low, high, mid);
  }

  printf("\n未找到目标元素 %d，返回 -1\n", target);
  return -1;
}

int binarySearchForLoop2(int arr[], int len, int target) {
  int low = 0;
  int high = len - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (target > arr[mid]) {
      low = mid + 1;
    } else if (target < arr[mid]) {
      high = mid - 1;
    } else {
      return mid;
    }
  }
  return -1;
}

int main() {
  // 设置控制台输出为 UTF-8
  SetConsoleOutputCP(CP_UTF8);


  int arr[] = {1, 4, 5, 9, 10, 12, 15, 18, 20, 23};
  int len = sizeof(arr) / sizeof(arr[0]);



  printf("原始数组：\n");
  printArr(arr, len);
  int target1 = 20;
  int index1 = binarySearchForLoop(arr, len, target1);
  printf("target1 = %d，其索引为 %d\n", target1, index1);
  printf("\n------------------------------------------------\n\n");

  printf("原始数组：\n");
  printArr(arr, len);
  int target2 = 4;
  int index2 = binarySearchForLoop(arr, len, target2);
  printf("target2 = %d，其索引为 %d", target2, index2);
  printf("\n------------------------------------------------\n\n");

  return 0;
}

/**
原始数组：
当前数组：1     4       5       9       10      12      15      18      20      23
数组索引：0     1       2       3       4       5       6       7       8       9

开始二分查找：target = 20

[循环开始] 当前搜索区间：[low = 0, high = 9], 计算中点 mid = 4
arr[4] = 10
arr[4] = 10 小于 target = 20，向右半区间继续查找
[循环结束] low = 5, high = 9, mid = 4

[循环开始] 当前搜索区间：[low = 5, high = 9], 计算中点 mid = 7
arr[7] = 18
arr[7] = 18 小于 target = 20，向右半区间继续查找
[循环结束] low = 8, high = 9, mid = 7

[循环开始] 当前搜索区间：[low = 8, high = 9], 计算中点 mid = 8
arr[8] = 20
找到目标元素：arr[8] = 20，返回索引 8
target1 = 20，其索引为 8

------------------------------------------------

原始数组：
当前数组：1     4       5       9       10      12      15      18      20      23
数组索引：0     1       2       3       4       5       6       7       8       9

开始二分查找：target = 4

[循环开始] 当前搜索区间：[low = 0, high = 9], 计算中点 mid = 4
arr[4] = 10
arr[4] = 10 大于 target = 4，向左半区间继续查找
[循环结束] low = 0, high = 3, mid = 4

[循环开始] 当前搜索区间：[low = 0, high = 3], 计算中点 mid = 1
arr[1] = 4
找到目标元素：arr[1] = 4，返回索引 1
target2 = 4，其索引为 1
------------------------------------------------
*/
