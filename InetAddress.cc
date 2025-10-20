#include "InetAddress.h"

#include <strings.h>
#include <cstring>
InetAddress::InetAddress(uint16_t port, std::string ip)
{
    bzero(&addr_, sizeof addr_);
    addr_.sin_family = AF_INET;
    addr_.sin_port = htons(port);
    addr_.sin_addr.s_addr = inet_addr(ip.c_str());
}
std::string InetAddress::toIp() const
{
    // addr_
    char buf[64] = {0};
    //inet_ntop用于将网络地址（通常是 IP 地址）从二进制形式（struct in_addr 或 struct in6_addr）
    //转换为标准的文本表示形式
    ::inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof buf);
    return buf;
}
std::string InetAddress::toIpPort() const
{
    // ip:port
    char buf[64] = {0};
    ::inet_ntop(AF_INET, &addr_.sin_addr, buf, sizeof buf);
    size_t end = strlen(buf);
    uint16_t port = ntohs(addr_.sin_port);
    sprintf(buf + end, ":%u", port);
    return buf;
}
uint16_t InetAddress::toPort() const
{
    return ntohs(addr_.sin_port);
}

// #include <iostream>
// int main()
// {
//     InetAddress addr(8080);
//     std::cout << addr.toIpPort() << std::endl;

//     return 0;
// }