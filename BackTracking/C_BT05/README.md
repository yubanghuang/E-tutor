# [C_BT05-易] 堆積排序
- Heap sort
1. Build Heap Tree
   - 一次插入一個值並做 Heapify
2. Sort
   - Heap Tree 中 Root 為最小值
   - Root 每次都會和已經排序好的元素的前一個元素做交換，然後做 Heapify。
