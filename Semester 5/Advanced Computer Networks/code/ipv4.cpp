#include <bitset>
#include <iostream>
#include <string>
using namespace std;
/*
 * Function to convert binary IP address to dotted decimal
 * @param binaryIP - binary IP address
 * @return dottedDecimal - dotted decimal IP address
 * */
string binaryToDottedDecimal(const string &binaryIP) {
  string dottedDecimal = "";
  for (int i = 0; i < 32; i += 8) {
    bitset<8> octet(binaryIP.substr(i, 8));
    dottedDecimal += to_string(octet.to_ulong());
    if (i < 24)
      dottedDecimal += ".";
  }
  return dottedDecimal;
}

/*
 *Function to convert dotted decimal IP address to binary
 * @param dottedDecimal - dotted decimal IP address
 * @return binaryIP - binary IP address
 * */
string dottedDecimalToBinary(const string &dottedDecimal) {
  string binaryIP = "";
  size_t start = 0;
  size_t end = dottedDecimal.find(".");
  while (end != string::npos) {
    int octet = stoi(dottedDecimal.substr(start, end - start));
    binaryIP += bitset<8>(octet).to_string();
    start = end + 1;
    end = dottedDecimal.find(".", start);
  }
  int octet = stoi(dottedDecimal.substr(start));
  binaryIP += bitset<8>(octet).to_string();
  return binaryIP;
}

int main() {
  char choice;
  cout << "1. Binary to dotted decimal IP address\n"
          "2. Dotted decimal to binary IP address\n";
  cout << "Enter your choice: " << endl;
  cin >> choice;

  if (choice == '1') {
    string binaryIP;
    cout << "Enter binary IP address (32 bits): ";
    cin >> binaryIP;
    string dottedDecimal = binaryToDottedDecimal(binaryIP);
    cout << "Dotted Decimal IP address: " << dottedDecimal << endl;
  } else if (choice == '2') {
    string dottedDecimal;
    cout << "Enter dotted decimal IP address (e.g., 192.168.1.1): ";
    cin >> dottedDecimal;
    string binaryIP = dottedDecimalToBinary(dottedDecimal);
    cout << "Binary IP address: " << binaryIP << endl;
  } else {
    cout << "Invalid choice. Please enter '1' or '2'." << endl;
  }

  return 0;
}
