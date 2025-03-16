/*
   logger.h -- Hyperdrive's logging system.

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
#ifndef HD_LOGGER_H
#define HD_LOGGER_H

#define HD_MAX_LOGGER_SUBJECT_SIZE 32
#define HD_MAX_LOGGER_MSG_SIZE 256

/**
 * @brief hd_logger represents Hyperdrive logging mechanism.
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
typedef struct hd_logger_s {
      char subject[HD_MAX_LOGGER_SUBJECT_SIZE];
} hd_logger;

/**
 * @brief Initialize a given hd_logger instance with the given subject.
 *
 * Initialize the internals of the given hd_logger instance with the given
 * subject. If the subject's length is greater than HD_MAX_LOGGER_SUBJECT_SIZE,
 * then it will be truncated to HD_MAX_LOGGER_SUBJECT_SIZE-1.
 *
 * This function doesn't return any status code. If an error occurs, we assume
 * that a logger system isn't critical enough to send an error code to the caller.
 *
 * All log messages will be made on stdout.
 *
 * @param out the hd_logger instance to update. MUST BE not null.
 * @param in_subject the log subject to attach to the hd_logger instance.
 */
void hd_logger_init(hd_logger* out, const char* in_subject);

/**
 * @brief Log the given message with a FATAL level. Exit the software with code 2.
 *
 * Log the given message for the subject in the given hd_logger instance with a
 * FATAL level (see the documentation of hd_logger for log format detail).
 *
 * IMPORTANT : due to the fact that a Fatal error is un-recoverable in theory, calling
 * this log message will result in a call to exit (with code 2). Make sure to use this
 * only when really needed.
 *
 * @param in the hd_logger instance use to log the message
 * @param msg the message to log (supports printf format)
 * @param ... varargs for message's parameters.
 */
void hd_log_fatal(const hd_logger* in, const char* msg, ...);

/**
 * @brief Log the given message with an ERROR level.
 *
 * Log the given messag for the subject in the given hd_logger instance with an
 * ERROR level (see the documentation of hd_logger for log format detail).
 *
 * @param in the hd_logger instance use to log the message
 * @param msg the message to log (supports printf format)
 * @param ... varargs for message's parameters.
 */
void hd_log_error(const hd_logger* in, const char* msg, ...);

/**
 * @brief Log the given message with a WARNING level.
 *
 * Log the given messag for the subject in the given hd_logger instance with a
 * WARNING level (see the documentation of hd_logger for log format detail).
 *
 * @param in the hd_logger instance use to log the message
 * @param msg the message to log (supports printf format)
 * @param ... varargs for message's parameters.
 */
void hd_log_warning(const hd_logger* in, const char* msg, ...);

/**
 * @brief Log the given message with an INFO level.
 *
 * Log the given messag for the subject in the given hd_logger instance with an
 * INFO level (see the documentation of hd_logger for log format detail).
 *
 * @param in the hd_logger instance use to log the message
 * @param msg the message to log (supports printf format)
 * @param ... varargs for message's parameters.
 */
void hd_log_info(const hd_logger* in, const char* msg, ...);

#endif // HD_LOGGER_H