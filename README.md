# Differentiator
**_"Wherever you poke, it's all rubbish... Don't just rub it, otherwise we won't collect the ends later."_**

## Content:
- [How to use it](#how-to-use-it)
- [Functions & operands](#functions--operands)
- [WARNING](#warning)
- [Result](#result)
- [Generating an article](#generating-an-article)
	- [Generating phrases](#generating-phrases) 
	- [Word usage statistics](#word-usage-statistics)
	- [Creating LaTeX file](#creating-latex-file)
	- [Simplified expression](#simplified-expression)

## How to use it
Inside the program you can choose the way (from console or file) to enter your function.

>[Back to Content](#content)

## Functions & operands
* **``(MINUS, -)``**
* **``(PLUS,  +)``**
* **``(MUL,   *)``**
* **``(DEGREE,^)``**
* **``(DIV,   /)``**
* **``tg``**
* **``ctg``**
* **``sin``**
* **``cos``**
* **``sh``**
* **``ch``**
* **``ln``**

>[Back to Content](#content)

## WARNING
You have to follow the correct bracket sequence. Spaces are optional.
For example:
```
 x
(x)*(2)
(x)^(ln(x))
(sin(sh(cos(x))))  *  (2)
(sh(ch(1.23))) ^ (ln(3.67))
(ln(x)) + (tg(ctg(x)))
```

>[Back to Content](#content)

## Result
After use, you can download a latex file to convert it into a small article. Markov chains are used to construct phrases, so the text's never repeated.

>[Back to Content](#content)

## Generating an article

### Generating phrases
The construction of Markov chains is used to construct the text. To do this, it is necessary to give examples of texts and phrases in order to use the collected statistics on the use of words and expressions in the future.

- - -

### Word usage statistics
**A proprietary hash function is used for distribution to storage cells.**

**Format for storing statistics on the use of words:**

``{``\
&emsp;``discuss - 1 -> them``\
&emsp;``are - 4 -> amazed -> very -> doing -> solved``\
``}``

- - -

### Creating LaTeX file
After collecting statistics and processing the function, a file is created that can be found in the workspace.

- - -

### Simplified expression
**For aesthetic appeal, the expression is simplified.**

A = $x \cdot ln(sh(x) ^ {x})$\
B = $ctg((A))$\
C = $sin(x) + (B)$\
D = $x - (C)$\
E = $ctg((D))$\
F = $(E) ^ {ln(ctg(x))}$\
G = $sh((F))$\
H = $x ^ {(G)}$\
I = $ctg(ln(sh(x ^ {x})))$

>[Back to Content](#content)

## ©Copyright
<p align="center">
	<img src="README/LogoMIPT/mipt1.png" 
		width="50%" 
		style="background-color: transparent;"
	/>
	<img src="README/LogoMIPT/greyFRKT.png" 
		width="30%"
		style="background-color: transparent;"
	/>
<p>
