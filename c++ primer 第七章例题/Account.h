class Account{
public:
    int read(int = bookno);
    int bookna = bookno;
private:
    static const int bookno = 30;
    //  static Bar book;  ���� ����� �ҵı�������֧�� ��̬����д��δ��������.
};
int Account::read(int inta){
    return inta*inta;
}

