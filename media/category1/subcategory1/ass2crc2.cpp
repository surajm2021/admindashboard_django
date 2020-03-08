#include<iostream>
using namespace std;

int main(){
	int fs,i,j,k;
	cout<<"Enter the frame size : ";
	cin>>fs;
	int f[20];
	for(i=0;i<fs;i++){
		cin>>f[i];
	}
	int gs;
	cout<<endl<<"Enter the generator size : ";
	cin>>gs;
	int g[20];
	for(i=0;i<gs;i++){
		cin>>g[i];
	}
	cout<<endl<<"You Enter the frame :";
	for(i=0;i<fs;i++){
		cout<<f[i];
	}
	cout<<endl<<"You Enter the generatr : ";
	for(i=0;i<gs;i++){
		cout<<g[i];
	}
	int rs;
	rs=gs-1;
	cout<<endl<<"no of 0 appeneded : "<<rs;
     cout<<endl<<"frame after appending 0's : ";
    for(i=0,j=fs;i<rs;i++,j++){
    	f[j]=0;
    }
    for(i=0;i<fs+rs;i++){
    	cout<<f[i];
    }
    int temp[20];
    for(i=0;i<fs+rs;i++){
    	temp[i]=f[i];
    }
    // DIVISION 

    for(i=0;i<fs;i++){
    	j=0;
    	k=i;
    	if(temp[k]>=g[j]){
    		for(j=0,k=i;j<gs;j++,k++){
	    		if((temp[k]==1)&&(g[j]==1) || temp[k]==0 && g[j]==0){
	    			temp[k]=0;
	    		}else{
	    			temp[k]=1;
	    		}
	    	}
        }
    }

    int crc[15];
    for(i=0,j=fs;i<rs;i++,j++){
    	crc[i]=temp[j];
    }
    cout<<endl<<"CRC bits : ";
    for(i=0;i<rs;i++){
    	cout<<crc[i];
    }
    int tf[20];
    cout<<endl<<"transfer frame : ";
    for(i=0;i<fs;i++){
    	tf[i]=f[i];
    }
    for(i=fs,j=0;i<fs+rs;i++,j++){
    	tf[i]=crc[j];
    }
    for(i=0;i<fs+rs;i++){
    	cout<<tf[i];
    }
    cout<<endl<<"Recevier Side : ";
    cout<<endl<<"Recevier frame : ";
    for(i=0;i<fs+rs;i++){
    	cout<<tf[i];
    }
    for(i=0;i<fs+rs;i++){
    	temp[i]=tf[i];
    }

    for(i=0;i<fs+rs;i++){
    	j=0;
    	k=i;
    	if(temp[k]>=g[j]){
    		for(j=0,k=i;j<gs;j++,k++){
    			if((temp[k]==1 && g[j]==1)||(temp[k]==0 && g[k]==0)){
    				temp[k]=0;
    			}else{
    				temp[k]=1;
    			}
    		}
    	}
    }
    cout<<endl<<"remainder : ";
    for(i=fs;i<fs+rs;i++){
    	cout<<temp[fs];
    }
	return 0;
}