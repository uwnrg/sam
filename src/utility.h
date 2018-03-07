#ifndef SAM_UTILITY_H
#define SAM_UTILITY_H

#include "types.h"

#include <Cosa/IOStream.hh>
#include <Cosa/Serial.hh>

#include <wlib/stl/Tuple.h>

IOStream &operator<<(IOStream &ios, const string &str);

IOStream &operator<<(IOStream &ios, const vector2i &vec);

byte_array read_until(Serial &serial, size_t count, char end);

byte_array read_up_to(Serial &serial, size_t count);

byte_array read_available(Serial &serial);

byte_array read_available_until(Serial &serial, char end);

byte_array __read_unsafe(Serial &serial, size_t count);

string to_string(const byte_array &bytes);

wlp::Tuple<vector2i, uint8_t> decode_message(const byte_array &bytes);

#endif //SAM_UTILITY_H
