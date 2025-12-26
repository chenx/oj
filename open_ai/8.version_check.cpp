

/**
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
- Initial implementation: Find earliest supporting version based on given list.
- Iterative refinement: Each test case may reveal exceptions or new rules, requiring hypothesis adjustment.
- Observation-driven logic: Must carefully examine the data and dynamically adjust assumptions.
- Version comparison: Properly parse and compare version numbers (consider major/minor/patch).
 */
