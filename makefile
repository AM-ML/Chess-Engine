all:
	clear;gcc vice.c init.c -o vice;./vice

git:
	clear;git add --all; git commit -am "Video #${a}"; git push;git log --oneline

log:
	clear;git log --oneline
