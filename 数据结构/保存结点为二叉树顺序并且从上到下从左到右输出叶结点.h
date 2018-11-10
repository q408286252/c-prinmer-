#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};

int f2(Node ne,int i){
    if (ne.left == NULL || ne.right == NULL)    //左右都空时
        return i;
    if(ne.left != NULL || ne.right != NULL)     //左右不空时
        return (f2(*ne.left,++i) >= f2(*ne.right,i)) ? f2(*ne.left,i) : f2(*ne.right,i);
    if (ne.left == NULL)
        return f2(*ne.right,++i);
    else
        return f2(*ne.left,++i);
}

void f3(Node ne){
    //cout << "经过的结点" << ne.data << "\n";
    vector<int> vec;
    deque<Node> dqe;
    dqe.push_back(ne);
    while (dqe.size() !=0){
        ne = dqe[0];
        dqe.pop_front();
        if (ne.left == NULL && ne.right == NULL)
            vec.push_back(ne.data);
        if(ne.left ){
            dqe.push_back(*ne.left);
        }
        if(ne.right ){
            dqe.push_back(*ne.right);
        }
    }
    for(auto beg = vec.begin(); beg != vec.end()-1; ++beg)
        cout << *beg << ' ';
    cout<< vec[vec.size()-1];
}

void f(vector<Node> veca){
    int sz,maxa=-1,i_new;
    vector< pair< int,pair<int,int> > > vecb((int)veca.size());
    for (int i=0; i<veca.size(); ++i){
        //cout << "第" << i << "循环" << "   ";
        sz = f2(veca[i],0);
        if(maxa < sz){
            maxa = sz;
            i_new = i;
            //cout << i_new << "\n";
        }
    }
    f3(veca[i_new]);
}

int main(){
    char a1, a2;
    int n, numb=0, i1, i2;
    cin >>n;
    vector<Node> veca(n);
    for (int i=0; i<n ;++i){
        cin >> a1 >> a2;
        veca[i].data = i;
        if(a1 =='-')
            veca[i].left = NULL;
        else{
            veca[i].left = & veca[(int)(a1-'0')];
        }
        if(a2 =='-')
            veca[i].right = NULL;
        else{
            veca[i].right = &veca[(int)(a2-'0')];
        }
    }
    if(n>0)
        f(veca);
}

/*
题目
03-树2 List Leaves （25 分）
Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:
For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
4 1 5
*/
