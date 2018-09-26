#include<iostream>
#include<math.h>
using namespace std;

//cuando hay overflow no se calcula el fibonacci de nuevo
bool intOverflow = false;
bool uintOverflow = false;
bool shortOverflow = false;
bool ushortOverflow = false;
bool longOverflow = false;
bool longlongOverfow = false;
bool unlongOverflow = false;
bool unlongLongOverflow = false;
bool longLongOverflow = false;


void check(float saved, int i)
{
	//integer: cuando es mayor a 2147483647
	if(!intOverflow && saved > pow(2, 32)/2 - 1)
	{
		cout<<"integer overflow at n= "<< i <<" Value= "<<saved<<endl;
		intOverflow = true;
	}
	
	//unsigned integer: cuando es mayor a 4.294.967.295
	if(!uintOverflow && saved > pow(2, 32) - 1)
	{
		cout<<"unsigned integer overflow at n= "<< i <<" Value= "<<saved<<endl;
		uintOverflow = true;
	}
	
	//short: cuando es mayor a 32767
	if(!shortOverflow && saved > pow(2, 16)/2 - 1)
	{
		cout<<"short overflow at n= "<< i <<" Value= "<<saved<<endl;
		shortOverflow = true;
	}
	
	//unsigned short: cuando es mayor a 65535
	if(!ushortOverflow && saved > pow(2, 16) - 1)
	{
		cout<<"unsigned short overflow at n= "<< i <<" Value= "<<saved<<endl;
		ushortOverflow = true;
	}
	//long: cuando es mayor a 2,147,483,647
	if(!longOverflow && saved > pow(2, 32)/2 - 1)
	{
		cout<<"long overflow at n= "<< i <<" Value= "<<saved<<endl;
		longOverflow = true;
	}
	//unsigned long: cuando es mayor a 4,294,967,295
		if(!unlongOverflow && saved > pow(2, 32) - 1)
	{
		cout<<"unsigned long overflow at n= "<< i <<" Value= "<<saved<<endl;
		unlongOverflow = true;
	}
	 //long long: cuando es mayor a 9,223,372,036,854,775,807
    if(!longLongOverflow && saved > pow(2, 64)/2 - 1)
	{
		cout<<"long long overflow at n= "<< i <<" Value= "<<saved<<endl;
		longLongOverflow = true;
	}
    //unsigned long long: cuando es mayor a 18,446,744,073,709,551,615
    if(!unlongLongOverflow && saved > pow(2, 64) - 1)
	{
		cout<<"unsigned long long overflow at n= "<< i <<" Value= "<<saved<<endl;
		unlongLongOverflow = true;
	}
	
}
void fib(int n){
	
	float fn, fn2 = 0, fn1 = 1, saved;
	
	
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
	    //mirar overflow para cada tipo e imprimir valor al que hay overflow
		check(saved, i + 2);	
		
	}
	

}

main()
{
	//calclar fibonacci hasta el termino 100
    fib(100);
   
   
}
