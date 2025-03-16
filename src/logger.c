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
#define _CRT_SECURE_NO_WARNINGS 1

#include "logger.h"

#include "assert.h"
#include "platform/time.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>


void log(const char* subject, const char* lvl, const char* msg);

void hd_logger_init(hd_logger* out, const char* in_subject) {
   HD_ASSERT_NOT_NULL(out);
   HD_ASSERT_NOT_NULL(in_subject);
   memset(out->subject, '\0', HD_MAX_LOGGER_SUBJECT_SIZE);
   strncpy(out->subject, in_subject, HD_MAX_LOGGER_SUBJECT_SIZE - 1);
}

void hd_log_fatal(const hd_logger* in, const char* msg, ...) {
   HD_ASSERT_NOT_NULL(in);
   HD_ASSERT_NOT_NULL(msg);
   char    unwrapped_msg[HD_MAX_LOGGER_MSG_SIZE] = {'\0'};
   va_list varargs                               = NULL;

   memset(unwrapped_msg, '\0', HD_MAX_LOGGER_MSG_SIZE);
   va_start(varargs, msg);
   vsnprintf(unwrapped_msg, HD_MAX_LOGGER_MSG_SIZE, msg, varargs);
   va_end(varargs);
   log(in->subject, "FATAL", unwrapped_msg);

   exit(2);
}
void hd_log_error(const hd_logger* in, const char* msg, ...) {
   HD_ASSERT_NOT_NULL(in);
   HD_ASSERT_NOT_NULL(msg);
   char    unwrapped_msg[HD_MAX_LOGGER_MSG_SIZE] = {'\0'};
   va_list varargs                               = NULL;

   memset(unwrapped_msg, '\0', HD_MAX_LOGGER_MSG_SIZE);
   va_start(varargs, msg);
   vsnprintf(unwrapped_msg, HD_MAX_LOGGER_MSG_SIZE, msg, varargs);
   va_end(varargs);
   log(in->subject, "ERROR", unwrapped_msg);
}

void hd_log_warning(const hd_logger* in, const char* msg, ...) {
   HD_ASSERT_NOT_NULL(in);
   HD_ASSERT_NOT_NULL(msg);
   char    unwrapped_msg[HD_MAX_LOGGER_MSG_SIZE] = {'\0'};
   va_list varargs                               = NULL;

   memset(unwrapped_msg, '\0', HD_MAX_LOGGER_MSG_SIZE);
   va_start(varargs, msg);
   vsnprintf(unwrapped_msg, HD_MAX_LOGGER_MSG_SIZE, msg, varargs);
   va_end(varargs);
   log(in->subject, "WARNING", unwrapped_msg);
}

void hd_log_info(const hd_logger* in, const char* msg, ...) {
   HD_ASSERT_NOT_NULL(in);
   HD_ASSERT_NOT_NULL(msg);
   char    unwrapped_msg[HD_MAX_LOGGER_MSG_SIZE] = {'\0'};
   va_list varargs                               = NULL;

   memset(unwrapped_msg, '\0', HD_MAX_LOGGER_MSG_SIZE);
   va_start(varargs, msg);
   vsnprintf(unwrapped_msg, HD_MAX_LOGGER_MSG_SIZE, msg, varargs);
   va_end(varargs);
   log(in->subject, "INFO", unwrapped_msg);
}

void log(const char* subject, const char* lvl, const char* msg) {
   hd_time now    = {};
   int     result = hd_time_now(&now);
   HD_ASSERT_OK(result);

   printf("%04d-%02d-%02d %02d:%02d:%02d.%03d - [%15s] %7s : %s\n",
          now.year, now.month, now.day, 
          now.hours, now.minutes, now.seconds, now.milliseconds,
          subject, lvl, msg);
}