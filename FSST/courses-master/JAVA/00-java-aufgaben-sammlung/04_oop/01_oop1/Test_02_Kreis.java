package test;

public class Test_02_Kreis {

	public static void main(String[] args) {
		Kreis k1= new Kreis("radius=10");
		Kreis k2= new Kreis(k1);
		
		double umfang= k1.getUmfang();
		
		System.out.println("Umfang von k1=" + umfang);

	}

}
