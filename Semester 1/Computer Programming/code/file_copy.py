#! /usr/bin/python

with open('text.txt', 'r+') as in_file:
    with open('text_copy.txt', 'w+') as out_file:
        for line in in_file:
            out_file.write(line)
