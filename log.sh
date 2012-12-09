#!/bin/bash

while [ 1 ]
do
	echo "$(date +%s) $(./temper)"
    sleep 1s
done
