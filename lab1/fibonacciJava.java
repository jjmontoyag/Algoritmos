public class Fibonacci {
	
	//cuando hay overflow no se calcula el fibonacci de nuevo
	static boolean intOverflow = false;
	static boolean shortOverflow = false;
	static boolean longOverflow = false;

	
	static void check(float saved, int i)
	{
		//integer: cuando es mayor a 2147483647
		if(!intOverflow && saved > Math.pow(2, 32)/2 - 1)
		{
			System.out.println("integer overflow at n= " + i  + " Value= " + saved);
			intOverflow = true;
		}
		
		//short: cuando es mayor a 32767
		if(!shortOverflow && saved > Math.pow(2, 16)/2 - 1)
		{
			System.out.println("short overflow at n= " + i  + " Value= " + saved);
			shortOverflow = true;
		}
		//long: cuando es mayor a 9,223,372,036,854,775,808
		if(!longOverflow && saved > Math.pow(2, 64)/2 - 1)
		{
			System.out.println("long overflow at n= " + i  + " Value= " + saved);
			longOverflow = true;
		}
	}
	
	static void fib(int n)
	{
		float fn, fn2 = 0, fn1 = 1, saved = 0;
		
		if(n == 1)
		  saved = 0;
		if(n == 2)
		  saved = 1;
		
		for(int i = 0; i < n - 2; i++)
		{
			fn = fn2 + fn1;
			saved = fn;
			fn2 = fn1;
			fn1 = fn;
			//mirar overfow para cada tipo
			check(saved, i + 2);
		}
		
	}

	public static void main(String[] args) {

        //correr hasta el termino 100
	    fib(100);
		
	}

}
