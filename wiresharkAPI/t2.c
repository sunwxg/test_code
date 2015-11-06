#include <wireshark/epan/epan.h>
#include <wireshark/epan/packet.h>
#include <wireshark/epan/frame_data.h>

int main(int argc, char* argv[])
{
	/*subscribe_create(subscribe_filename);*/

	epan_init(register_all_protocols, register_all_protocol_handoffs, NULL, NULL);

	apply_preferences();

	init_dissection();

	/*override_create(ring_buffer, non_block);*/

	union wtap_pseudo_header wtap_pseudohdr = {
		.eth = { .fcs_len = 0  }
	};
	struct wtap_pkthdr wtap_phdr = {
		.presence_flags = WTAP_HAS_TS | WTAP_HAS_CAP_LEN,
		.ts = {
			.secs = header->sec,
			.nsecs = header->usec * 1000,
		},
		.caplen = header->caplen,
		.len = header->len,
		.pkt_encap = WTAP_ENCAP_ETHERNET,
	};

	frame_data fd;
	frame_data_init(&fd, 0, &wtap_phdr, 0, 0);

	epan_dissect_t edt;
	epan_dissect_init(&edt, TRUE, TRUE);

	epan_dissect_run(&edt, &wtap_pseudohdr,
			(guint8 *) header + sizeof(*header), &fd, NULL);

	epan_dissect_cleanup(&edt);

	frame_data_cleanup(&fd);

	/*override_destroy();*/

	cleanup_dissection();
	epan_cleanup();

	subscribe_destroy();
}
