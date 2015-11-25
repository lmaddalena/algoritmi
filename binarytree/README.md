/* ==========================================================================================
binary tree:
the tree contains one node per distinct word, each node contains:
- a pointer to the word
- a count of the number of occurrences
- a pointer to the left child node
- a pointer to the right child node

No node may have more then 2 child node.
The nodes are manteined so that  at any node the left  subtree contains only
words that are lexographically less then the word at the node, and the right
subtree contains only words that are greater.
 
Example:

"now is the time for all good men to come to the aid of their party"

                                        now
                                 /                \
                               is                  the
                              /  \             /        \
                            for   men        of        time
                           /   \              \        /   \
                        all    good           party  their  to
                       /  \
                     aid  come         
                              

output:

   1 aid
   1 all
   1 come
   1 for
   1 good
   1 is
   1 men
   1 now
   1 of
   1 party
   2 the
   1 their
   1 time
   2 to
       
========================================================================================== */



