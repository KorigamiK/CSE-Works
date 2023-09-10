#include <iostream>
#include <string>
using namespace std;

/**
 * Determine the class based on the first octet
 * @param ipAddress - IP address
 * @return - 'A', 'B', 'C', 'D', 'E', or 'X'
 * */
char getIPv4Class(const string &ipAddress) {
  int firstOctet = stoi(ipAddress.substr(0, ipAddress.find(".")));
  if (firstOctet >= 1 && firstOctet <= 126) {
    return 'A';
  } else if (firstOctet >= 128 && firstOctet <= 191) {
    return 'B';
  } else if (firstOctet >= 192 && firstOctet <= 223) {
    return 'C';
  } else if (firstOctet >= 224 && firstOctet <= 239) {
    return 'D';
  } else if (firstOctet >= 240 && firstOctet <= 255) {
    return 'E';
  } else {
    return 'X'; // 'X' indicates an invalid IPv4 address
  }
}

int main(int argc, char *argv[]) {
  string ipAddress;
  cout << "Enter an IPv4 address: ";
  cin >> ipAddress;
  char ipClass = getIPv4Class(ipAddress);
  if (ipClass != 'X') {
    cout << "Class: " << ipClass << endl;
  } else {
    cout << "Invalid IPv4 address." << endl;
  }
  return 0;
}
