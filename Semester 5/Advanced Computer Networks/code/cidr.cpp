#include <algorithm>
#include <bitset>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class CIDR {
  friend int main();
private:
  struct AddressRange {
    string networkAddress;
    int prefixLength;
  };

  vector<AddressRange> addressRanges;

public:
  void addAddressRange(string networkAddress, int prefixLength) {
    addressRanges.push_back({networkAddress, prefixLength});
  }

  bool isIPAddressInRanges(string ipAddress) {
    for (const auto &range : addressRanges) {
      string networkAddress = range.networkAddress;
      int prefixLength = range.prefixLength;

      bitset<32> networkBits(stoul(networkAddress, nullptr, 0)); // Network address to binary
      bitset<32> ipBits(stoul(ipAddress, nullptr, 0)); // IP address to binary

      bool match = true; // Check if IP address falls within the CIDR range
      for (int i = 0; i < prefixLength; ++i) {
        if (networkBits[i] != ipBits[i]) {
          match = false;
          break;
        }
      }

      if (match) return true;
    }
    return false;
  }
};

int main() {
  CIDR cidr;

  // Add CIDR address ranges
  cidr.addAddressRange("192.168.1.0", 24);
  cidr.addAddressRange("10.0.0.0", 8);
  cidr.addAddressRange("172.16.0.0", 12);

  // Print CIDR address ranges
  for (const auto &range : cidr.addressRanges) {
    cout << "Network Address: " << range.networkAddress << "/" << range.prefixLength << endl;
  }

  // Check if IP addresses are within the CIDR address ranges
  vector<string> testIPs = {"192.168.1.1", "10.1.2.3", "172.16.1.1", "8.8.8.8"};
  for (const auto &ip : testIPs) {
    if (cidr.isIPAddressInRanges(ip))
      cout << ip << " is within the CIDR address ranges." << endl;
    else
      cout << ip << " is NOT within the CIDR address ranges." << endl;
  }

  return 0;
}
