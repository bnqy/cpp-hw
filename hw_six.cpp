#include <iostream>
#include <set>
#include <queue>

std::set<int>set; 
std::queue<int>kezek; 
int main(){
    int sandar; 
    int sandarSany; 
    int ex;
    std::cin >> sandarSany; 
    for(int i = 1; i <= sandarSany; i++){
        std::cin >> sandar; 
        ex = set.count(sandar); 
        if(ex == 0){kezek.push(sandar); set.insert(sandar);} 
    }
    while(!kezek.empty()){ 
        std::cout << kezek.front() << " "; 
        kezek.pop(); 
    }
}
