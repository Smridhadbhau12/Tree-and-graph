#include<stdio.h>
int partition(int *arr, int start, int end){
    int idx = start-1, pivat = arr[end];
    for(int j=start; j<end; j++){
        if(arr[j]<pivat){
            idx++;
            int temp = arr[idx];
            arr[idx] = arr[j];
            arr[j] = temp;
        }
    }
    idx++;
    int temp = arr[idx];
    arr[idx] = arr[end];
    arr[end] = temp;
    return idx;
}
void QuickSort(int *arr, int start, int end){
    if(start < end){
        int pivat = partition(arr, start, end);
        QuickSort(arr, start, pivat-1);
        QuickSort(arr, pivat+1, end);
    }
}
int main(){
    int n;
    printf("Enter Array Size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array Element: ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
QuickSort(arr, 0, n-1);
    printf("After Sorting Array Element are: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
