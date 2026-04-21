#ifndef MYSORT_HPP
#define MYSORT_HPP

namespace MySort {

    // Hàm Trộn (Merge) - Dùng template để nhận mọi kiểu dữ liệu T
    template <typename T>
    void Merge(T arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        
        // Cấp phát mảng động theo kiểu T
        T* L = new T[n1];
        T* R = new T[n2];
        
        for(int i = 0; i < n1; i++) L[i] = arr[left + i];
        for(int i = 0; i < n2; i++) R[i] = arr[mid + i + 1];
        
        int i = 0, j = 0;
        int k = left;
        while(i < n1 && j < n2) {
            if(L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        while(i < n1) {
            arr[k++] = L[i++];
        }
        while(j < n2) {
            arr[k++] = R[j++];
        }
        
        // Giải phóng bộ nhớ để chống leak RAM
        delete[] L;
        delete[] R;
    }

    // Hàm Merge Sort chính
    template <typename T>
    void MergeSort(T arr[], int left, int right) {
        if(left < right) {
            int mid = left + (right - left) / 2;
            MergeSort(arr, left, mid);
            MergeSort(arr, mid + 1, right);
            Merge(arr, left, mid, right);
        }
    }

} // Kết thúc namespace MySort

#endif // MYSORT_HPP