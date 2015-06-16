#!/bin/bash

for i in ./test/build/*
do
	if test -f $i
	then
		./$i $1
	fi
done

echo ""
