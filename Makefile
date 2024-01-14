all:
	g++ src/main.cpp -I include -o DDPN

runwin: all
	./DDPN.exe

runlinux: all
	./DDPN