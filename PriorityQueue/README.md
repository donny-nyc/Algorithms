# Priority Queue

A heap-based datastructure which maintains that the root node
is always the element with the highest `priority`, where `priority`
is a value assigned to the element.

By using `priority` as our sort key, we can apply either a `min-` or
`max-heap` to maintain our invariant: for min-heaps, lower `priority` values
must be picked-off first. For max-heaps, higher `priority` values must be
taken first.
