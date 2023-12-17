# Lingo_final
Lingo Programming Language Documentation
Language Specification
The Lingo Programming Language is designed to offer a simple yet intuitive syntax for basic programming operations. It supports basic arithmetic, variable handling, and a set of unique keywords for various operations.
Syntax and Semantics
Lingo's syntax is straightforward, focusing on readability and ease of use. The language syntax includes: 
- Variables: Identifiers for storing data values.
- Arithmetic Operations: +, -, *, and / for basic calculations.
- Custom Keywords: Special commands like 'Showme', 'Remember', etc., for specific functions.

Usage
Lingo programs can perform basic arithmetic, control structures, and demonstrate the use of custom keywords. To use Lingo, write the code in a plain text file with a .lingo extension and run it through the Lingo interpreter.
How to Run Lingo Programs
To run a Lingo program, follow these steps:
1. Write your code in a .lingo file.
2. Use the Lingo interpreter to execute the file. This can be done by compiling the Lingo source code and then running the resulting executable with the .lingo file as input.
Design Choices and Rationale
The design choices for Lingo were driven by the goal of creating a simple and educational language. Key decisions include:
- Simplicity: Ensuring that the syntax is easy to understand and write.
- Educational Value: Designing features that help beginners learn basic programming concepts.
- Custom Keywords: Introducing special keywords to make the language unique and engaging.

Syntax Specifics
Showme: Displays the result of the expression that follows it.
Remember: Stores the result of the expression that follows it for later use.
getIn: Typically used for initializing or entering a new scope or context.
getOut: Often used for exiting a scope or context.
give: Used to assign or pass a value or expression.
steal: Takes a value or expression, potentially for reassignment or manipulation.
LikeMe: Could be a comparison operator, checking for equality.
notLikeMe: Negation of LikeMe, checking for inequality.
moreThanMe: Compares two values or expressions, checking if one is greater than the other.
lessThanMe: Opposite of moreThanMe, checks if one value or expression is less than another.
IsitTrue: A conditional check, likely evaluating the truthiness of an expression.
hide: Potentially used for encapsulating or hiding a segment of code or data.
ofCourse: Might be used as an affirmation, possibly in conditional or loop structures.
never: A keyword for negation or representing a false condition.
