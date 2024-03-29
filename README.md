# Scheduling Program

## Requirements

This project does not require any external packages aside from a `c++` compiler. On my machine, I have used `g++`:

```
> g++ --version
Apple clang version 12.0.0 (clang-1200.0.32.2)
Target: x86_64-apple-darwin19.6.0
Thread model: posix
```

## Compilation

Simply run `make`. If that doesn't work, the project is compiled using this command in the root directory:

```
g++ -Wall -std=c++17 src/*.cpp -o main
```

So simply replace `g++` with whatever works on your system. `c++17` is required, I think.

This will generate a binary in the root directory called `main`. If this doesn't have executable permissions, this can be fixed with `chmod +x main`.

## Usage

There are three different functionalities: generate a whole roster, finishing a partially-completed roster, and recommending a hire. Each requires different flags.

The commandline application takes the format `./main [command] [args]` where the command is a flag which specifies what functionality will be used. Run the `./main --help` command to see a list the formats, but some short examples:

**Generate a whole roster**
```
> ./main --gen input/simple.requirements input/simple.availability -sw 10 -sa 5 -o simple.schedule
Schedule written to "simple.schedule"
```

**Finish a partially-completed roster**
```
> ./main --gen input/simple.requirements input/simple.availability input/partial.schedule -sw 10 -sa 5 -o complete.schedule
Schedule written to "complete.schedule"
```

## Testing

All tests are defined in the `/tests` subdirectory, and can be run using the
`make test` rule. Takes my 2015 Macbook about 10 seconds to run.

The unit test framework is provided by [Catch2](https://github.com/catchorg/Catch2) which easy-to-use, an industry standard `c++` testing suite. The test framework (e.g. the `REQUIRE(...)` functions) are *not* my own work, though the tests themselves are. I've included the header file directly in my project to avoid needing to install anything.

---

## Input Formats

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
