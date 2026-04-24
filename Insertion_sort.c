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
    for(int i=1 ;i<n;i++){
        int curr =arr[i];
        int prev =i-1;
        while(prev >=0 && arr[prev] > curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
    printf("After Sorting Array Elements are : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
