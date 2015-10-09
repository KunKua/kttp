#ifndef HTTP_H
#define HTTP_H

#include <sys/socket.h>

#define SAFE_DELETE(p)           do { delete (p); (p) = nullptr; } while(0)
#define SAFE_DELETE_ARRAY(p)     do { if(p) { delete[] (p); (p) = nullptr; } } while(0)
#define SAFE_FREE(p)             do { if(p) { free(p); (p) = nullptr; } } while(0)
#define SAFE_RELEASE(p)          do { if(p) { (p)->release(); } } while(0)
#define SAFE_RELEASE_NULL(p)     do { if(p) { (p)->release(); (p) = nullptr; } } while(0)
#define SAFE_RETAIN(p)           do { if(p) { (p)->retain(); } } while(0)
#define BREAK_IF(cond)           if(cond) break



namespace kttp {

typedef enum _Method {
	GET = 1,
	POST = 2
} Method;

typedef struct _Request {
	struct hostent _host;
	int _port;
	Method _method;
	char* _location;
	char* _queryStr;
} Request;

typedef struct _SendBuffer {
	char* _buffer;
	size_t _used;
	size_t _max;
} SendBuffer;

class Http
{
public:
	static Data* get(const char* url,Data& requestData,int retryNum);
	static Data* post(const char* url,Data& requestData,int retryNum);

private:
	int sockfd;
	struct sockaddr_in servaddr;
	socklen_t len;
	fd_set   t_set1;
	struct timeval  tv;
};


}

#endif
