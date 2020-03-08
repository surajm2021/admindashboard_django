#include<iostream>
using namespace std;

int main(){

	int data[20];
	cout<<endl<<"Enter the 4 bit binary data : "<<endl;
	cin>>data[7];
	cin>>data[6];
	cin>>data[5];
	cin>>data[3];
	data[1]=data[3]^data[5]^data[7];
	data[2]=data[3]^data[6]^data[7];
	data[4]=data[5]^data[6]^data[7];
	cout<<"data transfer is : ";
	for(int i=7;i>0;i--){
		cout<<data[i];
	} 
	cout<<endl<<"enter the receiver 8 bits data : "<<endl;
	int recdata[20];
	for(int i=7;i>0;i--){
		cin>>recdata[i];
	}
	cout<<endl<<"you enter receiver data as :";
	for(int i=7;i>0;i--){
		cout<<recdata[i];
	}
	int p1,p2,p4,c;
	p1=recdata[1]^recdata[3]^recdata[5]^recdata[7];
	p2=recdata[2]^recdata[3]^recdata[6]^recdata[7];
	p4=recdata[4]^recdata[5]^recdata[6]^recdata[7];
	c=p4*4+p2*2+p1;
	if(c==0){
		cout<<"No error in receiver message :)"<<endl;
	}else{
		cout<<"error in message "<<endl;
		cout<<endl<<"send data :";
		for(int i=7;i>0;i--){
			cout<<data[i];
		} 
		cout<<endl<<"receiver data : ";
		for(int i=7;i>0;i--){
		cout<<recdata[i];
		}
		cout<<endl<<"Error at "<<c<<"position"<<endl;
	}
	return 0;
}
