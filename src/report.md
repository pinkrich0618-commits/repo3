# 41343106

作業三：Sorting Project

---

# Bubble Sort

## 解題說明
本題實作 Bubble Sort，透過相鄰元素比較與交換，將資料由小到大排序。

## 程式實作
```cpp
#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "header.h"

class BubbleSort {
public:
    void sort(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    void print(vector<int> arr) {
        for(int x : arr)
            cout << x << " ";
        cout << endl;
    }
};

#endif
```
## 效能分析
1. 時間複雜度：$O(n^2)$  
2. 空間複雜度：$O(1)$  

## 測試與驗證
輸入：5 3 8 4 2  
輸出：2 3 4 5 8  

## 申論及開發報告
Bubble Sort 實作簡單，但效率較低，適合小量資料或教學用途。
