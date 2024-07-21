#!/bin/bash

# This script creates a backup directory using rsync with 
# increments. The interval is up to the admin (i.e. weekly, 
# semi-monthly). Use the backupDefs.sh super file defined 
# as source to set the variables used by the script.The 
# script performs incremental backups and archives them as 
# full snapshots.


# A script to perform incremental backups using rsync

source /mnt/udir/blackbox-srv-dirs/mud/DeadSouls-ForgottenGods/bin/scribe/backupDefs.sh

set -o errexit
set -o nounset
set -o pipefail

# Backup destination (change this to your backup location)

# Create a new backup directory with a timestamp
TIMESTAMP=$(date +%Y-%m-%d_%H-%M-%S)
ARCHIVE_NAME="$BACKUP_MUD$()_$TIMESTAMP"
NEW_BACKUP_DIR="$BACKUP_DIR/granular/$ARCHIVE_NAME"

# Check if older archives exist
if [[ -n $(find "$BACKUP_DIR/granular" -type d -ctime +$BACKUP_EXP) ]]; then
    echo "Older archives found. Running garbage collection."
    find "$BACKUP_DIR/granular" -type d -ctime +$BACKUP_EXP -exec rm -rf {} \;

else
    echo "No older archives found."
fi

echo "Granular backup archive started: $NEW_BACKUP_DIR"

mkdir -p "$NEW_BACKUP_DIR"
# Perform the backup using rsync
rsync -a --link-dest="$BACKUP_DIR/latest" "$BACKUP_SRC/" "$NEW_BACKUP_DIR"

# Update the "latest" symlink
rm -f "$BACKUP_DIR/latest"
ln -s "$NEW_BACKUP_DIR" "$BACKUP_DIR/latest"

echo "Granular backup archive completed: $NEW_BACKUP_DIR"
