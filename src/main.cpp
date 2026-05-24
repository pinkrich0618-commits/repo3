#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"

int main() {
    vector<int> data = {5, 3, 8, 4, 2};

    BubbleSort bubble;
    bubble.sort(data);
    bubble.print(data);

    return 0;
}
