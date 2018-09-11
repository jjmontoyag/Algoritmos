#include<iostream>
#include<math.h>
using namespace std;

//cuando hay overflow no se calcula el fibonacci de nuevo
bool intOverflow = false;
bool uintOverflow = false;
bool shortOverflow = false;
bool ushortOverflow = false;


void check(unsigned long long saved, int i)
{
	//integer
	if(!intOverflow && saved > pow(2, 32)/2 - 1)
	{
		cout<<"integer overflow at n= "<< i <<" Value= "<<saved<<endl;
		intOverflow = true;
	}
	
	//unsigned integer
	if(!uintOverflow && saved > pow(2, 32) - 1)
	{
		cout<<"unsigned integer overflow at n= "<< i <<" Value= "<<saved<<endl;
		uintOverflow = true;
	}
	
	//short 
	if(!shortOverflow && saved > pow(2, 16)/2 - 1)
	{
		cout<<"short overflow at n= "<< i <<" Value= "<<saved<<endl;
		shortOverflow = true;
	}
	
	//unsigned short
	if(!ushortOverflow && saved > pow(2, 16) - 1)
	{
		cout<<"unsigned short overflow at n= "<< i <<" Value= "<<saved<<endl;
		ushortOverflow = true;
	}
	
	   
	
}
void fib(int n){
	
	unsigned long long fn, fn2 = 0, fn1 = 1, saved;
	
	
	if(n == 1)
	  saved = 0;
	if(n == 2)
	  saved = 1;
	
	for(int i = 0; i < n - 2; i++)
	{
		//calcular fibonacci
		fn = fn2 + fn1;
		saved = fn;
		fn2 = fn1;
		fn1 = fn;
	    //mirar overflow para cada tipo
		check(saved, i + 2);	
		
	}
	

}

main()
{
    fib(60);
}
