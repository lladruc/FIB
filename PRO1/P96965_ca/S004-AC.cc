int suma_digits(int x){
	if(x<10){
		return x;
	}else{
		return (x%10) + suma_digits(x/10);
	}
}

int reduccio_digits(int x){
	while(x>9){
		x=suma_digits(x);
	}
	return x;
}

