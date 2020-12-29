// g++ -o calc main.cpp soap/soapC.cpp soap/soapcalcProxy.cpp -lgsoap++
//

//#include "soap/soapcalcProxy.h"
#include "soap/soapCalculatorPortBindingProxy.h"
#include "soap/CalculatorPortBinding.nsmap"

int main() {
	CalculatorPortBindingProxy service;

	ns1__addResponse	  result;

	if (service.add(1, 2, result) == SOAP_OK)
		 std::cout << "The sum is " << result._return_ << std::endl;
	else
		 service.soap_stream_fault(std::cerr);
}

