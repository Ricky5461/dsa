#include<iostream>
#include<vector>

using namespace std;
int main(){
    vector<int>nums={2,0,2,1,1,0};
    // Dutch national flag algorithm it took only one pass
    int l=0;int m=0;int h=nums.size()-1;
    while(m<=h){
        if(nums[m]==0){
            swap(nums[l],nums[m]);l++;m++;
        }
        else if(nums[m]==1){
            m++;
        }
        else{
            // mean nums[m]==2
            swap(nums[m],nums[h]);h--;
        }
    }
    
    for(int c:nums)cout<<c<<"\t";

    // This is my aproach and it took two pass 
//     vector<int >arr(3);
//     int n= nums.size();
//     int temp=0;
//     for(int i=0;i<n;i++){
//         arr[nums[i]]++;
//     }
//     int k;int i=0;
//     while(i<3){
//         k=0;
//     while(k<arr[i]){
//         nums[temp++]=i;k++;
//     }
//     i++;
// }
//     for(int o:nums){cout<<o<<"\t";}
    
    return 0;
}