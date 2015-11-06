#include <epan/epan.h>

int main(int argc, char* argv) {

	epan_init(register_all_protocols, register_all_protocol_handoffs, NULL, NULL);
	register_all_tap_listeners();

	proto_registrar_dump_fields();

	prefs_p = read_prefs(&gpf_open_errno, &gpf_read_errno, &gpf_path,
			&pf_open_errno, &pf_read_errno, &pf_path);

	cf_name = g_strdup(optarg);

	if (cf_name) {

		if (cf_open(&cfile, cf_name, in_file_type, FALSE, &err) != CF_OK) {
			epan_cleanup();
			return 2;
		}

			/*err = load_cap_file(&cfile, global_capture_opts.save_file, out_file_type, out_file_name_res,*/
					/*global_capture_opts.autostop_packets,*/
					/*global_capture_opts.autostop_filesize);*/
		err = load_cap_file(&cfile, output_file_name, out_file_type, out_file_name_res, 0, 0);

		if (err != 0) {
			/* We still dump out the results of taps, etc., as we might have
			   read some packets; however, we exit with an error status. */
			exit_status = 2;
		}
	}

	g_free(cf_name);

	draw_tap_listeners(TRUE);
	funnel_dump_all_text_windows();
	epan_free(cfile.epan);
	epan_cleanup();

	output_fields_free(output_fields);
	output_fields = NULL;

	return exit_status;
}

static int
load_cap_file(capture_file *cf, char *save_file, int out_file_type,
    gboolean out_file_name_res, int max_packet_count, gint64 max_byte_count)
{
	cf->frames = new_frame_data_sequence();
	edt = epan_dissect_new(cf->epan, create_proto_tree, FALSE);

	while (wtap_read(cf->wth, &err, &err_info, &data_offset)) {
		if (process_packet_first_pass(cf, edt, data_offset, wtap_phdr(cf->wth),
					wtap_buf_ptr(cf->wth))) {
			if ( (--max_packet_count == 0) || (max_byte_count != 0 && data_offset >= max_byte_count)) {
				err = 0; /* This is not an error */
				break;
			}
		}
	}

	if (edt) {
		epan_dissect_free(edt);
		edt = NULL;
	}

	wtap_sequential_close(cf->wth);
}

static gboolean
process_packet(capture_file *cf, epan_dissect_t *edt, gint64 offset, struct wtap_pkthdr *whdr,
               const guchar *pd, guint tap_flags)
{

}
