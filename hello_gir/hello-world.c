#include "hello-world.h"

G_DEFINE_TYPE(HelloWorld, hello_world, G_TYPE_OBJECT);

#define HELLO_WORLD_GET_PRIVATE(object) \
	(G_TYPE_INSTANCE_GET_PRIVATE((object), HELLO_WORLD_TYPE, HelloWorldPrivate))

struct _HelloWorldPrivate {
	gchar* greeting;
};

static void
hello_world_init(HelloWorld* this)
{
	HelloWorldPrivate* priv = HELLO_WORLD_GET_PRIVATE(this);

	priv->greeting = NULL;
}

static void
hello_world_finalize(GObject* this)
{
	/*HelloWorldPrivate* priv = HELLO_WORLD_GET_PRIVATE(this);*/

	/*g_free(priv->greeting);*/
	/*G_OBJECT_CLASS(hello_world_parent_class)->finalize(this);*/
}

static void
hello_world_class_init(HelloWorldClass* class)
{
	GObjectClass* object_class = G_OBJECT_CLASS(class);

	object_class->finalize = hello_world_finalize;

	g_type_class_add_private(class, sizeof(HelloWorldPrivate));
}

HelloWorld*
hello_world_new()
{
	HelloWorld* hello;

	hello = g_object_new(HELLO_WORLD_TYPE, NULL);

	return hello;
}

void hello_world_set_greeting(HelloWorld* this, gchar* greeting)
{
	HelloWorldPrivate* priv = HELLO_WORLD_GET_PRIVATE(this);

	priv->greeting = g_strdup_printf("%s", greeting);
}

gchar* hello_world_get_greeting(HelloWorld* this)
{
	HelloWorldPrivate* priv = HELLO_WORLD_GET_PRIVATE(this);

	return priv->greeting;
}
