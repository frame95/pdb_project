BREVE DESCRIZIONE

Nella cartella rough_data c'è un archivio di .ent dal Protein Data Bank.
In pdb_lib ci sono librerie create per la gestione delle proteine.
In weight si trovano il dizionario NOME_AMMINOACIDO <--> ID, e la tabella di matching tra i vari amminoacidi.
Sono stati scartati - con clean_data.sh e is_protein - i file che non erano proteine (come ad esempio i DNA).
In analysis ci sono le statistiche degli SSBOND, che forniscono le corrispondenti statistiche sull'approssimazione media della soluzione. In particolare, chiamando il programma SSBOND_statistics.m da octave, si possono visualizzare i risultati dell'analisi.
Negli altri file ci sono i dati raccolti.

ISTRUZIONI PER L'USO

Per analizzare due proteine, basta posizionarle in rough_data e chiamare il main.sh sulle due proteine. 
Esempio: se vogliamo analizzare pdb1a2z.ent e pdb1a3g.ent che si trovano già nella cartella rough_data, basterà eseguire da terminale

./main.sh "./rough_data/pdb1a2z.ent" "./rough_data/pdb1a3g.ent";

I risultati vengono stampati a schermo e salvati su result.txt (ATTENZIONE: ad ogni esecuzione il file result.txt viene sovrascritto).
