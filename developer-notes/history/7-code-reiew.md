# Code Review

## Variables Naming

- `UPPER_CASE` for constants and pins
- `snake_case` or `camalCase` for variables and functions
- `CapitalCase` for classes

use meaningful names that describe use of variable or function.

Try to use shorter names.

## Use of `#define`

use `#define` for pin numbers

for example:
```ino
#define R_LED_1 6
```

instead of 
```ino
const int R_LED_1 = 6;
```

## Use of `const`

Constants are usually used for settings that can be adjusted for program.

for example:
```ino
const long BLINK_INTERVAL = 35;
```

## Comments

Use short comments where required.