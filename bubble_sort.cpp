
// bubble_sort perform sorting from right to left in each iteration


// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// worst case time complexity O(n^2)  even if array is sorted, it will run n^2 times 
//  so to optimize it we can use a flag to check if any swapping happened or not if not then we can break the loop

// int main(){
//     vector<int> arr={23,45,11,2,3,456,6};
//     int n=arr.size()-1;
//     for(int i=n;i>=0;i--){
//         for(int j=0;j<=i-1;j++){
//             if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
//         }
//     }
//     for(int c:arr)cout<<c<<"\n";
//     return 0;
// }


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// if ARRAY IS SORTED THEN IT SHOULD RUN IN O(N)  oterhwsise it will run in O(n^2)
int main(){
    vector<int> arr={23,45,11,2,3,456,6};
    int n=arr.size()-1;
    for(int i=n;i>=0;i--){
        int flag=0;
        for(int j=0;j<=i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
      if(flag==0)break;
   }
   for(int c:arr)cout<<c<<"\n";
   return 0;
}