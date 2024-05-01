# Cat

The current procedure for processing any given input files is really simple, but
everything is crammed into the `main` function at the moment, so it looks more
complicated than it is.

This is what we are doing once we've finished processing command-line arguments.

```
FOREACH file DO
  OPEN file
  READ file
  CLOSE file
DONE
```

Note that I haven't defined any command-line arguments yet, so we "process" them
in the sense that we do parse the command-line, but we don't use the
command-line arguments after that unless the `--help` option is detected, in
which case we print the usage message and exit right away.
