SUBDIRS = src man
MAINTAINERCLEANFILES = aclocal.m4 config.h.in configure Makefile.in stamp-h.in
ACLOCAL_AMFLAGS = -I .
EXTRA_DIST = BUGS CONTRIB FAQ LICENSE.txt xft.m4 examples/statustext.sh examples/statustext-gavin.sh examples/statustext-deleuze.sh examples/themes/flat-grey-theme.conf examples/themes/accent-theme.conf examples/themes/flat-cyan-theme.conf examples/themes/gold-theme.conf examples/themes/laotse-theme.conf examples/themes/lunatic-theme.conf examples/themes/peacock-theme.conf examples/session-managers/kdm-entry ncwm.spec.in ncwm.spec
CLEANFILES = ncwm.spec

# Yes, we could create ncwm.spec from configure.in, but
# - Makefile.am content is easier to maintain
# - ncwm.spec is rebuilt faster from ncwm.spec.in if generated in
#   Makefile.am

ncwm.spec: $(srcdir)/ncwm.spec.in Makefile
	sed \
		-e 's,[@]RPM_NAME[@],$(PACKAGE),g' \
		-e "s,[@]RPM_VERSION[@],$$(echo '$(VERSION)' | sed -e 's/-/./g'),g" \
		-e 's,[@]TAR_NAME[@],$(PACKAGE),g' \
		-e 's,[@]TAR_VERSION[@],$(VERSION),g' \
		< $(srcdir)/ncwm.spec.in > ncwm.spec

