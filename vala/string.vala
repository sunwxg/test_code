public static int main (string[] args) {

	var line = string.nfill(10, 'x');
	stdout.printf ("%s\n", line);
	stdout.printf ("string length=%d\n", line.length);
	return 0;
}
