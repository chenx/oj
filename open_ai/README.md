# Questions:

1. CD Directory: https://www.hellointerview.com/community/questions/unix-cd-resolution/cmbskxz3y004n07adimbogre1
6. Node counting

# Links

- https://www.hellointerview.com/blog/openai-coding-questions
- https://www.linkjob.ai/interview-questions/openai-coding-interview/
- https://igotanoffer.com/en/advice/openai-interview-questions

-  https://leetcode.com/problem-list/design/

OpenAI’s coding questions come from a question bank. Recently, there have been 8 recurring problems: CD directory, Excel sheet, In-memory DB, KV store, Resumable iterator, Node counting, GPU credit, and Dependency version check. 

OpenAI’s coding questions come from a question bank. Recently, there have been 8 recurring problems: CD directory, Excel sheet, In-memory DB, KV store, Resumable iterator, Node counting, GPU credit, and Dependency version check. 

# OpenAI Coding Interviews 2025: Real Questions from Real Candidates
11/2025

OpenAI is one of the companies that has made a deliberate shift away from standard LeetCode-style questions. Their interviews center on production-oriented problem solving i.e. writing real code, handling edge cases, and building small but meaningful components. The focus isn't on some trick algorithms but rather on how you structure, reason about, and debug your code in a way that reflects actual engineering work.

One candidate who recently interviewed put it this way: "I was typing the whole time and finished passing all the test cases just in time." 

That's the reality. These interviews test whether you can actually build things, not just solve algorithmic puzzles.

## What Makes OpenAI Coding Interviews Different

OpenAI's coding rounds stand out in three ways:

- Volume matters. You'll write significantly more code than in typical FAANG interviews. The problems aren't about finding one clever algorithmic insight, but rather they're about implementing the complete functionality with proper structure. Candidates consistently report spending the entire hour typing.
- Practical over theoretical. Instead of "find the kth largest element," you get "implement a key-value store with serialization." Instead of "reverse a binary tree," you get "build a resumable iterator with state management."
- Production quality counts. As one senior interviewee noted, "they really want people who can be productive building / writing code, not just arch / design / org alignment." Your solution needs to be maintainable, handle edge cases, and look like code someone else could actually work with. A hacky solution that passes tests won't cut it.

## The Questions

We've collected real interview questions from candidates who've gone through OpenAI's process. Here's what people are actually getting asked, organized by what skill each question tests.

### Building Data Structures from Scratch

OpenAI needs engineers who can build custom data structures for AI systems, not just reach for off-the-shelf solutions.

#### KV Store Serialize/Deserialize
Implement serialization and deserialization for a key-value store where both keys and values can contain any characters including delimiters. You can't use simple delimiters because they might appear in the data. Most candidates land on length-prefix encoding (like 3:key5:value), which is the same pattern used in Redis protocol.

#### Time-Based Key-Value Store
Build a key-value store that can retrieve values at specific timestamps. Every set operation includes a timestamp, and get operations need to return the value that was active at a given time. This tests your ability to handle temporal data efficiently, which matters when you're building systems that need to track model versions or configuration changes over time.

#### Resumable Iterator
Create an iterator that can pause and resume iteration across multiple calls. You need to maintain state between invocations, handle nested structures, and support operations like skip and reset. It's straightforward in concept but involves a lot of careful bookkeeping to get right.

#### Implementing Real Systems
These questions test your ability to implement pieces of larger systems with real-world constraints. They're not isolated algorithmic puzzles.

#### In-Memory Database with SQL Operations
Implement a subset of SQL functionality in memory: tables, inserts, selects with WHERE clauses, maybe joins. This isn't about optimizing query execution, it's about parsing commands, managing data structures, and handling the edge cases that come up when multiple operations interact.

#### Unix CD Command with Symbolic Link Resolution
Implement the logic for cd command navigation including handling ., .., absolute paths, and symbolic links. The tricky part is resolving symlinks correctly and detecting cycles. It's a great example of something that seems simple until you start implementing it.

#### Design SQL / Meeting Rooms
Build a SQL query executor or solve the meeting rooms scheduling problem. Both test practical algorithmic thinking: how do you efficiently check for overlapping intervals? How do you manage resource allocation? These show up constantly in real systems.

### Handling Complexity
Production systems at OpenAI deal with complex interactions between components. Can you manage that complexity cleanly?

#### Multithreaded Web Crawler
Build a web crawler that uses multiple threads to fetch pages concurrently. You need to coordinate between threads, avoid crawling the same URL twice, handle failures, and probably implement some kind of rate limiting. Concurrency bugs are easy to introduce and hard to debug, which is exactly why they ask this.

#### Spreadsheet Formula Evaluation with Dependencies
Implement a spreadsheet that can evaluate formulas with cell references. If A1 references B2 and B2 references C3, you need to figure out the evaluation order. If A1 references B2 and B2 references A1, you need to detect the cycle. It's a graph problem dressed up as a spreadsheet, testing your ability to handle dependencies and circular references.

### What Success Looks Like
After talking to candidates who've been through the process, here's what actually works:

- Start with a working solution, then optimize. Don't spend the first 20 minutes architecting the perfect solution in your head. Get something working that handles the basic cases, then iterate. The interviewer will often introduce new requirements or ask for optimizations, and you can't optimize code that doesn't exist yet.
- Talk through your approach before coding. Take two minutes to clarify requirements and outline your plan. The interviewer wants to see your problem-solving process. If you immediately start typing, they have no idea if you understand the problem or are just hoping to figure it out as you go.
- Handle edge cases explicitly. Empty inputs, null values, boundary conditions - don't just assume they won't come up. Production code needs to handle these gracefully, and interviewers notice when you skip them.
- Write code that looks production-ready. Use meaningful variable names, break complex logic into helper functions, add comments where your intent isn't obvious. This isn't just about making the interviewer's job easier, it's about showing you write code that other people can maintain.

Multiple candidates have reported hearing that OpenAI "won't pass you if you have a 2/4 or low 3/4 on coding even if you ace everything else." You can't coast through coding rounds hoping to make up for it in system design or behavioral interviews. The coding bar is high, and it stays high across all levels.

### How to Prepare

The questions above aren't easy, but they're learnable. Here's how to approach preparation:
- Work through the actual questions. We've linked to detailed breakdowns of each problem above. Don't just read the solutions, implement them yourself. Time how long it takes. Then do it again faster. These design problems on LeetCode are also good practice.
- Focus on code structure, not just correctness. After you get a solution working, spend 10 minutes cleaning it up. Would another engineer understand this code? Could you explain your choices?
- Time yourself. Sixty minutes sounds like a lot until you're implementing something non-trivial. Build a habit of checking the clock and asking yourself "am I going to finish?"




=========

# My Real Questions List to Pass 2025 OpenAI Coding Interview
Seraphina
·September 13, 2025

I just finished my interview at OpenAI. The coding questions were mostly from the question bank, and the bank isn’t very big.

## OpenAI Coding Interview Overview

### Timeline
Here’s a quick look at the typical timeline:
- Application Submission
- Recruiter Screen
- Technical Screen
- Virtual On-Site Loop
- Offer Stage

This process usually takes about 6-8 weeks. Generally, there is usually a waiting period between each stage, so I used that time to review my notes and practice more.

### What Makes It Unique
The OpenAI coding interview stands out from other tech interviews I’ve experienced. Rather than focusing solely on algorithms, it emphasizes solving real-world coding problems. Therefore, correctness is the top priority.

### OpenAI Coding Interview Recent Real Questions

#### Coding Problem 1: CD Directory

Prompt: Organize the following loosely described interview problem into a clearly structured question:

Implement a function cd(current_dir, new_dir) that returns the resulting path.
Examples:
cd(/foo/bar, baz) = /foo/bar/baz
cd(/foo/../, ./baz) = /baz
cd(/, foo/bar/../baz) = /baz
cd(/, ..) = Null

Part 2: Add support for the ~ symbol (home directory).

Difficulty upgrade (Part 3): Add a third parameter soft_link (a dictionary of symbolic links). Examples:
cd(/foo/bar, baz, {/foo/bar: /abc}) = /abc/baz
cd(/foo/bar, baz, {/foo/bar: /abc, /abc: /bcd, /bcd/baz: /xyz}) = /xyz

The soft link dictionary may contain both short and long matches; the longer/more specific path should take precedence. Example:
cd(/foo/bar, baz, {/foo/bar: /abc, /foo/bar/baz: xyz}) = xyz
Detect cycles in the soft link dictionary (e.g., A→B, B→A).

Key points:

In Part 3, the logic for condensing soft links must be carefully handled to avoid incorrect path resolution.

When matching soft links, always prioritize the longest path to ensure more specific soft links take effect.

#### Coding Problem 2: Excel Sheet
Prompt: Organize the following loosely described interview problem into a proper interview question: Given a Spreadsheet API, implement getCell and setCell. setCell can depend on other cells or accept an independent value (e.g., setCell("A", "B+C"), setCell("A", 100)). 

Circular dependencies must be handled, and test cases should be written. Part 1 can implement a non-optimal getCell (calculates values in real time). 

Part 2 requires optimizing setCell so that it updates dependent cells, enabling getCell to achieve O(1) time complexity. Ultimately, implement both getCell() and setCell().

Test cases:
```
Example 1:

spreadsheet = Spreadsheet()
spreadsheet.setCell('A1', '1')
spreadsheet.setCell('A2', 2)
spreadsheet.setCell('A3', '=A1+A2')
spreadsheet.setCell('A4', '=A3+A2')
spreadsheet.setCell('A5', '=A3+A4')
spreadsheet.setCell('B1', '=A1+A2+A3+A4+A5')

Example 2:

Cell A = Cell(6, NULL, NULL)
Cell B = Cell(7, NULL, NULL)
Cell C = Cell(13, A, B)
print(getCell(C))  # should return 13 (A+B=6+7)

// after updating Cell A = Cell(2, NULL, NULL)
print(getCell(C))  # should return 9 (A+B=2+7)
```

Additional notes: A cell can be an int or a formula (e.g., A1+B1). Simple DFS can be used. Interviewers may ask how to optimize for more efficient search, especially across multiple requests.

Hints: Implement basic DFS first, then attempt cache-based optimization, particularly focusing on how to find downstream cells that are outdated when a node changes.

Key points:

Part 1: straightforward DFS.

To optimize getCell to O(1), setCell must update both dependents and dependencies; the logic is complex.
Use a set to detect circular dependencies (cycle detection).
Although OpenAI has a coding problem bank, answering them and follow-up questions well can still be challenging.

#### Coding Problem 3: In memory DB

Prompt: Organize the following into a proper interview question: Implement an in-memory database supporting insert and query. Queries must support where filtering and order by sorting. Provide a select(table_name, where=None, order_by=None) interface. Multiple where conditions only support AND logic. Implement queries with where, multi-column where, where with single-column sort, where with multi-column sort. The same API must be used, and input parameters should ensure backward compatibility.

Original requirements: Simulate SQL using a map. Create tables based on column name lists. Implement add row, query by single or multiple columns (supporting AND/OR), support comparison operators (>, <), and order by. No need to parse SQL; just provide APIs with the required functionality.

Key points: When where is empty, return all matching entries (or empty list if none).

#### Coding Problem 4: KV store
Prompt: Organize the following into a proper interview question: Implement a time-based KV store using real timestamps. Specify how to write tests, mock timestamps, ensure strictly increasing timestamps, handle locks under multithreading, and compare lock implementations for performance. Also implement versioned KV store. Implement KVStore class supporting set and get, persisting to and restoring from the file system. Keys and values are strings (may contain any characters, including newlines). Custom serialization/deserialization must be implemented (no Python built-in libraries like json).

Follow-up questions:

- How to ensure update consistency under multithreading.
- How to handle get with a future timestamp (e.g., current timestamp = 10, get("key", 20), at timestamp 15 add "value_15", then get("key", 20) should return "value_15").

Key points:
Choose a convenient method for serialization/deserialization.
Compare global lock vs per-key lock vs optimistic lock.

#### Coding Problem 5: Resumable iterator

Prompt: Organize the following into a proper interview question: Implement a resumable iterator supporting getState() / setState(). First two parts: implement for lists using indices. Third part: implement MultipleResumableFileIterator based on existing ResumableFileIterator to iterate multiple JSON files, handling empty files. For resumable JSON file iterators, implement file-chain iterators with tests.

Additional notes:

getState returns a state object, which is passed to setState. Example: list [1,2,3,4], next() → 1, then next() → 2, getState() saves state (2), next() → 3, setState(2) returns to state 2.

Writing test cases first is important. Full unit tests required, covering all get_state/set_state scenarios and iteration end (StopIteration).

Subtasks:
```
Part 1: iterator interface, implement abstract class IteratorInterface with __init__, iter, next, get_state, set_state. No hasNext(). Do not assume state is an index; caller handles iteration end.
Part 2: implement ResumableIterator for lists.
Part 3: implement ResumableMultiFileIterator using file iterator, handle empty files. Combine ideas from Leetcode 251 and resumable iterator.
Part 4: convert iterator to async (coroutines) for efficient multi-file iteration.
Part 5: implement 2D resumable list iterator using file iterator; next() uses recursion, careful with corner cases.
Part 6: implement 3D iterator.
Test pseudo-code:
def test_iterator(my_iter):
    states = []
    while my_iter.hasNext():  # handle exhausted iterator
        states.append(my_iter.get_state())
    for state in states:
        test_iter = my_iter.set_state(state)
        elements = all elements from test_iter to end
        assert elements == expected_elements
```

Additional notes:
```
Focus on test-driven development (TDD).
Write tests first, then implement functionality; not conventional, time-intensive, need preparation.
Multi-file iterator (Part 3) is prone to bugs; requires careful handling.
Coding Problem 6: Node counting
Prompt: Rewrite the following unclear problem description into a structured interview question:
You are given a tree, where each node represents a machine.
Communication is only possible between parent and child nodes.

The communication relies on the provided interfaces:

sendAsyncMessage(target, message): Sends an asynchronous message (already implemented, no need to implement).
receiveMessage(message): A method you need to implement for handling incoming messages.

Question 1: Count the total number of machines

Goal: Design a method to count how many machines exist in the entire tree.

Basic logic:

When receiveMessage(message) receives a count message, it forwards the same message to all of its children.
When it receives a response message from a child, it records the child’s count.
Once all child responses are collected, it computes the sum and sends the result back to its parent.

Special cases:

If the node is a leaf (no children), it directly returns 1 to its parent.
If the node is the root, the final sum is the total number of machines in the tree.

Example:
A 3-level tree: root → 2 children → each child has 2 leaves.
The result should be 7 machines in total.

Key Points:

Distributed communication model: Only parent-child message passing is allowed.
Recursive counting logic: count request propagates down → responses bubble up → aggregate results.
Boundary conditions: Special handling for root and leaf nodes.
Robustness: Must handle potential failures (e.g., lost messages, missing child responses).
```

#### Coding Problem 7: GPU credit

Operations:
```
Add credit: At time t, add x credits, which will expire at time t_expire.
Expire credit: Credits added earlier should automatically expire when their expiration time is reached.
Cost: At time t, deduct x credits if available. If insufficient credits exist at that time, return False.
```

Requirements:
```
Maintain all events (add, expire, cost) in chronological order.
When processing a cost event:
First check if the current balance is sufficient.
If not, return False.
If yes, deduct credits by adjusting the future expire entries accordingly (consume the oldest credits first).
The system should support multiple adds, expires, and costs interleaved at different timestamps.

Example:
Add(10, 5, expire=20)   # at timestamp=10, add 5 credits, which expire at 20
Cost(15, 3)             # at timestamp=15, consume 3 credits → valid
After this operation, the future expire at (20, 5) should be updated to (20, 2).
```

#### Coding Problem 8: Dependency Version Check

Prompt: Organize the following problem into a clearly structured interview question:
```
Part 1:
You are given a list of dependency versions, e.g., [103.003.02, 103.003.03, 203.003.02].
Each version may support or not support a specific feature.
Task: Find the earliest version that supports the current feature.

Part 2:
Multiple corner test cases are provided.
Some test cases may reveal additional requirements that invalidate initial assumptions.
Example: The first case may show that version 103.003.02 supports the feature, but the next version 103.003.03 does not.
You need to analyze the test data, identify new requirements, and confirm them with the interviewer.
Each test case can introduce new constraints, so careful observation of the data is required.

Key Points:
Initial implementation: Find earliest supporting version based on given list.
Iterative refinement: Each test case may reveal exceptions or new rules, requiring hypothesis adjustment.
Observation-driven logic: Must carefully examine the data and dynamically adjust assumptions.
Version comparison: Properly parse and compare version numbers (consider major/minor/patch).

FAQ

How should I manage my time during the coding interview?

Time management is crucial because most problems are hard-level implementation tasks and the coding interview usually lasts only 60–75 minutes. Often, a single problem contains multiple sub-questions, so you need to pace yourself carefully. Start by reading the problem thoroughly, clarifying requirements, and planning your approach. Prioritize correctness over micro-optimizations.

Which programming language would you recommend the most for completing OpenAI coding problems?

OpenAI’s coding problems can be considered mostly hard. Completing them requires excellent time management. I highly recommend using Python for these problems, as using other languages may make it difficult to finish on time.
```

=====

# 30+ Common OpenAI Interview Questions + Answers (by role)
```
Solve the LRU cache problem.
How would you design an LLM-powered enterprise search system?
Implement a GPU scheduling system using credits
Design an in-memory database.
Design Slack
```

