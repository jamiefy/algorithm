#include <iostream>
#include <vector>

void Sink(std::vector<int> &data,int k,int len){
    data[0]=data[k];
    for(int i=2*k;i<=len;){
        if(data[i]<data[i+1] && i+1<=len)i++;//注意是i+1<=len而不是i+1<len，因为len+1是数组长度，最大数组坐标是len
        if(data[0]>data[i]) break;
        data[k]=data[i];
        k=i;
        i=2*k;
    }
    data[k]=data[0];
}

void MaxHeapSort(std::vector<int> &data,int len) {
    int buildHeapCount=len/2;

    while(buildHeapCount){
        Sink(data,buildHeapCount--,len);
    }

    while(len){
        data[0]=data[1];
        data[1]=data[len];
        data[len--]=data[0];

        Sink(data,1,len);
    }
}

int main() {
    int N;
    int element;
    std::cin >> N;
    while(N) {
        std::vector<int> data{0};
        for (int i = 1; i <= N; i++) {
            std::cin >> element;
            data.emplace_back(element);
        };

        MaxHeapSort(data, N);
        data.erase(data.begin());

        for (auto it = data.rbegin(); it != data.rend(); it++)
            std::cout << *it << ' ';

        std::cout<<std::endl;
        std::cin >> N;
    }
}