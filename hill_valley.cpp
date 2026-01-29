#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int func(vector<int>&arr)
 {
   
   int k=0;int hill_valley=0;
   for(int i=1;i<arr.size()-1;i++){
       
       if(arr[i]==arr[k]) continue;

       if(arr[i]<arr[k] && arr[i]<arr[i+1]){
           hill_valley++;
       }
       else if(arr[i]>arr[k] && arr[i]>arr[i+1]){
           hill_valley++;    
       }
       k=i;
   }
   cout<<hill_valley;
    return 0;
}

int main(){
    vector<int>arr={2,4,1,1,6,5,7};
    func(arr);
    return 0;
}
