#!/bin/bash

# This script creates a tar archive of the backup directory. The 
# interval is up to the admin (i.e. every three months). Use the 
# backupDefs.sh super file defined as source to set the variables 
# used by the script.The script performs incremental backups and 
# archives them as full snapshots.


source /mnt/udir/blackbox-srv-dirs/mud/DeadSouls-ForgottenGods/bin/scribe/backupDefs.sh

# Check if the source directory exists
if [ ! -d "$BACKUP_DIR/latest" ]; then
    echo "Granular backup directory does not exist. Nothing to archive. Aborting."
    exit 1
fi

# Create the "full" directory if it doesn't exist
mkdir -p "$BACKUP_DIR/full"

# Archive name format (adjust as needed)
TIMESTAMP=$(date +%Y%m%d)
ARCHIVE_NAME="$BACKUP_DIR/full/$BACKUP_MUD$()_$TIMESTAMP.tar.gz"

echo "Full backup archive started: $ARCHIVE_NAME"

# Create the tar archive
tar --create --gzip --file "$ARCHIVE_NAME" "$BACKUP_DIR/latest"

echo "Full backup archive created: $ARCHIVE_NAME"
