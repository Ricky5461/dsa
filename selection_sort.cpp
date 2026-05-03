

// selection sort algorithm  
// EVERY TIME IT find minIMUM ELELEMENT FROM STARTING TO END  and place it at the begining in iterative way
// SO SORTING PERFOMR FROM LEFT TO RIGHT
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr={23,45,11,2,3,456,6};
    int mmi=0;
    for(int i=0;i<arr.size()-1;i++){
        mmi=i;
        for(int j=i;j<arr.size();j++) {
            if(arr[mmi]>arr[j]) mmi = j;
        }
        swap(arr[i],arr[mmi]);
    }
    for(int n:arr)cout<< n<<"\n";
    return 0;
}