install:
	@python setup.py install --record 1.log

uninstall:
	@cat 1.log |xargs -I {} rm -r {}
	@rm 1.log
