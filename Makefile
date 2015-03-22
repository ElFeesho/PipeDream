all:
	cd client; make
	cd server; make
	cd game; make

clean:
	cd client; make clean
	cd server; make clean
	cd game; make clean
