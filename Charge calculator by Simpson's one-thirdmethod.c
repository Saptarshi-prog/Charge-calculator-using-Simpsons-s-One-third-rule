#include<stdio.h>

//defining the time varying function of current
float function(float t){
	return 0.3-0.2*t;
}

void main(){
	int n,i;
	float h, y[20], q, e;
	float lower_limit = 0, upper_limit, output;
	
	//taking user inputs of the parameters
	
	printf("The current is varying with time as i(t) = 0.3 - 0.2t mA");
	printf("\nEnter the step size(h): \t");
	scanf("%f",&h);
	printf("\nEnter the time upto which you want to calculate the charge in seconds:\t");
	scanf("%f", &upper_limit);
	
	//calculating the total number of sub-intervals
	
	n= (upper_limit-lower_limit)/h;
	if(n%2==1){
		n=n+1;
	}
	h = (upper_limit-lower_limit)/n;
	
	//printing the refined values of n and h
	
	printf("\n Refined values of n and h are :%d and %f", n,h);
	
	//calculating the y values
	y[0] = function(lower_limit);
	y[n] = function(upper_limit);
	for(i=1; i<=n-1; i++){
		if(i%2==1){
			q = q+function(lower_limit + i*h);
		}
		else{
			e = e+function(lower_limit +i*h);
		}
	}
	
	output = (h/3)*(y[0] + y[n] + 4*q + 2*e);
	printf("\nThe value of the charge is %f milli Coulomb.\t", output);
	#
	
	
}
