# C++ STL Set & Map Operations

## Table of Operations

| **Operation**    | **Set (`set<int>`)** | **Map (`map<int, string>`)** |
|------------------|---------------------|------------------------------|
| **Insert**      | `s.insert(value);` | `m[key] = value;` or `m.insert({key, value});` |
| **Erase**       | `s.erase(value);` | `m.erase(key);` |
| **Search**      | `s.find(value);` | `m.find(key);` |
| **Check Existence** | `s.count(value);` | `m.count(key);` |
| **Size**        | `s.size();` | `m.size();` |
| **Clear**       | `s.clear();` | `m.clear();` |
| **Lower Bound** | `s.lower_bound(value);` | `m.lower_bound(key);` |
| **Upper Bound** | `s.upper_bound(value);` | `m.upper_bound(key);` |
| **Swap**        | `s1.swap(s2);` | `m1.swap(m2);` |
| **Traversal**   | `for(auto it = s.begin(); it != s.end(); ++it) cout << *it << " ";` | `for(auto it = m.begin(); it != m.end(); ++it) cout << it->first << ": " << it->second << endl;` |
| **Access First & Last Elements** | N/A (Only values stored) | `auto first = *m.begin(); auto last = *prev(m.end()); cout << "First: " << first.first << " -> " << first.second << endl; cout << "Last: " << last.first << " -> " << last.second << endl;` |

---

## **Details of Operations**
- **Insert:** Adds a new element to the container. `set` ensures uniqueness, while `map` associates keys with values.
- **Erase:** Removes a specific element or key-value pair.
- **Search:** Finds an element (in `set`) or key (in `map`). Returns an iterator.
- **Check Existence:** Returns `1` if the value/key exists, otherwise `0`.
- **Size:** Returns the total number of elements in the container.
- **Clear:** Removes all elements, leaving an empty container.
- **Lower Bound:** Returns iterator to the first element not less than the given value/key.
- **Upper Bound:** Returns iterator to the first element greater than the given value/key.
- **Swap:** Exchanges the contents between two sets/maps.
- **Traversal:** Iterates through all elements, printing them.
- **Access First & Last Elements:** Retrieves the first and last key-value pair from an ordered map.

---
