#include "HttpUri.h"


namespace kttp {

Uri:Uri()
:_full(NULL)
 ,_proto(NULL)
 ,_host(NULL)
 ,_port(0)
 ,_resource(NULL)
{
}

Uri:~Uri()
{
	SAFE_FREE(_full);
	SAFE_FREE(_proto);
	SAFE_FREE(_host);
	SAFE_FREE(_resource);
}

Uri* Uri::parse(const char* url)
{
	int urlLen = strlen(url);
	if(url == NULL || urlLen == 0) {
		return NULL;
	}

	char* start = NULL;
	char* end = NULL;
	bool hasPort = false;

	Uri* uri = new Uri();
	uri->_full = strdup(url);

	 /* check to make sure that there was a : in the string */
	start = strchr(url,':');
	if(!start) {
		goto error;
	}

	int protoLen = start - url;
	uri->_proto = (char*)malloc(protoLen + 1);
	if(!uri->_proto) goto error;
	memcpy(uri->_proto,url, protoLen);
	uri->_proto[protoLen] = '\0';

	/* check to make sure it starts with "http://" */
	if(strncmp(start, "://", 3) != 0) goto error;
	/* start at the beginning of the string */
	start = end = &(start[3]);
	while(end)
	{
		if(*end == ':')
		{
			hasPort = true
			int hostLen = end - start;
			uri->_host = (char*)malloc(hostLen + 1);
			memcpy(uri->_host,start,hostLen);
			uri->_host[hostLen] = '\0';
			start = end;
		}
		else if(*end == '/')
		{
			if(hasPort) {
				int hostLen = end - start;
				uri->_host = (char*)malloc(hostLen + 1);
				memcpy(uri->_host,start,hostLen);
				uri->_host[hostLen] = '\0';
				start = end;
			} else {
				int hostLen = end - start;
				uri->_host = (char*)malloc(hostLen + 1);
				memcpy(uri->_host,start,hostLen);
				uri->_host[hostLen] = '\0';
				start = end;
			}
			int resLen = urlLen - (end - url);
			uri->_resource = (char*)malloc(resLen + 1);
			memcpy(uri->_resource,end,resLen);
			uri->_resource[resLen] = '\0';
			break;
		}

		end++;
	}

	return uri;

error:
	return NULL;
}



}
