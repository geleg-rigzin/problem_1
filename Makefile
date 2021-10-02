.PHONY: all test plot
	
all: report

clean:
	rm -rf gen cntrl tim sspp *.bin *.png
gen: gen.cpp
	g++ -o gen gen.cpp
cntrl: cntrl.cpp
	g++ -o cntrl cntrl.cpp
tim: tim.cpp
	g++ -o tim tim.cpp
sspp: sspp.cpp
	g++ -o sspp sspp.cpp
test: gen cntrl
	g++ sspp.cpp -o sspp -Wall -Werror -pthread -O0 -fsanitize=address
	./test.sh sspp

report: gen cntrl tim sspp
	./sc.sh
