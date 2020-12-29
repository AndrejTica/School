package webservice;

import javax.jws.WebService;
import javax.jws.soap.SOAPBinding;
import javax.jws.soap.SOAPBinding.Style;

@WebService
@SOAPBinding(style=Style.RPC)

public class Calculator {
	public long add(int val1, int val2) {
		return val1 + val2;
	}

	public long min(int val1, int val2) {
		return val1 - val2;
	}
	
	public long mul(int val1, int val2) {
		return val1 * val2;
	}

	public long dic(int val1, int val2) {
		return val1 / val2;
	}

}
