# Binary expression evaluator

Evaluates expressions in propositional logic.
Write the expression into the .expr file and the values for each variable into the .map file

## Features
- Implicit brackets
- Parses (!a + b) as ((!a) + b) to save time

## Syntax
```
* : Logical AND
+ : Logical OR
! : Logical NOT

Example:
(!a + b) * !(c * d)
```

## Example
```
// MUX_4BIT.expr
(D0 * !S1 * !S0) + (D1 * !S1 * S0) + (D2 * S1 * !S0) + (D3 * S1 * S0)

// MUX_4BIT.map
D0: false
D1: false
D2: false
D3: true
S0: true
S1: true

// ./truthtable MUX_4BIT.expr MUX_4BIT.map
Variables:
        S1:: true
        D3:: true
        D2:: false
        S0:: true
        D1:: false
        D0:: false
Expression: (((((D0 + (!S1)) + (!S0)) * ((D1 + (!S1)) + S0)) * ((D2 + S1) + (!S0))) * ((D3 + S1) + S0))
Result: false
```

## Usage
```bash
make
./truthtable "(path to expression file)" "(path to map file)"
```
## Run Examples
```bash
./truthtable tests/SIMPLE.expr tests/SIMPLE.map
./truthtable tests/MUX_4BIT.expr tests/MUX_4BIT.map
```

## Future features
Option to generate a truth table (for all valuations) rather than a specific .map
