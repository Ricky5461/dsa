#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main(){

// Method 4 by first sorting the array element in nlogn time 
vector<int>arr={0,0,1,1,-2,-2,-1,-1,0,2,2,-2,1,-1,0,0};
sort(arr.begin(),arr.end());
vector<vector<int>>arr2;
for(int i=0;i<arr.size();i++){
    int j=i+1;
    int k=arr.size()-1;
    if(i>0 && arr[i]==arr[i-1]) continue;
    while(j<k){
        int sum= arr[i]+arr[j]+arr[k];
        if(sum>0) k--;
        else if(sum<0)j++;
        else{
            vector<int>temp={arr[i],arr[j],arr[k]}; //  no need to sort already sorted
            arr2.push_back(temp); //since it is already sorted all three pair will be unique  
            j++;k--;
            while(j<k && arr[j]==arr[j-1])j++;
            while(j<k && arr[k]==arr[k+1])k--;
        }
    }
}
int k=0;
for(auto num: arr2){
    
    cout<<"\nThis is: "<<k++<<"th\n";
    for(int n:num){
        cout<<n<<" ";
    }
  }

return 0;}
   /**  // Method3
    vector<int>arr={-1,0,1,2,-1,-4};
    set<vector<int>>set1;
    for(int i=0;i<arr.size()-1;i++){
        set<int>hashset; // initialize with empty in each iteration

        for(int j=i+1;j<arr.size();j++){
            
            int k=-(arr[i]+arr[j]);

            if(hashset.find(k)!=hashset.end()){   //got the element
                 vector<int> temp={arr[i],arr[j],k};
                 sort(temp.begin(),temp.end());
                 set1.insert(temp);  // only store if unique array
            }
            else {
                hashset.insert(arr[j]);
            }

        }
    }
    vector<vector<int>>arrfinal(set1.begin(),set1.end());
    for(auto n:arrfinal){
        for(int num:n){
            cout<<num<<" ";
        }
    }
**/

    /** Method 2 using Set  of Vector ,Set uses Redblack tree and insertion O(NlogN)  since it perform 
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
**/
/** 
    //   Method 1 using Vector of Vector
    vector<vector<int>>Array_Of_Array;
    
    vector<int>arr={-1,0,1,2,-1,-4};
    for(int i=0;i<arr.size()-2;i++){
        for(int j=i+1;j<arr.size()-1;j++){
            for(int k=j+1;k<arr.size();k++){
    
                if(arr[i]+arr[j]+arr[k]==0){
                    Array_Of_Array.push_back({arr[i],arr[j],arr[k]});  // this is called initializer list and it will create a vector of 3 element and push to Array_Of_Array
                    sort(Array_Of_Array.back().begin(),Array_Of_Array.back().end()); //arr.back() will return the last element of Array_Of_Array which is just pushed
                    
                }
            }
        }
    }
    sort(Array_Of_Array.begin(),Array_Of_Array.end());

    auto last = unique(Array_Of_Array.begin(),Array_Of_Array.end());  // place all duplicate element at end and return an iterator 
    Array_Of_Array.erase(last,Array_Of_Array.end());  // erasing all garbage value from iterator location to end

int i=0;
    for(auto n:Array_Of_Array){
        
        cout<< "\nThis was "<<i++<<"th-1D"<<endl;
        for(int element:n){
            cout<< element<<" ";
        }
    }
**/
//     return 0;
// }