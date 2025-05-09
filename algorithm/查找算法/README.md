# 1. 查找算法

## 1.1 顺序查找（Linear Search）

- 顺序查找：将待查找的关键字与表中的数据从头至尾按顺序进行比较。
- 其实就是遍历数组中的每个元素，直到找到目标元素为止。
- 时间复杂度：`O(n)`。

```c++
#include <iostream>
using namespace std;

// 顺序查找函数
int sequentialSearch(int arr[], int size, int target) {
    // 遍历数组中的每个元素
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // 找到目标元素，返回索引
        }
    }
    return -1; // 未找到目标元素，返回-1
}

int main() {
    int arr[] = { 3, 5, 7, 9, 12, 15, 20 }; // 数组
    int size = sizeof(arr) / sizeof(arr[0]); // 数组大小
    int target = 9; // 目标值

    int result = sequentialSearch(arr, size, target);

    if (result != -1) {
        cout << "目标元素 " << target << " 找到了，索引位置为: " << result << endl;
    } else {
        cout << "目标元素 " << target << " 未找到！" << endl;
    }

    return 0;
}
```

## 1.2 二分查找法（折半查找）（Binary Search）

### 1.2.1 二分查找法查找元素

- 要求：列表必须是顺序存储的数据结构。
- 时间复杂度：$\log_2 n$。
- 优点：**二分查找效率非常高**，无须额外空间。 
- 缺点：**仅适用于有序数组**，二分查找需要跳跃式访问元素，链表中执行跳跃操作效率低，所以不适用于基于链表实现的数据结构。
- **原理（不断缩小边界；小于目标值，就缩左界；大于目标值，就缩右界。）**：
  - **初始化左右边界**：
    - 通常设为 `left = 0`，`right = n - 1`（数组下标范围）。 
  - **每次查找中间元素**： 
    - 计算中间索引 `mid = left + (right - left) // 2`（避免整数溢出）。 
  - **比较中间值与目标值的大小**： 
    - 如果 `array[mid] == target`，说明找到了，返回 `mid`。 
    - 如果 `array[mid] < target`，则目标值只可能在右半部分，令 `left = mid + 1`。 
    - 如果 `array[mid] > target`，则目标值只可能在左半部分，令 `right = mid - 1`。 
  - **循环进行，直到 left > right**： 
    - 如果整个过程没有找到目标值，说明目标不存在，返回 `-1` 或 `null` 等表示未找到。

### 1.2.2 二分查找法示例代码

```c++
#include <iostream>
#include <vector>

using namespace std;

/* 二分查找 - 使用 while 循环（迭代） 
   前提：nums 必须是升序排列的数组 */
int binarySearchForLoop(vector<int> &nums, int target) {
    // 初始化双闭区间 [0, n-1]，即 i, j 分别指向数组首元素、尾元素
    int i = 0, j = nums.size() - 1;
    // 循环，当搜索区间为空时跳出（当 i > j 时为空）
    while (i <= j) {
        int m = i + (j - i) / 2; // 计算中点索引 m
        if (nums[m] < target) {
            // target 在区间 [m+1, j] 中
            i = m + 1;
        } else if (nums[m] > target) {
            // target 在区间 [i, m-1] 中
            j = m - 1;
        } else {
            // 找到目标元素，返回其索引
            return m;
        }
    }
    // 未找到目标元素，返回 -1
    return -1;
}

/* 二分查找 - 使用递归 
   前提：nums 必须是升序排列的数组 */
int binarySearchRecursive(vector<int> &nums, int low, int high, int target) {
    if (low > high) {
        // 搜索区间为空，返回 -1
        return -1;
    }

    int mid = low + (high - low) / 2;
    if (nums[mid] == target) {
        return mid;
    }
    if (target < nums[mid]) {
        // target 在区间 [low, mid-1] 中
        return binarySearchRecursive(nums, low, mid - 1, target);
    }
    // target 在区间 [mid+1, high] 中
    return binarySearchRecursive(nums, mid + 1, high, target);
}

/* 插入元素 - 保持数组升序 */
void insertElement(vector<int> &nums, int target) {
    int i = 0;
    // 使用二分查找找到插入位置
    while (i < nums.size() && nums[i] < target) {
        i++;
    }
    // 插入元素
    nums.insert(nums.begin() + i, target);
}

int main() {
    vector<int> nums = {1, 4, 5, 9, 10, 12, 15, 18, 20};
    int target = 8;
    
    // 插入元素
    insertElement(nums, target);

    // 输出插入后的数组
    cout << "Array after insertion: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // 使用二分查找查找插入后的元素
    int index1 = binarySearchForLoop(nums, target);
    cout << "Index of " << target << " (using loop): " << index1 << endl;

    int index2 = binarySearchRecursive(nums, 0, nums.size() - 1, target);
    cout << "Index of " << target << " (using recursion): " << index2 << endl;
    return 0;
}
```

