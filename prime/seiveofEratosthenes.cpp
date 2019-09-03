#include <iostream>
#include <vector>
#include <ctime>

#define MAX_VALUE 2e7

void LinearSeive(std::vector<int> &primes,std::vector<int> &is_primes,int &size){
    int count=0;
    primes.clear();
    for(int i=2;i<MAX_VALUE;i++){
        if(!is_primes[i]){
            primes.emplace_back(i);//初始化时初始化的size=0，必须向vector里插入元素才能构造元素,使用primes[count++]=i不能实现向vector里添加元素
            count++;
        }
        for(int j=0;j<count && i*primes[j]<MAX_VALUE;j++){
            is_primes[i*primes[j]]=1;
            if (i % primes[j] == 0)
                break;
        }
    }
    size=count;
}

int main() {
    int count;
    int a;
    int b;
    int case_number=1;
    std::cin>>count;
    std::vector<int> primes{0};
    std::vector<int> is_primes(MAX_VALUE+1);
    int size=0;
    LinearSeive(primes,is_primes,size);
    while(count--){
        clock_t t;
        t = clock();
        int prime=-1;
        std::cin>>a;
        std::cin>>b;
        if (a > b) {
            /*比较酷的方式，不用临时变量*/
            a = a ^ b; b = a ^ b; a = a ^ b;//一个数连续两次异或同一个值可回到原始值
        };
        for(int i=0;i<size-1;i++){
            if(!is_primes[i]){
                if(primes[i]>a && primes[i+1]>b){
                    /*如果恰好相等*/
                    if ((primes[i] - a) == (primes[i + 1] - b))
                    {
                        /*输出*/
                        prime = primes[i] - a;
                        break;
                    }
                }
            }
        }
        t=clock()-t;
        std::cout<<"case "<<case_number++<<" : "<<prime<<std::endl;
        std::cout<<"time : "<<(float)t/CLOCKS_PER_SEC;
    }
    return 0;
}
