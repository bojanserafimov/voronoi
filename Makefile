NAME = voronoi
PREFIX = inst
include common.mk

LDFLAGS += $(shell pkg-config --cflags --libs gtk+-3.0)
CFLAGS += 
DEPENDENCIES +=

clean::
	@make -C tests clean

test: all
	@make -C tests
	@inst/test
