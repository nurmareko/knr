
for (initial position; while there's another character; increment position)
	if (is blank character)
		if (not at tabstop)
			increment blanks counts
		else, at tabstop
			reset blank counts
			increment tab counts
	else, is not blank character
		for (; while tab count is not zero; decrement tab count)
			write tab character
		if (is tab character)
			reset blank count
		else, is not tab character
			for (; while blank count is not zero; decrement blank count)
				write blank character
		write character
		if (is newline character)
			reset position
		else if (is tab character)
			update position
