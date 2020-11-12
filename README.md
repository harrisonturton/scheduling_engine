# Scheduling Program

## Compilation

You should be able to compile this by running `make`, which should output an
binary executable `./main` to run.

```
> make
> ./main
```

If the executable doesn't have the correct permissions straight away (it does
on my system, but sometimes it differs), simply run:

``
> chmod +x main
``

## Roadmap

* Best-effort roster generation (given constraints)
* Roster completion
* Recommended hire?

## Todo

* Implement AVL tree
* Dynamic programming solution
* Local heuristic search

## Testing

All tests are defined in the `/tests` subdirectory, and can be run using the
`make test` rule. Takes my 2015 Macbook about 7 seconds to run.
