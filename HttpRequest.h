#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

namespace kttp {

typedef enum _HttpReqType {
  HttpReqType_get = 0,
  HttpReqType_options,
  HttpReqType_head,
  HttpReqType_post,
  HttpReqType_put,
  HttpReqType_delete,
  HttpReqType_trace,
  HttpReqType_connect,
  HttpReqType_propfind,
  HttpReqType_proppatch,
  HttpReqType_mkcol,
  HttpReqType_copy,
  HttpReqType_move,
  HttpReqType_lock,
  HttpReqType_unlock
} HttpReqType;

typedef enum _HttpReqState {
  HttpReqState_start = 0,
  HttpReqState_sending_request,
  HttpReqState_sending_headers,
  HttpReqState_sending_body
} HttpReqState;

class HttpHeader;

class HttpRequest
{
protected:
	float _version;
	char* _host;
	char* _fullUri;
	char* _resource;
	char* _body;
	int   _bodyLen;
	HttpHeader *_header;
	HttpReqState _state;
	HttpReqType _type;
public:
	HttpRequest();
	~HttpRequest();

	int send();
}


}

#endif
