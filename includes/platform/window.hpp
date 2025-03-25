#ifndef HD_PLATFORM_WINDOW_H
#define HD_PLATFORM_WINDOW_H

#ifndef NATIVE_PLATFORM_WINDOW_TYPE
#define NATIVE_PLATFORM_WINDOW_TYPE void*
#endif

#include "constants.hpp"
#include "string.hpp"

namespace HD::Platform {
   class Window {
      public:
         Window() : handle(nullptr), shown(false) {};
         virtual ~Window() = default;

         virtual HD::Result Initialize(const HD::String& title, int width, int height) {
            return HD::Codes::OK;
         };

         virtual void Show() {};
         virtual void PeekEvent() {};

         virtual int GetWidth() const {
            return 0;
         };

         virtual int GetHeight() const {
            return 0;
         }

         inline NATIVE_PLATFORM_WINDOW_TYPE GetHandle() const {
            return this->handle;
         }

         inline bool IsShown() const {
            return this->shown;
         }

      protected:
         NATIVE_PLATFORM_WINDOW_TYPE handle;
         bool                        shown;
   };
}; // namespace HD::Platform

#endif // HD_PLATFORM_WINDOW_HPP
