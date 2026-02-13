
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main(){

    /** Method 2 using Set  of Vector ,Set uses Redblack tree and insertion O(NlogN)  since it perform */
    set<vector<int>> set1;

    vector<int> arr={-1,0,1,2,-1,-4};
    for(int i=0;i<arr.size()-2;i++){
        for(int j=i+1;j<arr.size()-1;j++){
            for(int k=j+1;k<arr.size();k++){
                vector<int>temp;
                if(arr[i]+arr[j]+arr[k]==0){
                  temp={arr[i],arr[j],arr[k]};
                  sort(temp.begin(),temp.end());
                  set1.insert(temp);  // only insert unique element to set ,duplicacy will be remove
                }
            }
        }
    }

    vector<vector<int>>newArr(set1.begin(),set1.end());
    for(auto n:newArr){
        for(int m:n){
            cout<<m<<" ";
        }
    }   

    
    /**  Method 1 using Vector of Vector
    vector<vector<int>>Array_Of_Array;
    
    vector<int>arr={-1,0,1,2,-1,-4};
    for(int i=0;i<arr.size()-2;i++){
        for(int j=i+1;j<arr.size()-1;j++){
            for(int k=j+1;k<arr.size();k++){
               vector<int >temp;
               if(arr[i]+arr[j]+arr[k]==0){
               temp={arr[i],arr[j],arr[k]};
               sort(temp.begin(),temp.end());
                Array_Of_Array.push_back(temp);
               }
            }
        }
    }
    sort(Array_Of_Array.begin(),Array_Of_Array.end());

    auto last = unique(Array_Of_Array.begin(),Array_Of_Array.end());  // place all duplicate element at end and return an iterator 
    Array_Of_Array.erase(last,Array_Of_Array.end());  // erasing all garbage value from iterator location to end
   **/
   
    /** 
    for(int i=0;i<Array_Of_Array.size();i++){
        for(int k=0;k<Array_Of_Array[i].size();k++){
            cout<<Array_Of_Array[i][k];
        }
    }**/

    /**   
        int i=0;
            for(auto n:Array_Of_Array){
                
                cout<< "\nThis was "<<i++<<"th-1D"<<endl;
                for(int element:n){
                    cout<< element<<" ";
                }
            }
    **/
    return 0;
}