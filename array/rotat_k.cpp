#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void leftRotate(vector<int>& nums,int k){
    if(k==0)return;
    k=k%nums.size();
    reverse(nums.begin(),nums.end);
    reverse(nums.begin,nums.begin()+k);
    reverse(nums.begin()+k,nums.end());

    for(int n:nums){
        cout<<n<<" ";
    }
    cout<<"\n";
}
void RighRotate(vector<int>& nums ,int k){
    if(k==0)return ;
    k=k%nums.size();
    reverse(nums.begin(),nums.end());
    reverse(nums.begin(),nums.size()-k);
    reverse(nums.size()-k,nums.size());
}
int main(){
    vector<int>arr={}; // empty array
    int u,n;
    cout<<"Enter the numebr of ELment for array:";
    cin>> n;
    cout<<"\nEnter the array element:";
    for(int i=0;i<n;i++){
        cin>>u;
        arr.push_back(u);
    }
    while (true)
    {    
    cout<<"\nEnter the Direction you want to rotate Either Left(0) or Right(1)\n";
    cout<<"Press any number except 0 and 1  to Exit\n";
    cin>>u; 
    
    if(u==0){
        cout<<"\nEnter how many element to rotate:" ;  
        int t;
        cin>>t;
        leftRotate(arr,t);}
    else if(u==1){
        
        cout<<"\nEnter how many element to rotate:" ;  
        int t;
        cin>>t;
        RighRotate(arr,t);}
    else{
        exit(0);
    }
    }
    return 0;
}

/*
    cout<<"Fisrst array configuration\n";
    vector<int>arr1(3);  // arr filled with 3 zero 0
    cout<<arr1.size();    
    arr1.push_back(2);
    cout<<arr1[0];
    cout<< arr1[3];
cout<<"\nSecond Array configuaration\n";
    vector<int>arr={};  //array without any values or empty array
    cout<<arr.size();
    arr.push_back(4);
    cout<< arr[0];
*/
