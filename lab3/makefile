
all: clean draw

clean:
	rm -rf *.dat
	rm -rf *.jpeg
	rm -rf __pycache__

run:
	ls *.py|xargs -n 1 -P 3 python3

draw: run
	gnuplot gnuskrypt.sh

init:
	pip3 install -r requirements.txt
