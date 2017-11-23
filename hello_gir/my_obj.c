#include <glib.h>
#include <girepository.h>
#include "hello-world.h"

int main(int argc, char* argv[])
{
	HelloWorld* hello;
	/*GOptionContext *ctx;*/
	/*GError *error = NULL;*/

	/*ctx = g_option_context_new (NULL);*/
	/*g_option_context_add_group (ctx, g_irepository_get_option_group ());*/

	/*if (!g_option_context_parse (ctx, &argc, &argv, &error)) {*/
		/*g_print ("my_obj: %s\n", error->message);*/
		/*return 1;*/
	/*}*/


	hello = hello_world_new();

	hello_world_set_greeting(hello, "hello world!");

	g_print("%s\n", hello_world_get_greeting(hello));

	return 0;
}
