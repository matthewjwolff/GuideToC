==============================
A Short Guide to C Programming
==============================

Introduction
------------

This guide is meant for programmers familiar with common higher-level languages who might otherwise find it difficult 
to transition to a low level language. This guide assumes the reader is proficient in a general purpose programming 
language. This guide uses Java as its example high level language. 

The C programming language is credited mainly to Dennis Ritchie, with some help from Ken Thompson (the creator of 
the original UNIX operating system) and Brian Kernighan (co-author of the K&R C book). Its original purpose was to 
be the preferred programming language for the UNIX operating system. It allowed programmers of UNIX to use less 
assembly code and more platform-independent C code. It allows nearly all the power of assembly programming but 
more expressivity.

C is an *imperative* programming language. The programmer tells the computer what to do with function calls and 
statements. There are no objects and no object orientation capabilities in C, though as an exercise this guide will 
implement a basic object-orientation system in C. 

Chapter 1: Language comparison
------------------------------

First, we'll examine some code snippets in Java and how one might write the equivalent statements in C syntax. 

The main purpose of this chapter is to examine some of the ways C has influenced more modern languages. A lot of C 
should be very familiar for this reason. 

The exercise for this chapter will be implementing Quick Sort in Java (as a reference) and in C. 
The two main files are ``QuickSort.java`` and ``quicksort.c``. 

Let's examine the Java code and see what the statements do. 

Much of Java's syntax revolves around its object oriented nature. Most 
source files contain classes (the compiler actually mandates that every 
public class must be in an identically named classname.java file) and 
methods have a bunch of modifiers that only make sense in an object 
oriented language. For example, ``public`` and ``private`` determine 
whether code outside the object can use the method, and ``static`` 
determines whether the code is a class method or just a global function. 
In C, none of these modifiers exist. Functions (not methods, because 
there are no classes) are simply declared as 
``return_type function_name(params...)``. Notice that the Java methods 
are all static, as we're explicitly not using any object orientation. 
But enough with Java. Let's move on to C. 

The first thing you should notice is that the code is very very similar. 
In fact, the code for ``quicksort`` and ``swap`` was literally copied 
from the Java file to the C file with no changes except for code style. 
This was intentional, doing simple imperative programming in both 
languages is extremely similar.

Next, let's discuss language conventions. Java likes to use camelCase 
and four space indents, while C tends_to_use_underscores and uses 8 
space indents. Neither of these are mandated. If you prefer tabs, then 
both languages would use single tab indents, but the tabs would probably 
be rendered as 8 spaces when viewing C code. The difference in 
indentation should make sense when considering Java's extra scopes 
imposed by its forced object orientation. 

Now onto syntax differences. Look at the function declarations. We 
already discussed the lack of modifiers on the functions, but there's 
also another tiny difference that has larger implications. The first 
parameter in java is ``int[] a`` but in C it is ``int a[]`` (similarly 
in the main methods the arrays are declared as ``int[] array`` for Java 
and ``int array[]`` for C. Java added a real array type to the language 
but in C the programmer is given no such convenience. So we must learn 
how to deal with primitive arrays.

In C, there is no "array type". In fact, an array is really a pointer 
to the first element of a contiguous set of memory cells. So anything 
that can be done with arrays can be done with pointers. We'll get into 
pointers later though, but just understand that in C the machine knows 
a lot less about arrays than in Java. This is why the [] are put on the 
variable name and not the type: the [] just signifies that the variable 
is a pointer to a memory location that should be interpreted as the 
type (the definition of a pointer). 

That might have been a bit terse, so let's just get to what we cannot 
do in C. There is no .length that will give you the length of an array. 
To find the number of elements in an array, we can use the expression
``sizeof(a)/sizeof(a[0])``. ``sizeof`` is a compiler macro, meaning 
that it is executed by the compiler, not when you run the program. When 
you compile, ``sizeof(a)`` will be replaced with the size in bytes of a. 
Since a is known to be an array, you'll get the total bytes that a 
occupies. Simply divide (at run time) by the size of a single element 
and you'll have the number of elements. However, compiler macros don't 
always work: if you try to use ``sizeof`` on an array passed in as a 
parameter (like in the quicksort method), you'll only get the size in 
bytes of a pointer (because arrays are really just pointers). You'll 
notice that my array printing method takes as a parameter the size of 
the array. This is the reason I have to do that.

Next, let's discuss the preprocessor. The C preprocessor is a part of 
the compiler and is the first stage of compiling a C program. It will 
look for **compiler directives** (beginning with a **#**) and replace 
them with the result of the directive. Some useful directives are:

- ``#include "name"`` pastes the text of name at that point of the file. 
Name is the path to a file starting from the current directory.

- ``#include <name>`` is a slight variant of the above. Here the 
preprocessor looks among your system's include directory for the named 
file (often ``/usr/include/``). These files are like the ``java.x`` 
packages that you might have to ``import``. 

- ``define MACRO(params) (replacement)`` creates a macro that can be 
used elsewhere in your code. These often provide convenience to the 
programmer and are usually written in ALLCAPS. An example is LENGTH(x), 
which is replaced with the above way to compute the length of an array. 

There are many other preprocessor directives, but these are the most 
useful to the beginner C programmer. 

'Homework'
----------

Pick your favorite sorting algorithm, and implement it in Java (or a 
similar high-level language) as a reference,  and then implement it in C. 
Feel free to reuse as much code from here as possible, just pick a 
different algorithm. Choosing harder algorithms will teach you 
more about the languages. 
