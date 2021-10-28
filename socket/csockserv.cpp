#include <iostream>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

using namespace std;

int main(int argc, char **argv)
{
    sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(80);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        cerr << "Error : Socket Creation Error";
        return 0;
    }

    if (bind(sockfd, (sockaddr *)&address, sizeof(address)) < 0)
    {
        cerr << "Error : Binding Error";
        return 0;
    }

    if (listen(sockfd, 5) < 0)
    {
        cerr << "Error : Listening Error";
        return 0;
    }

    int csock;
    sockaddr_in caddr;
    socklen_t clen;
    csock = accept(sockfd, (sockaddr *)&caddr, &clen);

    char data[1024];
    int rd = recv(csock, data, 1024, 0);
    if (rd < 0)
    {
        cerr << "Error : Recieve Error";
        return 0;
    }

    cout << "\n"
         << rd << " Bytes Recieved";
    cout << "\n"
         << data;

    strcpy(data, "Empty Response !! Bye From Server");
    int sd = send(csock, data, strlen(data), 0);
    if (sd < 0)
    {
        cerr << "Error : Data Send Error";
        return 0;
    }

    cout << "\n" << sd << " Bytes sent";
    cout << "\n" << strlen(data);

    if (close(sockfd) < 0)
    {
        cerr << "Error : Unable To Close Server Socket";
        return 0;
    }

    return 0;
}