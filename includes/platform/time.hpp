/*
   time.hpp -- Hyperdrive's time manipulation module.

   Copyright 2025 by Sylvain Nieuwlandt (for Kingdom of Dreams)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/
#ifndef HD_PLATFORM_TIME_HPP
#define HD_PLATFORM_TIME_HPP

#include "constants.hpp"

namespace HD::Platform {
   /**
    * @brief Time is a time representation of a specific timestamp, common
    *  for all kind of platform, that will be use to manipulate time through
    *  Hyperdrive functions.
    *
    * Because every OS has it's own structure, function, and adapter for
    * manipulating time, we will provide our own which will be considered as
    * the only way to manipulate time in a Hyperdrive system.
    *
    * Some fields in this structure might not be supported by one of the
    * specific system Hyperdrive will run on. In that case, this field will
    * be positioned to its default value (0 in case of int).
    *
    * We strongly recommand to not fill an instance of this structure manually
    * but instead to use one of the supported platform's adapter of Hyperdrive.
    * If you don't find an adapter for your needs, we can either open an issue
    * for asking us to add it, or implement one yourself (you only need to
    * conform to every headers in the platform folder), and if you do so and
    * you have the possibility, we'll love a contribution to our engine !
    */
   class Time {
      public:
         inline Time() : year(0), month(0), day(0), hours(0), minutes(0), seconds(0), milliseconds(0) {};
         virtual ~Time() = default;

         /**
          * @brief Fill the calling instance with the current time on the calling system.
          *
          * @return HD::Codes::OK in case of success, HD::Codes::PLATFORM_ERROR if a platform's
          *       specific error occurs.
          */
         HD::Result Now();

         inline int GetYear() const {
            return this->year;
         }

         inline int GetMonth() const {
            return this->month;
         }

         inline int GetDay() const {
            return this->day;
         }

         inline int GetHours() const {
            return this->hours;
         }

         inline int GetMinutes() const {
            return this->minutes;
         }

         inline int GetSeconds() const {
            return this->seconds;
         }

         inline int GetMilliseconds() const {
            return this->milliseconds;
         }

      protected:
         int year;
         int month;
         int day;
         int hours;
         int minutes;
         int seconds;
         int milliseconds;
   };
}; // namespace HD::Platform

#endif