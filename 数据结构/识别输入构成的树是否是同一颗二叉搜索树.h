
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
    if( !BST ){ /* 若原树为空，生成并返回一个结点的二叉搜索树 */
        //cout<< "空运行了一次\n";
        BST = (Node*)malloc(sizeof(Node));
        BST->Data = X;
        BST->Left = NULL;
        BST->Right = NULL;
    }
    else { /* 开始找要插入元素的位置 */
        //cout << "运行了插入的else一次\n";       //````
        if( X < BST->Data ){
            //cout << "运行了插入的else的if一次\n";        //````
            BST->Left = Insert( BST->Left, X );   /*递归插入左子树*/
        }else  if( X > BST->Data ){
            //cout << "运行了插入的else的else一次\n";
            BST->Right = Insert( BST->Right, X ); /*递归插入右子树*/
        /* else X已经存在，什么都不做 */
        }
    }
    return BST;
}
bool f(Node* BST1, Node* BST2){
    if (!BST1 && !BST2)     //都为空
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
            if ( f(vec[0],vec[i]) )  //这里写的不对 可以用一个函数比较
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
04-树4 是否同一棵二叉搜索树 （25 分）
给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:
Yes
No
No

*/
