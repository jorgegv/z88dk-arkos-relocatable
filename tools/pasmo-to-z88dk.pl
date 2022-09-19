#!/usr/bin/perl

use strict;
use warnings;
use utf8;

my @output;

my $input = $ARGV[0];
defined( $input ) or
	die "usage: $0 <pasmo_asm_file>\n";

open SRC, $input or
	die "Could not open $input for reading...\n";

my @all_symbols;
while ( my $line = <SRC> ) {
	chomp $line;
	$line =~ s/\r//g;				# remove DOS-style line feeds
	$line =~ s/db /defb /g;				# DB -> DEFB
	$line =~ s/dw /defw /g;				# DW -> DEFW
	$line =~ s/\$\+/0x/g;				# replace $+ for 0x
	$line =~ s/^\s+/\t/g;				# all leading blanks -> 1 tab

	if ( $line =~ /^(\w+)$/ ) {			# add : to all labels which are
		push @output, "\n$1:\n";		# alone on a single line
		push @all_symbols, $1;			# ...and save the symbol
		next;
	}

	if ( $line =~ /^(.+)\s+equ\s+(.*)$/ ) {		# replace EQU defs with DEFC
		push @output, "defc $1 = $2\n";
		next;
	}

	if ( $line =~ /^(\w+)\s+(.*)$/ ) {		# add : to all labels with
		push @output, "$1:\n\t$2\n";		# instructions on the same line
		push @all_symbols, $1;
		next;
	}

	push @output, "$line\n";			# save processed line
}
close SRC;

print join( "", @output ), "\n";
