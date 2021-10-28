#include <string.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        cerr << "Usage : " << argv[0] << " <ip> <port>";
        return 0;
    }

    sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(argv[1]);
    address.sin_port = htons(atoi(argv[2]));

    int clsock = socket(AF_INET, SOCK_STREAM, 0);
    if (clsock < 0)
    {
        cerr << "Error : Cannot Create Socket";
        return 0;
    }

    if (connect(clsock, (sockaddr *)&address, sizeof(sockaddr_in)) < 0)
    {
        cerr << "Error : Connection Error";
        return 0;
    }

    cout << "Connected";

    char data[2000];
    strcpy(data, "Hi Server ,\nThis is your client");

    int sd = send(clsock, data, strlen(data), 0);
    if (sd < 0)
    {
        cerr << "Error : Data Send Error";
        return 0;
    }

    cout << "\n"
         << sd << " Bytes sent";
    cout << "\n"
         << strlen(data);

    memset(data, 0, 2000);

    int rd = recv(clsock, data, 2000, 0);
    if (rd < 0)
    {
        cerr << "Error : Recieve Error";
        return 0;
    }

    cout << "\n"
         << rd << " Bytes Recieved";
    cout << "\n"
         << data;

    if (close(clsock) < 0)
    {
        cerr << "Error : Cannot Close";
        return 0;
    }

    return 0;
}