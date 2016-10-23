#include "suffix_tree.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
        return -1;

    s_trie *trie = build(argv[1]);

    trie_to_dot(trie, argv[2]);

    return 0;
}
