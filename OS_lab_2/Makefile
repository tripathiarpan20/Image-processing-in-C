SRCDIR := bins
INCLDIR := include
TRANSDIR := transforms
EXEDIR := exe
LIBDIR := libs


build: $(EXEDIR) $(LIBDIR)/libmatrixmath.a
	gcc -o $(EXEDIR)/main -I $(INCLDIR) $(SRCDIR)/ppm_util.c $(TRANSDIR)/*.c $(SRCDIR)/run_main.c $(SRCDIR)/matrixmath.c

T1.o: $(EXEDIR) $(LIBDIR)/libmatrixmath.a
	gcc -o $(EXEDIR)/T1 -I $(INCLDIR) $(SRCDIR)/ppm_util.c $(TRANSDIR)/*.c $(SRCDIR)/T1.c $(SRCDIR)/matrixmath.c 


T2.o: $(EXEDIR) $(LIBDIR)/libmatrixmath.a
	gcc -o $(EXEDIR)/T2 -I $(INCLDIR) $(SRCDIR)/ppm_util.c $(TRANSDIR)/*.c $(SRCDIR)/T2.c $(SRCDIR)/matrixmath.c

T1: T1.o
	@echo "input" >> inp.txt
	@echo "output" >> inp.txt
	@cat inp.txt
	$(EXEDIR)/T1
	@rm inp.txt

T2: T2.o
	@echo "input" >> inp.txt
	@echo "output" >> inp.txt
	@cat inp.txt
	$(EXEDIR)/T2
	@rm inp.txt

$(LIBDIR)/libmatrixmath.a:
#$(LIBDIR)/libmatrixmath.o
#gcc -o 


#used to prepare the txt file, that acts as input to our executable
#if 'prepare' is used before 'run', inp.txt has 4 lines, but the main.o
#only reads two lines from the 'prepare', hence, both 'prepare' and 'run'
#have proper functionality
run: build
	@echo "input" >> inp.txt
	@echo "output" >> inp.txt
	@cat inp.txt
	$(EXEDIR)/main
	@rm inp.txt 

prepare: build
	@chmod +x build.sh
	./build.sh
	@cat inp.txt
#https://stackoverflow.com/questions/3743793/makefile-why-is-the-read-command-not-reading-the-user-input


test%: build
	@echo $@ > inp.txt
	@echo $@_ >> inp.txt
	$(EXEDIR)/main 

clean:
	rm $(EXEDIR)/*
	rmdir $(EXEDIR)
	rm $(LIBDIR)/*
	rmdir $(LIBDIR)
	rm inp.txt
	

$(EXEDIR):
	mkdir -p $(EXEDIR)
$(LIBDIR):
	mkdir -p $(LIBDIR)

#TODO: liba and libso, such that libmatrixmath.a (OR) libmatrixmath.so is created in $(LIBDIR) folder
#optimizing the compilation process using $ ? automatic variable
#create test1.ppm, test2.ppm and test3.ppm in the 'inputs' folder
#debugging, obviously
