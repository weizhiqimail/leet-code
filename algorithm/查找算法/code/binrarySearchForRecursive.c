#include <stdio.h>

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

int binarySearchForRecursive(int arr[], int low, int high, int target) {
  // 每次递归都输出当前的 low, high, mid
  printf("[递归调用] 当前区间：[low = %d, high = %d], 计算中点 mid = %d, arr[mid] = %d\n", low, high, (low + high) / 2, arr[(low + high) / 2]);

  // 当区间无效时（低索引大于高索引）返回-1
  if (low > high) {
    printf("\n[递归结束] low > high, 未找到目标元素 %d, 返回 -1\n", target);
    return -1;
  }

  // 计算中点
  int mid = low + (high - low) / 2;

  // 找到目标元素
  if (arr[mid] == target) {
    printf("目标元素 %d 找到，索引为 %d\n", target, mid);
    return mid;
  }

  // 如果目标大于中点元素，则目标在右半区间
  if (target > arr[mid]) {
    printf("目标 %d 大于 arr[mid] = %d，向右半区间继续查找：[mid + 1, high]\n", target, arr[mid]);
    return binarySearchForRecursive(arr, mid + 1, high, target);
  }

  // 如果目标小于中点元素，则目标在左半区间
  printf("目标 %d 小于 arr[mid] = %d，向左半区间继续查找：[low, mid - 1]\n", target, arr[mid]);
  return binarySearchForRecursive(arr, low, mid - 1, target);
}

int main() {
  int arr[] = {1, 4, 5, 9, 10, 12, 15, 18, 20, 23};
  int len = sizeof(arr) / sizeof(arr[0]);
  int low = 0;
  int high = len - 1;

  printf("原始数组：\n");
  printArr(arr, len);

  // 测试查找目标元素 20
  int target1 = 20;
  printf("查找目标 %d 的索引：\n", target1);
  int index1 = binarySearchForRecursive(arr, low, high, target1);
  printf("target1 = %d，其索引为 %d\n", target1, index1);
  printf("\n------------------------------------------------\n\n");

  // 测试查找目标元素 4
  printf("原始数组：\n");
  printArr(arr, len);
  int target2 = 4;
  printf("查找目标 %d 的索引：\n", target2);
  int index2 = binarySearchForRecursive(arr, low, high, target2);
  printf("target2 = %d，其索引为 %d\n", target2, index2);
  printf("\n------------------------------------------------\n\n");

  return 0;
}

/**
原始数组：
当前数组：1     4       5       9       10      12      15      18      20      23
数组索引：0     1       2       3       4       5       6       7       8       9

查找目标 20 的索引：
[递归调用] 当前区间：[low = 0, high = 9], 计算中点 mid = 4, arr[mid] = 10
目标 20 大于 arr[mid] = 10，向右半区间继续查找：[mid + 1, high]
[递归调用] 当前区间：[low = 5, high = 9], 计算中点 mid = 7, arr[mid] = 18
目标 20 大于 arr[mid] = 18，向右半区间继续查找：[mid + 1, high]
[递归调用] 当前区间：[low = 8, high = 9], 计算中点 mid = 8, arr[mid] = 20
目标元素 20 找到，索引为 8
target1 = 20，其索引为 8

------------------------------------------------

原始数组：
当前数组：1     4       5       9       10      12      15      18      20      23
数组索引：0     1       2       3       4       5       6       7       8       9

查找目标 4 的索引：
[递归调用] 当前区间：[low = 0, high = 9], 计算中点 mid = 4, arr[mid] = 10
目标 4 小于 arr[mid] = 10，向左半区间继续查找：[low, mid - 1]
[递归调用] 当前区间：[low = 0, high = 3], 计算中点 mid = 1, arr[mid] = 4
目标元素 4 找到，索引为 1
target2 = 4，其索引为 1

------------------------------------------------
 */