
#include <iostream>
#include <vector>

using namespace std;

void maxsum2 (vector<int> a, int n){
    int newmax =0, oldmax =-1;
    for (int i=0; i <= n-1; ++i){
        newmax += a[i];
        if ( newmax > oldmax){
            oldmax = newmax;
        } else if ( newmax < 0){
            newmax = 0;
        }
    }
    if (oldmax == -1 ){
        oldmax = 0;
    }
    cout << oldmax;
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
    maxsum2(a,n);
}


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
            high = a[i];
            oldmax = newmax;
        } else if ( newmax < 0){
            low = 0;
            newmax = 0;
        } else
            ++low;
    }
    if (oldmax == -1 ){
        oldlow = a[0];
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
/*
Sample Input:
10
-10 1 2 3 4 -5 -23 3 7 -21
Sample Output:
10 1 4
*/



