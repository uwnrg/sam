#include "utility.h"

IOStream &operator<<(IOStream &ios, const string &str) {
    return ios << str.c_str();
}

byte_array read_available(Serial &serial) {
    auto count = static_cast<size_t>(serial.available());
    byte_array bytes(count);
    while (count--) {
        bytes.push_back(static_cast<char>(serial.getchar()));
    }
    return bytes;
}

string to_string(const byte_array &bytes) {
    return {bytes.data(), bytes.size()};
}

wlp::Tuple<vector2i, uint8_t> decode_message(const byte_array &bytes) {
    int16_t x = *reinterpret_cast<const int16_t *>(bytes.data());
    int16_t y = *reinterpret_cast<const int16_t *>(bytes.data() + 2);
    auto time = static_cast<uint8_t>(bytes[4]);
    return wlp::make_tuple(vector2i(x, y), time);
};
