#include <iostream>
#include <queue>

using namespace std;

class LeakyBucket {
private:
  int bucketSize;     // Size of the bucket
  int leakRate;       // Rate at which packets leak from the bucket
  queue<int> packets; // Queue of packets waiting to be transmitted

public:
  LeakyBucket(int bucketSize, int leakRate) {
    this->bucketSize = bucketSize;
    this->leakRate = leakRate;
  }
  bool addPacket(int packetSize) {
    if (packets.size() + packetSize > bucketSize)
      return false; // Bucket is full, discard packet

    packets.push(packetSize); // Add packet to the queue
    return true;
  }
  void transmitPackets() {
    while (!packets.empty()) {
      int packetSize = packets.front(); // Remove a packet from the queue
      packets.pop();
      // Transmit the packet
      cout << "Transmitting packet of size: " << packetSize << endl;
      // Adjust the bucket size based on the leak rate
      bucketSize -= leakRate;
    }
  }
};

int main() {
  LeakyBucket leakyBucket(10, 2); // Bucket size = 10, leak rate = 2

  // Add some packets to the bucket
  leakyBucket.addPacket(3);
  leakyBucket.addPacket(5);
  leakyBucket.addPacket(4);

  // Transmit packets
  leakyBucket.transmitPackets();
  return 0;
}
