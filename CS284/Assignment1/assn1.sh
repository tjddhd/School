#!/bin/sh
	echo WELCOME
	echo ________________________
	echo select a menu option
	echo 1 - ancestry tree
	echo 2 - who is online
	echo 3 - what process any user is running
	echo 4 - quit
	
	while read variablename
	do
		
		case $variablename in
			1)
				echo
				echo THE ANCESTRY TREE OF THE CURRENT PROCESS IS..

				ps -ef| while read currentProcessID
				do
					echo $currentProcessID | cut -f2 -d' ' >>processlisting
				done
				ps -ef| while read currentProcessID
				do
					echo $currentProcessID | cut -f3 -d' ' >>parentlisting
				done
				
				ps | while read currentProcessID
				do
					echo $currentProcessID | cut -f1 -d' '>>quicklist
				done
				
				
				rm processlisting quicklist parentlisting
				;;
			2)	who | cut -f1 -d' '
				;;
			3)	who | while read onlineuser
				do
					echo $onlineuser | cut -f1 -d' '>>userlist
				done
				index=0
				echo Please pick a user process you would like to see
				while read onlineuser
				do
					echo $index')'$onlineuser
					index=$(expr $index + 1)
				done < userlist
				read desireduser
				rm userlist
				;;
			*)	echo Thanks for using the program
				exit
				;;
		esac
		
		echo select a menu option
		echo 1 - ancestry tree
		echo 2 - who is online
		echo 3 - what process any user is running
		echo 4 - quit
		
	done
    
