#include<iostream>
using namespace std;

int main(){
    int fs;
    cout<<"Enter the frame size"<<endl;
    cin>>fs;
    int f[20];
    for(int i=0;i<fs;i++){
    	cin>>f[i];
    	if(!(f[i]==0 or f[i]==1)){
    		cout<<"please enter binary only 0 or 1"<<endl;
    		return 0;
    	}
    }

    int gs;
    cout<<"Enter the genretor size"<<endl;
    cin>>gs;
    int g[20];
    for(int i=0;i<gs;i++){
    	cin>>g[i];
    	if(!(g[i]==0 or g[i]==1)){
    		cout<<"please enter binary only 0 or 1"<<endl;
    		return 0;
    	}
    }

    cout<<endl<<"You Enter the frame as : ";
    for(int i=0;i<fs;i++){
    	cout<<f[i];
    }
    cout<<endl<<endl<<"Generator :";
    for(int i=0;i<gs;i++){
    	cout<<g[i];
    }


    //appending 0

    int rs;
    rs=gs-1;
    cout<<endl<<"number of 0 appending : "<<rs<<endl;
    for(int i=fs;i<fs+rs;i++){
    	f[i]=0;
    }
    cout<<"frame after apending 0 :";
     for(int i=0;i<fs+rs;i++){
    	cout<<f[i];
    }
    int temp[20];
    for(int i=0; i<20;i++){
    	temp[i]=f[i];
    }    
    int j,k;
    for(int i=0;i<fs;i++){
    	j=0;
    	k=i;
    	if(temp[k]>=g[j]){
    		for(j=0,k=i;j<gs;j++,k++){
    			if((temp[k]==1 && g[j]==1)||(temp[k]==0 && g[j]==0)){
    				temp[k]=0;
    			}else{
    				temp[k]=1;
    			}
    		}
    	}
    }
    cout<<endl;
    int crc[15];
    for(int i=0,j=fs;i<rs;i++,j++){
    	crc[i]=temp[j];
    }
    cout<<"crc bits (remainder) :";
    for(int i=0;i<rs;i++){
    	cout<<crc[i];
    }

    cout<<endl<<"transmitted frame : ";
    int tf[20];

    for(int i=0;i<fs;i++){
    	tf[i]=f[i];
    }
    for(int i=fs,j=0;j<rs;i++,j++){
    	tf[i]=crc[j];
    }
    for(int i=0;i<fs+rs;i++){
    	cout<<tf[i];
    }

	cout<<endl<<"recevier side ::"<<endl;
	cout<<"received frame :";
	for(int i=0;i<fs+rs;i++){
    	cout<<tf[i];
    }
    for(int i=0;i<fs+rs;i++){
    	temp[i]=tf[i];
    }

   	//DIVISION
   	for(int i=0;i<fs+rs;i++){
   		j=0;
   		k=i;
   		if(temp[k]>=g[j]){
   			for(j=0,k=i;j<gs;j++,k++){
   				if((temp[k]==1 && g[j]==1)||(temp[k]==0 && g[j]==0)){
   					temp[k]=0;
   				}else{
   					temp[k]=1;
   				}
   			}
   		}
   	}
   	cout<<endl<<"remainder :";
   	int r[20];
   	for(int i=fs,j=0;i<fs+rs;j++,i++){
   		r[j]=temp[i];
   	}
   	for(int i=0;i<rs;i++){
   		cout<<r[i];
   	}
   	cout<<endl;
   	int flag=0;
   	for(int i=0;i<rs;i++){
   		if(r[i]!=0){
   			flag=1;
   		}
   	}
   	if(flag==0){
   		cout<<"hence remainder is zero hence message transfer succefully";
   	}else{
   		cout<<"hence remainder is NOT zero hence message transfer unsuccefully";
   	}
	return 0;
}