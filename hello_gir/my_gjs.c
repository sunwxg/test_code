#include <glib.h>
#include <girepository.h>
#include <gjs/gjs.h>

int main (int argc, char *argv[])
{
    int status = 0;
    /*GError *error = NULL;*/

    /*GjsContext *gjs;*/

    /*gjs = gjs_context_new();*/
    /*if (!gjs_context_eval_file(gjs, "hello.js", &status, &error)) {*/
        /*g_print("hello: couldn't evaluate JavaScript: %s\n",*/
                 /*error->message);*/
        /*g_clear_error(&error);*/
    /*}*/
    /*g_object_unref(gjs);*/

    char **search_path;

    search_path = g_malloc0 (2 * sizeof (char *));
    search_path[0] = g_strdup ("resource:///org/gnome/shell");

    GjsContext *js_context;
    js_context = g_object_new (GJS_TYPE_CONTEXT,
            "search-path", search_path,
            NULL);

    g_strfreev (search_path);

    char *script;
    gsize script_len;
    GError **error = NULL;

    if (!g_file_get_contents("hello.js", &script, &script_len, error))
        return FALSE;

    if (!gjs_context_eval (js_context, script, -1, "<main>", &status, NULL))
        g_message ("Retrieving list of available modes failed.");

    return status;
}
