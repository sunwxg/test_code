#ifndef __HELLO_WORLD_H__
#define __HELLO_WORLD_H__

#include <glib.h>
#include <glib-object.h>

#define HELLO_WORLD_TYPE (hello_world_get_type())
#define HELLO_WORLD(o)			\
    (G_TYPE_CHECK_INSTANCE_CAST ((o), HELLO_WORLD_TYPE, HelloWorld))
#define HELLO_WORLD_CLASS(c)		\
    (G_TYPE_CHECK_CLASS_CAST ((c), HELLO_WORLD_TYPE, HelloWorldClass))
#define HELLO_IS_WORLD(o)		\
    (G_TYPE_CHECK_INSTANCE_TYPE ((o), HELLO_WORLD_TYPE))
#define HELLO_IS_WORLD_CLASS(c)		\
    (G_TYPE_CHECK_CLASS_TYPE ((c),  HELLO_WORLD_TYPE))
#define HELLO_WORLD_GET_CLASS(o)	\
    (G_TYPE_INSTANCE_GET_CLASS ((o), HELLO_WORLD_TYPE, HelloWorldClass))

typedef struct _HelloWorld HelloWorld;
typedef struct _HelloWorldPrivate HelloWorldPrivate;
typedef struct _HelloWorldClass HelloWorldClass;

struct _HelloWorld {
	GObject parent;
};

struct _HelloWorldClass {
	GObjectClass parent;
};

GType hello_world_get_type() G_GNUC_CONST;

HelloWorld* hello_world_new();

void hello_world_set_greeting(HelloWorld* this, gchar* greeting);
gchar* hello_world_get_greeting(HelloWorld* this);

#endif // __HELLO_WORLD_H__
