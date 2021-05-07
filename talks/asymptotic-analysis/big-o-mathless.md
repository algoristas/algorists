---
author: Ulises Tirado Zatarain
title: Big $\mathcal{O}$ notation
date: May, 2016
---

# A little problem: What kind of algorithm is that?

```algorithm
/* uli is an abbreviation for the type:
   unsigned long int */
function do_something_weird(uli $x$, uli y): uli
    uli result = 0;
    while x != 0 do:
        if x & 1 == 1 then:
            result = result + y;
        end
        x = x >> 1;
        y = y << 1;
    end
    return result;
end
```

---

# Definitions
- Big $\mathcal{O}$ time/space is the lenguage and metric we use to describe the efficiency of algorithms.
- Imagine the following scenario:
  - You got a file on a hard drive and you need to send it to a friend who lives across the country. You need to get the file to your friend as fast as possible. How should you send it?
  - E-mail
  - FTP, HTTP, SCP, ...
  - Dropbox, Google Drive, Sky Drive, ...
  - Airplane
  - What if the file was really large?

---

# Definitions
> - The ammount of elemental operations or stored information to solve a problem we know as "Computational Complexity"
- The are two kinds of complexity:
  - Runtime (temporal complexity)
  - Memory (spatial complexity)
 - Big $\mathcal{O}$ notation allow us classify our algorithms in categories based-on input size.

---

# Notation $\mathcal{O}\left(\cdot\right)$: categories
- Those categories are:
  - $\mathcal{O}\left(1\right)$, $\mathcal{O}\left(n\right)$, $\mathcal{O}\left(n^2\right)$, $\mathcal{O}\left(n^3\right)$, $\mathcal{O}\left(n^4\right)$, ...
  - $\mathcal{O}\left(\log n\right)$, $\mathcal{O}\left(n\log n\right)$, $\mathcal{O}\left(n^2\log n\right)$, ...
  - $\mathcal{O}\left(n!\right)$, $\mathcal{O}\left(2^n\right)$, ... 
  - What the hell does this mean? $\mathcal{O}$.o o.$\mathcal{O}$ @-@

---

# Definitions and notation

- For example, to send a file to a friend the run time is:
  - By e-mail, FTP, Dropbox is $\mathcal{O}\left(s\right)$ where $s$ is the file size.
  - By airplane is $\mathcal{O}\left(1\right)$.
  - But, maybe is $O\left(2^{n}\right)$ in money, where $n$ ...? WTF! Why?
- Rule: Drop the constants
  - What?
  - Why?
  - Example: seems that to send by e-mail is indeed at least $2s$ in time where $s$ is the file size.

---

# Best, Worst and Average/Expected cases

- Think about search an element in an unsorted simply linked list:
  - Best case: the element is at the start of the list. (Maybe you think this is $\mathcal{O}\left(1\right)$).
  - Worst case: the element is at the end of the list. (Maybe you think this is $\mathcal{O}\left(n\right)$).
  - Average/Expected case: the element is in any position at the list. (What do you think about this?)

---

# Examples: Print elements in arrays $A$ and $B$

$\mathcal{O}\left(a+b\right)$: where $a$ and $b$ are the size of array $A$ and $B$ respectively.
```algorithm
for each x in A:
	print(x);
end
for each y in B:
	print(y);
end
```

---

# Examples: Print elements in arrays $A$ and $B$

$\mathcal{O}\left(ab\right)$: where $a$ and $b$ are the size of array $A$ and $B$ respectively.
```algorithm
for each x in A:
	for each y in B:
        print(x,y);
	end
end
```

---

# Examples: Print elements in arrays $A$

$\mathcal{O}\left(n^2\right)$: where $n$ is the size of array $A$.
```algorithm
for i = 0 to n - 1 do:
	for j = i to n - 1 do:
        print(A[j]);
	end
end

A[0], A[1], A[2], ... , A[n-1]
A[1], A[2], ... , A[n-1]
A[2], ... , A[n-1]
.
.
.
A[n-1]
```

---

# What does following function? What is the run time?

```algorithm
function something(n: integer): integer
    x = 0;
    while x * x < n do:
        x = x + 1;
    end
    return x;
end
```

---

# References

- [Gayle Laakmann - Cracking the Coding Interview](http://#)
- [Robert Sedgewick - Algorithms C++](http://#)
- [Thomas H. Cormen - Introduction to Algorithms](http://#)
- [Donald E. Knuth - The Art of Computer Programming](http://#)
- [Wikipedia](https://en.wikipedia.org/wiki/Computational_complexity_theory)
- [Quora](https://www.quora.com)

  
