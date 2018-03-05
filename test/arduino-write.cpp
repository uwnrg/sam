#include <fstream>
#include <iostream>
using namespace std;

int main() {
  int data[3] = {1, 3, 4};
  ofstream file;
  file.open("/dev/ttyUSB0");
  for (int i = 0; i < 3; i++) {
    file << data[i];
    file << ',';
  }
  file.close();
  return 1;
}
