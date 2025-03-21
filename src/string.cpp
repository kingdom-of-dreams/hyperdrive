#include <string.hpp>

#include <vector>
#include <cstdarg>
#include <cstdio>
#include <cstring>

HD::String HD::String::Snprintf(size_t size, const char* fmt, ...) {
   HD::String result;
   result.nativeValue.assign(size + 1, '\0');
   va_list args;
   va_start(args, fmt);
   (void) vsnprintf(result.nativeValue.data(), size, fmt, args);
   va_end(args);

   return result;
}

HD::String::String() : String("") {}

HD::String::String(const char* originValue, size_t maxSize) {
   size_t valueSize = strlen(originValue);
   if (maxSize > 0) {
      valueSize = maxSize;
   }
   this->nativeValue.resize(valueSize + 1);
   this->nativeValue.assign(valueSize + 1, '\0');
   strncpy(this->nativeValue.data(), originValue, valueSize);
}

HD::String::~String() = default;

const char* HD::String::ToCStr() const {
   return this->nativeValue.data();
}

HD::String& HD::String::operator=(const HD::String& origin) {
   if (this == &origin) {
      return *this;
   }

   this->nativeValue = std::vector<char>(origin.nativeValue);
   return *this;
}