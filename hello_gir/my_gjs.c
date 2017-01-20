#include <glib.h>
#include <girepository.h>
#include <gjs/gjs.h>

int main (int argc, char *argv[])
{
    GjsContext *gjs;
    int status = 0;
    GError *error = NULL;

    gjs = gjs_context_new();
    if (!gjs_context_eval_file(gjs, "hello.js", &status, &error)) {
        g_print("hello: couldn't evaluate JavaScript: %s\n",
                 error->message);
        g_clear_error(&error);
    }
    g_object_unref(gjs);

    return status;
}
