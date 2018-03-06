#ifndef SAM_UTILITY_H
#define SAM_UTILITY_H

#include "types.h"

#include <Cosa/IOStream.hh>
#include <Cosa/Serial.hh>

#include <wlib/stl/Tuple.h>

IOStream &operator<<(IOStream &ios, const string &str);

byte_array read_available(Serial &serial);

string to_string(const byte_array &bytes);

wlp::Tuple<vector2i, uint8_t> decode_message(const byte_array &bytes);

#endif //SAM_UTILITY_H
