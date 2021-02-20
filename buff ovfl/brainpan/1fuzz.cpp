#include <iostream>
#include "../helper.cpp"
#include <boost/asio.hpp>

using namespace std;
using namespace NAM;
using namespace boost;

#define errormayhappen                                \
    if (ec.value())                                   \
    {                                                 \
        cerr << "\nError : " << ec.message() << "\n"; \
        return ec.value();                            \
    }

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Error : requires ip and port to connect to";
        return 0;
    }

    for (int i = 0; i < 25; i++)
    {
        string payload = createstr('A', i * 100);
        cout << "Fuzzing with " << i * 100 << " bytes\n\n";
            //*****************

            asio::io_service ioservice;
        system::error_code ec;
        asio::ip::address ip = asio::ip::address::from_string(argv[1], ec);
        errormayhappen;
        asio::ip::tcp::endpoint sep(ip, atoi(argv[2]));

        asio::ip::tcp::socket client(ioservice);
        asio::ip::tcp protocol = asio::ip::tcp::v4();
        client.open(protocol, ec);
        errormayhappen;

        client.connect(sep, ec);
        errormayhappen;

        client.write_some(asio::buffer(payload), ec);

        client.close(ec);
        errormayhappen;

        //################
    }
}