#include <iostream>
#define NUMBER 100000
using namespace std;

void MaxSum4(int A[], int N) {
    int ThisSum, MaxSum;
    int i;
    int a=0, b=0, n=0; https:// ¼ÇÂ¼×ø±ê
    ThisSum = 0;
    MaxSum = A[0];
    for (i = 0; i < N; i++) {
        ThisSum += A[i];
        if (ThisSum > MaxSum) {
            MaxSum = ThisSum;
            b = i;
            a = n;
        }
        else if (ThisSum < 0) {
            ThisSum = 0;
            n = i + 1;
        }
    }

    if (MaxSum < 0) {
        cout  << "0 ";
        cout << A[0] << ' ' << A[N-1];
    }else {
        cout << MaxSum << ' ';
        cout << A[a] << ' ' << A[b];
    }
}

int main()
{
    int n, i;
    cin >> n;
    int A[NUMBER];
    for (i = 0; i < n; i++)
        cin >> A[i];

    MaxSum4(A, n);

    return 0;
}
