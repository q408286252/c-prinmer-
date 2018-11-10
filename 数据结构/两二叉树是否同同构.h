#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void f(vector< pair<char,pair<char,char>>> &veca, vector< pair<char,pair<char,char>>> &vecb){
    for (int i=0; i<veca.size(); ++i){
        if (veca[i].second.first == '-')
            ;
        else
            veca[i].second.first =  veca[(int)(veca[i].second.first-'0')].first;
        if (veca[i].second.second =='-')
            ;
        else
             veca[i].second.second =  veca[(int)(veca[i].second.second-'0')].first;
    }
    for (int i=0; i<vecb.size(); ++i){
        if (vecb[i].second.first == '-')
            ;
        else
            vecb[i].second.first =  vecb[(int)(vecb[i].second.first-'0')].first;
        if (vecb[i].second.second =='-')
            ;
        else
             vecb[i].second.second =  vecb[(int)(vecb[i].second.second-'0')].first;
    }
}

void f2(vector< pair<char,pair<char,char>>> &veca, vector< pair<char,pair<char,char>>> &vecb){
    int i=0;
    for (auto bega=veca.begin(); bega != veca.end(); ++bega)
        for (auto begb=vecb.begin(); begb != vecb.end(); ++begb)
            if( bega->first == begb->first)
                if ( (bega->second.first == begb->second.first
                        || bega->second.first == begb->second.second
                        ) && (
                        bega->second.second == begb->second.first
                        || bega->second.second == begb->second.second
                        ))
                    ++i;
    if(i==veca.size())
        cout << "Yes";
    else
        cout << "No";
}

int main(){
    char s, a1, a2;
    int n, n2;
    vector< pair< char,pair<char,char> > > veca,vecb;
    pair<char,char> pa;
    cin >>n;
    for (int i=0; i<n ;++i){
        cin >> s >> a1 >> a2;
        pa = {a1,a2};
        veca.push_back({s,pa});
    }
    cin >>n2;
    for (int i=0; i<n2 ;++i){
        cin >> s >> a1 >> a2;
        vecb.push_back({s,{a1,a2}});
    }
    if(n == n2 && n2 == 0)
        cout << "Yes";
    else if(n == n2 && n>0 && n2>0){
        f(veca,vecb);
        f2(veca,vecb);
    }else
        cout << "No";
}

/*
输入:
8                   结点数
A 1 2               第一个结点名 和 儿子左右编号
B 3 4               之后同理
C 5 -
D - -
E 6 -
G 7 -
F - -
H - -
8                   结点数
G - 4               第一个结点名 和 儿子左右编号
B 7 6               之后同理
F - -
A 5 1
H - -
C 0 -
D - -
E 2 -
输出
Yes
