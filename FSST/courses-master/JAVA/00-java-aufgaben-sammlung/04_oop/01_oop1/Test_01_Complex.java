package test;

public class Test_01_Complex {

	public static void main(String[] args) {
		
		Complex a= new Complex(3.0, 2.0);
		Complex b= new Complex(a);
		Complex c;
	
		c= a.add(b);	
		
		System.out.println ("c= " + c.toString());
		

	//The output should be:
	//c= [6.0 + 4.0 j]

	}

}
