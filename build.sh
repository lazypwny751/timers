#!/bin/sh

set -e

echo "${0##*/}: processing operations for \"${0:-build}\"..."
case "${1}" in
	"clean")
		[ -d "build" ] && rm -rf "build"
		echo "> removed build."
	;;
	*)
		if [ "${1}" != "build" ] && [ "${1}" != "" ] 
		then
			echo "${0##*/}: \"${1}\" is an unknown option defaulting to \"build\""
		fi
		[ ! -d "build" ] && mkdir -p "build"
		for c in "src/"*".c"
		do
			base="${c##*/}"
			gcc -I"include" -c "${c}" -o "build/${base%.*}.o"
			echo "> ${base} exported as ${base%.*}.o"
		done
	;;
esac
echo "${0##*/}: operations \"${0:-build}\" done..."
