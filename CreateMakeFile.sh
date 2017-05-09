#! /bin/sh

#Colorcodes
RED=$(tput setaf 1)
GREEN=$(tput setaf 2)
YELLOW=$(tput setaf 3)
CYAN=$(tput setaf 6)
NORMAL=$(tput sgr0)

#Checking existence of the old Makefile
if [ -f Makefile ];
then
	if [ -f Makefile_old ];
	then
		echo "${RED}Deleting Makefile_old!${NORMAL}"
		rm Makefile_old
	fi
	echo "Renamed your ${CYAN}Makefile${NORMAL} into ${CYAN}Makefile_old${NORMAL}"
	mv Makefile Makefile_old
fi

#Asking user
printf "Do you want to enter ${CYAN}\$NAME, \$CC and \$CFLAGS${NORMAL} manually?[${YELLOW}y${NORMAL}/${YELLOW}n${NORMAL}]: ${GREEN}"
read Temp
printf "${NORMAL}"
#Auto entry
if [ $Temp = "n" ]
then
	#Checking existence of the old Makefile
	if [ -f Makefile_old ];
	then
		echo "Reading from Makefile_old!"
		Nm=$(cat "Makefile_old" | grep "^NAME")
		Cc=$(cat "Makefile_old" | grep "^CC")
		Fl=$(cat "Makefile_old" | grep "^CFLAGS")
		printf "Will write this int Makefile:\n${CYAN}\t$Nm\n\t$Cc\n\t$Fl\n${NORMAL}Is it right?[${YELLOW}y${NORMAL}/${YELLOW}n${NORMAL}]: ${GREEN}"
		read Ans
		if [ $Ans = "y" ]
		then
			echo "Writing into makefile"
			printf "$Nm\n$Cc\n$Fl\n" > Makefile
		else
			echo "${RED}Not${NORMAL} writing into Makefile"
			Temp="y"
		fi
	else
		echo "${RED}No makefile found!${NORMAL}"
		Temp="y"
	fi
fi
#Manual entry
if [ $Temp = "y" ]
then
	#Reading NAME, CC, CFLAGS params for makefile
	INFO="NAME"
	printf "Enter the programm ${CYAN}$INFO${NORMAL}: ${GREEN}"
	read Temp
	printf "\t   ${NORMAL}Writing ${CYAN}$INFO = ${YELLOW}$Temp${NORMAL} to the Makefile...\n"
	echo "$INFO = $Temp" > Makefile
	INFO="CC"
	printf "Enter the programm ${CYAN}$INFO${NORMAL}: ${GREEN}"
	read Temp
	printf "\t   ${NORMAL}Writing ${CYAN}$INFO = ${YELLOW}$Temp${NORMAL} to the Makefile...\n"
	echo "$INFO = $Temp" >> Makefile
	INFO="CFLAGS"
	printf "Enter the programm ${CYAN}$INFO${NORMAL}: ${GREEN}"
	read Temp
	printf "\t   ${NORMAL}Writing ${CYAN}$INFO = ${YELLOW}$Temp${NORMAL} to the Makefile...\n"
	echo "$INFO = $Temp" >> Makefile
fi
echo "" >> Makefile

#Creating OBJECTS section
OBJ=$(ls *.c | tr '\n' ' '| sed 's/\.c/\.o/g')
Am=$(ls *.c | wc -w | bc)
printf "\t   Writing ${CYAN}OBJECTS = ${YELLOW}$OBJ${NORMAL} to the Makefile...(${YELLOW}$Am${NORMAL} in total)\n"
echo "OBJECTS = $OBJ" >> Makefile
echo "" >> Makefile

#creating ALL rule
echo "Creating ${CYAN}ALL${NORMAL} rule..."
printf "all : \$(NAME)\n\n" >> Makefile

#creating command for NAME
#echo "Creating ${CYAN}\$(NAME)${NORMAL} rule..."
printf "\$(NAME) : \$(OBJECTS)\n\t" >> Makefile

# Creating a rule for NAME
printf "Do you want to create ${YELLOW}d${CYAN}efault/${YELLOW}c${CYAN}ustom/${YELLOW}l${CYAN}ibrary${NORMAL} rule?: ${GREEN}"
read Ans
#custom rule
if [ $Ans = "c" ];
then
	echo "${NORMAL}Enter the ${CYAN}custom \$(NAME) rule${NORMAL}:${GREEN}"
	read Temp
	echo "${NORMAL}"
fi
#library rule
if [ $Ans = "l" ];
then
	printf "${NORMAL}Creating ${CYAN}library \$(NAME) rule${NORMAL}: "
	Temp="ar rc \$(NAME) \$(OBJECTS)\n\t\t\t\tranlib \$(NAME)"
	echo "${YELLOW}$Temp${NORMAL}"
	Temp="ar rc \$(NAME) \$(OBJECTS)\n\tranlib \$(NAME)"
else
#all other rules
	printf "${NORMAL}Creating ${CYAN}default \$(NAME) rule${NORMAL}: "
	Temp="\$(CC) \$(CFLAGS) \$(OBJECTS) -o \$(NAME)"
	echo "${YELLOW}$Temp${NORMAL}"
fi
printf "$Temp\n\n" >> Makefile

#adding CLEAN, FCLEAN, RE rules
echo "Creating ${CYAN}clean, fclean, re${NORMAL} rules..."
printf "clean :\n\trm -f \$(OBJECTS)\n\nfclean : clean\n\trm -f \$(NAME)\n\nre : fclean all" >> Makefile

#adding rule for every object
Fls=$(ls *.c)
printf "Creating a rule for every file..."
for word in $Fls;
do
#	echo "Creating a rule for ${YELLOW}$word${NORMAL}"
	printf "\n\n${word%.c}.o : $word\n\t\$(CC) \$(CFLAGS) -c $word" >> Makefile
done
Am=$(ls *.c | wc -w | bc)
printf "\t${YELLOW}$Am${NORMAL} in total.\n"
echo "${GREEN}Done!${NORMAL}"
