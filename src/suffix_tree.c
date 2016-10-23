#include "suffix_tree.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static s_list *create_node(const char c)
{
    s_list *node = malloc(sizeof (s_list));
    if (!node)
        return NULL;

    node->next = NULL;
    node->trie.val = c;
    node->trie.children = NULL;

    return node;
}

static void insert(s_trie *trie, const char *str)
{
    if (!*str)
        return;

    if (!trie->children)
    {
        trie->children = create_node(*str++);
        if (!trie->children)
            return;
        insert(&trie->children->trie, str);
        return;
    }

    s_list *iter = trie->children;

    while (iter->next)
    {
        if (iter->trie.val == *str)
        {
            insert(&iter->trie, ++str);
            return;
        }
        iter = iter->next;
    }

    if (iter->trie.val == *str)
    {
        insert(&iter->trie, ++str);
        return;
    }

    iter->next = create_node(*str++);
    insert(&iter->next->trie, str);
}

s_trie *build(const char *str)
{
    int len = strlen(str);
    s_trie *trie = calloc(1, sizeof (s_trie));
    trie->val = '/';

    for (int i = len - 1; i >= 0; --i)
    {
        insert(trie, str + i);
    }

    return trie;
}

void write_to_file(FILE *fdp, const s_trie *trie)
{
    s_list *iter = trie->children;
    while (iter)
    {
        fprintf(fdp, "%lu [label=\"%c\"]\n", (unsigned long)&iter->trie, iter->trie.val);
        fprintf(fdp, "\t%lu -- %lu\n", (unsigned long)trie, (unsigned long)&iter->trie);
        write_to_file(fdp, &iter->trie);
        iter = iter->next;
    }
}

void trie_to_dot(const s_trie *trie, const char *filename)
{
    FILE *fdp = fopen(filename, "w");

    fprintf(fdp, "graph suffix_tree {\n");
    fprintf(fdp, "%lu [label=\"%c\"]\n", (unsigned long)trie, trie->val);
    write_to_file(fdp, trie);

    fprintf(fdp, "}\n");
    fclose(fdp);
}
