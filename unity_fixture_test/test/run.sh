#!/bin/bash

for i in ./test/build/*
do
	if test -f $i
	then
		./$i
	fi
done

echo ""
