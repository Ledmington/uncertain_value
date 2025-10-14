# Uncertain Value
A library to track how floating point errors propagate through C++ code.

## Coming soon
- Deduce expression and visibly track the error on an example run.
- Add `strict_uncertain_value`: a stricter version of `nominal_uncertain_value` which checks if the error range allows a given operation before executing it.
- Add `gaussian_uncertain_value`: changes the error model to a probabilistic model in which the error is the standard deviation of a normal distribution centered on the given value.
