/* soapCalculatorPortBindingProxy.cpp
   Generated by gSOAP 2.8.16 from soap/calc.h

Copyright(C) 2000-2013, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
GPL or Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapCalculatorPortBindingProxy.h"

CalculatorPortBindingProxy::CalculatorPortBindingProxy()
{	CalculatorPortBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

CalculatorPortBindingProxy::CalculatorPortBindingProxy(const struct soap &_soap) : soap(_soap)
{ }

CalculatorPortBindingProxy::CalculatorPortBindingProxy(const char *url)
{	CalculatorPortBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

CalculatorPortBindingProxy::CalculatorPortBindingProxy(soap_mode iomode)
{	CalculatorPortBindingProxy_init(iomode, iomode);
}

CalculatorPortBindingProxy::CalculatorPortBindingProxy(const char *url, soap_mode iomode)
{	CalculatorPortBindingProxy_init(iomode, iomode);
	soap_endpoint = url;
}

CalculatorPortBindingProxy::CalculatorPortBindingProxy(soap_mode imode, soap_mode omode)
{	CalculatorPortBindingProxy_init(imode, omode);
}

CalculatorPortBindingProxy::~CalculatorPortBindingProxy()
{ }

void CalculatorPortBindingProxy::CalculatorPortBindingProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"ns1", "http://webservice/", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void CalculatorPortBindingProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void CalculatorPortBindingProxy::reset()
{	destroy();
	soap_done(this);
	soap_initialize(this);
	CalculatorPortBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

void CalculatorPortBindingProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *CalculatorPortBindingProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *CalculatorPortBindingProxy::soap_fault()
{	return this->fault;
}

const char *CalculatorPortBindingProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *CalculatorPortBindingProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int CalculatorPortBindingProxy::soap_close_socket()
{	return soap_closesock(this);
}

int CalculatorPortBindingProxy::soap_force_close_socket()
{	return soap_force_closesock(this);
}

void CalculatorPortBindingProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void CalculatorPortBindingProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}
#endif

char *CalculatorPortBindingProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int CalculatorPortBindingProxy::mul(const char *endpoint, const char *soap_action, int _arg0, int _arg1, struct ns1__mulResponse &_param_1)
{	struct soap *soap = this;
	struct ns1__mul soap_tmp_ns1__mul;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:8080/calculator";
	if (soap_action == NULL)
		soap_action = "http://webservice/Calculator/mulRequest";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_ns1__mul._arg0 = _arg0;
	soap_tmp_ns1__mul._arg1 = _arg1;
	soap_serializeheader(soap);
	soap_serialize_ns1__mul(soap, &soap_tmp_ns1__mul);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__mul(soap, &soap_tmp_ns1__mul, "ns1:mul", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__mul(soap, &soap_tmp_ns1__mul, "ns1:mul", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_1)
		return soap_closesock(soap);
	soap_default_ns1__mulResponse(soap, &_param_1);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__mulResponse(soap, &_param_1, "ns1:mulResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int CalculatorPortBindingProxy::dic(const char *endpoint, const char *soap_action, int _arg0, int _arg1, struct ns1__dicResponse &_param_2)
{	struct soap *soap = this;
	struct ns1__dic soap_tmp_ns1__dic;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:8080/calculator";
	if (soap_action == NULL)
		soap_action = "http://webservice/Calculator/dicRequest";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_ns1__dic._arg0 = _arg0;
	soap_tmp_ns1__dic._arg1 = _arg1;
	soap_serializeheader(soap);
	soap_serialize_ns1__dic(soap, &soap_tmp_ns1__dic);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__dic(soap, &soap_tmp_ns1__dic, "ns1:dic", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__dic(soap, &soap_tmp_ns1__dic, "ns1:dic", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_2)
		return soap_closesock(soap);
	soap_default_ns1__dicResponse(soap, &_param_2);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__dicResponse(soap, &_param_2, "ns1:dicResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int CalculatorPortBindingProxy::add(const char *endpoint, const char *soap_action, int _arg0, int _arg1, struct ns1__addResponse &_param_3)
{	struct soap *soap = this;
	struct ns1__add soap_tmp_ns1__add;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:8080/calculator";
	if (soap_action == NULL)
		soap_action = "http://webservice/Calculator/addRequest";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_ns1__add._arg0 = _arg0;
	soap_tmp_ns1__add._arg1 = _arg1;
	soap_serializeheader(soap);
	soap_serialize_ns1__add(soap, &soap_tmp_ns1__add);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__add(soap, &soap_tmp_ns1__add, "ns1:add", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__add(soap, &soap_tmp_ns1__add, "ns1:add", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_3)
		return soap_closesock(soap);
	soap_default_ns1__addResponse(soap, &_param_3);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__addResponse(soap, &_param_3, "ns1:addResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int CalculatorPortBindingProxy::min(const char *endpoint, const char *soap_action, int _arg0, int _arg1, struct ns1__minResponse &_param_4)
{	struct soap *soap = this;
	struct ns1__min soap_tmp_ns1__min;
	if (endpoint)
		soap_endpoint = endpoint;
	if (soap_endpoint == NULL)
		soap_endpoint = "http://localhost:8080/calculator";
	if (soap_action == NULL)
		soap_action = "http://webservice/Calculator/minRequest";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp_ns1__min._arg0 = _arg0;
	soap_tmp_ns1__min._arg1 = _arg1;
	soap_serializeheader(soap);
	soap_serialize_ns1__min(soap, &soap_tmp_ns1__min);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns1__min(soap, &soap_tmp_ns1__min, "ns1:min", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns1__min(soap, &soap_tmp_ns1__min, "ns1:min", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&_param_4)
		return soap_closesock(soap);
	soap_default_ns1__minResponse(soap, &_param_4);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get_ns1__minResponse(soap, &_param_4, "ns1:minResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */
