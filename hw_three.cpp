#include <iostream>
int main()
{
    int a,b,summa(0);
    std::cin>>a;
    for(int i=1;i<=a/2;i++){ 
        b=0;
        if(a%i==0){ 
            for(int j=1;j<=i;j++) 
            if(i%j==0)b++; 
            if(b==2)summa+=i; 
        }
    }
    std::cout<<summa; 
}
