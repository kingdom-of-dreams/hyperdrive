#ifndef HD_STRING_HPP
#define HD_STRING_HPP

#include <vector> // TODO: Do not use dynamic STL like that.

namespace HD {
   class String {
      public:
         static String Snprintf(size_t size, const char* fmt...);

         String();
         String(const char* value, size_t maxSize = 0);
         virtual ~String();

         const char* ToCStr() const;
         int         AsWideCStr(wchar_t* outbuffer, int bufferSize) const;

         HD::String& operator=(const HD::String& origin);

      private:
         std::vector<char> nativeValue = {};
   };
} // namespace HD

#endif // HD_STRING_HPP