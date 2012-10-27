#ifndef __UTILS_H__
#define __UTILS_H__

void error_abort(const char *format, ...);
void open_log_wnd(); 
void close_log_wnd(bool wait_for_user = false);
void log_printf(const char *format, ...);

#endif