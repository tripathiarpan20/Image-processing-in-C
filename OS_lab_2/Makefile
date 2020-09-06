SRCDIR := bin
INCLDIR := include
TRANSDIR := transforms
EXEDIR := exe
LIBDIR := libs


build: $(EXEDIR) $(LIBDIR)/libmatrixmath.a
	gcc -o $(EXEDIR)/main.o -I $(INCLDIR) $(SRCDIR)/run_main.c $(TRANSDIR)/*.c $(SRCDIR)/matrix_math.c $(SRCDIR)/ppm_util.c -L $(LIBDIR) -lmatrixmath

T1:
	gcc -o $(EXEDIR)/main.o -I $(INCLDIR) $(SRCDIR)/T1.c $(TRANSDIR)/*.c $(SRCDIR)/matrix_math.c $(SRCDIR)/ppm_util.c -L $(LIBDIR) -lmatrixmath


T2:
	gcc -o $(EXEDIR)/main.o -I $(INCLDIR) $(SRCDIR)/T2.c $(TRANSDIR)/*.c $(SRCDIR)/matrix_math.c $(SRCDIR)/ppm_util.c -L $(LIBDIR) -lmatrixmath

$(LIBDIR)/libmatrixmath.a:
	


#used to prepare the txt file, that acts as input to our executable
#if 'prepare' is used before 'run', inp.txt has 4 lines, but the main.o
#only reads two lines from the 'prepare', hence, both 'prepare' and 'run'
#have proper functionality
run: build 
	@echo "input.ppm" >> inp.txt
	@echo "output.ppm" >> inp.txt
	../$(EXEDIR)/main.o << inp.txt
	rm inp.txt

prepare: build
	@read inp_file
	@read out_file
	@echo $$inp_file >> inp.txt
	@echo $$out_file >> inp.txt  
#https://stackoverflow.com/questions/3743793/makefile-why-is-the-read-command-not-reading-the-user-input


test%: test%.ppm test%_.ppm
	@echo $@.ppm > inp.txt
	@echo $@_.ppm >> inp.txt
	../$(EXEDIR)/main.o << inp.txt

clean:
	rm inp.txt
	rm $(EXEDIR)/*
	rm $(EXEDIR)
	rm $(LIBDIR)/*
	rm $(LIBDIR)

$(EXEDIR):
	mkdir -p $(EXEDIR)
$(LIBDIR):
	mkdir -p $(LIBDIR)

#TODO: liba and libso, such that libmatrixmath.a (OR) libmatrixmath.so is created in $(LIBDIR) folder
#optimizing the compilation process using $ ? automatic variable
#create test1.ppm, test2.ppm and test3.ppm in the 'inputs' folder
#debugging, obviously
