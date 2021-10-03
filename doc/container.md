### Container, an overview

Let's start by considering the following example:
```
// container.cpp

int values[] = {5,4,3,2};
...
```

Given these values, we need to satisfy the following use-cases:
1. I must be able to order these values using a strategy of my choosing
2. I must be able to iterate over every value in the collection
3. I must be able to search for a specific value using its associated `key`
4. I should not depend on the standard library

```
// container.cpp

// building a container using an array of 
// values of the same type, then retrieving
// a specific value

...

Container c = Container(values);

int res = 0;

if (res = c.find(3)) { 
	// value exists in our collection
} else {
	// value is not in our container
}

...
```
