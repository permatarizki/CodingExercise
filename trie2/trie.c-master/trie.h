#ifndef _TRIE_H_
#define _TRIE_H_

#define TREE_SIZE_DEF 128
static const int TRIE_SIZE = TREE_SIZE_DEF;

typedef union trie_t {
    void *sentinel;
    union trie_t *chars[TREE_SIZE_DEF];
} trie_t;

trie_t *trie_init(void);
void trie_add(trie_t *, char *);
int trie_exists(trie_t *, char *);
int trie_load(trie_t *, char *);
void trie_strip(trie_t *, char *, char *);
void trie_free(trie_t *);

#define trie_step(t,c) (t = (t == NULL || t->chars[c] == NULL ? NULL : t->chars[c]))
#define trie_word(t) (t != NULL && t->sentinel != NULL)

#endif
