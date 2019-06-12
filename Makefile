prog: b.o a-hidden.o main.o
	$(CXX) -o $@ $^	

a-default.o: a.cpp
	$(CXX) -fPIC -std=c++11 -O2  -o $@ -c $^
a-hidden.o: a.cpp
	$(CXX) -fPIC -fvisibility=hidden -std=c++11 -O2  -o $@ -c $^
main.o: main.cpp
	$(CXX) -fPIC -std=c++11 -O2  -o $@ -c $^
b.o:	b.cpp
	$(CXX) -fPIC -std=c++11 -O2 -o $@ -c $^
	
dump: a-default.o a-hidden.o
	nm a-default.o | grep call_once
	nm a-hidden.o | grep call_once

