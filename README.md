# Suffix Tree

This is a naive implementation of a suffix tree made in C. It allows you to
build and print the suffix tree representation of a word using **dot**.

# How to

## Build

Simply type the command `make`.

## Usage

To output a suffix tree representation you have to give several arguments.

```
$ ./tree bananas out.dot
```

This will output a dot file containing the representation of your word. To
generate the image corresponding:

```
$ dot -Tpng out.dot > out.png
```

It will create an image like this:

![Bananas generated file](img/bananas.png)
