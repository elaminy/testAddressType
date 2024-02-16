#include <iostream>
#include <string>

using namespace std;

class addressType {
public:
    // Default constructor
    addressType() : street(""), city(""), state("XX"), zip(10000) {}

    // Parameterized constructor
    addressType(string st, string ci, string sta, int z) {
        street = st;
        city = ci;
        setState(sta);
        setZipcode(z);
    }

    // Setters with validation
    void setState(string sta) {
        if (sta.length() == 2) state = sta;
        else cout << "Invalid state. Must be 2 characters. State unchanged.\n";
    }

    void setZipcode(int z) {
        if (z >= 11111 && z <= 99999) zip = z;
        else cout << "Invalid ZIP code. Must be between 11111 and 99999. ZIP code unchanged.\n";
    }

    void setAddress(string st) { street = st; }
    void setCity(string ci) { city = ci; }

    // Getters
    string getState() const { return state; }
    int getZipcode() const { return zip; }
    string getAddress() const { return street; }
    string getCity() const { return city; }

    // Print function
    void print() const {
        cout << street << ", " << city << ", " << state << " " << zip << endl;
    }

private:
    string street, city, state;
    int zip;
};

int main() {
    cout << "Testing default constructor ... " << endl;
    addressType defAddress;
    defAddress.print();
    cout << endl;

    cout << "Testing constructor with parameters ... " << endl;
    addressType address("123 South Street", "Newport News", "VA", 23664);
    address.print();
    cout << endl;

    cout << "Testing invalid state (Virginia)... " << endl;
    address.setState("Virginia");
    address.print();
    cout << endl;

    cout << "Testing invalid ZIP code (55555555)..." << endl;
    address.setZipcode(55555555);
    address.print();
    cout << endl;

    cout << "Testing valid address ..." << endl;
    address.setAddress("44 East Main Street");
    address.setCity("Hampton");
    address.setState("VA");
    address.setZipcode(23669);
    address.print();
    cout << endl;

    return 0;
}
