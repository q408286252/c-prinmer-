#include <iostream>
#include <vector>

using namespace std;

void maxsum (vector<int> a, int n){
    int newmax =0, oldmax =-1, oldlow, low =0, high = 0;
    for (int i=0; i <= n-1; ++i){
        newmax += a[i];
        if ( newmax > oldmax){
            oldlow = a[i-low];
            ++low;
            cout << oldlow << "\n";
            high = a[i];
            oldmax = newmax;
        } else if ( newmax < 0){
            low = 0;
            newmax = 0;
        } else
            ++low;
    }
    if (oldmax == -1 ){
        low = a[0];
        high = a[n-1];
        oldmax = 0;
    }
    cout << oldmax << ' ' << oldlow << ' ' << high;
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    int i;
    for (int l=1; l <= n; ++l){
        cin >> i;
        a.push_back(i);
    }
    maxsum(a,n);
}


