#include "gifunc-hello.h"

gchar *
gifunc_hello_world (gchar * greeting)
{
	return g_strdup_printf("Hello World from function: %s", greeting);
}
