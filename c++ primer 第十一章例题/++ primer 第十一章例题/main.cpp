#include <iostream> //���������
#include <string>   //�ַ����ļ�
#include <cctype>   //�����ַ��ж�(�Ƿ��Ƿ��� ���� ��� ��ĸ�� ʲô��.)�����Ŀ�
#include <vector>   //���ɶ�������� �׳��б�
#include <cstring>  //�ṩC���Ա�׼���һЩ����
#include <fstream>  //�ļ�IO
#include <sstream>  //strIO
#include <list>     // ˫���� ����
#include <forward_list> //����������
#include <deque>    // ˫��vector����
#include <array>    //�̶����� array
#include <stack>    //ջ������stack
#include <queue>    //���������� ����: priority_queue �� queue;
#include <algorithm>    //�󲿷��㷨����
#include <iterator> //���ֵ�����  ��������� ��������;���������;�ƶ�������;
#include <functional>   //��bind����;  ref(os) ����һ������ɿ�������   cref(os)��������ɿ���const����
#include <map>  //��Ӧֵ����
#include <set>  //�ؼ�������
#include <unordered_map>    //�����Ӧֵ����
#include <unordered_set>    //����ؼ�������

#include "Sales_data.h"
#include "Sales_item.h"

using namespace std;

int main()
{
    vector<int> vec = {0,1,2,3,4,5,6,1,2,3};
    sort(vec.begin(),vec.end());
    auto iter = unique(vec.begin(),vec.end());
    vec.erase(iter, vec.end());
    for (auto i : vec)
        cout << i << endl;
}
    /*
    map<string, size_t> word_count;
    set<string> exclude =  {"111","222","333"};
    string word;
    while (cin>> word)
        //���ֻͳ��111 222 333֮���string����
        if (exclude.find(word) == exclude.end() )   //�ڹؼ�����������ͬ���ؼ��� ����յ�������:
            ++word_count[word];
    for (const auto &w : word_count)
        cout << w.first << "��" << w.second << ((w.second > 1) ? "times" : "time" ) << endl;
    */


/*
//11.8
    vector<int> vec = {0,1,2,3,4,5,6,1,2,3};
    sort(vec.begin(),vec.end());
    auto iter = unique(vec.begin(),vec.end());
    vec.erase(iter, vec.end());
    for (auto i : vec)
        cout << i << endl;
    //�ŵ������ ������Ҫд4������ ��setһ�о��� ����vector��Ԫ�������������.ɾ���ظ����ǳ���.


//11.7      //������ûд��ô����mapԪ��.... ��Ҫ��д���Ԫ��...
    map<string, vector<string>> demo= {{"yang",{"rui","niu"} },{"yu",{"rui","niu"} } };
    demo.insert({"nana",{"ni","hao"}});


//11.6
    set��list����̫���� ��һlist��������ʽ��ÿԪ����˳������,�ұ��,���ظ�
    ��set �����ظ�,����������ʽ��.


//11.5
    //����� map�ںܶ���Ҫ���Һܶ���Ϣʱ��ʹ�÷ǳ��� ��set����Ψһ���ںܶ಻���ظ�����Ǻ��õ�.



//11.4
    map<string, size_t> word;
    string s;
    while(cin >> s){
        s[0] = tolower(s[0]);
        for (size_t i =0; i <= s.size(); ++i){  //������д!= Ȼ��������û�ҳ���.....
            if(s[i] == '.' || s[i] == ',')
                s = s.erase(i,1);
        }
        ++word[s];
    }
    for (auto &i : word)
        cout << "����" << i.first << "�Ĵ���Ϊ:" << i.second << endl;



//11.3
map<string, size_t> word;
    string s;
    while(cin >> s)
        ++word[s];
    for (auto &i : word)
        cout << "����" << i.first << "�Ĵ���Ϊ:" << i.second << endl;



//11.2
    list    ��ʱ�齨��ģС����֯�������ɾ��
    vector  һЩ��¼; ��¼��Զ���沢��˳��̶�
    deque   �Ŷ�����ֻ��β��Ӻ� ��ɾ��
    map     ��¼ĳЩ�������ִ�����, ���֤������; ÿ����Ա��¼��;
    set     ������Զ���ظ��Ķ��������֤



//11.1
    ��ͬ���� map��ͬʱ������������ֵ; ��vectorֻ�ܱ���һ��
    vector��˳�򱣴� ��map����˳���������;
    vector��Ԫ��ֵ������ͬ��ͬ, ��map��������ֻ�ܲ�ͬ;


*/
