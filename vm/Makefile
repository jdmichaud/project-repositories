##
## Makefile for Makefile in 
## 
## Made by romain bottier
## Login   <bottie_r@epita.fr>
## 
## Started on  Wed Oct 24 16:19:46 2001 romain bottier
## Last update Fri Jan 11 13:07:27 2002 jean-daniel michaud
##
#
NAME	= kvm
srcdir	= src/
DATE	= `date '+%b%d%y%Hh%M'`
#
all	: chdir
#
chdir	:
	cd $(srcdir) && make && cd ..
	mv src/kvm ./
#
libs	:
	cd lib/my && make fclean all && make clean && cd ../..
	cd lib/data_struct && make fclean all && make clean && cd ../..
	cd lib/dlist && make fclean all && make clean && cd ../..
	cd lib/my_printf && make fclean all && make clean && cd ../..
	cd lib/my_print_error && make fclean all && make clean && cd ../..
	cd lib/xlib && make fclean all && make clean && cd ../..
#
my	:
	cd lib/my && make fclean all && make clean && cd ../..
#
printf	:
	cd lib/my_printf && make fclean all && make clean && cd ../..
#
vsprintf	:
	cd lib/my_vsprintf && make fclean all && make clean && cd ../..
#
print_error	:
	cd lib/my_print_error && make fclean all && make clean && cd ../..
#
ds	:
	cd lib/data_struct && make fclean all && make clean && cd ../..
#
dlist	:
	cd lib/dlist && make fclean all && make clean && cd ../..
#
xvm	:
	cd lib/xlib && make fclean all && make clean && cd ../..
#
clean	:
	rm -f $(NAME) && cd $(srcdir) && make clean && cd ..
#
re	: clean all
#
save	: clean
	cd .. && tar -zcvf $(SAVEDIR)$(NAME)_$(USER)_$(DATE).tgz vm/
	cd .. && chmod 600 *.tgz
