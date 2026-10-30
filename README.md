# SKZygisk stage 1: entry probe

Experimental entry/log probe only. This is NOT a Zygisk implementation and does not establish LSPosed compatibility.

The probe prints PID, UID and CLOCK_BOOTTIME and returns. It does not print the root key, inject Zygote, write kernel memory, change SELinux or modify boot partitions. The upstream SDK wrapper handles the root key internally.

## Cloud build

The Build entry probe workflow runs on push and workflow_dispatch using Android NDK 28.2.13676358. It downloads the official SDK archive directly from upstream and verifies the previously recorded SHA-256 before extraction. The upstream master URL is mutable: checksum mismatch must stop the build, not be bypassed.

No upstream SDK headers or static libraries are committed here. SDK redistribution permission has not been established. Build artifacts contain upstream linked code and are for evaluation; no release is published automatically. Artifact retention is one day.

A compiled artifact is still UNTESTED. Check Actions logs and ELF reports before considering device tests. stdout capture and Zygote startup order require real device validation.

## Device testing gate

Do not install automatically. First verify SKRoot Pro SDK compatibility and an independent disable/uninstall/recovery route. Prefer the official developer run-once mode. Do not upload root keys or GitHub tokens. A successful entry log does not prove Zygisk support.
