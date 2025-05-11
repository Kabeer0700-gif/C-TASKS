#include <iostream>
#include <exception>
using namespace std;

class DatabaseException : public exception {
public:
    const char* what() const noexcept override {
        return "A database error occurred.";
    }
};

class ConnectionFailedException : public DatabaseException {};
class QueryTimeoutException : public DatabaseException {};

void simulateDatabaseConnection(const string& dbName) {
    if (dbName == "invalid_db")
        throw ConnectionFailedException();
    else if (dbName == "slow_db")
        throw QueryTimeoutException();
    else
        cout << "Connected to " << dbName << " successfully.\n";
}

int main() {
    try {
        cout << "Attempting to connect to invalid_db...\n";
        simulateDatabaseConnection("invalid_db");
    } catch (const ConnectionFailedException& e) {
        cout << "Caught ConnectionFailedException - what(): " << e.what() << endl;
    }

    try {
        cout << "\nAttempting to connect to slow_db...\n";
        simulateDatabaseConnection("slow_db");
    } catch (const DatabaseException& e) {
        cout << "Caught a general DatabaseException - what(): " << e.what() << endl;
    }

    return 0;
}
