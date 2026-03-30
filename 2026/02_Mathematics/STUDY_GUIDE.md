# STUDY GUIDE: 02 Mathematics

## Purpose
Master this folder at interview quality while preserving contest-ready speed.

## Prerequisites
01 Foundations and STL

## Current Chapter Status Audit
Based on the files already present in this folder:

- Theory notes completed:
  - `Number_Theory_Foundations.md`
  - `Arithmetic_Optimizations.md`
  - `Bit_Manipulation_XOR.md`
- Concept coverage already started:
  - GCD/LCM and divisibility logic
  - Prime sieve and segmented sieve
  - Modular arithmetic and fast power
  - Overflow-safe multiplication
  - Bitwise/XOR patterns
- Still missing before this chapter is considered complete:
  - Problem-solving evidence inside `Code/`
  - Session entries in `TRACKER.md` for Folder 02
  - Completion checks in `MASTER_PLAN.md`
  - Spaced-repetition entries for any difficult math problems

## Atomic Topics to Learn
- GCD/LCM and divisibility logic
- Prime sieve and segmented sieve
- Modular arithmetic and fast power
- Overflow-safe multiplication and exponentiation
- Bitwise arithmetic patterns

## Trigger Patterns (When to Use This Folder)
- Large ranges of primes
- Modulo constraints (1e9+7)
- Power or divisibility queries

## Common Failure Modes
- Integer overflow before modulo
- Recomputing primality naively
- Negative modulo handling bugs
- Using `int` where `long long` or `__int128` is required
- Forgetting corner cases like `L = 1` in segmented sieve
- Confusing XOR tricks with arithmetic addition/subtraction logic

## Revision Checklist Before New Problems
Use this 15-minute reset before your next chapter-2 session:

- Re-explain Euclidean GCD and safe LCM formula without looking.
- Write sieve from memory and state its time complexity.
- Write binary exponentiation from memory and explain why it is `O(log b)`.
- Re-state modular subtraction and modular inverse rules.
- Recall 3 XOR identities and 2 common single-number patterns.
- Review one failure-risk case:
  - overflow before modulo
  - negative modulo
  - `1` marked as prime by mistake
  - `1 << i` overflow instead of `1LL << i`

## Remaining Work To Finish Chapter 02
Complete these in order:

1. Solve 2 warm-up problems on GCD / divisibility / bit basics.
2. Solve 2 sieve or prime-factorization problems.
3. Solve 2 modular arithmetic or fast-power problems.
4. Solve 2 XOR / bit-manipulation problems.
5. Add complexity + one edge case note for each accepted problem.
6. Update `TRACKER.md`, `MASTER_PLAN.md`, and `SPACED_REPETITION_LOG.md`.

## Recommended Problem Ladder
Use this order so revision and continuation feel smooth:

1. `LC 69` Sqrt(x) for arithmetic boundary discipline.
2. `LC 204` Count Primes for sieve revision.
3. `LC 231` Power of Two for bit checks.
4. `LC 191` Number of 1 Bits or equivalent popcount practice.
5. `LC 50` Pow(x, n) for fast exponentiation.
6. `LC 136` Single Number for XOR basics.
7. `LC 137` Single Number II for bit-count logic.
8. `LC 1498` Number of Subsequences That Satisfy the Given Sum Condition if you want a stronger modular/combinational stretch.

## Session Protocol (90 Minutes)
- 15 minutes: review one spaced-repetition problem.
- 50 minutes: solve one new Medium (or 2 Easy if blocked after 35 minutes).
- 20 minutes: speed rerun of a previously solved problem without notes.
- 5 minutes: update TRACKER, MASTER_PLAN, and SPACED_REPETITION_LOG.

## Completion Gate
- [ ] Solve 8 to 10 math or bit problems
- [ ] Complete at least 2 modular arithmetic problems
- [ ] Maintain >=70% first-try acceptance on recent set

## Evidence to Record
- Problem ID and final complexity.
- At least one edge case that caused or could cause WA.
- If solve time exceeds 45 minutes or hints were used, log in spaced repetition.

## Exit Rule For Moving To Folder 03
Only move to `03_Arrays_and_Searching` after all are true:

- At least 8 math/bit problems are solved and stored in `Code/`.
- At least 2 accepted problems required modular arithmetic or fast power.
- Recent Folder 02 first-try acceptance is at least 70%.
- You can explain:
  - when to use sieve vs segmented sieve
  - when XOR works and when it does not
  - how to avoid overflow before modulo
