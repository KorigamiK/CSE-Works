#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

const int WINDOW_SIZE = 4;
const int MAX_SEQ_NUM = 7;

struct Frame {
  int seqNum;
  string data;
  bool acked;
};

class GoBackN {
private:
  int nextSeqNum;
  Frame frames[WINDOW_SIZE];

public:
  int base;
  GoBackN() : base(0), nextSeqNum(0) {
    for (int i = 0; i < WINDOW_SIZE; ++i) {
      frames[i].seqNum = -1; // initialize with invalid sequence number
      frames[i].acked = false;
    }
  }

  void sendFrame(string data) {
    if (nextSeqNum < base + WINDOW_SIZE) {
      int currentIndex = nextSeqNum % WINDOW_SIZE;
      frames[currentIndex].seqNum = nextSeqNum;
      frames[currentIndex].data = data;
      frames[currentIndex].acked = false;

      cout << "Sending Frame with SeqNum: " << nextSeqNum << " : " << data
           << endl;

      if (base == nextSeqNum)
        startTimer(); // Start a timer for the oldest unacknowledged frame

      nextSeqNum++;
    } else {
      cout << "Window is full. Cannot send more frames." << endl;
    }
  }

  void receiveAck(int ackNum) {
    if (ackNum >= base && ackNum < base + WINDOW_SIZE) {
      int ackIndex = ackNum % WINDOW_SIZE;
      frames[ackIndex].acked = true;
      cout << "Received ACK for SeqNum: " << ackNum << endl;

      // Slide the window forward
      while (frames[base % WINDOW_SIZE].acked) {
        stopTimer();
        base++;
        if (nextSeqNum < base + WINDOW_SIZE) {
          // Start a timer for the next unacknowledged frame
          startTimer();
        }
      }
    }
  }

  void startTimer() {
    cout << "Timer Started for SeqNum: " << base << endl; // Simulate starting a timer
  }

  void stopTimer() {
    cout << "Timer Stopped for SeqNum: " << base << endl; // Simulate stopping a timer
  }
};

int main() {
  srand(time(0)); // Seed for random data
  GoBackN sender;
  // Simulate sending frames
  for (int i = 0; i < 10; ++i) {
    string data = "Data" + to_string(i);
    sender.sendFrame(data);

    // Simulate random ACK reception
    if (rand() % 2 == 0) {
      int ackNum = sender.base + rand() % WINDOW_SIZE;
      sender.receiveAck(ackNum);
    }
  }

  return 0;
}
