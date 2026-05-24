# 41343106

作業三：Sorting Project

---

# Bubble Sort

## 解題說明
本題實作 Bubble Sort，透過相鄰元素比較與交換，將資料由小到大排序。

### 解題策略

1. 從第一個元素開始比較相鄰元素  
2. 若前者大於後者則交換位置  
3. 每輪會將最大值移動到最後  
4. 重複執行直到排序完成  

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

### 測試程式

```cpp
#include "bubble_sort.h"

int main() {
    vector<int> data = {5,3,8,4,2};

    BubbleSort b;
    b.sort(data);
    b.print(data);
}
```
## 測試與驗證
輸入：5 3 8 4 2  
輸出：2 3 4 5 8  

### 編譯與執行指令

```shell
g++ -std=c++17 -o sorting main.cpp
./sorting
```

## 申論及開發報告
Bubble Sort 是一種基礎且經典的排序演算法，其核心概念為「透過不斷比較相鄰元素並交換位置，將較大的元素逐步移動到陣列尾端」。由於排序過程中較大的元素會像氣泡一樣慢慢浮到最上層，因此稱為 Bubble Sort。

在本次實作中，使用雙層迴圈完成排序。外層迴圈控制排序回合數，內層迴圈負責比較相鄰元素並進行交換。當前一個元素大於後一個元素時，即透過 `swap()` 函式交換位置，最終完成由小到大的排序結果。

Bubble Sort 的優點是程式邏輯簡單、容易理解，特別適合作為初學者學習排序演算法的入門範例。透過本次實作，可以更加理解排序演算法中的「比較」與「交換」概念，以及迴圈控制方式。此外，Bubble Sort 不需要額外的大量記憶體，其空間複雜度僅為 $O(1)$，屬於 in-place sorting。

然而，Bubble Sort 的缺點也十分明顯。由於其平均與最差時間複雜度皆為 $O(n^2)$，當資料量增加時，排序效率會明顯下降。因此，在實際大型資料處理中，通常不會直接使用 Bubble Sort，而會改用 Merge Sort、Quick Sort 或 Heap Sort 等效率更高的演算法。


