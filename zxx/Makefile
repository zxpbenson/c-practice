all: 8.3.1 8.7.2

clean:
	rm -f 8.3.1 \
	rm -f 8.7.2

8.3.1: 8.3.1.c
	gcc $< -o $@

8.7.2: 8.7.2.c
	gcc $< -o $@

.DEFAULT: all
