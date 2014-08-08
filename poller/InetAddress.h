#ifndef INET_ADDRESS_H_
#define INET_ADDRESS_H_ 

#include "Copyable.h"
#include <strings.h>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

//InetAddress对sockaddr_in做了一些简单的包装

typedef struct sockaddr SA;

class InetAddress : Copyable
{
	public:
		explicit InetAddress(uint16_t port);
		InetAddress(const struct sockaddr_in &addr);
		
		const struct sockaddr_in *getSockAddrInet() const;

		void setSockAddrInet(const struct sockaddr_in &addr);

		uint32_t ipNetEndian() const;

		uint16_t portNetEndian() const;

		std::string toIp() const;
		uint16_t toPort() const;

		static InetAddress getLocalAddress(int sockfd);
		static InetAddress getPeerAddress(int sockfd);
	private:
		struct sockaddr_in addr_;
};

inline InetAddress::InetAddress(const struct sockaddr_in &addr)
	:addr_(addr)
{}

inline const struct sockaddr_in *InetAddress::getSockAddrInet() const
{
	return &addr_;
}

inline void InetAddress::setSockAddrInet(const struct sockaddr_in &addr)
{
	addr_ = addr;
}

inline uint32_t InetAddress::ipNetEndian() const
{
	return addr_.sin_addr.s_addr;
}

inline uint16_t InetAddress::portNetEndian() const
{
	return addr_.sin_port;
}

inline std::string InetAddress::toIp() const
{
	return std::string(inet_ntoa(addr_.sin_addr));
}

inline uint16_t InetAddress::toPort() const
{
	return ntohs(addr_.sin_port);
}

#endif  /*INET_ADDRESS_H_*/
