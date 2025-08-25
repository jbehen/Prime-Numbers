#!/usr/bin/perl

#$| = 1;

use strict;
use warnings;

my $max = $ARGV[0];

$max = 23456790 unless $max;

# understanding the desired dataset with 2 being the 1st prime and every odd number being a potential prime

my @prime = (2);

for (my $i = 3; $i <= $max; $i += 2)
{
	my $is_prime = 1;
	my $sqrt_i = sqrt($i);
	
	foreach my $p (@prime)
	{
		if ($i % $p == 0)
		{
			$is_prime = 0;
			last;
		}
		elsif ($p > $sqrt_i)
		{
			last;
		}
	}
	
	push @prime, $i if $is_prime;
}

if (1)
{
	foreach (@prime)
	{
		print "$_\n";
	}
}
