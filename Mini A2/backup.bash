#!/bin/bash

# Xibei Jia
# ECE Department
# xibei.jia@mail.mcgill.ca

# Check two input statements
if [[ $# != 2 ]]
then
	echo "Error: Expected two input parameters."
	echo "Usage: $0 <backupdirectory> <fileordirtobackup>"
	exit 1
fi

# Check the directory to store the tar file exists or not
if [[ ! -d $1 ]]
then
	echo "Error: The directory $1 to store the tar file does not exist."
	exit 2
fi

# Check the file or directory to back up exits or not
if [[ ! -d $2 ]] && [[ ! -f $2 ]]
then    
        echo "Error: The backup file or directory $2 does not exist."
	exit 2
fi


if [[ $1 -ef $2 ]]
then
	echo "Both arguments are the same directory."
	exit 2
fi

filename=$(basename $2)
backupdate=$(date +%Y%m%d)

backuptarfile=$filename.$backupdate.tar

if [[ -f "$1"/"$backuptarfile" ]]
then
	echo "Backup file '$backuptarfile' already exists. Overwrite? (y/n)"
	read input
	if [[ $input = "y" ]]
	then
	       tar -cvf $1/$backuptarfile $2
	       exit 0
	fi
	if [[ $input = "n" ]]
	then
		echo "Backup file not overwriting"
		exit 3
	fi
fi

tar -cvf $1/$backuptarfile $2
exit 0

