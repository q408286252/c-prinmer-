#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    list<vector<string>> vecdata;
    vector<string> name = {"b1","b2","b3","c1","c2","c3"};

    for (auto str1 : name)
        for (auto str2 : name)
            for (auto str3 : name)
                for (auto str4 : name)
                    for (auto str5 : name)
                        for (auto str6 : name)
                            vecdata.push_back({str1,str2,str3,str4,str5,str6});
    //beg 是每个方案
    for (auto beg = vecdata.begin(); beg != vecdata.end(); ++beg){
        //删除开头c1 c2 c3
        if ((*beg)[0] != "b1" && (*beg)[0] != "b2" && (*beg)[0] != "b3" ){
            beg = vecdata.erase(beg); //删除这个迭代器元素
            --beg;  //上移一格
        //结尾必须是c
        } else if ( (*beg)[5] != "c1"
                   &&(*beg)[5] != "c2"
                   &&(*beg)[5] != "c3"
                   ){
            beg = vecdata.erase(beg);
            --beg;
        //删除元素重复的
        }else if ( 1 != count(beg->begin(), beg->end(), string("b1"))
                   || 1 != count(beg->begin(), beg->end(), "b2")
                   || 1 != count(beg->begin(), beg->end(), "b3")
                   || 1 != count(beg->begin(), beg->end(), "c1")
                   || 1 != count(beg->begin(), beg->end(), "c2")
                   || 1 != count(beg->begin(), beg->end(), "c3")
                   ){
            beg = vecdata.erase(beg);
            --beg;
        }else {
            int i = 0;  //控制i
            int siz = 0;
            siz += count(beg->begin(),(beg->begin())+3, "b1");
            siz += count(beg->begin(),(beg->begin())+3, "b2");
            siz += count(beg->begin(),(beg->begin())+3, "b3");
            //前三元素不能出现三次b1 b2 b3
            if (siz ==3){
                i += 1;
                goto en;
            }
            //begg尾每个方案的元素迭代器
            for (auto begiter = beg->begin(); begiter != (*beg).end();++begiter){
                //遇到元素c1c2c3 时 且 之前元素没有b1b2b3
                if ( (*begiter) == "c1" && begiter == find(beg->begin(), begiter, string("b1") ) ){
                    i += 1;
                    break;
                } else if (*begiter == "c2" && begiter == find(beg->begin(), begiter, "b2") ){
                    i += 1;
                    break;
                } else if (*begiter == "c3" && begiter == find(beg->begin(), begiter, "b3") ){
                    i += 1;
                    break;
                }
            }
            en:
            if (i != 0){
                beg = vecdata.erase(beg);
                --beg;
                i = 0;
            }
        }
    }
    ofstream out("data.txt",ofstream::app);
    //显示剩下方案:
    for (auto i : vecdata)
        out << i[0] << " " << i[1] << " " << i[2] << " " << i[3] << " " << i[4] << " " << i[5] << endl;
}
