#include "utility.h"


IOStream &operator<<(IOStream &ios, const string &str) {
    return ios << str.c_str();
}

IOStream &operator<<(IOStream &ios, const vector2i &vec) {
    return ios << '(' << vec.x() << ',' << ' ' << vec.y() << ')';
}

byte_array read_until(Serial &serial, size_t count, char end) {
    auto available = static_cast<size_t>(serial.available());
    byte_array bytes(count);
    char *s = bytes.data();
    char c;
    while (available--) {
        c = serial.getchar();
        bytes.push_back(c);
        if (c == end) { break; }
    }
    return bytes;
}

byte_array read_up_to(Serial &serial, size_t count) {
    auto available = static_cast<size_t>(serial.available());
    if (count > available) { count = available; }
    return __read_unsafe(serial, count);
}

byte_array read_available(Serial &serial) {
    auto available = static_cast<size_t>(serial.available());
    return __read_unsafe(serial, available);
}

byte_array read_available_until(Serial &serial, char end) {
    auto available = static_cast<size_t>(serial.available());
    char c;
    byte_array bytes(available);
    while(available-- && (c = static_cast<char>(serial.getchar()) != end)) {
        bytes.push_back(c);
    }
    return bytes;
}

byte_array __read_unsafe(Serial &serial, size_t count) {
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
