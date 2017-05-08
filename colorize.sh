#!/bin/sh

cat \
	| sed "s|A|$(echo "\033[0;31mA\033[0m")|g" \
	| sed "s|B|$(echo "\033[0;32mB\033[0m")|g" \
	| sed "s|C|$(echo "\033[0;33mC\033[0m")|g" \
	| sed "s|D|$(echo "\033[0;34mD\033[0m")|g" \
	| sed "s|E|$(echo "\033[0;35mE\033[0m")|g" \
	| sed "s|F|$(echo "\033[0;36mF\033[0m")|g" \
	| sed "s|G|$(echo "\033[0;31mG\033[0m")|g" \
	| sed "s|H|$(echo "\033[0;32mH\033[0m")|g" \
	| sed "s|I|$(echo "\033[0;33mI\033[0m")|g" \
	| sed "s|J|$(echo "\033[0;34mJ\033[0m")|g" \
	| sed "s|K|$(echo "\033[0;35mK\033[0m")|g" \
	| sed "s|L|$(echo "\033[0;36mL\033[0m")|g" \
	| sed "s|M|$(echo "\033[0;31mM\033[0m")|g" \
	| sed "s|N|$(echo "\033[0;32mN\033[0m")|g" \
	| sed "s|O|$(echo "\033[0;33mO\033[0m")|g" \
	| sed "s|P|$(echo "\033[0;34mP\033[0m")|g" \
	| sed "s|Q|$(echo "\033[0;35mQ\033[0m")|g" \
	| sed "s|R|$(echo "\033[0;36mR\033[0m")|g" \
