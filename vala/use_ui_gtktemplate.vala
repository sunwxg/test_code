using Gtk;

[GtkTemplate (ui = "/org/gnome/use_ui/sample_template.ui")]
class My.App: Gtk.Window {

	[GtkCallback]
	public void on_button1_clicked (Button source) {
		source.label = "Thank you!";
	}

	[GtkCallback]
	public void on_button2_clicked (Button source) {
		source.label = "Thanks!";
	}

}

int main (string[] args) {
	Gtk.init (ref args);

	var app = new My.App ();
	app.show_all ();

	Gtk.main ();

	return 0;
}
