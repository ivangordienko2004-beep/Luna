#
# LuNA Makefile
# =============
#
# Main targets:
# ------------
#	build (default) - build rts and parser
#	clean - clean generated files
#
#
# Recognized environment variables:
# --------------------------------
# 	CXX - C++ compiler to use
# 	CXX_FLAGS - compile keys (appended by system keys, see below)
# 	CXX_WARN - warning options (appended to CXX_FLAGS)
# 	LDFLAGS - link flags
# 	MPICXX - MPI compiler to use
#	PYTHON - Python interpreter

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
mkfile_dir := $(dir $(mkfile_path))

CXX_WARN ?= \
	-Wall -Werror -Wpedantic -Wno-vla -Wno-sign-compare \
	-Wno-unused-but-set-variable -Wno-unused-variable \
	-Wno-unused-function
PYTHON ?= python3
MPICXX ?= mpicxx
MPICH_CXX?=${CXX}
CXX_FLAGS += \
	-I ${mkfile_dir}/include \
	-std=c++11 -fPIC \
	-O3 ${CXX_WARN}
CXX_FLAGS_DBG += \
	-I ${mkfile_dir}/include \
	-std=c++11 -fPIC \
	-O3 -g -DADD_DEBUG_INFO
LDFLAGS_COMMON += -ldl -g
LDFLAGS_RTS := -L ${mkfile_dir}/lib -lrts
LDFLAGS_RTS_DBG := -L ${mkfile_dir}/lib -lrts_dbg -g
LUNA_HOME ?= ${mkfile_dir}

PYTHON ?= python3

LD_LIBRARY_PATH ?= ${mkfile_dir}/lib
export LD_LIBRARY_PATH


.PHONY: default
default: build_all

test: build_all
	LUNA_HOME=${LUNA_HOME} ${PYTHON} scripts/run_tests.py tests

fftest: build_all
	LUNA_HOME=${LUNA_HOME} ${PYTHON} scripts/run_tests.py --first-fail tests

test04:
	LUNA_HOME=${LUNA_HOME} ${PYTHON} scripts/run_tests.py --first-fail tests/04_programs

.PHONY: build_all
build_all: bin/rts bin/rts.dbg bin/parser bin/luna

# --------------------
# LuNA Run-time System
# --------------------

.PHONY: lib/librts.so
lib/librts.so: build/Makefile_lib
	make lib
	make -f build/Makefile_lib

.PHONY: lib/librts_dbg.so
lib/librts_dbg.so: build/Makefile_lib.dbg
	make lib
	make -f build/Makefile_lib.dbg

.PHONY: bin/rts
bin/rts: build/Makefile_main lib/librts.so
	make bin
	make -f build/Makefile_main

.PHONY: bin/rts.dbg
bin/rts.dbg: build/Makefile_main.dbg lib/librts_dbg.so
	make bin
	make -f build/Makefile_main.dbg

.PHONY: build/Makefile_main
.DELETE_ON_ERROR:
build/Makefile_main: scripts/mkgen
	make build
	echo "src/rts/main.cpp" | ${PYTHON} scripts/mkgen \
		--out=bin/rts --src-stdin --compiler=${MPICXX} \
		--compile-flags="${CXX_FLAGS}" \
		--link-flags="${LDFLAGS_COMMON} ${LDFLAGS_RTS}" \
		--obj=build > build/Makefile_main

.PHONY: build/Makefile_main.dbg
.DELETE_ON_ERROR:
build/Makefile_main.dbg: scripts/mkgen
	make build/dbg
	echo "src/rts/main.cpp" | ${PYTHON} scripts/mkgen \
		--out=bin/rts.dbg --src-stdin --compiler=${MPICXX} \
		--compile-flags="${CXX_FLAGS_DBG}" \
		--link-flags="${LDFLAGS_COMMON} ${LDFLAGS_RTS_DBG}" \
		--obj=build/dbg > build/Makefile_main.dbg

.PHONY: build/Makefile_lib
.DELETE_ON_ERROR:
build/Makefile_lib: scripts/mkgen
	make build
	find src/rts/*.cpp | ${PYTHON} scripts/mkgen \
		--out=lib/librts.so --src-stdin --compiler=${MPICXX} \
		--compile-flags="${CXX_FLAGS}" \
		--link-flags="${LDFLAGS_COMMON} -shared -fPIC" \
		--obj=build > build/Makefile_lib

.PHONY: build/Makefile_lib.dbg
.DELETE_ON_ERROR:
build/Makefile_lib.dbg: scripts/mkgen
	make build/dbg
	find src/rts/*.cpp | ${PYTHON} scripts/mkgen \
		--out=lib/librts_dbg.so --src-stdin --compiler=${MPICXX} \
		--compile-flags="${CXX_FLAGS_DBG}" \
		--link-flags="${LDFLAGS_COMMON} -shared -fPIC" \
		--obj=build/dbg > build/Makefile_lib.dbg


# -----------
# LuNA Parser
# -----------

bin/parser: src/parser/parser.cpp build/grammar.tab.cpp build/lex.yy.cpp
	make bin
	${CXX} ${CXX_FLAGS} src/parser/parser.cpp build/grammar.tab.cpp \
		build/lex.yy.cpp -o bin/parser

build/grammar.tab.hpp build/grammar.tab.cpp: src/parser/grammar.ypp
	make build
	cd build ; bison -d ../src/parser/grammar.ypp

build/lex.yy.cpp: src/parser/lexics.l build/grammar.tab.hpp
	make build
	flex -o build/lex.yy.cpp src/parser/lexics.l


# -----------------
# Symlinks and dirs
# -----------------

bin/luna: ${mkfile_dir}/scripts/luna
	make bin
	ln -s ${mkfile_dir}/scripts/luna bin/luna

bin/pp: ${mkfile_dir}/scripts/pp
	make bin
	ln -s ${mkfile_dir}/scripts/pp.py bin/pp

bin:
	mkdir bin

build/dbg:
	mkdir build/dbg

build:
	mkdir build

lib:
	mkdir lib

.PHONY: clean
clean:
	rm -rf bin build lib
	rm -rf `find . | grep -e "\.luna$$"`
