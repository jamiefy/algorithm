#include <iostream>
#include <vector>
#include <memory>

void Merge(std::vector<int> &data,int start,int mid,int end){
    int len=end-start+1;
    auto temp=std::unique_ptr<int>(new int[len]);

    int i=start;
    int j=mid+1;
    int index=0;
    while(start+index<=end){
        if(i<=mid && (j>end || data[i]>=data[j]))
            temp.get()[index++]=data[i++];
        else
            temp.get()[index++]=data[j++];
    }

    for(int count=0;count<len;){
        data[start++]=temp.get()[count++];
    }
}

void MergeSort(std::vector<int> &data,int start,int end){
    int len=end-start+1;
    for(int gap=1;gap<=len;gap*=2){
        int index=start;
        for(;index+gap*2-1<=end;index+=gap*2){
            if(data[index+gap-1]<data[index+gap]){
                Merge(data,index,index+gap-1,index+gap*2-1);
            }
        }
        if(index+gap-1<end){
            Merge(data,index,index+gap-1,end);
        }
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