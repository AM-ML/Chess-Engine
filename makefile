all:
	clear;gcc vice.c -o vice;./vice

git:
	clear;git add --all; git commit -am "${a}"; git push;git log
