bool es_capicua(int n, int b){
	int cap= n,cua=0;
	while(cap>0){
		cua= (cua*b)+(cap%b);
		cap=cap/b;
	}
	if(n==cua){
		return true;
	}else{
		return false;
	}
}