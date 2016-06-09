function SSBOND_distribution
	M=dlmread("SSBOND_distribution.txt");
	v=M(:,3)+M(:,4);
	N=max(v);
	for i=(0:N) 
		w(i+1)=sum(v == i);
	endfor
	plot(v);
	hist(v);
	dlmwrite("SSBOND_definitive.txt", w');
endfunction
