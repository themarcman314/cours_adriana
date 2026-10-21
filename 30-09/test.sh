#!/bin/bash

echo "Les paramètres sont : $*"

for param in "$@";
	do echo "parametre $param"
done
