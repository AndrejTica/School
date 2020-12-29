package webservice;

// bezug auf generierte STUBS
import webservice.Calculator;
import webservice.CalculatorService;


 public class CalculatorClient {
    public static void main(String args[]) {
        
    	CalculatorService service = new CalculatorService();
        
        Calculator calculator = service.getCalculatorPort();
        
        System.out.println("Summe: " + calculator.add(17, 13));
    }
}
