archive:
	git archive HEAD --prefix=DSDemo-0.2/ -o DSDemo-0.2.tar.gz
clean:
	rm -rf *.~bpr *.obj *.cbproj.local *.exe *.map *.res *.tds *.~bpr *Debug* *.obj *Debug_Build* `find . -name "*__history*"`
