#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#include <stack>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <list>
#define forn(i,n) for(int i=0;i<int(n);i++)
#define io ios_base::sync_with_stdio(false);  cin.tie(NULL);
#define ll long long
#define nl "\n"
using namespace std;





int main(){
	 int n;
    cin >> n;
    int arr[n];
    forn(i,n){
        cin >> arr[i];
    }
    int left = 0;
    int right = 0;
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            left = i;
            break;
        }
    }
    for(int i=left;i<n-1;i++){
        if(arr[i] < arr[i+1]){

            right = i;
            break;
        }
    }
    if(right == 0 && arr[n-2] > arr[n-1]){
        right= n-1;
    }
    reverse(arr+left,arr+right+1);
    cout << nl;
    int flag =1;
    for(int i=0;i<n-1;i++){
        if(arr[i] > arr[i+1]){
            flag = 0;
            break;
        }
     }

     if(flag == 0){
         cout << "no" << nl;
     }
     else{
         cout << "yes" << nl;
         cout << left+1 << " " << right+1;
     }

	}










