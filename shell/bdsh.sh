#!/bin/sh

exit_usage ()
{
    echo "Syntax error : bad usage"
    exit
}

if [ $# = 0 ]
then
    exit_usage
fi

filename="sh.db"
k=0
i=1
stopf=0
stopk=0
if [ -f $filename ]
then
    cr=0
else
    cr=1
fi

while [ $i -le $# ]
do
    if eval [ \$$i = "-k" ]
    then
	k=1
	stopk=$((stopk+1))
    elif eval [ \$$i = "-f" ]
    then
	i=$((i+1))
	eval filename=\"\$$i\"
	stopf=$((stopf+1))
    elif eval [ \$$i = "-c" ]
    then
	i=$((i+1))
	eval filename=\"\$$i\"
	cr=1
	stopf=$((stopf+1))
    else
	break
    fi
    i=$((i+1))
done

if [ $stopf -gt 1 ] || [ $stopk -gt 1 ]
then
    exit_usage
fi

if [ -f $filename ]
then
    if [ $cr = 1 ]
    then
	exit
    fi
else
    if [ $cr = 1 ]
    then
    else
	echo "No base found : $filename"
	exit
    fi
fi

if [ $i -gt $# ]
then
    exit_usage
fi

put=0
del=0
select=0
flush=0
if eval [ \$$i = "put" ]
then
    put=1
    i=$((i+1))
    eval key=\"\$$i\"
    i=$((i+1))
    eval val=\"\$$i\"
elif eval [ \$$i = "del" ]
then
    del=1
    i=$((i+1))
    eval key=\"\$$i\"
    if [ $i != $# ]
    then
	i=$((i+1))
	eval val=\"\$$i\"
	val_del=1
    else
	val_del=0
    fi
elif eval [ \$$i = "select" ]
then
    select=1
    i=$((i+1))
    if [ $i = $# ]
    then
	eval expr=\"\$$i\"
	expr_select=1
    else
	i=$((i-1))
	expr_select=0
    fi
elif eval [ \$$i = "flush" ]
then
    flush=1
else
    exit_usage
fi

if [ $i != $# ]
then
    exit_usage
fi

if [ $cr = 1 ]
then
    > $filename
fi

if [ $put = 1 ]
then
    if echo "$key" | grep '^\$' > /dev/null
    then
	key=$(echo "$key" | cut -d '$' -f 2)
	if cat $filename | grep "^$key:=-=:" > /dev/null
	then
	    key=$(cat $filename | grep "^$key:=-=:" | sed "s/:=-=:/|/" | cut -d "|" -f 2)
	else
	    echo No such key : "$key"
	    exit
	fi
    fi
    if echo "$val" | grep '^\$' > /dev/null
    then
	val=$(echo "$val" | cut -d '$' -f 2)
	if cat $filename | grep "^$val:=-=:" > /dev/null
	then
	    val=$(cat $filename | grep "^$val:=-=:" | sed "s/:=-=:/|/" | cut -d "|" -f 2)
	else
	    echo No such key : "$val"
	    exit
	fi
    fi
    if test -s $filename
    then
	if cat $filename | grep "^$key:=-=:" > /dev/null
	then
	    res=$(cat $filename | grep "^$key:=-=:")
	    res2=$(cat $filename | grep "^$key:=-=:" | sed "s/:=-=:/|/" | cut -d "|" -f 2)
	    len=${#res2}
	    if [ $len != 0 ]
	    then
		cat $filename | sed "s/$res/$key:=-=:$val/" > $filename
	    fi
	else
	    echo -n "$key" >> $filename
	    echo -n ':=-=:' >> $filename
	    echo "$val" >> $filename
	fi
    else
	echo -n "$key" >> $filename
	echo -n ':=-=:' >> $filename
	echo "$val" >> $filename
    fi
elif [ $del = 1 ]
then
    if echo "$key" | grep '^\$' > /dev/null
    then
	key=$(echo "$key" | cut -d '$' -f 2)
	if cat $filename | grep "^$key:=-=:" > /dev/null
	then
	    key=$(cat $filename | grep "^$key:=-=:" | sed "s/:=-=:/|/" | cut -d "|" -f 2)
	else
	    echo No such key : "$key"
	    exit
	fi
    fi
    if cat $filename | grep "^$key:=-=:" > /dev/null
    then
	if [ $val_del = 1 ]
	then
	    if echo "$val" | grep '^\$' > /dev/null
	    then
		val=$(echo "$val" | cut -d '$' -f 2)
		if cat $filename | grep "^$val:=-=:" > /dev/null
		then
		    val=$(cat $filename | grep "^$val:=-=:" | sed "s/:=-=:/|/" | cut -d "|" -f 2)
		else
		    echo No such key : "$val"
		    exit
		fi
	    fi
	    if cat $filename | grep "^$key:=-=:$val\$" > /dev/null
	    then
		cat $filename | sed "/^$key:=-=:$val\$/d" > $filename
	    fi
	else
	    res=$(cat $filename | grep ^$key:=-=:)
	    if cat $filename | sed "s/$res/$key:=-=:/" > $/dev/null
	    then
		cat $filename | sed "s/$res/$key:=-=:/" > $filename
	    fi
	fi
    else
	exit
    fi
elif [ $select = 1 ]
then
    if [ $expr_select = 1 ]
    then
	if echo "$expr" | grep '^\$' > /dev/null
	then
	    expr=$(echo "$expr" | cut -d '$' -f 2)
	    if cat $filename | grep "^$expr:=-=:" > /dev/null
	    then
		expr=$(cat $filename | grep "^$expr:=-=:" | sed "s/:=-=:/|/" | cut -d "|" -f 2)
	    else
		echo No such key : "$expr"
		exit
	    fi
	fi
	if [ $k = 1 ]
	then
	    while read line
	    do
		if str=$(echo "$line" | sed "s/:=-=:/|/g" | cut -d "|" -f 1 | grep "$expr")
		then
		    cat $filename | grep "$str:=-=:" | sed "s/:=-=:/=/g"
		fi
	    done < $filename
	else
	    while read line
	    do
		if str=$(echo "$line" | sed "s/:=-=:/|/" | cut -d "|" -f 1 | grep "$expr")
		then
		    res=$(cat $filename | grep "$str:=-=:" | sed "s/:=-=:/|/" | cut -d "|" -f 2)
		    len=${#res}
		    if [ $len != 0 ]
		    then
			cat $filename | grep "$str:=-=:" | sed "s/:=-=:/|/" | cut -d "|" -f 2
		    fi
		fi
	    done < $filename
	fi
    else
	if [ $k = 1 ]
	then
	    cat $filename | sed "s/:=-=:/=/"
	else
	    cat $filename | sed "s/:=-=:/|/" | cut -d '|' -f 2 | grep -v "^\$"
	fi
    fi
elif [ $flush = 1 ]
then
    > $filename
else
    exit_usage
fi
