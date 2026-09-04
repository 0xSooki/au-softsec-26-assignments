# Assignment 1

In this assignment you are required toresearch and do write up on a **class of software weakness** from  [Common Weakness Enumeration (CWE)](https://cwe.mitre.org/). This is a *research and writing* assignment, and the goal is to practice reading and understanding technical documents, and practive research writing.

N.B: A **CWE** describes a *type/class* of mistake (e.g. "SQL Injection", CWE-89). While a **CVE** describes *one specific instantiatoin* of such a mistake in a specific software (e.g. SQL injection in gmail). One CWE class is the parent of thousands of CVEs.

## Preliminaries

None. However, you might find the following sites useful for choosing the assignment.

- The CWE database: <https://cwe.mitre.org/> (search by number, e.g. `CWE-89`).
- The National Vulnerability Database (NVD): <https://nvd.nist.gov/vuln/search>, to find real CVEs and see their CWE mapping.
- The [2025 CWE Top 25 Most Dangerous Software Weaknesses](https://cwe.mitre.org/top25/archive/2025/2025_cwe_top25.html) for context on why your weakness matters.

## Learning Objectives

- Distinguish a weakness class (CWE) from a specific instantiation of the class (CVE).
- Connect the CWE to a *real-world incident*.
- Describe how the weakness class is typically *detected* and *prevented*.
- Practice writing concise, and clear technical explanations.

## Tasks

Write at max a one page concise report (excluding references) on your choosen CWE according to the following criterias:

1. Explain it in your own words, what the weakness is and how can it be exploited.
2. Find a real CVE on NVD that is an instantiation of your CWE and argue why it belongs to your chosen CWE class.
3. What coding, design decision, etc. is the root of this class of weakness.
4. How is this class of weakness typically *found*? Name at least one method that actually fits your CWE (e.g. static analysis)
5. Give the standard, defense(s) for this class.

## What to submit

- At max one page report (PDF) excluding references covering the five parts and the reasoning paragraph.
- The CVE identifier and a link to the advisory you used, plus citations for any other source (docs, blog, AI assistant) you used.
