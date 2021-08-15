#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
    //控制cout的显示精度
    //1.强制以小数方式显示
    cout << fixed ;
    //2.控制显示的精度
    cout << setprecision(2);//()里数字表示小数点都显示的数字位数
    //输出double类型数据
    double doubleNum = 100.0/3.0;

    cout << doubleNum * 1000000 << endl;

    return 0;
}
