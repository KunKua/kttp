#include "HttpHeader.h"
#include <stdlib.h>
#include <string.h>

namespace kttp {

#define HTTP_HDRS_MAX     256
#define HEADER_INCREMENT   10
#define HEADER_BASE        10


/* entity headers */
const char HTTP_HEADER_Allow[] = "Allow";
const char HTTP_HEADER_Content_Encoding[] = "Content-Encoding";
const char HTTP_HEADER_Content_Language[] = "Content-Language";
const char HTTP_HEADER_Content_Length[] = "Content-Length";
const char HTTP_HEADER_Content_Location[] = "Content-Location";
const char HTTP_HEADER_Content_MD5[] = "Content-MD5";
const char HTTP_HEADER_Content_Range[] = "Content-Range";
const char HTTP_HEADER_Content_Type[] = "Content-Type";
const char HTTP_HEADER_Expires[] = "Expires";
const char HTTP_HEADER_Last_Modified[] = "Last-Modified";

/* general headers */
const char HTTP_HEADER_Cache_Control[] = "Cache-Control";
const char HTTP_HEADER_Connection[] = "Connection";
const char HTTP_HEADER_Date[] = "Date";
const char HTTP_HEADER_Pragma[] = "Pragma";
const char HTTP_HEADER_Transfer_Encoding[] = "Transfer-Encoding";
const char HTTP_HEADER_Update[] = "Update";
const char HTTP_HEADER_Trailer[] = "Trailer";
const char HTTP_HEADER_Via[] = "Via";

/* request headers */
const char HTTP_HEADER_Accept[] = "Accept";
const char HTTP_HEADER_Accept_Charset[] = "Accept-Charset";
const char HTTP_HEADER_Accept_Encoding[] = "Accept-Encoding";
const char HTTP_HEADER_Accept_Language[] = "Accept-Language";
const char HTTP_HEADER_Authorization[] = "Authorization";
const char HTTP_HEADER_Expect[] = "Expect";
const char HTTP_HEADER_From[] = "From";
const char HTTP_HEADER_Host[] = "Host";
const char HTTP_HEADER_If_Modified_Since[] = "If-Modified-Since";
const char HTTP_HEADER_If_Match[] = "If-Match";
const char HTTP_HEADER_If_None_Match[] = "If-None-Match";
const char HTTP_HEADER_If_Range[] = "If-Range";
const char HTTP_HEADER_If_Unmodified_Since[] = "If-Unmodified-Since";
const char HTTP_HEADER_Max_Forwards[] = "Max-Forwards";
const char HTTP_HEADER_Proxy_Authorization[] = "Proxy-Authorization";
const char HTTP_HEADER_Range[] = "Range";
const char HTTP_HEADER_Referrer[] = "Referrer";
const char HTTP_HEADER_TE[] = "TE";
const char HTTP_HEADER_User_Agent[] = "User-Agent";

/* response headers */

const char HTTP_HEADER_Accept_Ranges[] = "Accept-Ranges";
const char HTTP_HEADER_Age[] = "Age";
const char HTTP_HEADER_ETag[] = "ETag";
const char HTTP_HEADER_Location[] = "Location";
const char HTTP_HEADER_Retry_After[] = "Retry-After";
const char HTTP_HEADER_Server[] = "Server";
const char HTTP_HEADER_Vary[] = "Vary";
const char HTTP_HEADER_Warning[] = "Warning";
const char HTTP_HEADER_WWW_Authenticate[] = "WWW-Authenticate";


const char *HTTP_HEADER_known_list[] =
{
  /* entity headers */
  HTTP_HEADER_Allow,
  HTTP_HEADER_Content_Encoding,
  HTTP_HEADER_Content_Language,
  HTTP_HEADER_Content_Length,
  HTTP_HEADER_Content_Location,
  HTTP_HEADER_Content_MD5,
  HTTP_HEADER_Content_Range,
  HTTP_HEADER_Content_Type,
  HTTP_HEADER_Expires,
  HTTP_HEADER_Last_Modified,
  /* general headers */
  HTTP_HEADER_Cache_Control,
  HTTP_HEADER_Connection,
  HTTP_HEADER_Date,
  HTTP_HEADER_Pragma,
  HTTP_HEADER_Transfer_Encoding,
  HTTP_HEADER_Update,
  HTTP_HEADER_Trailer,
  HTTP_HEADER_Via,
  /* request headers */
  HTTP_HEADER_Accept,
  HTTP_HEADER_Accept_Charset,
  HTTP_HEADER_Accept_Encoding,
  HTTP_HEADER_Accept_Language,
  HTTP_HEADER_Authorization,
  HTTP_HEADER_Expect,
  HTTP_HEADER_From,
  HTTP_HEADER_Host,
  HTTP_HEADER_If_Modified_Since,
  HTTP_HEADER_If_Match,
  HTTP_HEADER_If_None_Match,
  HTTP_HEADER_If_Range,
  HTTP_HEADER_If_Unmodified_Since,
  HTTP_HEADER_Max_Forwards,
  HTTP_HEADER_Proxy_Authorization,
  HTTP_HEADER_Range,
  HTTP_HEADER_Referrer,
  HTTP_HEADER_TE,
  HTTP_HEADER_User_Agent,
  /* response headers */
  HTTP_HEADER_Accept_Ranges,
  HTTP_HEADER_Age,
  HTTP_HEADER_ETag,
  HTTP_HEADER_Location,
  HTTP_HEADER_Retry_After,
  HTTP_HEADER_Server,
  HTTP_HEADER_Vary,
  HTTP_HEADER_Warning,
  HTTP_HEADER_WWW_Authenticate,
  NULL
};

static const char* isKnownHeader(const char* hdr)
{
	if(hdr == NULL) return NULL;

	int pos = 0;
	const char* result = NULL;

	while(HTTP_HEADER_known_list[pos] != NULL) {
		if(strcasecmp(hdr,HTTP_HEADER_known_list[pos]) == 0) {
			result = HTTP_HEADER_known_list[pos];
			break;
		}
		pos++;
	}

	return result;
}

HttpHeader::HttpHeader()
{

}

HttpHeader::~HttpHeader()
{

}

int HttpHeader::set(const char* name, const char* value)
{

}

char* HttpHeader::get(const char* name)
{

}

int HttpHeader::clear(const char* name)
{

}

}
