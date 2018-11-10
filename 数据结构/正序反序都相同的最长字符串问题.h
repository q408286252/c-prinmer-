//��õ�.
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
            if(iLen - i <= iMaxLen / 2){    //����ֵiδ֪С�� �ֵ/2 ʱ���û��Ҫ���������.
                break;
            }
            int iLeft(i);   //��ʼ��
            int iRight(i);  //��ʼ��
            while(iRight < iLen - 1 && s.at(iRight) == s.at(iRight + 1)){
                ++iRight;   //�Ҳ��¸���ֵͬ��ͬ���Ҳ�����;       ����������ֵ;
            }
            i = iRight + 1; //i�Ҳ����;
            while(iRight < iLen - 1 && iLeft > 0 && s.at(iLeft - 1) == s.at(iRight + 1)){   //�Ҳ�û��, ������0,  �����ֵ==�Ҳ���ֵ �����;
                --iLeft;
                ++iRight;
            }
            int iNewLen(iRight - iLeft + 1);   //iNewLen Ϊ��󳤶�; �������max����
            if(iNewLen > iMaxLen){
                iStart = iLeft;
                iMaxLen = iNewLen;
            }
        }
        return s.substr(iStart, iMaxLen);
    }
//��д��
string longestPalindrome(string s) {
    if (s == "")
        return s;
    int maxlow,maxlen=-1;
    for (int hight=s.size()-1; s[hight] != '\0';--hight){    //��ѭ��
        if (maxlen < hight+1){  //����ʣ�·�Χ����ȼ�¼��ֵ��
            for (int low=0;low <= hight && maxlen < hight-low+1; ++low){  //ѭ����maxlen ���� ʣ��ѭ��������ȡ��ѭ��;
                if (s[hight] == s[low]){    //�ҵ���һ����ֵͬ��¼
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
����һ���ַ��� s���ҵ� s ����Ļ����Ӵ�������Լ��� s ����󳤶�Ϊ1000��

ʾ�� 1��

����: "babad"
���: "bab"
ע��: "aba"Ҳ��һ����Ч�𰸡�
ʾ�� 2��

����: "cbbd"
���: "bb"
*/
