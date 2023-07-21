# SimpleParser

A simple parser that can be implemented in an application that needs to draw objects to a display programmatically via an external file.

#Comments
// This is a comment
Write a line of text that will not get processed during parsing.
This can be used anywhere in the code.

#Built-in functions [BUILT-IN FUNC]
##.color(R, G, B);
Selects a color to be applied to the next build-in function.
R = RED
G = GREEN
B = BLUE

##.line(int x, int y, int xx, int yy);
Draw a line at coordinate (X,Y) to coordinate (XX, YY).

##.circle(int x, int y, int r);
Draw a circle at coordinate (x, y) with a radius of (r).

##.rectangle(int x, int y, int xx, int yy);
Draw a rectangle from upper left corner at coordinate (x, y) to bottom right corner to (xx, yy).

##.text(int x, int y, int thickness, (string) TEXT);
Draw a text at coordinate (x, y) with a thickness of (thickness).

#Arithmetics [ARITHMETIC]
##IFs
###If example
if (STATEMENT) {
    [ARITHMETIC|VAR|BUILT-IN FUNC]
    ...
    ...
}
Execute code within the code block if STATEMENT is true.
STATEMENT: [STRING|VAR] operator [STRING|VAR]
OPERATOR: [>|<|=|!=|<=|>=]

###If-else example
if (STATEMENT) {
    [ARITHMETIC|VAR|BUILT-IN FUNC]
    ...
    ...
} else {
    [ARITHMETIC|VAR|BUILT-IN FUNC]
    ...
    ...
}
Execute code within the IF code block if STATEMENT is true. Otherwise execute code in the ELSE code block.
STATEMENT: [STRING|VAR] operator [STRING|VAR]
OPERATOR: [>|<|=|!=|<=|>=]

###If-else if-else example
if (STATEMENT) {
    [ARITHMETIC|VAR|BUILT-IN FUNC]
    ...
    ...
} else if (STATEMENT) {
    [ARITHMETIC|VAR|BUILT-IN FUNC]
    ...
    ...
[} else if (STATEMENT) { ... }...]
[...]
} else {
    [ARITHMETIC|VAR|BUILT-IN FUNC]
    ...
    ...
}
Execute code within the IF code block if STATEMENT is true. Otherwise jump to ELSE IF and compare the STATEMENT - execute if true.
Continue the check un till a match is found or reach a ELSE code block.
STATEMENT: [STRING|VAR] operator [STRING|VAR]
OPERATOR: [>|<|=|!=|<=|>=]

##FOR
###For example
for (int i to int j) {
    [ARITHMETIC|VAR|BUILT-IN FUNC]
    ...
    ...
}
Repeatively execute the code within the code block DELTA number of times.
DELTA: j - i 