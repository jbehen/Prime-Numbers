#!/usr/bin/perl

#$| = 1;

#use strict;
#use warnings;

my @prime = (2);

foreach my $i (3..23456790)
{
	# no even numbers
	next unless ($i % 2);

	my $is_prime = 1;
	my $sqrt_i = sqrt($i);
	
	foreach my $p (@prime)
	{
		if ($p > $sqrt_i)
		{
			last;
		}
		elsif ($i % $p == 0)
		{
			$is_prime = 0;
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
