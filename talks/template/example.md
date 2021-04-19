---
author: Ulises Tirado Zatarain
title: Algorists Template for Talks
date: Nov, 2020
---

# Formulas and equations
> - Example of math using an underscore and mathcal: $a_i \in \mathcal{A}$
> - Example of math using an arrow and mathbb: $\overrightarrow{\beta} \notin \mathbb{B}$
> - Example of math using an super script and mathbf: $c^k \subset \mathbf{C}$
> - Following there is a more complicated formula:
$$
\Gamma^n=\int^{b}_{a}{\frac{4py}{k\epsilon}}dy
\times
\begin{bmatrix}
    x & y & z \\
    u & v & w
\end{bmatrix}
$$

---

# Code in C++
Let see what the code looks like:
```cpp
for (auto& x: S) {
	if (x > 10) {
		printf("%d\n", x);
	}
}
```

---

# Including source code files
You can also include a cpp file:

\cplusplus{example}

---

# Algorithm Example (\LaTeX/`algorithm2e`)
\begin{algorithm}[H]
\SetAlgoLined
\While{$n>5$}{
    instructions\;
    \eIf{condition}{
        instructions1\;
        instructions2\;
    }{
        instructions3\;
    }
}
\end{algorithm}

---

# Algorithm Example (`pseudocode`)
```algorithm
map of <string, integer> dictionary;
vector of integer numbers;
pair of <integer, integer> position;
set of integer S;
unique pointer of character c = null;
const reference
for each any x in S do:
	if x > 10 then:
		writeln("%d", x);
	end
end

integer index = 0;
repeat:
    index++;
until index >= 10;
```
