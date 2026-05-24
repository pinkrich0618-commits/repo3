#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "header.h"

class MergeSort {
public:
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left;
        int j = mid + 1;

        while(i <= mid && j <= right) {
            if(arr[i] <= arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }

        while(i <= mid)
            temp.push_back(arr[i++]);

        while(j <= right)
            temp.push_back(arr[j++]);

        for(int k = 0; k < temp.size(); k++)
            arr[left + k] = temp[k];
    }

    void sort(vector<int>& arr, int left, int right) {
        if(left >= right)
            return;

        int mid = (left + right) / 2;
        sort(arr, left, mid);
        sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    void print(vector<int> arr) {
        for(int x : arr)
            cout << x << " ";
        cout << endl;
    }
};

#endif
