int suma_bits_potencies_parells(int n){
	int aux=0;
	for(int i=0;n>0;i++){
		if(n%2!=0 and i%2==0){
			++aux;
		}
		n=n/2;
	}
	aux+=n;
	return aux;
}