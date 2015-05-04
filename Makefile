compiler=g++
outputfile=const_string_test
includes=-I.
libs=/usr/local/Cellar/boost/1.57.0/lib/libboost_unit_test_framework.a
testfiles=const_string_test.cpp
dependencies=const_string.cpp

default: test

test: $(testfiles) $(dependencies)
	$(compiler) -Wl,$(libs) -o $(outputfile) $(includes) $(testfiles)

clean:
	rm -fv $(outputfile)
