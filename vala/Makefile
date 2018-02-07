OBJ=hello \
	animate_actor \
	use_ui \
	use_ui_gtktemplate \
	sourceView \
	cat_patch

all: ${OBJ}

hello: hello.vala
	valac $^ -o $@

animate_actor: animate_actor.vala
	valac --pkg clutter-1.0 $^ -o $@

c_file: hello.vala
	valac hello.vala -C -H hello.h

use_ui: use_ui.vala
	valac --pkg gtk+-3.0 --pkg gmodule-2.0 $^ -o $@

resources.c:
	glib-compile-resources --generate-source --target resources.c resources.xml

use_ui_gtktemplate: use_ui_gtktemplate.vala resources.c
	valac --pkg gtk+-3.0 --pkg gmodule-2.0 --gresources "resources.xml" $^ -o $@

sourceView: sourceView.vala
	valac --pkg gtk+-3.0 --pkg gtksourceview-3.0 $^ -o $@

cat_patch: cat_patch.vala
	valac $^ -o $@

clean:
	@rm -f ${OBJ}
	@rm -f hello.c hello.h resources.c
