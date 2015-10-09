#ifndef HTTP_URI_H
#define HTTP_URI_H

namespace kttp {


class Uri
{
	char*            _full;                          /* full URL */
	char*            _proto;                         /* protocol */
	char*            _host;                          /* copy semantics */
	unsigned short   _port;
	char*            _resource;
public:
	Uri();
	~Uri();
	static Uri* parse(const char* url);

};


}

#endif
