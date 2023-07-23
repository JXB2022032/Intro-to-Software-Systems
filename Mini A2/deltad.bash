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

# Check if the first input is a directory
if [[ ! -d $1 ]]
then
        echo "Error: Input parameter #1 $1 is not a directory."
	echo "Usage: $0 <backupdirectory> <fileordirtobackup>"
        exit 2
fi

# Check if the second input is a directory
if [[ ! -d $2 ]]
then
        echo "Error: Input parameter #2 $2 is not a directory."
	echo "Usage: $0 <backupdirectory> <fileordirtobackup>"
        exit 2
fi

# Check the two input directories are the same or not
if [[ $1 -ef $2 ]]
then
        echo "Error: Input parameters #1 $1 and #2 $2 are same directories."
	echo "Usage: $0 <backupdirectory> <fileordirtobackup>"
        exit 2
fi

# Check if there are files existing in 1st directory but not exist 2nd directory
flag=0
for i in $(ls $1)
do
	if [[ ! -f "$2"/"$i" ]]
	then
		flag=3
		echo "$2/$i is missing"
	fi
	# Now check if the existing file in both directories are differ in content
	if [[ -f "$2"/"$i" ]]
	then
		Differ=$(diff $1/$i $2/$i)
		if [[ $Differ = "" ]]
		then
			flag=0
		fi
		if [[ $Differ != "" ]]
        then
			flag=3
                  	echo "$1/$i differs"
        fi
	fi
done

# Check if there are files existing in 2nd directory but not exist 1st directory
for j in $(ls $2)
do
	if [[ ! -f "$1"/"$j" ]]
	then
		flag=3
		echo "$1/$j is missing"
	fi
done

if [[ $flag -eq 3 ]]
then
	exit 3
fi
# exit with code 0
exit 0


