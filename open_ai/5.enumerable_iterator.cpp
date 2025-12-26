

/**
Implement a resumable iterator supporting getState() / setState(). 

- First two parts: implement for lists using indices. 
- Third part: implement MultipleResumableFileIterator based on existing ResumableFileIterator 
  to iterate multiple JSON files, handling empty files. 
- For resumable JSON file iterators, implement file-chain iterators with tests.

Additional notes:
getState returns a state object, which is passed to setState. 

Example: 
list [1,2,3,4], next() → 1, then next() → 2, getState() saves state (2), next() → 3, setState(2) returns to state 2.

Writing test cases first is important. Full unit tests required, covering all get_state/set_state scenarios and 
iteration end (StopIteration).

Subtasks:

- Part 1: iterator interface, implement abstract class IteratorInterface with __init__, iter, next, 
  get_state, set_state. No hasNext(). Do not assume state is an index; caller handles iteration end.
- Part 2: implement ResumableIterator for lists.
- Part 3: implement ResumableMultiFileIterator using file iterator, handle empty files. Combine ideas 
  from Leetcode 251 and resumable iterator.
- Part 4: convert iterator to async (coroutines) for efficient multi-file iteration.
- Part 5: implement 2D resumable list iterator using file iterator; next() uses recursion, careful 
  with corner cases.
- Part 6: implement 3D iterator.

Test pseudo-code:

def test_iterator(my_iter):
    states = []
    while my_iter.hasNext():  # handle exhausted iterator
        states.append(my_iter.get_state())
    for state in states:
        test_iter = my_iter.set_state(state)
        elements = all elements from test_iter to end
        assert elements == expected_elements


Additional notes:
- Focus on test-driven development (TDD).
- Write tests first, then implement functionality; not conventional, time-intensive, need preparation.
- Multi-file iterator (Part 3) is prone to bugs; requires careful handling.
 */
