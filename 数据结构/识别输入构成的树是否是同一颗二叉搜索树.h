
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node{
    int Data;
    Node *Left, *Right;
};
cout endl;
Node* Insert( Node* BST, int X )
{
    //cout << BST;            //````
    if( !BST ){ /* ��ԭ��Ϊ�գ����ɲ�����һ�����Ķ��������� */
        //cout<< "��������һ��\n";
        BST = (Node*)malloc(sizeof(Node));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else { /* ��ʼ��Ҫ����Ԫ�ص�λ�� */
        //cout << "�����˲����elseһ��\n";       //````
        if( X < BST->Data ){
            //cout << "�����˲����else��ifһ��\n";        //````
            BST->Left = Insert( BST->Left, X );   /*�ݹ����������*/
        }else  if( X > BST->Data ){
            //cout << "�����˲����else��elseһ��\n";
            BST->Right = Insert( BST->Right, X ); /*�ݹ����������*/
        /* else X�Ѿ����ڣ�ʲô������ */
        }
    }
    return BST;
}
bool f(Node* BST1, Node* BST2){
    if (!BST1 && !BST2)     //��Ϊ��
        return true;
    else if (BST1 && BST2){
        if (BST1->Data == BST2->Data){
            if ( f(BST1->Left, BST2->Left) && f(BST1->Right, BST2->Right) )
                return true;
            else
                return false;
        }else
            return false;
    }else
        return false;
}

int main(){
    int ia, ib,dataint;
    vector<string> vecstr;
    while (true){
        cin >> ia;
        //cout << ia << "\n";     //````
        if(ia ==0)
            break;
        cin >> ib;
        //cout << ib << "\n";     //````
        vector<Node*> vec(ib+1);
        for(int ilow=0; ilow<ib+1; ++ilow){
            for(int i=0; i < ia; ++i){
                cin >> dataint;
                //cout << "ia=" << ia <<"  ib=" << ib << "dataint=" <<dataint << "\n" ;    //````
                vec[ilow] = Insert(vec[ilow],dataint);
            }
        }
        for(int i=1; i <ib+1; ++i){
            if ( f(vec[0],vec[i]) )  //����д�Ĳ��� ������һ�������Ƚ�
                vecstr.push_back("Yes");
            else
                vecstr.push_back("No");
        }
    }
    for(int i=0; i<vecstr.size(); ++i){
        if (i == vecstr.size()-1)
            cout << vecstr[i];
        else
            cout << vecstr[i] << "\n";
    }
}

/*
04-��4 �Ƿ�ͬһ�ö��������� ��25 �֣�
����һ���������оͿ���Ψһȷ��һ�ö�����������Ȼ����һ�ø����Ķ���������ȴ�����ɶ��ֲ�ͬ�Ĳ������еõ�������ֱ�������{2, 1, 3}��{2, 3, 1}�����ʼΪ�յĶ��������������õ�һ���Ľ�������Ƕ�������ĸ��ֲ������У�����Ҫ�ж������Ƿ�������һ���Ķ�����������

�����ʽ:
�������������������ݡ�ÿ�����ݵĵ�1�и�������������N (��10)��L���ֱ���ÿ�����в���Ԫ�صĸ�������Ҫ�������и�������2�и���N���Կո�ָ�������������Ϊ��ʼ�������С����L�У�ÿ�и���N�������Ԫ�أ�����L����Ҫ�������С�

����������Ǳ�֤ÿ���������ж���1��N��һ�����С�������NΪ0ʱ����־����������������ݲ�Ҫ����

�����ʽ:
��ÿһ����Ҫ�������У���������ɵĶ�������������Ӧ�ĳ�ʼ�������ɵ�һ���������Yes�������������No����

��������:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
�������:
Yes
No
No

*/
