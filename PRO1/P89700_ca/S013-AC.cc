#include <iostream>
using namespace std;

int main(){
	int seq=0,fi=0,i=1,n;
	bool firstSeq=true;
	while(firstSeq){
		cin >> n;
		if(n!=0){
			fi=n;
			seq+=n;
		}else{
			seq-=fi; // seq - end seq.
			firstSeq=false;
		}
	}
	//cout << "F seq: " << seq << " - Fi: " << fi << endl;
	firstSeq=true; // reurtilizamos variables
	while(firstSeq){
		bool noZero=true;
		int nSeq=0,nFi=0;
		cin >> n;
		if(n==0){
			firstSeq=false;
		}else{
			noZero=true;
		}
		while(noZero){
			if(n!=0){
				nSeq+=n;
				nFi=n;
				cin >> n;
			}else{
				nSeq-=nFi;
				noZero=false;
				if(seq==nSeq and fi==nFi){
					++i;
				}
			}
		}
		//cout << "N seq: " << nSeq << " - nFi: " << nFi << endl; 
	}
	cout << i << endl;
}