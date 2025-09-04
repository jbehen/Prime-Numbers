#!/usr/bin/perl

use strict;

use warnings;



# Return all primes <= n as a list (fast, pure-Perl)

sub primes_upto {

    my ($n) = @_;

    return ()       if $n < 2;

    return (2)      if $n < 3;



    # Map index i -> odd number p = 2*i + 3   (i = 0..m)

    my $m     = int(($n - 3) / 2);  # highest index

    my $sieve = "";                 # bitset; 1 = composite, 0 = prime

    vec($sieve, $m, 1) = 0;         # allocate bits



    my $r = int( (sqrt($n) - 3) / 2 );  # max i where p^2 <= n



    for (my $i = 0; $i <= $r; $i++) {

        next if vec($sieve, $i, 1);     # already marked composite

        my $p = 2*$i + 3;               # the prime

        my $j = int( ($p*$p - 3) / 2 ); # index for p^2

        for (; $j <= $m; $j += $p) {    # stride by p over odds

            vec($sieve, $j, 1) = 1;

        }

    }



    my @primes = (2);

    for (my $i = 0; $i <= $m; $i++) {

        push @primes, 2*$i + 3 if vec($sieve, $i, 1) == 0;

    }

    return @primes;

}



# Demo: print primes <= the first argument (default 1_000_000)

my $N = @ARGV ? 0 + $ARGV[0] : 23456789;

foreach (primes_upto($N))
{
	print "$_\n";
}