#include <iostream>//数据输入输出流
#include <string.h>//字符串操作函数
#include <stdio.h>//C的输入输出
#include <stdlib.h>//定义杂项函数及内存分配函数
#include <math.h>//C中的数学函数
#include <string.h>//c++中的string类 他不能用strcpy等c函数去操作
#include <vector>//STL vetor容器
#include <list>//STL list
#include <map>// STL map
#include <queue>// STL queue
#include <set>// STL set
#include <stack>//sTL stack
#include <bitset>//bitset可按位定义串
//比如：bitset <1000> all;定义一个1000位的串
#include <algorithm>//STL各种算法 比如 swap sort merge max min 比较
#include <numeric>//常用数字操作 一般和algorithm搭配使用
#include <functional>//STL定义运算函数（代替运算符）
#include <climits>
#include <cfloat>
#define N 1000005
using namespace std;

map<int ,int> valueMap;
//bool f( int x ){ if( x <0 || x > N-5 || b[x] ) return false; return true;}
bool f(int x)
{
    if(x  >  100 || x < -100)
    {
        //if(valueMap.find(x) != valueMap.end())
          return false;
    }
    else{
        if(valueMap.find(x) != valueMap.end())
          return false;
    }
    return true;
}
void bfs( int n, int m )
{
    queue< int > a;
    a.push( n );
    while( a.size() )
    {
        int k = a.front();
        cout<<"k = "<<k<<"\n";
        a.pop();
        if( k == m )break;
        if( f( k-1) )
        {
            a.push( k-1 );
            //b[k-1] = b[k] + 1;
            valueMap[k-1] = valueMap[k] + 1;
        }
        if( f(k+1) )
        {
            a.push( k+1 );
            //b[k+1] = b[k] + 1;
            valueMap[k+1] = valueMap[k] + 1;
        }
        if( f( k*2 ) )
        {
            a.push( k*2 );
           // b[k*2] = b[k] + 1;
            valueMap[k*2] = valueMap[k] + 1;
        }
    }
}
int main()
{
    while(true){
            char *sp;
    sp = (char *)malloc(sizeof(char));
    gets(sp);
    string str = "";
    int tmp;
    int n, m;
    int len = strlen(sp);
    int start = 0;
    for(int i = 0; i < len; i++){
            str += sp[i];
           if(sp[i] == ','){
                tmp = atoi(str.c_str());
                str = "";
                n = tmp;
        }
    }
    m = atoi(str.c_str());
    //cout<<n<<"   "<< m;
   // memset( b, 0, sizeof(b) );
    valueMap[n] = 0;
    bfs( n, m );
    cout << valueMap[m] << "\n";
    valueMap.erase(valueMap.begin() , valueMap.end());
    //memset( b, 0, sizeof(b) );
    }
   return 0;
}
