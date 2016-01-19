#ifndef HTTP_H
#define HTTP_H

#include <sys/socket.h>

#define DELETE(p)           do { delete (p); (p) = nullptr; } while(0)
#define DELETE_ARRAY(p)     do { delete[] (p); (p) = nullptr; } while(0)
#define FREE(p)             do { free(p); (p) = nullptr;} while(0)
#define RELEASE(p)          do { (p)->release(); } while(0)
#define RELEASE_NULL(p)     do { (p)->release(); (p) = nullptr; } while(0)
#define BREAK_IF(cond)           if(cond) break

namespace kttp {

typedef enum _HttpErrorType {
	HttpErrorType_host = 0,
	HttpErrorType_errno
} HttpErrorType;

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

	Http();
	~Http();

	int connect();

private:
	struct hostent* _hostInfo;
	int sockFd;
	struct sockaddr_in _serverAddr;
	socklen_t len;
	
	char* _host;
	char* _proxyHost;
	short _port;
	short _proxyPort;

	HttpErrorType _errorType;
	int   _error;
	char* _errorStr;

	int                  sync;              /* sync or async? */
  	char                *io_buf;            /* buffer */
  	int                  io_buf_len;        /* how big is it? */
  	int                  io_buf_alloc;      /* how much is used */
  	int                  io_buf_io_done;    /* how much have we already moved? */
  	int                  io_buf_io_left;    /* how much data do we have left? */
  	int                  io_buf_chunksize;  /* how big should the chunks be that get
					    read in and out be? */
  	int                  last_read;         /* the size of the last read */
  	int                  chunk_len;         /* length of a chunk. */

};


}

#endif
