#include<stdio.h>
int main(){
    int n;
    printf("Enter Array size: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n-1;i++){
        int minIdx =i;
        for(int j=i+1;j<n;j++){
            if(arr[j] <arr[minIdx])
            minIdx =j;
        }
        if(minIdx != i){
            int temp = arr[minIdx];
            arr[minIdx] =arr[i];
            arr[i] = temp;
        }
    }
    printf("After Sorting Array Elements are : ");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
    return 0;
}
