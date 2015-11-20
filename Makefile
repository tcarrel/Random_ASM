

gen: gen.cpp
	g++ -std=c++11 gen.cpp -o gen

clean:
	rm -f gen
