#!/bin/bash

while [ 1 ]
do
	echo "$(date +%s) $(./temper)"
    sleep 2s
done
