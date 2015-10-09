#include "HttpRequest.h"

HttpRequest::HttpRequest()
:_host(NULL)
,_fullUri(NULL)
,_resource(NULL)
,_body(NULL)
,_bodyLen(0)
{
	//default to 1.1
	_version = 1.1;
	_header = new HttpHeader();

	_state = HttpReqState_start;
	_type = HttpReqType_get;
}

HttpRequest:~HttpRequest()
{
	SAFE_DELETE(_header);
	SAFE_FREE(_host);
	SAFE_FREE(_fullUri);
	SAFE_FREE(_resource);
	SAFE_FREE(_body);
}
