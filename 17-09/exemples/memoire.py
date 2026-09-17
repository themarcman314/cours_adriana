# demo.py
import sys

# Python automatically picks the object wrapper type
val = 42

print(f"Value: {val}")
print(f"Type: {type(val)}")
# sys.getsizeof shows the heavy PyObject wrapper, not a raw 4-byte int!
print(f"Size in Memory: {sys.getsizeof(val)} bytes")
