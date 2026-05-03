#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

int main(){
    // 1,4,5,6,13
    vector<int>arr={9930,9923,9983,9997,9934,9952,9945,9914,9985,9982,9970,9932,9985,9902,9975,9990,9922,9990,9994,9937,9996,9964,9943,9963,9911,9925,9935,9945,9933,9916,9930,9938,10000,9916,9911,9959,9957,9907,9913,9916,9993,9930,9975,9924,9988,9923,9910,9925,9977,9981,9927,9930,9927,9925,9923,9904,9928,9928,9986,9903,9985,9954,9938,9911,9952,9974,9926,9920,9972,9983,9973,9917,9995,9973,9977,9947,9936,9975,9954,9932,9964,9972,9935,9946,9966};
    vector<int>v(14);
    unordered_map<int,int>hash;
    for(int t:arr){
        hash[t]++;   // all key value will be increase from 0 to 1;
    }

    for(int i=0;i<arr.size();i++)
    {
       int k=3056; int temp=arr[i];
       while(k){
           temp++;
           if(hash.find(temp)!=hash.end())   // if keys found then icrease their value
           {
            hash[temp]++;
           } 

           /* using vector it will take O(N) time
           if(find(arr.begin(),arr.end(),temp)!=arr.end()){
            v[temp]++;
           }
            */
           k--;
       }
    }
    
    int maxfreq=0;int Mostfreqe=-1;
    for(const auto& pair:hash){
        if(pair.second>maxfreq){
            maxfreq=pair.second;
            Mostfreqe=pair.first;
        }
    }
    cout<<" Most Frequent Element:"<<Mostfreqe<<"max frequency:"<<maxfreq;


    // int max1=INT_MIN;
    // for(int i=0;i< v.size();i++){
    //      if(max1<v[i]){
    //         max1=v[i];
    //      }
    // }
    // cout<< max1+1;
    return 0;
}