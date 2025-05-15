#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

// 打印数组指定范围内容（带标签）
void printArrayRange(int arr[], int start, int end, const char* label) {
  printf("%s [", label);
  for (int i = start; i <= end; i++) {
    printf("%d", arr[i]);
    if (i != end) printf(", ");
  }
  printf("]\n");
}

// 合并两个有序子数组 arr[left..m] 和 arr[m+1..right]
void merge(int arr[], int left, int m, int right) {
  printf("\n【合并】left = %d，m = %d，right = %d\n", left, m, right);

  int n1 = m - left + 1;
  int n2 = right - m;

  printf("左数组长度 n1 = %d，右数组长度 n2 = %d\n", n1, n2);

  int L[n1], R[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
    printf("L[%d] ← arr[%d] = %d\n", i, left + i, L[i]);
  }

  for (int j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
    printf("R[%d] ← arr[%d] = %d\n", j, m + 1 + j, R[j]);
  }

  printArrayRange(L, 0, n1 - 1, "左数组:");
  printArrayRange(R, 0, n2 - 1, "右数组:");

  int i = 0, j = 0, k = left;

  printf("开始归并：\n");

  while (i < n1 && j < n2) {
    printf("比较 L[%d]=%d 和 R[%d]=%d\n", i, L[i], j, R[j]);
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      printf("→ 选用 L[%d] = %d 放入 arr[%d]\n", i, L[i], k);
      i++;
    } else {
      arr[k] = R[j];
      printf("→ 选用 R[%d] = %d 放入 arr[%d]\n", j, R[j], k);
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    printf("拷贝剩余 L[%d] = %d 到 arr[%d]\n", i, L[i], k);
    i++;
    k++;
  }

  printf("左数组拷贝完成，i = %d，k = %d\n", i, k);
  printArrayRange(arr, left, right, "合并过程当前 arr:");

  while (j < n2) {
    arr[k] = R[j];
    printf("拷贝剩余 R[%d] = %d 到 arr[%d]\n", j, R[j], k);
    j++;
    k++;
  }

  printf("右数组拷贝完成，j = %d，k = %d\n", j, k);
  printArrayRange(arr, left, right, "合并完成 arr:");

  printf("\n------------------------------\n");
}

// 归并排序函数
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    int mid = left + (right - left) / 2;

    printf("\n【分解】mergeSort(arr, %d, %d)，中点 mid = %d\n", left, right,
           mid);
    printArrayRange(arr, left, right, "当前要分解的数组:");

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
  } else {
    printf("\n【跳过】mergeSort(arr, %d, %d)：只有一个元素，无需处理。\n", left,
           right);
  }
}

// 打印整个数组
void printFullArray(int arr[], int size, const char* label) {
  printf("%s [", label);
  for (int i = 0; i < size; i++) {
    printf("%d", arr[i]);
    if (i != size - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

// 主函数
int main() {
  // 设置控制台输出为 UTF-8
  SetConsoleOutputCP(CP_UTF8);

  int arr[] = {64, 34, 25, 12, 22, 11, 90, 66, 39, 48, 56};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("\n========= 原始数组 =========\n");
  printFullArray(arr, n, "原始数组:");

  mergeSort(arr, 0, n - 1);

  printf("\n========= 排序后数组 =========\n");
  printFullArray(arr, n, "排序后数组:");

  return 0;
}
