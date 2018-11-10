//最好的.
string longestPalindrome2(string s) {
        int iLen((int)s.length());
        if(s.empty()){
            return "";
        }
        if(iLen == 1){
            return s;
        }
        int iStart(0);
        int iMaxLen(1);
        for(int i = 0; i < iLen; /*++i*/){
            if(iLen - i <= iMaxLen / 2){    //中心值i未知小于 最长值/2 时候就没必要继续检测了.
                break;
            }
            int iLeft(i);   //初始化
            int iRight(i);  //初始化
            while(iRight < iLen - 1 && s.at(iRight) == s.at(iRight + 1)){
                ++iRight;   //右侧下个相同值相同则右侧增加;       就是找中心值;
            }
            i = iRight + 1; //i右侧更新;
            while(iRight < iLen - 1 && iLeft > 0 && s.at(iLeft - 1) == s.at(iRight + 1)){   //右侧没超, 左侧大于0,  左侧左值==右侧右值 则继续;
                --iLeft;
                ++iRight;
            }
            int iNewLen(iRight - iLeft + 1);   //iNewLen 为最大长度; 如果大于max更新
            if(iNewLen > iMaxLen){
                iStart = iLeft;
                iMaxLen = iNewLen;
            }
        }
        return s.substr(iStart, iMaxLen);
    }
//我写的
string longestPalindrome(string s) {
    if (s == "")
        return s;
    int maxlow,maxlen=-1;
    for (int hight=s.size()-1; s[hight] != '\0';--hight){    //总循环
        if (maxlen < hight+1){  //首先剩下范围必须比纪录的值大
            for (int low=0;low <= hight && maxlen < hight-low+1; ++low){  //循环中maxlen 大于 剩下循环次数则取消循环;
                if (s[hight] == s[low]){    //找到第一个相同值纪录
                    string s1(s,low,hight-low+1), s2(s1.rbegin(),s1.rend());
                    if ( s1 == s2){
                        maxlow = low;
                        maxlen = hight-low+1;
                        break;
                    }
                }
            }
        }
    }
    string ss(s,maxlow,maxlen);
    return ss;
}
int main()
{
    string s = "asdfghjklkjhgfdsaa";
    cout << longestPalindrome2(s);
}
/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"
*/
