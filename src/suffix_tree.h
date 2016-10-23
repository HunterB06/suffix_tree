#ifndef SUFFIX_TREE_H
# define SUFFIX_TREE_H

struct list;

typedef struct trie {
    char val;
    struct list *children;
} s_trie;

typedef struct list {
    s_trie trie;
    struct list *next;
} s_list;

s_trie *build(const char *str);
void trie_to_dot(const s_trie *trie, const char *filename);

#endif /* !SUFFIX_TREE_H */
