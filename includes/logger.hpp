/*
   logger.hpp -- Hyperdrive's logging system.

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
#ifndef HD_LOGGER_HPP
#define HD_LOGGER_HPP

#include "string.hpp"

namespace HD {
   /**
    * @brief Logger represents Hyperdrive logging mechanism.
    *
    * An application using Hyperdrive may have several logging instances, each
    * instance will have a dedicated subject that will be used in prefix of the
    * log messages (particularly usefull in case of multithreaded applications).
    *
    * The subject's length must be at max HD_MAX_LOGGER_SUBJECT_SIZE.
    *
    * All log messages will have the same format :
    *
    * <timestamp> [<subject>] <level> <message>
    */
   class Logger {
      public:
         /**
          * @brief Initialize a given Logger instance with the given subject.
          *
          * Initialize the internals of the calling instance with the given
          * subject. If the subject's length is greater than HD_MAX_LOGGER_SUBJECT_SIZE,
          * then it will be truncated to HD_MAX_LOGGER_SUBJECT_SIZE-1.
          *
          * All log messages will be made on stdout.
          *
          * @param subjectName the log subject to attach to the Logger instance.
          */
         Logger(const char* subjectName);
         virtual ~Logger() = default;

         /**
          * @brief Log the given message with a FATAL level.
          *
          * Log the given message for the subject in the calling instance with a
          * FATAL level (see the documentation of the class for log format detail).
          *
          * IMPORTANT : in debug builds, a call to this method will trigger an assertion failure
          * to force the program to break early.
          *
          * @param msg the message to log (supports printf format)
          * @param ... varargs for message's parameters.
          */
         void Fatal(const char* msg, ...) const;

         /**
          * @brief Log the given message with an ERROR level.
          *
          * Log the given messag for the subject in the calling instance with an
          * ERROR level (see the documentation of the class for log format detail).
          *
          * @param msg the message to log (supports printf format)
          * @param ... varargs for message's parameters.
          */
         void Error(const char* msg, ...) const;

         /**
          * @brief Log the given message with a WARN level.
          *
          * Log the given messag for the subject in the calling instance with a
          * WARN level (see the documentation of the class for log format detail).
          *
          * @param msg the message to log (supports printf format)
          * @param ... varargs for message's parameters.
          */
         void Warn(const char* msg, ...) const;

         /**
          * @brief Log the given message with an INFO level.
          *
          * Log the given messag for the subject in the calling instance with an
          * INFO level (see the documentation of the class for log format detail).
          *
          * @param msg the message to log (supports printf format)
          * @param ... varargs for message's parameters.
          */
         void Info(const char* msg, ...) const;

      private:
         HD::String subject;
   };
}; // namespace HD

#endif // HD_LOGGER_HPP