# Page Replacement Simulator

A command-line based Operating Systems project written in C that simulates and compares different page replacement algorithms.

The simulator demonstrates how an operating system manages memory frames when page references are generated and a page replacement is required.

---

## Overview

In virtual memory management, when a page that is not currently present in memory is requested, a **page fault** occurs.

If all available memory frames are occupied, the operating system must decide which page should be removed.

This project simulates this process using three page replacement algorithms:

- FIFO (First-In First-Out)
- LRU (Least Recently Used)
- Optimal Page Replacement

The simulator displays the state of memory frames after every page reference and provides performance statistics for each algorithm.

---

## Features

- Simulates FIFO page replacement
- Simulates LRU page replacement
- Simulates Optimal page replacement
- Displays memory frame state after each page reference
- Calculates total page hits
- Calculates total page faults
- Calculates hit rate
- Calculates page fault rate
- Compares all three algorithms
- Identifies the best-performing algorithm based on minimum page faults
- Handles ties between algorithms
- Validates user input
- Modular C project structure

---

## Algorithms

### 1. FIFO

**First-In First-Out** replaces the page that has been present in memory for the longest time.

A circular replacement pointer is used to keep track of the next frame to replace.

**Time Complexity:** O(n)

---

### 2. LRU

**Least Recently Used** replaces the page that has not been used for the longest period of time.

The simulator maintains the last-used time of each page to determine which page should be replaced.

**Time Complexity:** O(n × f)

Where:

- `n` = number of page references
- `f` = number of frames

---

### 3. Optimal

The **Optimal Page Replacement** algorithm replaces the page whose next use is farthest in the future.

If a page will never be referenced again, it becomes the preferred replacement candidate.

Optimal replacement provides the theoretical minimum number of page faults and is therefore useful as a benchmark.

**Time Complexity:** O(n × f × n)

---

## Performance Metrics

The simulator calculates the following metrics:

### Hit Rate

```text
Hit Rate = (Page Hits / Total References) × 100