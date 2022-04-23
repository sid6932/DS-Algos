#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int n,m,k,t;
    cin >> n >> m >> k >> t;
    int x;
    int y;
    vector<pair<int,int>> v;
    while(k--){
        cin >> x >> y;
        v.push_back({x,y});
    }
    
    sort(v.begin(),v.end());
    for(auto i : v){
        cout << i.first << " " << i.second << endl;
    }
    while(t--){
        cin >> x >> y;
        int count = 0;
        int flag  =0;
        for(auto i : v){
            if(x==i.first && y == i.second){
                flag = 1;
            }
            if(m*(x-1)+y < m*(i.first-1)+i.second ){
                break;
            }
            count++;
        }
        if(flag == 1){
            cout << "Waste" << endl;
            continue;
        }
        int tile = m*(x-1)+y;
        tile = tile - count;
        tile = tile%3;
        if(tile == 0){
            cout << "Grapes" << endl;
        }
        else if(tile == 1){
            cout << "Carrots" << endl;
        }
        else{
            cout << "Kiwis" << endl;
        }
    }

    return 0;
}
