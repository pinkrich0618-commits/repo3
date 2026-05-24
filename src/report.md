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

## 測試與驗證

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
###測試結果

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


# Selection Sort

## 解題說明
本題實作 Selection Sort，透過每回合尋找最小值並放到正確位置，完成由小到大的排序。

### 解題策略

1. 從未排序區間中尋找最小元素  
2. 記錄最小值的位置  
3. 將最小值與目前位置交換  
4. 重複執行直到排序完成  

---

## 程式實作

```cpp
#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "header.h"

class SelectionSort {
public:
    void sort(vector<int>& arr) {
        int n = arr.size();

        for(int i = 0; i < n - 1; i++) {

            int minIndex = i;

            for(int j = i + 1; j < n; j++) {

                if(arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            swap(arr[i], arr[minIndex]);
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
##效能分析
1. 時間複雜度：$O(n^2)$  
2. 空間複雜度：$O(1)$
   
## 測試與驗證

### 測試程式
```cpp
#include "selection_sort.h"

int main() {

    vector<int> data = {5,3,8,4,2};

    SelectionSort s;

    s.sort(data);

    s.print(data);
}
```
###測試結果

輸入：5 3 8 4 2  
輸出：2 3 4 5 8  

### 編譯與執行指令

```shell
g++ -std=c++17 -o sorting main.cpp
./sorting
```
## 申論及開發報告
Selection Sort 是一種基礎排序演算法，其主要概念為每次從未排序區間中選出最小值，並將其放置到正確的位置。與 Bubble Sort 不同的是，Selection Sort 每回合只會進行一次交換，因此交換次數較少。

在本次實作中，使用雙層迴圈完成排序。外層迴圈負責控制目前排序的位置，內層迴圈則負責尋找剩餘元素中的最小值。找到最小值後，再與目前位置進行交換，逐步完成整體排序。

Selection Sort 的優點是程式邏輯簡單、容易理解，且交換次數固定較少，因此在交換成本較高的情況下具有一定優勢。此外，其空間複雜度為 $O(1)$，屬於 in-place sorting，不需要額外大量記憶體。

然而，Selection Sort 的缺點是即使資料接近排序完成，仍然需要完整比較所有元素，因此最佳、平均與最差時間複雜度皆為 $O(n^2)$。當資料量增加時，效率會明顯下降，因此較不適合大型資料排序。

# Insertion Sort

## 解題說明
本題實作 Insertion Sort，透過將元素逐一插入已排序區間中，完成由小到大的排序。

### 解題策略

1. 將第一個元素視為已排序區間  
2. 從第二個元素開始逐一取出  
3. 與前方已排序元素比較  
4. 將較大的元素向後移動  
5. 將元素插入正確位置  

---

## 程式實作

```cpp
#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "header.h"

class InsertionSort {
public:
    void sort(vector<int>& arr) {

        int n = arr.size();

        for(int i = 1; i < n; i++) {

            int key = arr[i];
            int j = i - 1;

            while(j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
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

##效能分析
1. 時間複雜度：$O(n^2)$  
2. 空間複雜度：$O(1)$

3. ## 測試與驗證

### 測試程式
```cpp
#include "insertion_sort.h"

int main() {

    vector<int> data = {5,3,8,4,2};

    InsertionSort s;

    s.sort(data);

    s.print(data);
}
```

##測試結果

輸入：5 3 8 4 2  
輸出：2 3 4 5 8  

### 編譯與執行指令

```shell
g++ -std=c++17 -o sorting main.cpp
./sorting
```
## 申論及開發報告
Insertion Sort 是一種簡單且直觀的排序演算法，其核心概念為將資料逐一插入到已排序區間中的正確位置。排序過程類似於撲克牌整理方式，每次取出一張牌並插入到適當位置，因此稱為 Insertion Sort。

在本次實作中，程式會從第二個元素開始，將目前元素與前方已排序區間進行比較，若前方元素較大則向後移動，直到找到適合的位置後再插入。透過不斷重複此步驟，即可完成整體排序。

Insertion Sort 的優點是程式邏輯簡單，且當資料接近排序完成時效率相當不錯。在最佳情況下（資料原本已排序），時間複雜度可達 $O(n)$，因此在小量資料或近乎排序完成的情況下具有良好效能。此外，其空間複雜度為 $O(1)$，屬於 in-place sorting。

然而，Insertion Sort 在大量資料情況下效率較低，平均與最差時間複雜度皆為 $O(n^2)$。因此在大型資料排序中，通常會使用 Merge Sort 或 Quick Sort 等效率更高的演算法。

