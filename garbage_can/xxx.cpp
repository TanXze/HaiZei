#include<iostream>
using namespace std;


int main(){
	// 一个int 4个字节，G是一个G需要的个数
	long long G = 1024*1024*1024/4;
	int howmanyG = 0;
	cout<<"要占用多少G？"<<endl;
	cin>>howmanyG;


	cout<<"正在占用内存，不要关闭程序"<<endl;
	for (long long i=0; i<G*howmanyG; i++){
		int * temp = new int;
	}

	cin>>G;
    return 0;
}

