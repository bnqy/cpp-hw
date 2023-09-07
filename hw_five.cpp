#include<iostream>
#include <ctime>
 
struct Qatar 
{
    int i;
    Qatar *vevo;
};
 
Qatar *bashy = 0; 
 
 
void set(int i)
{
    Qatar *sandyk = new Qatar; 
    sandyk->i=i;
    sandyk->vevo = NULL;
    
    if(bashy==0)
    {
        bashy = sandyk;
    }
}
 
void print()
{
    Qatar *es0 = bashy;
    while (es0 != 0)
    {
        std::cout <<es0->i<<" "; 
        es0=es0->vevo; 
    }
    std::cout << "\n";
}
 
void set_bashy(int randsan)
{
    Qatar *es = new Qatar; 
    es->i = randsan; 
    es->vevo = bashy; 
    bashy = es; 
}
 
int main()
{
   
    srand(time(0));

    
    set(rand()%9); 
    std::cout << "Сап ---:  ";      
    print(); 
 
    
 
    set_bashy(rand()%9); 
    std:: cout << "Саптын башына рандом сан кошулгандан кийин ---: ";
    print(); 
    
    
    return 0;
}
