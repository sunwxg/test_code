#ifndef __GIFUNC_HELLO_H__
#define __GIFUNC_HELLO_H__

#include <glib.h>

/**
 *gifunc_hello_world:
 *@greeting:
 *
 * Returns: (transfer full): a constant, free when you used it
 */
gchar *
gifunc_hello_world (gchar * greeting);

#endif // __GIFUNC_HELLO_H__
