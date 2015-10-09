#ifndef HTTP_HEADER_H
#define HTTP_HEADER_H

namespace kttp {

class HttpHeader
{
public:
	HttpHeader();
	~HttpHeader();

	int set(const char* name, const char* value);
	char* get(const char* name);
	int clear(const char* name);
private:
	void checkSize();
private:
	char** _header;
	char** _value;

	int _num;
	int _size;
};


}

#endif
