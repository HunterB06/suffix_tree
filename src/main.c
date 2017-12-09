#include <stdio.h>

#include "suffix_tree.h"

#define USAGE() printf("Usage:\n%s: <word> <output_file.dot>\n", argv[0])


int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        USAGE();
        return 1;
    }

    s_trie *trie = build(argv[1]);

    trie_to_dot(trie, argv[2]);

    return 0;
}
