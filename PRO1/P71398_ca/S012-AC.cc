void digit_maxim_i_minim(int n, int& maxim, int& minim){
	int myMax=0;
	int myMin=9;
	if(n<9) myMin=n;
	while(n>0){
		int aux= n%10;
		n=n/10;
		if(aux > myMax) myMax = aux;
		if(aux < myMin) myMin = aux;
	}
	maxim = myMax;
	minim = myMin;
}