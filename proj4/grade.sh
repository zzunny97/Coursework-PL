#/bin/bash

[ $# -eq 0 ] && { 
	com=`history | tail -n 1 | awk '{print $4}'`
	echo "Usage: $com MAXPOINTS";
	exit 1;
}

./clear.sh

maxpoint=$1
list=(`ls -l *.c | awk '{print $9}' | sort`)


for i in ${list[@]}
do
	curpoint=$1
	id=`echo $i | cut -d '.' -f1`
	comments=`grep -rn "//" $i | wc -l`
	if [ ${comments} -lt 3 ]; then
		((curpoint="${curpoint}"-5))
	fi
	gcc -o $id.out $i 
	./$id.out > $id".output"

	diff -bwi $id".output" output.txt > $id".diff"
	
	diffcnt=`grep -rn '>' $id."diff" | wc -l`
	diffcnt2=`grep -rn '<' $id."diff" | wc -l`
	((diffcnt_total="${diffcnt}"+$diffcnt2))
	((curpoint="${curpoint}"-$diffcnt_total))
	if [ ${curpoint} -lt 0 ]; then
		((curpoint=0))
	fi
	if [ ${diffcnt} -eq 0 ]; then
		echo $i has correct output
		echo $i has $comments lines with comments
		echo $i has earned a score of $curpoint / $maxpoint
	else
		echo $i has incorrect output "("$diffcnt_total lines do not match")"
		echo $i has $comments lines with comments
		echo $i ahs earned a score of $curpoint / $maxpoint

	fi
done

./clear.sh
