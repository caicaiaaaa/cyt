#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
    //����cout����ʾ����
    //1.ǿ����С����ʽ��ʾ
    cout << fixed ;
    //2.������ʾ�ľ���
    cout << setprecision(2);//()�����ֱ�ʾС���㶼��ʾ������λ��
    //���double��������
    double doubleNum = 100.0/3.0;

    cout << doubleNum * 1000000 << endl;

    return 0;
}
