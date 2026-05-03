#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
int main(){
    vector<int>arr={2,-1,0,0,-2,1,2,-1,1,0,2,-2,-1};
    vector<vector<int>>vect1;
    sort(arr.begin(),arr.end());int target=0;
    // if element is less than 4 then we can not find any quadruple so return 0
    int n= arr.size();
    if(n<4) return 0;
    for(int i=0;i<arr.size()-2;i++){
        if(i>0 && arr[i]==arr[i-1])continue; // skiiping duplicate
        for(int j=i+1;j<arr.size()-1;j++){
        if(j>i+1&& arr[j]==arr[j-1]) continue;   // skiping duplicate
        int k= j+1;int l= arr.size()-1;
        while(k<l){
           // if element long long then we can not store in int so  typecast to long long to prevent overflow
           long long sum=(long long)arr[i]+arr[j]+arr[k]+arr[l];
           if(sum>target){
            l--;
           }
           else if(sum<target){
            k++;
           }
           else{  // when exactly equal to target then
            vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
             vect1.push_back(temp);
             k++;l--;
           while(k<l && arr[k]==arr[k-1])k++;  // k<l safe from going out of bound access and skiping duplicacy
           while(k<l && arr[l]==arr[l+1])l--; // prevent getting of bound access and remove duplicacy
           }
          
        }
    }}
//   vector<vector<int>>vect1(s1.begin(),s1.end());
    for(auto r1:vect1){
        for(int n: r1){
            cout<< n<<" ";
        }
        cout<<"\n";
    }   


    // lil bit optimize way andd O(n^3 log(m element in short hash)) time complexity
  /**
    set<vector<int>>s1;
    for(int i=0;i<arr.size()-3;i++){
        for(int j=i+1;j< arr.size()-2;j++){
            set<int>hashset;
            for(int k=j+1;k<arr.size()-1;k++){
                int target=0;
                int sum=arr[i]+arr[j]+arr[k];
                int fourth= target-sum;
                if(hashset.find(fourth)!=hashset.end()){
                    vector<int>temp={arr[i],arr[j],arr[k],fourth};
                    sort(temp.begin(),temp.end());
                    s1.insert(temp);
                }
                // if element not found in hashlist then put fourth element inside short hash
                hashset.insert(arr[k]);

            }
        }
    }
  vector<vector<int>>vectr1(s1.begin(),s1.end());
    for(auto r1:vectr1){
        for(int n: r1){
            cout<< n<<" ";
        }
        cout<<"\n";
    } 
**/

    /**  // Brute Force Technique   O(n^4)
    set<vector<int>>s1;
    for(int i=0;i<arr.size()-3;i++){
        for(int j=i+1;j< arr.size()-2;j++){
            for(int k=j+1;k<arr.size()-1;k++){
                for(int l=k+1;k<arr.size();k++){
                    int sum=arr[i]+arr[j]+arr[k]+arr[l];
                    if(sum==0){
                        vector<int>temp={arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        s1.insert(temp); 
                    }
                }
            }
        }
    }
    vector<vector<int>>vectr1(s1.begin(),s1.end());
    for(auto r1:vectr1){
        for(int n: r1){
            cout<< n<<" ";
        }
        cout<<"\n";
    } **/
    return 0;
}