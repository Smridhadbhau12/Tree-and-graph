#include<stdio.h>
int main(){
    int n;
    printf("Enter Array size: ");
    int arr[n];
    printf("Enter Array Elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int val;
    printf("Enter searching element: ");
    scanf("%d",&val);
    int startIdx = 0;
    int endIdx = n-1;
    while(startIdx <= endIdx){
        int mid = startIdx + (endIdx - startIdx)/2;
        if(val == arr[mid]){
            printf("Found!!!\n");
            return mid;
        }
        else if(val <arr[mid])
        endIdx =mid-1;
        else
        startIdx = mid+1;
    }
     printf("Not Found!!!!\n");
     return 0;
}
