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

## Input Formatting

There are three types of files that this program uses. A `requirements` file,
an `availability` file, and a `schedule` file. These names are the file
extensions, and each file has different syntax.

* `requirements` specifies what people with what skills must be present on any given shift
* `availability` specifies what skills, and what shifts, every person can work
* `schedule` is the outputted schedule taking into account the previous two files, or the partially-filled one which must be completed.


### Requirements

```
[people count] [list of skills]
...55 more lines
```

This represents a single shift. There should be `7*8=56` different shifts
specified. Consider a shift which requires two employees and a manager to be rostered.
This would look like:

```
3 1 1 2
```

Where `3` is the number of employees to be scheduled, and `1 1 2` shows that we
need two employees (role number `1`) and a manager (role number `2`)

## Availability

```
[number people]
[Name]
[skills]
[shift 1 availability] [shift 2 availability] ... [shift 56 availability]
...other people
```

The `skills` field specifies the roles that this person can perform. As above,
a `1` would mean they can do the job of a regular employee, and `2` means they
can do the job of a manager.

The availability of a shift is specified by `1` if they can work it, or `2` if
they cannot.

Consider a business with 2 employees. John is a regular employee and can work
every shift except Mondays. Jane is a manager and can work every shift through
the week.

The availability file would look like:

```
1
0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 2
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
```

## Schedule

```
1
0 1
```

Each line is a list of people who are working that day. Each element is the
index of the person in the `availability` file.
