6、输入n,求你！末尾的第一个非零数字
#include<cstdio>
using namespace std;
int main0()
{
    int n,i;
    long long s;
    while(scanf("%d",&n)!=EOF)
    {
        if(n <= 0){
            printf("%d\n",0);
        }else{
            s=1;
            for(i=2;i<=n;i++){
                s*=i;
                while(s%10==0)s/=10;
                    s=s%100000;
            }
            printf("%lld\n",s%10);
        }
    }
    return 0;
}
