# LuNA

## Description

The lo3 project is dedicated to the LuNA language compiler and run-time system with the goal of removing everything that can be computed statically from a dynamic context.

## Installation

### Windows

A possible workaround for Windows 10 is to install WSL (Windows Subsystem for Linux).

### Ubuntu

1. Clone this repository.

2. You will need following dependencies to build luna (it is recommended to run `sudo apt-get update` before installation):
   1. g++ (`sudo apt-get install g++`)
   2. mpicxx and openmpi (`sudo apt-get install openmpi-bin openmpi-common libopenmpi-dev libopenmpi2`)
   3. pythond2.7 (`sudo apt install python2.7 python-pip`)
   4. bison (`sudo apt-get install bison`)
   5. flex (`sudo apt-get install flex`)

3. Run `make` from project directory to compile luna and parser.

4. Set `LUNA_HOME` to project path (to `lo3`) and add `$LUNA_HOME/bin` to `PATH` environment variable.

5. Run HelloWorld (from project directory): `luna examples/tests_luna/basic1/test.fa`

#### Make options

1. `make test` run all tests
2. `make fftest` run tests until the first failed
3. `make clean` - cleanup build files (carefully, it will also remove bins)

## Documentation

[LuNA language.](https://gitlab.ssd.sscc.ru/luna/luna5/wikis/luna_lang_v01)

[luna_trace debug utility.](./LUNA_TRACE.md)
