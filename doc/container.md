### Container, an overview

Let's start by considering the following example:
```
// sample.cpp

int values[] = {5,4,3,2};
```

Given these values, we need to satisfy the following use-cases:
1. I must be able to order these values using a strategy of my choosing
2. I must be able to iterate over every value in the collection
3. I must be able to search for a specific value using its associated `key`
4. I should not depend on the standard library
