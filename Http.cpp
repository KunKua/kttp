#include "http.h"

#include <stdio.h>

#include <sys/types.h>
#include <time.h>
#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IPSTR "61.147.124.120"
#define PORT 80
#define BUFSIZE 1024

Http::get(const char* url,Data& requestData,int retryNum)
{
	int sockfd, ret, i, h;

	if((hptr = gethostbyname(ptr)) == NULL)
	{
	    printf(" gethostbyname error for host:%s\n", ptr);
	    return 0;
	}

	struct sockaddr_in servaddr;
	        char str1[4096], str2[4096], buf[BUFSIZE], *str;
	        socklen_t len;
	        fd_set   t_set1;
	        struct timeval  tv;

	        if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ) {
	                printf("创建网络连接失败,本线程即将终止---socket error!\n");
	                exit(0);
	        };

	        bzero(&servaddr, sizeof(servaddr));
	        servaddr.sin_family = AF_INET;
	        servaddr.sin_port = htons(PORT);
	        if (inet_pton(AF_INET, IPSTR, &servaddr.sin_addr) <= 0 ){
	                printf("创建网络连接失败,本线程即将终止--inet_pton error!\n");
	                exit(0);
	        };

	        if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0){
	                printf("连接到服务器失败,connect error!\n");
	                exit(0);
	        }
	        printf("与远端建立了连接\n");

	        //发送数据
	        memset(str2, 0, 4096);
	        strcat(str2, "qqCode=474497857");
	        str=(char *)malloc(128);
	        len = strlen(str2);
	        sprintf(str, "%d", len);

	        memset(str1, 0, 4096);
	        strcat(str1, "POST /webservices/qqOnlineWebService.asmx/qqCheckOnline HTTP/1.1\n");
	        strcat(str1, "Host: www.webxml.com.cn\n");
	        strcat(str1, "Content-Type: application/x-www-form-urlencoded\n");
	        strcat(str1, "Content-Length: ");
	        strcat(str1, str);
	        strcat(str1, "\n\n");

	        strcat(str1, str2);
	        strcat(str1, "\r\n\r\n");
	        printf("%s\n",str1);

	        ret = write(sockfd,str1,strlen(str1));
	        if (ret < 0) {
	                printf("发送失败！错误代码是%d，错误信息是'%s'\n",errno, strerror(errno));
	                exit(0);
	        }else{
	                printf("消息发送成功，共发送了%d个字节！\n\n", ret);
	        }

	        FD_ZERO(&t_set1);
	        FD_SET(sockfd, &t_set1);

	        while(1){
	                sleep(2);
	                tv.tv_sec= 0;
	                tv.tv_usec= 0;
	                h= 0;
	                printf("--------------->1");
	                h= select(sockfd +1, &t_set1, NULL, NULL, &tv);
	                printf("--------------->2");

	                //if (h == 0) continue;
	                if (h < 0) {
	                        close(sockfd);
	                        printf("在读取数据报文时SELECT检测到异常，该异常导致线程终止！\n");
	                        return -1;
	                };

	                if (h > 0){
	                        memset(buf, 0, 4096);
	                        i= read(sockfd, buf, 4095);
	                        if (i==0){
	                                close(sockfd);
	                                printf("读取数据报文时发现远端关闭，该线程终止！\n");
	                                return -1;
	                        }

	                        printf("%s\n", buf);
	                }
	        }
	        close(sockfd);
}

Http::Uri:Uri()
:_full(NULL)
 ,_proto(NULL)
 ,_host(NULL)
 ,_port(0)
 ,_resource(NULL)
{
}

Http::Uri:~Uri()
{
	SAFE_FREE(_full);
	SAFE_FREE(_proto);
	SAFE_FREE(_host);
	SAFE_FREE(_resource);
}

Http::Uri* Http::Uri::parse(const char* url)
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