/*
   logger.c -- Hyperdrive's logging system implementation.

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

#include "logger.hpp"

#include "assert.hpp"
#include "platform/time.hpp"
#include "string.hpp"

#include <cstdarg>
#include <cstdio>
#include <cstdlib>

constexpr int HD_MAX_SUBJECT_SIZE    = 32;
constexpr int HD_MAX_LOGGER_MSG_SIZE = 256;

namespace {
   void log(const HD::String& subject, const char* lvl, const HD::String& msg) {
      HD::Platform::Time time;
      HD_ASSERT_OK(time.Now());

      printf("%04d-%02d-%02d %02d:%02d:%02d.%03d - [%15s] %7s : %s\n", time.GetYear(), time.GetMonth(), time.GetDay(),
             time.GetHours(), time.GetMinutes(), time.GetSeconds(), time.GetMilliseconds(), subject.ToCStr(), lvl,
             msg.ToCStr());
   }
}; // namespace

#define GLOBAL_LOG(subject, level, msg)                                                                                     \
   va_list varargs = NULL;                                                                                                  \
   va_start(varargs, msg);                                                                                                  \
   const HD::String message = HD::String::Snprintf(HD_MAX_LOGGER_MSG_SIZE, msg, varargs);                                   \
   va_end(varargs);                                                                                                         \
   log(subject, level, message);

HD::Logger::Logger(const char* subjectName) {
   HD_ASSERT_NOT_NULL(subjectName);
   this->subject = HD::String(subjectName, HD_MAX_SUBJECT_SIZE);
}

void HD::Logger::Fatal(const char* msg, ...) const {
   HD_ASSERT_NOT_NULL(msg);
   GLOBAL_LOG(this->subject, "FATAL", msg);
   HD_ASSERT_FAIL(); // Force abort in debug.
}

void HD::Logger::Error(const char* msg, ...) const {
   HD_ASSERT_NOT_NULL(msg);
   GLOBAL_LOG(this->subject, "ERROR", msg);
}

void HD::Logger::Warn(const char* msg, ...) const {
   HD_ASSERT_NOT_NULL(msg);
   GLOBAL_LOG(this->subject, "WARNING", msg);
}

void HD::Logger::Info(const char* msg, ...) const {
   HD_ASSERT_NOT_NULL(msg);
   GLOBAL_LOG(this->subject, "INFO", msg);
}