#include <iostream>
#include <time.h>

void Merge(int a[],int start,int mid,int end){
    int len=end-start+1;
    int* temp=new int[len];

    int i=start;//注意赋值i=start而不是0
    int j=mid+1;
    int index=0;
    while(index+start<=end){
        if(i<=mid && (j>end || a[i]<=a[j]))//j>end而不是j>=end
            temp[index++]=a[i++];
        else
            temp[index++]=a[j++];
    }

    for(int count=0;count<len;){
        a[start++]=temp[count++];
    }
}

void MergeSort(int a[],int start,int end){
    if(start<end){
        int len=end-start+1;
        for(int gap=1;gap<len;gap*=2){
            int index=start;
            for(;index+gap*2-1<=end;index+=gap*2){//index+gap*2-1<=end而不是index+gap*2-1<end
                if(a[index+gap-1]>a[index+gap])//index+gap-1而不是index+gap
                    Merge(a,index,index+gap-1,index+gap*2-1);//index+gap-1而不是index+gap
            }
            if(index+gap-1<end){
                Merge(a,index,index+gap-1,end);//index+gap-1而不是index+gap
            }
        }

    }
}

int main() {
    int a[10]={1,4,2,6,3,7,5,9,8,0};
    clock_t startTime=clock();
    MergeSort(a,0,9);
    for(int i=0;i<10;i++)std::cout<<i<<":"<<a[i]<<std::endl;
    clock_t endTime=clock();
    std::cout<<"running time is: "<< static_cast<double>(endTime-startTime)/CLOCKS_PER_SEC*1000<<std::endl;
}