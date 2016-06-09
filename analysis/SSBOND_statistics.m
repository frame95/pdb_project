function SSBOND_statistics
	w=dlmread("SSBOND_definitive.txt");
	w=w/890;
	M=size(w,1);
	E=0; V=0;
	for i=1:M
		c=sum(w(i+1:M));
		E+=(2*w(i)*c + w(i)^2)/i;
		V+=(2*w(i)*c + w(i)^2)/(i^2);
	endfor
	V=V-E^2;
	printf("Mean value of approximation: %d\n", 100*E);
	printf("Variance: %d\n", 100*V);
	printf("99 percent of cases the approximation is at least %d\n", 100*abs(E-10*sqrt(V)) );
	hist(w);
endfunction
