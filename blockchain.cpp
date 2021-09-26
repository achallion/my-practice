#include <ctime>
#include <vector>
#include <string>

using namespace std;

// transaction data
struct TransactionData
{
    double amount;
    string senderkey;
    string receiverkey;
    time_t timestamp;
};

// block class
class block
{

private:
    int index;
    size_t blockhash;
    size_t previoushash;
    size_t generatehash();

public:
    TransactionData data;

    block(int, TransactionData &, size_t);
    size_t gethash();
    size_t getprevioushash();
    bool ishashvalid();
};

// block chain class