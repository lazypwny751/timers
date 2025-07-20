#!/bin/sh

set -e

echo "${0##*/}: processing operations for \"${0:-build}\"..."
case "${1}" in
	"clean")
		[ -d "build" ] && rm -rf "build"
	;;
	*)
		if [ "${1}" != "build" ] && [ "${1}" != "" ] 
		then
			echo "${0##*/}: \"${1}\" is an unknown option defaulting to \"build\""
		fi
		[ ! -d "build" ] && mkdir -p "build"
		# gcc -I"include" -c "src/ton.c" "src/tof.c" -o "build/timers.o" # <- make this logic in Makefile or here as shell.
	;;
esac
echo "${0##*/}: operations \"${0:-build}\" done..."
