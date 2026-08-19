# Windows-OS-Defense-in-depth-flaw
Security research into Windows 10/11 analyzing Antivirus installations resulting in defense-in-depth gaps and its implications, mainly focusing on the shutdown of Microsoft Defender’s Antimalware Service Executable system process after third-party AV installation. Microsoft has assessed this behavior as by design.

---

## Executive Summary

This repository documents security research performed against Windows 10/11 systems investigating the interaction between Microsoft Defender Antivirus and third-party antivirus software.

The research began after observing that the installation of certain third-party antivirus products caused the Windows Defender **Antimalware Service Executable** to stop running.

The investigation then examined the security implications of operating without this additional native Windows malware-protection layer.

The original controlled research demonstrated significant security impact under the tested conditions, including code execution, file access, system modification, security-control bypass, and potential denial of service.

The underlying behavior was subsequently assessed by Microsoft as **by design**, rather than an unintended vulnerability in Windows. The behavior was later mitigated.

Therefore, this project is classified as:

> **Windows Endpoint Defense-in-Depth Security Research**

and is **not** presented as an unpatched Microsoft Windows vulnerability.

---

## Research Question

> If Microsoft Defender Antivirus is inactive because a third-party antivirus product has become the active antivirus provider, what security implications arise if the remaining endpoint protection layer is bypassed or fails?

The objective was to investigate the consequences of reduced defensive redundancy within a Windows endpoint-security architecture.

---

## Security Context

Modern Windows endpoint security can consist of multiple complementary security layers:

```text
                    Windows Endpoint
                           |
             +-------------+-------------+
             |                           |
             v                           v
      Third-Party AV              Microsoft Defender
       Protection                   Antivirus
             |                           |
             +-------------+-------------+
                           |
                           v
                   Defense in Depth
                           |
                           v
                    Attack Resistance


# Copyright Notice

Copyright © 2026 Arjun B Raj. All rights reserved.

This repository and its contents, including source code, proof-of-concept
material, documentation, research, diagrams, and other original works,
are protected by copyright.

No permission is granted to reproduce, redistribute, modify, publish,
commercialize, or create derivative works from the restricted
proof-of-concept material without prior written permission from the
copyright holder.
