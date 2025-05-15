#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// 打印整个数组
void printFullArray(int arr[], int size, const char *label) {
  printf("%s [", label);
  for (int i = 0; i < size; i++) {
    printf("%d", arr[i]);
    if (i != size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

// 合并数组（带详细日志）
void mmerge(int arr[], int tempArr[], int left, int mid, int right) {
  printf("\n[合并] 左: %d ~ %d, 右: %d ~ %d\n", left, mid, mid + 1, right);
  printFullArray(arr, right + 1, "合并前数组:");

  int lPos = left;
  int rPos = mid + 1;
  int pos = left;
  printf("while 之前： lPost=%d, rPos=%d, pos=%d ", lPos, rPos, pos);

  while (lPos <= mid && rPos <= right) {
    printf("  比较 arr[%d]=%d 和 arr[%d]=%d => ", lPos, arr[lPos], rPos,
           arr[rPos]);
    if (arr[lPos] < arr[rPos]) {
      printf("选择 arr[%d]=%d 放入 tempArr[%d]\n", lPos, arr[lPos], pos);
      tempArr[pos++] = arr[lPos++];
    } else {
      printf("选择 arr[%d]=%d 放入 tempArr[%d]\n", rPos, arr[rPos], pos);
      tempArr[pos++] = arr[rPos++];
    }
  }

  while (lPos <= mid) {
    printf("  复制左侧剩余 arr[%d]=%d 到 tempArr[%d]\n", lPos, arr[lPos], pos);
    tempArr[pos++] = arr[lPos++];
  }

  while (rPos <= right) {
    printf("  复制右侧剩余 arr[%d]=%d 到 tempArr[%d]\n", rPos, arr[rPos], pos);
    tempArr[pos++] = arr[rPos++];
  }

  for (int i = left; i <= right; i++) {
    arr[i] = tempArr[i];
    printf("  拷贝回原数组 arr[%d] = %d\n", i, arr[i]);
  }

  printFullArray(arr, right + 1, "合并后数组:");
}

// 拆解数组（递归 + 日志 + 缩进）
void msort(int arr[], int tempArr[], int left, int right, int depth) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    // 打印当前递归深度的缩进
    for (int i = 0; i < depth; i++) {
      printf("  ");
    }
    printf("[拆分] 左: %d ~ %d, 右: %d ~ %d\n", left, mid, mid + 1, right);

    // 递归左半部分
    msort(arr, tempArr, left, mid, depth + 1);
    // 递归右半部分
    msort(arr, tempArr, mid + 1, right, depth + 1);

    // 合并前日志
    for (int i = 0; i < depth; i++) {
      printf("  ");
    }
    printf("[合并准备] 合并: %d ~ %d 和 %d ~ %d\n", left, mid, mid + 1, right);

    // 合并操作
    mmerge(arr, tempArr, left, mid, right);
  }
}

void mmerge2(int arr[], int tempArr[], int left, int mid, int right) {
  int lPos = left;
  int rPos = mid + 1;
  int pos = left;

  while (lPos <= mid && rPos <= right) {
    if (arr[lPos] < arr[rPos]) {
      tempArr[pos++] = arr[lPos++];
    } else {
      tempArr[pos++] = arr[rPos++];
    }
  }

  while (lPos <= mid) {
    tempArr[pos++] = arr[lPos++];
  }

  while (rPos <= right) {
    tempArr[pos++] = arr[rPos++];
  }

  while (left <= right) {
    arr[left] = tempArr[left];
    left++;
  }
}

void msort2(int arr[], int tempArr[], int left, int right, int depth) {
  if (left < right) {
    int mid = left + (right - left) / 2;
    msort2(arr, tempArr, left, mid, depth + 1);
    msort2(arr, tempArr, mid + 1, right, depth + 1);
    mmerge2(arr, tempArr, left, mid, right);
  }
}

// 主函数
int main() {
  // 设置控制台输出为 UTF-8
  SetConsoleOutputCP(CP_UTF8);

  int arr[] = {64, 34, 25, 12, 22, 11, 90, 66, 39, 48, 56};
  int n = sizeof(arr) / sizeof(arr[0]);
  int *tempArr = (int *)malloc(n * sizeof(int));

  printf("\n========= 原始数组 =========\n");
  printFullArray(arr, n, "原始数组:");

  msort2(arr, tempArr, 0, n - 1, 0);

  printf("\n========= 排序后数组 =========\n");
  printFullArray(arr, n, "排序后数组:");

  return 0;
}
