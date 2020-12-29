/* soap/calc.h
   Generated by wsdl2h 2.8.16 from http://localhost:8080/calculator?wsdl and typemap.dat
   2015-04-13 06:56:38 GMT

   DO NOT INCLUDE THIS FILE DIRECTLY INTO YOUR PROJECT BUILDS
   USE THE soapcpp2-GENERATED SOURCE CODE FILES FOR YOUR PROJECT BUILDS

   gSOAP XML Web services tools.
   Copyright (C) 2000-2013 Robert van Engelen, Genivia Inc. All Rights Reserved.
   Part of this software is released under one of the following licenses:
   GPL or Genivia's license for commercial use.
*/

/** @page page_notes Usage Notes

NOTE:

 - Run soapcpp2 on soap/calc.h to generate the SOAP/XML processing logic.
   Use soapcpp2 -I to specify paths for #import
   To build with STL, 'stlvector.h' is imported from 'import' dir in package.
   Use soapcpp2 -j to generate improved proxy and server classes.
 - Use wsdl2h -c and -s to generate pure C code or C++ code without STL.
 - Use 'typemap.dat' to control namespace bindings and type mappings.
   It is strongly recommended to customize the names of the namespace prefixes
   generated by wsdl2h. To do so, modify the prefix bindings in the Namespaces
   section below and add the modified lines to 'typemap.dat' to rerun wsdl2h.
 - Use Doxygen (www.doxygen.org) on this file to generate documentation.
 - Use wsdl2h -R to generate REST operations.
 - Use wsdl2h -nname to use name as the base namespace prefix instead of 'ns'.
 - Use wsdl2h -Nname for service prefix and produce multiple service bindings
 - Use wsdl2h -d to enable DOM support for xsd:anyType.
 - Use wsdl2h -g to auto-generate readers and writers for root elements.
 - Use wsdl2h -b to auto-generate bi-directional operations (duplex ops).
 - Struct/class members serialized as XML attributes are annotated with a '@'.
 - Struct/class members that have a special role are annotated with a '$'.

WARNING:

   DO NOT INCLUDE THIS ANNOTATED FILE DIRECTLY IN YOUR PROJECT SOURCE CODE.
   USE THE FILES GENERATED BY soapcpp2 FOR YOUR PROJECT'S SOURCE CODE:
   THE soapStub.h FILE CONTAINS THIS CONTENT WITHOUT ANNOTATIONS.

LICENSE:

@verbatim
--------------------------------------------------------------------------------
gSOAP XML Web services tools
Copyright (C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.

This software is released under one of the following licenses:
GPL or Genivia's license for commercial use.
--------------------------------------------------------------------------------
GPL license.

This program is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 2 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 59 Temple
Place, Suite 330, Boston, MA 02111-1307 USA

Author contact information:
engelen@genivia.com / engelen@acm.org

This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial-use license is available from Genivia, Inc., contact@genivia.com
--------------------------------------------------------------------------------
@endverbatim

*/


//gsoapopt w

/******************************************************************************\
 *                                                                            *
 * Definitions                                                                *
 *   http://webservice/                                                       *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Import                                                                     *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Schema Namespaces                                                          *
 *                                                                            *
\******************************************************************************/


/* NOTE:

It is strongly recommended to customize the names of the namespace prefixes
generated by wsdl2h. To do so, modify the prefix bindings below and add the
modified lines to typemap.dat to rerun wsdl2h:

ns1 = "http://webservice/"

*/

/******************************************************************************\
 *                                                                            *
 * Built-in Schema Types and Top-Level Elements and Attributes                *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Forward Declarations                                                       *
 *                                                                            *
\******************************************************************************/



/******************************************************************************\
 *                                                                            *
 * Services                                                                   *
 *                                                                            *
\******************************************************************************/


//gsoap ns1  service name:	CalculatorPortBinding 
//gsoap ns1  service type:	Calculator 
//gsoap ns1  service port:	http://localhost:8080/calculator 
//gsoap ns1  service namespace:	http://webservice/ 
//gsoap ns1  service transport:	http://schemas.xmlsoap.org/soap/http 

/** @mainpage CalculatorService Definitions

@section CalculatorService_bindings Service Bindings

  - @ref CalculatorPortBinding

@section CalculatorService_more More Information

  - @ref page_notes "Usage Notes"

  - @ref page_XMLDataBinding "XML Data Binding"

  - @ref SOAP_ENV__Header "SOAP Header Content" (when applicable)

  - @ref SOAP_ENV__Detail "SOAP Fault Detail Content" (when applicable)


*/

/**

@page CalculatorPortBinding Binding "CalculatorPortBinding"

@section CalculatorPortBinding_operations Operations of Binding  "CalculatorPortBinding"

  - @ref ns1__mul

  - @ref ns1__dic

  - @ref ns1__add

  - @ref ns1__min

@section CalculatorPortBinding_ports Endpoints of Binding  "CalculatorPortBinding"

  - http://localhost:8080/calculator

Note: use wsdl2h option -Nname to change the service binding prefix name


*/

/******************************************************************************\
 *                                                                            *
 * Service Binding                                                            *
 *   CalculatorPortBinding                                                    *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns1__mul                                                                 *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__mulResponse" of operation "ns1__mul"
struct ns1__mulResponse
{
    LONG64                              _return_;
};

/// Operation "ns1__mul" of service binding "CalculatorPortBinding"

/**

Operation details:

  - SOAP literal messaging

  - Addressing input action: "http://webservice/Calculator/mulRequest"

  - Addressing output action: "http://webservice/Calculator/mulResponse"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__mul(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // input parameters:
    int                                 arg0,
    int                                 arg1,
    // output parameters:
    struct ns1__mulResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__mul(
    struct soap *soap,
    // input parameters:
    int                                 arg0,
    int                                 arg1,
    // output parameters:
    struct ns1__mulResponse&
  );
@endcode

C++ proxy class (defined in soapCalculatorPortBindingProxy.h):
@code
  class CalculatorPortBindingProxy;
@endcode
Important: use soapcpp2 option '-j' (or '-i') to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapCalculatorPortBindingService.h):
@code
  class CalculatorPortBindingService;
@endcode
Important: use soapcpp2 option '-j' (or '-i') to generate greatly improved and easy-to-use service classes;

*/

//gsoap ns1  service method-protocol:	mul SOAP
//gsoap ns1  service method-style:	mul rpc
//gsoap ns1  service method-encoding:	mul literal
//gsoap ns1  service method-input-action:	mul http://webservice/Calculator/mulRequest
//gsoap ns1  service method-output-action:	mul http://webservice/Calculator/mulResponse
int ns1__mul(
    int                                 _arg0,	///< Input parameter
    int                                 _arg1,	///< Input parameter
    struct ns1__mulResponse            &	///< Output response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns1__dic                                                                 *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__dicResponse" of operation "ns1__dic"
struct ns1__dicResponse
{
    LONG64                              _return_;
};

/// Operation "ns1__dic" of service binding "CalculatorPortBinding"

/**

Operation details:

  - SOAP literal messaging

  - Addressing input action: "http://webservice/Calculator/dicRequest"

  - Addressing output action: "http://webservice/Calculator/dicResponse"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__dic(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // input parameters:
    int                                 arg0,
    int                                 arg1,
    // output parameters:
    struct ns1__dicResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__dic(
    struct soap *soap,
    // input parameters:
    int                                 arg0,
    int                                 arg1,
    // output parameters:
    struct ns1__dicResponse&
  );
@endcode

C++ proxy class (defined in soapCalculatorPortBindingProxy.h):
@code
  class CalculatorPortBindingProxy;
@endcode
Important: use soapcpp2 option '-j' (or '-i') to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapCalculatorPortBindingService.h):
@code
  class CalculatorPortBindingService;
@endcode
Important: use soapcpp2 option '-j' (or '-i') to generate greatly improved and easy-to-use service classes;

*/

//gsoap ns1  service method-protocol:	dic SOAP
//gsoap ns1  service method-style:	dic rpc
//gsoap ns1  service method-encoding:	dic literal
//gsoap ns1  service method-input-action:	dic http://webservice/Calculator/dicRequest
//gsoap ns1  service method-output-action:	dic http://webservice/Calculator/dicResponse
int ns1__dic(
    int                                 _arg0,	///< Input parameter
    int                                 _arg1,	///< Input parameter
    struct ns1__dicResponse            &	///< Output response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns1__add                                                                 *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__addResponse" of operation "ns1__add"
struct ns1__addResponse
{
    LONG64                              _return_;
};

/// Operation "ns1__add" of service binding "CalculatorPortBinding"

/**

Operation details:

  - SOAP literal messaging

  - Addressing input action: "http://webservice/Calculator/addRequest"

  - Addressing output action: "http://webservice/Calculator/addResponse"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__add(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // input parameters:
    int                                 arg0,
    int                                 arg1,
    // output parameters:
    struct ns1__addResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__add(
    struct soap *soap,
    // input parameters:
    int                                 arg0,
    int                                 arg1,
    // output parameters:
    struct ns1__addResponse&
  );
@endcode

C++ proxy class (defined in soapCalculatorPortBindingProxy.h):
@code
  class CalculatorPortBindingProxy;
@endcode
Important: use soapcpp2 option '-j' (or '-i') to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapCalculatorPortBindingService.h):
@code
  class CalculatorPortBindingService;
@endcode
Important: use soapcpp2 option '-j' (or '-i') to generate greatly improved and easy-to-use service classes;

*/

//gsoap ns1  service method-protocol:	add SOAP
//gsoap ns1  service method-style:	add rpc
//gsoap ns1  service method-encoding:	add literal
//gsoap ns1  service method-input-action:	add http://webservice/Calculator/addRequest
//gsoap ns1  service method-output-action:	add http://webservice/Calculator/addResponse
int ns1__add(
    int                                 _arg0,	///< Input parameter
    int                                 _arg1,	///< Input parameter
    struct ns1__addResponse            &	///< Output response struct parameter
);

/******************************************************************************\
 *                                                                            *
 * Service Operation                                                          *
 *   ns1__min                                                                 *
 *                                                                            *
\******************************************************************************/

/// Operation response struct "ns1__minResponse" of operation "ns1__min"
struct ns1__minResponse
{
    LONG64                              _return_;
};

/// Operation "ns1__min" of service binding "CalculatorPortBinding"

/**

Operation details:

  - SOAP literal messaging

  - Addressing input action: "http://webservice/Calculator/minRequest"

  - Addressing output action: "http://webservice/Calculator/minResponse"

C stub function (defined in soapClient.c[pp] generated by soapcpp2):
@code
  int soap_call_ns1__min(
    struct soap *soap,
    NULL, // char *endpoint = NULL selects default endpoint for this operation
    NULL, // char *action = NULL selects default action for this operation
    // input parameters:
    int                                 arg0,
    int                                 arg1,
    // output parameters:
    struct ns1__minResponse&
  );
@endcode

C server function (called from the service dispatcher defined in soapServer.c[pp]):
@code
  int ns1__min(
    struct soap *soap,
    // input parameters:
    int                                 arg0,
    int                                 arg1,
    // output parameters:
    struct ns1__minResponse&
  );
@endcode

C++ proxy class (defined in soapCalculatorPortBindingProxy.h):
@code
  class CalculatorPortBindingProxy;
@endcode
Important: use soapcpp2 option '-j' (or '-i') to generate greatly improved and easy-to-use proxy classes;

C++ service class (defined in soapCalculatorPortBindingService.h):
@code
  class CalculatorPortBindingService;
@endcode
Important: use soapcpp2 option '-j' (or '-i') to generate greatly improved and easy-to-use service classes;

*/

//gsoap ns1  service method-protocol:	min SOAP
//gsoap ns1  service method-style:	min rpc
//gsoap ns1  service method-encoding:	min literal
//gsoap ns1  service method-input-action:	min http://webservice/Calculator/minRequest
//gsoap ns1  service method-output-action:	min http://webservice/Calculator/minResponse
int ns1__min(
    int                                 _arg0,	///< Input parameter
    int                                 _arg1,	///< Input parameter
    struct ns1__minResponse            &	///< Output response struct parameter
);

/**

@page CalculatorPortBinding Binding "CalculatorPortBinding"

@section CalculatorPortBinding_policy_enablers Policy Enablers of Binding  "CalculatorPortBinding"

Based on policies, this service imports

  - WS-Policy reminders and enablers:
    - WS-Addressing 1.0 (2005/08, accepts 2004/08):
	@code
	#import "wsa5.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsaapi.h"
	soap_register_plugin(soap, soap_wsa); // register the wsa plugin in your code
	// See the user guide gsoap/doc/wsa/html/index.html
	@endcode
    - WS-Addressing (2004/08):
	@code
	#import "wsa.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsaapi.h"
	soap_register_plugin(soap, soap_wsa); // register the wsa plugin in your code
	// See the user guide gsoap/doc/wsa/html/index.html
	@endcode
    - WS-ReliableMessaging 1.0:
	@code
	#import "wsrm5.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsrmapi.h"
	soap_register_plugin(soap, soap_wsa); // register the wsa plugin in your code
	soap_register_plugin(soap, soap_wsrm); // register the wsrm plugin in your code
	// See the user guide gsoap/doc/wsrm/html/index.html
	@endcode
    - WS-ReliableMessaging 1.1:
	@code
	#import "wsrm.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsrmapi.h"
	soap_register_plugin(soap, soap_wsa); // register the wsa plugin in your code
	soap_register_plugin(soap, soap_wsrm); // register the wsrm plugin in your code
	// See the user guide gsoap/doc/wsrm/html/index.html
	@endcode
    - WS-Security (SOAP Message Security) 1.0 (accepts 1.1):
	@code
	#import "wsse.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsseapi.h"
	soap_register_plugin(soap, soap_wsse); // register the wsse plugin in your code
	// See the user guide gsoap/doc/wsse/html/index.html
	@endcode
    - WS-Security (SOAP Message Security) 1.1 (accepts 1.0):
	@code
	#import "wsse11.h" // to be added to this header file for the soapcpp2 build step
	@endcode
	@code
	#include "plugin/wsseapi.h"
	soap_register_plugin(soap, soap_wsse); // register the wsse plugin in your code
	// See the user guide gsoap/doc/wsse/html/index.html
	@endcode
    - HTTP Digest Authentication:
	@code
	#include "plugin/httpda.h"
	soap_register_plugin(soap, soap_http_da); // register the HTTP DA plugin in your code
	// See the user guide gsoap/doc/httpda/html/index.html
	@endcode
*/


/******************************************************************************\
 *                                                                            *
 * XML Data Binding                                                           *
 *                                                                            *
\******************************************************************************/


/**

@page page_XMLDataBinding XML Data Binding

SOAP/XML services use data bindings contractually bound by WSDL and auto-
generated by wsdl2h and soapcpp2 (see Service Bindings). Plain data bindings
are adopted from XML schemas as part of the WSDL types section or when running
wsdl2h on a set of schemas to produce non-SOAP-based XML data bindings.

The following readers and writers are C/C++ data type (de)serializers auto-
generated by wsdl2h and soapcpp2. Run soapcpp2 on this file to generate the
(de)serialization code, which is stored in soapC.c[pp]. Include "soapH.h" in
your code to import these data type and function declarations. Only use the
soapcpp2-generated files in your project build. Do not include the wsdl2h-
generated .h file in your code.

Data can be read in XML and deserialized from:
  - a file descriptor, using soap->recvfd = fd
  - a socket, using soap->socket = ...
  - a C++ stream, using soap->is = ...
  - a buffer, using the soap->frecv() callback

Data can be serialized in XML and written to:
  - a file descriptor, using soap->sendfd = fd
  - a socket, using soap->socket = ...
  - a C++ stream, using soap->os = ...
  - a buffer, using the soap->fsend() callback

The following options are available for (de)serialization control:
  - soap->encodingStyle = NULL; to remove SOAP 1.1/1.2 encodingStyle
  - soap_mode(soap, SOAP_XML_TREE); XML without id-ref (no cycles!)
  - soap_mode(soap, SOAP_XML_GRAPH); XML with id-ref (including cycles)
  - soap_set_namespaces(soap, struct Namespace *nsmap); to set xmlns bindings


*/

/* End of soap/calc.h */
