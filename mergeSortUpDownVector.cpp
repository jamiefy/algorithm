#include <iostream>
#include <vector>
#include <memory>

void Merge(std::vector<int> &data,int start,int end){
    int mid=(start+end)/2;
    int leftLen=mid-start+1;
    int rightLen=end-mid;

    auto left=std::shared_ptr<int>(new int[leftLen],[](int *p){delete []p;});
    auto right=std::shared_ptr<int>(new int[rightLen],[](int *p){delete []p;});

    for(int i=0;i<rightLen;i++){
        left.get()[i]=data[start+i];
    }
    for(int j=0;j<rightLen;j++){
        right.get()[j]=data[mid+1+j];
    }

    int i=0,j=0,count=start;
    while(i<rightLen && j<rightLen){
        if(left.get()[i]>=right.get()[j])
            data[count++]=left.get()[i++];
        else
            data[count++]=right.get()[j++];
    }
    while(i<leftLen) data[count++]=left.get()[i++];
    while(j<rightLen) data[count++]=right.get()[j++];
}

void MergeSort(std::vector<int> &data,int start,int end){
    if(start<end){
        int mid=(start+end)/2;
        MergeSort(data,start,mid);
        MergeSort(data,mid+1,end);
        Merge(data,start,end);
    }
}

int main(){
    int N;
    int element;
    std::cin>>N;
    while(N){
        std::vector<int> data;
        while(N--){
            std::cin>>element;
            data.emplace_back(element);
        }
        MergeSort(data,0,data.size()-1);
        for(auto it=data.begin();it!=data.end();it++){
            std::cout<<*it<<' ';
        }
        std::cout<<std::endl;
        std::cin>>N;
    }
}

