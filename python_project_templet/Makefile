test:
	py.test

vtest:
	py.test -v

ptest:
	py.test -s

script:
	@python py_hello

install:
	@python setup.py install --record 1.log

uninstall:
	@cat 1.log |xargs -I {} rm -r {}
	@rm 1.log

.PHONY: test vtest ptest install uninstall
