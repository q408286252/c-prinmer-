
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int compare(int a, int b){
    if (a > b)
        return 1;
    else if ( a < b)
        return -1;
    else
        return 0;
}

vector<pair<int,int>> cinpairs (int n){
    vector<pair<int,int>> vec;
    for (int ls=0; ls <= 2*n-1;++ls){
        int i,pairfirst;
        cin >> i;
        if (i > 1000 && i < -1000){
            cin>>i;
            ++ls;
        }else if ( ls %2 == 0)
            pairfirst = i;
        else{
            vec.push_back({pairfirst,i});
        }
    }
    sort(vec.begin(), vec.end(),
         [](const pair<int,int> &paira, const pair<int,int> &pairb){return paira.second > pairb.second;});
    for (auto beg = vec.begin(); beg != vec.end(); ++beg){
        if (beg != vec.end()-1)
            if (beg->second == (beg+1)->second ){
                (beg+1)->first = beg->first + (beg+1)->first;
                beg = vec.erase( beg );
                --beg;
            }
    }
    return vec;
}

void algorithm (vector<pair<int,int>> pairs, vector<pair<int,int>> pairs2){
    vector<pair<int,int>> vec;
    for (auto bega = pairs.begin(); bega != pairs.end();++bega)
        for (auto begb = pairs2.begin(); begb != pairs2.end();++begb)
            vec.push_back({ (bega->first) * (begb->first), (bega->second) + (begb->second)});
    sort(vec.begin(), vec.end(),
         [](const pair<int,int> &paira, const pair<int,int> &pairb){return paira.second > pairb.second;});
    for (auto beg = vec.begin(); beg != vec.end(); ++beg){
        if (beg != vec.end()-1)
            if (beg->second == (beg+1)->second ){
                (beg+1)->first = beg->first + (beg+1)->first;
                beg = vec.erase( beg ) -1;
            }
        if (beg->first == 0)
            beg = vec.erase(beg) -1;
    }
    if (vec[0].first ==0 & vec[0].second ==0)
        cout << 0 << ' ' << 0;
    else
        for (auto beg = vec.begin(); beg != vec.end(); ++beg)
            if (vec.begin() == beg){
                cout << beg->first << ' ' << beg->second ;
            } else
                cout << ' ' << beg->first << ' ' << beg->second ;
}

void algorithm2 (vector<pair<int,int>> pairs, vector<pair<int,int>> pairs2){
    vector<pair<int,int>> vec;//����ù�ʽ
    int maxa = pairs.size(), maxb = pairs2.size();//������Ԫ��ֵ
    int ia=0,ib=0;
    for (; ia<=maxa-1 &&ib <=maxb-1;){
        switch( compare(pairs[ia].second , pairs2[ib].second) ){
            case 1:
                vec.push_back(pairs[ia++]);
                break;
            case -1:
                vec.push_back(pairs2[ib++]);
                break;
            case 0:
                vec.push_back({pairs[ia].first+pairs2[ib++].first, pairs[ia++].second});
                break;
        }
    }
    for(;ia <=maxa-1;++ia)
        vec.push_back(pairs[ia]);
    for(;ib <=maxb-1;++ib)
        vec.push_back(pairs2[ib]);
    sort(vec.begin(), vec.end(),
         [](const pair<int,int> &paira, const pair<int,int> &pairb){return paira.second > pairb.second;});
    for (auto beg = vec.begin(); beg != vec.end(); ++beg){
        if (beg != vec.end()-1)
            if (beg->second == (beg+1)->second ){
                (beg+1)->first = beg->first + (beg+1)->first;
                beg = vec.erase( beg ) -1;
            }
        if (beg->first == 0)
            beg = vec.erase(beg) -1;
    }
    if (vec[0].first ==0 & vec[0].second ==0)
        cout << 0 << ' ' << 0;
    else
        for (auto beg = vec.begin(); beg != vec.end(); ++beg)
            if (vec.begin() == beg){
                cout << beg->first << ' ' << beg->second ;
            } else
                cout << ' ' << beg->first << ' ' << beg->second ;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> pairs(cinpairs(n));
    cin >> n;
    vector<pair<int,int>> pairs2(cinpairs(n));
    algorithm(pairs,pairs2);
    cout  << "\n";
    algorithm2(pairs,pairs2);
}

/*
�����ʽ:
�����2�У�ÿ�зֱ��ȸ�������ʽ������ĸ���������ָ���ݽ���ʽ����һ������ʽ������ϵ����ָ��������ֵ��Ϊ������1000�������������ּ��Կո�ָ���

�����ʽ:
�����2�У��ֱ���ָ���ݽ���ʽ����˻�����ʽ�Լ��Ͷ���ʽ�������ϵ����ָ�������ּ��Կո�ָ�������β�����ж���ո������ʽӦ���0 0��

��������:
4 3 4 -5 2  6 1  -2 0
3 5 20  -7 4  3 1
�������:
15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/
