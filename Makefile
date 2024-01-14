all:
	g++ src/main.cpp -I include -o DDPN

run: all
	./DDPN.exe