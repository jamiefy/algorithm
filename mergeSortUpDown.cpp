#include <iostream>
#include <memory>
#include <time.h>

void Merge(int a[],int low,int high){
    int mid=(high+low)/2;
    int leftLen=mid-low+1;
    int rightLen=high-mid;

//    int *left=new int[leftLen];
//    int *right=new int[rightLen];
    std::shared_ptr<int> left=std::shared_ptr<int>(new int(leftLen),[](int *p){delete []p;});//要构造deleter删除器，不然得话只能实现delete p;而不是delete []p,内存不能完全释放
    std::shared_ptr<int> right=std::shared_ptr<int>(new int(rightLen),[](int *p){delete []p;});//用unique_ptr的时候不用写删除器可直接使用，因为该指针具有构造数组特征化

//    make_shared不能构造数组，构造数组只能用shared_ptr或者unique_ptr
//    auto left=std::make_shared<int[]>(leftLen);
//    auto right=std::make_shared<int[]>(rightLen);

    for(int i=0;i<leftLen;i++){
        (left.get())[i]=a[low+i];
    }
    for(int j=0;j<rightLen;j++){
        right.get()[j]=a[mid+1+j];
    }

    int i=0,j=0,count=low;//count=low而不是0
    while(i<leftLen && j<rightLen){
        if((left.get())[i]<= (right.get())[j])
            a[count++]=(left.get())[i++];
        else
            a[count++]= (right.get())[j++];
    }

    while(i<leftLen)a[count++]=(left.get())[i++];
    while(j<rightLen)a[count++]=(right.get())[j++];

//    delete left;
//    delete right;
}

void MergeSort(int a[],int low,int high){
    if(low<high) {
        int mid = (high + low) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, high);
    }
}

int main() {
   int a[10]={2,4,3,6,1,8,9,0,5,7};
   clock_t startTime=clock();
   MergeSort(a,0,9);
   for(int i=0;i<10;i++)std::cout<<i<<":"<<a[i]<<std::endl;
   clock_t endTime=clock();
   std::cout<<"running time is: "<< static_cast<double>(endTime-startTime)/CLOCKS_PER_SEC*1000<<std::endl;
}