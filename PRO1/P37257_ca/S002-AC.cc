bool tres_digits_seguits_iguals(int n, int b){
	if(n==0) return false;
	if(n%b == (n/b)%b and n%b == (n/(b*b))%b) return true;
	else return tres_digits_seguits_iguals(n/b,b);
}