SRCDIR := bin
INCLDIR := include
TRANSDIR := transforms
EXEDIR := exe


build:
	gcc -o $(EXEDIR)/main.o -I $(INCLDIR) $(SRCDIR)/run_main.c $(TRANSDIR)/*.c $(SRCDIR)/matrix_math.c $(SRCDIR)/ppm_util.c 



run: build
	@echo "input.ppm" >> inp.txt
	@echo "output.ppm" >> inp.txt
	./main.o << inp.txt
	rm inp.txt

prepare: build
	@read inp_file
	@read out_file
	@echo $$inp_file >> inp.txt
	@echo $$out_file >> inp.txt  
	
