SCARICARE NUOVE PROTEINE

Anzitutto, si utilizzino i due comandi

rsync -rlpt -v -z --delete --port=33444 \
rsync.rcsb.org::ftp_data/structures/divided/pdb/ ./temporary

Dalla cartella principale, e premere Ctrl+C prima che scarichi troppe cose.
Dunque posizionarsi nella cartella utilities e chiamare:

./pdb_unzip.sh
./pdb_copy.sh
./clean_data.sh

Per ottenere i dati trasferiti su rough_data, spacchettati e solo con proteine (senza DNA o simili).
Eliminare poi il contenuto di temporary per non appesantire il processo successivo.





