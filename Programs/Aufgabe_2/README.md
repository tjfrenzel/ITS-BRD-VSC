# Zustände

| Phase | A | B |
|---|---:|---:|
| Phase A | 0 | 0 |
| Phase B | 1 | 0 |
| Phase C | 1 | 1 |
| Phase D | 0 | 1 |

# Zustandsübergänge

| A Alt | B Alt | Phase Alt | A Neu | B Neu | Phase Neu | Ereignis | Zählwert |
|---:|---:|---|---:|---:|---|---|---:|
| 0 | 0 | Phase A | 0 | 0 | Phase A | Keine Änderung | 0 |
| 0 | 0 | Phase A | 0 | 1 | Phase D | Rückwärtslauf | -1 |
| 0 | 0 | Phase A | 1 | 0 | Phase B | Vorwärtslauf | +1 |
| 0 | 0 | Phase A | 1 | 1 | Phase C | Fehler | 2 |
| 0 | 1 | Phase D | 0 | 0 | Phase A | Vorwärtslauf | +1 |
| 0 | 1 | Phase D | 0 | 1 | Phase D | Keine Änderung | 0 |
| 0 | 1 | Phase D | 1 | 0 | Phase B | Fehler | 2 |
| 0 | 1 | Phase D | 1 | 1 | Phase C | Rückwärtslauf | -1 |
| 1 | 0 | Phase B | 0 | 0 | Phase A | Rückwärtslauf | -1 |
| 1 | 0 | Phase B | 0 | 1 | Phase D | Fehler | 2 |
| 1 | 0 | Phase B | 1 | 0 | Phase B | Keine Änderung | 0 |
| 1 | 0 | Phase B | 1 | 1 | Phase C | Vorwärtslauf | +1 |
| 1 | 1 | Phase C | 0 | 0 | Phase A | Fehler | 2 |
| 1 | 1 | Phase C | 0 | 1 | Phase D | Vorwärtslauf | +1 |
| 1 | 1 | Phase C | 1 | 0 | Phase B | Rückwärtslauf | -1 |
| 1 | 1 | Phase C | 1 | 1 | Phase C | Keine Änderung | 0 |